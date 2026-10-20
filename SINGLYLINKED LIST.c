
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int regno;
    char name[10];
    struct node *next;
};


void create(struct node **head)
{
    *head = NULL;
}


void add(struct node **head)
{
    struct node *p, *t;

    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter registration number: ");
    scanf("%d", &p->regno);

    printf("Enter name: ");
    scanf("%9s", p->name);

    p->next = NULL;

    if (*head == NULL)
    {
        *head = p;
    }
    else
    {
        t = *head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = p;
    }

    printf("Student added\n");
}


void deleteNode(struct node **head)
{
    int r;
    struct node *t, *p = NULL;

    printf("Enter regno to delete: ");
    scanf("%d", &r);

    t = *head;

    while (t != NULL && t->regno != r)
    {
        p = t;
        t = t->next;
    }

    if (t == NULL)
    {
        printf("Student not found\n");
        return;
    }

    if (p == NULL)
    {
        *head = t->next;
    }
    else
    {
        p->next = t->next;
    }

    free(t);

    printf("Student deleted\n");
}


void display(struct node *head)
{
    struct node *t = head;

    if (t == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nStudent details:\n");

    while (t != NULL)
    {
        printf("Reg No: %d\tName: %s\n", t->regno, t->name);
        t = t->next;
    }
}


void count(struct node *head)
{
    int c = 0;

    while (head != NULL)
    {
        c++;
        head = head->next;
    }

    printf("Total students = %d\n", c);
}


void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *nextNode;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    *head = prev;

    printf("List reversed\n");
}

int main()
{
    struct node *head = NULL;
    int ch;

    create(&head);

    do
    {
        printf("\n\n----- STUDENT LINKED LIST -----");
        printf("\n1. Add");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Count");
        printf("\n5. Reverse");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                add(&head);
                break;

            case 2:
                deleteNode(&head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                count(head);
                break;

            case 5:
                reverse(&head);
                break;

            case 6:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 6);

    return 0;
}

