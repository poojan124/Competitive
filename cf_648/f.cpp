#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        map<pair<int,int>, int> mp;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];
        for(int i=0;i<(n+1)/2;i++)
            mp[{min(a[i], a[n-i-1]), max(a[i], a[n-i-1])}]++;
        for(int i=0;i<(n+1)/2;i++){
            pair<int,int> p = {min(b[i], b[n-i-1]), max(b[i], b[n-i-1])};
            if(mp.find(p) != mp.end())
                mp[p]--;
        }
        bool ok = true;
        for(auto x : mp){
            if(x.second != 0){
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    return 0;
}