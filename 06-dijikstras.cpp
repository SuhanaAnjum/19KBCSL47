#include <iostream.h>
#include <conio.h>

#define INFI 999
#define MAX 5

void dijkstra(int G[MAX][MAX], int nodes, int startNode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX], count, minDis, nextNode;

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            if(G[i][j] == 0)
                cost[i][j] = INFI;
            else cost[i][j] = G[i][j];

    for (int i = 0; i < nodes; i++) {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while(count < nodes - 1) {
        minDis = INFI;
        for (int i = 0; i < nodes; i++) {
            if(distance[i] < minDis && !visited[i]) {
                minDis = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;
        for (int i = 0; i < nodes; i++) {
            if(!visited[i] && minDis + cost[nextNode][i] < distance[i]) {
                distance[i] = minDis + cost[nextNode][i];
                pred[i] = nextNode;
            }
            count++;
        }

        for (int i = 0; i < nodes; i++) {
            if(i != startNode) {
                cout << "\nDistance of node " << i + 1 << ":" << distance[i];
                cout << "\nPath " << i + 1;
                int j = i;
                do {
                    j = pred[j];
                    cout << " <- " << j + 1;
                } while(j != startNode);
            }
        }
    }
}

int main() {
    int G[MAX][MAX], stnode, nodes;
    clrscr();

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            cin >> G[i][j];

    cout << "Enter the source node: ";
    cin >> stnode;

    dijkstra(G, nodes, stnode - 1);

    getch();
}

/* OUTPUT:
Enter number of nodes: 5
Enter adjacency matrix:
0 3 999 7 999
3 0 4 2 999
999 4 0 5 6
7 2 5 0 4
999 999 6 4 0
Enter the source node: 1

Distance of node 2:3
Path 2 <- 1
Distance of node 3:7
Path 3 <- 2 <- 1
Distance of node 4:5
Path 4 <- 2 <- 1
Distance of node 5:9
Path 5 <- 4 <- 2 <- 1
? */

