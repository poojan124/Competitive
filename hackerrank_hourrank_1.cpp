#include<bits/stdc++.h>
using namespace std;
int rev(int s){
    int sum=0;
    while(s>0){
        sum=sum*10+s%10;
        s/=10;
    }
    return sum;
}
int main()
{
    int a1,b1,k;
    cin>>a1>>b1>>k;

    int ans=0;
    for(int i=a1;i<=b1;i++){
        int t=rev(i);
        //cout<<t<<endl;
        if(abs(t-i)%k==0)
            ans++;
    }
    cout<<ans;
}
