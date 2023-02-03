/*Given an array, rotate the array by one position in clock-wise direction.*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >>n;
	int a[n];int temp;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	temp = a[0];
	a[0]=a[n-1];
	for(int i=1;i<n;i++)
	{
		int j= a[i];
		a[i]=temp;
		temp = j;
	}
	for(int i=0;i<n;i++){
		cout << a[i] << " " ;
	}
	return 0;
}