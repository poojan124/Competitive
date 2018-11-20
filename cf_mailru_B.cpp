#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,l;
    cin>>n>>m>>l;
    int a[n];
    int c[n];
    int ans = 0;
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>l)
            c[i] = 1;
    }
    int f = 0;
    for(int i=0;i<n;i++){
        if(c[i] && !f){
            ans++;
            f=1;
        }
        if(!c[i])
            f = 0 ;
    }
    // cout<<"ans "<<ans<<endl;
    for(int i=0;i<m;i++){
        int q;
        cin>>q;
        if(q==1){
            int x,y;
            cin>>x>>y;
            x--;
            a[x]+=y;
            // assert(x<n);
            cout<<a[x]<<endl;
            if(a[x]>l && !c[x]){
                // cout<<"???"<<endl;
                c[x] = 1;
                if(x==0 && x+1<n){
                    // cout<<"case1"<<endl;
                    if(c[x+1]!=1)
                        ans++;
                }
                else if(x == n-1){
                    // cout<<"case1.5"<<endl;
                    if(c[x-1]!=1)
                        ans++;
                }
                else{
                    // cout<<"case2"<<c[x-1]<<" "<<c[x+1]<<endl;
                    if(c[x-1] && c[x+1])
                        ans--;
                    if(!c[x-1] && !c[x+1])
                        ans++;
                }
            }
        }
        if(q==0)
            cout<<ans<<endl;
    }
    return 0;
}