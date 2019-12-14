#include <bits/stdc++.h>
using namespace std;

bool fourSum(int array[], int n, int k)
{
    unordered_multimap<int, vector<pair<int, int>>> hash;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = array[i] + array[j];

            if(hash.find(k - sum) != hash.end())
            {
                auto num = hash.find(k - sum);
                vector<pair<int, int>> v = num->second;

                for(int k = 0; k < num->second.size(); k++)
                {
                    pair<int, int> it = v[k];

                    if(it.first != i && it.first != j && 
                        it.second != i && it.second != j)
                    {
                        return true;
                    }
                }
            }

            hash.insert(sum, make_pair(i, j));
        }
    }

    //hash.clear();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numSize;
    cin >> numSize;

    int num[numSize];
    for(int i = 0; i < numSize; i++)
    {
        cin >> num[i];
    }

    if(fourSum(num, numSize, 0))
    {
        cout << 1 << endl;
    } 
    else {
        cout << 0 << endl;
    }

    return 0;
}
