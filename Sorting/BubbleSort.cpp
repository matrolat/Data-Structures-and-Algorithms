#include<bits/stdc++.h>
using namespace std;

void sort(vector<int>& v)
{
	int n= v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(v[j] < v[j-1])
			{
				swap(v[j],v[j-1]);
			}
		}
	}	
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v);
	
	for(auto it:v) cout << it << endl;
	
}