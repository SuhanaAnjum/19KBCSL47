#include <iostream.h>
#include <conio.h>
#include <time.h>

int part(int a[], int low, int high){
    int i = low + 1, j = high, temp;

    while(i <= j){
        while(a[i] < a[low]) i++;
        while(a[j] > a[low]) j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
        }
    }
    return j;
}

void quick(int a[], int low, int high){
    if(low < high){
        int j = part(a, low, high);
        quick(a, low, j - 1);
        quick(a, j + 1, high);
    }
}

int main(){
    int i, n, a[20];
    clock_t start, end;
    clrscr();

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "The elements selected are: ";
    for (i = 0; i < n; i++) {
        a[i] = rand();
        cout << a[i] << "\t";
    }

    start = clock();
    quick(a, 0, n-1);
    end = clock();

    cout << "\nThe sorted array is:\n" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << "\t";

    cout << "\nThe total time taken is: " << (end - start) / CLOCKS_PER_SEC << endl;

    getch();
}
