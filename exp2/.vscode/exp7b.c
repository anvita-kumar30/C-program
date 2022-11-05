// WAP to implement Stack ADT using Linked List
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int isEmpty(struct stack *);
int peek(struct stack *);
int main(int argc, char *argv[])
{
    int val, option;
    printf("\n *****MAIN MENU*****");
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. PEEK");
    printf("\n 4. isEmpty");
    printf("\n 5. DISPLAY");
    printf("\n 6. EXIT");
    do
    {
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
                printf("\n The value at the top of stack is: %d", val);
            else
                printf("\n STACK IS EMPTY");
            break;
        case 4:
            if (top == NULL)
                printf(" Stack is empty");
            else
                printf(" Stack is not empty");
            break;
        case 5:
            top = display(top);
            break;
        }
    } while (option != 6);
    return 0;
}
struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}
struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK IS EMPTY");
    else
    {
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK UNDERFLOW");
    else
    {
        top = top->next;
        printf("\n The value being deleted is: %d", ptr->data);
        free(ptr);
    }
    return top;
}
int isEmpty(struct stack *top)
{
    if (top == NULL)

    {
        printf("Underflow");
        return 0;
    }
    else
        printf("SStack is not empty");
    return 1;
}
int peek(struct stack *top)
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}