#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define trav(x,v) for (auto &x : v)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pv(v) EACH(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) EACH(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) EACH(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

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
        if(b%2)res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k1,k2;
    cin>>k1;
    bool a[1000000],b[1000000];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    F0R(i,k1){
        int x;
        cin>>x;
        a[x] = 1;
    }
    cin>>k2;
    F0R(i,k2){
        int x;
        cin>>x;
        b[x] = 1;
    }
    int who = 0;
    int ans = 0;
    FOR(i,0,1000000){
        if(a[i] && b[i]){
            who = 0;
            ans++;
        }    
        else if(who ==0){
            if(a[i]){
                ans++;
                who = 1;
            }
            if(b[i]){
                ans++;
                who = 2;
            }
        }
        else if(who == 2 && a[i]){
            ans++;
            who = 1;
        }
        else if(who == 1 && b[i]){
            ans++;
            who = 2;
        }
    }
    cout<<ans;
    return 0;
}