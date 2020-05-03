from collections import deque
import random
import string

# number of test sets
NSETS = 5

# max number of test cases
MAX_NUM_TC = 1000

# sum of input size in a test set is 1000
SUMTC = 1000

# allowed character list
allowed_char = list(string.ascii_lowercase)

# range of costs
MIN_VAL = -int(1e9)
MAX_VAL = int(1e9)

# probabilites of different kinds of cases
# correct: target is generated such that answer exists
# permutn: target is a random permutation of source
# random : target is generated randomly, independent of source
prob = {
    'correct' : 0.9,
    'permutn' : 0.05,
    'random'  : 0.05
}

# current sum of input size
curr_sum_input = None

# build source list
def build_source(n):

    s = []
    for i in range(n):
        s.append(random.choice(allowed_char))

    return s

# build target list for which answer exists
def build_correct_target(s):

    dq = deque()

    for x in s:
        choice = random.choice(['front', 'back'])

        if choice == 'front':
            dq.appendleft(x)
        else:
            dq.append(x)

    return list(dq)

# build target list
def build_target(s, case_type):

    if case_type == 'correct':
        return build_correct_target(s)
    elif case_type == 'permutn':
        t = s
        random.shuffle(t)
        return t
    else:
        t = []
        for i in range(len(s)):
            t.append(random.choice(allowed_char))
        return t

# generate single test case of a test set
def generate_test_case(is_final):

    global SUMTC, curr_sum_input
    global MIN_VAL, MAX_VAL

    # generation has completed
    if curr_sum_input >= SUMTC:
        assert(is_final is False)
        return False
    
    if is_final:
        n = SUMTC - curr_sum_input
    else:
        n = random.randint(1, SUMTC - curr_sum_input)

    s = build_source(n)
    pr = random.uniform(0, 1)

    if pr <= prob['correct']:
        t = build_target(s, 'correct')
    elif pr <= prob['correct'] + prob['permutn']:
        t = build_target(s, 'permutn')
    else:
        t = build_target(s, 'random')

    f = []
    b = []
    
    for i in range(n):
        f.append(random.randint(MIN_VAL, MAX_VAL))
        b.append(random.randint(MIN_VAL, MAX_VAL))

    curr_sum_input += n

    return n, s, t, f, b

def write_list(fl, ls, add_spaces):

    for x in ls:
        fl.write(str(x))
        if add_spaces:
            fl.write(' ')
    
    fl.write('\n')

# generate single test set
def generate_test_set(fl):

    global MAX_NUM_TC, curr_sum_input
    
    curr_sum_input = 0
    test_list = []
    completed_building = False

    for i in range(MAX_NUM_TC):

        ret_val = generate_test_case(False)
        if ret_val is False:
            completed_building = True
            break

        test_list.append(ret_val)
    
    if completed_building is False:
        test_list.append(generate_test_case(True))

    # number of test cases in test set
    fl.write(str(len(test_list)) + '\n\n')
    
    for (n, s, t, f, b) in test_list:
        
        fl.write(str(n) + '\n')
        write_list(fl, s, False)
        write_list(fl, t, False)
        write_list(fl, f, True)
        write_list(fl, b, True)
        fl.write('\n')

# generates all test sets and places them in different filess
def main():

    for i in range(1, NSETS + 1):
        fl = open('test_set_' + str(i), 'w')
        generate_test_set(fl)
        fl.close()

if __name__ == '__main__':
    main()