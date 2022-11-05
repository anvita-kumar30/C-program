//WAP to implement infix to postfix conversion using stack and vice versa

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 100

float st[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

char peek()
{
    return st[top];
}

void push(float val)
{
    if (isFull())
        printf("\n STACK OVERFLOW");
    else
    {
        top++;
        st[top] = val;
    }
}

void pushi(char value)
{
    if (isFull())
        printf("Stack Full!");

    else
    {
        top++;
        st[top] = value;
    }
}

float pop(float st[])
{
    float val = -1;
    if (isEmpty())
        printf("\n STACK UNDERFLOW");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

char popi()
{
    char ch = -1;
    if (isEmpty())
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        ch = st[top];
        top--;
    }
    return (ch);
}

// Function to check if the given character is operand
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Fucntion to compare precedence
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

float evaluatePostfixExp(char exp[])
{
    int i = 0;
    float op1, op2, value;
    printf("\n Enter a postfix expression : ");
    scanf("%s", exp);
    while (exp[i] != '\0')
    {
        if (checkIfOperand(exp[i]))
            push((float)(exp[i] - '0'));
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(value);
        }
        i++;
    }
    float answer = pop(st);
    printf("\n Value of the postfix expression = %.2f", answer);
    return answer;
}

int covertInfixToPostfix(char *exp)
{
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    int i, j;
    for (i = 0, j = -1; exp[i]; ++i)
    {
        // Checking if the character is operand or not and adding to the output
        if (checkIfOperand(exp[i]))
            exp[++j] = exp[i];

        // If character is ‘(‘, we need push it to the stack
        else if (exp[i] == '(')
            pushi(exp[i]);

        // If character is ‘)’, we need to pop and print from the stack
        // Do this until an ‘(‘ is encountered in the stack.
        else if (exp[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                exp[++j] = popi();
            if (!isEmpty() && peek() != '(')
                return -1; // invalid expression
            else
                popi();
        }
        else // if an opertor
        {
            while (!isEmpty() && precedence(exp[i]) <= precedence(peek()))
                exp[++j] = popi();
            pushi(exp[i]);
        }
    }

    // Once all inital expression characters are traversed
    // Adding all elements from stack to expression
    while (!isEmpty())
        exp[++j] = popi();

    exp[++j] = '\0';
    printf("Final postfix expression is: %s", exp);
}

int main()
{
    float val;
    char exp[100];
    int ch;
    printf("\n");
    printf("Enter a choice(1 for infix to postfix, 2 for postfix to infix): ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        covertInfixToPostfix(exp);
        break;
    case 2:
        val = evaluatePostfixExp(exp);
        break;
    default:
        printf("Invalid choice!");
    }
    return 0;
}
