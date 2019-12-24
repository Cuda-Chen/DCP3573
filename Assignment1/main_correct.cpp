#include <bits/stdc++.h>
using namespace std;

int k, input[13], i, output[6];

void print()
{
    cout << output[0];
    for(i = 1; i != 6; i++)
    {
        cout << ' ' << output[i];
    }
    cout << endl;
}

void combination(int x, int y)
{
    if(y == 6)
    {
        print();
        return;
    }

    if(x == k)
    {
        return;
    }
    int j;
    for(j = x; j != k; j++)
    {
        output[y] = input[j];
        combination(j + 1, y + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(;;)
    {
        cin >> k;
        if(k == 0)
        {
            break;
        }
        for(i = 0; i != k; i++)
        {
            cin >> input[i];
        }
        combination(0, 0);
        cout << endl;
    }

    return 0;
}
