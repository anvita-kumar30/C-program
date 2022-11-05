//WAP to implement Hashing Table using array
#include <stdio.h>
#include <stdlib.h>
#define max 10
int hashing(int val)
{
    return val % max;
}
void linearprob(int a[], int val)
{
    for (int i = 0; i < max; i++)
    {
        int code = hashing(hashing(val) + i);
        if (a[code] == -1)
        {
            a[code] = val;
            break;
        }
    }
}
void quadprob(int a[], int val)
{
    for (int i = 0; i < max; i++)
    {
        int code = hashing(hashing(val) + i * i);
        if (a[code] == -1)
        {
            a[code] = val;
            break;
        }
    }
}
void display(int a[])
{
    printf("------------------------------------------------------\n");
    for (int i = 0; i < max; i++)
    {
        printf("| %d ", a[i]);
    }
    printf("|\n------------------------------------------------------\n");
}
void create(int a[])
{
    for (int i = 0; i < max; i++)
    {
        a[i] = -1;
    }
}
int main()
{
    int val, choice, n, a[max];
    printf("This program is an implementation of hashing table using array\n\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    do
    {
        create(a);
        printf("Choose collision resolution method:\n");
        printf("1. LINEAR PROBING\n2. QUADRATIC\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        for (int i = 0; i < n; i++)
        {
            printf("Enter Inserting Element: ");
            scanf("%d", &val);
            switch (choice)
            {
            case 1:
                linearprob(a, val);
                display(a);
                break;
            case 2:
                quadprob(a, val);
                display(a);
                break;
            case 3:
                printf("\n\tEXIT POINT!");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}