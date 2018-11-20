#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    m--;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    if(!a[0]){
        cout<<'NO';
        return 0;
    }
    if(!a[m] && !b[m]){
        cout<<"NO";
        return 0;
    }
    if(a[m]){
        cout<<"YES";
        return 0;
    }
    else{
        for(int i=m+1;i<n;i++){
            if(a[i]&b[i]){
                cout<<"YES"<<endl;
            }
        }
    }
}