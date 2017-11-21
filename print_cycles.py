import numpy as np
from itertools import permutations
import sys

def measure_mvmnt(x,y):
    s=0
    n=x.shape[0]
    for n_ in xrange(n):
        s+=np.sum(y==x)**2
        y=np.concatenate((y[1:],y[:1]))
    return s


if len(sys.argv) >= 2:
    N=int(sys.argv[1])
else:
    N=4

if len(sys.argv) >= 3:
    shw=True
else:
    shw=False

X=np.arange(N)

P=permutations(X)
nmax=0
for p in P:
    x=np.array(p)
    y=np.array(p)
    flg=True
    n=0
    s=0
    while flg:
        n=n+1
        if shw:
            print  y, 
        else:
            None
        y=y[x]
        s+=measure_mvmnt(X,X[y])
        if np.all(y==x):
            if shw:
                print y,
            else:
                None
            if n > nmax:
                nmax = n
            if shw:
                print float(s)/n,
            else:
                print float(s)/n
            flg=False
            continue
    if shw:
        print
    else:
        None

print nmax
