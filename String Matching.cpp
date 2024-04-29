#include <bits/stdc++.h>
using namespace std;
int main(){
	string str, p; cin>>str>>p;
	string s=p+"#"+str;
	vector <int> b (s.size(),0);
	int j=0;
	for (int i=1;i<s.size();i++){
		while (s[i]!=s[j] && j){
			j=b[j-1];
			
		}
		if (s[i]==s[j]) j++;
		b[i]=j;
	}
	int cont=0;
	for (auto i:b) if (i==p.size()) cont++;
	cout<<cont;
}
