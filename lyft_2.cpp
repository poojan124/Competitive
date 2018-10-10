#include<bits/stdc++.h>
using namespace std;
bool check(long long x){
    for(long long i=2;i*i<=x;i++)
        if(!x%i)
            return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        // assert(check(11000007643));
        if(x-y > 1)
            cout<<"NO"<<endl;
        else{
            if(check(x+y))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}