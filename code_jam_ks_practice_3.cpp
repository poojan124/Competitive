#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

ll pow(ll a, ll b, ll n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) x = (x*y) % n; 
        y = (y*y) % n; 
        b /= 2;
    }
    return x % n;
}

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        ll n,k,x1,y1,c,d,e1,e2,f;
        cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        vector<ll> A(n+1);
        for(int i=1;i<=n;i++){
            A[i] = (x1 + y1) % f;
            ll xo=x1,yo=y1;
            x1 = ((c * xo)% f + (d * yo)% f + e1) % f;
            y1 = ((d * xo)% f + (c * yo)% f + e2) % f;
        }
        ll sm = k;
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(i!=1){
                ll X = (pow(i, k+1, mod)-1) * pow(i-1, mod-2, mod) % mod;
                X--;
                if(X<0) X += mod;
                sm = sm + X;
            }
            sm %= mod;
            ans = ans + ((A[i] * (n-i+1) % mod) * sm ) % mod;
            ans %= mod;
        }   
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}