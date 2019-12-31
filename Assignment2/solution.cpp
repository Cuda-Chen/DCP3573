#include <bits/stdc++.h>
using namespace std;

struct CharacterCount
{
    char character;
    int counter;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int characterNums = 26;
    CharacterCount charCount[characterNums];
    for(int i = 0; i < characterNums; i++)
    {
        charCount[i].character = 'A' + i;
        charCount[i].counter = 0;
    }
    for(char &c: str)
    {
        charCount[c - 'A'].counter++;
    }

    sort(charCount, charCount + characterNums, [](CharacterCount a, CharacterCount b) -> bool {
        if(a.counter == b.counter) { return a.character < b.character; } 
            return a.counter > b.counter; });

    for(int i = 0; i < characterNums; i++)
    {
        if(charCount[i].counter)
        {
            cout << (int) charCount[i].character << ' ' << charCount[i].counter<< endl;
        }
    }

    return 0;
} 
