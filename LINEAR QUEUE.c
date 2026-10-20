#include <stdio.h>
#include <string.h>
#define size 5

struct que
{
    int jobid;
    char tittle[20];
};

int rear = -1;
int front = -1;
struct que q[size];

int isfull()
{
    if(rear == size - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(rear == front)
        return 1;
    else
        return 0;
}

void ADDQ(struct que ele)
{
    if(isfull())
    {
        printf("queue is full\n");
    }
    else
    {
        rear = rear + 1;
        q[rear] = ele;
        printf("job added successfully\n");
    }
}

void DELETEQ()
{
    if(isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        front = front + 1;

        printf("Job ID: %d\n", q[front].jobid);
        printf("Title: %s\n", q[front].tittle);
        printf("the element is deleted\n");
    }
}

void display()
{
    int i;

    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i = front + 1; i <= rear; i++)
        {
            printf("Job ID: %d\n", q[i].jobid);
            printf("Title: %s\n", q[i].tittle);
        }
    }
}

int main()
{
    int choice;
    struct que ele;

    do
    {
        printf("\n1. Add Job");
        printf("\n2. Delete Job");
        printf("\n3. Display Queue");
        printf("\n4. Exit");

        printf("\nEnter the user choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("enter the jobid of the people: ");
                scanf("%d", &ele.jobid);

                printf("enter the jobtittle of the people: ");
                scanf("%s", ele.tittle);

                ADDQ(ele);
                break;

            case 2:
                DELETEQ();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}