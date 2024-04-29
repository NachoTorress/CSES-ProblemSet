#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	string solucion="", solucionAux;
	//multiset <char> chars;
	map<char, int> chars;
	for (int i=0;i<s.size();i++){
		chars[s[i]]++;
	}
	long long impares=0;
	char impar=0;
	int cantImpar=0;
	for (auto i:chars){
	 if (i.second%2) {
		impares++;
		impar=i.first;
		cantImpar=i.second;
	}
}
	if (impares>1) {
		cout<<"NO SOLUTION";
		return 0;
	}
	for (auto i:chars){
			if (i.first!=impar){
				for (auto j=0;j<i.second/2;j++){
					solucionAux+=i.first;
				}
			}
		}
		//cout<<solucionAux<<"SOL"<<endl;
		solucion=solucionAux;
		reverse(solucionAux.begin(), solucionAux.end());
		for (long long i=0;i<cantImpar;i++){
			solucion+=impar;
		}
		solucion+=solucionAux;
		cout<<solucion;
	}


