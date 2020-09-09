#first file with python instead of c++, figured this would be more convenient from now on
from numba import jit
from matplotlib import pyplot as plt
import numpy as np

import time
start_time = time.time()

#inital conditions
size = 100000

a = 0.9
b = -0.6013
c = 2
d = 0.5

x_o = -0.72
y_o = -0.64

@jit()
def fnx(x,y,a,b):
	res = x*x - y*y + a*x + b*y
	return res

@jit()
def fny(x,y,c,d):
	res = 2*x*y + c*x + d*y
	return res

@jit()
def iter():
	pl = np.empty(shape=(2,size), dtype=np.float32)	
	pl[0,0] = x_o
	pl[1,0] = y_o
	for i in range(1,size):
		pl[0,i] = fnx(pl[0,i-1], pl[1,i-1], a, b)
		pl[1,i] = fny(pl[0,i-1], pl[1,i-1], c, d)
	return pl

xy = iter()

x = xy[0,...]
y = xy[1,...]

plt.scatter(x, y, s=0.5, color='black')
print("--- %s seconds ---" % (time.time() - start_time))

plt.show()