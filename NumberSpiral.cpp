#include <bits/stdc++.h>
using namespace std;
int main(){
	int q, n, m;
	cin>>q;
	int matriz [5][5]= {1, 2, 9, 10, 25,4, 3,8,11,24,5,6,7,12,23,16,15,14,13,22,17,18,19,20,21};
	while (q--){
		cin>>n>>m;
		cout<<matriz[n-1][m-1]<<"\n";
	}
}
