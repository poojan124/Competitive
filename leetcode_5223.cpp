#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // map to bottom left 0,0
        // king[0] = 8-king[0];
        // for(auto q:queens)
        //     q[0] = 8-q[0];
        // int cn
//         int i,j;
//         vector<vector<int> > ans;
//         vector<int> tmp;

//         //checking king to up
//         tmp = {-1,-1};
//         for(auto q:queens){
//             if(q[1] == king[1] && q[1] > tmp[1])
//                 tmp = q;
//         }
//         if(tmp[0]!=-1)
//             ans.push_back(temp);
//         //king to down
//         tmp = {9,9}
//         for(auto q:queens){
//             if(q[1] == king[1] && q[1] < tmp[1])
//                 tmp = q;
//         }
//         if(tmp[0]!=9)
//             ans.push_back(temp);
//         // king to right
//         tmp = {9,9};
//         for(auto q:queens){
//             if(q[0] == king[1] && q[1] < tmp[1])
//                 tmp = q;
//         }
//         if(tmp[0]!=9)
//             ans.push_back(temp);
//         // king to left
//         tmp = {-1,-1};
//         for(auto q:queens){
//             if(q[0] == king[0] && q[1] > tmp[1])
//                 tmp = q;
//         }
//         if(tmp[0]!=-1)
//             ans.push_back(temp);
        int i,j;
        map<vector<int>, bool> m;
        for(auto q:queens){
            m[q] = true;
        }
        vector<vector<int> > ans;
        //right
        for(i=king[1];i<=8;i++){
            vector<int> v{king[0], i};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //left
        for(i=king[1];i>=0;i--){
            vector<int> v{king[0], i};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //top
        for(i=king[0];i>=0;i--){
            vector<int> v{i, king[1]};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //down
        for(i=king[0];i<=8;i++){
            vector<int> v{i, king[1]};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //top left
        i = king[0];
        j = king[1];
        for(;;){
            i--;j--;
            if(i<0 || j<0 || i>8 || j>8)
                break;
            vector<int> v{i,j};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //top  right
        i = king[0];
        j = king[1];
        for(;;){
            i--;j++;
            if(i<0 || j<0 || i>8 || j>8)
                break;
            vector<int> v{i,j};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //bottom right
        i = king[0];
        j = king[1];
        for(;;){
            i++;j++;
            if(i<0 || j<0 || i>8 || j>8)
                break;
            vector<int> v{i,j};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        //bottom left
        i = king[0];
        j = king[1];
        for(;;){
            i++;j--;
            if(i<0 || j<0 || i>8 || j>8)
                break;
            vector<int> v{i,j};
            if(m[v]){
                ans.push_back(v);
                break;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int> > queens = {{0,0}};
    vector<int> king = {3,3};
    Solution sol = Solution();
    auto ans = sol.queensAttacktheKing(queens, king);
    for(auto i:ans){
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}

