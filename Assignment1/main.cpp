#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permuteHelper(vector<int> &nums, int k, vector<vector<int>> &result)
{
    if(k >= nums.size())
    {
        result.push_back(nums);
    }
    else
    {
        // elements up to k have been fixed
        for(int i = k; i < nums.size(); i++)
        {
            swap(nums[i], nums[k]);
            permuteHelper(nums, k + 1, result);
            swap(nums[i], nums[k]);
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    int temp;
    vector<int> input(k, 0);
    for(int i = 0; i < k; i++)
    {
        cin >> temp;
        input[i] = temp;
    }

    vector<vector<int>> result = permute(input);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
