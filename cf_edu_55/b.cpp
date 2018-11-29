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
string to_string(vector<char> &vv){
    string sss;
    trav(x,vv)
        sss+=x;
    return sss;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    int ii = 0;
    while(s[ii]=='S')
        ii++;
    int jj = n-1;
    while(s[jj]=='S')
        jj--;
    jj++;
    if(ii>jj){
        cout<<"0";
        return 0;
    }
    vector<char> sss(s.begin()+ii,s.begin()+jj);
    s = to_string(sss);
    // cout<<s<<endl;
    int cnt1 = 0;
    int cnt2 = 0;
    trav(x,s){
        if(x=='G'){
            if(cnt2>0)
                v.pb(-cnt2);
            cnt2 = 0;
            cnt1++;
        }
        else{
            if(cnt1>0)
                v.pb(cnt1);
            cnt1 = 0;
            cnt2++;
        }
    }
    if(cnt1>0)
        v.pb(cnt1);
    if(cnt2>0)
        v.pb(-cnt2);
    vector<int> ans;
    int ANS = 0;
    if(v.size()==1){
        cout<<v[0]<<endl;
        return 0;
    }
    if(v.size()==3)
        if(v[1]==-1)
            ANS = v[0]+v[2];
        else
            ANS = max(v[0],v[2])+1;
    else{
        FOR(i,0,v.size()){
            if(v[i]>0){
                if(i+2<v.size() && v[i+1]==-1)
                    ans.pb(v[i]+v[i+2]+1);
                else ans.pb(v[i]+1);
            }
        }
        if(!ans.empty())
            ANS = *max_element(all(ans));
    }
    cout<<ANS<<endl;
    return 0;
}