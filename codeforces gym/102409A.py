t = int(input())
for q in range(t):
	a, b, c = list(map(int, input().split()))
	x = a + b
	print (x//c,end=".")
	mod = x % c
	for i in range(50):
		mod = mod * 10
		print (mod // c,end=""),
		mod = mod % c
	print ("")