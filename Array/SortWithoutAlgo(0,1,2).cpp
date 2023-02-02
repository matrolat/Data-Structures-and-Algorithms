#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int zero=0,one=0,two=0;
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int s;
			cin >> s;
			if(s==0)zero++;
			else if(s==1)one++;
			else{
				two++;
			}
		}
			for(int i=0;i<zero;i++)cout << 0 << " " ;
			for(int i=0;i<one;i++)cout << 1 << " " ;
			for(int i=0;i<zero;i++)cout << 2 << " " ;
	}
	return 0;
}