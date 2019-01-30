n, m = map(int, input().split())
if m>=n:
    print(n)
else:
    l = 1
    r = 2000000000
    for i in range(100):
        mid = (l + r) // 2
        if(((mid) * (mid + 1)) // 2 + m >= n):
            r = mid
        else:
            l = mid
    print(m + r)