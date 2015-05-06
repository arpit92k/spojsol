t=int(raw_input())
mark=range(10)
while t>0:
	t-=1
	inp=raw_input()
	inp=inp.split()
	b=int(inp[0])
	p=int(inp[1])
	if b==0:
		print 0
	elif p==0:
		print 1
	else:
		for i in range(10):
			mark[i]=0
		l=[]
		d=b%10
		while not mark[d]:
		 	l.append(d)
	 		mark[d]=1
		 	d*=b
		 	d%=10
		d=len(l)
		p-=1
		print l[p%d]
