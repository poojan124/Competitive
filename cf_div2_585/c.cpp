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
    string s1,s2;
    cin >> s1 >> s2;
    pi p1=mp(0,0), p2=mp(0,0);
    trav(x, s1) (x=='a'?p1.F:p1.S)++;
    trav(x, s2) (x=='a'?p2.F:p2.S)++;
    if((p1.F+p2.F)%2!=0){
        cout << -1;
        return 0;
    }
    vector<pi> ans;
    vector<int> a,b;
    F0R(i,n){
        if(s1[i]!=s2[i]){
            if(s1[i]=='a')
                a.pb(i+1);
            else
                b.pb(i+1);
        }
        if((int)a.size()==2){
            ans.pb(mp(a[0],a[1]));
            a.clear();
        }
        if((int)b.size()==2){
            ans.pb(mp(b[0],b[1]));
            b.clear();
        }
    }
    if(a.size()>0){
        ans.pb(mp(a[0],a[0]));
        ans.pb(mp(a[0],b[0]));
    }
    cout << (int)ans.size() << endl;
    trav(x, ans)
        cout << x.F << " " << x.S << endl;
    return 0;
}
