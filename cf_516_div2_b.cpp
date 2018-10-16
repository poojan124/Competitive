#include<bits/stdc++.h>
using namespace std;
int cntr;
void count1(unsigned n){
    if(n!=0){
        if(n%2)
            cntr++;
        count1(n>>1);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cntr = 0;
        count1(n);
        cout<<long(pow(2,cntr))<<endl;
    }
}