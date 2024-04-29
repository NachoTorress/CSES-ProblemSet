#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector <int> coins(n);
	for (auto &i:coins) cin>>i;
	map<int, int> mapa, mapAux;
	mapa[0]++; mapAux[0]++;
	mapa[coins[0]]++; mapAux[coins[0]]++;
	for (int i=1;i<n;i++){
		for (auto j:mapa){
			mapAux[j.first+coins[i]]++;
			
		}
		mapa=mapAux;
	}
	int i=1;
	while (true){
		//cout<<"a"<<endl;
		if (mapa[i]==0) {
			cout<<i;
			return 0;
		}
		i++;
	}
}
