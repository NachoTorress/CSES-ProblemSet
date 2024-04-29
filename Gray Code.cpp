#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	for (int i=0;i<1<<n;i++){	
	bitset <16> bs1(i);
	cout<<bs1<<endl;
	}
}
