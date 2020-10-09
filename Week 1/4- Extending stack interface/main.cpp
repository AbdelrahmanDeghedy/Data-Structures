
#include<bits/stdc++.h>
using namespace std;

class stacky
{
	vector <pair <int,int> > vec;
	int top;

public:
	stacky() : top (-1)
	{
	}
	bool empty()
	{
		return top == -1;
	}
	void push(int value)
	{
		if(empty())
		{
			vec.push_back({value,value});
			top = 0;
		}
		else
		{
			int maxi = max(value,vec[top].second);
			vec.push_back({value, maxi});
			top++;
		}
	}
	void pop()
	{
		vec.pop_back();
		top--;
	}
	int maxe()
	{
		return vec[top].second;
	}
};

int main()
{
	int n;
	cin >> n;
	stacky s;
	string str;
	int value;
	for(int i = 0; i < n; ++i)
	{
		cin >> str;
		if(str == "push")
		{
			cin >> value;
			s.push(value);
		}
		else if(str == "pop")
			s.pop();
		else
			cout << s.maxe() << "\n";
	}
	return 0;
}
