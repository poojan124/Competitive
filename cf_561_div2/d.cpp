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
    int n;
    cin >> n;
    while(n--){
        ll a,b,m;
        cin >> a >> b >> m;
        bool ok = false;
        ll fac = -1;
        ll N = -1;
        if(a == b){
            cout << "1 " << a << endl;
            continue;
        }
        FOR(i,0,64){
            ll p = (ll)pow(2, i); 
            double d = b/(double)p;
            //cout << "d " << d <<"i" << i << endl;
            if(d>=a+1 && d<=m+a){
                ok = true;
                fac = (ll)d;
                N = i;
                break;
            }
            if(d < a+1)
                break;
        }
        if(ok){
            //cout << "N " << N << endl;
            vector<ll> ans(N+2);
            vector<ll> mult(N+1);
            vector<ll> plex(N+1);
            ans[0] = a;
            ll need = b - pow(2, N)*(a+1);
            FOR(i,0,N+1){
                mult[i] = pow((ll)2,(ll)max(N-i-1,0ll));
                plex[i] = 1;
            }
            //cout << "mult" << endl;
            //pv(mult);
            FOR(i,0,(int)mult.size()){
                //cout << "need "<< need << endl;
                if(mult[i]<=need){
                    ll factor = (ll)need/mult[i];
                    if(factor + 1 > m)
                        factor = m-1;
                    need -= factor*mult[i];
                    plex[i] += factor;
                }
            }
            //cout << "plex" << endl;
            //pv(plex);
            ll s = 0;
            FOR(i,0,N+1){
                s += ans[i];
                ans[i+1] = s + plex[i];
            }
            cout << ans.size() << " ";
            pv(ans);
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
