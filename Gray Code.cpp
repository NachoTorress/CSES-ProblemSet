#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
int main(){
	int n; cin>>n;
	int k=(1<<n);
	vector <string> grey(k);
	for (int i=1;i<=n;i++){
		int aux=1<<i;
		string orden;
		for (int i=0;i<aux;i++) 
			if (i<aux/2) orden+='0';
			else orden+='1';
		reverse (orden.begin(), orden.end());
		for (int j=0;j<k;j++){
			if (j%aux==0) reverse(orden.begin(), orden.end());
			grey[j]+=orden[j%aux];	 
		}
	}
	for (auto &i:grey) reverse (i.begin(), i.end());
	for (auto i:grey) cout<<i<<"\n";
	
}
