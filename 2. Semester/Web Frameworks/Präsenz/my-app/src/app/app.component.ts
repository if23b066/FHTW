import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { LoginComponent } from './login/login.component';
import { RegistrationComponent } from './registration/registration.component';
import { MatButtonModule } from '@angular/material/button';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, LoginComponent, RegistrationComponent, MatButtonModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.scss',
  
})
export class AppComponent {
  title = 'FHTW Puzzle Game';

  showLogin() {
    const loginElement = document.getElementById('login');
    if (loginElement) {
      loginElement.style.display = 'block';
    }
    const signupElement = document.getElementById('signup');
    if (signupElement) {
      signupElement.style.display = 'none';
    }
  }
  showSignup() {
    const loginElement = document.getElementById('login');
    if (loginElement) {
      loginElement.style.display = 'none';
    }
    const signupElement = document.getElementById('signup');
    if (signupElement) {
      signupElement.style.display = 'block';
    }
  }
}
