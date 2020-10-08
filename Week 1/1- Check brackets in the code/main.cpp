#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x;
    cin >> x;
    stack <pair <int, int>> s;
    for (int i = 0; i < (int) x.size(); i++)
    {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            s.push ({x[i], i + 1});
        else
        {
            if (s.size() == 0 && (x[i] == ']' || x[i] == '}' || x[i] == ')'))
            {
                cout << i + 1;
                return 0;
            }
            if ((x[i] == ']' && s.top().first != '[' )|| (x[i] == ')' && s.top().first != '(') || (x[i] == '}' && s.top().first != '{'))
            {
                  cout << i + 1;
                  return 0;
            }
            else if ((x[i] == ']' && s.top().first == '[' )|| (x[i] == ')' && s.top().first == '(') || (x[i] == '}' && s.top().first == '{'))
            {
                  s.pop();
            }
        }
    }
    if (s.empty())
    {
        cout << "Success";
        return 0;
    }
    else
    {
        while (s.size() > 1)
            s.pop();
        cout << s.top().second;
        return 0;
    }

    cout << "Success";

    return 0;
}
