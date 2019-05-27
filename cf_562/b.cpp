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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pi> v;
    int n,m,x,y;
    map<int,int> M;
    cin >> n >> m;
    F0R(i,m){
        cin >> x >> y;
        M[x]++;
        M[y]++;
        v.pb(mp(x,y));
    }
    vector<pi> cnt;
    trav(xx,M)
        cnt.pb(xx);
    sort(all(cnt),[](pi a, pi b){return a.S>b.S;});
    if(cnt.size() == 1){
        cout << "YES";
        return 0;
    }
    F0R(i,((int)cnt.size())-1){
        vector<pi> temp;
        trav(p, v){
            if(p.F != cnt[i].F && p.S != cnt[i].F)
                temp.pb(p);
        }
        bool f1 = false;
        FOR(j,i+1,((int)cnt.size())){
            if(cnt[i].S + cnt[j].S < m)
                break;
            int pr = cnt[j].F;
            f1 = true;
            bool ans = true;
            trav(p, temp){
                if (p.F!=pr && p.S!=pr){
                    ans = false;
                    break;
                }
            }
            if(ans){
                cout << "YES";
                return 0;
            }
        }
        if(!f1)
            break;
    }
    cout << "NO" ;
    return 0;
}
