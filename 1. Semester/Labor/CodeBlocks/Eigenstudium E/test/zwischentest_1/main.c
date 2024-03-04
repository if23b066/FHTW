#include <stdio.h>
#include <stdlib.h>

// Funktion zur Berechnung der Steuern
double steuern(double betrag){
    double steuern;
    if(betrag <= 20){
        return ;
    }
    else if(betrag > 20 && betrag <= 50){
        steuern = (betrag - 20)*0.1;
        return steuern;
    }
    else if(betrag > 50 && betrag <= 200){
        steuern = (betrag - 50) * 0.2 + 3;
        return steuern;
    }
    else if(betrag > 200){
        steuern = (betrag - 200) * 0.4 + 33;
        return steuern;
    }
}

int main(){
    char vtyp;
    double guthaben = 100;
    double betrag;
    double gezahlteSteuern = 0;
    double einnahmen = 0; double ausgaben = 0;

    while(1){
        printf("Guthaben: %.2f\n", guthaben);
        printf("Vorgangstyp: ");
        scanf(" %c", &vtyp);
        printf("Betrag in Euro: ", betrag);
        scanf("%lf", &betrag);
        if(betrag < 0){
            printf("Der Betrag kann nicht negativ sein\n");
        }
        switch(vtyp){
            case 'e': // Einnahme (besteuert)
                printf("Gezahlte Steuern: %.2f", steuern(gezahlteSteuern));
                return guthaben;
            case 's': // Steuerfreie Einnahme
                printf("%.2f", guthaben+betrag);
                return guthaben;
            case 'k': // Kosten
                printf("");
                break;
            case '=':
                break;
        }
    }
}
