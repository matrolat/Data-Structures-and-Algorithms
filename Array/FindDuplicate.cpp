//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> v;int c=0;
        map<int,int> umap;
        for(int i=0;i<n;i++)
        {
        	// cout << arr[i] << " ";
            umap[arr[i]]++;
        }
        // cout << endl;
        for(auto it : umap)
        {
        	// cout << it.first << " " << it.second << endl;
            if(it.second>1)
            {
                v.push_back(it.first);
                c++;
            }
        }
        if(c>0)
        {
        return v;
            
        }
        else{
            v.push_back(-1);
            return v;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends