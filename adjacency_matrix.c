
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int n;

// Create Graph Function
void CreateGraph(int edges)
{
    int u, v;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

// Display Adjacency Matrix Function
void DisplayMatrix()
{
    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    CreateGraph(edges);

    DisplayMatrix();

    return 0;
}

