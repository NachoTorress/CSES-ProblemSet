#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector <int> apples (n);
	for (auto &i:apples) cin>>i;
	long long mini=(1<<31)-1;
	long long suma1=0, suma2=0;
	for (int mask=(1<<n)-1;mask>=0; mask--){
		for (int j=0;j<n;j++){
			if (1<<j & mask) suma1+=apples[j];
			else suma2+=apples[j];	
		}
		mini=min(mini, abs(suma1-suma2));
		suma1=0, suma2=0;
	}
	cout<<mini;
}
