MAXN=1001
LOGN=10
ancestor=[[0 for i in range(LOGN)] for i in range(MAXN)]
level=[0 for i in range(MAXN)]
parent=[0 for i in range(MAXN)]
def lca(u,v):
        lu=level[u]
        lv=level[v]
        if lu<lv:
                t=u
                u=v
                v=t
        log=0
        t=level[u]-level[v]
        while 1<<log <=t:
                log+=1
        while level[u]!=level[v] :
                if level[ancestor[u][log]]>=level[v]:
                        u=ancestor[u][log]
                else:
                        log-=1
        if u==v:
                return u
        log=0
        t=level[u]
        while 1<<log <=t:
                log+=1
        while parent[u]!=parent[v]:
                if ancestor[u][log]!=ancestor[v][log]:
                        u=ancestor[u][log]
                        v=ancestor[v][log]
                else:
                        log-=1
        return parent[u]
t=int(raw_input())
tc=1
while t:
	t-=1
	n=int(raw_input())
	parent=[0 for i in range(n+1)]
	level[1]=0
	for i in range(1,n+1):
		inp=raw_input()
		inp=inp.split()
		m=int(inp[0])
		for j in range(1,m+1):
			parent[int(inp[j])]=i
			level[int(inp[j])]=level[i]+1
	for i in range(1,n+1):
                ancestor[i][0]=parent[i]
        for i in range(1,LOGN):
                for j in range(1,n+1):
                        ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1]
	q=int(raw_input())
	print "Case %d:" % tc
	tc+=1
	while q:
		q-=1
		inp=raw_input()
		inp=inp.split()
		a=int(inp[0])
		b=int(inp[1])
		if a==1 or b==1:
			print 1
		else:
			print lca(a,b)
