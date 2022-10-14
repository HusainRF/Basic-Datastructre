def numOfDivisors(n):
    def pf(n):
        dic = defaultdict(int)
        while n % 2 == 0:
            dic[2] += 1
            n = n // 2
        for i in range(3,int(math.sqrt(n))+1,2):
            while n % i== 0:
                dic[i] += 1
                n = n // i
        if n > 2:
            dic[n] += 1
        return dic
    p = pf(n)
    ans = 1
    for item in p:
        ans *= (p[item] + 1)
    return ans