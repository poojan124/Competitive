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

// at the end of the day its still about who you first want to share your good news with.
// And not everyone is lucky to have someone like this. So if you got one respect that.
bool dp[100005];

bool solve(int n, int k, vector<int> &v, bool flag){
    bool ok = false;
    for(auto x : v){
        ok &= solve(n, k-x, v, !flag);
    }
    
    return !ok;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    F0R(i, n) cin >> v[i];
    cout << (solve(n, k, v)?"First":"Second");
    return 0;
}