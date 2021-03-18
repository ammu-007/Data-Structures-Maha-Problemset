#include <iostream>
using namespace std;
#define nl cout << "\n"
#define print(any)        \
    for (auto i : any)    \
        cout << i << " "; \
    nl;
void heapify(int arr[], int n, int i)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2;
    int maximum = i;
    if (c1 < n && arr[c1] > arr[maximum])
        maximum = c1;
    if (c2 < n && arr[c2] > arr[maximum])
        maximum = c2;
    if (maximum != i)
    {
        swap(arr[maximum], arr[i]);
        heapify(arr, n, maximum);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[] = {10, 2, 4, 1, 6, 3, 9, 5, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    // cout << arr[0];
    print(arr);
}