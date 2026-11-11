

#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

void Dijkstra(int start)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest Distances:\n");

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d -> Not Reachable\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main()
{
    int edges, u, v, w, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    Dijkstra(start);

    return 0;
}
