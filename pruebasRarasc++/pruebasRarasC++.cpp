#include <bits/stdc++.h>

using namespace std;

/*
int quick_pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1) ans = 1ll*ans*a%yzh;
        a = 1ll*a*a%yzh, b >>= 1; 
    }
    return ans;
}*/
int main(){
	int k = 10000;
	int suma = 0;
	printf("%d\n",suma);
	while(k){
		
		printf("%d kha\n",2e5);
		printf("%d re kha\n",-1LL*1e9+7/2);
		printf("%d %d %d\n",k,suma,(suma+=k)%=5);
		k >>= 1;// divide en 2
		// k&1 = 1 si es impar = 0 si es par
		//printf("%d %d\n",k&1,k);
	}
	
	printf("%lld\n",2ll);
	printf("%lld\n",4>>1);
	
	return 0;
}
