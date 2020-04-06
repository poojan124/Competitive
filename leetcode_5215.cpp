#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum = 0, ans=0;
    bool visi[16][16];
    void dfs(vector<vector<int> > v, int i, int j, char par){
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size())
            return;
        if(v[i][j] == 0 || visi[i][j])
            return;
        sum += v[i][j];
        visi[i][j] = 1;
        ans = max(ans, sum);
        if(par != 'd')
            dfs(v, i-1, j, 'u'); //u
        if(par != 'l')
            dfs(v, i, j+1, 'r'); //r
        if(par != 'u')
            dfs(v, i+1, j, 'd'); //d
        if(par != 'r')
            dfs(v, i, j-1, 'l'); //l
        sum -= v[i][j];
        visi[i][j] = 0;
        return;
    }
    int getMaximumGold(vector<vector<int>>& v) {
        bool leaf[16][16];
        int N = v.size(), M = v[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int C[] = {0,0,0,0};
                if(i>0 && v[i-1][j]!=0) C[0]++;//u
                if(i+1<N && v[i+1][j]!=0) C[1]++;//d
                if(j>0 && v[i][j-1]!=0) C[2]++; //l
                if(j+1<M && v[i][j+1]!=0)C[3]++; //r
                int CNT = C[0] + C[1] + C[2] + C[3];
                if((((C[0] == 1 && C[3]==1) || (C[0] == 1 && C[2]==1) ||(C[1] == 1 && C[3]==1) || (C[1] == 1 && C[2]==1) ) && (CNT == 2) ) || (CNT == 1))
                    leaf[i][j] = 1;
                else
                    leaf[i][j] = 0;
            }
        }

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout << i << " " << j << " " << leaf[i][j] << endl;
                if(!leaf[i][j])
                    continue;
                sum = 0;
                for(int X=0;X<16;X++)
                    for(int Y=0;Y<16;Y++)
                        visi[X][Y] = 0;
                dfs(v, i, j, '@');
            }
        }
        return ans;
    }
};

int main(){
    //vector<vector<int > > v = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    //vector<vector<int> > v = {{3,31,23,3,15,20,12},{0,8,11,25,0,31,20},{39,30,16,11,2,29,34},{13,38,35,3,0,14,9}};
    vector<vector<int> > v = {{1,1},{1,1}};
    Solution sol = Solution();
    cout << sol.getMaximumGold(v);
}
