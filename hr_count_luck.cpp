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
int cnt;
int toMatch;
bool visi[101][101];
void dfs(int i,int j,vector<string> &s){
    if(visi[i][j])return;
    visi[i][j] = true;
    if(s[i][j] == '*'){
        cout<<((cnt==toMatch)?"Impressed":"Oops!")<<endl;
    }
    int l,r,u,d;
    l = r = u = d = 0;
    int n = s.size();
    int m = s[0].size();
    if(j-1>=0 && (s[i][j-1]=='.' || s[i][j-1]=='*') && !visi[i][j-1])
        l = 1;
    if(j+1<m && (s[i][j+1]=='.' || s[i][j+1]=='*') && !visi[i][j+1])
        r = 1;
    if(i-1>=0 && (s[i-1][j]=='.' || s[i-1][j]=='*') && !visi[i-1][j])
        u = 1;
    if(i+1<n && (s[i+1][j]=='.' || s[i+1][j]=='*') && !visi[i+1][j])
        d = 1;
    
    cnt += (l+r+u+d) > 1 ;
    if(l)dfs(i,j-1,s);
    if(r)dfs(i,j+1,s);
    if(u)dfs(i-1,j,s);
    if(d)dfs(i+1,j,s);
    cnt -= (l+r+u+d) > 1 ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > v;
        vector<string> s(n);
        F0R(i,n)cin>>s[i];
        cin>>toMatch;
        memset(visi,0,sizeof(visi));
        F0R(i,n){
            F0R(j,m){
                if(s[i][j]=='M' ){
                    cnt = 0 ;
                    dfs(i,j,s);
                }
            }
        }
    }
    return 0;
}