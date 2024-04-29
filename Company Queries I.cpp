#include <bits/stdc++.h>
using namespace std;
int up [200002][20];
int main(){
	int n,q;
	cin>>n>>q;
	for (int i=2;i<=n;i++){
		int jef; cin>>jef;
		up[i][0]=jef;
	}
	for (int i=1;i<20;i++){
		for (int j=1;j<=n;j++){
			up[j][i]=up[up[j][i-1]][i-1];
		}
	}
	while (q--){
		int a, k; cin>>a>>k;
		for (int i=0;i<20;i++){
			if (k & (1<<i)){
				a=up[a][i];
			}
		}
		if (a==0) a=-1;
		cout<<a<<endl;
	}
}
