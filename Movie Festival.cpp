#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector <int> v1, v2, v3;
	vector <tuple<int, int, int>> movies;
	for (int i=0;i<n;i++){
		int aux1,aux2; 
		cin>>aux1>>aux2;
		movies.push_back(make_tuple(aux1,1,0)); movies.push_back(make_tuple(aux2,2,aux1));
	}
	sort (movies.begin(), movies.end());
	int aux;
	int contador=1;
	int pos=0;
	for (int i=0;i<movies.size();i++){
		if (get<1>(movies[i])==2){
			aux=get<0>(movies[i]);
			pos=i;
			break;	
			}
	}
	for (int i=pos;i<movies.size();i++){
		if (get<1>(movies[i])==2 && get<2>(movies[i])>=aux){
			aux=get<0>(movies[i]);
			contador++;
		}
	}
	cout<<contador;
}
