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
map<int,int> m1,m2;
int gs = 0;
    
void gc(string s){
    stack<char> st;
    trav(c,s){
        if(c==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                st.push(')');
        }
        else{
            st.push('(');
        }
    }
    pi p = {0,0};
    //cout<<"asfd";
    while(!st.empty()){
        if(st.top() == '(')
            p.F++;
        else
            p.S++;
        st.pop();
    }
    if(p.F==0){
        m1[p.S]++;
    }
    else if(p.S==0){
        m2[p.F]++;
    }
    if(p.F==0 && p.S==0)
        gs++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string ss;
    F0R(i,n){
        cin>>ss;
        gc(ss);
    }
    int ans = gs/2;
    // pm(m1);
    trav(x,m1){
        ans += min(x.S,m2[x.F]);
    }
    cout<<ans;
    return 0;
}