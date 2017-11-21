import numpy as np
from itertools import permutations
import sys

def measure_mvmnt(x,y):
    s=0
    n=x.shape[0]
    for n_ in xrange(n):
        s+=np.sum(y==x)**2.
        y=np.concatenate((y[1:],y[:1]))
    return s

N=5

shw=True

X=np.arange(N)
ZZ=np.array([0,0,1,1,2])
P=permutations(X)
nmax=0
for p in P:
    x=np.array(p)
    XX=ZZ[x]
    y=np.array(p)
    flg=True
    n=0
    s=0
    while flg:
        n=n+1
        if shw:
            print ZZ[y], 
        else:
            None
        y=y[x]
        s+=measure_mvmnt(XX,ZZ[y])
        if np.all(ZZ[y]==XX):
            if shw:
                print ZZ[y],
            else:
                None
            if n > nmax:
                nmax = n
            print float(s)/n,
            flg=False
            continue
    if shw:
        print
    else:
        None

print nmax
