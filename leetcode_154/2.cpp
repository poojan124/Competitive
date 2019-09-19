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
class Solution {
public:
    string rev(string s, int a, int b){
        string s1 = "";
        //cout << s << a << b << endl;
        //assert(b-a>2);
        for(int i=(int)s.size()-1; i>=0; i--){
            if(s[i] == '(') s1 += ')';
            else if(s[i] == ')') s1 += '(';
            else s1 += s[i];
        }
        return s1;
    }
    string reverseParentheses(string s) {
        int n = s.length();
        int i = 0;
        int tmp = 0;
        while(i < n && s[i] != '(')i++;
        int j = i;
        while(j<n){
            j++;
            if(s[j] == '(')tmp++;
            if(s[j] == ')')
                if(tmp==0)break;
                else tmp--;
        }
        while(i<n){
            s = s.substr(0,i) + rev(s.substr(i,j-i+1),i,j) + s.substr(j+1);
            i++;
            tmp = 0;
            while(i < n && s[i] != '(')i++;
            j = i;
            while(j<n){
                j++;
                if(s[j] == '(')tmp++;
                if(s[j] == ')')
                    if(tmp==0)break;
                    else tmp--;
            }
            //cout << s << endl;
        }
        string s1 = "";
        trav(x, s){
            if(x != '(' && x != ')') s1 += x;
        }
        return s1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s = Solution();
    cout << s.reverseParentheses("(u()(love)i)");
    return 0;
}
