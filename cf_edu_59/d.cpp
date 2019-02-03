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
void pf(int n,map<int,int> &m){ 
    if(n%2==0)
        m[2] = 0;
    while (n%2 == 0){
        m[2]++;
        n = n/2; 
    }
    for(int i = 3; i <= sqrt(n); i = i+2) { 
        if(n%i==0)
            m[i] = 0;
        while (n%i == 0){
            m[i]++;
            n = n/i; 
        }
    } 
    if (n > 2) 
        m[n] = 1;
} 
void createMap(map<char, string> &m) { 
    m['0'] = "0000" ; m['1'] = "0001" ; m['2'] = "0010" ; m['3'] = "0011" ; m['4'] = "0100" ; m['5'] = "0101" ; m['6'] = "0110" ; m['7'] = "0111" ; m['8'] = "1000" ; m['9'] = "1001" ; m['A'] = "1010" ; m['B'] = "1011" ; m['C'] = "1100" ; m['D'] = "1101" ; m['E'] = "1110" ; m['F'] = "1111" ; 
} 
map<char,string> m;
vector<string> v(6000);
int n;
bool check(int fa){
    // cout<<"call for "<<fa<<endl;
    string st;
    int i = 0;
    while(i<n){
        st = "";
        trav(c,v[i]){
            st+=m[c];
        }
        int xx = 0;
        char prev = '!';
        // cout<<st<<" --- "<<i<<endl;
        while(xx<st.size()){
            if(xx%fa==0)
                prev = st[xx];
            if(st[xx]!=prev)
                return 0;
            xx++;
        }
        int cnt = 1;
        while(cnt<fa){
            if(v[i+cnt]!=v[i])
                return 0;
            cnt++;
        }
        i+=fa;
    }
    return 1;
}   
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    F0R(i,n) cin>>v[i];
    map<int,int> fac;
    pf(n,fac);
    createMap(m);
    int ans = 1;
    trav(x,fac){
        int best = 1;
        int xa = x.F;
        int ya = x.S;
        int c = 1;
        while(check(pow(xa,c)) && c<=ya){
            best = pow(xa,c);
            c++;
        }
        ans *= best;
    }
    cout<<ans;
    return 0;
}