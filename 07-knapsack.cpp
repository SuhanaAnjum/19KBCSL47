#include <iostream.h>
#include <conio.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knapsack(int W, int wt[], int val[], int n) {
    int wt, k[10][10];

    for (int i = 0; i <= n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            if(i == 0 || wt == 0) k[i][wt] = 0;
            else if(w[i-1] <= wt)
                k[i][wt] = max(v[i-1]+k[i-1][wt-w[i-1]], k[i-1][wt]);
            else k[i][wt] = k[i-1][wt];
        }
    }
    return k[n][W];
}

/* recursive approach, better in my opinion
int knapsack(int W, int wt[], int val[], int n) {
    if(n == 0 || W == 0)
        return 0;
    if(wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        return max (
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
            knapsack(W, wt, val, n - 1)
        );
}
*/

int main() {
    int W, wt[10], val[10], n;
    clrscr();

    cout << "Enter the number of items in knapsack: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight if item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    cout << "Maximum profit: " << knapsack(W, wt, val, n) << endl;

    getch();
}

/* OUTPUT:
Enter the number of items in knapsack: 4
Enter profit and weight if item 1: 1 2
Enter profit and weight if item 2: 2 3
Enter profit and weight if item 3: 5 4
Enter profit and weight if item 4: 6 5
Enter the capacity of knapsack: 8
Maximum profit: 8
*/
