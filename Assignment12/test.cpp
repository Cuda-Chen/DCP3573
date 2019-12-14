// https://cp-algorithms.com/schedules/schedule-with-completion-duration.html

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline;
    int duration;
    int index;

    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

int compute_schedule(Job jobs[], int n) {
    //sort(jobs.begin(), jobs.end());
    sort(jobs, jobs + n);

    set<pair<int,int>> s;
    vector<int> schedule;
    for (int i = n - 1; i >= 0; i--) {
        int t = jobs[i].deadline - (i ? jobs[i - 1].deadline : 0);
        s.insert(make_pair(jobs[i].duration, jobs[i].index));
        while (t && !s.empty()) {
            auto it = s.begin();
            if (it->first <= t) {
                t -= it->first;
                schedule.push_back(it->second);
            } else {
                s.insert(make_pair(it->first - t, it->second));
                t = 0;
            }
            s.erase(it);
        }
    }
    return schedule.size();
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);

    int n;
    cin >> n;
    //vector<Job> jobs;
    Job jobs[n];
    for(int i = 0; i < n; i++) {
        //jobs.push_back(Job());
        cin >> jobs[i].deadline >> jobs[i].duration;
        jobs[i].index = i;
    }

    int result = compute_schedule(jobs, n);
    cout << result << endl;

    return 0;
}
