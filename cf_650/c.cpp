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
        int n,k;
        cin >> n >> k;
        string s,pad="";
        cin >> s;
        
        F0R(i,k) pad += '0';
        
        s = pad + s + pad;
        
        int ans=0,l=k,r=k,idx=-1;
        bool left = true;

        for(int i=0;i<s.length();i++){
            // cout << l << " " << r << endl;
            if(l == 0 && r == 0){
                ans++;
                l = 0;
                r = k;
                left = true;
            }
            if(s[i] == '1'){
                l = k;
                r = k;
                left = true;
                continue;
            }
            if(l == 0 && left){
                left = !left;
                continue;
            }
            (left?l:r)--;
        }
        if(l == 0 && r == 0){
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}