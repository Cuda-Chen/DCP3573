// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

#include <bits/stdc++.h>
using namespace std;

class pairSum
{
    public:
        int first;
        int second;
        int sum;
};

int compare(const void *a, const void *b)
{
    const int ia = (*(const pairSum *)a).sum;
    const int ib = (*(const pairSum *)b).sum;
    return (ia > ib) - (ia < ib);
}
/*
bool noCommon(pairSum a, pairSum b)
{
    if(a.first != b.first && a.first != b.second &&
        a.second != b.first && a.second != b.second)
    {
        return true;
    }

    return false;
}
*/
bool noCommon(pairSum a, pairSum b)  
{  
    if (a.first == b.first || a.first == b.second ||  
            a.second == b.first || a.second == b.second)  
        return false;  
    return true;  
} 

bool fourSum(int array[], int n, int X)
{
    int i, j;

    int size = (n * (n - 1)) / 2;
    pairSum aux[size];

    int k = 0;
    for(i = 0; i < n - 1; i++) 
    {
        for(j = i + 1; j < n; j++)
        {
            aux[k].sum = array[i] + array[j];
            aux[k].first = i;
            aux[k].second = j;
            k++;
        }
    }

    qsort(aux, size, sizeof(pairSum), compare);
    //sort(aux, aux + size, [](pairSum const &a, pairSum const &b) -> bool{return a.sum < b.sum;});

    i = 0; 
    j = size - 1;
    while(i < size && j >= 0)
    {
        if((aux[i].sum + aux[j].sum == X) &&
            noCommon(aux[i], aux[j]))
        {
            return true;
        }
        else if(aux[i].sum + aux[j].sum < X)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

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
    else
    {
        cout << 0 << endl;
    }

    return 0;
}
