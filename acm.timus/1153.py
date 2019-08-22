
def getDr():
	ret = 1
	for i in range(601):
		ret = ret * 10
	return ret

n = int(raw_input())
       
st = 1           
dr = getDr()

while st <= dr:
	m = (st + dr) / 2
	curr = (m * (m+1)) / 2
	if curr == n:
		print m
		break
	elif curr > n:
		dr = m-1
	else:
		st = m+1