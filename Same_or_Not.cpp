#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    queue<int> que;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        que.push(val);
    }

    if (st.size() != que.size())
    {
        cout << "NO";
        return 0;
    }

    while (!st.empty() && !que.empty())
    {
        if (st.top() != que.front())
        {
            cout << "NO";
            return 0;
        }
        st.pop();
        que.pop();
    }
    cout << "YES";

    return 0;
}