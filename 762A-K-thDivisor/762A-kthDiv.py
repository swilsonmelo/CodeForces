from sys import stdin


def main():

    n,k = [int(x) for x  in stdin.readline().strip().split()]
    Icop = 0
    md = -1
    cont = 0
    for i in range(1,n+1):
        if( i*i > n):
            break
        if( n % i ) == 0:
            cont += 1
        if(cont == k ):
            md = i
            break
        Icop = i
    #print(Icop,cont,md)
    if(md == -1):
        
        for i in range(Icop,0,-1):
            #print(i,cont)
            if(n % i == 0):
                cont +=1
            if(cont == k):
                md = n//i
                break
    print(md)
        
    



main()
