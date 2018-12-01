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
int dp[505][5005];
int a[505];
int n,k;
vector<int> get_bag(){
    vector<int> bag;
    int max_sum = -1;
    FOR(i,1,k+1){
        FOR(j,1,n+1){
            if(dp[i][j])
                max_sum = max(max_sum,j);
        }
    }
    FORd(i,1,k+1){
        if(dp[i][max_sum]){
            if(!dp[i-1][max_sum]){
                bag.pb(a[i]);
                max_sum-=a[i];
            }
            if(max_sum==0)
                return bag;
        }
    }
    return bag;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    FOR(i,1,k+1)cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    sort(a+1,a+k+1);
    FOR(i,1,k+1){
        FOR(j,0,n+1){
            if(j>=a[i])
                dp[i][j] = dp[i-1][j-a[i]] | dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    auto bag = get_bag();
    int t=0;
    int ans[k+1];
    fill(ans,ans+k+1,-1);
    int j=0;
    sort(all(bag));
    FOR(i,1,k+1){
        if(j==bag.size())
            break;
        if(a[i]==bag[j]){
            ans[i] = t;
            j++;
            t+=a[i];
        }
    }
    t = 0;
    //FOR(i,1,k+1)cout<<ans[i]<<" ";
    //cout<<endl;
    FOR(i,1,k+1){
        if(ans[i]==-1){
            ans[i] = t;
            t+=a[i];
        }
    }
    FOR(i,1,k+1)cout<<ans[i]<<" ";
    return 0;
}
