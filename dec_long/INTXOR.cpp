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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        int i=1;
        vector<pl> query;
        vector<ll> res;
        if(n%2==0){
            while(i<n){
                query.pb(mp(i,i+1));
                query.pb(mp(i,i+1));
                i+=2;
            }
        }
        else{
            while(i<=n-4){
                query.pb(mp(i,i+1));
                query.pb(mp(i,i+1));
                i+=2;
            }
            query.pb(mp(n-2,n-1));
            query.pb(mp(n-2,n));
            query.pb(mp(n-1,n));
        }
        int third = 3;
        trav(x,query){
            cout<<"1 "<<x.F<<" "<<x.S<<" "<<third<<"\n";
            fflush(stdout);
            ll response;
            cin>>response;
            res.pb(response);
            third++;
            if(third>n)
                third = 1;
        }
        i = 0;
        int j = 4;
        // pv(res);
        if(n%2==0){
            while(i+2<n){
                // cout<<"check1 "<<j<<" "<<res[i]<<" "<<res[i+1]<<" "<<res[i+2]<<" "<<(res[i]^res[i+1]^res[i+2])<<"\n";
                if(j>=n)
                    j=0;
                a[j] = res[i]^res[i+1]^res[i+2];
                j++;
                if(j>=n)
                    j=0;
                if(i+3<n){
                    // cout<<"check2 "<<j<<" "<<res[i]<<" "<<res[i+1]<<" "<<res[i+2]<<" "<<(res[i]^res[i+1]^res[i+3])<<"\n";
                    a[j] = res[i]^res[i+1]^res[i+3];
                    j++;
                    if(j>=n)
                        j=0;
                }
                i+=2;
            }
            a[2] = res[0]^a[0]^a[1];
            a[3] = res[1]^a[0]^a[1];
        }
        else{
            while(i+2<n){
                // cout<<"check1 "<<j<<" "<<res[i]<<" "<<res[i+1]<<" "<<res[i+2]<<" "<<(res[i]^res[i+1]^res[i+2])<<"\n";
                if(j>=n)
                    j=0;
                a[j] = res[i]^res[i+1]^res[i+2];
                j++;
                if(j>=n)
                    j=0;
                if(i+3<n){
                    // cout<<"check2 "<<j<<" "<<res[i]<<" "<<res[i+1]<<" "<<res[i+2]<<" "<<(res[i]^res[i+1]^res[i+3])<<"\n";
                    a[j] = res[i]^res[i+1]^res[i+3];
                    j++;
                    if(j>=n)
                        j=0;
                }
                i+=2;
            }
            // cout<<"_--------"<<"\n";
            // pv(a);
            a[0] = a[0]^a[n-1]^a[n-2];
            // cout<<a[0]<<" huh\n";
            a[1] = a[1]^a[0]^a[n-1];
            a[2] = res[0]^a[0]^a[1];
            a[3] = res[1]^a[0]^a[1];
        }
        cout<<"2 ";
        pv(a);
        fflush(stdout);
        ll lmao;
        cin>>lmao;
    }
    return 0;
}