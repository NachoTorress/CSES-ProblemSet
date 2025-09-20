#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	ll total=0, respuesta=0;
	vector <ll> op (n);
	op[0]++;
	for (int i=0;i<n;i++){
		total+=nums[i];
		ll resto = (total % n + n) % n;
		respuesta+=op[resto];
		op[resto]++;
		//cout<<"total actual: "<<total<<" sumando: "<<op.count(n-total%n)<<endl;
	}
	cout<<respuesta;
}
