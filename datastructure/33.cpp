#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void maxHeapify(vector<int> &maxHeap, int i)
{
    int left = 2 * i +1;
    int right = 2 * i + 2;
    int largest;
    if (left < maxHeap.size() && maxHeap[left] > maxHeap[i])
    {
        largest = left;
    }
    else 
    {
        largest = i;
    }
    if (right < maxHeap.size() && maxHeap[right] > maxHeap[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(maxHeap[i], maxHeap[largest]);
        maxHeapify(maxHeap, largest);
    }
}

void buildMaxHeap(vector<int> &maxHeap)
{
    for (int i = maxHeap.size() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(maxHeap, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> maxHeap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> maxHeap[i];
    }

    buildMaxHeap(maxHeap);

    for (int i = 0; i < n; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    return 0;
}