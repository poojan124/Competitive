#include<bits/stdc++.h>
using namespace std;
// vector<vector<int> > v;
bool visited[1000+5];
int ans = 0;
void dfs(int s,vector<vector<int> > v){
    // cout<<"Visiting "<<s<<endl;
    visited[s] = 1;
    int flag = 0;
    for(auto i:v[s])
        if(!visited[i] && !flag){
            flag = 1;
            dfs(i,v);
        }
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(visited,0,sizeof(visited));
        vector<vector<int> > v(305);
        int n,k;
        cin>>n>>k;
        int a[n+1];
        ans = 0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        set<int> s(a,a+n);
        vector<int> arr(s.begin(),s.end());
        // sort(arr.begin(),arr.end());
        int sz = arr.size();
        for(int i=0;i<sz;i++){
            // int idx = lower_bound(arr.begin(),arr.end(),arr[i]+k) - arr.begin();
            // cout<<arr[i]<<" --- "<<arr[idx]<<endl;
            for(int j=i+1;j<sz;j++){
                // cout<<arr[i]<<" ---edge--- "<<arr[j]<<endl;
                if(arr[j]-arr[i])
                    v[i].push_back(j);
            }
        }
        // cout<<"-------------------"<<endl;
        // for(int node = 0;node<sz;node++){
        //     for(auto val:v[node])
        //         cout<<val<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<sz;i++){
            if(!visited[i]){
                // cout<<"---------"<<endl;
                ans++;
                dfs(i,v);
            }
        }
        cout<<ans<<endl;
    }
}