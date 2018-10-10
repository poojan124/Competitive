#include<bits/stdc++.h>
using namespace std;
int main(){
    //ifstream cin;
    //cin.open("input.txt");
    int q;
    cin>>q;
    while(q--){
        int m;
        cin>>m;
        int a[m+1][m+1];
        long long home[m+1],away[m+1],sum[m+1];
        memset(home,0,sizeof(home));        
        memset(away,0,sizeof(away));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                home[i] += a[i][j];
                away[j] += a[i][j];
            }
        }
        //for(int i=0;i<m;i++)
          //  cout<<home[i]<<" "<<away[i]<<endl;
        int flag = 1;
        for(int i=0;i<m;i++){
            int intflag = 0;
            for(int j=0;j<m;j++){
                if(home[i] == away[j]){
                    intflag = 1;
                    break;
                }
            }
            if(!intflag){
                flag=0;
                break;
            }
        }
        if(flag)
                cout<<"Possible"<<endl;
        else
                cout<<"Impossible"<<endl;
    }
    return 0;
}