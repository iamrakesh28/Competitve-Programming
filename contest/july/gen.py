import random

N = int(2e5)
print(N)
for i in range(N):
    print(str(random.randint(0, 20)) + " ", end='')
print(N)
for i in range(N):
    l = random.randint(0, N - 1)
    r = random.randint(l, N - 1)
    print(l, r)
