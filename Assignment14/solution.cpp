#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::greater;
using std::priority_queue;
using std::vector;

int n, i, j, k;
long long w, t;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> w;
        q.push(w);
    }

    while(n-- > 1)
    {
        w = q.top();
        q.pop();
        t = q.top();
        q.pop();
        w = (w + t) * 2;
        q.push(w);
    }

    cout << q.top();
    
    return 0;
}
