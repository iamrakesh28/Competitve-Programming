import random

K = 26
n_range = [(int(1e4), int(1e5)), (int(1e2), int(1e4)), (10, 100)]
val_range = [(int(1e8), int(1e9)), (int(1e5), int(1e9)), (int(1e2), int(1e3)), (10, 50)]

def genString(n):
    s = ""
    t = ""
    for i in range(n):
        alp = random.randint(0, K - 1)
        s = s + chr(ord('a') + alp)
        alp = random.randint(0, K - 1)
        t = t + chr(ord('a') + alp)
    return (s, t)

def genMat(vrange):
    i = 0
    mat = []
    while i < K:
        mat.append([])
        j = 0
        while j < K:
            if i == j:
                mat[i].append(0)
                j += 1
                continue
            if j < i:
                mat[i].append(mat[j][i])
                j += 1
                continue
            num = random.randint(vrange[0], vrange[1])
            mat[i].append(num)
            j += 1
        i += 1
    return mat

def testcase(vrange, nrange, i):
    global K
    K = random.randint(1, 26)
    mat = genMat(vrange)
    n = random.randint(nrange[0], nrange[1])
    (s, t) = genString(n)
    fname = "t1/test_case_" + str(i)
    fp = open(fname, "w")
    content = str(n) + " " + str(K) + "\n" + s + "\n" + t + "\n"
    for i in range(K):
        for j in range(K):
            content = content + str(mat[i][j])
            if j != K - 1:
                content += " "
            else:
                content += "\n"
    fp.write(content)
    fp.close()
    
def main():

    '''
    print(n_range, val_range)
    (s, t) = genString(10)
    mat = genMat(val_range[3])
    print(len(mat))
    for x in mat:
        print(len(x), max(x), min(x))
    '''
    testcase(val_range[3], n_range[2], 1)
    testcase(val_range[2], n_range[1], 2)
    testcase(val_range[1], n_range[1], 3)    
    testcase(val_range[1], n_range[0], 4)
    testcase(val_range[0], (n_range[0][1], n_range[0][1]), 5)

if __name__ == "__main__":
    main()
