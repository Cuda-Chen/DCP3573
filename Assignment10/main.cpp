// https://www.careercup.com/question?id=14928366

#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
    const int ia = *(const int *)a;
    const int ib = *(const int *)b;
    //return (ia > ib) - (ia < ib);
    return (ia < ib) - (ia > ib);
}

int summation0(int nums[], int n)
{
    qsort(nums, n, sizeof(int), compare);
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        int elem = nums[i];
        if(i == 0)
        {
            sum = nums[i];
            continue;
        }

        if(sum >= elem)
        {
            elem = -elem;
            sum = sum + elem;
        }
        else
        {
            if(sum < elem && sum > 0)
            {
                elem = -elem;
                sum = sum + elem;
            }
            else
            {
                sum = sum + elem;
            }
        }
    }

    return abs(sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numSize;
    cin >> numSize;
    int nums[numSize];
    for(int i = 0; i < numSize; i++)
    {
        cin >> nums[i];
    }

    cout << summation0(nums, numSize) << endl;

    return 0;
}
