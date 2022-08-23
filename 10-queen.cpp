#include <stdio.h>
#include <conio.h>
#include <math.h>

int a[30], count = 0;

int place(int pos) {
    for (int i = 1; i < pos; i++)
        if(a[i] == a[pos] || (abs(a[i] - a[pos]) == abs(i - pos)))
            return 0;
    return 1;
}

void print_sol(int n) {
    printf("Solution #%d\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i] == j) printf("Q\t");
            else printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n) {
    int k = 1;
    a[k] = 0;
    while(k != 0) {
        a[k]++;
        while(a[k] <= n && !place(k))
            a[k]++;
        if(a[k] <= n)
            if(k == n) print_sol(n);
            else a[++k] = 0;
        else k--;
    }
}

int main() {
    int n;
    clrscr();
    
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    queen(n);
    printf("Total solutions = %d", count);
    
    getch();
}

/* OUTPUT:
Enter the number of Queens: 4
Solution #1
*       Q       *       *
*       *       *       Q
Q       *       *       *
*       *       Q       *
Solution #2
*       *       Q       *
Q       *       *       *
*       *       *       Q
*       Q       *       *

NOTE: loop counters have to specifically start with 1 otherwise
the output is just not right, also note the loop conditions.
*/
