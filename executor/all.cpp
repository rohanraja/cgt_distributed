
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_f9255658e60a2f311a374964fa909aab(float x, int8_t y) {return x*y;}
                CGT_EXPORT_C void call_f9255658e60a2f311a374964fa909aab(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int8_t* in1 = (int8_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_f9255658e60a2f311a374964fa909aab(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                static inline float scalar_call_acf21bff0d87db1480fd9f44dbb01744(float x) {return x*x;}
                CGT_EXPORT_C void call_acf21bff0d87db1480fd9f44dbb01744(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_acf21bff0d87db1480fd9f44dbb01744(readdata[i]);
                    }
                }
#include "cgt_common.h"
typedef struct closure_1346fce5ddd6517ee0c556c24438a685 {
int ax;
} closure_1346fce5ddd6517ee0c556c24438a685;

            CGT_EXPORT_C cgtArray* call_1346fce5ddd6517ee0c556c24438a685(void* cl0, cgtArray** reads) {
                closure_1346fce5ddd6517ee0c556c24438a685* cl = (closure_1346fce5ddd6517ee0c556c24438a685*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_e70024f2d2f2197f4e868709be40790e(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_e70024f2d2f2197f4e868709be40790e(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_e70024f2d2f2197f4e868709be40790e(in0[i], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline int64_t scalar_call_3571c1db4b7ec367015133339a08488e(int64_t x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_3571c1db4b7ec367015133339a08488e(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3571c1db4b7ec367015133339a08488e(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "string.h"

        using namespace std ;
        static inline float reduction_call_fc058bee187972eb84b3bf5f998e4c2c(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_fc058bee187972eb84b3bf5f998e4c2c(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(i0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(i0,0) = reduction_call_fc058bee187972eb84b3bf5f998e4c2c(x, y);
            }}
        }
        
#include "cgt_common.h"
typedef struct closure_377edd6bc778d8d351c7d2481e0d043b {
int ndim;
void* shape;
uint8_t dtype;
void* data;
} closure_377edd6bc778d8d351c7d2481e0d043b;

            CGT_EXPORT_C void call_377edd6bc778d8d351c7d2481e0d043b(closure_377edd6bc778d8d351c7d2481e0d043b* cldata, cgtArray** reads, cgtArray* write) {
                cgt_memcpy(cgtCPU, cgtCPU, write->data(), cldata->data, write->nbytes());
            }
            
#include "cgt_common.h"

            CGT_EXPORT_C void call_ad1488cf4dc7245ba68a8e34f05f5773(void**, cgtArray** xkp, cgtArray* write) {
                cgtArray *x=xkp[0], *k=xkp[1], *p=xkp[2];
                if (write->data() != x->data()) cgt_memcpy(cgtCPU, cgtCPU, write, x, write->nbytes());
                for (int i=0; i < p->size(); ++i) {
                    write->at<float>(k->at<long>(i)) += p->at<float>(i);
                }
            }
            
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_1d73b0b14c11996deb1caa8267af6a78(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_1d73b0b14c11996deb1caa8267af6a78(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_1d73b0b14c11996deb1caa8267af6a78(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"

            CGT_EXPORT_C void call_2822c07acfde5ee13a7fa554778e4fcf(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = read->at<float>(i0,0);
                }}
            }
            
#include "cgt_common.h"
#include "math.h"

                static inline float scalar_call_960ddb616081d55826d0d2ed97b532c4(float x) {return (-x);}
                CGT_EXPORT_C void call_960ddb616081d55826d0d2ed97b532c4(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_960ddb616081d55826d0d2ed97b532c4(readdata[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_f00b0648901f586735a69d8e8d71081b(float x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_f00b0648901f586735a69d8e8d71081b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_f00b0648901f586735a69d8e8d71081b(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_60374604bcb1913f2624c58f384f0cf5(float x, float y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_60374604bcb1913f2624c58f384f0cf5(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_60374604bcb1913f2624c58f384f0cf5(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                static inline float scalar_call_72da8db18ab69840269cdb7c6df936b5(float x) {return sqrt(x);}
                CGT_EXPORT_C void call_72da8db18ab69840269cdb7c6df936b5(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_72da8db18ab69840269cdb7c6df936b5(readdata[i]);
                    }
                }
#include "cgt_common.h"
#include "cblas.h"
typedef struct closure_a8e6eaa51a19a09311763a23e4857537 {
bool tA;
void* handle;
} closure_a8e6eaa51a19a09311763a23e4857537;

                CGT_EXPORT_C void call_a8e6eaa51a19a09311763a23e4857537(closure_a8e6eaa51a19a09311763a23e4857537* cl, cgtArray** Ax, cgtArray* y) {
                    cgtArray *A=Ax[0], *x=Ax[1];
                    int lda = A->shape()[1];
                    int M = A->shape()[0];
                    int N = A->shape()[1];
                    const float alpha=1, beta=0;
                    int incx = 1, incy = 1;
                  cblas_sgemv(CblasRowMajor, (CBLAS_TRANSPOSE)(cl->tA + 111), M, N, alpha, (float*)A->data(), lda, (float*)x->data(),
                      incx, beta, (float*)y->data(), incy);
                }
                
#include "cgt_common.h"
typedef struct closure_ced7981716a41ef9061a822153188a45 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
} closure_ced7981716a41ef9061a822153188a45;

            CGT_EXPORT_C cgtArray* call_ced7981716a41ef9061a822153188a45(closure_ced7981716a41ef9061a822153188a45* cldata, cgtArray** reads) {
                
                cgtDtype dtype = (cgtDtype) cldata->dtype ;
                cgtDevtype devtype = (cgtDevtype) cldata->devtype ;
                cgtArray *out = new cgtArray(cldata->ndim, (long*)cldata->shape, dtype, devtype, cldata->fromdata, false);
                return out ;
                //return *(cgtArray**)cldata->pptr;
            }
#include "cgt_common.h"
#include "string.h"

        using namespace std ;
        static inline float reduction_call_eafca26c937e64b4054053d1125297f8(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_eafca26c937e64b4054053d1125297f8(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) {
                float x = write->at<float>(0);
                float y = read->at<float>(i0) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0) = reduction_call_eafca26c937e64b4054053d1125297f8(x, y);
            }
        }
        
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_9fd4496473fe3a3242221eeff05628b0(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_9fd4496473fe3a3242221eeff05628b0(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9fd4496473fe3a3242221eeff05628b0(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_a2d013b07ef4c2f2e9a061a047a53a35(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_a2d013b07ef4c2f2e9a061a047a53a35(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_a2d013b07ef4c2f2e9a061a047a53a35(in0[i], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_9966c117a8e4fda64e742af7c30fa8c0(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_9966c117a8e4fda64e742af7c30fa8c0(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9966c117a8e4fda64e742af7c30fa8c0(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline int64_t scalar_call_0b761055c26c1913acfdaf3f306e5627(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_0b761055c26c1913acfdaf3f306e5627(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_0b761055c26c1913acfdaf3f306e5627(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_f220520ab58c05298ed3779039c9ea82(int8_t x, float y) {return x*y;}
                CGT_EXPORT_C void call_f220520ab58c05298ed3779039c9ea82(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int8_t* in0 = (int8_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_f220520ab58c05298ed3779039c9ea82(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_8f5ee6a4fd7c82dd9729d27e86439821(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_8f5ee6a4fd7c82dd9729d27e86439821(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8f5ee6a4fd7c82dd9729d27e86439821(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"

            CGT_EXPORT_C void call_2f722e24ca68ec28b3f26cecb59acb9f(void**, cgtArray** xk, cgtArray* z) {
                cgtArray *x=xk[0], *k=xk[1];
                for (int i=0; i < z->size(); ++i) {
                    z->at<float>(i) = x->at<float>(k->at<long>(i));
                }
            }
            
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_9b0f92c8d25a16795c3febb42920924b(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_9b0f92c8d25a16795c3febb42920924b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9b0f92c8d25a16795c3febb42920924b(in0[i], in1[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                static inline float scalar_call_8cb199057ec55cb2f32fbbbf1b7b309e(float x) {return log(x);}
                CGT_EXPORT_C void call_8cb199057ec55cb2f32fbbbf1b7b309e(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_8cb199057ec55cb2f32fbbbf1b7b309e(readdata[i]);
                    }
                }
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline float scalar_call_41f2941c7d335e82888a7cb0b3f6eb8f(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_41f2941c7d335e82888a7cb0b3f6eb8f(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_41f2941c7d335e82888a7cb0b3f6eb8f(in0[0], in1[0]);
                    }
                }
#include "cgt_common.h"
typedef struct closure_627ef1a951e161ff788118f4f8969b0d {
int ndim;
} closure_627ef1a951e161ff788118f4f8969b0d;

            CGT_EXPORT_C cgtArray* call_627ef1a951e161ff788118f4f8969b0d(closure_627ef1a951e161ff788118f4f8969b0d* cldata, cgtArray** reads) {
                cgtArray* in = reads[0];
                long* newshape = new long[cldata->ndim];
                for (int i=0; i < cldata->ndim; ++i) {
                    long s = reads[i+1]->at<long>(0);
                    newshape[i] = static_cast<long*>(reads[i+1]->data())[0];
                    cgt_assert((newshape[i] >= 0) && "negative size in reshape not supported");
                }
                cgtArray* out = new cgtArray(cldata->ndim, newshape, in->dtype(), in->devtype(), in->data(), false);
                return out;
            }
            
#include "cgt_common.h"
#include "math.h"

                #include<iostream>
                static inline int8_t scalar_call_76676c0c6d7bc2c6e22758b906d37712(float x, int64_t y) {return x>=y;}
                CGT_EXPORT_C void call_76676c0c6d7bc2c6e22758b906d37712(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_76676c0c6d7bc2c6e22758b906d37712(in0[i], in1[0]);
                    }
                }
#include "cgt_common.h"
#include "string.h"

        using namespace std ;
        static inline float reduction_call_cd8a42d1a1a189a9a5590b8037fba3f6(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_cd8a42d1a1a189a9a5590b8037fba3f6(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,0) = reduction_call_cd8a42d1a1a189a9a5590b8037fba3f6(x, y);
            }}
        }
        
#include "cgt_common.h"
#include "math.h"

                static inline float scalar_call_ad2d4f2befcb0d541ef73cca1570b00d(float x) {return exp(x);}
                CGT_EXPORT_C void call_ad2d4f2befcb0d541ef73cca1570b00d(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_ad2d4f2befcb0d541ef73cca1570b00d(readdata[i]);
                    }
                }
#include "cgt_common.h"
#include "cblas.h"
typedef struct closure_973b98f8826d24cd562a02ff5a79bee6 {
bool tA;
bool tB;
void* handle;
} closure_973b98f8826d24cd562a02ff5a79bee6;

                CGT_EXPORT_C void call_973b98f8826d24cd562a02ff5a79bee6(closure_973b98f8826d24cd562a02ff5a79bee6* cl, cgtArray** AB, cgtArray* C) {
                    cgtArray *A=AB[0], *B=AB[1];
                    int lda = A->shape()[1], ldb = B->shape()[1], ldc = C->shape()[1];
                    int M = C->shape()[0];
                    int N = C->shape()[1];
                    int K = A->shape()[cl->tA ? 0 : 1];
                    const float alpha=1, beta=0;
                  cblas_sgemm(CblasRowMajor, (CBLAS_TRANSPOSE)(cl->tA + 111), (CBLAS_TRANSPOSE)(cl->tB + 111), M, N, K, alpha, (float*)A->data(), lda, (float*)B->data(),
                      ldb, beta, (float*)C->data(), ldc);
                }
                

#include<map>

std::map<std::string, void *> fmap;


void create_functions_map(){

	fmap["call_f9255658e60a2f311a374964fa909aab"] = (void *) &call_f9255658e60a2f311a374964fa909aab ; 
	fmap["call_acf21bff0d87db1480fd9f44dbb01744"] = (void *) &call_acf21bff0d87db1480fd9f44dbb01744 ; 
	fmap["call_1346fce5ddd6517ee0c556c24438a685"] = (void *) &call_1346fce5ddd6517ee0c556c24438a685 ; 
	fmap["call_e70024f2d2f2197f4e868709be40790e"] = (void *) &call_e70024f2d2f2197f4e868709be40790e ; 
	fmap["call_3571c1db4b7ec367015133339a08488e"] = (void *) &call_3571c1db4b7ec367015133339a08488e ; 
	fmap["call_fc058bee187972eb84b3bf5f998e4c2c"] = (void *) &call_fc058bee187972eb84b3bf5f998e4c2c ; 
	fmap["call_377edd6bc778d8d351c7d2481e0d043b"] = (void *) &call_377edd6bc778d8d351c7d2481e0d043b ; 
	fmap["call_ad1488cf4dc7245ba68a8e34f05f5773"] = (void *) &call_ad1488cf4dc7245ba68a8e34f05f5773 ; 
	fmap["call_1d73b0b14c11996deb1caa8267af6a78"] = (void *) &call_1d73b0b14c11996deb1caa8267af6a78 ; 
	fmap["call_2822c07acfde5ee13a7fa554778e4fcf"] = (void *) &call_2822c07acfde5ee13a7fa554778e4fcf ; 
	fmap["call_960ddb616081d55826d0d2ed97b532c4"] = (void *) &call_960ddb616081d55826d0d2ed97b532c4 ; 
	fmap["call_f00b0648901f586735a69d8e8d71081b"] = (void *) &call_f00b0648901f586735a69d8e8d71081b ; 
	fmap["call_60374604bcb1913f2624c58f384f0cf5"] = (void *) &call_60374604bcb1913f2624c58f384f0cf5 ; 
	fmap["call_72da8db18ab69840269cdb7c6df936b5"] = (void *) &call_72da8db18ab69840269cdb7c6df936b5 ; 
	fmap["call_a8e6eaa51a19a09311763a23e4857537"] = (void *) &call_a8e6eaa51a19a09311763a23e4857537 ; 
	fmap["call_ced7981716a41ef9061a822153188a45"] = (void *) &call_ced7981716a41ef9061a822153188a45 ; 
	fmap["call_eafca26c937e64b4054053d1125297f8"] = (void *) &call_eafca26c937e64b4054053d1125297f8 ; 
	fmap["call_9fd4496473fe3a3242221eeff05628b0"] = (void *) &call_9fd4496473fe3a3242221eeff05628b0 ; 
	fmap["call_a2d013b07ef4c2f2e9a061a047a53a35"] = (void *) &call_a2d013b07ef4c2f2e9a061a047a53a35 ; 
	fmap["call_9966c117a8e4fda64e742af7c30fa8c0"] = (void *) &call_9966c117a8e4fda64e742af7c30fa8c0 ; 
	fmap["call_0b761055c26c1913acfdaf3f306e5627"] = (void *) &call_0b761055c26c1913acfdaf3f306e5627 ; 
	fmap["call_f220520ab58c05298ed3779039c9ea82"] = (void *) &call_f220520ab58c05298ed3779039c9ea82 ; 
	fmap["call_8f5ee6a4fd7c82dd9729d27e86439821"] = (void *) &call_8f5ee6a4fd7c82dd9729d27e86439821 ; 
	fmap["call_2f722e24ca68ec28b3f26cecb59acb9f"] = (void *) &call_2f722e24ca68ec28b3f26cecb59acb9f ; 
	fmap["call_9b0f92c8d25a16795c3febb42920924b"] = (void *) &call_9b0f92c8d25a16795c3febb42920924b ; 
	fmap["call_8cb199057ec55cb2f32fbbbf1b7b309e"] = (void *) &call_8cb199057ec55cb2f32fbbbf1b7b309e ; 
	fmap["call_41f2941c7d335e82888a7cb0b3f6eb8f"] = (void *) &call_41f2941c7d335e82888a7cb0b3f6eb8f ; 
	fmap["call_627ef1a951e161ff788118f4f8969b0d"] = (void *) &call_627ef1a951e161ff788118f4f8969b0d ; 
	fmap["call_76676c0c6d7bc2c6e22758b906d37712"] = (void *) &call_76676c0c6d7bc2c6e22758b906d37712 ; 
	fmap["call_cd8a42d1a1a189a9a5590b8037fba3f6"] = (void *) &call_cd8a42d1a1a189a9a5590b8037fba3f6 ; 
	fmap["call_ad2d4f2befcb0d541ef73cca1570b00d"] = (void *) &call_ad2d4f2befcb0d541ef73cca1570b00d ; 
	fmap["call_973b98f8826d24cd562a02ff5a79bee6"] = (void *) &call_973b98f8826d24cd562a02ff5a79bee6 ; 

}
