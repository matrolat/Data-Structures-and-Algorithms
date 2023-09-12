#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	for(int i=1;i<=10;i++)
	{
		if(i<=5)
		{
			for(int j=1;j<=i;j++)
			{
				cout << "*" ;
			}
			cout << endl;
		}
		else{
			for(int j= 10-i;j>=1;j-- )
			{
				cout << "*" ;
			}
			cout << endl;
		}
		
	}
	
	return 0;
}