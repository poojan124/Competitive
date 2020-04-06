#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    vector<int> v;
    long long sum = 0;
    for(int i = 0 ; i < n; i++)
        if(a[i] > n - k){
            v.push_back(i);
            sum += a[i];
        }
    
    long long ans = 1;
    int prev = v[0];
    for(int i = 1 ; i < v.size(); i++){
        ans *= (long long)(v[i] - prev);
        ans %= 998244353;
        prev = v[i];
    }
    cout << sum << " "  << ans << endl;
    return 0;
}