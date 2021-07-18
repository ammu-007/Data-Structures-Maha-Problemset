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

int extract_max(int arr[], int &n)
{
    swap(arr[0], arr[n - 1]);
    int result = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    return result;
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[] = {32, 15, 20, 30, 12, 25, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    print(arr);
    cout << extract_max(arr, n);
    nl;
    print(arr);
    nl;
    cout << extract_max(arr, n);
    nl;
    print(arr);
    nl;
    cout << extract_max(arr, n);
    nl;
    print(arr);
}