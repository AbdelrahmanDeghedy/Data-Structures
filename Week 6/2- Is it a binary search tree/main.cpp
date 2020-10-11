
#include <bits/stdc++.h>

using namespace std;


class node
{
public :

    int value;
    int left;
    int right;
};

class tree
{
public :
    vector <int> inOrd;
    vector <node> nodes;
    int siz;
    tree (int n) : siz (n)
    {
        nodes.resize (n);
    }
    void input ()
    {
        int v, r, l;
        for (int i = 0; i < siz; i++)
        {
            cin >> v >> l >> r;
            nodes[i].value = v;
            nodes[i].right = r;
            nodes[i].left = l;
        }
    }
    void inOrder (int root)
    {
        if (root == -1)
            return;
        inOrder (nodes[root].left);
        inOrd.push_back (nodes[root].value);
        inOrder (nodes[root].right);
    }
    bool check ()
    {
        if (siz > 0)
        {
            inOrder (0);
            for (int i = 0; i < siz - 1; i++)
            {
                if (inOrd[i + 1] < inOrd[i])
                    return 0;
            }
        }
        return 1;
    }
};

int main()
{
    int n;
    cin >> n;
    tree T (n);
    T.input ();
    if (T.check())
        cout << "CORRECT";
    else
        cout << "INCORRECT";


    return 0;
}
