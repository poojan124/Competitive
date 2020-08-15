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

bool cmp(int a, int b){
    return a > b;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.F > b.F;
}

/*
    i am so dumb missed this fking simple case:
    1 1 2
    4
    4
    3 3

    Answer is fking 4*3 + 4*3. So greedy wont work you dumb fuck.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b;
    cin >> r >> g >> b;
    vector<int> R(r), G(g), B(b);
    F0R(i, r) cin >> R[i];
    F0R(i, g) cin >> G[i];
    F0R(i, b) cin >> B[i];
    sort(R.begin(), R.end(), cmp);
    sort(G.begin(), G.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    ll ans = 0;
    int i=0,j=0,k=0;
    while(true){
        vector<pair<int, int>> v;
        if(i < r) v.pb({R[i], 0});
        if(j < g) v.pb({G[j], 1});
        if(k < b) v.pb({B[k], 2});
        if(v.size() <= 1) break;
        sort(v.begin(), v.end(), cmp2);
        cout << v[0].F << " " << v[1].F << " " << v[2].F << endl;
        ans += v[0].F * v[1].F;
        i += ((v[0].S == 0) | (v[1].S == 0));
        j += ((v[0].S == 1) | (v[1].S == 1));
        k += ((v[0].S == 2) | (v[1].S == 2));
        cout << i << " " << j << " " << k << " " << ans << endl;
    }
    cout << ans;
    return 0;
}