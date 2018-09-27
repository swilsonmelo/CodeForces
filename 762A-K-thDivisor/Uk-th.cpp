#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	long k;
	cin >> n;
	cin >> k;
	long long i, md = -1, cont = 0;
	for( i = 1; i*i <= n; i++ ){
		if(n % i == 0) cont++;
		if(cont == k){
			md = i;
			break;
		} 
	}
	//printf("%d",i);
	if(md == -1){
		i--;
    	if (i*i==n)cont--;
		for( ; i > 0; i-- ){
			if(n % i == 0) cont ++;
			if(cont == k){
				md = n / i;
				break;
			}
		}
	}
	cout << md << endl;	
	
	return 0;
}
