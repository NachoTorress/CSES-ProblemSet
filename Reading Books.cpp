#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	ll sum=0, maxi=-1;
	for (int i=0;i<n;i++){
		ll lib; cin>>lib; 
		sum+=lib;
		maxi=max(maxi,lib);
	}
	cout<<max(sum, maxi*2);
}
