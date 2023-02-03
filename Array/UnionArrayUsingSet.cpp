#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	int a,b;
	cin >> a >> b;
	for(int i=0;i<(a+b);i++)
	{
		int t;cin >>t;
		s.insert(t);
	}
	cout << s.size();
	return 0;
}