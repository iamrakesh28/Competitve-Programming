import random

# number of test sets (minimum 2)
NUM_TEST_SETS = 5

# input size range (normal)
MIN_N = int(5e5)
MAX_N = int(1e6)

# input size range (special case 1)
SPEC_N = int(5e3)

# difference small range
MIN_DIFF = 1
MAX_DIFF = 100

# difference special (special case 2)
DIFF_SPECIAL = int(1e4)

# number range
MIN_VAL = 0
MAX_VAL = int(1e6)

def write_list(fl, ls, add_spaces):

    for x in ls:
        fl.write(str(x))
        if add_spaces:
            fl.write(' ')
    
    fl.write('\n')

def generate_test_set(fl, n, d):

    global MIN_VAL, MAX_VAL

    a = []
    for i in range(n):
        a.append(random.randint(MIN_VAL, MAX_VAL))
    
    fl.write(str(n) + ' ' + str(d) + '\n')
    write_list(fl, a, True)

def main():
    
    global MIN_N, MAX_N, SPEC_N
    global MIN_DIFF, MAX_DIFF, DIFF_SPECIAL

    # special case: small input
    fl = open('test_case_1', 'w')
    generate_test_set(fl, SPEC_N, random.randint(MIN_DIFF, MAX_DIFF))
    fl.close()

    # special case large difference value
    fl = open('test_case_2', 'w')
    generate_test_set(fl, random.randint(MIN_N, MAX_N), DIFF_SPECIAL)
    fl.close()

    for i in range(3, NUM_TEST_SETS + 1):
        fl = open('test_case_' + str(i), 'w')
        generate_test_set(
            fl,
            random.randint(MIN_N, MAX_N),
            random.randint(MIN_DIFF, MAX_DIFF)
        )
        fl.close()

if __name__ == '__main__':
    main()