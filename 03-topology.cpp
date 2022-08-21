#include <stdio.h>
#include <conio.h>

int a[10][10], indegree[10], n;

void find_indegree(){
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += a[j][i];
        indegree[i] = sum;
    }
}

void topology(){
    int s[10], sTop = -1, u, t[10], tTop = 0;
    find_indegree();

    for (int i = 0; i < n; i++)
        if(indegree[i] == 0)
            s[++sTop] = i;
    
    while(sTop != -1){
        u = s[sTop--];
        t[tTop++] = u;
        for (int i = 0; i < n; i++) {
            if(a[u][i] == 1){
                indegree[i]--;
                if(indegree[i] == 0)
                    s[++sTop] = i;
            }
        }
    }

    printf("The topological sorting is:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", t[i]);
    printf("\n");
}

void main(){
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

