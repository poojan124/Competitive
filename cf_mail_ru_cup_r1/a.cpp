#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    long long c1 = 0,c2 = 0;
    c1 = abs(x-y)*t1;
    c2 = 3*t3 + t2*(abs(x-y)+abs(x-z));
    if(c2<=c1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;    
}