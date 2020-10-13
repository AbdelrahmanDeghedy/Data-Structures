#include <bits/stdc++.h>

using namespace std;

class query
{
public :

    string type, name;
    int number;
};
class bucket
{
public :
    int m,siz;
    vector<vector<string>> table;
    bucket (int n, int mod) : m (mod), siz (n)
    {
        table.resize (100009);
    }
    int hsh (string s)
    {
        const size_t x = 263;
        const size_t p = 1000000007;
        unsigned long long h = 0;
        for (int i = (int) (s.size()) - 1; i >= 0; --i)
            h = (h * x + s[i]) % p;
        return h % m;
    }
    void add (string s)
    {
        for (int i = 0; i < (int) table[hsh (s)].size(); i++)
        {
            if (table[hsh (s)][i] == s)
                return;
        }
        table [hsh (s)].push_back (s);
    }
    void del (string s)
    {
        for (int i = 0; i < (int) table[hsh (s)].size(); i++)
        {
            if (table[hsh (s)][i] == s)
            {
                table[hsh (s)].erase (table[hsh(s)].begin() + i);
                return;
            }
        }
    }
    void fnd (string s)
    {
        for (int i = 0; i < (int) table[hsh (s)].size (); i++)
        {
            if (table[hsh (s)][i] == s)
            {
                cout << "yes\n";
                return;
            }
        }
        cout << "no\n";
    }
    void check (int i)
    {
        for (int j = (int) table[i].size () - 1; j >= 0; j--)
            cout << table[i][j] << " ";
        cout << "\n";
    }
    void input ()
    {
        query q;
        for (int i = 0; i < siz; i++)
        {
            cin >> q.type;
            if (q.type == "add")
            {
                cin >> q.name;
                add (q.name);
            }
            else if (q.type == "find")
            {
                cin >> q.name;
                fnd (q.name);
            }
            else if (q.type == "del")
            {
                cin >> q.name;
                del (q.name);
            }
            else
            {
                cin >> q.number;
                check (q.number);
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> m >> n;
    bucket B (n, m);
    B.input();
    return 0;
}
