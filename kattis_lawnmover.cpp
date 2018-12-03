#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<long long int,long long int> &a,
              const pair<long long int,long long int> &b)
{
    return (a.second < b.second);
}


int main(){
  long long int l,m;
  cin>>l>>m;
  string str,substr;
  getline(cin,str);
  long long int ar[m][4];
  vector<pair<long long int,long long int>> vect;
  string names[m];

  for(long long int i=0;i<m;i++){
    getline(cin,str);
    stringstream ss( str );
    long long int j = -1;
    while( ss.good() )
    {
      string substr;
      getline( ss, substr, ',' );
      if(j>=0) ar[i][j] = stoi(substr);
      else names[i] = substr;
      j++;
    }
  }
  for(long long int i=0;i<m;i++){
  	long long int temp = 10080;
  	double ans = 0;
	ans = 1.0*ar[i][1]*ar[i][2]*(10080/(float)(ar[i][2]+ar[i][3]));
  	if((ans) >= l )
  		vect.push_back(make_pair(i,ar[i][0]));
  }
  if(vect.empty())
  	cout<<"no such mower";
  else{
    sort(vect.begin(), vect.end(), sortbysec);
    //edited part ---
    vector<int> vvv;
    vvv.push_back(vect[0].first);
    //-------
    long long int j =0;
	while( ((j+1)<vect.size()) && (vect[j].second == vect[j+1].second) ){
	    vvv.push_back(vect[j+1].first);
	      j++;
	}
    // this you have to do. Print movers based on their index for same cost.
	sort(vvv.begin(),vvv.end());
	for(auto xx:vvv)
		cout<<names[xx]<<endl;
  }
  return 0;
}