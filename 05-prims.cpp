#include <iostream.h>
#include <conio.h>

#define ROW 7
#define COL 7
#define INFI 999

class Prims {
    int graph[ROW][COL], nodes;
    public:
        Prims();
        void createGraph();
        void primsAlgo();
};

Prims::Prims() {
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            graph[i][j] = 0;
}

void Prims::createGraph() {
    cout << "Enter total nodes: ";
    cin >> nodes;

    cout << "Enter Adjacency matrix:\n";
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            cin >> graph[i][j];

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            if (graph[i][j] == 0)
                graph[i][j] = INFI;
}

void Prims::primsAlgo() {
    int selected[ROW], ne, edgeCost, totalCost = 0;
    int min, x, y;

    for (int i = 0; i < nodes; i++)
        selected[i] = false;

    selected[0] = true;
    ne = 0;
    
    while(ne < nodes - 1){
        min = INFI;
        for (int i = 0; i < nodes; i++)
            if (selected[i] == true)
                for (int j = 0; j < nodes; j++)
                    if (selected[j] == false)
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }

        selected[y] = true;
        edgeCost = graph[x][y];
        totalCost += edgeCost;
        cout << "\n" << x + 1 << " -> " << y + 1 << ": " << edgeCost;
        ne++;
    }

    cout << "\nCost of MST: " << totalCost << endl;
}

void main() {
    Prims MST;
    clrscr();

    cout << "Prims algorithm for MST\n";
    MST.createGraph();
    MST.primsAlgo();

    getch();
}

/* OUTPUT:
Prims algorithm for MST
Enter total nodes: 5
Enter Adjacency matrix:
0   5   15  20  999
5   0   25  999 999
15  25  0   30  37
20  999 30  0   35
999 999 37  35  0

1 -> 2: 5
1 -> 3: 15
1 -> 4: 20
4 -> 5: 35
Cost of MST: 75
*/
