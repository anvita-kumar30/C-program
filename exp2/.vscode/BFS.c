#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void breadth_first_search(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front =-1, i;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[++front];
        if (start == 4)
            printf("5\t");
        else
            printf("%c \t", start + 65);
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void create_graph()
{
    int count, max_edge, origin, destin;

    printf("Enter number of vertices : ");
    scanf("%d", &n);
    max_edge = n * (n - 1);

    for (count = 1; count <= max_edge; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ", count);
        scanf("%d %d", &origin, &destin);

        if ((origin == -1) && (destin == -1))
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}
int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}
int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}
void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}
void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    while (!isEmpty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}
int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    printf("\n Enter the adjacency matrix: ");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);
    breadth_first_search(adj, visited, 0);
    return 0;
    create_graph();
    BF_Traversal();
    return 0;
}

void BF_Traversal()
{
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(v);
}