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
int visi[500005];
vector<int> v[500005];
int cnt = 0;
int x = 0;
void dfs(int s){
    if(visi[s])
        return;
    visi[s] = x;
    cnt++;
    trav(ch, v[s]){
        dfs(ch);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    memset(visi, 0, sizeof(visi));
    F0R(i, m){
        int xx, par, val;
        cin >> xx;
        if(xx==0)
            continue;
        cin >> par;
        F0R(i,xx-1){
            cin >> val; 
            v[par].pb(val);
            v[val].pb(par);
        }
    }
    vector<int> cntr;
    FOR(i,1,n+1){
        if(!visi[i]){
            cnt = 0;
            x++;
            dfs(i);
            cntr.pb(cnt);
        }
    }
    FOR(i,1,n+1){
        cout << cntr[visi[i] - 1] << " ";
    }
    return 0;
}
