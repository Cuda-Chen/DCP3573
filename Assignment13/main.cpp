// Kadane’s Algorithm

// Kadane's Algorithm with recording minimal start end index
// https://www.collegestash.com/kadanes-algorithm-maximum-sum-subarray-indices-handles-negatives/

#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(int nums[], int n)
{
    int left = 0, right = 0;
    int globalLeft = 0, globalRight = 0;
    int localMax = nums[0];
    int globalMax = nums[0];

    for(int i = 1; i < n; i++)
    {
        if(nums[i] > localMax + nums[i])
        {
            localMax = nums[i];
            left = i;
            right = i;
        }
        else
        {
            localMax = localMax + nums[i];
            right = i;
        }

        if(localMax > globalMax)
        {
            globalMax = localMax;
            globalLeft = left;
            globalRight = right;
        }
    }

    // boundary check
    globalLeft = globalLeft >= 0 ? globalLeft : 0;
    globalRight = (globalRight + 1) < n ? (globalRight + 1) : n;
    cout << globalLeft << " " << globalRight << endl;
    return globalMax;
}

int main()
{
    int numsSize;
    cin >> numsSize;
    int nums[numsSize];
    for(int i = 0; i < numsSize; i++)
    {
        cin >> nums[i];
    }

    int result = maxSubarraySum(nums, numsSize);

    //cout << result << endl;
    
    return 0;
}
