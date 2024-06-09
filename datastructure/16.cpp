#include <iostream>

using namespace std;

bool judge(int n, int k, int w[], int p)
{
    int car_sum = k - 1;
    int car_afford = p;
    for (int i = 0; i < n; i++)
    {
        car_afford -= w[i];
        if (car_afford < 0)
        {
            car_sum--;
            car_afford = p;
            i--;
            if (car_sum < 0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int w[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    int Max = sum;
    int Min = sum / k;
    int mid = (Max + Min) / 2;
    while (Max > Min)
    {
        mid = (Max + Min) / 2;
        if (judge(n, k, w, mid))
            Max = mid - 1;
        else
            Min = mid + 1;
    }
    if (judge(n, k, w, mid))
    {
        while (1)
        {
            if (judge(n, k, w, mid))
            {
                mid--;
            }
            else
            {
                cout << mid + 1;
                break;
            }
        }
    }
        
    else
    {
        while (1)
        {
            if (!judge(n, k, w, mid))
                mid++;
            else
            {
                cout << mid;
                break;
            }
        }
    }
    return 0;
}