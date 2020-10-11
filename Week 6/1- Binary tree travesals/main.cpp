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
        cout << nodes[root].value << " ";
        inOrder (nodes[root].right);
    }
    void preOrder (int root)
    {
        if (root == -1)
            return;
        cout << nodes[root].value << " ";
        preOrder (nodes[root].left);
        preOrder (nodes[root].right);
    }
    void postOrder (int root)
    {
        if (root == -1)
            return;
        postOrder (nodes[root].left);
        postOrder (nodes[root].right);
        cout << nodes[root].value << " ";
    }
};

int main()
{
    int n;
    cin >> n;
    tree T (n);
    T.input ();
    T.inOrder (0);
    cout << "\n";
    T.preOrder (0);
    cout << "\n";
    T.postOrder (0);


    return 0;
}
