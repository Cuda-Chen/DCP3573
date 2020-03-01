// Moore-Hodgson Algorithm
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Job 
{
    int deadline;
    int duration;
};

int n, i, c;
long long t;
Job jobs[1000000];
priority_queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> jobs[i].deadline >> jobs[i].duration;
    }
    sort(jobs, jobs + n, [](const Job &a, const Job &b) -> bool { return a.deadline < b.deadline; });
    c = n;
    for(int i = 0; i < n; i++)
    {
        t += jobs[i].duration;
        q.push(jobs[i].duration);
        if(t > jobs[i].deadline)
        {
            t -= q.top();
            q.pop();
            c--;
        }
    }

    cout << c;
    return 0;
}
