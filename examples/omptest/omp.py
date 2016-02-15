
import cgt
import numpy as np

np.random.seed(0)

# cgt.update_config(default_device=cgt.core.Device(devtype="cpu"), backend="python")
ma = np.random.rand(4,3)
print ma 
a = cgt.shared(ma)
x = cgt.matrix()
# a = cgt.shared(np.ones((3000,40000)))
# a2 = cgt.shared(np.random.rand(560,166))
# b = a.sum(0)
# b = a.sum()
# b = a / 4
b = cgt.concatenate( [a, a] , 0)

f = cgt.function([x], [x])
# f.save("test.inp")

print f.record("tstout", ma)
# print f(ma)[0].shape

