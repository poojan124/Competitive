#include<bits/stdc++.h>
using namespace std;

long long int compute(bool ar[], long long int st, long long int en){
  bool x = ar[st], y = ar[st];
  if(en==st)
    return 0;
  for(long long int i=st+1;i<=en;i++){
    x = x&ar[i];
    y = y^ar[i];
  }
  if(x==1 || y ==0)
    return 0;
  long long int mid = st+(en-st)/2;
  //cout<<mid<<endl;
  return 2+compute(ar, st, mid)+compute(ar, mid+1, en);
}
int main(){
  long long int n;
  cin>>n;
  long long int x = 1<<n;
  bool ar[x+1];
  for(long long int i=1;i<=x;i++)
    cin>>ar[i];
  //cout<<(ar[1]&ar[2]);
  reverse(ar+1,ar+n);
  cout<<compute(ar,1,x)+1;
  return 0;
}