#include <bits/stdc++.h>
using namespace std;

int maximum_score(int points[], int need_n_minutes[], int n, int deadline_due)
{
    int dp[deadline_due + 1];
    for(int i = 0; i < deadline_due + 1; i++)
    {
        dp[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = deadline_due; j - need_n_minutes[i] >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j - need_n_minutes[i]] + points[i]);
        }
    }

    return dp[deadline_due];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, deadline_due;
    cin >> n >> deadline_due;
    int points[n];
    int need_n_minutes[n];
    for(int i = 0; i < n; i++)
    {
        cin >> points[i] >> need_n_minutes[i];
    }

    int result = maximum_score(points, need_n_minutes, n, deadline_due);
    cout << result << endl;
    return 0;
}
