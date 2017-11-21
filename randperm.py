import sys
from random import shuffle
n=int(sys.argv[1])
s=range(n)
shuffle(s)
for s_ in s:
    print s_,
print
