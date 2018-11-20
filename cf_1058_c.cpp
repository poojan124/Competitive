#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(s[i]-'0');
    int sum = 0;
    bool ans = false;
    for(int i=0;i<n-1;i++){
        sum = 0;
        for(int c=0;c<=i;c++)
            sum += v[c];
        int tsum = 0;
        ans = true;
        int f = 0;
        for(int j=i+1;j<n;j++){
            tsum += v[j];
            f=0;
            if(tsum==sum){
                while(tsum==sum && j+1<n){
                    j++;                    
                    tsum += v[j];
                }
                if(tsum!=sum)
                    j--;
                tsum=0;
                f = 1;
            }
            if(tsum>sum){
                ans = false;
                break;
            }
        }
        if(!f)
            ans = false;
        if(ans)
            break;
    }
    cout<<(ans?"YES":"NO")<<endl;
}