#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[] = {1,3,4,5,7};
	int idx = lower_bound(a+2,a+5,8) -(a);
	cout<<idx<<endl;
}