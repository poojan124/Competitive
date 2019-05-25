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
vector<vector<int> > v(100000+5);
bool respect[100000+5];
bool dead[100000+5];
void dfs(int s, int p){
    dead[s] = respect[s];
    trav(ch, v[s]){
        if(ch != p){
            dead[s]&=respect[ch];
            dfs(ch, s);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x,y,root;
    F0R(i, n){
        cin >> x >> y;
        if(x == -1) root = i+1;
        else{
            v[i+1].pb(x);
            v[x].pb(i+1);
        }
        respect[i+1] = y;
    }
    dfs(root, -1);
    bool flag = false;
    FOR(i,1,n+1){
        if(dead[i]){
            cout << i << " ";
            flag = true;
        }
    }
    if(!flag)
        cout << -1;
    return 0;
}
