#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> b(n), ans(n);
    for(int i=0;i<n;i++)
        cin >> b[i];
    ans[0] = b[0];
    ans[1] = b[1] + ans[0];
    int max_ = max(ans[0], ans[1]);
    for(int i=2;i<n;i++){
        ans[i] = b[i] + max_;
        max_ = max(max_, ans[i]);
    }
    for(auto i : ans)
        cout << i << " ";
  	return 0;
}