#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    int speedOfPolices[n];
    for(int i = 0; i < n; i++)
    {
        cin >> speedOfPolices[i];
    }

    sort(speedOfPolices, speedOfPolices + n);

    cout << speedOfPolices[n - 1] << endl;
    return 0;
}
