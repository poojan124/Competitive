#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<int> *v;
    vector<int> x;
    x.push_back(10);
    if(x.size() > (*v).size())
        v = &x;
    for(auto i:(*v))
        cout << i << endl;
    for(auto i:(*v))
        cout << i << endl;
}
