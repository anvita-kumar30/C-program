#include <stdio.h>
int stack[10],choice,max,top,x,i;
void push(void);
void pop(void);
void peek(void);
void size(void);
void display(void);
int main()
{
    top=-1;
    printf("\n Enter the size of STACK[MAX=10]:");
    scanf("%d",&max);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.PEEK\n\t 4.SIZE\n\t 5.DISPLAY\n\t 6.EXIT");
    printf("\n\t--------------------------------");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                size();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5/6)");
            }
        }
    }
    while(choice!=6);
    return 0;
}
void push()
{
    if(top>=max-1)
    {
        printf("\n\tSTACK is overflow");
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\tStack is underflow");
    }
    else
    {
        printf("\n\t The popped element is %d",stack[top]);
        top--;
    }
}
void peek()
{
    if(top<=-1)
    {
        printf("\n\tStack is underflow");
    }
    else
    {
        printf("The item present on the top of the stack is %d\n",stack[top]);
    }
}
void size()
{
    int count=0;
    if(top>=0)
    {
        printf("The number of elements in STACK:");
        for(i=top; i>=0; i--){
            count++;
        }
        printf(" %d\n",count);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK ");
        for(i=top; i>=0; i--)
        {
            printf("\n%d",stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
