#include<bits/stdc++.h>
using namespace std;
#define maxn (int)1e5
int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(12);
	v.push_back(14);
	v.push_back(21);
	v.push_back(71);
	cout<<lower_bound(v.begin(),v.end(),72)-v.begin();
}