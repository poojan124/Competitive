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
pl get_num(ll x1,ll y1,ll x2,ll y2){
    ll pieces = (x2-x1+1)*(y2-y1+1);
    if(pieces%2==0)
        return mp(pieces/2,pieces/2);
    else{
        if((x1+y1)%2==0)
            return make_pair((pieces+1)/2,(pieces-1)/2);
        else
            return make_pair((pieces-1)/2,(pieces+1)/2);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll x1,x2,y1,y2,x3,x4,y3,y4;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;        
        pl bo1 = get_num(x1,y1,x2,y2);
        pl bo2 = get_num(x3,y3,x4,y4);
        pl ans = get_num(1,1,m,n);
        ll x5 = max(x1,x3);
        ll y5 = max(y1,y3);
        ll x6 = min(x2, x4);
        ll y6 = min(y2, y4); 
        if(x5<=x6 && y5<=y6){
            pl bo3 = get_num(x5,y5,x6,y6);
            ans.F = ans.F-bo1.F-bo2.F+bo3.F;
            ans.S = ans.S-bo1.S-bo2.S+bo3.S;
            cout<<ans.F+(bo1.F+bo1.S)-(bo3.F+bo3.S)<<" "<<ans.S+bo2.F+bo2.S<<endl;
        }
        else{
            ans.F = ans.F - bo1.F-bo2.F;
            ans.S = ans.S - bo1.S-bo2.S;
            cout<<ans.F+(bo1.F+bo1.S)<<" "<<ans.S+(bo2.F+bo2.S)<<endl;
        }
    }
    return 0;
}