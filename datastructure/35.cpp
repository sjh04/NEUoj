#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform max-heapify operation
void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

// Function to perform heap sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // Reverse the sorted array
    reverse(A.begin(), A.end());

    // Output the result
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
