#include<bits/stdc++.h>
using namespace std;
int rev(int x,int k){
  int rev = 0;
  while(x){
    rev<<=1;
    rev |= x&1;
    x>>=1;
    k--;
  }
  return rev<<k;
}
int compute(bool ar[], int st, int en){
  bool x = ar[st], y = ar[st];
  if(en==st)
    return 0;
  for(int i=st+1;i<=en;i++){
    x = x&ar[i];
    y = y|ar[i];
  }
  if(x==1 || y==0)
    return 0;
  int mid = st+(en-st)/2;
  return 2+compute(ar, st, mid)+compute(ar, mid+1, en);
}
int main(){
  int n;
  cin>>n;
  int x=1<<n;
  bool ar[x];
  assert(rev(x-1,n)==x-1);
  for(int i=0;i<x;i++){
    cin>>ar[rev(i)];
  }
  //cout<<(ar[1]&ar[2]);
  cout<<compute(ar,0,x-1)+1;
  return 0;
}