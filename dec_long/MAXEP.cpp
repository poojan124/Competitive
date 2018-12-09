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
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,c;
    cin>>n>>c;
    vector<int> range;
    int jump = (int)sqrt(n);
    int i=1;
    while(i<n){
        range.pb(i);
        i+=jump;
    }
    range.pb(n);
    int break_point;
    trav(x,range){
        cout<<1<<" "<<x<<"\n";
        fflush(stdout);
        int ans;
        cin>>ans;
        if(ans){
            break_point = x;
            cout<<"2"<<"\n";
            fflush(stdout);
            break;
        }
    }
    if(break_point==1){
        cout<<"3 1";
    }
    else{
        FOR(i,break_point-jump,break_point+1){
            cout<<"1 "<<i<<"\n";
            fflush(stdout);
            int ans;
            cin>>ans;
            if(ans){
                cout<<"3 "<<i;
                break;
            }
        }
    }
    return 0;
}