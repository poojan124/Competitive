#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v(100000+5);
int cnt2 = 0 ;

bool odd = false;

pair<bool, bool> dfs(int s, int par){
    pair<bool, bool> p = {false, false};
    for(auto x : v[s]){
        if(x == par) continue;
        auto child = dfs(x, s);
        if(!child.first && !child.second){
            child.first = true;
        }
        p.first |= child.first;
        p.second |= child.second;
        
    }
    if(p.first && p.second)
        odd = true;
    return {p.second, p.first};
}

int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
    int n, x, y;
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s = 0;
    for(int i=0;i<n-1;i++){
        if(v[i].size() > 1){
            s = i;
            break;
        }
    }
    auto dump = dfs(s, -1);
    cout << (odd ?  "3 ":"1 ");
    int a[n+1] = {0};
    for(int i = 1; i <= n; i++)
        a[v[i][0]] += (v[i].size() == 1);
    int ans = n-1;
    for(int i = 1; i <= n; i++){
        if(a[i] > 1)
            ans -= (a[i] - 1);
    }
    cout << ans << endl;
    return 0;
}