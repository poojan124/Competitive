#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modpow(ll a,ll b,ll m){
    ll res = 1;
    a = a%m;
    while(b>0){
        if(b%2)
            res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
int main(){
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll a[n+1];
    ll b[n+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0'){
            b[i]+=(b[i-1]+1);
            a[i]+=a[i-1];
        }
        else{
            a[i]+=(a[i-1]+1);
            b[i]+=b[i-1];
        }
    }

    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        //cout<<x<<" "<<y<<endl;
        ll xx = a[y];
        ll yy = b[y];
        if(x>=1){
            xx -= a[x];
            yy -= b[x];
        }
        //cout<<"--> "<<xx<<" "<<yy<<endl;
        ll s1 = modpow(2,xx,1000000007)-1;
        ll s2 = ((modpow(2,yy,1000000007)-1)*s1)%1000000007;
        cout<<(s2+s1)%1000000007<<endl;
    }
    return 0;
}