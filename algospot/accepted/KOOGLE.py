C = int(input())
for _ in range(C):
    N = int(input())

    mm = 1
    ans = None
    for _ in range(N):
        s = input()
        d,a = 0,0
        for c in s:
            if c.isdigit():
                d += 1
            elif c.isalpha():
                a += 1
        n = 26**a * 10**d

        if mm < n:
            mm, ans = n, s
        elif mm == n:
            ans = min(ans, s)

    print(ans)
