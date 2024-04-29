#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	char newChar=str[0];
	int contador=1, maxi=0;
	for (int i=1;i<str.size();i++){
		if (str[i]==newChar){
			contador++;
		}
		else {
			newChar=str[i];
			maxi=max(contador, maxi);
			contador=1;
		}
	}
	maxi=max(contador, maxi);
	cout<<maxi;
}

