// https://www.geeksforgeeks.org/maximum-sum-in-circular-array-such-that-no-two-elements-are-adjacent/

#include <bits/stdc++.h>
using namespace std;

long maxSum1(long nums[], int n)
{
    long include = nums[0];
    long exclude = 0;
    long temp;

    for(int i = 1; i < n - 1; i++)
    {
        temp = (include > exclude) ? include : exclude;

        include = exclude + nums[i];
        exclude = temp;
    }

    return ((include > exclude) ? include : exclude);
}

long maxSum2(long nums[], int n)
{
    long include = nums[1];
    long exclude = 0;
    long temp = 0;

    for(int i = 2; i < n; i++)
    {
        temp = (include > exclude) ? include : exclude;

        include = exclude = nums[i];
        exclude = temp;
    }

    return ((include > exclude) ? include : exclude);
}

long summation3(long nums[], int n)
{
    return max(maxSum1(nums, n), maxSum2(nums, n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numSize;
    cin >> numSize;

    long nums[numSize];
    for(int i = 0; i < numSize; i++)
    {
        cin >> nums[i];
    }

    cout << summation3(nums, numSize) << endl;

    return 0;
}
