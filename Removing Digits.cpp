#include <bits/stdc++.h>
using namespace std;
bool comp
int main(){
	int n;
	cin>>n;
	vector <int> dp;
	dp.push_back(n);
	string str=to_string(n);
	int num=n;
	while (num>0){
	str=to_string(num);
	int maxNum=str[0]-'0';
	for (int i=0;i<str.size();i++){
		maxNum=max(maxNum, str[i]-'0');
	}
	num-=maxNum;
	dp.push_back(num);
	//cout<<"digito "<<maxNum<<endl;
	//cout<<num<<endl;
}
cout<<dp.size()-1;
}
