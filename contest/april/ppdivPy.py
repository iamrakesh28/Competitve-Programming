import math

prime = int(1e9 + 7)

q = int(input())
for t in range(q):
    n = int(input())
    ans = n % prime
    cb = int(n ** (1 / 3.0))
    power = set ()
    x = 2
    while (x * x * x <= n):
        temp = x * x * x
        while (temp <= n):
            if temp not in power:
                t1 = n // temp;
                ans = ans + t1 * temp;
                ans = ans % prime
                power.add(temp)
            temp = temp * x
        x += 1

    for v in power:
        sq = int(math.sqrt(v))
        if (sq * sq == v):
            sq = n // v
            sq = sq * v
            ans = ans - sq
            ans = ans + prime
            ans = ans % prime

    b = cb
    for i in range(2, b + 1):
        temp = n // (i * i)
        temp = temp * i * i
        ans = ans + temp
        ans = ans % prime

    prev = b
    x = b
    while x >= 1:
        lb = n // (x + 1)
        ub = n // x
        lbs = int(math.sqrt(lb))
        if lbs * lbs != lb:
            lbs += 1
        if lbs == 0:
            lbs += 1
        ubs = int(math.sqrt(ub))

        if (lbs > ubs):
            x -= 1
            continue
        sum2 = ubs * (ubs + 1) * (2 * ubs + 1);
        sum2 = sum2 // 6;
        sum1 = lbs * (lbs + 1) * (2 * lbs + 1);
        sum1 = sum1 // 6;
        if prev != lbs :
            sum1 = sum1 - lbs * lbs;
        sum2 -= sum1;
        sum2 = x * sum2 % prime;
        sum2 = (sum2 + prime) % prime;
        ans = (ans + sum2) % prime;
        prev = ubs;
        x -= 1
    print(ans)
