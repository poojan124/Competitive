#include<bits/stdc++.h>
using namespace std;
int comp(int a,int b){
    return a>b?1:0;
}
int main(){
    int n;
    scanf("%d",&n);
    set<int> a;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        a.insert(t);
    }
    vector<int> v(a.begin(),a.end());
    sort(v.begin(),v.end(),comp);
    int m;
    scanf("%d",&m);
    int b[m+1];
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int size = v.size();
    int i = size;
    int j = 0;
    while(i>=0 && j<m){
        if(v[i-1] > b[j]){
            printf("%d\n",i+1);
            j++;
            i++;
        }
        else if(v[i-1] == b[j]){
            printf("%d\n",i);
            j++;
            i++;
        }
        i--;
    }
    while(j<m){
        printf("1\n");
        j++;
    }
    return 0;
}