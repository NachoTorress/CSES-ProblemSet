#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
	long long n; cin>>n; int total=1;
	for (int i=0;i<n;i++){
		total=(total*2)%MOD;
	}
	cout<<total;
}
