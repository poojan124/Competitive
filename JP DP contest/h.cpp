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

#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    char v[n][m];
    F0R(i,n)
        F0R(j,m)
            cin >> v[i][j];
    ll dp[n][m];
    memset(dp, 0, sizeof(dp));
    F0R(i, n){
        F0R(j, m){
            if(i==0 && j==0) dp[i][j] = 1;
            else if(i==0 && v[i][j] != '#') dp[i][j] = dp[i][j-1];
            else if(j==0 && v[i][j] != '#') dp[i][j] = dp[i-1][j];
            else{
                if(v[i][j] != '#')
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];     
            }
            dp[i][j] = dp[i][j] % MOD;
        }
    }
    cout << dp[n-1][m-1];
    return 0;
}