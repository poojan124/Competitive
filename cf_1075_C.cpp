#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,ma;
    cin>>n>>ma;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(0);
    v.push_back(1000000000);
    sort(v.begin(),v.end());
    map<int,int> m1;
    map<int,int> m2;
    int cntr = 0;
    for(int i=0;i<ma;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(x!=1)continue;
        x--;
        int r = lower_bound(v.begin(),v.end(),y)  - v.begin();
        int l = lower_bound(v.begin(),v.end(),x) - v.begin();
        if(v[r]!=y)
            r--;
        if(r<=l)
            continue;
        m1[v[l]]++;
        m2[v[r]]++;
    }
    int ans = 1000000009;
    int at = m1[v[0]];
    ans = min(ans,at);
    for(int i=1;i<v.size()-1;i++){
        at = at - m2[v[i]] + 1;
        ans = min(ans,at);
    }
    cout<<ans<<endl;
    return 0;
}