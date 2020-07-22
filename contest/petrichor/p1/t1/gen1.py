import random

N = int(5e5)
Q = int(5e5)
A = int(1e9)


def interval(points):
    lines = []
    for i in range(int(1e4)):
        if i:
            a = b
        else:
            a = 0
        b = random.randint(a, len(points) - 1)
        mx = max(points[a], points[b])
        mn = min(points[a], points[b])
        l = mn#random.randint(mn, mx)
        r = mx#random.randint(l, mx)
        lines.append([l, r])
        b = min(b + 1, len(points) - 1)
    return lines
        
            
            
def query():
    const = int(1e4)
    points = []
    m = 2
    pi = []
    for j in range(m):
        points.append([])
        for i in range(const):
            ai = random.randint(1, int(1e9))
            points[j].append(ai)
            pi.append(ai)
        random.shuffle(points[j])
    return (points, pi)

def main():
    n = int(1e3)
    points, pi = query()
    assert(len(points[0]) * len(points) == int(2e4))
    pi = []
    for i in range(len(points)):
        v = random.randint(0, 1)
        if v:
            pi = pi + points[i][:]
    pi.sort()
    lines = interval(pi)
    #assert(len(lines) == n)
    s = str(len(lines))
    print(s)
    for i in range(len(lines)):
        s = str(lines[i][0]) + " " + str(lines[i][1])
        assert(lines[i][0] <= lines[i][1])
        assert(lines[i][0] >= 1 and lines[i][1] <= int(1e9))
        #print(s)
        #return
        print(s)
    s = str(len(points))
    print(s)
    for i in range(len(points)):
        s = str(len(points[i]))
        print(s)
        s = ""
        for j in range(len(points[i])):
            if j == 0:
                s = s + str(points[i][j])
            else:
                s = s + " " + str(points[i][j])
        if i != len(points) - 1:
            print(s)
        else:
            print(s, end="")

if __name__ == "__main__":
    main()
