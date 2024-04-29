#include <bits/stdc++.h>
using namespace std; 
int main(){
	int n; cin>>n;
	vector <int> nums (n);
	for (auto &i:nums) cin>>i;
	set <int> numeros;
	int maxTam=0;
	int var=0;
	for (int i=0;i<n;i++){
		int aux=nums[i];	
		if (numeros.count(aux)) {
			while (numeros.count(aux)){
				numeros.erase(nums[var]);
				var++;
			}
		}
		numeros.insert(aux);
		int tam=numeros.size(); 
		maxTam=max(maxTam,tam);
	}

	cout<<maxTam;
}
