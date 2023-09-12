#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int i=0;
	int j=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5-i;j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}