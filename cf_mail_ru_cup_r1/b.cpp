#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = -1;
    int x;
    cin>>x;
    if(x!=0)
        ans = 1;
    int must = 1;
    for(int i=2;i<=n;i++){
        cin>>x;
        if(ans!=-1)
            continue;
        if(x == must){
            must++;
            continue;
        }
        if(x > must)
            ans = i;
    }
    cout<<ans<<endl;
}