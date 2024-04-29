#include <bits/stdc++.h>
using namespace std;
string construir (string str, int n){
	string respuesta="";
	for (int i=str.size()-n;i<str.size();i++){
		respuesta+=str[i];
	}
	return respuesta;
}
int main(){
	
	int n; cin>>n;
	for (int i=0;i<(1<<n);i++){
		bitset<16> bs=i;
		//bs.set(i);
		string str=bs.to_string();
		
		cout<<construir(str,n)<<endl;
		
		//bs.reset();
	}
}
