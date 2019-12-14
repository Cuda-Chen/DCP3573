// https://medium.com/@bhch3n/huffman-coding-%E9%9C%8D%E5%A4%AB%E6%9B%BC%E7%B7%A8%E7%A2%BC-3879df5ecddc

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    int freq;
    string encodedString;
    Node *leftChild;
    Node *rightChild;

    Node(int _value, int _freq, Node *_leftChild, Node *_rightChild)
    {
        value = _value;
        freq = _freq;
        leftChild = _leftChild;
        rightChild = _rightChild;
    }
};

unordered_map<int, int> freq;
deque<Node *> forest;
int result = 0;

bool cmp(Node *a, Node *b)
{
    return a->freq < b->freq;
}

void printCode(Node *ptr, string s)
{
    if(ptr->leftChild == nullptr || ptr->rightChild == nullptr)
    {
        //printf("'%d' (freq = %d) --> %s\n", ptr->value, freq[ptr->value], s.c_str());
        ptr->encodedString = s;
        /*
        cout << ptr->value << " (freq = " 
            << ptr->freq << ") --> " << ptr->encodedString << endl;
        */
        result += ptr->freq * pow(2, (ptr->encodedString).size());
        return;
    }

    if(ptr->leftChild) 
    {
        printCode(ptr->leftChild, string(s + "0"));
    }
    if(ptr->rightChild)
    {
        printCode(ptr->rightChild, string(s + "1"));
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        forest.push_back(new Node((*it).first, (*it).second, nullptr, nullptr));
    }

    for(int i = 0; i < freq.size() - 1; i++)
    {
        sort(forest.begin(), forest.end(), cmp);
        Node *node1 = forest.front();
        forest.pop_front();
        Node *node2 = forest.front();
        forest.pop_front();
        Node *parentNode = new Node(-1, node1->freq + node2->freq, node1, node2);
        forest.push_back(parentNode);
    }

    printCode(forest.front(), string(""));
    cout << result << endl;
    return 0;
}
