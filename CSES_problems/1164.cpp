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

bool cmp(pi p1, pi p2){
    return p1.S < p2.s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin >> n;
    vector<pi> v;
    F0R(i,n){
        cin >> a >> b;
        v.pb({1,a});
        v.pb({2,b+1});
    }
    sort(v.begin(), v.end(), cmp);
    deque<int> q;
    int ans=0;
    vector<int> av;
    for(auto x : v){
        if(x.F == 1){
            if(q.empty()){
                ans++;
                q.push_back(ans);
            }
        }
    }
    return 0;
}