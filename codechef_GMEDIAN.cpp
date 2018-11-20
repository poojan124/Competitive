#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m (ll)1000000007 
ll facto[1001];
ll invfacto[1001];
ll fac[1001][1001];;
ll modpow(ll x,ll y){
    ll res = 1;
    x = x%m;
    while(y>0){
        if(y&1)
            res = (res*x)%m;
        y>>=1;
        x=(x*x)%m;
    }
    return res;
}
void pre(){
    facto[0]=1;
    for(int i=1;i<=1000;i++)
        facto[i] = ((ll)facto[i-1]*i)%m;
    for(int i=1;i<=1000;i++)
        invfacto[i] = modpow(facto[i],m-2);   
    for(int i=0;i<1001;i++){
        fac[i][0] = 1;
        fac[0][i] = 1;
    }
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=i;j++)
            fac[i][j] = ((facto[i]*invfacto[j])%m*invfacto[i-j])%m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    pre();
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll ans = modpow(2,n)-1;
        ll ans2 = 0;
        sort(a,a+n);
        for(int i = 0;i<=n-2;i++){
            if(a[i]==a[i+1])
                continue;
            cout<<"???"<<endl;
            int l = i;
            int r = n-i-2;
            int R = min(l,r);
            for(int j=0;j<=R;j++)
                ans2 = (ans2 + (fac[l][j]*fac[r][j])%m)%m;
        }
        // ans-=ans2;
        cout<<ans<<" "<<ans2<<endl;
        cout<<(m + (ans-ans2)%m)%m<<endl;
    }
    return 0;
}