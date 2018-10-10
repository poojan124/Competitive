#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+5];
    int b[n+5];
    int c[n+4];
    // memset
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]] = i;
    }
    c[n] = 0;
    // assert(false);
    for(int i=n-1;i>=1;i--){
        int index = b[i];
        int flag = 0;
        // cout<<i<<" asdfasdf "<<endl;
        while(index+i <= n){
            index += i;
            if(a[index]>i){
                if(c[a[index]] == 0)
                    flag |= 1;
                if(c[a[index]] == 1)
                    flag |= 2;
            }
        }
        while(index-i>=1){
             index -= i;
            if(a[index]>i){
                if(c[a[index]] == 0)
                    flag |= 1;
                if(c[a[index]] == 1)
                    flag |= 2;
            }
        }
        
        if(flag == 0 || flag == 2)
            c[i] = 0;
        if(flag == 1 or flag == 3)
            c[i] = 1;
        // cout<<c[i]<<" for i = "<<i<<endl;
    }
    for(int i=1;i<=n;i++)
        if(c[a[i]])
            cout<<"A";
        else
            cout<<"B";
    return 0;
}