#include <iostream.h>
#include <conio.h>

#define ROW 7
#define COL 7
#define INFI 999
#define FALSE 0
#define TRUE 1

class Prims {
    int graph[ROW][COL], nodes;
    public:
        Prims();
        void createGraph();
        void primsAlgo();
};

Prims::Prims(){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            graph[i][j] = 0;
}

void Prims::createGraph(){
    cout << "Enter total nodes: ";
    cin >> nodes;

    cout << "Enter Adjacency matrix:\n";
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            cin >> graph[i][j];

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            if(graph[i][j] == 0)
                graph[i][j] = INFI;
}

void Prims::primsAlgo(){
    int selected[ROW], ne, edgeCost, totalCost = 0;
    int min, x, y;

    for (int i = 0; i < nodes; i++)
        selected[i] = FALSE;

    selected[0] = TRUE;
    ne = 0;
    while(ne < nodes - 1){
        min = INFI;
        for (int i = 0; i < nodes; i++)
            if(selected[i] == TRUE)
                for (int j = 0; j < nodes; j++)
                    if(selected[j] == FALSE)
                        if(min > graph[i][j]){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }

        selected[y] = TRUE;
        edgeCost = graph[x][y];
        totalCost += edgeCost;
        cout << "\n" << x + 1 << "->" << y + 1 << " " << edgeCost;
        ne++;
    }
    cout << "\nCost of MST: " << totalCost << endl;
}

void main(){
    Prims MST;
    clrscr();

    cout << "Prims algorithm for MST\n";
    MST.createGraph();
    MST.primsAlgo();

    getch();
}

