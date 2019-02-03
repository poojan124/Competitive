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
    int n,m;
    cin>>n>>m;
    map<string,int> ma;
    vector<pair<int,string> > q;
    int ones = 0;
    map<string,int> idx;
    int lol = 0;
    F0R(i,n){
        int x;
        cin>>x;
        if(x==2){
            string t;
            cin>>t;
            if(idx.find(t)==idx.end())
                idx[t] = lol++;
            q.pb(mp(2,t));
        }
        else{
            ones++;
            q.pb(mp(1,"PJ"));
        }
    }
    int i = 1;
    int presum[ones][m];
    memset(presum,0,sizeof(presum));
    int O = 0;
    while(i<n){
        if(q[i].F==1){
            trav(xx,ma){
                if(O==0)
                    presum[O][idx[xx.F]] = xx.S;
                else
                    presum[O][idx[xx.F]] =  xx.S;
            }
            O++;
            ma.clear();
        }
        else{
            ma[q[i].S]++;
        }
        i++;
    }
    if(q[n-1].F!=1){
        trav(xx,ma){
            presum[O][idx[xx.F]] = xx.S; 
        }
        O++;
        ma.clear();
    }
    int ans = presum[ones-1][0];
    F0R(i,m){
        ans = max(ans,presum[ones-1][i]);
    }
    // F0R(i,ones){
    //     F0R(j,m)
    //         cout<<presum[i][j]<<" ";
    //     cout<<"\n";
    // }
    F0R(i,ones-1){
        int x = 0;
        int y = 0;
        F0R(j,m){
            x = max(presum[i][j],x);
        }
        F0R(j,m){
            y = max(presum[i+1][j]-presum[i][j],y);
        }
        ans += max(ans,x+y);
    }
    cout<<ans;
    return 0;
}