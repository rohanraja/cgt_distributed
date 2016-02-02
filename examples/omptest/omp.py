
import cgt
import numpy as np

np.random.seed(0)

# cgt.update_config(default_device=cgt.core.Device(devtype="cpu"), backend="python")
ma = np.random.rand(4,3)
print ma.sum(0)
a = cgt.shared(ma)
a = cgt.shared(np.ones((3000,4000)))
# a2 = cgt.shared(np.random.rand(560,166))
# b = a.sum(0)
b = a.sum()

#
f = cgt.function([], [b])
f.save("test.inp")
print f()

