#include <bits/stdc++.h>
using namespace std;
vector <vector <bool>> visited;
vector <string> rooms;
int n,m;
void mostrarV(){
	for (int i=0;i<visited.size();i++){
		for (int j=0;j<visited[0].size();j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-----------------------------------"<<endl;
}
void dfs(int i, int j){
	if (visited[i][j]) return;
	if (rooms[i][j]=='#') return;
	visited[i][j]=true;
	if (i-1>=0) dfs(i-1,j);
	if (i+1<n) dfs(i+1,j);
	if (j-1>=0) dfs(i,j-1);
	if (j+1<m) dfs(i,j+1);
}
int main(){
	 cin>>n>>m;
	 int contador=0;
	rooms.resize(n);
	visited.resize(n,vector <bool>(m,false));
	for (auto &i:rooms) cin>>i;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (!visited[i][j] && rooms[i][j]!='#'){
				dfs(i,j);
				contador++;
			}
			//	mostrarV();
		}
	
	}
	cout<<contador<<endl;
}
