#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    scanf("%d",&a[0]);
    int max_ = 1;
    int idx = 0;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[idx]*2){
            max_ = max(max_,i-idx);
            while(a[i]>a[idx]*2)
                idx++;
        }
        else{
            max_ = max(max_,i-idx+1);
        }
    }
    printf("%d",max_);
    return 0;
}
