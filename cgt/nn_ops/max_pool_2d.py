import cgt
from cgt import core
import ctypes
from collections import namedtuple
import numpy as np


# <Copied from im2col.py>
PoolInfo = namedtuple("PoolInfo", ["kernel_h", "kernel_w", "pad_h", "pad_w", "stride_h", "stride_w"])

def info2closure(info):
    return [
        ("kernel_h", ctypes.c_int, info.kernel_h),
        ("kernel_w", ctypes.c_int, info.kernel_w),
        ("pad_h", ctypes.c_int, info.pad_h),
        ("pad_w", ctypes.c_int, info.pad_w),
        ("stride_h", ctypes.c_int, info.stride_h),
        ("stride_w", ctypes.c_int, info.stride_w),
    ]    
# </Copied>

class MaxPool(core.Op):
    available_impls = ("native_cpu",)    
    def __init__(self, info):
        assert info.stride_h>0 and info.stride_w>0        
        self.info = info
    def get_diff(self, _):
        return [True]
    def get_py_impl(self):
        raise core.MethodNotDefined
    def pullback(self, (x,), y, gy):
        pool,mask = core.unpack(y)
        gpool,_gmask = gy
        return [core.Result(MaxPoolPullback(self.info), [x,pool,mask,gpool])]
    def shp_apply(self, inputs):
        # pooled_height_ = static_cast<int>(ceil(static_cast<float>(height_ + 2 * pad_h_ - kernel_h_) / stride_h_)) + 1;
        # pooled_width_ = static_cast<int>(ceil(static_cast<float>(width_ + 2 * pad_w_ - kernel_w_) / stride_w_)) + 1;
        info = self.info
        batch_size, channels, height, width = cgt.shape(inputs[0])
        pooled_height =  cgt.ceil_divide(height + 2*info.pad_h - info.kernel_h, info.stride_h)
        pooled_width = cgt.ceil_divide(width + 2*info.pad_w - info.kernel_w, info.stride_w)
        outshape = [batch_size ,  channels, pooled_height, pooled_width]
        return (outshape, outshape)
    def typ_apply(self, inputs):
        return core.TupleType(core.TensorType(inputs[0].dtype, 4), core.TensorType('i4', 4))
    def get_closure_wrapper(self):
        return self.clobj
    def get_closure(self, _inputs):
        return info2closure(self.info)
    def get_native_compile_info(self, input_types, devtype):
        code = r"""
CGT_EXPORT_C void $function(conv_closure* cl, cgtArray** reads, cgtTuple* write) {
    max_pool<%(cdtype)s>(cl, reads[0], static_cast<cgtArray*>(write->getitem(0)), static_cast<cgtArray*>(write->getitem(1)));
}"""%dict(cdtype=core.np2c[input_types[0].dtype])
        self.clobj = info2closure(self.info)
        return core.NativeCompileInfo(code, closure_triples=self.clobj, includes=["pooling.h"])

class MaxPoolPullback(core.Op):
    available_impls = ("native_cpu",)
    def __init__(self, info):
        self.info = info
    def get_py_impl(self):
        raise core.MethodNotDefined
    def shp_apply(self, inputs):
        return cgt.shape(inputs[0])
    def typ_apply(self, inputs):
        return core.TensorType(inputs[0].dtype, 4)
    def get_closure_wrapper(self):
        return self.clobj
    def get_closure(self, _inputs):
        return info2closure(self.info)
    def get_native_compile_info(self, input_types, devtype):
        code = r"""
CGT_EXPORT_C void $function(conv_closure* cl, cgtArray** reads, cgtArray* write) {
    max_pool_pullback<%(cdtype)s>(reads[0], reads[1], reads[2], reads[3], write);
}"""%dict(cdtype=core.np2c[input_types[0].dtype])
        self.clobj = info2closure(self.info)
        return core.NativeCompileInfo(code, closure_triples=self.clobj, includes=["pooling.h"])

