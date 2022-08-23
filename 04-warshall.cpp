#include <stdio.h>
#include <conio.h>

#define MAX 5

void transitiveClosure(int adjmat[MAX][MAX], int t[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(adjmat[i][j] == 1) t[i][j] = 1;
            else t[i][j] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                t[i][j] = t[i][j] || (t[i][k] && t[k][j]);
}

void main() {
    int n, adjmat[MAX][MAX], tr[MAX][MAX];
    clrscr();

    printf("Warshalls algorithm to find transitive closure of a matrix.\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjmat[i][j]);

    transitiveClosure(adjmat, tr, n);

    printf("Transitive closure of matrix is: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d", tr[i][j]);
        printf("\n");
    }

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
