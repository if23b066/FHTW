#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    Horror = 1,
    Abenteuer,
    Romantik,
    Sachbuch
} genre_type;

const char* getGenre(genre_type genre)
{
    switch(genre)
    {
        case Horror: return "Horror"; break;
        case Abenteuer: return "Abenteuer"; break;
        case Romantik: return "Romantik"; break;
        case Sachbuch: return "Sachbuch"; break;
    }
    return 0;
}

typedef struct book
{
    char title[32];
    genre_type genre;
    int year;
    int amount;
    int dur;
} book;

typedef struct bookNode
{
    book content;
    struct bookNode* next;
} bookNode;

typedef struct borrowNode
{
    char title[32];
    char name[32];
    struct borrowNode* next;
} borrowNode;

bookNode* insertBook(bookNode* inventory)
{
    book newBook;

    printf("\nGeben Sie den Titel ein: ");
    scanf(" %s", newBook.title);
    while(1)
    {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf(" %d", (int*)&newBook.genre);
        if(newBook.genre < 1 || newBook.genre > 4)
        {
            printf("\nUngueltige Eingabe!");
        }
        else
        {
            break;
        }
    }
    while(1)
    {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf(" %d", &newBook.year);
        if(newBook.year <= 0)
        {
            printf("\nUngueltige Eingabe!");
        }
        else
        {
            break;
        }
    }
    while(1)
    {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf(" %d", &newBook.amount);
        if(newBook.amount < 1)
        {
            printf("\nUngueltige Eingabe!");
        }
        else
        {
            newBook.dur = newBook.amount;
            break;
        }
    }

    bookNode* newItem = (bookNode*)malloc(sizeof(bookNode));
    newItem->content = newBook;
    newItem->next = inventory;

    return newItem;
}

int printList(bookNode* inventory)
{
    int count = 0;
    if (inventory != NULL)
    {
        printf("\n");
        while (inventory != NULL)
        {
            printf("%d: %s, %s (%d)\n", count+1, inventory->content.title, getGenre(inventory->content.genre), inventory->content.year);
            inventory = inventory->next;
            count++;
        }
    }
    return count;
}

int printBorrowedList(borrowNode** borrowedBooks)
{
    int countB = 0;
    if(*borrowedBooks != NULL)
    {
        printf("\n");
        borrowNode* current = *borrowedBooks;
        while(current != NULL)
        {
            printf("%d: %s geliehen von %s\n", countB+1, current->title, current->name);
            current = current->next;
            countB++;
        }
    }
    else
    {
        printf("\nEs sind keine Titel ausgeliehen\n");
    }
    return countB;
}

void borrowBook(bookNode* inventory, borrowNode** borrowedBooks, int count)
{
    bookNode* chosenBook = inventory;
    if(inventory == NULL)
    {
        printf("\nEs sind keine Buecher im Inventar vorhanden.\n");
    }
    else
    {
        int choice;
        while(1)
        {
            printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", count);
            scanf(" %d", &choice);
            if(choice < 1 || choice > count)
            {
                printf("\nUngueltige Eingabe!");
            }
            else
            {
                break;
            }
        }
        for(int i = 1; i < choice; i++)
        {
            chosenBook = chosenBook->next;
        }
        char name[32];
        printf("\nGeben Sie Ihren Namen ein: ");
        scanf(" %s", name);
        borrowNode* current = *borrowedBooks;
        while(current != NULL)
        {
            if(strcmp(current->title, chosenBook->content.title) == 0 && strcmp(current->name, name) == 0)
            {
                printf("\nSie haben diesen Titel bereits ausgeliehen!");
                return;
            }
            current = current->next;
        }
        if(chosenBook->content.dur <= 0)
        {
            printf("\nBereits alle Exemplare ausgeliehen!\n");
        }
        else
        {
            borrowNode* borrowEntry = (borrowNode*)malloc(sizeof(borrowNode));
            strcpy(borrowEntry->title, chosenBook->content.title);
            strcpy(borrowEntry->name, name);
            borrowEntry->next = *borrowedBooks;
            *borrowedBooks = borrowEntry;
            chosenBook->content.dur--;
        }
    }
}

void returnBook(borrowNode** borrowedBooks, bookNode **inventory, int countB)
{
    int choice;

    if(*borrowedBooks == NULL)
    {
        printf("\nEs sind keine Titel ausgeliehen!\n");
        return;
    }
    while(1)
    {
        printf("\nWelchen Titel moechten Sie retournieren? (1-%d): ", countB);
        scanf("%d", &choice);
        if(choice < 1 || choice > countB)
        {
            printf("\nUngueltige Eingabe!");
        }
        else
        {
            break;
        }
    }
    borrowNode* temp = *borrowedBooks;
    if(choice == 1)
    {
        *borrowedBooks = temp->next;
        bookNode* currentBook = *inventory;

        while(currentBook != NULL && strcmp(currentBook->content.title, temp->title) != 0)
        {
            currentBook = currentBook->next;
        }
        if(currentBook != NULL)
        {
            currentBook->content.dur++;
        }
        free(temp);
    }
    else
    {
        borrowNode* current = temp;
        for(int i = 1; i < choice - 1; i++)
        {
            temp = temp->next;
            current = temp;
        }
        borrowNode* toDelete = temp->next;
        temp->next = toDelete->next;

        bookNode* currentBook = *inventory;
        while(currentBook != NULL && strcmp(currentBook->content.title, toDelete->title) != 0)
        {
            currentBook = currentBook->next;
        }
        if(currentBook != NULL)
        {
            currentBook->content.dur++;
        }
        free(toDelete);
    }
}

void printListInOrder(bookNode* inventory)
{
    int count = 0;
    bookNode* booksArray = NULL;
    bookNode* current = inventory;

    while(current != NULL)
    {
        booksArray = realloc(booksArray, (count + 1) * sizeof(bookNode));
        booksArray[count] = *current;
        count++;
        current = current->next;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(booksArray[j].content.year > booksArray[j + 1].content.year)
            {
                bookNode temp = booksArray[j];
                booksArray[j] = booksArray[j+1];
                booksArray[j+1] =  temp;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d: %s, %s (%d)\n", i+1, booksArray[i].content.title, getGenre(booksArray[i].content.genre), booksArray[i].content.year);
    }
}

void freeMemory(bookNode* inventory, borrowNode* borrowedBooks)
{
    while (inventory != NULL)
    {
        bookNode* temp = inventory;
        inventory = inventory->next;
        free(temp);
    }

    while (borrowedBooks != NULL)
    {
        borrowNode* temp = borrowedBooks;
        borrowedBooks = borrowedBooks->next;
        free(temp);
    }
}

int main()
{
    char input;
    bookNode* inventory = NULL;
    borrowNode* borrowedBooks = NULL;
    int count;
    int countB;
    do
    {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &input);
        switch(input)
        {
            case 'n': inventory = insertBook(inventory); break;
            case 'b': count = printList(inventory); borrowBook(inventory, &borrowedBooks, count); break;
            case 'r': countB = printBorrowedList(&borrowedBooks); returnBook(&borrowedBooks, &inventory, countB); break;
            case 'l': printList(inventory); break;
            case 's': printListInOrder(inventory); break;
            case 'x': break;
            default: printf("\nUngueltige Eingabe!"); break;
        }
    } while(input != 'x');
    freeMemory(inventory, borrowedBooks);
    return 0;
}
