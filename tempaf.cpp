#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for(auto c:s)
            v.push_back(c-48);
        int sm = 0;
        int len = (n%2)?((n+1)/2):n/2;
        for(int i=0;i<len;i++) sm += v[i];
        int ans = sm;
        for(int i=len; i<n; i++){
            sm = sm + v[i] - v[i-len];
            ans = max(ans, sm);
        }
        cout << "Case #"<<t<<": "<<ans << endl;
    }
}
