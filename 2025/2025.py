t = int(input())
for i in range(t):
    n, k = [int(i) for i in input().split()]
    m = n // k
    q = n % k
    z = m + 1
    s = ((n - z * q) * (n - m) + (z * q) * (n - m - 1)) // 2
    print(s)
