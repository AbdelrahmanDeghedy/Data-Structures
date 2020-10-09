#include <bits/stdc++.h>

using namespace std;
vector <pair <int, int>> swaps;

int leftChild (int i)
{
    return i * 2 + 1;
}
int rightChild (int i)
{
    return i * 2 + 2;
}

void siftDown (int i, int siz, int* arr)
{
    int smallestIndex = i;
    int l = leftChild (i);
    int r = rightChild (i);
    if (l < siz && arr[l] < arr[smallestIndex])
        smallestIndex = l;
    if (r < siz && arr[r] < arr[smallestIndex])
        smallestIndex = r;
    if (i != smallestIndex)
    {
        swaps.push_back ({i, smallestIndex});
        swap (arr[i], arr[smallestIndex]);
        siftDown (smallestIndex, siz, arr);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = (n / 2); i >= 0; i--)
        siftDown(i, n, arr);
    cout << swaps.size() << "\n";
    for (int i = 0; i < (int) swaps.size(); i++)\
        cout << swaps[i].first << " " << swaps[i].second << "\n";
    return 0;
}
