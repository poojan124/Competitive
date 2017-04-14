#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=10;i++){
        int temp=i*n;
        if(temp%10==m || temp%10==0){
            cout<<i<<endl;
            break;
        }
    }
}
