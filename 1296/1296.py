n = int(input())
s = 0
ans = 0
i = 0
while i < n:
    i = i + 1
    inp = int(input())
    s = s + inp
    if s < 0:
        s = 0
    elif sequence > ans:
        ans = s
print(ans)
