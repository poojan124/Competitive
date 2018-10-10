#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=0;i<n;i++){
        if(i!=n){
            if(a[i]!=b[i]){
                if(a[i+1]!=b[i+1]){
                    if(a[i]==b[i+1] && a[i+1] == b[i]){
                        ans+=1;
                        a[i]=b[i];
                        a[i+1]=b[i+1];
                    }
                    else
                        ans+=1;
                }
                else
                    ans+=1;
            }
        }
        else{
            if(a[i]!=b[i])
                ans++;
        }
    }
    cout<<ans<<endl;
}
