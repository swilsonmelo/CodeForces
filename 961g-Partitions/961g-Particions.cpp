#include<bits/stdc++.h>

#define mod 1000000007 

using namespace std;
typedef long long ll;
ll inv[200005],f[200005],jie[200005];
ll qmi(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	//printf("qmi ans %d\n",ans);
	return ans;
}
ll C(ll x,ll y){
	long long ans;
	ans = jie[x]*f[y]%mod*f[x-y]%mod;
	//printf("C x %lld y %lld\n",x,y);
	//printf("jie[x] %lld f[x] %lld f[x-y] %lld]\n",jie[x],f[x],f[x-y]);
	//printf("c ans %lld\n",ans);
	return ans;
	}
ll S(ll n,ll k)
{
	ll ans=0;
	for(int i=0;i<=k;i++)
	{
		if((k+i)%2)ans=((ans-C(k,i)*qmi(i,n)%mod)%mod+mod)%mod;
		else ans=((ans+C(k,i)*qmi(i,n)%mod)%mod+mod)%mod;
	}
	ans = ans*f[k]%mod;
	//printf("s ans %lld\n",ans);
	return ans;
}
int main()
{
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	jie[0]=f[0]=inv[0]=1;
	for(ll i=1;i<200005;i++)
		inv[i]=qmi(i,mod-2);
	for(ll i=1;i<200005;i++)
		f[i]=f[i-1]*inv[i]%mod,jie[i]=jie[i-1]*i%mod;
	ll n,k,sum=0;
	//scanf("%lld%lld",&n,&k);
	cin >> n >> k;
	for(ll i=0;i<n;i++)
	{
		ll r;
		cin >> r;
		//scanf("%lld",&r);
		sum=(sum+r)%mod;
		//printf("%d\n",r);
	}
	//printf("suma %lld %lld %lld\n",sum,n,k);
	long long res = (S(n,k)+(n-1)*S(n-1,k)%mod)%mod*sum%mod;
	//printf("result %lld\n",(S(n,k)+(n-1)*S(n-1,k)%mod)%mod*sum%mod);
	//printf("%lld\n",res);
	cout << res<< endl;
}
