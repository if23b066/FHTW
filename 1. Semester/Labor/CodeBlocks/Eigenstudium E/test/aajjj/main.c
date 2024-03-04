#include <stdio.h>
#include <stdlib.h>

enum Type{Freunde, Geschaeftlich, Pause};

struct appointment
{
    enum Type type;
    int time;
    int duration;
};

const char* getTypeName(enum Type type) // Funktion um Enum-Text auszugeben
{
    switch(type)
    {
        case Freunde: return "Freunde"; break;
        case Geschaeftlich: return "Geschaeftlich"; break;
        case Pause: return "Pause"; break;
    }
    return 0;
}

struct appointment createAppointment()  // Funktion um Termin zu kreieren
{
    struct appointment neuerTermin;
    char type;
    int maxDauer;

    while(1)
    {
        printf("Gib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): \n");
        scanf(" %c", &type);
        if(type == 'f' || type == 'b' || type == 'p')
        {
            switch(type)
            {
                case 'f': neuerTermin.type = Freunde; break;
                case 'b': neuerTermin.type = Geschaeftlich; break;
                case 'p': neuerTermin.type = Pause; break;
            }
            break;
        }
        else
        {
            printf("Ungueltige Eingabe!\n");
        }
    }

    while(1)
    {
        printf("Gib eine Uhrzeit ein (8-21): \n");
        scanf(" %d", &neuerTermin.time);
        if(neuerTermin.time < 8 || neuerTermin.time > 21)
        {
            printf("Ungueltige Eingabe!\n");
        }
        else
        {
            break;
        }
    }

    maxDauer = 22 - neuerTermin.time;
    while(1)
    {
        printf("Gib eine Dauer ein (1-%d): \n", maxDauer);
        scanf(" %d", &neuerTermin.duration);
        if(neuerTermin.duration < 1 || neuerTermin.duration > maxDauer)
        {
            printf("Ungueltige Eingabe!\n");
        }
        else
        {
            break;
        }
    }
    return neuerTermin;
}


void printAppointments(struct appointment *schedule, int length) // 'l'-Eingabe (Termine ausgeben
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("%d: %s: %d Uhr, Dauer %dh\n", i+1, getTypeName(schedule[i].type), schedule[i].time, schedule[i].duration);
    }
}

void printInformation(struct appointment *schedule, int length) // 'i'-Eingabe (Information ausgeben)
{
    int i;
    int col = 0;
    int countF = 0, countG = 0, countP = 0;

    if(col < 1)
    {
        printf("Der Kalender hat keine Kollisionen!\n");
    }
    for(i = 0; i < length - 1; i++)
    {
        if((schedule[i].time + schedule[i].duration) > schedule[i + 1].time)
        {
            col++;
            printf("Entweder Termin %d oder Termin %d sollte abgesagt werden.\n", i+1, i+2);
        }
        else
        {
            int uZeit = schedule[i + 1].time - (schedule[i].time + schedule[i].duration);
            if(uZeit > 0)
            {
                printf("Zwischen den Terminen %d und %d liegen %dh ungeplante Zeit.\n", i+1, i+2, uZeit);
            }
        }
    }
    for(i = 0; i < length; i++)
    {
        switch(schedule[i].type)
        {
            case Freunde: countF++; break;
            case Geschaeftlich: countG++; break;
            case Pause: countP++; break;
        }
    }
    printf("Sie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.\n", countG, countF, countP);
}

void addAppointment(struct appointment *schedule, int *length) // 'n'-Eingabe (Neuen Termin)
{
    if(*length >= 10)
    {
        printf("Der Kalender ist voll!\n");
    }
    else
    {
        struct appointment neuerTermin = createAppointment();
        schedule[*length] = neuerTermin;
        int pos = *length;
        for(int i = 0; i < *length; i++)
        {
            if(neuerTermin.time < schedule[i].time)
            {
                pos = i;
                break;
            }
        }
        for(int i = *length; i > pos; i--)
        {
            schedule[i] = schedule[i - 1];
        }
        schedule[pos] = neuerTermin;
        (*length)++;
    }
}

void deleteAppointment(struct appointment *schedule, int *length) // 'd'-Eingabe (Termin loeschen)
{
    int del;

    if(*length == 0)
    {
        printf("Der Kalender ist leer!\n");
    }
    else
    {
        printAppointments(schedule, *length);
        printf("Welchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);
        while(1)
        {
            scanf("%d", &del);
            if(del < 1 || del > *length)
            {
                printf("Ungueltige Eingabe!");
            }
            else
            {
                printf("\nTermin %d wurde geloescht!\n", del);
                for(int i = del - 1; i < *length - 1; i++)
                {
                    schedule[i] = schedule[i + 1];
                }
                (*length)--;
                break;
            }
        }
    }
}

int main()
{
    struct appointment schedule[10];
    int length = 0;
    char auswahl;
    printf("\n");
    do
    {
        printf("Neuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)\nAuswahl: \n");
        scanf(" %c", &auswahl);
        switch(auswahl)
        {
            case 'n': addAppointment(schedule, &length); break;
            case 'd': deleteAppointment(schedule, &length); break;
            case 'l': printAppointments(schedule, length); break;
            case 'i': printInformation(schedule, length); break;
            case 'x': break;
            default: printf("Ungueltige Eingabe!\n"); break;
        }
    } while(auswahl != 'x');
    return 0;
}
