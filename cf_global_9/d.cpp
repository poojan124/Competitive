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
        int n;
        cin >> n;
        int a[n];
        bool v[n+1];
        memset(v, 0, sizeof(v));        
        vector<int> extra_pos;
        F0R(i, n){
            cin >> a[i];
            if(a[i] == n){
                extra_pos.pb(i);
                continue;
            }
            if(!v[a[i]]){
                v[a[i]] = true;
            }
            else{
                extra_pos.pb(i);
            }
        }
        
        int ans = n;
        vector<int> pos;
        F0R(i,n){
            if(!v[i]){
                assert(extra_pos.size() > 0);
                int idx = extra_pos.back();
                extra_pos.pop_back();
                a[idx] = i;
                ans++;
                pos.pb(idx);
            }
        }
        cout << " ---- " << endl;
        for(auto x : a) cout << x << " ";
        cout << endl <<" --- "<< endl;
        map<int,int> m;
        F0R(i, n){
            m[a[i]] = i;
        }
        int pen = 9, cur=0;
        F0R(i, n){
            if(m[cur] == cur){
                cur++;
            }
            else{
                if(pen == cur){
                    ans++;
                    pos.append(cur);
                    pen = a[cur];
                    a[cur] = cur;
                }
                else{
                    ans += 2;
                    pos.append(m[cur]);
                    a[m[cur]] = pen;
                    pos.append(cur)
                }
            }
        }


    }
    return 0;
}



/**
  a[m[0]] = n;
        int cur = 0, nxt=-1;
        int boom = 1;
        F0R(i, n){
            if(cur == 0){
                boom = 0;
                nxt = a[0];
                a[0] = 0;
                cur = nxt;
                pos.pb(0);
                
            }
            else{
                pos.pb(cur-boom);
                nxt = a[cur-boom];
                a[cur-boom] = cur;
                cur = nxt;
            }
            for(auto x : a) cout << x << " ";
            cout << "--> " << cur;
            cout << endl;
        }
        cout << ans << endl;
        for(auto x : pos) cout << x << " ";
        cout << endl;
        for(auto x : a) cout << x << " ";
        cout << endl;
 **/

/**
2 0 1 8 7 4 6 5 3

2 9 1 8 7 4 6 5 3

0 9 1 8 7 4 6 5 3
 
0 9 2 8 7 4 6 5 3

0 1 2 8 7 4 6 5 3

0 1 2 8 7 4 6 5 9

0 1 2 3 7 4 6 5 9

0 1 2 3 7 4 6 5 8

0 1 2 3 7 4 6 5 8

**/