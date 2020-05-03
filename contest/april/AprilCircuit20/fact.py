def prime(n):
	i = 2
	while i * i <= n:
		if n % i == 0:
			return False
		i += 1
	return True


def factorize(n):
	fact = []
	if n % 2 == 0:
		fact.append(2)
		while n % 2 == 0:
			n >>= 1
	i = 3
	while i * i <= n:
		if n % i == 0:
			fact.append(i)
			while n % i == 0:
				n /= i
		i += 2
	if n > 1:
		fact.append(n)
	return fact

x = 100000007700000049
print(factorize(5))
print(factorize(4))
print(factorize(x))
print(prime(4))
print(prime(3))
print(prime(100000007))
