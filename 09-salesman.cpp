#include <stdio.h>
#include <conio.h>

int a[10][10], visited[10], n, cost = 0, start;

int least(int c) {
    int nc = 999;
    int min = 999;

    for (int i = 0; i < n; i++)
        if(a[c][i] != 0 && visited[i] == 0)
            if(a[c][i] < min) {
                min = a[c][i];
                nc = i;
            }

    if(min != 999) cost += min;
    return nc;
}

void mincost(int city) {
    visited[city] = 1;
    
    printf("%d\t", city);
    int ncity = least(city);

    if(ncity == 999) {
        ncity = start;
        printf("%d\t", ncity);
        cost += a[city][ncity];
        return;
    }

    mincost(ncity);
    return;
}

int main() {
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    mincost(start);

    printf("\nCost is: %d\n", cost);

    getch();
}

/* OUTPUT:
Enter the number of vertices: 4
Enter the cost matrix:
0 16 11 6
8 0 13 16
4 7 0 9
5 12 2 0
Enter the start vertex: 1
1       4       3       2       1
Cost is: 23
? */

