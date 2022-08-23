#include <stdio.h>
#include <conio.h>

#define MAX 5

void transitiveClosure(int adjmat[MAX][MAX], int node) {
    for (int k = 0; k < node; k++)
        for (int i = 0; i < node; i++)
            for (int j = 0; j < node; j++)
                adjmat[i][j] = adjmat[i][j] || (adjmat[i][k] && adjmat[k][j]);

    printf("Transitive closure of matrix is: \n");
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++)
            printf("%d", adjmat[i][j]);
        printf("\n");
    }
}

void main() {
    int node, adjmat[MAX][MAX];
    clrscr();

    printf("Warshalls algorithm to find transitive closure of a matrix.\n");
    printf("Enter number of vertices: ");
    scanf("%d", &node);

    printf("Enter the matrix:\n");
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            scanf("%d", &adjmat[i][j]);

    transitiveClosure(adjmat, node);

    getch();
}

/* OUTPUT:
Warshalls algorithm to find transitive closure of a matrix.
Enter number of vertices: 4
Enter the matrix:
0 1 0 0 
0 0 0 1
0 0 0 0
1 0 1 0
Transitive closure of matrix is:
1 1 1 1
1 1 1 1 
0 0 0 0
1 1 1 1
*/
