#include <bits/stdc++.h>
using namespace std;
void mostrarV(vector <long long> v){
	cout<<v.size()<<endl;
	for (auto i:v) cout<<i<<" ";
	cout<<endl;
}
int main(){
	long long n; cin>>n;
	if ((n*(n+1)/2)%2){
		cout<<"NO";
		return 0;
	}
	long long mitad=(n*(n+1)/2)/2;
	long long total1=mitad, total2=mitad;
	vector<long long> array1, array2;
	for (int i=n;i>0;i--){
		if (total1>=i){
			total1-=i;
			array1.push_back(i);
		}
		else {
			total2-=i;
			array2.push_back(i);
		}
	}
	cout<<"YES"<<endl;
	mostrarV(array1);
	mostrarV(array2);
	
	
}
