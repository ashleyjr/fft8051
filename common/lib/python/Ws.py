import sys
import math
import cmath

def calcW(n, N, scale):
    assert n < N
    im = -((math.pi*2*n)/N)
    p = complex(0, im)
    c = cmath.exp(p)
    r = (c.real * scale)
    i = (c.imag * scale)
    return int(r),int(i)

def main(argv):

    if 3 != len(argv):
        print "Error: Args"
        return

    N     = 2 ** int(argv[1])
    scale = int(argv[2])

    print "// Autogenerated"
    print "#include \"fft8051.h\""
    print "static const complex_t W[N] = {"
    for j in range(N):
        r,i = calcW(j,N,scale)
        print "\t{(char)" + str(r) + ", (char)" + str(i) + "}",
        if j != N-1:
            print ",",
        print""
    print "};"


if "__main__" == __name__:
    main(sys.argv)

