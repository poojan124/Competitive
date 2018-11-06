#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long x,y;
    cin>>x>>y;
    long long a1 = (min(x,y)-1) + (max(x,y)-min(x,y));
    long long a2 = (n-max(x,y))+ (max(x,y)-min(x,y));
    // cout<<a1<<" "<<a2<<endl;
    cout<<(a1<=a2?"White":"Black")<<endl; 
}