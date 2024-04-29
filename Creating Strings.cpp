#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	sort (s.begin(), s.end());
	vector <string> array;
	array.push_back(s);
	next_permutation(s.begin(), s.end());
	while (s!=array[0]){
		array.push_back(s);
		next_permutation(s.begin(), s.end());
	}
	cout<<array.size()<<endl;
	for (auto i:array) cout<<i<<endl;
}
