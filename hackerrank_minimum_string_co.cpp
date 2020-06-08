#include<bits/stdc++.h>

using namespace std;

vector<int> count(string s){
    vector<int> v;
    int cnt = 0;
    char prev = s[0];
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != prev){
            v.push_back(cnt);
            cnt = 0;
        }
        cnt++;
        prev = s[i];
    }
    v.push_back(cnt);
    return v;
}

int main(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    auto v = count(s);
    int k = v.size() - (2*p + 1) - 1;
    if(k <= 0){
        cout << 0;
    }
    else{
        int sum = 0;
        for(int i = 1; i <= k; i++) sum+=v[i];
        int ans = sum;
        for(int i = k+1; i < v.size() - 1; i++){
            sum -= v[i-k];
            sum += v[i];
            ans = min(ans, sum);
        }       
        cout << ans;
    }
    return 0;
}