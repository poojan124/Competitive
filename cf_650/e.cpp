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

vector<int> prime_fac(int n){
    vector<int> v;
    if(n%2 == 0){
        v.pb(2);
        while(n%2 == 0){
            n/=2;
        }
    }
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i == 0){
            v.pb(i);
            while(n%i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        v.pb(n);
    }
    return v;
}

bool cmp(pair<char,int> p1, pair<char, int> p2){
    return p1.S > p2.S;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        unordered_map<char, int> m;
        string s;
        cin >> s;
        for(auto x : s){
            m[x]++;
        }
        vector< pair<char, int> > mv;
        for(auto x : m){
            mv.pb(x);
        }
        sort(mv.begin(), mv.end(), cmp);
        int ans = mv[0].S;
        vector<int> fac = prime_fac(k);
        // cout << fac.size() << endl;
        // for(auto x : mv){
        // cout << x.F << " --- " << x.S << endl;
        // }
        fac.pb(k);
        for(int x : fac){
            // cout << x << " -- fac "  << endl;
            int min_ = INT_MAX;
            if(x > 26){
                continue;
            }
            vector<int> tmp;
            for(int i=0;i<mv.size();i++){
                tmp.pb(mv[i].S);
            }
            for(int xx = 1; xx <= mv[0].S ; xx++){
                int cnt = 0;
                for(auto xxx : tmp){
                    cnt += (int)(xxx/xx);
                }
                // cout << xx << " " << cnt << endl;
                if(cnt >= x){
                    // cout << "wtf " << endl;
                    ans = max(ans, xx * x);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}