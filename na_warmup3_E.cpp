#include<bits/stdc++.h>
using namespace std;
inline bool ispali(int x){
    int a[6];
    int i=5;
    while(x>0){
        a[i] = x%10;
        i--;
        x/=10;
    }
    assert(i==-1);
    return a[0]==a[5] && a[1]==a[4] && a[2]==a[3];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    assert(ispali(123321));
    v.push_back(0);
    for(int i=100001;i<=999999;i++){
        if(ispali(i))
            v.push_back(i);
    }
    while(n--){
        int x;
        cin>>x;
        int idx = lower_bound(v.begin(),v.end(),x) - v.begin();
        cout<< ((x-v[idx-1]<v[idx]-x )? v[idx-1]:v[idx] )<<endl;
    }
}