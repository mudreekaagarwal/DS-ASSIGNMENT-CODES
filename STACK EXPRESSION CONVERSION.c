
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE][SIZE];
int top = -1;

void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

void pop(char str[])
{
    strcpy(str, stack[top]);
    top--;
}

void postfixToInfix(char exp[])
{
    int i;
    char x;
    char op1[SIZE], op2[SIZE];
    char temp[SIZE];
    char op[2];

    top = -1;

    for (i = 0; exp[i] != '\0'; i++)
    {
        x = exp[i];

        if (isalnum(x))
        {
            temp[0] = x;
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            pop(op2);
            pop(op1);

            temp[0] = '\0';

            op[0] = x;
            op[1] = '\0';

            strcat(temp, "(");
            strcat(temp, op1);
            strcat(temp, op);
            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(temp);

    printf("Infix Expression: %s\n", temp);
}

void prefixToInfix(char exp[])
{
    int i;
    char x;
    char op1[SIZE], op2[SIZE];
    char temp[SIZE];
    char op[2];

    top = -1;

    for (i = strlen(exp) - 1; i >= 0; i--)
    {
        x = exp[i];

        if (isalnum(x))
        {
            temp[0] = x;
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            pop(op1);
            pop(op2);

            temp[0] = '\0';

            op[0] = x;
            op[1] = '\0';

            strcat(temp, "(");
            strcat(temp, op1);
            strcat(temp, op);
            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(temp);

    printf("Infix Expression: %s\n", temp);
}

int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 4;

    if (ch == '(')
        return 5;

    return 0;
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 3;

    if (ch == '(')
        return 0;

    return 0;
}

void infixToPostfix(char exp[])
{
    int i;
    char x;
    char temp[SIZE];
    char op[2];

    top = -1;
    temp[0] = '\0';

    for (i = 0; exp[i] != '\0'; i++)
    {
        x = exp[i];

        if (isalnum(x))
        {
            op[0] = x;
            op[1] = '\0';

            strcat(temp, op);
        }
        else if (x == '(')
        {
            op[0] = x;
            op[1] = '\0';

            push(op);
        }
        else if (x == ')')
        {
            while (top != -1 && stack[top][0] != '(')
            {
                pop(op);
                strcat(temp, op);
            }

            if (top != -1)
                pop(op);
        }
        else
        {
            while (top != -1 &&
                   isp(stack[top][0]) >= icp(x))
            {
                pop(op);
                strcat(temp, op);
            }

            op[0] = x;
            op[1] = '\0';

            push(op);
        }
    }

    while (top != -1)
    {
        pop(op);
        strcat(temp, op);
    }

    printf("Postfix Expression: %s\n", temp);
}

int main()
{
    int choice;
    char exp[SIZE];

    do
    {
        printf("\n--- Expression Conversion ---\n");
        printf("1. Postfix to Infix\n");
        printf("2. Prefix to Infix\n");
        printf("3. Infix to Postfix\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Postfix Expression: ");
                scanf("%s", exp);

                postfixToInfix(exp);
                break;

            case 2:
                printf("Enter Prefix Expression: ");
                scanf("%s", exp);

                prefixToInfix(exp);
                break;

            case 3:
                printf("Enter Infix Expression: ");
                scanf("%s", exp);

                infixToPostfix(exp);
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
