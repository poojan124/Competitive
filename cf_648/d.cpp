#include <bits/stdc++.h>
using namespace std;
bool visi[51][51];
int n,m,cnt2;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool check(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m){
        return false;
    }
    return true;
}
void dfs(int i, int j, vector<string> &v){
    if(!check(i,j) || visi[i][j] || v[i][j] == '#'){
        return;
    }
    visi[i][j] = true;
    if(v[i][j] == 'G') cnt2++;
    for(int c=0;c<4;c++){
        int nx = i+dx[c];
        int ny = j+dy[c];
        dfs(nx, ny, v);
    }
}
int main(){
	int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> v;
        memset(visi, 0, sizeof(visi));
        for(int i = 0 ; i < n ; i++){
            string tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        bool ok = true;
        int cnt1 = 0 ;
        cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(v[i][j] == 'B'){
                    for(int c=0;c<4;c++){
                        int nx = i+dx[c];
                        int ny = j+dy[c];
                        if(!check(nx, ny))continue;
                        if(v[nx][ny] == 'G'){
                            ok = false;
                        }
                        else if(v[nx][ny] == '.'){
                            v[nx][ny] = '#';
                        }
                    }
                }
                if(v[i][j] == 'G'){
                    cnt1++;
                }
            }
        }
        if(!ok){
            cout << "No" << endl;
            continue;
        }
        dfs(n-1, m-1, v);
        cout << ((cnt1 == cnt2)?"Yes":"No") << endl;
    }
  	return 0;
}