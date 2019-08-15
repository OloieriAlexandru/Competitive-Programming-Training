
def is_prime(x):
	if x % 2 == 0 and x != 2:
		return False
	if x == 1:
		return False
	i = 3
	while i * i <= x:
		if x % i == 0:
			return False
		i += 2
	return True

primes = []

n = int(raw_input())

cnt = 0
i = 2
while cnt < n:
	if is_prime(i):
		primes.append(i)
		cnt += 1
	i += 1	

if n <= 2:
	print -1
else:
	ans = 1
	for i in range(n):
		ans = ans * primes[i]
	for i in range(n):
		print ans/primes[i]