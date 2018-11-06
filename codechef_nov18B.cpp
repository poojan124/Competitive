#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+5];
        int ans[n+5];
        memset(ans,0,sizeof(ans));
        bool flagger = 0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            if(ans[a[a[i]]] == 0)
                ans[a[a[i]]] = a[i];
            else if(ans[a[a[i]]] != a[i]){
                flagger = 1;
                break;
            }
        }
        if(flagger)
            cout<<"Truly Happy"<<endl;
        else
            cout<<"Poor Chef"<<endl;
    }
    return 0;
}