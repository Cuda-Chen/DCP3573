#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

#define num 26

int main()
{
    int charFreq[num] = {0};

    string str;
    getline(cin, str);

    for(const char c: str)
    {
        charFreq[toupper(c) - 'A']++;
    }

    for(int i = 0; i < num; i++)
    {
        if(charFreq[i] > 0)
        {
            cout << (int)(i + 'A') << " " << charFreq[i] << endl;
        }
    }

    return 0;
}

