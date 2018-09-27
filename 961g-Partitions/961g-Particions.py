from sys import stdin
maxi = 200005
mod = 1000000007
inv = [0]* maxi
f = [0] * maxi
jie = [0]  * maxi

def qmi(a,b):
    ans = 1
    while b:
        if(b%2):
            ans = ans*a%mod
        a = a*a%mod
        b //=2
    ##print("qmi ans",ans)
    return ans


def c(x,y):
    #print("C x y",x,y)
    ans = jie[x]*f[y]%mod*f[x-y]%mod
    #print("jie[x]",jie[x])
    #print("c ans",ans)  
    return ans

def s(n,k):
    ans = 0
    for i in range(k+1):
        if( (k+i)%2 ):
            ans = ((ans-c(k,i)*qmi(i,n)%mod)%mod+mod)%mod
        else:
            ans=((ans+c(k,i)*qmi(i,n)%mod)%mod+mod)%mod
    ans =  ans*f[k]%mod              
    #print("s ans",ans)            
    return ans         


def main():
    n,k = [int(x) for x in stdin.readline().strip().split()]
    jie[0] = f[0] = inv[0] = 1
    for i in range(1,k+1):
        inv[i] = qmi(i,mod-2)
    
    for i in range(1,k+1):
        f[i] = f[i-1]*inv[i]%mod
        jie[i] = jie[i-1]*i%mod
    
    suma = 0
    m = [int(x) for x in stdin.readline().strip().split()]
    for i in range(n):
        suma = (suma+m[i])%mod
    #print("suma n k",suma,n,k)
    res = (s(n,k)+(n-1)*s(n-1,k)%mod)%mod*suma%mod
    #print("result",res)
    print(res)   
    


main()
