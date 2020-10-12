#include <bits/stdc++.h>

using namespace std;

class query
{
public:

    string type, name;
    int number;
};

class bookManager
{
public:

    map <int, string> m;
    vector <query> Queries;
    bookManager (int n)
    {
        Queries.resize (n);
    }
    void add (string name, int num)
    {
        m[num] = name;
    }
    void del (int num)
    {
        m.erase (num);
    }
    void fnd (int num)
    {
        if (!m.count (num))
            cout << "not found" << "\n";
        else
            cout << m[num] << "\n";
    }
    void input ()
    {
        string s, name;
        int num;
        for (int i = 0; i < (int) Queries.size(); i++)
        {
            cin >> s >> num;
            Queries[i].type = s;
            Queries[i].number = num;
            if (s == "add")
            {
                cin >> name;
                Queries[i].name = name;
                add (Queries[i].name, Queries[i].number);
            }
            else if (s == "del")
                del (Queries[i].number);
            else
                fnd (Queries[i].number);
        }
    }
};

int main()
{
    int N;
    cin >> N;
    bookManager B (N);
    B.input ();
    return 0;
}
