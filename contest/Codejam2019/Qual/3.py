import sys

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b,a%b)

q = int(eval(input()))
for i in range(q):
	data = sys.stdin.readline()
	l = data.split()
	n = int(l[0])
	l = int(l[1])	
	ind = None
	prime = [ [0,0] for j in range(l+1) ]
	ans = [ ['A'] for j in range(l+1) ]
	data = sys.stdin.readline()
	prod = data.split()
	for j in range(len(prod)):
		prod[j] = int(prod[j])
	for j in range(l):
		if j and prod[j] != prod[j-1] :
			ind = j
		prime[j][1] = j
	j = ind+1
	p = gcd(prod[ind],prod[ind-1])
	prime[ind][0] = p
	prime[l][1] = l
	while j <= l: 
		prime[j][0] = prod[j-1]//p
		p = prime[j][0]
		j += 1	
	j = ind-1
	p = gcd(prod[ind],prod[ind-1])
	#cout<<p<<" "<<ind<<endl;
	while j >= 0:
		prime[j][0] = prod[j]//p
		p = prime[j][0]
		j -= 1	
	prime.sort()
	ch = ord('A')
	#print(prime)
	ans[prime[0][1]] = chr(ch)
	#cout<<prime[0].first<<" ";
	for j in range(1,l+1):
		if prime[j][0] != prime[j-1][0]:
			ch += 1
			ans[prime[j][1]] = chr(ch)
		else:
			ans[prime[j][1]] = chr(ch)
	#cout<<prime[j].first<<" ";
	s = ''
	for j in range(l+1):
		s += str(ans[j])
	print('Case #',i+1,': ',s,sep='')

	
