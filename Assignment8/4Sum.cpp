#include <bits/stdc++.h>
using namespace std;

class pairSum {
public:
    int firstIdx;
    int secondIdx;
    int sum;
};

int compare(const void *a, const void *b) {
    return ((*(pairSum *)a).sum - (*(pairSum *)b).sum);
}

bool noCommon(pairSum a, pairSum b) {
    if(a.firstIdx == b.firstIdx || a.firstIdx == b.secondIdx ||
        a.secondIdx == b.firstIdx || a.secondIdx == b.secondIdx) {
        return false;
    }
    
    return true;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int i, j;
    int n = nums.size();
    vector<vector<int>> result;
    vector<int> temp(4, 0);
    if(n <= 0) {
        return result;
    }
    int size = (n * (n - 1)) / 2;
    pairSum aux[size];

    int k = 0;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            aux[k].sum = nums[i] + nums[j];
            aux[k].firstIdx = i;
            aux[k].secondIdx = j;
            k++;
        }
    }

    qsort(aux, size, sizeof(aux[0]), compare);

    i = 0;
    j = size - 1;
    while(i < size && j >= 0) {
        if((aux[i].sum + aux[j].sum == target) &&
            noCommon(aux[i], aux[j])) {
            temp[0] = (aux[i].firstIdx);
            temp[1] = (aux[i].secondIdx);
            temp[2] = (aux[j].firstIdx);
            temp[3] = (aux[j].secondIdx);
            result.push_back(temp);
        } else if(aux[i].sum + aux[j].sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numSize;
    cin >> numSize;

    vector<int> num(numSize, 0);
    for(int i = 0; i < numSize; i++)
    {   
        cin >> num[i];
    }   

    vector<vector<int>> result = fourSum(num, 0);
    for(vector<int> vec: result) {
        for(int elem: vec) {
            cout << elem << " ";
        }

        cout << endl;
    }

    return 0;
}

