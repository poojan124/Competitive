#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    map<int, int> cnt, idx;
    for(int i=0;i<n;i++){
        idx[b[i]] = i;
    }
    for(int i=0;i<n;i++){
        int j = idx[a[i]];
        if(j<i) j+= n;
        cnt[i-j]++;
    }
    int ans = 0;
    for(auto x : cnt){
        ans = max(x.second, ans);
    }
    cout << ans;
    return 0;
}