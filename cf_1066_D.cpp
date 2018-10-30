#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    ll s[n];
    cin>>a[0];
    s[0] = a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    bool ok = false;
    int l = 0;
    int r = n-1;
    while( (ll)k * m < (s[r]-s[l]+a[l]))
        l++;
    // cout<<l<<" ----- "<<r<<endl;
    while(!ok && l<=r){
        ok = true;
        int rem = m;
        for(int x=l;x<=r;){
            int val = s[x]+k-a[x];
            // cout<<"searching for val "<<val<<" idx " <<x<<endl;
            int idx = lower_bound(s+l,s+r+1,val) - (s);
            rem--;
            // cout<<"index chaned to "<<x<<endl;
            if(rem<0){
                ok = false;
                break;
            }
            if(idx>=n)
                break;
            if(s[idx] == val)
                idx++;
            x = idx;
        }
        // cout<<"what "<< rem << endl;
        if(!ok)
            l++;
    }
    // cout<<l<<" --- "<<r<<endl;
    cout<<r-l+1<<endl;
}