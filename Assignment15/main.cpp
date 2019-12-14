// http://www.cs.mun.ca/~kol/courses/3719-w12/scheduling.pdf

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int point;
    int deadline;
    int duration;

    bool operator < (Job o) const
    {
        return deadline < o.deadline;
    }
};

int maximum_score(Job jobs[], int n)
{
    sort(jobs, jobs + n);

    int deadline_max = jobs[n - 1].deadline;
    int dp[n][deadline_max + 1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < deadline_max + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < deadline_max + 1; j++)
        {
            int t_prime = min(j, jobs[i].deadline) - jobs[i].duration;
            if(t_prime < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], jobs[i].point + dp[i - 1][t_prime]);
            }
        }
    }

    return dp[n][deadline_max];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Job jobs[n];
    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].point >> jobs[i].deadline;
        jobs[i].duration = 1;
    }

    int result = maximum_score(jobs, n);
    cout << result;

    return 0;
}
