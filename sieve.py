def sieve(n):
    res=[0 for i in range(n+1)]
    prime=[]
    for i in range(2,n+1):
        if not res[i]:
            prime.append(i)
            for j in range(1,n//i+1):
                res[i*j]=1
    return prime