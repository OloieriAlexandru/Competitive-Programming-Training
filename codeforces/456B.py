
n = int(raw_input())
r = n % 4
ans = 1**r + 2**r + 3**r + 4**r
ans %= 5
print ans