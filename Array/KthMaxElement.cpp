#include<bits/stdc++.h>
using namespace std;
/*
Given an array arr[] and an integer K where K is smaller than size of array,
 the task is to find the Kth smallest element in the given array.
  It is given that all array elements are distinct
*/

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i] ;
	}
	int k;
	cin >> k;
	sort(a,a+n);// 4 7 10 15 20
	cout << a[n-k];
	return 0;

	
}