import cgt
import numpy as np, numpy.random as nr

a = cgt.scalar(name='a')
nr.seed(0)
# ones = cgt.shared(np.ones((2,3)))
ones = cgt.shared(nr.randn(2))
d = cgt.sum(ones) + a

out = ones * 10
# d = a / 11
g = cgt.function([a], [d])
g.save("train.inp")
g.record("train_sched.bin")



# g = run.load()
# g.record("run_sched.bin2")

# print g(np.ones((2,3)) )
print g(420)
print g(112)
