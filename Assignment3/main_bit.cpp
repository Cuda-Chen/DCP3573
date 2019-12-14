#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define kMod 524287

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result;
        vector<int> clone = nums;
        int length = (int)nums.size();
        unordered_map<int, int> reflect;
        array.resize(length + 1);
        sort(clone.begin(), clone.end());
        for(int i = 0; i < length; i++)
        {
            reflect[clone[i]] = i + 1;
        }

        for(int i = length - 1; i >= 0; i--)
        {
            clone[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }

        return clone;
    }
private:
    vector<int> array;

    inline int lowbit(int pos)
    {
        return pos & -pos;
    }

    void add(int pos, int val)
    {
        long len = array.size();
        while(pos < len)
        {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }

    int query(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += array[pos];
            pos -= lowbit(pos);
        }

        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numsSize;
    cin >> numsSize;
    int temp;

    vector<int> nums(numsSize, 0);
    for(int i = 0; i < nums.size(); i++)
    {
        cin >> temp;
        nums[i] = temp;
    }

    Solution sol;
    vector<int> result = sol.countSmaller(nums);

    int sum = 0;
    for(int i = 0; i < result.size(); i++)
    {
        #if DEBUG
        cout << "result[" << i << "] = " << result[i] << endl;
        #endif
        sum = (sum + result[i]) % kMod;
    }

    cout << sum << endl;

    return 0;
}
