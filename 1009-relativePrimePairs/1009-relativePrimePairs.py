from sys import stdin

def main():
    a,b = [int(x) for x in stdin.readline().strip().split()]
    print('YES')
    for i in range(a,b+1,2):
        print(i,i+1)
    

main()
