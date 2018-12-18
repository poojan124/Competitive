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
    cin>>n;
    map<int,int> m;
    int a[n];
    F0R(i,n){
        cin>>a[i];
        m[a[i]]++;
    }
    bool ok = true;
    trav(p,m){
        if(p.S%(n-p.F)!=0){
            ok=false;
            break;
        }
    }
    if(ok){
        cout<<"Possible\n";
        int start = 1;
        trav(xx,a){
            pi i = mp(xx,m[xx]);
            if(xx==0){
                cout<<1<<" ";
            }
            int idx = i.F + floor((i.S-1)/(double)(n-i.F)) ;
            cout<<idx<<" ";
            m[i.F]--;
        }
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}