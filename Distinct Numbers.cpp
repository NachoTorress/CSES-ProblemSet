#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	set <int> contador;
	for (int i=0;i<n;i++){
		int aux;
		cin>>aux;
		contador.insert(aux);
	}
	cout<<contador.size();
}
