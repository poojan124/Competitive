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

string gen(string a, string b){
    string g = "";
    string lolz = "SETEST"; // ;_;
    F0R(i, a.length()){
        if(a[i] == b[i])
            g += a[i];
        else{
            string lol{a[i], b[i]};
            sort(lol.begin(), lol.end());
            int hue = lolz.find(lol);
            g += lolz[hue-1];
        }
    }
    return g;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<string> v(n);
    F0R(i, n)
        cin >> v[i];
    map<string, int> m;
    F0R(i, n){
        m[v[i]] = i;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string g = gen(v[i], v[j]);
            if((m.find(g) != m.end()) && (m[g] > j))
                ans ++ ;
        }
    }
    cout << ans;
    return 0;
}
