#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	int a[t];
	vector<int> p;
	vector<int> d;
	for(int i=0;i<t;i++)
	{
		cin >> a[i];
		if(a[i]>=0){
			p.push_back(a[i]);
		}
		else{
			d.push_back(a[i]);
		}
	}
	for (vector<int>::iterator it = p.begin() ; it != p.end(); ++it)
		cout  << *it << " ";
   	for (vector<int>::iterator it = d.begin() ; it != d.end(); ++it)
  		cout  << *it << " ";
	return 0;
}