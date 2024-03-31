#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node* next;
}node;

void printList(struct node* head)
{
    if(head != NULL)
    {
        printf("%d  ", head->element);
        printList(head->next);
    }
}

struct node* insertAtBeginning(int input, node* head)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = input;
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(int input, node* head)
{
    /*if(head == NULL)
    {
        return head;
    }
    struct node* newHead = head->next;
    free(head);*/

    if(head == NULL)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->element = input;
        newNode->next = NULL;
        return newNode;
    }
    else
    {
        head->next = insertAtEnd(input, head->next);
    }
    return head;
}

void freeList(node* head)
{
    node* current = head;

    while(current != NULL)
    {
        head = head->next;
        free(current);
        current = head;
    }
}

int main()
{
    int input;
    node* head = NULL;

    while(1)
    {
        scanf("%d", &input);
        if(input == 0)
        {
            break;
        }

        if(input % 2 == 0)
        {
            head = insertAtBeginning(input, head);
        }
        else
        {
            head = insertAtEnd(input, head);
        }
        printList(head);
        printf("\n");
    }

    freeList(head);
    return 0;
}
