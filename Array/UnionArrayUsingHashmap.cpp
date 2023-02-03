#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin >> m >> n;int t;
	 unordered_map<int, int> umap;
	for(int i=0;i<(m+n);i++){
		cin >>t;
		umap[t]++;
	}
	int c=0;
	for (auto x : umap)
    c++;
	cout << c;
	return 0;
}