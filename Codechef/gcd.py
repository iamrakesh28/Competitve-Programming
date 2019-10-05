
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

def repeat(time,p,t):
	r=1
	while time > 0:
		if(time%2) :
			r = (r*p)%t
		p = (p*p)%t
		time = time//2
	return r%t



q = int(input())
prime = 1000000007
i = 0
while i<q:
	a,b,n = raw_input().split(" ")
	n = int(n)
	b = int(b)
	a = int(a)
	mod = a-b
	if mod == 0:
		an = repeat(n,a%prime,prime)
		ans = (an + an)%prime
		print(ans)
	else :	
		an = repeat(n,a%mod,mod)
		bn = repeat(n,b%mod,mod)
		ans = gcd(mod,(an+bn)%mod)%prime
		print(ans)
	i+=1
