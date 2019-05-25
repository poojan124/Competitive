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

int lps(string s) {
    vector<int> p(s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (j > 0 && s[j] != s[i])
            j = p[j-1];

        if (s[j] == s[i])
            j++;
        p[i] = j;
    }   
    return p[(int)s.size()-1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int a1[]= {0,0}, a2[]={0,0}, a3[]={0,0};
    trav(c,s1) a1[c-48]++;
    trav(c,s2) a2[c-48]++;
    int L = lps(s2);
    string s3 = "";
    if(L>0){
        s3 = s2.substr(L,(int)s2.size() -  L);
        trav(c,s3) a3[c-48]++;
    }
    if(a1[0] >= a2[0] && a1[1] >= a2[1]){
        bool FIRST = true;
        while(1){
            if(L == 0 && (a1[0]< a2[0] || a1[1] < a2[1]))
                break;
            else if(a1[0]< a3[0] || a1[1] < a3[1])
                break;
            
            if(FIRST || L == 0){
                cout << s2;
                a1[0]-=a2[0];
                a1[1]-=a2[1];
                FIRST = false;
            }
            else{
                cout << s3;
                a1[0]-=a3[0];
                a1[1]-=a3[1];
            }
        }
        while(a1[0]--) cout << 0;
        while(a1[1]--) cout << 1;
    }
    else
        cout << s1;
    return 0;
}
