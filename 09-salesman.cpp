#include <stdio.h>
#include <conio.h>

int n, a[10][10], visited[10], cost = 0, start;

int least(int c) {
    // nc - next city 
    int nc = 999, min = 999;

    for (int i = 1; i <= n; i++)
        // if city is not visited and cost to that city is non zero,
        // non zero means there is a direct path to that city
        if (a[c][i] != 0 && visited[i] == 0)
            if (a[c][i] < min) {
                min = a[c][i];
                nc = i;
            }

    if (min != 999) cost += min;
    return nc;
}

void mincost(int city) {
    visited[city] = 1;
    printf("%d\t", city);

    int nextCity = least(city);

    if (nextCity == 999) {
        nextCity = start;
        printf("%d\t", nextCity);
        cost += a[city][nextCity];
        return;
    }

    mincost(nextCity);
    return;
}

int main() {
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // initially none is visited
    for (int i = 1; i <= n; i++)
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

NOTE: the loop counters have to start from 1 and loop termination conditions
have to be specifically adjusted otherwise the program will not work.

*/
