#include <stdio.h>
#include <conio.h>

#define MAX 5

void transitiveClosure(int adjmat[MAX][MAX], int t[MAX][MAX], int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(adjmat[i][j] == 1) t[i][j] = 1;
            else t[i][j] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                t[i][j] = t[i][j] || (t[i][k] && t[k][j]);
}

void main(){
    int adjmat[MAX][MAX], n, tr[MAX][MAX];
    clrscr();

    printf("Warshalls algorithm to find transitive closure of a matric\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the matrix\n");
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

