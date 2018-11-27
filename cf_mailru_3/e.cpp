#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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

#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;
const int MOD1 = 1000010101;
const ll prm = 257;
ll h[1000005];
ll modpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1)
            res = (a*res)%MOD;
        a = (a*a)%MOD;
        b=b>>1;
    }
    return res;
}
ll modPos(ll a, ll mod=MOD){
    if (a >= 0) return a%mod;
    return (a%mod+mod)%mod;
}
bool is_equal(pi p1,pi p2){
    ll mul = modpow(prm,abs(p1.F-p2.F));
    if(p1.F>=p2.F)
        return modPos(h[p1.S]-h[p1.F]) == modPos(modPos(h[p2.S]-h[p2.F])*mul);
    else
        return modPos((mul*modPos(h[p1.S]-h[p1.F]))) == modPos(h[p2.S]-h[p2.F]);
}
int main(){
    string s,t;
    cin>>s>>t;
    int n = t.length();
    h[0] = t[0]-'a'+1;
    ll p_pow = prm;
    FOR(i,1,n){
        h[i] = (h[i-1] + ((t[i]-'a'+1) * p_pow) )%MOD;
        p_pow = (p_pow*prm)%MOD;
    }
    //F0R(i,n)cout<<h[i]<<" ";
    //cout<<endl;
    int cnt[] ={0,0};
    F0R(i,s.length())cnt[s[i]-'0']++;

    return 0;
}
