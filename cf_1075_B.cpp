#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+m],b[n+m];
    vector<int> v;
    for(int i=0;i<n+m;i++){
        cin>>a[i];
    }
    v.push_back(0);
    for(int i=0;i<n+m;i++){
        cin>>b[i];
        if(b[i])
            v.push_back(i);
    }
    v.push_back(n+m);
    cout<<"asdf "<<v.size()<<endl;
    cout<<v[1]<<endl;
    for(int i=1;i<=v.size()-2;i++){
        if(i==0)
            cout<<v[i]- v[i-1] + int((v[i+1]-v[i]-1+1)/2)<<" ";
        else
            cout<<int((v[i]- v[i-1]-1)/2) + int((v[i+1]-v[i]-1+1)/2)<<" ";

    }
}