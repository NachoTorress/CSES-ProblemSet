#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, k; cin>>n>>m>>k;
	vector <int>  appl (n); vector <int> deps(m);
	for (auto &i: appl) cin>>i;
	for (auto &i:deps) cin>>i;
	sort (deps.rbegin(), deps.rend());
	sort (appl.rbegin(), appl.rend());
	int i=0, j=i, contador=0;
	bool termino=false;
	while (!termino){
		if (abs(deps[j]-appl[i])<=k){
			contador++;
			i++;
			j++;
		}
		else {
			if (deps[j]>appl[i]) j++;
			else i++;
		}
		if (j==m || i==n) termino=true;
	}
	cout<<contador;
}
	
	


