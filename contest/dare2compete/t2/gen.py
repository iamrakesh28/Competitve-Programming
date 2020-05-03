import random

b = 5 * int(1e3)
a = int(1e3)
n = random.randint(a, b)
dn = random.randint(20, int(1e2))
print(n, ' ', dn)
l = []
'''
for i in range(n):
    v = random.randint(1, b)
    l.append(v)
'''

p = 1
r = random.randint(1, 100)
d = 1
for i in range(n):
    v = None
    if r == 0:
        r = random.randint(1, 100)
        d = 1 - d
    if d == 1:
        p = int((1 + p) >> 5)
        v = random.randint(p, b)
    else:
        p = int((b + p) >> 5)
        v = random.randint(1, p)
    p = v
    l.append(v)
    r -= 1

for i in range(n):
    print(l[i], ' ', end='')
print()
