                      
binN = int(raw_input())
n = 0
p2 = 1                 
while binN > 0:
	if binN % 10 == 1:
		n += p2
	p2 *= 2
	binN /= 10
              
if n <= 1:
	print 0
else:
	ans = 1
	p4 = 4
	while p4 < n:
		ans += 1
		p4 *= 4
	print ans