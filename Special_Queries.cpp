#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    queue<string> qu;
    while (q--)
    {
        int num;
        cin >> num;
        string name;

        if (num == 0)
        {
            cin >> name;
            qu.push(name);
        }
        else if (num == 1)
        {
            if (!qu.empty())
            {
                cout << qu.front() << endl;
                qu.pop();
            }
            else if (qu.empty())
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}