#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n<2){
		return 0;
	}
	sort(a,a+n);
	int maxi,mini,diff;
	diff = a[n-1]-a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-k<0)continue;
		maxi = max(a[i-1]+k,a[n-1]-k);
		mini = min(a[i]-k,a[0]+k);
		diff = min(maxi-mini,diff);
	}
	cout << diff << endl;
	return 0;
}