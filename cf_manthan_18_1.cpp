#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long i=1;
    while(1){
        if((i*(i+1))/2 >= n){
            cout<<i<<endl;
            break;
        }
        i++;
    }
    //cout<<i+1<<endl;
    return 0;
}
