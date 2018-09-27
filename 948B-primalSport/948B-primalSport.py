from sys import stdin
maxn = 1000006
prime = [0] * maxn
def getPrimes():
    #Encontrar el mayor factor primo de cada número
    n = 2
    while(n < maxn):
        num = n*2
        while(num < maxn):
            prime[num] = n
            #print("num",num,"= n",n)
            num += n
        num = n + 1
        #print(num,n)
        while(  num < maxn and prime[num]!= 0 ):
            num += 1
        n = num


def main():
    getPrimes()
    n = int(stdin.readline().strip())
    a = 0
    b = prime[n]
    x0 = 9999999
    print(b)
    for i in range(n-b+1,n+1):
        
        a = prime[i]
        x0 = min(i-a+1,x0)
        print("i",i,"prime[i]",prime[i],"x0",x0)
    print(x0)

main()
