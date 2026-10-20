#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(int ele)
{
    stack[++top] = ele;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char exp[])
{
    int i, op1, op2, result;
    top = -1;

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
            push(exp[i] - '0');
        else
        {
            op1 = pop();
            op2 = pop();

            switch(exp[i])
            {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
            }

            push(result);
        }
    }

    return pop();
}

int evaluatePrefix(char exp[])
{
    int i, op1, op2, result;
    top = -1;

    for(i = strlen(exp) - 1; i >= 0; i--)
    {
        if(isdigit(exp[i]))
            push(exp[i] - '0');
        else
        {
            op1 = pop();
            op2 = pop();

            switch(exp[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
    }

    return pop();
}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

int evaluateInfix(char exp[])
{
    int values[20], vtop = -1;
    char operators[20];
    int otop = -1;
    int i, op1, op2, result;

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
            values[++vtop] = exp[i] - '0';

        else if(exp[i] == '(')
            operators[++otop] = exp[i];

        else if(exp[i] == ')')
        {
            while(otop >= 0 && operators[otop] != '(')
            {
                op1 = values[vtop--];
                op2 = values[vtop--];

                switch(operators[otop--])
                {
                    case '+': result = op2 + op1; break;
                    case '-': result = op2 - op1; break;
                    case '*': result = op2 * op1; break;
                    case '/': result = op2 / op1; break;
                }

                values[++vtop] = result;
            }
            otop--;
        }

        else
        {
            while(otop >= 0 &&
                  operators[otop] != '(' &&
                  precedence(operators[otop]) >= precedence(exp[i]))
            {
                op1 = values[vtop--];
                op2 = values[vtop--];

                switch(operators[otop--])
                {
                    case '+': result = op2 + op1; break;
                    case '-': result = op2 - op1; break;
                    case '*': result = op2 * op1; break;
                    case '/': result = op2 / op1; break;
                }

                values[++vtop] = result;
            }

            operators[++otop] = exp[i];
        }
    }

    while(otop >= 0)
    {
        op1 = values[vtop--];
        op2 = values[vtop--];

        switch(operators[otop--])
        {
            case '+': result = op2 + op1; break;
            case '-': result = op2 - op1; break;
            case '*': result = op2 * op1; break;
            case '/': result = op2 / op1; break;
        }

        values[++vtop] = result;
    }

    return values[vtop];
}

int main()
{
    int choice, result;
    char exp[20];

    do
    {
        printf("\n1. Infix Evaluation");
        printf("\n2. Prefix Evaluation");
        printf("\n3. Postfix Evaluation");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 4)
        {
            printf("Exiting...\n");
            break;
        }

        printf("Enter expression: ");
        scanf("%s", exp);

        switch(choice)
        {
            case 1:
                result = evaluateInfix(exp);
                break;

            case 2:
                result = evaluatePrefix(exp);
                break;

            case 3:
                result = evaluatePostfix(exp);
                break;

            default:
                printf("Invalid choice\n");
                continue;
        }

        printf("Result = %d\n", result);

    } while(choice != 4);

    return 0;
}