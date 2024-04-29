#include <bits/stdc++.h>
using namespace std;
vector <int> dp;
void mostrar(vector <int> v) {
	cout<<endl;
	for (auto i:v) cout<<i<<" ";
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	dp.resize(n+1);
	dp[0]=0;
	for (int i=1;i<=n;i++) {
		if (i>6) break;
		dp[i]=1;
	}
	for (int i=0;i<=n;i++){
		for (int j=1;j<=6;j++){
			if (i+j<=n){
				dp[i+j]=(dp[i]+dp[i+j])%1000000007;
				//mostrar(dp);
			}
		}
	}
	//mostrar(dp);
	cout<<dp[n]<<endl;
}

