#include <bits/stdc++.h>
using namespace std;
void mostrarM(vector <vector <int>> m){
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[i].size();j++)cout<<m[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	int n, x;
	cin>>n>>x;
	vector <pair <int, int>> libros (n);
	for (auto &i:libros) cin>>i.first;
	for (auto &i:libros) cin>>i.second;
	vector <vector <int>> dp(n, vector <int> (x+1, 0));
	for (int i=libros[0].first;i<=x;i++){
		dp[0][i]=libros[0].second;
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<=x;j++){
			int pagsActual=0, precio=libros[i].first;
			if (j>=precio) pagsActual=libros[i].second; if (j-precio>0) pagsActual+=dp[i-1][j-precio];
			int anterior=0;
			if (j-1>=0)int anterior=dp[i][j-1];
			if (j-precio>0) anterior+=dp[i-1][j-precio];
			int arriba=dp[i-1][j];
			//if (j-libros[i].first>0 && i-2>0) //arriba+=dp[i-2][j-libros[i].first];
			int maxi=max(arriba, anterior);
			dp[i][j]=max(maxi, pagsActual);
			
			  
		}
	}
	//mostrarM(dp);
	cout<<dp[n-1][x];
}
