C = int(input())
for _ in range(C):
    N = int(input())

    mm = 1
    ans = None
    for _ in range(N):
        s = input()
        n = 1
        for c in s:
            if c.isdigit():
                n *= 10
            elif c.isalpha():
                n *= 26

        if mm < n:
            mm, ans = n, s
        elif mm == n:
            ans = min(ans, s)

    print(ans)
