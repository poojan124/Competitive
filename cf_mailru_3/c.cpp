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

#define pv(v) EACH(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) EACH(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) EACH(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

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
bool cmp(pi a,pi b){
    return a.F>b.F;
}
int n,m;
vector<pi> a;
map<int,int > v;
bool visi[2002];
map<int,int > ma;
int get_best(){
    int j = 0;
    while(j<2*n){
        if(!visi[a[j].S])
            return a[j].S;
        j++;
    }
    return -1;
}
int check(){
    trav(x,v){
        if(!visi[x.S]){
            int pick;
            if(ma[x.F]>ma[x.S])pick = x.F;
            else pick = x.S;
            return pick;
        }
    }
    return -1;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin>>n>>m;
    F0R(i,2*n){
        int x;
        cin>>x;
        a.pb(mp(x,i+1));
    }
    sort(all(a),cmp);
    F0R(i,m){
        int x,y;
        cin>>x>>y;
        v[x] = y;
        v[y] = x;
    }
    memset(visi,0,sizeof(visi));
    F0R(i,2*n){
        ma[a[i].S] = a[i].F;
    }
    int t;
    cin>>t;
    int cnt = n;
    if(t==1){
        trav(x,v){
            if(visi[x.F])continue;
            cnt--;
            int pick;
            if(ma[x.F]>ma[x.S])pick = x.F;
            else pick = x.S;
            cout<<pick<<endl;
            fflush(stdout);
            int reply;
            cin>>reply;
            visi[pick] = 1;
            visi[reply] = 1;
        }
        while(cnt>0){
            int my = get_best();
            assert(my!=-1);
            cout<<my<<endl;
            fflush(stdout);
            int jury;
            cin>>jury;
            visi[jury]= 1 ;
            visi[my] = 1;
            cnt--;
        }
    }
    else{
        while(cnt>0){
            cnt--;
            int jury;
            cin>>jury;
            if(v.find(jury)!=v.end() && !visi[v[jury]]){
                cout<<v[jury]<<endl;
                fflush(stdout);
                visi[jury] = 1;
                visi[v[jury]] = 1;
            }
            else{
                visi[jury] = 1;
                int ff = check();
                if(ff!=-1){
                    cout<<ff<<endl;
                    fflush(stdout);
                    visi[ff] = 1;
                    continue;
                }
                int my = get_best();
                assert(my!=-1);
                cout<<my<<endl;
                fflush(stdout);
                visi[my] = 1;
            }
        }
    }
    return 0;
}