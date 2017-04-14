#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<char> v1(s1.begin(),s1.end());
    vector<char> v2(s2.begin(),s2.end());
    int k,cnt=0;
    cin>>k;
    if(k>=(v1.size()+v2.size())){
        printf("Yes\n");
        return 0;
    }
    int min_=min(v1.size(),v2.size());
    for(int i=0;i<min_;i++){
        if(v1[i]==v2[i])
            cnt++;
        else
            break;
    }
    int dod=v1.size()+v2.size()-2*cnt;
    if(dod<=k){
        if(dod%2==1 && k%2==0)
            printf("No\n");
        else if(dod%2==0 && k%2==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    else
        printf("No\n");
    return 0;
}
