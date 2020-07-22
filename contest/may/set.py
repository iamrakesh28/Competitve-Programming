import random

MAX = 10000
MIN = 0

case = 10000
print(case)
for i in range(case):
    x = random.randint(MIN, MAX)
    y = random.randint(MIN, MAX)
    r = random.randint(MIN, MAX)
    l = random.randint(MIN, r)
    print(x, y, l, r)
