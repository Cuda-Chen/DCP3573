// https://github.com/amulyagaur/Segment-Tree/blob/master/range-max-query.cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void buildTree(int *tree, int *a, int index, int start, int end) {
    // base case
    if(start > end) {
        return;
    }

    // reach leaf node
    if(start == end) {
        tree[index] = a[start];
        return;
    }

    // now build the segment tree in bottom up manner
    int mid = (start + end) / 2;
    buildTree(tree, a, 2 * index, start, mid);
    buildTree(tree, a, 2 * index + 1, mid + 1, end);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    return;
}

int query(int *tree, int index, int start, int end, int qstart, int qend) {
    // base case: if query range is outside the node range
    if(qstart > end || start > qend) {
        return INT_MIN;
    }

    // complete overlap
    if(start >= qstart && end <= qend){
        return tree[index];
    }

    // now partial overlap case is executed
    int mid = (start + end) / 2;
    int left_ans = query(tree, 2 * index, start, mid, qstart, qend);
    int right_ans = query(tree, 2 * index + 1, mid + 1, end, qstart, qend);
    return max(left_ans, right_ans);
}

void updateNode(int *tree, int index, int start, int end, int pos, int val) {
    if(pos < start || pos > end) {
        return;
    }

    if(start == end) {
        tree[index] = val;
        return;
    }

    int mid = (start + end) / 2;
    updateNode(tree, 2 * index, start, mid, pos, val);
    updateNode(tree, 2 * index + 1, mid + 1, end, pos, val);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numSize;
    int queries;
    int queryType;
    int num1;
    int num2;

    // get inputs
    cin >> numSize >> queries;
    int num[numSize];
    for(int i = 0; i < numSize; i++) {
        cin >> num[i];
    }

    int *tree = new int[4 * numSize + 1];
    int index = 1;
    int start = 0;
    int end = numSize - 1;
    buildTree(tree, num, index, start, end);

    // perform queries
    for(int i = 1; i <= queries; i++) {
        cin >> queryType >> num1 >> num2;
        
        switch(queryType) {
            case 1:
                #ifdef DEBUG
                    cout << "type " << queryType;
                    cout << " num[" << num1 << "] = " << num2 << endl;
                #endif
                updateNode(tree, index, start, end, num1, num2);
                break;
            case 2:
                #ifdef DEBUG
                    cout << "type " << queryType;
                    cout << " range from " << num1 << " " << num2 << endl;
                #endif
                cout << query(tree, index, start, end, num1, num2) << endl;
                break;
            default:
                cerr << "You should not come here." << endl;
                return 1;
                break;
        }
    }

    return 0;
}
