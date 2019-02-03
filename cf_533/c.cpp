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

const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,l,r;
    cin>>n>>l>>r;
    ll rem[]={0,0,0};
    while(l%3!=0 && l<r){
        rem[l%3]++;
        l++;
    }
    while(r%3!=0 && r>l){
        rem[r%3]++;
        r--;
    }
    if(l==r)
        rem[l%3]++;
    ll x = l/3;
    ll y = r/3;
    ll i = (y-x);
    rem[0] += i;
    rem[1] += i; 
    rem[2] += i;
    if(l!=r)
        rem[0]++;
    // pv(rem);
    ll dp[n][3];
    dp[0][0] = rem[0];
    dp[0][1] = rem[1];
    dp[0][2] = rem[2];
    FOR(i,1,n){
        dp[i][0] = ((dp[i-1][0]*rem[0])%MOD + (dp[i-1][1]*rem[2])%MOD + (dp[i-1][2]*rem[1])%MOD ) %MOD;
        dp[i][1] = ((dp[i-1][0]*rem[1])%MOD + (dp[i-1][1]*rem[0])%MOD + (dp[i-1][2]*rem[2])%MOD ) %MOD;
        dp[i][2] = ((dp[i-1][0]*rem[2])%MOD + (dp[i-1][1]*rem[1])%MOD + (dp[i-1][2]*rem[0])%MOD ) %MOD;
    }
    // F0R(i,n){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    // }
    cout<<dp[n-1][0];
    return 0;
}