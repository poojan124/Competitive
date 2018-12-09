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
    string s;
    cin>>s;
    int n = s.length(),cntr = 0;
    stack<int> st;
    int dp[n];
    fill(dp,dp+n,-1);
    F0R(i,n){
        if(s[i]=='(')
            st.push(i);
        if(s[i]==')'){
            if(!st.empty()){
                int pre_open = st.top();
                st.pop();
                dp[i] = pre_open;
                if(pre_open>0)
                    if(s[pre_open-1]==')' && dp[pre_open-1]!=-1)
                        dp[i] = dp[pre_open-1];
            }
            else
                dp[i] = -1;
        }    
    }
    int ans = 0;
    int ans_cnt = 1;
    F0R(i,n){
        if(dp[i]!=-1){
            int cur = i-dp[i]+1;
            if(cur>ans){
                ans = cur;
                ans_cnt = 1;
            }
            else if(cur==ans)
                ans_cnt++;
        }
    }
    if(ans==0)
        cout<<"0 1";
    else
        cout<<ans<<" "<<ans_cnt;
    return 0;
}