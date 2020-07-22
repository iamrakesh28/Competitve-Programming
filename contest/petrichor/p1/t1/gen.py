import random

N = int(5e5)
Q = int(5e5)
A = int(1e9)


def interval():
    m = 10
    line = [[10, int(1e5)], [int(5e5), int(8e5)], [int(1e6), int(3e6)], [int(2e6), int(4e6)], [int(1e7), int(2e7)], [int(4e7), int(5e7)], [int(1e8), int(2e8)], [int(4e8), int(5e8)], [int(6e8), int(7e8)], [int(8e8), int(9e8)]]
    #line = [int(1e5), int(3e5), int(5e5), int(7e5), int(9e5), int(2e6), int(4e6), int(6e6), int(8e6), int(9e6)]
    lines = []
    prev = None
    final = None
    const = int(5e3)
    for i in range(m):
        #if i == 0:
        #    prev = 1
        #    final = line[i + 1]
        #elif i == m - 1:
        #    prev = line[i - 1]
        #    final = int(1e9)
        #else:
        #    prev = line[i - 1]
        #    final = line[i + 1]
        #prev = 1
        #final = int(1e9)
        #l = line[i]
        #r = l + int(1e5)
        for j in range(const):
            a = random.randint(1, line[i][0])
            b = random.randint(line[i][1], int(1e9))
            lines.append([a, b])
    random.shuffle(lines)
    return (line, lines)
        
            
            
def query(line):
    const = int(5e1)
    points = []
    m = 1000
    for i in range(m):
        points.append([])
        for j in range(const):
            num = random.randint(0, 1)
            ind = random.randint(0, 9)
            if num:
                ai = random.randint(line[ind][0], line[ind][1])
                points[i].append(ai)
            else:
                ai = random.randint(1, int(1e9))
                points[i].append(ai)
        random.shuffle(points[i])
    random.shuffle(points)
    return points

def main():
    n = int(5e4)
    line, lines = interval()
    assert(len(lines) == n)
    points = query(line)
    assert(len(points[0]) * len(points) == n)
    s = str(n)
    print(s)
    for i in range(len(lines)):
        s = str(lines[i][0]) + " " + str(lines[i][1])
        assert(lines[i][0] <= lines[i][1])
        assert(lines[i][0] >= 1 and lines[i][1] <= int(1e9))
        #print(s)
        #return
        print(s)
    s = str(len(points[0]))
    print(s)
    for i in range(len(points[0])):
        s = str(len(points))
        print(s)
        s = ""
        for j in range(len(points)):
            if j == 0:
                s = s + str(points[j][i])
            else:
                s = s + " " + str(points[j][i])
        if i != len(points[0]) - 1:
            print(s)
        else:
            print(s, end="")

if __name__ == "__main__":
    main()
