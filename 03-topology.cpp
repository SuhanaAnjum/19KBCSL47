#include <stdio.h>
#include <conio.h>

int a[10][10], indegree[10], n;

void find_indegree() {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            // a[j][i] gives the incomming edges
            // a[i][j] gives the outgoing edges
            sum += a[j][i];
        indegree[i] = sum;
    }
}

void topology() {
    int stack[10], top = -1, visited[10], visitedTop = 0;
    find_indegree();

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            stack[++top] = i;
    
    while (top != -1) {
        int u = stack[top--];
        visited[visitedTop++] = u;
        for (int i = 0; i < n; i++)
            if (a[u][i] == 1) {
                // the node that is visited remove its outgoing edges
                indegree[i]--;
                if (indegree[i] == 0)
                    stack[++top] = i;
            }
    }

    printf("The topological sorting is:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", visited[i]);
    printf("\n");
}

void main() {
    clrscr();

    printf("Enter number of vertices of DAG: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topology();

    getch();
}

/* OUTPUT:
Enter number of vertices of DAG: 5
Enter the adjacency matrix:
0 1 0 1 0
0 0 1 1 0
0 0 0 0 0
0 0 1 0 1
0 0 0 0 0
The topological sorting is:
0 1 3 4 2
*/
