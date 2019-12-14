#include <iostream>
#include <queue>
using namespace std;

#define kMod 524287

int minCost(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

    int res = 0;

    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res = (res + first + second) % kMod;
        pq.push(first + second);
    }

    return res;
}

int main() {
    int numSize;
    cin >> numSize;

    int num[numSize];
    for(int i = 0; i < numSize; i++) {
        cin >> num[i];
    }

    cout << minCost(num, numSize);

    return 0;
}
