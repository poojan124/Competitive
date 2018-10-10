#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1){
        cout<<abs(k-a[0])<<endl;
        return 0;
    }
    sort(a,a+n);
    long long i = (n-1)/2;
    if(a[i]==k)
        cout<<0<<endl;
    else if(a[i]>k){
        long long j=i;
        long long s1=0;
        while(j>=0 && a[j]>k){
            s1 += (a[j]-k);
            j--;
        }
        cout<<s1<<endl;
    }
    else{
        long long j=i;
        long long s1=0;
        while(j<n && a[j]<k){
            s1 += abs(a[j]-k);
            j++;
        }
        cout<<s1<<endl;
    }
    return 0;
}
