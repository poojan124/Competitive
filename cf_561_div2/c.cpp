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
    ll n,x,zero=0;
    vector<int> pos,neg;
    cin >> n;
    F0R(i, n){
        cin >> x;
        if(x>0)
            pos.pb(x);
        else if(x<0)
            pos.pb(-x);
        else
            zero=1;
    }
    ll ans = 0;
    sort(pos.begin(),pos.end());
    F0R(i, (int)pos.size()){
        //int idx1 = upper_bound(pos.begin(), pos.end(), pos[i]) - pos.begin();
        int idx2 = upper_bound(pos.begin(), pos.end(), pos[i]*2) - pos.begin();
        //cout << "idx1 " << idx1 << "idx2 "<<idx2 << endl;
        ans += (idx2-i-1);
    }
    /*
    F0R(i, (int)neg.size()){
        int idx = upper_bound(neg.begin(), neg.end(), neg[i]*2) - neg.begin();
        cout << "idx " << idx << endl;
        if(idx<neg.size()){
            if(neg[idx] == 2*neg[i])
                idx++;
        }
        ans += (idx-i-1);
    }*/
    cout << ans;
    return 0;
}
