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
bool visi[100005];
bool isleaf[100005];
vector<vector<int> > v(100005);
vector<int> cntleaf;
int dfs(int s){
    if(isleaf[s] && !visi[s]){
        visi[s] = 1;
        return 1;
    }
    if(visi[s])
        return 0;
    visi[s] = 1;
    int sum = 0;
    trav(x,v[s])
        sum += dfs(x) ;
    cntleaf.pb(sum);
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    fill(isleaf,isleaf+n+1,1);
    F0R(i,n-1){
        int x;
        cin>>x;
        v[i+2].pb(x);
        v[x].pb(i+2);
        isleaf[x] &= 0;
    }
    memset(visi,0,sizeof(visi));
    int xd = dfs(1);
    sort(all(cntleaf));
    F0R(i,n-cntleaf.size())
        cout<<"1 ";
    trav(i,cntleaf)
        cout<<i<<" ";
    return 0;
}