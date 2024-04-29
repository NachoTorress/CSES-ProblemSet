#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long m;
vector <vector<long long>>matriz;
long long getVal(vector <vector<long long>> &matriz, long long& x, long long &y){
	long long total=0;
	if (x-1>0) total+=matriz[x-1][y-1];
	total+=matriz[x][y-1];
	if (x+1<=m) total +=matriz[x+1][y-1];
	return total%MOD;
}
void mostrarMatriz(vector <vector<long long>> &matriz){
	for (long long i=0;i<matriz.size();i++){
		for (long long j=0;j<matriz[i].size();j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	long long n; cin>>n>>m;
	vector <long long> nums (n);
	matriz.resize(m+1, vector<long long>(n,0));
	for (auto &i:nums) cin>>i;
	if (nums[0]==0){
		for (long long j=0;j<=m;j++){
			matriz[j][0]=1;
		}
	
	}
	else {
		matriz[nums[0]][0]=1;
	}
	for (long long i=1;i<n;i++){
		if (nums[i]!=0) matriz[nums[i]][i]=getVal(matriz, nums[i],i);
		else {
			for (long long j=0;j<=m;j++){
				matriz[j][i]=getVal(matriz,j,i);
			}
		}
	}
	//mostrarMatriz(matriz);
	long long solucion=0;
	for (long long i=1;i<=m;i++){
		solucion=(solucion+matriz[i][n-1])%MOD;
	}
	cout<<solucion;
}
	
	

