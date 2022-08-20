#include <iostream.h>
#include <conio.h>

#define NODE 5
#define INFI 999

int costMat[NODE][NODE];

void floyd(int costMat[NODE][NODE], int node){
    int cost[NODE][NODE];
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            cost[i][j] = costMat[i][j];

    for (int k = 0; k < node; k++)
        for (int i = 0; i < node; i++)
            for (int j = 0; j < node; j++)
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];

    cout << "All pair shorttest path matrix:" << endl;
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++)
            cout << " " << cost[i][j];
        cout << endl;
    }
}

void main(){
    int node;
    clrscr();
    cout << "Enter number of vertices: ";
    cin >> node;
    
    cout << "Enter weighted adjacency matrix:" << endl;
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            cin >> costMat[i][j];

    floyd(costMat, node);

    getch();
}

