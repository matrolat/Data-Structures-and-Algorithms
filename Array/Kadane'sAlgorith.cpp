#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int maxi=INT_MIN;int sum=0;
	for(int i=0;i<n;i++)
	{
		sum = sum + a[i];
		maxi = max(sum,maxi);
		if(sum<0)
		{
			sum = 0;
		}
	}
	cout << maxi << endl;
	return 0;
}