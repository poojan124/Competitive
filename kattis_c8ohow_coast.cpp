#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define EACH(x,v) for (auto &x : v)
ll gcd(ll a, ll b) {
      if (a == 0) return b;
      return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
ll modPos(ll a, ll mod=MOD){
    if (a >= 0) return a%mod;
    return (a%mod+mod)%mod;
}
ll modpow(ll a,ll b,ll m = MOD){
    ll res = 1;
    a = a%m;
    while(b>0){
        if(b%2)
            res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
char grid[1005][1005];
bool v[1005][10005];
int n,m;
void dfs(int x,int y){
    if(x<0 || x>=n+2 || y<0 || y>=m+2)
        return;
    if(grid[x][y]=='1' || v[x][y])
        return;
    v[x][y] = 1;
    grid[x][y] = 'S';
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    memset(v,0,sizeof(v));
    for(int i=0;i<n+2;i++)
        for(int j=0;j<m+2;j++)
            grid[i][j] = 'S';
    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++)
            cin>>grid[i][j];
    dfs(0,0);
    int ans = 0;
    int x[] = {1,-1,0,0};
    int y[] = {0,0,1,-1};
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(grid[i][j]=='1'){
                for(int c=0;c<4;c++)
                    ans += ((grid[x[c]+i][y[c]+j] == 'S')?1:0);
            }
        }
    }
    cout<<ans;
    return 0;
}