#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define pb push_back`
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define EACH(x,v) for (auto &x : v)
ll gcd(ll a, ll b) {
      if (a == 0) return b;
      return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
ll modPos(ll a, ll mod=MOD){
    if (a >= 0) return a%mod;
    return (a%mod+mod)%mod;
}
ll modpow(ll a,ll b,ll m = MOD){
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll n = y-x+1;
        if(n==1){
            if(x%2)
                cout<< -x<<endl;
            else    
                cout<< x<<endl;
        }
        else{
            if(x%2==1){
                if(n%2==0)
                    cout<<(n/2)<<endl;
                else
                    cout<<((n-1)/2)-y<<endl;
            }
            else{
                if(n%2==0)
                    cout<<(ll)(-1)*(n/2)<<endl;
                else
                    cout<<(ll)(-1)*((n-1)/2)+y<<endl;
            }
        }
    }
    return 0;
}