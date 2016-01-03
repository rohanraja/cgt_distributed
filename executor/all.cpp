#include "cgt_common.h"

#include "math.h"

                #include<iostream>

#include "cblas.h"

            #include<iostream>

#include "string.h"

#include "iostream"

#include "limits"

#include<map>


                static inline float scalar_call_00914cbe71181f85859917d0afbd6fa4(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_00914cbe71181f85859917d0afbd6fa4(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_00914cbe71181f85859917d0afbd6fa4(in0[i], in1[i]);
                    }
                }

                static inline float scalar_call_01ea73a67790f024647388b85086685a(float x) {return exp(x);}
                CGT_EXPORT_C void call_01ea73a67790f024647388b85086685a(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_01ea73a67790f024647388b85086685a(readdata[i]);
                    }
                }

                static inline float scalar_call_0486a7d8d91ec22cdaff5147b528f1be(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_0486a7d8d91ec22cdaff5147b528f1be(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_0486a7d8d91ec22cdaff5147b528f1be(in0[i], in1[i]);
                    }
                }
typedef struct closure_0c6c7064d1b67674b42721dcf159e554 {
int ax;
} closure_0c6c7064d1b67674b42721dcf159e554;

            CGT_EXPORT_C cgtArray* call_0c6c7064d1b67674b42721dcf159e554(void* cl0, cgtArray** reads) {
                closure_0c6c7064d1b67674b42721dcf159e554* cl = (closure_0c6c7064d1b67674b42721dcf159e554*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline float scalar_call_0e757cd60b7235565b009c7f90c5ce62(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_0e757cd60b7235565b009c7f90c5ce62(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_0e757cd60b7235565b009c7f90c5ce62(in0[i], in1[0]);
                    }
                }
typedef struct closure_116c98fe90386fc618a04137cd19b63d {
bool tA;
bool tB;
void* handle;
} closure_116c98fe90386fc618a04137cd19b63d;

                CGT_EXPORT_C void call_116c98fe90386fc618a04137cd19b63d(closure_116c98fe90386fc618a04137cd19b63d* cl, cgtArray** AB, cgtArray* C) {
                    cgtArray *A=AB[0], *B=AB[1];
                    int lda = A->shape()[1], ldb = B->shape()[1], ldc = C->shape()[1];
                    int M = C->shape()[0];
                    int N = C->shape()[1];
                    int K = A->shape()[cl->tA ? 0 : 1];
                    const float alpha=1, beta=0;
                  cblas_sgemm(CblasRowMajor, (CBLAS_TRANSPOSE)(cl->tA + 111), (CBLAS_TRANSPOSE)(cl->tB + 111), M, N, K, alpha, (float*)A->data(), lda, (float*)B->data(),
                      ldb, beta, (float*)C->data(), ldc);
                }
                

                static inline int64_t scalar_call_178591db5c7372022010d2a67a9b7657(float x) {return (int)floor(x);}
                CGT_EXPORT_C void call_178591db5c7372022010d2a67a9b7657(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_178591db5c7372022010d2a67a9b7657(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_2a8b57ddc17094fa96c60ef7ad664593(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) {
                    write->at<float>(i0) = read->at<float>(0);
                }
            }
            

                static inline float scalar_call_2e5636f9ee548a895307078ff481642b(float x, float y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_2e5636f9ee548a895307078ff481642b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_2e5636f9ee548a895307078ff481642b(in0[i], in1[i]);
                    }
                }

                static inline float scalar_call_3612a30b453dc657d8c1aac4ab6bffb8(int8_t x, float y) {return x*y;}
                CGT_EXPORT_C void call_3612a30b453dc657d8c1aac4ab6bffb8(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int8_t* in0 = (int8_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3612a30b453dc657d8c1aac4ab6bffb8(in0[i], in1[i]);
                    }
                }

            CGT_EXPORT_C void call_36d491c15f6159cd25a33ad4d2262584(void**, cgtArray** xk, cgtArray* z) {
                cgtArray *x=xk[0], *k=xk[1];
                for (int i=0; i < z->size(); ++i) {
                    z->at<float>(i) = x->at<float>(k->at<long>(i));
                }
            }
            
typedef struct closure_3c244bf4129a80c0a2e0b28d2c64827f {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_3c244bf4129a80c0a2e0b28d2c64827f;


            CGT_EXPORT_C cgtArray* call_3c244bf4129a80c0a2e0b28d2c64827f(closure_3c244bf4129a80c0a2e0b28d2c64827f* cldata, cgtArray** reads) {
                
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

            CGT_EXPORT_C void call_3f2152dbb82fc3bd6f125e49e35f7163(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = read->at<float>(i0,0);
                }}
            }
            

                static inline float scalar_call_41dec2fc4c17214cd47d4607fef1b7c3(float x) {return log(x);}
                CGT_EXPORT_C void call_41dec2fc4c17214cd47d4607fef1b7c3(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_41dec2fc4c17214cd47d4607fef1b7c3(readdata[i]);
                    }
                }

                static inline float scalar_call_4cc1602fdb29f1c37ecb5d02fb599ca7(float x, int8_t y) {return x*y;}
                CGT_EXPORT_C void call_4cc1602fdb29f1c37ecb5d02fb599ca7(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int8_t* in1 = (int8_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_4cc1602fdb29f1c37ecb5d02fb599ca7(in0[i], in1[i]);
                    }
                }

                static inline int8_t scalar_call_5276e4197cd56cac0d3a38c53298e890(int64_t x, int64_t y) {return x==y;}
                CGT_EXPORT_C void call_5276e4197cd56cac0d3a38c53298e890(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_5276e4197cd56cac0d3a38c53298e890(in0[i], in1[i]);
                    }
                }

                static inline float scalar_call_5985a55ad132563945f92851e9b93973(float x) {return x*x;}
                CGT_EXPORT_C void call_5985a55ad132563945f92851e9b93973(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_5985a55ad132563945f92851e9b93973(readdata[i]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_654893363f89562cd042919f7d1efc24(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_654893363f89562cd042919f7d1efc24(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) {
                float x = write->at<float>(0);
                float y = read->at<float>(i0) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0) = reduction_call_654893363f89562cd042919f7d1efc24(x, y);
            }
        }
        

                static inline float scalar_call_6942516ef96064da1e2901a047a92859(float x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_6942516ef96064da1e2901a047a92859(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_6942516ef96064da1e2901a047a92859(in0[0], in1[0]);
                    }
                }

                static inline float scalar_call_6cf598e930fe44f238860b9128685441(int8_t x) {return x;}
                CGT_EXPORT_C void call_6cf598e930fe44f238860b9128685441(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    int8_t* readdata = (int8_t*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_6cf598e930fe44f238860b9128685441(readdata[i]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_98ab48d6ea6663d494105ded831e534a(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_98ab48d6ea6663d494105ded831e534a(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(i0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(i0,0) = reduction_call_98ab48d6ea6663d494105ded831e534a(x, y);
            }}
        }
        

                static inline int64_t scalar_call_a51b30884986af971213422277600489(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_a51b30884986af971213422277600489(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_a51b30884986af971213422277600489(in0[i], in1[i]);
                    }
                }

        using namespace std ;
        #define otype long
        #define itype float

        static inline otype reduction_call_a8df3af7cb5fe6faf9a0219ea6ca48cb(otype x, itype y) {return fmax(x,y);}
        
        CGT_EXPORT_C void call_a8df3af7cb5fe6faf9a0219ea6ca48cb(void* cldata, cgtArray** reads, cgtArray* write) {
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
        
typedef struct closure_b380ee0c312278649c5ffda6803d8d26 {
int ndim;
void* shape;
uint8_t dtype;
void* data;
} closure_b380ee0c312278649c5ffda6803d8d26;

            CGT_EXPORT_C void call_b380ee0c312278649c5ffda6803d8d26(closure_b380ee0c312278649c5ffda6803d8d26* cldata, cgtArray** reads, cgtArray* write) {
                cgt_memcpy(cgtCPU, cgtCPU, write->data(), cldata->data, write->nbytes());
            }
            

                static inline int64_t scalar_call_b965185d7179dad78ca8b04360615f33(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_b965185d7179dad78ca8b04360615f33(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_b965185d7179dad78ca8b04360615f33(in0[0], in1[i]);
                    }
                }

                static inline int64_t scalar_call_c630d03c28159edfd6b41e32b6133d0b(int64_t x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_c630d03c28159edfd6b41e32b6133d0b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_c630d03c28159edfd6b41e32b6133d0b(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C cgtArray* call_cdb74c65b31c8c9c808e6241378c9391(void* cldata, cgtArray** reads) {
                long start=reads[0]->at<long>(0),
                       stop=reads[1]->at<long>(0),
                       step=reads[2]->at<long>(0);
                long size = (stop-start)/step;
                cgtArray* out = new cgtArray(1, &size, cgt_i8, cgtCPU);
                for (int i=0; i < size; ++i) out->at<long>(i) = start+i*step;
                return out;
            }

                static inline float scalar_call_d315f97464ca63ecc5c6f08af8957f1b(float x) {return (-x);}
                CGT_EXPORT_C void call_d315f97464ca63ecc5c6f08af8957f1b(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_d315f97464ca63ecc5c6f08af8957f1b(readdata[i]);
                    }
                }

                static inline float scalar_call_d31c90b62cf90ba21fda300ed65b3115(float x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_d31c90b62cf90ba21fda300ed65b3115(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_d31c90b62cf90ba21fda300ed65b3115(in0[0], in1[0]);
                    }
                }

                static inline int8_t scalar_call_d94650c9f181b5719a909169c77653dc(float x, int64_t y) {return x>=y;}
                CGT_EXPORT_C void call_d94650c9f181b5719a909169c77653dc(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_d94650c9f181b5719a909169c77653dc(in0[i], in1[0]);
                    }
                }
typedef struct closure_df6ff67bdcd8961b3dc93e126e908cd4 {
double value;
} closure_df6ff67bdcd8961b3dc93e126e908cd4;

            CGT_EXPORT_C void call_df6ff67bdcd8961b3dc93e126e908cd4(closure_df6ff67bdcd8961b3dc93e126e908cd4* cldata, cgtArray** reads, cgtArray* write) {
                long s = write->size();
                float value = cldata->value;
                for (int i=0; i < s; ++i) write->at<float>(i) = value;
            }

                static inline float scalar_call_e561000695f157d5cbe9ce6a549a2efb(int64_t x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_e561000695f157d5cbe9ce6a549a2efb(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_e561000695f157d5cbe9ce6a549a2efb(in0[0], in1[0]);
                    }
                }
typedef struct closure_edd318b850a586afb3c52877b989a956 {
int ndim;
} closure_edd318b850a586afb3c52877b989a956;

            CGT_EXPORT_C cgtArray* call_edd318b850a586afb3c52877b989a956(closure_edd318b850a586afb3c52877b989a956* cldata, cgtArray** reads) {
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
            

                static inline float scalar_call_ef7ce0528df23ebd0d6b0b275eac2722(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_ef7ce0528df23ebd0d6b0b275eac2722(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ef7ce0528df23ebd0d6b0b275eac2722(in0[i], in1[i]);
                    }
                }

            CGT_EXPORT_C void call_fef23e677f07f08a3802edcc480fa2b8(void**, cgtArray** xkp, cgtArray* write) {
                cgtArray *x=xkp[0], *k=xkp[1], *p=xkp[2];
                if (write->data() != x->data()) cgt_memcpy(cgtCPU, cgtCPU, write, x, write->nbytes());
                for (int i=0; i < p->size(); ++i) {
                    write->at<float>(k->at<long>(i)) += p->at<float>(i);
                }
            }
            


std::map<std::string, void *> fmap;


void create_functions_map(){

	fmap["call_00914cbe71181f85859917d0afbd6fa4"] = (void *) &call_00914cbe71181f85859917d0afbd6fa4 ; 
	fmap["call_01ea73a67790f024647388b85086685a"] = (void *) &call_01ea73a67790f024647388b85086685a ; 
	fmap["call_0486a7d8d91ec22cdaff5147b528f1be"] = (void *) &call_0486a7d8d91ec22cdaff5147b528f1be ; 
	fmap["call_0c6c7064d1b67674b42721dcf159e554"] = (void *) &call_0c6c7064d1b67674b42721dcf159e554 ; 
	fmap["call_0e757cd60b7235565b009c7f90c5ce62"] = (void *) &call_0e757cd60b7235565b009c7f90c5ce62 ; 
	fmap["call_116c98fe90386fc618a04137cd19b63d"] = (void *) &call_116c98fe90386fc618a04137cd19b63d ; 
	fmap["call_178591db5c7372022010d2a67a9b7657"] = (void *) &call_178591db5c7372022010d2a67a9b7657 ; 
	fmap["call_2a8b57ddc17094fa96c60ef7ad664593"] = (void *) &call_2a8b57ddc17094fa96c60ef7ad664593 ; 
	fmap["call_2e5636f9ee548a895307078ff481642b"] = (void *) &call_2e5636f9ee548a895307078ff481642b ; 
	fmap["call_3612a30b453dc657d8c1aac4ab6bffb8"] = (void *) &call_3612a30b453dc657d8c1aac4ab6bffb8 ; 
	fmap["call_36d491c15f6159cd25a33ad4d2262584"] = (void *) &call_36d491c15f6159cd25a33ad4d2262584 ; 
	fmap["call_3c244bf4129a80c0a2e0b28d2c64827f"] = (void *) &call_3c244bf4129a80c0a2e0b28d2c64827f ; 
	fmap["call_3f2152dbb82fc3bd6f125e49e35f7163"] = (void *) &call_3f2152dbb82fc3bd6f125e49e35f7163 ; 
	fmap["call_41dec2fc4c17214cd47d4607fef1b7c3"] = (void *) &call_41dec2fc4c17214cd47d4607fef1b7c3 ; 
	fmap["call_4cc1602fdb29f1c37ecb5d02fb599ca7"] = (void *) &call_4cc1602fdb29f1c37ecb5d02fb599ca7 ; 
	fmap["call_5276e4197cd56cac0d3a38c53298e890"] = (void *) &call_5276e4197cd56cac0d3a38c53298e890 ; 
	fmap["call_5985a55ad132563945f92851e9b93973"] = (void *) &call_5985a55ad132563945f92851e9b93973 ; 
	fmap["call_654893363f89562cd042919f7d1efc24"] = (void *) &call_654893363f89562cd042919f7d1efc24 ; 
	fmap["call_6942516ef96064da1e2901a047a92859"] = (void *) &call_6942516ef96064da1e2901a047a92859 ; 
	fmap["call_6cf598e930fe44f238860b9128685441"] = (void *) &call_6cf598e930fe44f238860b9128685441 ; 
	fmap["call_98ab48d6ea6663d494105ded831e534a"] = (void *) &call_98ab48d6ea6663d494105ded831e534a ; 
	fmap["call_a51b30884986af971213422277600489"] = (void *) &call_a51b30884986af971213422277600489 ; 
	fmap["call_a8df3af7cb5fe6faf9a0219ea6ca48cb"] = (void *) &call_a8df3af7cb5fe6faf9a0219ea6ca48cb ; 
	fmap["call_b380ee0c312278649c5ffda6803d8d26"] = (void *) &call_b380ee0c312278649c5ffda6803d8d26 ; 
	fmap["call_b965185d7179dad78ca8b04360615f33"] = (void *) &call_b965185d7179dad78ca8b04360615f33 ; 
	fmap["call_c630d03c28159edfd6b41e32b6133d0b"] = (void *) &call_c630d03c28159edfd6b41e32b6133d0b ; 
	fmap["call_cdb74c65b31c8c9c808e6241378c9391"] = (void *) &call_cdb74c65b31c8c9c808e6241378c9391 ; 
	fmap["call_d315f97464ca63ecc5c6f08af8957f1b"] = (void *) &call_d315f97464ca63ecc5c6f08af8957f1b ; 
	fmap["call_d31c90b62cf90ba21fda300ed65b3115"] = (void *) &call_d31c90b62cf90ba21fda300ed65b3115 ; 
	fmap["call_d94650c9f181b5719a909169c77653dc"] = (void *) &call_d94650c9f181b5719a909169c77653dc ; 
	fmap["call_df6ff67bdcd8961b3dc93e126e908cd4"] = (void *) &call_df6ff67bdcd8961b3dc93e126e908cd4 ; 
	fmap["call_e561000695f157d5cbe9ce6a549a2efb"] = (void *) &call_e561000695f157d5cbe9ce6a549a2efb ; 
	fmap["call_edd318b850a586afb3c52877b989a956"] = (void *) &call_edd318b850a586afb3c52877b989a956 ; 
	fmap["call_ef7ce0528df23ebd0d6b0b275eac2722"] = (void *) &call_ef7ce0528df23ebd0d6b0b275eac2722 ; 
	fmap["call_fef23e677f07f08a3802edcc480fa2b8"] = (void *) &call_fef23e677f07f08a3802edcc480fa2b8 ; 

}
