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
        if(b%2)res = (res*a) % m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}
int v[102][102];
map<string,int> ma;
bool visited[102];
const int max_ = (1<<30)-1;
void bfs(int s,int n){
    queue<pi > q;
    q.push(mp(0,0));
    int dis[102];
    int level[102];
    fill(level,level+102,500);
    level[0] = 1;
    fill(dis,dis+102,max_);
    dis[0] = 0;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        F0R(i,n){
            if(!visited[i] && v[p.F][i] && level[p.F]<level[i]  && v[p.F][i]<dis[i]){
                dis[i] = v[p.F][i];
                q.push(mp(i,p.S+1));
                level[i] = level[p.F]+1;
            }
        }
    }
    int ans = 0;
    F0R(i,n){
        if(dis[i]==max_){
            cout<<"Impossible";
            return;
        }
        ans+=dis[i];
    }
    cout<<ans;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(v,0,sizeof(v));
    ma["English"] = 0;
    F0R(i,n){
        string node;
        cin>>node;
        ma[node] = i + 1;
    }
    F0R(i,m){
        string x,y;
        int cost;
        cin>>x>>y>>cost;
        int xx=ma[x],yy=ma[y];
        v[xx][yy] = cost;
        v[yy][xx] = cost;
    }
    bfs(0,n+1);
    return 0;
}