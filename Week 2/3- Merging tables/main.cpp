#include <bits/stdc++.h>

using namespace std;

class sett
{
public:

    int siz;
    int rankk;
    int parent;

    sett (int a = 0, int b = 0, int c = -1) : siz (a), rankk (b), parent (c)
    {

    }
};

class DisjointSet
{
public:

    vector <sett> sets;
    int siz;
    int maxSize;

    DisjointSet (int size_dijoint) : maxSize (0)
    {
        siz = size_dijoint;
        sets.resize (size_dijoint);
        for (int i = 0; i < siz; i++)
            sets[i].parent = i;
    }
    void findMaxFromInput ()
    {
        for (int i = 0; i < siz; i++)
        {
            cin >> sets[i].siz;
            maxSize = max (maxSize, sets[i].siz);
        }
    }
    int fnd (int i)
    {
        if (i != sets[i].parent)
            sets[i].parent = fnd (sets[i].parent);
        return sets[i].parent;
    }
    void unionn (int x, int y)
    {
        int xID = fnd (x);
        int yID = fnd (y);
        if (xID != yID)
        {
            if (sets[xID].rankk > sets[yID].rankk)
            {
                sets[yID].parent = xID;
                sets[xID].siz += sets[yID].siz;
                sets[yID].siz = 0;
                maxSize = max (maxSize, sets[xID].siz);
            }
            else
            {
                sets[xID].parent = yID;
                sets[yID].siz += sets[xID].siz;
                sets[xID].siz = 0;
                maxSize = max (maxSize, sets[yID].siz);

                if (sets[xID].rankk == sets[yID].rankk)
                    sets[yID].rankk += 1;
            }

        }
    }
};

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    DisjointSet ds (n);
    ds.findMaxFromInput ();
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--, y--;   // convert to zero-index
        ds.unionn (x, y);
        cout << ds.maxSize << "\n";
    }

    return 0;
}
