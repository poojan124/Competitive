#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
       int n;
       cin>>n;
       n--;
       int ans;
       cin>>ans;
       while(n--){
            int s;
            cin>>s;
            ans=ans^s;
       }
       if(ans==0)
        cout<<"Second"<<endl;
       else
        cout<<"First"<<endl;
    }
    return 0;
}
