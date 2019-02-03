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
const int ma = 100005;
int n,m;
vector<vector<int> > v(ma);
int visi[ma];
stack<int> st;
set<int> ss;
set<int> pawn;
set<int> lmao;
map<pi,pi> w; 
int ans = 0;
void dfs(int s){
    if(visi[s]==2)
        return;
    // cout<<"call for : "<<s<<"\n";
    visi[s] = 2;
    st.push(s);
    ss.insert(s);
    pawn.insert(s);
    trav(x,v[s]){
        if(ss.find(x)!=ss.end()){
            // cout<<"Cyecle found "<<s<<" and x is "<<x<<endl;
            stack<int> temp;
            while(!st.empty() && st.top()!=x){
                int xxx = st.top();
                st.pop();
                temp.push(xxx);
            }
            temp.push(x);
            st.pop();
            int mn = w[mp(s,x)].F;
            int mnidx = w[mp(s,x)].S;
            int X = temp.top();
            temp.pop();
            st.push(X);
            bool thigdu = false;
            while(!temp.empty()){
                int xxx = temp.top();
                temp.pop();
                // mn = min(mn,w[mp(X,xxx)].F);
                if(w[mp(X,xxx)].F < mn){
                    mn = w[mp(X,xxx)].F;
                    mnidx = w[mp(X,xxx)].S;
                    thigdu = false;
                }
                if(w[mp(X,xxx)].F == mn && lmao.find(w[mp(X,xxx)].S)!=lmao.end())
                    thigdu = true;
                st.push(xxx);
                X = xxx;
            }
            if(!thigdu)
                lmao.insert(mnidx);
            ans = max(ans,mn);
        }
        else{
            if(visi[x]!=2)
                dfs(x);
        }
    }
    visi[s] = 1;
    ss.erase(s);
    st.pop();
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n>>m;
    int x,y,z;
    F0R(i,m){
        cin>>x>>y>>z;
        v[x].pb(y);
        w[mp(x,y)] = mp(z,i+1);
    }
    memset(visi,0,sizeof(visi));
    F0R(i,n){
        if(visi[i+1]==0){
            dfs(i+1);
            trav(x,pawn)
                visi[x] = 2;
            pawn.clear();
        }
    }
    cout<<ans<<" "<<lmao.size()<<"\n";
    pv(lmao);
    return 0;
}