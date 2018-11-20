#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define pb push_back
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
    string s;
    cin>>s;
    int len = s.length();
    vector<pi> v;
    for(int i = 1;i<=5;i++){
        for(int j=1;j<=20;j++){
            if(i*j>=len){
                v.pb(mp(i,j));
                break;
            }
        }
    }
    pair<int,pi> min_ = mp(200,mp(-1,-1));
    assert(v.size()>0);
    EACH(i,v){
        if(((i.F*i.S)-len)<min_.F){
            min_ = mp(((i.F*i.S)-len),i);
        }
    }
    
    return 0;
}