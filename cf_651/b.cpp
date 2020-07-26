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
    int t;
    cin >> t;
    while(t--){
        int x,n;
        cin >> n;
        vector<int> e,o;
        int e_cnt = 0, o_cnt = 0;
        for(int i=0;i<2*n;i++){
            cin >> x;
            if(x%2){
                o.pb(i+1);
                o_cnt++;
            }
            else{
                e.pb(i+1);
                e_cnt++;
            }
        }
        if(o_cnt % 2){
            o.pop_back();
            e.pop_back();
        }
        else{
            if(o.size()==0){
                e.pop_back();
                e.pop_back();
            }
            else{
                o.pop_back();
                o.pop_back();
            }
        }
        for(int i = 0 ; i < o.size() ; i +=2 )
            cout << o[i] << " " << o[i+1] << endl;
        for(int i = 0 ; i < e.size() ; i +=2 )
            cout << e[i] << " " << e[i+1] << endl;
        
    }
    return 0;
}