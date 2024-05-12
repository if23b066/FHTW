import { Component } from '@angular/core';
import { takeUntilDestroyed } from '@angular/core/rxjs-interop';
import {
  FormControl,
  Validators,
  FormsModule,
  ReactiveFormsModule,
} from '@angular/forms';
import { MatInputModule } from '@angular/material/input';
import { MatFormFieldModule } from '@angular/material/form-field';
import { merge } from 'rxjs';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';
import { MatSelectModule } from '@angular/material/select';

@Component({
  selector: 'app-registration',
  standalone: true,
  imports: [
    MatFormFieldModule,
    MatInputModule,
    FormsModule,
    ReactiveFormsModule,
    MatIconModule,
    MatButtonModule,
    MatSelectModule,
  ],
  templateUrl: './registration.component.html',
  styleUrl: './registration.component.scss',
})
export class RegistrationComponent {
  email = new FormControl('', [Validators.required, Validators.email]);
  password = new FormControl('', [
    Validators.minLength(8),
    Validators.required,
  ]);
  confirmPassword = new FormControl('', [
    Validators.minLength(8),
    Validators.required,
  ]);
  company = new FormControl('FH Technikum Wien');
  postalcode = new FormControl('', [Validators.pattern('^[0-9]*$')]);

  errorMessage = '';

  constructor() {
    merge(this.email.statusChanges, this.email.valueChanges)
      .pipe(takeUntilDestroyed())
      .subscribe(() => this.updateErrorMessage());
  }

  updateErrorMessage() {
    if (this.email.hasError('required')) {
      this.errorMessage = 'You must enter a value';
    } else if (this.email.hasError('email')) {
      this.errorMessage = 'Not a valid email';
    } else {
      this.errorMessage = '';
    }
  }
  hide = true;

  register() {
    if (this.password.value !== this.confirmPassword.value) {
      console.log('Passwords do not match');
      window.alert('Passwords do not match');
    }
    if (
      this.email.value === '' ||
      this.password.value === '' ||
      this.confirmPassword.value === '' ||
      this.company.value === '' ||
      this.postalcode.value === ''
    ) {
      console.log('Some fields are missing');
      window.alert('Some fields are missing');
    }
    if (
      this.email.valid &&
      this.password.valid &&
      this.confirmPassword.valid &&
      this.company.valid &&
      this.postalcode.valid
    ) {
      console.log('Registration successful');
      window.alert('Registration successful');
    }
  }
}
