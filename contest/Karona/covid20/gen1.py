import random

S = None
T = None

N = 1000
M = 1000

def lies(i, j):
    s = min(S, T)
    t = max(S, T)
    if s[1] >= t[1]:
        if i >= t[0] and i <= s[1] and j >= t[1] and j <= s[1]:
            return True
        return False
    else:
        if (i, j) >= s and (i, j) <= t:
            return True
    return False

def gen_mat(n, m, prob, arr):
    s = ""
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if (i, j) == S:
                s += 'S'
                continue
            elif (i, j) == T:
                s += 'T'
                continue
            if lies(i, j):
                s += '.'
                continue
            ch = random.choices(arr, prob, k=1)[0]
            s += ch
        s += '\n'
    return s

def main():
    global S, T
    prob = [40, 100, 10]
    arr = ['#', '.', '*']
    n = N
    m = M
    while (n, m) == (1, 1):
        n = random.randint(N - 100, N)
        m = random.randint(M - 100, M)
    S = (random.randint(int(4 * n / 5) + 1, n), random.randint(int(4 * m / 5) + 1, m))
    #S = (1, 1)
    T = S
    #T = (n, m)
    while T == S:
        T = (random.randint(int(2 * n / 3) + 1, n), random.randint(int(2 * m / 3) + 1, m))
    #print(S, T)
    s = str(n) + ' ' + str(m) + '\n'
    s += gen_mat(n, m, prob, arr)
    print(s)

if __name__ == "__main__":
    main()
