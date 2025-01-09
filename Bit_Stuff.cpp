#include <iostream>
using namespace std;

string BitStuffing(string s)
{
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            c++;
            if (c == 5)
            {
                s.insert(i + 1, "0"); 
                c = 0; 
            }
        }
        else
        {
            c = 0;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << BitStuffing(s) << endl;
    return 0;
}
