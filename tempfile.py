import math
def solution(w, h, s):
    # Your code here
    a = partitions(w)
    b = symgroup(w)
    c = partitions(h)
    d = symgroup(h)
    perms = []
    coeffs = []
    for i in range(len(a)):
        for j in range(len(c)):
            perms.append(matjoin(a[i], c[j]))
            coeffs.append(b[i]*d[j])
    res = 0
    for i in range(len(perms)):
        res += coeffs[i]*s**len(perms[i])
    return str(res//sum(coeffs))
    
def partitions(n):
    dp = []
    dp.append([[]])
    dp.append([[1]])
    for i in range(2, n+1):
        dptemp = set()
        for j in range(1, i+1):
            temp = [j]
            for k in dp[i-j]:
                dptemp.add(tuple(sorted(temp + k)))
        dptemp = list(dptemp)
        dptemp = list(map(list, dptemp))
        dp.append(dptemp)
    return dp[n]
    
def symgroup(n):
    x = partitions(n)
    coeffs = []
    for i in range(len(x)):
        num = math.factorial(n)
        perm = {}
        for j in x[i]:
            perm[j] = perm.get(j, 0) + 1
        den = 1
        for p in perm:
            den *= (p**perm[p])*(math.factorial(perm[p]))
        coeffs.append(num//den)
    return coeffs
    
def matjoin(x, y):
    temp = []
    for i in x:
        for j in y:
            for k in range(math.gcd(i, j)):
                temp.append((i*j)//math.gcd(i, j))
    return temp


print(solution(2,2,2))
print(solution(12,12,20))
