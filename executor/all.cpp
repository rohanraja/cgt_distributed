#include "cgt_common.h"

#include "math.h"

                #include<iostream>

#include "im2col.h"

#include "string.h"

#include "pooling.h"

#include "iostream"

#include "limits"

            #include<iostream>

#include "cblas.h"

#include<map>

typedef struct closure_a5ae98d392f5aa50dafe08bd27572ed4 {
double value;
} closure_a5ae98d392f5aa50dafe08bd27572ed4;

            CGT_EXPORT_C void call_a5ae98d392f5aa50dafe08bd27572ed4(closure_a5ae98d392f5aa50dafe08bd27572ed4* cldata, cgtArray** reads, cgtArray* write) {
                long s = write->size();
                float value = cldata->value;
                for (int i=0; i < s; ++i) write->at<float>(i) = value;
            }

                static inline float scalar_call_aa7098cd2f06db362615b9b2831f95a9(int64_t x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_aa7098cd2f06db362615b9b2831f95a9(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_aa7098cd2f06db362615b9b2831f95a9(in0[0], in1[0]);
                    }
                }

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

                static inline int64_t scalar_call_19aa925cd5a138c016e54c3c342bbcbf(float x) {return (int)ceil(x);}
                CGT_EXPORT_C void call_19aa925cd5a138c016e54c3c342bbcbf(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_19aa925cd5a138c016e54c3c342bbcbf(readdata[i]);
                    }
                }

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
typedef struct closure_9fd904cdca27f3325fefa612e5d9d867 {
int kernel_h;
int kernel_w;
int pad_h;
int pad_w;
int stride_h;
int stride_w;
} closure_9fd904cdca27f3325fefa612e5d9d867;

            CGT_EXPORT_C void call_9fd904cdca27f3325fefa612e5d9d867(closure_9fd904cdca27f3325fefa612e5d9d867* cl, cgtArray** reads, cgtArray* write) {
                cgtArray* im = reads[0];
                const long* imshape = im->shape();
                int batchsize = imshape[0],
                    channels = imshape[1],
                    height = imshape[2],
                    width = imshape[3];
                for (int i=0; i < batchsize; ++i) {
                    im2col_cpu<float, 3,3,1,1,1,1>
                    ((float*)im->data() + im->stride(0)*i, channels, height, width, (float*)write->data() + write->stride(0)*i);
                }
            }

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
        
typedef struct closure_377edd6bc778d8d351c7d2481e0d043b {
int ndim;
void* shape;
uint8_t dtype;
void* data;
} closure_377edd6bc778d8d351c7d2481e0d043b;

            CGT_EXPORT_C void call_377edd6bc778d8d351c7d2481e0d043b(closure_377edd6bc778d8d351c7d2481e0d043b* cldata, cgtArray** reads, cgtArray* write) {
                cgt_memcpy(cgtCPU, cgtCPU, write->data(), cldata->data, write->nbytes());
            }
            

            CGT_EXPORT_C void call_ad1488cf4dc7245ba68a8e34f05f5773(void**, cgtArray** xkp, cgtArray* write) {
                cgtArray *x=xkp[0], *k=xkp[1], *p=xkp[2];
                if (write->data() != x->data()) cgt_memcpy(cgtCPU, cgtCPU, write, x, write->nbytes());
                for (int i=0; i < p->size(); ++i) {
                    write->at<float>(k->at<long>(i)) += p->at<float>(i);
                }
            }
            

            CGT_EXPORT_C void call_1f4a7b91f89e6776cf659d80159e9c9d(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) {
                    write->at<float>(i0) = read->at<float>(0);
                }
            }
            

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

            CGT_EXPORT_C void call_2822c07acfde5ee13a7fa554778e4fcf(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = read->at<float>(i0,0);
                }}
            }
            

                static inline int64_t scalar_call_b5a543221a311e3c742b1f7bd90af814(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_b5a543221a311e3c742b1f7bd90af814(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_b5a543221a311e3c742b1f7bd90af814(in0[i], in1[i]);
                    }
                }

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

            CGT_EXPORT_C void call_5af903fc63dbd48aeaa50153616b45b3(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read = reads[0];
                float* indata = (float*)read->data(), *outdata = (float*)write->data();
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) { for (int i2=0; i2 < write->shape()[2]; ++i2) { for (int i3=0; i3 < write->shape()[3]; ++i3) {
                    write->at<float>(i0,i1,i2,i3) = read->at<float>(i0,i2,i3,i1);
                }}}}
            }

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

                static inline int64_t scalar_call_de06a0177f85cb9521e81e81be5490ee(float x) {return (int)floor(x);}
                CGT_EXPORT_C void call_de06a0177f85cb9521e81e81be5490ee(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_de06a0177f85cb9521e81e81be5490ee(readdata[i]);
                    }
                }

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

            CGT_EXPORT_C void call_d7abdd2089e597538ddfdfd5035398c5(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read = reads[0];
                float* indata = (float*)read->data(), *outdata = (float*)write->data();
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) { for (int i2=0; i2 < write->shape()[2]; ++i2) { for (int i3=0; i3 < write->shape()[3]; ++i3) {
                    write->at<float>(i0,i1,i2,i3) = read->at<float>(i0,i3,i1,i2);
                }}}}
            }

                static inline int64_t scalar_call_684d70ccfe67436367ae5b19a34d70db(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_684d70ccfe67436367ae5b19a34d70db(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_684d70ccfe67436367ae5b19a34d70db(in0[0], in1[0]);
                    }
                }

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
typedef struct closure_db27808c9fdd01fdad6f76448df212c7 {
int kernel_h;
int kernel_w;
int pad_h;
int pad_w;
int stride_h;
int stride_w;
} closure_db27808c9fdd01fdad6f76448df212c7;

CGT_EXPORT_C void call_db27808c9fdd01fdad6f76448df212c7(conv_closure* cl, cgtArray** reads, cgtTuple* write) {
    max_pool<float>(cl, reads[0], static_cast<cgtArray*>(write->getitem(0)), static_cast<cgtArray*>(write->getitem(1)));
}

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

                static inline int8_t scalar_call_9ae09d7f3b207f9f1bd2f643dcb985b3(int64_t x, int64_t y) {return x!=y;}
                CGT_EXPORT_C void call_9ae09d7f3b207f9f1bd2f643dcb985b3(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9ae09d7f3b207f9f1bd2f643dcb985b3(in0[i], in1[i]);
                    }
                }

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

                static inline float scalar_call_fdbc35e554751dbc308b47c1295591c8(float x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_fdbc35e554751dbc308b47c1295591c8(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_fdbc35e554751dbc308b47c1295591c8(in0[0], in1[0]);
                    }
                }

                static inline int64_t scalar_call_ee7fbeb9b48f81f8be4b1635a23e1c14(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_ee7fbeb9b48f81f8be4b1635a23e1c14(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ee7fbeb9b48f81f8be4b1635a23e1c14(in0[0], in1[i]);
                    }
                }

                static inline float scalar_call_279ab4f35a5d4cb06d16fc04bc465f16(float x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_279ab4f35a5d4cb06d16fc04bc465f16(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_279ab4f35a5d4cb06d16fc04bc465f16(in0[i], in1[0]);
                    }
                }

        using namespace std ;
        #define otype long
        #define itype float

        static inline otype reduction_call_72336d178d3d571059cec482dd52df9a(otype x, itype y) {return fmax(x,y);}
        
        CGT_EXPORT_C void call_72336d178d3d571059cec482dd52df9a(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            otype arg_max = -1 ;
            itype max_val = -std::numeric_limits<float>::min() ;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                itype y = read->at<itype>(i0,i1) ;
                if(i1 == 0)
                    max_val = -std::numeric_limits<float>::min() ;

                if(y > max_val){
                    max_val = y;
                    write->at<otype>(0,i0) = i1;
                }
            }}
        }
        

            CGT_EXPORT_C void call_2f722e24ca68ec28b3f26cecb59acb9f(void**, cgtArray** xk, cgtArray* z) {
                cgtArray *x=xk[0], *k=xk[1];
                for (int i=0; i < z->size(); ++i) {
                    z->at<float>(i) = x->at<float>(k->at<long>(i));
                }
            }
            
typedef struct closure_abdc5d1dd36f5b3766aa4a4be6ff713d {
int idx;
} closure_abdc5d1dd36f5b3766aa4a4be6ff713d;

            CGT_EXPORT_C cgtObject* call_abdc5d1dd36f5b3766aa4a4be6ff713d(closure_abdc5d1dd36f5b3766aa4a4be6ff713d* cldata, cgtTuple** reads) {
                return reads[0]->getitem(cldata->idx);
            }

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
            

                static inline float scalar_call_0f464f048a7c709f27b64ab52f580fec(int8_t x) {return x;}
                CGT_EXPORT_C void call_0f464f048a7c709f27b64ab52f580fec(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    int8_t* readdata = (int8_t*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_0f464f048a7c709f27b64ab52f580fec(readdata[i]);
                    }
                }
typedef struct closure_d4be1fb9d81d2aae82e40ac68f3d2843 {
int kernel_h;
int kernel_w;
int pad_h;
int pad_w;
int stride_h;
int stride_w;
} closure_d4be1fb9d81d2aae82e40ac68f3d2843;

            CGT_EXPORT_C void call_d4be1fb9d81d2aae82e40ac68f3d2843(closure_d4be1fb9d81d2aae82e40ac68f3d2843* cl, cgtArray** reads, cgtArray* write) {
                cgtArray* col = reads[0];
                long batchsize = reads[1]->at<long>(0),
                       channels  = reads[2]->at<long>(0),
                       height    = reads[3]->at<long>(0),
                       width     = reads[4]->at<long>(0);
                for (int i=0; i < batchsize; ++i) {
                    col2im_cpu<float, 3,3,1,1,1,1>
                    ((float*)col->data() + col->stride(0)*i, channels, height, width,(float*)write->data() + write->stride(0)*i);
                }
            }

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
typedef struct closure_dd0180309f63cef5e3d98ce087819bbe {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_dd0180309f63cef5e3d98ce087819bbe;


            CGT_EXPORT_C cgtArray* call_dd0180309f63cef5e3d98ce087819bbe(closure_dd0180309f63cef5e3d98ce087819bbe* cldata, cgtArray** reads) {
                
                if( *((long*)cldata->pptr) == 0)
                {
                    //std::cout << "\n***\nALLOCATING NEW MEMORY FOR INMEMORY DATA\n***\n" ;
                    //std::cout << cldata->pptr;

                    cgtDtype dtype = (cgtDtype) cldata->dtype ;
                    cgtDevtype devtype = (cgtDevtype) cldata->devtype ;
                    cgtArray *out = new cgtArray(cldata->ndim, (long*)cldata->shape, dtype, devtype, cldata->fromdata, false);
                    *((cgtArray**)cldata->pptr) = out;
                    return out ;
                }else
                    return *(cgtArray**)cldata->pptr;
            }

            CGT_EXPORT_C cgtArray* call_1941946d5c1745efbfc340f945e268d0(void* cldata, cgtArray** reads) {
                long start=reads[0]->at<long>(0),
                       stop=reads[1]->at<long>(0),
                       step=reads[2]->at<long>(0);
                long size = (stop-start)/step;
                cgtArray* out = new cgtArray(1, &size, cgt_i8, cgtCPU);
                for (int i=0; i < size; ++i) out->at<long>(i) = start+i*step;
                return out;
            }

                static inline int8_t scalar_call_edc9848dde4736824c96aa6b879e7e15(int64_t x, int64_t y) {return x==y;}
                CGT_EXPORT_C void call_edc9848dde4736824c96aa6b879e7e15(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_edc9848dde4736824c96aa6b879e7e15(in0[i], in1[i]);
                    }
                }

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
                
typedef struct closure_6720382d349d67e9bd42b13a4a90b8d9 {
int kernel_h;
int kernel_w;
int pad_h;
int pad_w;
int stride_h;
int stride_w;
} closure_6720382d349d67e9bd42b13a4a90b8d9;

CGT_EXPORT_C void call_6720382d349d67e9bd42b13a4a90b8d9(conv_closure* cl, cgtArray** reads, cgtArray* write) {
    max_pool_pullback<float>(reads[0], reads[1], reads[2], reads[3], write);
}


std::map<std::string, void *> fmap;


void create_functions_map(){

	fmap["call_a5ae98d392f5aa50dafe08bd27572ed4"] = (void *) &call_a5ae98d392f5aa50dafe08bd27572ed4 ; 
	fmap["call_aa7098cd2f06db362615b9b2831f95a9"] = (void *) &call_aa7098cd2f06db362615b9b2831f95a9 ; 
	fmap["call_f9255658e60a2f311a374964fa909aab"] = (void *) &call_f9255658e60a2f311a374964fa909aab ; 
	fmap["call_19aa925cd5a138c016e54c3c342bbcbf"] = (void *) &call_19aa925cd5a138c016e54c3c342bbcbf ; 
	fmap["call_acf21bff0d87db1480fd9f44dbb01744"] = (void *) &call_acf21bff0d87db1480fd9f44dbb01744 ; 
	fmap["call_1346fce5ddd6517ee0c556c24438a685"] = (void *) &call_1346fce5ddd6517ee0c556c24438a685 ; 
	fmap["call_e70024f2d2f2197f4e868709be40790e"] = (void *) &call_e70024f2d2f2197f4e868709be40790e ; 
	fmap["call_9fd904cdca27f3325fefa612e5d9d867"] = (void *) &call_9fd904cdca27f3325fefa612e5d9d867 ; 
	fmap["call_3571c1db4b7ec367015133339a08488e"] = (void *) &call_3571c1db4b7ec367015133339a08488e ; 
	fmap["call_fc058bee187972eb84b3bf5f998e4c2c"] = (void *) &call_fc058bee187972eb84b3bf5f998e4c2c ; 
	fmap["call_377edd6bc778d8d351c7d2481e0d043b"] = (void *) &call_377edd6bc778d8d351c7d2481e0d043b ; 
	fmap["call_ad1488cf4dc7245ba68a8e34f05f5773"] = (void *) &call_ad1488cf4dc7245ba68a8e34f05f5773 ; 
	fmap["call_1f4a7b91f89e6776cf659d80159e9c9d"] = (void *) &call_1f4a7b91f89e6776cf659d80159e9c9d ; 
	fmap["call_1d73b0b14c11996deb1caa8267af6a78"] = (void *) &call_1d73b0b14c11996deb1caa8267af6a78 ; 
	fmap["call_2822c07acfde5ee13a7fa554778e4fcf"] = (void *) &call_2822c07acfde5ee13a7fa554778e4fcf ; 
	fmap["call_b5a543221a311e3c742b1f7bd90af814"] = (void *) &call_b5a543221a311e3c742b1f7bd90af814 ; 
	fmap["call_960ddb616081d55826d0d2ed97b532c4"] = (void *) &call_960ddb616081d55826d0d2ed97b532c4 ; 
	fmap["call_5af903fc63dbd48aeaa50153616b45b3"] = (void *) &call_5af903fc63dbd48aeaa50153616b45b3 ; 
	fmap["call_f00b0648901f586735a69d8e8d71081b"] = (void *) &call_f00b0648901f586735a69d8e8d71081b ; 
	fmap["call_de06a0177f85cb9521e81e81be5490ee"] = (void *) &call_de06a0177f85cb9521e81e81be5490ee ; 
	fmap["call_60374604bcb1913f2624c58f384f0cf5"] = (void *) &call_60374604bcb1913f2624c58f384f0cf5 ; 
	fmap["call_72da8db18ab69840269cdb7c6df936b5"] = (void *) &call_72da8db18ab69840269cdb7c6df936b5 ; 
	fmap["call_d7abdd2089e597538ddfdfd5035398c5"] = (void *) &call_d7abdd2089e597538ddfdfd5035398c5 ; 
	fmap["call_684d70ccfe67436367ae5b19a34d70db"] = (void *) &call_684d70ccfe67436367ae5b19a34d70db ; 
	fmap["call_eafca26c937e64b4054053d1125297f8"] = (void *) &call_eafca26c937e64b4054053d1125297f8 ; 
	fmap["call_9fd4496473fe3a3242221eeff05628b0"] = (void *) &call_9fd4496473fe3a3242221eeff05628b0 ; 
	fmap["call_db27808c9fdd01fdad6f76448df212c7"] = (void *) &call_db27808c9fdd01fdad6f76448df212c7 ; 
	fmap["call_a2d013b07ef4c2f2e9a061a047a53a35"] = (void *) &call_a2d013b07ef4c2f2e9a061a047a53a35 ; 
	fmap["call_9ae09d7f3b207f9f1bd2f643dcb985b3"] = (void *) &call_9ae09d7f3b207f9f1bd2f643dcb985b3 ; 
	fmap["call_0b761055c26c1913acfdaf3f306e5627"] = (void *) &call_0b761055c26c1913acfdaf3f306e5627 ; 
	fmap["call_f220520ab58c05298ed3779039c9ea82"] = (void *) &call_f220520ab58c05298ed3779039c9ea82 ; 
	fmap["call_fdbc35e554751dbc308b47c1295591c8"] = (void *) &call_fdbc35e554751dbc308b47c1295591c8 ; 
	fmap["call_ee7fbeb9b48f81f8be4b1635a23e1c14"] = (void *) &call_ee7fbeb9b48f81f8be4b1635a23e1c14 ; 
	fmap["call_279ab4f35a5d4cb06d16fc04bc465f16"] = (void *) &call_279ab4f35a5d4cb06d16fc04bc465f16 ; 
	fmap["call_72336d178d3d571059cec482dd52df9a"] = (void *) &call_72336d178d3d571059cec482dd52df9a ; 
	fmap["call_2f722e24ca68ec28b3f26cecb59acb9f"] = (void *) &call_2f722e24ca68ec28b3f26cecb59acb9f ; 
	fmap["call_abdc5d1dd36f5b3766aa4a4be6ff713d"] = (void *) &call_abdc5d1dd36f5b3766aa4a4be6ff713d ; 
	fmap["call_9b0f92c8d25a16795c3febb42920924b"] = (void *) &call_9b0f92c8d25a16795c3febb42920924b ; 
	fmap["call_8cb199057ec55cb2f32fbbbf1b7b309e"] = (void *) &call_8cb199057ec55cb2f32fbbbf1b7b309e ; 
	fmap["call_627ef1a951e161ff788118f4f8969b0d"] = (void *) &call_627ef1a951e161ff788118f4f8969b0d ; 
	fmap["call_0f464f048a7c709f27b64ab52f580fec"] = (void *) &call_0f464f048a7c709f27b64ab52f580fec ; 
	fmap["call_d4be1fb9d81d2aae82e40ac68f3d2843"] = (void *) &call_d4be1fb9d81d2aae82e40ac68f3d2843 ; 
	fmap["call_76676c0c6d7bc2c6e22758b906d37712"] = (void *) &call_76676c0c6d7bc2c6e22758b906d37712 ; 
	fmap["call_dd0180309f63cef5e3d98ce087819bbe"] = (void *) &call_dd0180309f63cef5e3d98ce087819bbe ; 
	fmap["call_1941946d5c1745efbfc340f945e268d0"] = (void *) &call_1941946d5c1745efbfc340f945e268d0 ; 
	fmap["call_edc9848dde4736824c96aa6b879e7e15"] = (void *) &call_edc9848dde4736824c96aa6b879e7e15 ; 
	fmap["call_ad2d4f2befcb0d541ef73cca1570b00d"] = (void *) &call_ad2d4f2befcb0d541ef73cca1570b00d ; 
	fmap["call_973b98f8826d24cd562a02ff5a79bee6"] = (void *) &call_973b98f8826d24cd562a02ff5a79bee6 ; 
	fmap["call_6720382d349d67e9bd42b13a4a90b8d9"] = (void *) &call_6720382d349d67e9bd42b13a4a90b8d9 ; 

}
