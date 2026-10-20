#include <stdio.h>

#define n 5

int Q[n];
int front = 0, rear = 0;

void AddCQ(int elem)
{
    if ((rear + 1) % n == front)
    {
        printf("Queue Full\n");
    }
    else
    {
        rear = (rear + 1) % n;
        Q[rear] = elem;
        printf("Print Job %d added to queue.\n", elem);
    }
}

void DelCQ()
{
    int elem;

    if (front == rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        front = (front + 1) % n;
        elem = Q[front];
        printf("Print Job %d processed.\n", elem);
    }
}

void DisplayCQ()
{
    int i;

    if (front == rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Pending Print Jobs:\n");

        i = (front + 1) % n;

        while (i != (rear + 1) % n)
        {
            printf("%d ", Q[i]);
            i = (i + 1) % n;
        }

        printf("\n");
    }
}

int main()
{
    int choice, job;

    do
    {
        printf("\n--- Printer Queue Manager ---\n");
        printf("1. Add a Print Job\n");
        printf("2. Process a Print Job\n");
        printf("3. Display All Pending Print Jobs\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Print Job number: ");
                scanf("%d", &job);
                AddCQ(job);
                break;

            case 2:
                DelCQ();
                break;

            case 3:
                DisplayCQ();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}