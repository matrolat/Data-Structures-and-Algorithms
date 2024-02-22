#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& v,int low,int mid,int high)
{
	vector<int> ans;
	int i=low;
	int j = mid+1;
	while(i<=mid && j<=high)
	{
		if(v[i] < v[j])
		{
			ans.push_back(v[i]);
			i++;
		}
		else{
			ans.push_back(v[j]);
			j++;
		}
	}
	while(i<=mid)
	{
		ans.push_back(v[i]);
		i++;
	}
	while( j<=high)
	{
		ans.push_back(v[j]);
		j++;
	}
	
	i = low; j = 0;
	while(i<=high && j<ans.size())
	{
		v[i] = ans[j];
		i++;
		j++;
	}
}

void mergeSort(vector<int>& v, int low, int high)
{
    if (high <= low) {
        return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
    return;
}


void sort(vector<int>& v)
{
	mergeSort(v,0,v.size()-1);
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v);
	
	for(auto it:v) cout << it << endl;
	
}