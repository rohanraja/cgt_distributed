#include "cgt_common.h"

            #include<iostream>

#include "math.h"

                #include<iostream>

#include "string.h"

#include "cblas.h"

            //#include<iostream>

#include "iostream"

#include "limits"

#include<map>


typedef struct closure_0077a2258ab15bfa9cafda07748efe2d {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_0077a2258ab15bfa9cafda07748efe2d;


            CGT_EXPORT_C cgtArray* call_0077a2258ab15bfa9cafda07748efe2d(closure_0077a2258ab15bfa9cafda07748efe2d* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = \n" ;
                std::cout << cldata->ndim << "\n";
                //cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                //std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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
typedef struct closure_07446b7655dd180a91f826341a8b28ee {
int ax;
} closure_07446b7655dd180a91f826341a8b28ee;

            CGT_EXPORT_C cgtArray* call_07446b7655dd180a91f826341a8b28ee(void* cl0, cgtArray** reads) {
                closure_07446b7655dd180a91f826341a8b28ee* cl = (closure_07446b7655dd180a91f826341a8b28ee*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nIN = %ld\n", (long)(cl->ax));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

        using namespace std ;
        static inline float reduction_call_0762a8e46046b932520c160b35d4ec56(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_0762a8e46046b932520c160b35d4ec56(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            

            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(i0,0);
                float y = read->at<float>(i0,i1) ;
                write->at<float>(i0,0) = reduction_call_0762a8e46046b932520c160b35d4ec56(x, y);
            }}
    
        }
        
typedef struct closure_08f2981c4318710424b1d8548e5f2b0c {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_08f2981c4318710424b1d8548e5f2b0c;


            CGT_EXPORT_C cgtArray* call_08f2981c4318710424b1d8548e5f2b0c(closure_08f2981c4318710424b1d8548e5f2b0c* cldata, cgtArray** reads) {
                
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "\n^^^^^^^\n";
                tmp->print();
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

        using namespace std ;
        static inline float reduction_call_0984639e5104f291a73ac19a63801f4c(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_0984639e5104f291a73ac19a63801f4c(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,0) = reduction_call_0984639e5104f291a73ac19a63801f4c(x, y);
            }}
        }
        
typedef struct closure_0a0aa1b01ea5da675741b34fcff7a66a {
int ax;
} closure_0a0aa1b01ea5da675741b34fcff7a66a;

            CGT_EXPORT_C cgtArray* call_0a0aa1b01ea5da675741b34fcff7a66a(void* cl0, cgtArray** reads) {
                closure_0a0aa1b01ea5da675741b34fcff7a66a* cl = (closure_0a0aa1b01ea5da675741b34fcff7a66a*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nShapePtr = %ld\n", (long)(in->ndim() ));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline double scalar_call_0b93c838349c5f53e28cc2863cf54f7e(double x) {return sin(x);}
                CGT_EXPORT_C void call_0b93c838349c5f53e28cc2863cf54f7e(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_0b93c838349c5f53e28cc2863cf54f7e(readdata[i]);
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
typedef struct closure_0f918d474b775f067714ee43559e5434 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_0f918d474b775f067714ee43559e5434;


            CGT_EXPORT_C cgtArray* call_0f918d474b775f067714ee43559e5434(closure_0f918d474b775f067714ee43559e5434* cldata, cgtArray** reads) {
                
                std::cout << cldata->pptr;
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

                static inline int64_t scalar_call_10f0d09ec2a398d1beb65533f118d5fd(double x) {return ceil(x);}
                CGT_EXPORT_C void call_10f0d09ec2a398d1beb65533f118d5fd(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_10f0d09ec2a398d1beb65533f118d5fd(readdata[i]);
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
                

                static inline float scalar_call_16687a8c7c6d6d130b381a881321a005(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_16687a8c7c6d6d130b381a881321a005(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_16687a8c7c6d6d130b381a881321a005(in0[0], in1[i]);
                    }
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
typedef struct closure_17f1447d8d94b7387f8487dcd099260f {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_17f1447d8d94b7387f8487dcd099260f;


            CGT_EXPORT_C cgtArray* call_17f1447d8d94b7387f8487dcd099260f(closure_17f1447d8d94b7387f8487dcd099260f* cldata, cgtArray** reads) {
                
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "^^^^^^^\n";
                tmp->print();
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

        using namespace std ;
        static inline long double reduction_call_18483579d8e099ed78369e9efdd9c39f(long double x, long double y) {return x+y;}
        CGT_EXPORT_C void call_18483579d8e099ed78369e9efdd9c39f(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<long double>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                long double x = write->at<long double>(0,i1);
                long double y = read->at<long double>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<long double>(0,i1) = reduction_call_18483579d8e099ed78369e9efdd9c39f(x, y);
            }}
        }
        

                static inline float scalar_call_18982b4b7da20b5956d4ddd29ce87758(int64_t x, float y) {return x-y;}
                CGT_EXPORT_C void call_18982b4b7da20b5956d4ddd29ce87758(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_18982b4b7da20b5956d4ddd29ce87758(in0[0], in1[i]);
                    }
                }

                static inline float scalar_call_1a1142f848ddff90134cf2a31003c0c1(float x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_1a1142f848ddff90134cf2a31003c0c1(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_1a1142f848ddff90134cf2a31003c0c1(in0[i], in1[0]);
                    }

                }
typedef struct closure_1a28d6c48323e37e2b380e74aad66f54 {
int ax;
} closure_1a28d6c48323e37e2b380e74aad66f54;

            CGT_EXPORT_C cgtArray* call_1a28d6c48323e37e2b380e74aad66f54(void* cl0, cgtArray** reads) {
                closure_1a28d6c48323e37e2b380e74aad66f54* cl = (closure_1a28d6c48323e37e2b380e74aad66f54*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nIN = %ld\n", (long)(in->shape()));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline int8_t scalar_call_1b079f23c9f2e2b127e2e1069bd57d03(double x, double y) {return x==y;}
                CGT_EXPORT_C void call_1b079f23c9f2e2b127e2e1069bd57d03(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_1b079f23c9f2e2b127e2e1069bd57d03(in0[0], in1[0]);
                    }
                }
typedef struct closure_1d74840e9207d67849de0464474c0945 {
int ax;
} closure_1d74840e9207d67849de0464474c0945;

            CGT_EXPORT_C cgtArray* call_1d74840e9207d67849de0464474c0945(void* cl0, cgtArray** reads) {
                closure_1d74840e9207d67849de0464474c0945* cl = (closure_1d74840e9207d67849de0464474c0945*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nIN = %ld\n", (long)(in->shape()[0]));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline long double scalar_call_23b5cf985249175896fe1f7a7d0b9354(int64_t x, long double y) {return x-y;}
                CGT_EXPORT_C void call_23b5cf985249175896fe1f7a7d0b9354(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_23b5cf985249175896fe1f7a7d0b9354(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_2a8b57ddc17094fa96c60ef7ad664593(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) {
                    write->at<float>(i0) = read->at<float>(0);
                }
            }
            
typedef struct closure_2b4e64d9e5905f8462bafc8567176bc3 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_2b4e64d9e5905f8462bafc8567176bc3;


            CGT_EXPORT_C cgtArray* call_2b4e64d9e5905f8462bafc8567176bc3(closure_2b4e64d9e5905f8462bafc8567176bc3* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = \n" ;
                std::cout << cldata->ndim << "\n";
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)cldata->pptr << "\n^^^^^^^\n";
                //tmp->print();
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

                static inline long double scalar_call_2beb4dd9251cb3e58b14c98a0d4223d1(long double x, long double y) {return x*y;}
                CGT_EXPORT_C void call_2beb4dd9251cb3e58b14c98a0d4223d1(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_2beb4dd9251cb3e58b14c98a0d4223d1(in0[i], in1[i]);
                    }
                }

                static inline long double scalar_call_2c43a850375e29e1a29ebf06b7e19c7f(long double x) {return 1.0/(1.0+exp(-x));}
                CGT_EXPORT_C void call_2c43a850375e29e1a29ebf06b7e19c7f(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_2c43a850375e29e1a29ebf06b7e19c7f(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_2c9c8c81633ccf384021920691b364dc(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 14; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<long double>(i0+n) = in->at<long double>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline float scalar_call_2cd8fbc2f681256d0c24de5a03a9fa18(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_2cd8fbc2f681256d0c24de5a03a9fa18(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_2cd8fbc2f681256d0c24de5a03a9fa18(in0[0], in1[i]);
                    }
                }

                static inline long double scalar_call_2d52f1a472bbd8bc778f047231e189aa(long double x) {return log(x);}
                CGT_EXPORT_C void call_2d52f1a472bbd8bc778f047231e189aa(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_2d52f1a472bbd8bc778f047231e189aa(readdata[i]);
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

                static inline float scalar_call_2e6d1830f6af5bc3bfe19c793b961ed8(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_2e6d1830f6af5bc3bfe19c793b961ed8(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_2e6d1830f6af5bc3bfe19c793b961ed8(in0[0], in1[i]);
                    }

                }

                static inline long double scalar_call_3226404ff60d804c68e91acb5706242d(long double x, long double y) {return x-y;}
                CGT_EXPORT_C void call_3226404ff60d804c68e91acb5706242d(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3226404ff60d804c68e91acb5706242d(in0[0], in1[i]);
                    }
                }

                static inline long double scalar_call_330ac74b27c3e8142f30f417a9dc3da2(long double x, long double y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_330ac74b27c3e8142f30f417a9dc3da2(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_330ac74b27c3e8142f30f417a9dc3da2(in0[i], in1[i]);
                    }
                }

            CGT_EXPORT_C void call_340dc32f3e7ceeda734df9317566288b(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *in=reads[0];
                long start = reads[1]->at<long>(0);
                long step = reads[3]->at<long>(0);
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) { for (int i2=0; i2 < write->shape()[2]; ++i2) {
                    write->at<long double>(i0,i1,i2) = in->at<long double>(start + step*i0,i1,i2);
                }}}
            }
            
typedef struct closure_34f595a3030cc883f5d0bcd308304338 {
int ax;
} closure_34f595a3030cc883f5d0bcd308304338;

            CGT_EXPORT_C cgtArray* call_34f595a3030cc883f5d0bcd308304338(void* cl0, cgtArray** reads) {
                closure_34f595a3030cc883f5d0bcd308304338* cl = (closure_34f595a3030cc883f5d0bcd308304338*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nShapePtr = %ld\n", (long)(in->shape()));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline float scalar_call_3539101fa53fce435ea0abaaff8132f3(float x) {return fabs(x);}
                CGT_EXPORT_C void call_3539101fa53fce435ea0abaaff8132f3(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_3539101fa53fce435ea0abaaff8132f3(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_3551095f0502668d9309e879a74e2bb7(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *in=reads[0];
                long start = reads[1]->at<long>(0);
                long step = reads[3]->at<long>(0);
                for (int i0=0; i0 < write->shape()[0]; ++i0) {
                    write->at<float>(i0) = in->at<float>(start + step*i0);
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
            

                static inline int8_t scalar_call_375f03a71c9e4a0af09bf68563017692(double x, double y) {return x>y;}
                CGT_EXPORT_C void call_375f03a71c9e4a0af09bf68563017692(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_375f03a71c9e4a0af09bf68563017692(in0[0], in1[0]);
                    }
                }

                static inline float scalar_call_386828486bca60340a218a5b12c90715(int64_t x, float y) {return x-y;}
                CGT_EXPORT_C void call_386828486bca60340a218a5b12c90715(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_386828486bca60340a218a5b12c90715(in0[0], in1[i]);
                    }

                }

            CGT_EXPORT_C void call_39593a6fe5c2c42533a877e51734430e(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 50; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline double scalar_call_3a4d4af30d56983f64851f92519e5718(double x, double y) {return x+y;}
                CGT_EXPORT_C void call_3a4d4af30d56983f64851f92519e5718(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3a4d4af30d56983f64851f92519e5718(in0[0], in1[0]);
                    }
                }

                static inline double scalar_call_3a835494bf7a51183896653cb7097397(double x) {return cos(x);}
                CGT_EXPORT_C void call_3a835494bf7a51183896653cb7097397(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_3a835494bf7a51183896653cb7097397(readdata[i]);
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

                static inline long double scalar_call_3c7a910b9d9d680c188c1123065df33b(long double x, long double y) {return x*y;}
                CGT_EXPORT_C void call_3c7a910b9d9d680c188c1123065df33b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3c7a910b9d9d680c188c1123065df33b(in0[i], in1[0]);
                    }
                }
typedef struct closure_3d6fdc1ad6a7e829bc79be06a0e35942 {
int ax;
} closure_3d6fdc1ad6a7e829bc79be06a0e35942;

            CGT_EXPORT_C cgtArray* call_3d6fdc1ad6a7e829bc79be06a0e35942(void* cl0, cgtArray** reads) {
                closure_3d6fdc1ad6a7e829bc79be06a0e35942* cl = (closure_3d6fdc1ad6a7e829bc79be06a0e35942*)cl0;
                cgtArray* in = reads[0];
                printf("\nIN = %ld\n", (long)(in));
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }
typedef struct closure_3d9afa35b8a5c5d9376cd1573a40645c {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_3d9afa35b8a5c5d9376cd1573a40645c;


            CGT_EXPORT_C cgtArray* call_3d9afa35b8a5c5d9376cd1573a40645c(closure_3d9afa35b8a5c5d9376cd1573a40645c* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = \n" ;
                std::cout << cldata->ndim << "\n";
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "\n^^^^^^^\n";
                tmp->print();
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
            

                static inline int64_t scalar_call_3f9445792506a5d8ac3f886d9f053dcd(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_3f9445792506a5d8ac3f886d9f053dcd(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_3f9445792506a5d8ac3f886d9f053dcd(in0[0], in1[0]);
                    }

                }

                static inline float scalar_call_4021ca0c86840ba0290b68c9d92c17ef(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_4021ca0c86840ba0290b68c9d92c17ef(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_4021ca0c86840ba0290b68c9d92c17ef(in0[0], in1[0]);
                    }
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
typedef struct closure_41e712db6cbece52d7a00206934af1ec {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
long pptr;
} closure_41e712db6cbece52d7a00206934af1ec;


            CGT_EXPORT_C cgtArray* call_41e712db6cbece52d7a00206934af1ec(closure_41e712db6cbece52d7a00206934af1ec* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = \n" ;
                std::cout << cldata->ndim << "\n";
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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

            CGT_EXPORT_C void call_44fe2f9f36c46a1dc14e634bd0536233(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *in=reads[0];
                long start = reads[1]->at<long>(0);
                long step = reads[3]->at<long>(0);
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = in->at<float>(i0,start + step*i1);
                }}
            }
            

                static inline int64_t scalar_call_46aa4554818a2927d268e9fc8894bc02(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_46aa4554818a2927d268e9fc8894bc02(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_46aa4554818a2927d268e9fc8894bc02(in0[0], in1[0]);
                    }
                }

                static inline float scalar_call_471580551479c7db61b80eff870865d7(float x) {return sqrt(x);}
                CGT_EXPORT_C void call_471580551479c7db61b80eff870865d7(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_471580551479c7db61b80eff870865d7(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_479ac9a2be384300b93e7e3f1c31976d(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 25; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

        using namespace std ;
        static inline float reduction_call_4830064b23695591a6af7d194be6a2a2(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_4830064b23695591a6af7d194be6a2a2(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,0) = reduction_call_4830064b23695591a6af7d194be6a2a2(x, y);
            }}
        }
        

                static inline float scalar_call_4894654a0f8c779625611cf68a5928a6(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_4894654a0f8c779625611cf68a5928a6(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_4894654a0f8c779625611cf68a5928a6(in0[0], in1[i]);
                    }
                }

        using namespace std ;
        static inline long double reduction_call_4c2229220e536f222bbdd79ca5a5b429(long double x, long double y) {return x+y;}
        CGT_EXPORT_C void call_4c2229220e536f222bbdd79ca5a5b429(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<long double>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                long double x = write->at<long double>(i0,0);
                long double y = read->at<long double>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<long double>(i0,0) = reduction_call_4c2229220e536f222bbdd79ca5a5b429(x, y);
            }}
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

                static inline float scalar_call_4d94758a55a5502ff2c19eca5d6744de(float x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_4d94758a55a5502ff2c19eca5d6744de(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_4d94758a55a5502ff2c19eca5d6744de(in0[0], in1[0]);
                    }
                }
typedef struct closure_5187519ea92c8860706738ffe8f71df5 {
double value;
} closure_5187519ea92c8860706738ffe8f71df5;

            CGT_EXPORT_C void call_5187519ea92c8860706738ffe8f71df5(closure_5187519ea92c8860706738ffe8f71df5* cldata, cgtArray** reads, cgtArray* write) {
                long s = write->size();
                float value = cldata->value;
                #ifdef OMP
                #pragma omp parallel for
                #endif
                for (int i=0; i < s; ++i) write->at<float>(i) = value;
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

                static inline float scalar_call_52b6a0c7ae37a49e0262978bc892eb1c(int64_t x, float y) {return x-y;}
                CGT_EXPORT_C void call_52b6a0c7ae37a49e0262978bc892eb1c(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_52b6a0c7ae37a49e0262978bc892eb1c(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_52d9784c8ba98af51f75c4983377eceb(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 2; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) { for (int i1=0; i1 < in->shape()[1]; ++i1) {
                        write->at<float>(i0,i1+n) = in->at<float>(i0,i1);
                    }}
                    n += in->shape()[1];
                }
            }
            

                static inline float scalar_call_53ee6b4eaa295484ee6a6ee8629ddb8d(float x, float y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_53ee6b4eaa295484ee6a6ee8629ddb8d(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_53ee6b4eaa295484ee6a6ee8629ddb8d(in0[i], in1[i]);
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

                static inline float scalar_call_5aa9a69b1361d0efb5650481927a77b8(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_5aa9a69b1361d0efb5650481927a77b8(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_5aa9a69b1361d0efb5650481927a77b8(in0[i], in1[i]);
                    }

                }

                static inline int64_t scalar_call_602ca48e0b0af2dd51e9fb9781fd3709(int64_t x, int32_t y) {return x+y;}
                CGT_EXPORT_C void call_602ca48e0b0af2dd51e9fb9781fd3709(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int32_t* in1 = (int32_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_602ca48e0b0af2dd51e9fb9781fd3709(in0[i], in1[i]);
                    }
                }

                static inline float scalar_call_628118e1c962d6a7606216e735267c62(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_628118e1c962d6a7606216e735267c62(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_628118e1c962d6a7606216e735267c62(in0[0], in1[i]);
                    }

                }

            CGT_EXPORT_C void call_6308c0e977da679f337ec6492f040944(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 38; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline int64_t scalar_call_63909673aa4a98e3b723ed863fc6f43a(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_63909673aa4a98e3b723ed863fc6f43a(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_63909673aa4a98e3b723ed863fc6f43a(in0[i], in1[0]);
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
        
typedef struct closure_655d406f1a12aef7d487656f5fb26d4a {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_655d406f1a12aef7d487656f5fb26d4a;


            CGT_EXPORT_C cgtArray* call_655d406f1a12aef7d487656f5fb26d4a(closure_655d406f1a12aef7d487656f5fb26d4a* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = \n" ;
                std::cout << cldata->ndim << "\n";
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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

        using namespace std ;
        static inline float reduction_call_6585d4bdb427baa98f16bf12b74f9d07(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_6585d4bdb427baa98f16bf12b74f9d07(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,i1);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,i1) = reduction_call_6585d4bdb427baa98f16bf12b74f9d07(x, y);
            }}
        }
        

                static inline double scalar_call_68e75408004d9e261b96d5545c4f7b3b(double x) {return (-x);}
                CGT_EXPORT_C void call_68e75408004d9e261b96d5545c4f7b3b(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_68e75408004d9e261b96d5545c4f7b3b(readdata[i]);
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

                static inline long double scalar_call_69f3226397743250901087efacff0721(long double x, long double y) {return x-y;}
                CGT_EXPORT_C void call_69f3226397743250901087efacff0721(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_69f3226397743250901087efacff0721(in0[0], in1[0]);
                    }
                }

                static inline long double scalar_call_6b57857061b96a0001f6158bfba7c86d(long double x) {return x*x;}
                CGT_EXPORT_C void call_6b57857061b96a0001f6158bfba7c86d(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_6b57857061b96a0001f6158bfba7c86d(readdata[i]);
                    }
                }
typedef struct closure_6b9b6faea3b42e4b82b579d3a752d97d {
int ax;
} closure_6b9b6faea3b42e4b82b579d3a752d97d;

            CGT_EXPORT_C cgtArray* call_6b9b6faea3b42e4b82b579d3a752d97d(void* cl0, cgtArray** reads) {
                closure_6b9b6faea3b42e4b82b579d3a752d97d* cl = (closure_6b9b6faea3b42e4b82b579d3a752d97d*)cl0;
                cgtArray* in = reads[0];
                printf("\n%ld\n", (long)(in));
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
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

            CGT_EXPORT_C void call_71100cca4d39751ce99c83e507e84a25(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *in=reads[0];
                long start = reads[1]->at<long>(0);
                long step = reads[3]->at<long>(0);
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) { for (int i2=0; i2 < write->shape()[2]; ++i2) {
                    write->at<float>(i0,i1,i2) = in->at<float>(start + step*i0,i1,i2);
                }}}
            }
            

                static inline float scalar_call_730f86d42c34ccf5c1bf611deb0e7720(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_730f86d42c34ccf5c1bf611deb0e7720(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_730f86d42c34ccf5c1bf611deb0e7720(in0[0], in1[0]);
                    }

                }

                static inline double scalar_call_7357cab132f639dabfbb68bb0a880f8d(double x) {return sqrt(x);}
                CGT_EXPORT_C void call_7357cab132f639dabfbb68bb0a880f8d(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_7357cab132f639dabfbb68bb0a880f8d(readdata[i]);
                    }
                }

                static inline double scalar_call_746b244cde2c72af998d5184c1e4289b(double x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_746b244cde2c72af998d5184c1e4289b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_746b244cde2c72af998d5184c1e4289b(in0[0], in1[0]);
                    }
                }
typedef struct closure_755332e55df4b48e724d3a7af84ab013 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_755332e55df4b48e724d3a7af84ab013;


            CGT_EXPORT_C cgtArray* call_755332e55df4b48e724d3a7af84ab013(closure_755332e55df4b48e724d3a7af84ab013* cldata, cgtArray** reads) {
                
                //cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                //std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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

                static inline int8_t scalar_call_75b34b4e8efbfbfb18cacef3ff79ce6a(float x, float y) {return x>=y;}
                CGT_EXPORT_C void call_75b34b4e8efbfbfb18cacef3ff79ce6a(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_75b34b4e8efbfbfb18cacef3ff79ce6a(in0[0], in1[0]);
                    }
                }

                static inline double scalar_call_7796e255803f6bc0cf957a3f1a947e20(double x, double y) {return x*y;}
                CGT_EXPORT_C void call_7796e255803f6bc0cf957a3f1a947e20(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_7796e255803f6bc0cf957a3f1a947e20(in0[0], in1[0]);
                    }
                }
typedef struct closure_7b01573a1463d1871f51382d3d1d7ff4 {
void* pptr;
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
} closure_7b01573a1463d1871f51382d3d1d7ff4;


            CGT_EXPORT_C cgtArray* call_7b01573a1463d1871f51382d3d1d7ff4(closure_7b01573a1463d1871f51382d3d1d7ff4* cldata, cgtArray** reads) {
                
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                std::cout << (long)tmp << "\n^^^^^^^\n";
                tmp->print();
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

            CGT_EXPORT_C void call_7bde25db51c60d19cbca3371767f1b58(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 8; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline float scalar_call_7d7ab754a9b95691cfdde507875d3061(int64_t x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_7d7ab754a9b95691cfdde507875d3061(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_7d7ab754a9b95691cfdde507875d3061(in0[0], in1[0]);
                    }

                }

            CGT_EXPORT_C void call_7dfcd46e6055a7435746afa5927271db(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 1; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            
typedef struct closure_7e35e9e7e5aba24c437973d7f9a61b86 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_7e35e9e7e5aba24c437973d7f9a61b86;


            CGT_EXPORT_C cgtArray* call_7e35e9e7e5aba24c437973d7f9a61b86(closure_7e35e9e7e5aba24c437973d7f9a61b86* cldata, cgtArray** reads) {
                
                //std::cout << "\nNdim = \n" ;
                //std::cout << cldata->ndim << "\n";
                //cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                //std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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
typedef struct closure_813f96afc50911138c661dd51950492d {
int ax;
} closure_813f96afc50911138c661dd51950492d;

            CGT_EXPORT_C cgtArray* call_813f96afc50911138c661dd51950492d(void* cl0, cgtArray** reads) {
                closure_813f96afc50911138c661dd51950492d* cl = (closure_813f96afc50911138c661dd51950492d*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nShapePtr = %ld\n", (long)(in->shape()));
                in->print();
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline float scalar_call_828a9d190c46f71761b5c41f4203b93a(float x) {return sin(x);}
                CGT_EXPORT_C void call_828a9d190c46f71761b5c41f4203b93a(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_828a9d190c46f71761b5c41f4203b93a(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_834ebc4a7dd7bd617db75fddc7141535(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 26; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline float scalar_call_837416003779b7e337f5285dfea13caa(float x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_837416003779b7e337f5285dfea13caa(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_837416003779b7e337f5285dfea13caa(in0[i], in1[0]);
                    }
                }

                static inline double scalar_call_85db5ee2ab1d24d70ef55d3210fbbac6(double x, double y) {return pow(x,y);}
                CGT_EXPORT_C void call_85db5ee2ab1d24d70ef55d3210fbbac6(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_85db5ee2ab1d24d70ef55d3210fbbac6(in0[0], in1[0]);
                    }
                }

                static inline int64_t scalar_call_86b3f78cc5d099d95c904c2f639801df(float x) {return ceil(x);}
                CGT_EXPORT_C void call_86b3f78cc5d099d95c904c2f639801df(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_86b3f78cc5d099d95c904c2f639801df(readdata[i]);
                    }
                }

                static inline float scalar_call_8a82ec7cad0636c9213c0fbcc743733e(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_8a82ec7cad0636c9213c0fbcc743733e(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8a82ec7cad0636c9213c0fbcc743733e(in0[0], in1[i]);
                    }

                }

                static inline int8_t scalar_call_8c61a75760d0083e2cb49767853c0802(double x, double y) {return x<y;}
                CGT_EXPORT_C void call_8c61a75760d0083e2cb49767853c0802(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8c61a75760d0083e2cb49767853c0802(in0[0], in1[0]);
                    }
                }

                static inline int8_t scalar_call_8deabf99162c03b41a8aed3096475a1f(float x, float y) {return x<y;}
                CGT_EXPORT_C void call_8deabf99162c03b41a8aed3096475a1f(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8deabf99162c03b41a8aed3096475a1f(in0[0], in1[0]);
                    }
                }

                static inline float scalar_call_8eb0a994cd80a6ac5f48a0eac6aa8da4(float x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_8eb0a994cd80a6ac5f48a0eac6aa8da4(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8eb0a994cd80a6ac5f48a0eac6aa8da4(in0[0], in1[0]);
                    }

                }

                static inline float scalar_call_8f3da4a32a10b03ef8278341ba6f586e(float x, float y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_8f3da4a32a10b03ef8278341ba6f586e(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8f3da4a32a10b03ef8278341ba6f586e(in0[i], in1[0]);
                    }
                }

                static inline int8_t scalar_call_8f4da1a8d5270ed812aef6f9eb1ec49d(double x, double y) {return x!=y;}
                CGT_EXPORT_C void call_8f4da1a8d5270ed812aef6f9eb1ec49d(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_8f4da1a8d5270ed812aef6f9eb1ec49d(in0[0], in1[0]);
                    }
                }

                static inline long double scalar_call_907b8209f353bb98eace89067afcec0d(long double x) {return tanh(x);}
                CGT_EXPORT_C void call_907b8209f353bb98eace89067afcec0d(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_907b8209f353bb98eace89067afcec0d(readdata[i]);
                    }
                }

                static inline float scalar_call_922578de4678ac78d9f5989406c590ec(float x) {return tanh(x);}
                CGT_EXPORT_C void call_922578de4678ac78d9f5989406c590ec(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_922578de4678ac78d9f5989406c590ec(readdata[i]);
                    }
                }
typedef struct closure_9287f4bc38a2ac5457ad661034723054 {
int ax;
} closure_9287f4bc38a2ac5457ad661034723054;

            CGT_EXPORT_C cgtArray* call_9287f4bc38a2ac5457ad661034723054(void* cl0, cgtArray** reads) {
                closure_9287f4bc38a2ac5457ad661034723054* cl = (closure_9287f4bc38a2ac5457ad661034723054*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nShapePtr = %ld\n", (long)(in->shape()));
                in->print_data();
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline float scalar_call_92f558cdc5d5bb606ade889355aaff43(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_92f558cdc5d5bb606ade889355aaff43(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_92f558cdc5d5bb606ade889355aaff43(in0[i], in1[0]);
                    }

                }

            CGT_EXPORT_C void call_9376bccff3d63129ec69af653442cee0(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 6; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline int64_t scalar_call_98467f237f93b280b2785a25087254f8(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_98467f237f93b280b2785a25087254f8(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_98467f237f93b280b2785a25087254f8(in0[0], in1[0]);
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
        

                static inline long double scalar_call_9b07fa1affdb10adab342f9030ea341f(long double x, long double y) {return x+y;}
                CGT_EXPORT_C void call_9b07fa1affdb10adab342f9030ea341f(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9b07fa1affdb10adab342f9030ea341f(in0[0], in1[i]);
                    }
                }

                static inline float scalar_call_9dddb41c709118d2172771d5b299b3fc(float x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_9dddb41c709118d2172771d5b299b3fc(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_9dddb41c709118d2172771d5b299b3fc(in0[i], in1[0]);
                    }
                }

                static inline double scalar_call_a0ed09161e5638249ea4fd3525cfc6df(double x) {return x*x;}
                CGT_EXPORT_C void call_a0ed09161e5638249ea4fd3525cfc6df(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_a0ed09161e5638249ea4fd3525cfc6df(readdata[i]);
                    }
                }
typedef struct closure_a282d446c5073c38d2baa9d2634fc74f {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_a282d446c5073c38d2baa9d2634fc74f;


            CGT_EXPORT_C cgtArray* call_a282d446c5073c38d2baa9d2634fc74f(closure_a282d446c5073c38d2baa9d2634fc74f* cldata, cgtArray** reads) {
                
                if( *((long*)cldata->pptr) == 0)
                {
                    std::cout << "\n***\nALLOCATING NEW MEMORY FOR INMEMORY DATA\n***\n" ;
                    //std::cout << cldata->pptr;

                    cgtDtype dtype = (cgtDtype) cldata->dtype ;
                    cgtDevtype devtype = (cgtDevtype) cldata->devtype ;
                    cgtArray *out = new cgtArray(cldata->ndim, (long*)cldata->shape, dtype, devtype, cldata->fromdata, false);
                    *((cgtArray**)cldata->pptr) = out;
                    return out ;
                }else
                    return *(cgtArray**)cldata->pptr;
            }
typedef struct closure_a3b4515d2c469e01d6b693c530db3809 {
int ax;
} closure_a3b4515d2c469e01d6b693c530db3809;

            CGT_EXPORT_C cgtArray* call_a3b4515d2c469e01d6b693c530db3809(void* cl0, cgtArray** reads) {
                closure_a3b4515d2c469e01d6b693c530db3809* cl = (closure_a3b4515d2c469e01d6b693c530db3809*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                printf("\nIN = %ld\n", (long)(in));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline double scalar_call_a3f9686634d8f0c5cd012280d7d4cc45(double x) {return fabs(x);}
                CGT_EXPORT_C void call_a3f9686634d8f0c5cd012280d7d4cc45(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_a3f9686634d8f0c5cd012280d7d4cc45(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_a4230cd216c73e2b9b2b9b05493023a2(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 4; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

        using namespace std ;
        static inline long double reduction_call_a50e1f55987d314a4ac296a7d7c995ef(long double x, long double y) {return x+y;}
        CGT_EXPORT_C void call_a50e1f55987d314a4ac296a7d7c995ef(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<long double>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                long double x = write->at<long double>(0,0);
                long double y = read->at<long double>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<long double>(0,0) = reduction_call_a50e1f55987d314a4ac296a7d7c995ef(x, y);
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

                static inline long double scalar_call_a5b8e838b4149ebfc256ade78114d940(long double x) {return (-x);}
                CGT_EXPORT_C void call_a5b8e838b4149ebfc256ade78114d940(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_a5b8e838b4149ebfc256ade78114d940(readdata[i]);
                    }
                }

                static inline int64_t scalar_call_a67fe44b26ef01dcda9f32ed11d6789b(long double x) {return (int)ceil(x);}
                CGT_EXPORT_C void call_a67fe44b26ef01dcda9f32ed11d6789b(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_a67fe44b26ef01dcda9f32ed11d6789b(readdata[i]);
                    }
                }

                static inline float scalar_call_a6e41565e6126bc654455f48b24bb83f(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_a6e41565e6126bc654455f48b24bb83f(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_a6e41565e6126bc654455f48b24bb83f(in0[i], in1[i]);
                    }

                }

                static inline long double scalar_call_a7e3b5b5c89ee1e8695b678404663a40(long double x) {return exp(x);}
                CGT_EXPORT_C void call_a7e3b5b5c89ee1e8695b678404663a40(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    long double* readdata = (long double*)read->data();
                    long double* writedata = (long double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_a7e3b5b5c89ee1e8695b678404663a40(readdata[i]);
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
        

                static inline long double scalar_call_a8fc2beadd070d0fa1b440336c98cf62(int64_t x, long double y) {return x-y;}
                CGT_EXPORT_C void call_a8fc2beadd070d0fa1b440336c98cf62(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_a8fc2beadd070d0fa1b440336c98cf62(in0[0], in1[i]);
                    }
                }

                static inline int8_t scalar_call_a99f0dd270b91d81d05c527e46c4eaac(float x, float y) {return x==y;}
                CGT_EXPORT_C void call_a99f0dd270b91d81d05c527e46c4eaac(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_a99f0dd270b91d81d05c527e46c4eaac(in0[0], in1[0]);
                    }
                }

                static inline double scalar_call_aac989c73cf9a878b439e771fcb257cf(double x) {return 1.0/(1.0+exp(-x));}
                CGT_EXPORT_C void call_aac989c73cf9a878b439e771fcb257cf(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_aac989c73cf9a878b439e771fcb257cf(readdata[i]);
                    }
                }

                static inline float scalar_call_abb833c470857b79df9f1ecd89cbca26(int64_t x, float y) {return x-y;}
                CGT_EXPORT_C void call_abb833c470857b79df9f1ecd89cbca26(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_abb833c470857b79df9f1ecd89cbca26(in0[0], in1[0]);
                    }

                }

                static inline double scalar_call_ada66833da654eabccfd196ac649e500(int64_t x, double y) {return x-y;}
                CGT_EXPORT_C void call_ada66833da654eabccfd196ac649e500(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ada66833da654eabccfd196ac649e500(in0[0], in1[0]);
                    }
                }

                static inline int8_t scalar_call_afbe5b8e6d348f7ba855808e42d3cdfe(double x, double y) {return x<=y;}
                CGT_EXPORT_C void call_afbe5b8e6d348f7ba855808e42d3cdfe(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_afbe5b8e6d348f7ba855808e42d3cdfe(in0[0], in1[0]);
                    }
                }

                static inline long double scalar_call_b0e8f1d124c3efce72291b857931c13d(long double x, long double y) {return x+y;}
                CGT_EXPORT_C void call_b0e8f1d124c3efce72291b857931c13d(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_b0e8f1d124c3efce72291b857931c13d(in0[i], in1[i]);
                    }
                }

                static inline double scalar_call_b24f762393f9be1ed151f099bdef976c(double x, double y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_b24f762393f9be1ed151f099bdef976c(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_b24f762393f9be1ed151f099bdef976c(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_b3629c6e274682b652b8235b7e4333b4(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *x=reads[0], *inds=reads[1], *inc = reads[2];
                cgt_assert(x->size() == write->size());
                if (write->data() != x->data()) cgt_copy_array(write, x);
                for (int i0=0; i0 < inc->shape()[0]; ++i0) { for (int i1=0; i1 < inc->shape()[1]; ++i1) { for (int i2=0; i2 < inc->shape()[2]; ++i2) {
                    write->at<float>(inds->at<long>(i0),i1,i2) += inc->at<float>(i0,i1,i2);
                }}}
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
            

                static inline int64_t scalar_call_b41731624f42047331b4137d032eb7f6(float x) {return (int)ceil(x);}
                CGT_EXPORT_C void call_b41731624f42047331b4137d032eb7f6(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_b41731624f42047331b4137d032eb7f6(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_b4d4a7c958d00599327cd46ab0d33562(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<long double>(i0,i1) = read->at<long double>(i0,0);
                }}
            }
            
typedef struct closure_b68b551ff9247e464844194a76503b54 {
long value;
} closure_b68b551ff9247e464844194a76503b54;

            CGT_EXPORT_C void call_b68b551ff9247e464844194a76503b54(closure_b68b551ff9247e464844194a76503b54* cldata, cgtArray** reads, cgtArray* write) {
                long s = write->size();
                int64_t value = cldata->value;
                for (int i=0; i < s; ++i) write->at<int64_t>(i) = value;
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

                static inline int8_t scalar_call_bc0447d8dd2eb055013601db9f63c1c0(float x, float y) {return x<=y;}
                CGT_EXPORT_C void call_bc0447d8dd2eb055013601db9f63c1c0(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_bc0447d8dd2eb055013601db9f63c1c0(in0[0], in1[0]);
                    }
                }

                static inline int8_t scalar_call_c11b7e69b9a3b663eecd771a2e7b5e20(float x, float y) {return x>y;}
                CGT_EXPORT_C void call_c11b7e69b9a3b663eecd771a2e7b5e20(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_c11b7e69b9a3b663eecd771a2e7b5e20(in0[0], in1[0]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_c2647a120b5b43c63eedc6ad775c2e4a(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_c2647a120b5b43c63eedc6ad775c2e4a(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            

            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                write->at<float>(0,0) = reduction_call_c2647a120b5b43c63eedc6ad775c2e4a(x, y);
            }}
    
        }
        
typedef struct closure_c2ff4ce1d2ba56134c6dcb4936a2ad80 {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_c2ff4ce1d2ba56134c6dcb4936a2ad80;


            CGT_EXPORT_C cgtArray* call_c2ff4ce1d2ba56134c6dcb4936a2ad80(closure_c2ff4ce1d2ba56134c6dcb4936a2ad80* cldata, cgtArray** reads) {
                
                std::cout << "\nNdim = " << cldata->ndim << "\n";
                //cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                //std::cout << (long)tmp << "\n^^^^^^^\n";
                //tmp->print();
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

                static inline float scalar_call_c53f1da5d1098de1e07fe41f67eac489(float x) {return 2*(x>0)-1;}
                CGT_EXPORT_C void call_c53f1da5d1098de1e07fe41f67eac489(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_c53f1da5d1098de1e07fe41f67eac489(readdata[i]);
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

                static inline int8_t scalar_call_c7aa8f1e9e36c4a3fc7ba2a83867d8e6(float x, float y) {return x>y;}
                CGT_EXPORT_C void call_c7aa8f1e9e36c4a3fc7ba2a83867d8e6(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_c7aa8f1e9e36c4a3fc7ba2a83867d8e6(in0[i], in1[0]);
                    }
                }

                static inline int64_t scalar_call_c8123927c84f5634705a0e3428c9cfb3(double x) {return (int)ceil(x);}
                CGT_EXPORT_C void call_c8123927c84f5634705a0e3428c9cfb3(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_c8123927c84f5634705a0e3428c9cfb3(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_c8c490bae186ccc423be53957a5da680(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 2; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) { for (int i1=0; i1 < in->shape()[1]; ++i1) {
                        write->at<float>(i0+n,i1) = in->at<float>(i0,i1);
                    }}
                    n += in->shape()[0];
                }
            }
            

            CGT_EXPORT_C void call_c9f5b4046f71c9c458664aebb1182df9(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<long double>(i0,i1) = read->at<long double>(0,i1);
                }}
            }
            

                static inline float scalar_call_ca7587555378e3cc79833947d83d47cc(float x, float y) {return x*y;}
                CGT_EXPORT_C void call_ca7587555378e3cc79833947d83d47cc(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ca7587555378e3cc79833947d83d47cc(in0[0], in1[0]);
                    }
                }

                static inline float scalar_call_cb79ac6b604af5e44d8792256505212b(float x, float y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_cb79ac6b604af5e44d8792256505212b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_cb79ac6b604af5e44d8792256505212b(in0[0], in1[0]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_cbf1bfec9da6c5673a05f5d8d609364f(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_cbf1bfec9da6c5673a05f5d8d609364f(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            

            double sum = 0;
            float *readArray = (float *)read->data() ;

            #ifdef OMP
            #pragma omp parallel for reduction(+:sum)
            #endif
            for (int i=0; i < read->size(); ++i) 
                sum += readArray[i] ;

            write->at<float>(0,0) = sum ;

    
        }
        

            CGT_EXPORT_C void call_cd284c2516aa6afd8452a83bb37257c6(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 14; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
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

                static inline float scalar_call_cf7bead502a5bf6dc5a1e4971f134e3a(float x, float y) {return x+y;}
                CGT_EXPORT_C void call_cf7bead502a5bf6dc5a1e4971f134e3a(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_cf7bead502a5bf6dc5a1e4971f134e3a(in0[i], in1[i]);
                    }

                }

                static inline int8_t scalar_call_d0466c6ecf77b654c738065f186c3244(double x, double y) {return x>=y;}
                CGT_EXPORT_C void call_d0466c6ecf77b654c738065f186c3244(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_d0466c6ecf77b654c738065f186c3244(in0[0], in1[0]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_d0b714f20d3618a23f5c379d8aba7e20(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_d0b714f20d3618a23f5c379d8aba7e20(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,i1);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,i1) = reduction_call_d0b714f20d3618a23f5c379d8aba7e20(x, y);
            }}
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

                static inline double scalar_call_d570c94925faf90878c7477ec70a0faa(double x, double y) {return x-y;}
                CGT_EXPORT_C void call_d570c94925faf90878c7477ec70a0faa(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    double* in0 = (double*)reads[0]->data();
                    double* in1 = (double*)reads[1]->data();
                    double* out = (double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_d570c94925faf90878c7477ec70a0faa(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_d664126d6759cfa421f46dc3ccf153ea(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *in=reads[0];
                long start = reads[1]->at<long>(0);
                long step = reads[3]->at<long>(0);
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = in->at<float>(start + step*i0,i1);
                }}
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

                static inline double scalar_call_db80f8c9e69321f883d324eb19079b48(double x) {return tanh(x);}
                CGT_EXPORT_C void call_db80f8c9e69321f883d324eb19079b48(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_db80f8c9e69321f883d324eb19079b48(readdata[i]);
                    }
                }

                static inline double scalar_call_dd889476d995a77a862ea2fb5d576952(double x) {return exp(x);}
                CGT_EXPORT_C void call_dd889476d995a77a862ea2fb5d576952(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_dd889476d995a77a862ea2fb5d576952(readdata[i]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_deb0fee25f1e7b7bedb93714a46341b8(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_deb0fee25f1e7b7bedb93714a46341b8(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            

            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,i1);
                float y = read->at<float>(i0,i1) ;
                write->at<float>(0,i1) = reduction_call_deb0fee25f1e7b7bedb93714a46341b8(x, y);
            }}
    
        }
        

                static inline int64_t scalar_call_dec2664a1fe34f6af692db579b083623(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_dec2664a1fe34f6af692db579b083623(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_dec2664a1fe34f6af692db579b083623(in0[0], in1[0]);
                    }

                }

                static inline float scalar_call_df50b9eb5067c0b36c5a6fbb9fd7b389(float x, float y) {return x-y;}
                CGT_EXPORT_C void call_df50b9eb5067c0b36c5a6fbb9fd7b389(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_df50b9eb5067c0b36c5a6fbb9fd7b389(in0[0], in1[0]);
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

                static inline int64_t scalar_call_e1d13c1c4e8e03ed66fa40881414a9cb(int64_t x, int64_t y) {return x*y;}
                CGT_EXPORT_C void call_e1d13c1c4e8e03ed66fa40881414a9cb(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_e1d13c1c4e8e03ed66fa40881414a9cb(in0[i], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_e275d27556904ee35697caff0b637bbd(void* cldata, cgtArray** reads, cgtArray* write) {
                cgtArray *read=reads[0];
                for (int i0=0; i0 < write->shape()[0]; ++i0) { for (int i1=0; i1 < write->shape()[1]; ++i1) {
                    write->at<float>(i0,i1) = read->at<float>(0,i1);
                }}
            }
            

                static inline float scalar_call_e534e35af6b9563a11f771bb8c7e3c96(float x) {return 1.0/(1.0+exp(-x));}
                CGT_EXPORT_C void call_e534e35af6b9563a11f771bb8c7e3c96(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_e534e35af6b9563a11f771bb8c7e3c96(readdata[i]);
                    }
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

                static inline float scalar_call_e5985f06daf02647b6fcd254e5c5882e(float x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_e5985f06daf02647b6fcd254e5c5882e(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    float* in0 = (float*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_e5985f06daf02647b6fcd254e5c5882e(in0[i], in1[0]);
                    }

                }

                static inline long double scalar_call_e611523a7e6a087733ffc5df4968398b(long double x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_e611523a7e6a087733ffc5df4968398b(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_e611523a7e6a087733ffc5df4968398b(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_e8894ade3fc514d54ae656001a16a2f9(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 5; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            
typedef struct closure_e8b17796de113e1b4ae5027aa31bdf46 {
int ax;
} closure_e8b17796de113e1b4ae5027aa31bdf46;

            CGT_EXPORT_C cgtArray* call_e8b17796de113e1b4ae5027aa31bdf46(void* cl0, cgtArray** reads) {
                closure_e8b17796de113e1b4ae5027aa31bdf46* cl = (closure_e8b17796de113e1b4ae5027aa31bdf46*)cl0;
                cgtArray* in = reads[0];
                cgtArray* out = new cgtArray(0, NULL, cgt_i8, cgtCPU);
                //printf("\nShapePtr = %ld\n", (long)(in->ndim() ));
                out->at<long>(0) = in->shape()[cl->ax];
                return out;
            }

                static inline float scalar_call_eb80c1ab146f7c5b5bb0dd426b22554f(float x) {return cos(x);}
                CGT_EXPORT_C void call_eb80c1ab146f7c5b5bb0dd426b22554f(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    float* readdata = (float*)read->data();
                    float* writedata = (float*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_eb80c1ab146f7c5b5bb0dd426b22554f(readdata[i]);
                    }
                }

                static inline float scalar_call_ebe471ffc86c39419cb930d4c0d99376(float x, float y) {return pow(x,y);}
                CGT_EXPORT_C void call_ebe471ffc86c39419cb930d4c0d99376(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    float* out = (float*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ebe471ffc86c39419cb930d4c0d99376(in0[0], in1[0]);
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
            

                static inline int64_t scalar_call_eddf2b48584029d010051fd5e6738201(int64_t x, int64_t y) {return x-y;}
                CGT_EXPORT_C void call_eddf2b48584029d010051fd5e6738201(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_eddf2b48584029d010051fd5e6738201(in0[0], in1[0]);
                    }

                }

        using namespace std ;
        static inline float reduction_call_edecbd49e6ae28211a12d42213fd7e44(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_edecbd49e6ae28211a12d42213fd7e44(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,0) = reduction_call_edecbd49e6ae28211a12d42213fd7e44(x, y);
            }}
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

                static inline int8_t scalar_call_f0669ee522ea85be5b0aa2d751d19bad(float x, float y) {return x!=y;}
                CGT_EXPORT_C void call_f0669ee522ea85be5b0aa2d751d19bad(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    float* in0 = (float*)reads[0]->data();
                    float* in1 = (float*)reads[1]->data();
                    int8_t* out = (int8_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_f0669ee522ea85be5b0aa2d751d19bad(in0[0], in1[0]);
                    }
                }

            CGT_EXPORT_C void call_f481673829e119a23f29e6ab8d9bf5eb(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 17; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline double scalar_call_f481e23187341d3d86076d1a9e9bbe18(double x) {return log(x);}
                CGT_EXPORT_C void call_f481e23187341d3d86076d1a9e9bbe18(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_f481e23187341d3d86076d1a9e9bbe18(readdata[i]);
                    }
                }

                static inline long double scalar_call_f493065b9eab7f005dff6e70da4f2f57(long double x, long double y) {return x-y;}
                CGT_EXPORT_C void call_f493065b9eab7f005dff6e70da4f2f57(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    long double* in0 = (long double*)reads[0]->data();
                    long double* in1 = (long double*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_f493065b9eab7f005dff6e70da4f2f57(in0[i], in1[i]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_f4f6614d2fe82ccc7912092d2c149eb1(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_f4f6614d2fe82ccc7912092d2c149eb1(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,0);
                float y = read->at<float>(i0,i1) ;
                //cout << "\n" << x << ", " << y ;
                write->at<float>(0,0) = reduction_call_f4f6614d2fe82ccc7912092d2c149eb1(x, y);
            }}
        }
        

            CGT_EXPORT_C void call_f60c0734a432524a16089d5e525792e9(void* cldata, cgtArray** reads, cgtArray* write) {
                long n=0; // value along concat axis
                for (int i=0; i < 9; ++i) {
                    cgtArray* in = reads[i];
                    for (int i0=0; i0 < in->shape()[0]; ++i0) {
                        write->at<float>(i0+n) = in->at<float>(i0);
                    }
                    n += in->shape()[0];
                }
            }
            

                static inline double scalar_call_f91ee53e472c2bb6604eafeac60dff98(double x) {return 2*(x>0)-1;}
                CGT_EXPORT_C void call_f91ee53e472c2bb6604eafeac60dff98(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    double* writedata = (double*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_f91ee53e472c2bb6604eafeac60dff98(readdata[i]);
                    }
                }
typedef struct closure_fc0220403eac7c57c2b94a643bc8188f {
int ndim;
void* shape;
int dtype;
int devtype;
void* fromdata;
void* pptr;
} closure_fc0220403eac7c57c2b94a643bc8188f;


            CGT_EXPORT_C cgtArray* call_fc0220403eac7c57c2b94a643bc8188f(closure_fc0220403eac7c57c2b94a643bc8188f* cldata, cgtArray** reads) {
                
                cgtArray *tmp = *(cgtArray**)cldata->pptr ;
                tmp->print();
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

                static inline int64_t scalar_call_fdcb0169866a5dfe6abd49e991198542(int64_t x, int64_t y) {return x+y;}
                CGT_EXPORT_C void call_fdcb0169866a5dfe6abd49e991198542(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[0]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    int64_t* out = (int64_t*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    #ifdef OMP
                    #pragma omp parallel for
                    #endif
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_fdcb0169866a5dfe6abd49e991198542(in0[i], in1[i]);
                    }

                }

                static inline int64_t scalar_call_febdf4da78dbf024627e5159650c2693(double x) {return (int)floor(x);}
                CGT_EXPORT_C void call_febdf4da78dbf024627e5159650c2693(void* cldata, cgtArray** reads, cgtArray* write) {
                    cgtArray* read = reads[0];
                    int s = read->size();
                    double* readdata = (double*)read->data();
                    int64_t* writedata = (int64_t*)write->data();
                    for (int i=0; i < s; ++i) {
                        writedata[i] = scalar_call_febdf4da78dbf024627e5159650c2693(readdata[i]);
                    }
                }

            CGT_EXPORT_C void call_fef23e677f07f08a3802edcc480fa2b8(void**, cgtArray** xkp, cgtArray* write) {
                cgtArray *x=xkp[0], *k=xkp[1], *p=xkp[2];
                if (write->data() != x->data()) cgt_memcpy(cgtCPU, cgtCPU, write, x, write->nbytes());
                for (int i=0; i < p->size(); ++i) {
                    write->at<float>(k->at<long>(i)) += p->at<float>(i);
                }
            }
            

                static inline long double scalar_call_ff6e6d23b5563a7427b2d5326d46c48c(int64_t x, int64_t y) {return (x+0.0)/y;}
                CGT_EXPORT_C void call_ff6e6d23b5563a7427b2d5326d46c48c(void* cldata, cgtArray** reads, cgtArray* write) {
                    int s = reads[1]->size();
                    int64_t* in0 = (int64_t*)reads[0]->data();
                    int64_t* in1 = (int64_t*)reads[1]->data();
                    long double* out = (long double*)write->data();
                    cgt_check(write->size() == s, "Shape error in elementwise binary operation. You might be missing a call to cgt.broadcast(...)");
                    for (int i=0; i < s; ++i) {
                        //std::cout << "Args " << in0[0] << ", " << in1[0] << "\n";
                        out[i] = scalar_call_ff6e6d23b5563a7427b2d5326d46c48c(in0[0], in1[0]);
                    }
                }

        using namespace std ;
        static inline float reduction_call_ffd925f2ac6fb223ff612dea320fe3f8(float x, float y) {return x+y;}
        CGT_EXPORT_C void call_ffd925f2ac6fb223ff612dea320fe3f8(void* cldata, cgtArray** reads, cgtArray* write) {
            cgtArray *read=reads[0];
            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i=0; i < write->size(); ++i) write->at<float>(i) = 0;

            

            #ifdef OMP
            #pragma omp parallel for
            #endif
            for (int i0=0; i0 < read->shape()[0]; ++i0) { for (int i1=0; i1 < read->shape()[1]; ++i1) {
                float x = write->at<float>(0,i1);
                float y = read->at<float>(i0,i1) ;
                write->at<float>(0,i1) = reduction_call_ffd925f2ac6fb223ff612dea320fe3f8(x, y);
            }}
    
        }
        

std::map<std::string, void *> fmap;

void create_functions_map(){

	fmap["call_0077a2258ab15bfa9cafda07748efe2d"] = (void *) &call_0077a2258ab15bfa9cafda07748efe2d ; 
	fmap["call_00914cbe71181f85859917d0afbd6fa4"] = (void *) &call_00914cbe71181f85859917d0afbd6fa4 ; 
	fmap["call_01ea73a67790f024647388b85086685a"] = (void *) &call_01ea73a67790f024647388b85086685a ; 
	fmap["call_0486a7d8d91ec22cdaff5147b528f1be"] = (void *) &call_0486a7d8d91ec22cdaff5147b528f1be ; 
	fmap["call_07446b7655dd180a91f826341a8b28ee"] = (void *) &call_07446b7655dd180a91f826341a8b28ee ; 
	fmap["call_0762a8e46046b932520c160b35d4ec56"] = (void *) &call_0762a8e46046b932520c160b35d4ec56 ; 
	fmap["call_08f2981c4318710424b1d8548e5f2b0c"] = (void *) &call_08f2981c4318710424b1d8548e5f2b0c ; 
	fmap["call_0984639e5104f291a73ac19a63801f4c"] = (void *) &call_0984639e5104f291a73ac19a63801f4c ; 
	fmap["call_0a0aa1b01ea5da675741b34fcff7a66a"] = (void *) &call_0a0aa1b01ea5da675741b34fcff7a66a ; 
	fmap["call_0b93c838349c5f53e28cc2863cf54f7e"] = (void *) &call_0b93c838349c5f53e28cc2863cf54f7e ; 
	fmap["call_0c6c7064d1b67674b42721dcf159e554"] = (void *) &call_0c6c7064d1b67674b42721dcf159e554 ; 
	fmap["call_0e757cd60b7235565b009c7f90c5ce62"] = (void *) &call_0e757cd60b7235565b009c7f90c5ce62 ; 
	fmap["call_0f918d474b775f067714ee43559e5434"] = (void *) &call_0f918d474b775f067714ee43559e5434 ; 
	fmap["call_10f0d09ec2a398d1beb65533f118d5fd"] = (void *) &call_10f0d09ec2a398d1beb65533f118d5fd ; 
	fmap["call_116c98fe90386fc618a04137cd19b63d"] = (void *) &call_116c98fe90386fc618a04137cd19b63d ; 
	fmap["call_16687a8c7c6d6d130b381a881321a005"] = (void *) &call_16687a8c7c6d6d130b381a881321a005 ; 
	fmap["call_178591db5c7372022010d2a67a9b7657"] = (void *) &call_178591db5c7372022010d2a67a9b7657 ; 
	fmap["call_17f1447d8d94b7387f8487dcd099260f"] = (void *) &call_17f1447d8d94b7387f8487dcd099260f ; 
	fmap["call_18483579d8e099ed78369e9efdd9c39f"] = (void *) &call_18483579d8e099ed78369e9efdd9c39f ; 
	fmap["call_18982b4b7da20b5956d4ddd29ce87758"] = (void *) &call_18982b4b7da20b5956d4ddd29ce87758 ; 
	fmap["call_1a1142f848ddff90134cf2a31003c0c1"] = (void *) &call_1a1142f848ddff90134cf2a31003c0c1 ; 
	fmap["call_1a28d6c48323e37e2b380e74aad66f54"] = (void *) &call_1a28d6c48323e37e2b380e74aad66f54 ; 
	fmap["call_1b079f23c9f2e2b127e2e1069bd57d03"] = (void *) &call_1b079f23c9f2e2b127e2e1069bd57d03 ; 
	fmap["call_1d74840e9207d67849de0464474c0945"] = (void *) &call_1d74840e9207d67849de0464474c0945 ; 
	fmap["call_23b5cf985249175896fe1f7a7d0b9354"] = (void *) &call_23b5cf985249175896fe1f7a7d0b9354 ; 
	fmap["call_2a8b57ddc17094fa96c60ef7ad664593"] = (void *) &call_2a8b57ddc17094fa96c60ef7ad664593 ; 
	fmap["call_2b4e64d9e5905f8462bafc8567176bc3"] = (void *) &call_2b4e64d9e5905f8462bafc8567176bc3 ; 
	fmap["call_2beb4dd9251cb3e58b14c98a0d4223d1"] = (void *) &call_2beb4dd9251cb3e58b14c98a0d4223d1 ; 
	fmap["call_2c43a850375e29e1a29ebf06b7e19c7f"] = (void *) &call_2c43a850375e29e1a29ebf06b7e19c7f ; 
	fmap["call_2c9c8c81633ccf384021920691b364dc"] = (void *) &call_2c9c8c81633ccf384021920691b364dc ; 
	fmap["call_2cd8fbc2f681256d0c24de5a03a9fa18"] = (void *) &call_2cd8fbc2f681256d0c24de5a03a9fa18 ; 
	fmap["call_2d52f1a472bbd8bc778f047231e189aa"] = (void *) &call_2d52f1a472bbd8bc778f047231e189aa ; 
	fmap["call_2e5636f9ee548a895307078ff481642b"] = (void *) &call_2e5636f9ee548a895307078ff481642b ; 
	fmap["call_2e6d1830f6af5bc3bfe19c793b961ed8"] = (void *) &call_2e6d1830f6af5bc3bfe19c793b961ed8 ; 
	fmap["call_3226404ff60d804c68e91acb5706242d"] = (void *) &call_3226404ff60d804c68e91acb5706242d ; 
	fmap["call_330ac74b27c3e8142f30f417a9dc3da2"] = (void *) &call_330ac74b27c3e8142f30f417a9dc3da2 ; 
	fmap["call_340dc32f3e7ceeda734df9317566288b"] = (void *) &call_340dc32f3e7ceeda734df9317566288b ; 
	fmap["call_34f595a3030cc883f5d0bcd308304338"] = (void *) &call_34f595a3030cc883f5d0bcd308304338 ; 
	fmap["call_3539101fa53fce435ea0abaaff8132f3"] = (void *) &call_3539101fa53fce435ea0abaaff8132f3 ; 
	fmap["call_3551095f0502668d9309e879a74e2bb7"] = (void *) &call_3551095f0502668d9309e879a74e2bb7 ; 
	fmap["call_3612a30b453dc657d8c1aac4ab6bffb8"] = (void *) &call_3612a30b453dc657d8c1aac4ab6bffb8 ; 
	fmap["call_36d491c15f6159cd25a33ad4d2262584"] = (void *) &call_36d491c15f6159cd25a33ad4d2262584 ; 
	fmap["call_375f03a71c9e4a0af09bf68563017692"] = (void *) &call_375f03a71c9e4a0af09bf68563017692 ; 
	fmap["call_386828486bca60340a218a5b12c90715"] = (void *) &call_386828486bca60340a218a5b12c90715 ; 
	fmap["call_39593a6fe5c2c42533a877e51734430e"] = (void *) &call_39593a6fe5c2c42533a877e51734430e ; 
	fmap["call_3a4d4af30d56983f64851f92519e5718"] = (void *) &call_3a4d4af30d56983f64851f92519e5718 ; 
	fmap["call_3a835494bf7a51183896653cb7097397"] = (void *) &call_3a835494bf7a51183896653cb7097397 ; 
	fmap["call_3c244bf4129a80c0a2e0b28d2c64827f"] = (void *) &call_3c244bf4129a80c0a2e0b28d2c64827f ; 
	fmap["call_3c7a910b9d9d680c188c1123065df33b"] = (void *) &call_3c7a910b9d9d680c188c1123065df33b ; 
	fmap["call_3d6fdc1ad6a7e829bc79be06a0e35942"] = (void *) &call_3d6fdc1ad6a7e829bc79be06a0e35942 ; 
	fmap["call_3d9afa35b8a5c5d9376cd1573a40645c"] = (void *) &call_3d9afa35b8a5c5d9376cd1573a40645c ; 
	fmap["call_3f2152dbb82fc3bd6f125e49e35f7163"] = (void *) &call_3f2152dbb82fc3bd6f125e49e35f7163 ; 
	fmap["call_3f9445792506a5d8ac3f886d9f053dcd"] = (void *) &call_3f9445792506a5d8ac3f886d9f053dcd ; 
	fmap["call_4021ca0c86840ba0290b68c9d92c17ef"] = (void *) &call_4021ca0c86840ba0290b68c9d92c17ef ; 
	fmap["call_41dec2fc4c17214cd47d4607fef1b7c3"] = (void *) &call_41dec2fc4c17214cd47d4607fef1b7c3 ; 
	fmap["call_41e712db6cbece52d7a00206934af1ec"] = (void *) &call_41e712db6cbece52d7a00206934af1ec ; 
	fmap["call_44fe2f9f36c46a1dc14e634bd0536233"] = (void *) &call_44fe2f9f36c46a1dc14e634bd0536233 ; 
	fmap["call_46aa4554818a2927d268e9fc8894bc02"] = (void *) &call_46aa4554818a2927d268e9fc8894bc02 ; 
	fmap["call_471580551479c7db61b80eff870865d7"] = (void *) &call_471580551479c7db61b80eff870865d7 ; 
	fmap["call_479ac9a2be384300b93e7e3f1c31976d"] = (void *) &call_479ac9a2be384300b93e7e3f1c31976d ; 
	fmap["call_4830064b23695591a6af7d194be6a2a2"] = (void *) &call_4830064b23695591a6af7d194be6a2a2 ; 
	fmap["call_4894654a0f8c779625611cf68a5928a6"] = (void *) &call_4894654a0f8c779625611cf68a5928a6 ; 
	fmap["call_4c2229220e536f222bbdd79ca5a5b429"] = (void *) &call_4c2229220e536f222bbdd79ca5a5b429 ; 
	fmap["call_4cc1602fdb29f1c37ecb5d02fb599ca7"] = (void *) &call_4cc1602fdb29f1c37ecb5d02fb599ca7 ; 
	fmap["call_4d94758a55a5502ff2c19eca5d6744de"] = (void *) &call_4d94758a55a5502ff2c19eca5d6744de ; 
	fmap["call_5187519ea92c8860706738ffe8f71df5"] = (void *) &call_5187519ea92c8860706738ffe8f71df5 ; 
	fmap["call_5276e4197cd56cac0d3a38c53298e890"] = (void *) &call_5276e4197cd56cac0d3a38c53298e890 ; 
	fmap["call_52b6a0c7ae37a49e0262978bc892eb1c"] = (void *) &call_52b6a0c7ae37a49e0262978bc892eb1c ; 
	fmap["call_52d9784c8ba98af51f75c4983377eceb"] = (void *) &call_52d9784c8ba98af51f75c4983377eceb ; 
	fmap["call_53ee6b4eaa295484ee6a6ee8629ddb8d"] = (void *) &call_53ee6b4eaa295484ee6a6ee8629ddb8d ; 
	fmap["call_5985a55ad132563945f92851e9b93973"] = (void *) &call_5985a55ad132563945f92851e9b93973 ; 
	fmap["call_5aa9a69b1361d0efb5650481927a77b8"] = (void *) &call_5aa9a69b1361d0efb5650481927a77b8 ; 
	fmap["call_602ca48e0b0af2dd51e9fb9781fd3709"] = (void *) &call_602ca48e0b0af2dd51e9fb9781fd3709 ; 
	fmap["call_628118e1c962d6a7606216e735267c62"] = (void *) &call_628118e1c962d6a7606216e735267c62 ; 
	fmap["call_6308c0e977da679f337ec6492f040944"] = (void *) &call_6308c0e977da679f337ec6492f040944 ; 
	fmap["call_63909673aa4a98e3b723ed863fc6f43a"] = (void *) &call_63909673aa4a98e3b723ed863fc6f43a ; 
	fmap["call_654893363f89562cd042919f7d1efc24"] = (void *) &call_654893363f89562cd042919f7d1efc24 ; 
	fmap["call_655d406f1a12aef7d487656f5fb26d4a"] = (void *) &call_655d406f1a12aef7d487656f5fb26d4a ; 
	fmap["call_6585d4bdb427baa98f16bf12b74f9d07"] = (void *) &call_6585d4bdb427baa98f16bf12b74f9d07 ; 
	fmap["call_68e75408004d9e261b96d5545c4f7b3b"] = (void *) &call_68e75408004d9e261b96d5545c4f7b3b ; 
	fmap["call_6942516ef96064da1e2901a047a92859"] = (void *) &call_6942516ef96064da1e2901a047a92859 ; 
	fmap["call_69f3226397743250901087efacff0721"] = (void *) &call_69f3226397743250901087efacff0721 ; 
	fmap["call_6b57857061b96a0001f6158bfba7c86d"] = (void *) &call_6b57857061b96a0001f6158bfba7c86d ; 
	fmap["call_6b9b6faea3b42e4b82b579d3a752d97d"] = (void *) &call_6b9b6faea3b42e4b82b579d3a752d97d ; 
	fmap["call_6cf598e930fe44f238860b9128685441"] = (void *) &call_6cf598e930fe44f238860b9128685441 ; 
	fmap["call_71100cca4d39751ce99c83e507e84a25"] = (void *) &call_71100cca4d39751ce99c83e507e84a25 ; 
	fmap["call_730f86d42c34ccf5c1bf611deb0e7720"] = (void *) &call_730f86d42c34ccf5c1bf611deb0e7720 ; 
	fmap["call_7357cab132f639dabfbb68bb0a880f8d"] = (void *) &call_7357cab132f639dabfbb68bb0a880f8d ; 
	fmap["call_746b244cde2c72af998d5184c1e4289b"] = (void *) &call_746b244cde2c72af998d5184c1e4289b ; 
	fmap["call_755332e55df4b48e724d3a7af84ab013"] = (void *) &call_755332e55df4b48e724d3a7af84ab013 ; 
	fmap["call_75b34b4e8efbfbfb18cacef3ff79ce6a"] = (void *) &call_75b34b4e8efbfbfb18cacef3ff79ce6a ; 
	fmap["call_7796e255803f6bc0cf957a3f1a947e20"] = (void *) &call_7796e255803f6bc0cf957a3f1a947e20 ; 
	fmap["call_7b01573a1463d1871f51382d3d1d7ff4"] = (void *) &call_7b01573a1463d1871f51382d3d1d7ff4 ; 
	fmap["call_7bde25db51c60d19cbca3371767f1b58"] = (void *) &call_7bde25db51c60d19cbca3371767f1b58 ; 
	fmap["call_7d7ab754a9b95691cfdde507875d3061"] = (void *) &call_7d7ab754a9b95691cfdde507875d3061 ; 
	fmap["call_7dfcd46e6055a7435746afa5927271db"] = (void *) &call_7dfcd46e6055a7435746afa5927271db ; 
	fmap["call_7e35e9e7e5aba24c437973d7f9a61b86"] = (void *) &call_7e35e9e7e5aba24c437973d7f9a61b86 ; 
	fmap["call_813f96afc50911138c661dd51950492d"] = (void *) &call_813f96afc50911138c661dd51950492d ; 
	fmap["call_828a9d190c46f71761b5c41f4203b93a"] = (void *) &call_828a9d190c46f71761b5c41f4203b93a ; 
	fmap["call_834ebc4a7dd7bd617db75fddc7141535"] = (void *) &call_834ebc4a7dd7bd617db75fddc7141535 ; 
	fmap["call_837416003779b7e337f5285dfea13caa"] = (void *) &call_837416003779b7e337f5285dfea13caa ; 
	fmap["call_85db5ee2ab1d24d70ef55d3210fbbac6"] = (void *) &call_85db5ee2ab1d24d70ef55d3210fbbac6 ; 
	fmap["call_86b3f78cc5d099d95c904c2f639801df"] = (void *) &call_86b3f78cc5d099d95c904c2f639801df ; 
	fmap["call_8a82ec7cad0636c9213c0fbcc743733e"] = (void *) &call_8a82ec7cad0636c9213c0fbcc743733e ; 
	fmap["call_8c61a75760d0083e2cb49767853c0802"] = (void *) &call_8c61a75760d0083e2cb49767853c0802 ; 
	fmap["call_8deabf99162c03b41a8aed3096475a1f"] = (void *) &call_8deabf99162c03b41a8aed3096475a1f ; 
	fmap["call_8eb0a994cd80a6ac5f48a0eac6aa8da4"] = (void *) &call_8eb0a994cd80a6ac5f48a0eac6aa8da4 ; 
	fmap["call_8f3da4a32a10b03ef8278341ba6f586e"] = (void *) &call_8f3da4a32a10b03ef8278341ba6f586e ; 
	fmap["call_8f4da1a8d5270ed812aef6f9eb1ec49d"] = (void *) &call_8f4da1a8d5270ed812aef6f9eb1ec49d ; 
	fmap["call_907b8209f353bb98eace89067afcec0d"] = (void *) &call_907b8209f353bb98eace89067afcec0d ; 
	fmap["call_922578de4678ac78d9f5989406c590ec"] = (void *) &call_922578de4678ac78d9f5989406c590ec ; 
	fmap["call_9287f4bc38a2ac5457ad661034723054"] = (void *) &call_9287f4bc38a2ac5457ad661034723054 ; 
	fmap["call_92f558cdc5d5bb606ade889355aaff43"] = (void *) &call_92f558cdc5d5bb606ade889355aaff43 ; 
	fmap["call_9376bccff3d63129ec69af653442cee0"] = (void *) &call_9376bccff3d63129ec69af653442cee0 ; 
	fmap["call_98467f237f93b280b2785a25087254f8"] = (void *) &call_98467f237f93b280b2785a25087254f8 ; 
	fmap["call_98ab48d6ea6663d494105ded831e534a"] = (void *) &call_98ab48d6ea6663d494105ded831e534a ; 
	fmap["call_9b07fa1affdb10adab342f9030ea341f"] = (void *) &call_9b07fa1affdb10adab342f9030ea341f ; 
	fmap["call_9dddb41c709118d2172771d5b299b3fc"] = (void *) &call_9dddb41c709118d2172771d5b299b3fc ; 
	fmap["call_a0ed09161e5638249ea4fd3525cfc6df"] = (void *) &call_a0ed09161e5638249ea4fd3525cfc6df ; 
	fmap["call_a282d446c5073c38d2baa9d2634fc74f"] = (void *) &call_a282d446c5073c38d2baa9d2634fc74f ; 
	fmap["call_a3b4515d2c469e01d6b693c530db3809"] = (void *) &call_a3b4515d2c469e01d6b693c530db3809 ; 
	fmap["call_a3f9686634d8f0c5cd012280d7d4cc45"] = (void *) &call_a3f9686634d8f0c5cd012280d7d4cc45 ; 
	fmap["call_a4230cd216c73e2b9b2b9b05493023a2"] = (void *) &call_a4230cd216c73e2b9b2b9b05493023a2 ; 
	fmap["call_a50e1f55987d314a4ac296a7d7c995ef"] = (void *) &call_a50e1f55987d314a4ac296a7d7c995ef ; 
	fmap["call_a51b30884986af971213422277600489"] = (void *) &call_a51b30884986af971213422277600489 ; 
	fmap["call_a5b8e838b4149ebfc256ade78114d940"] = (void *) &call_a5b8e838b4149ebfc256ade78114d940 ; 
	fmap["call_a67fe44b26ef01dcda9f32ed11d6789b"] = (void *) &call_a67fe44b26ef01dcda9f32ed11d6789b ; 
	fmap["call_a6e41565e6126bc654455f48b24bb83f"] = (void *) &call_a6e41565e6126bc654455f48b24bb83f ; 
	fmap["call_a7e3b5b5c89ee1e8695b678404663a40"] = (void *) &call_a7e3b5b5c89ee1e8695b678404663a40 ; 
	fmap["call_a8df3af7cb5fe6faf9a0219ea6ca48cb"] = (void *) &call_a8df3af7cb5fe6faf9a0219ea6ca48cb ; 
	fmap["call_a8fc2beadd070d0fa1b440336c98cf62"] = (void *) &call_a8fc2beadd070d0fa1b440336c98cf62 ; 
	fmap["call_a99f0dd270b91d81d05c527e46c4eaac"] = (void *) &call_a99f0dd270b91d81d05c527e46c4eaac ; 
	fmap["call_aac989c73cf9a878b439e771fcb257cf"] = (void *) &call_aac989c73cf9a878b439e771fcb257cf ; 
	fmap["call_abb833c470857b79df9f1ecd89cbca26"] = (void *) &call_abb833c470857b79df9f1ecd89cbca26 ; 
	fmap["call_ada66833da654eabccfd196ac649e500"] = (void *) &call_ada66833da654eabccfd196ac649e500 ; 
	fmap["call_afbe5b8e6d348f7ba855808e42d3cdfe"] = (void *) &call_afbe5b8e6d348f7ba855808e42d3cdfe ; 
	fmap["call_b0e8f1d124c3efce72291b857931c13d"] = (void *) &call_b0e8f1d124c3efce72291b857931c13d ; 
	fmap["call_b24f762393f9be1ed151f099bdef976c"] = (void *) &call_b24f762393f9be1ed151f099bdef976c ; 
	fmap["call_b3629c6e274682b652b8235b7e4333b4"] = (void *) &call_b3629c6e274682b652b8235b7e4333b4 ; 
	fmap["call_b380ee0c312278649c5ffda6803d8d26"] = (void *) &call_b380ee0c312278649c5ffda6803d8d26 ; 
	fmap["call_b41731624f42047331b4137d032eb7f6"] = (void *) &call_b41731624f42047331b4137d032eb7f6 ; 
	fmap["call_b4d4a7c958d00599327cd46ab0d33562"] = (void *) &call_b4d4a7c958d00599327cd46ab0d33562 ; 
	fmap["call_b68b551ff9247e464844194a76503b54"] = (void *) &call_b68b551ff9247e464844194a76503b54 ; 
	fmap["call_b965185d7179dad78ca8b04360615f33"] = (void *) &call_b965185d7179dad78ca8b04360615f33 ; 
	fmap["call_bc0447d8dd2eb055013601db9f63c1c0"] = (void *) &call_bc0447d8dd2eb055013601db9f63c1c0 ; 
	fmap["call_c11b7e69b9a3b663eecd771a2e7b5e20"] = (void *) &call_c11b7e69b9a3b663eecd771a2e7b5e20 ; 
	fmap["call_c2647a120b5b43c63eedc6ad775c2e4a"] = (void *) &call_c2647a120b5b43c63eedc6ad775c2e4a ; 
	fmap["call_c2ff4ce1d2ba56134c6dcb4936a2ad80"] = (void *) &call_c2ff4ce1d2ba56134c6dcb4936a2ad80 ; 
	fmap["call_c53f1da5d1098de1e07fe41f67eac489"] = (void *) &call_c53f1da5d1098de1e07fe41f67eac489 ; 
	fmap["call_c630d03c28159edfd6b41e32b6133d0b"] = (void *) &call_c630d03c28159edfd6b41e32b6133d0b ; 
	fmap["call_c7aa8f1e9e36c4a3fc7ba2a83867d8e6"] = (void *) &call_c7aa8f1e9e36c4a3fc7ba2a83867d8e6 ; 
	fmap["call_c8123927c84f5634705a0e3428c9cfb3"] = (void *) &call_c8123927c84f5634705a0e3428c9cfb3 ; 
	fmap["call_c8c490bae186ccc423be53957a5da680"] = (void *) &call_c8c490bae186ccc423be53957a5da680 ; 
	fmap["call_c9f5b4046f71c9c458664aebb1182df9"] = (void *) &call_c9f5b4046f71c9c458664aebb1182df9 ; 
	fmap["call_ca7587555378e3cc79833947d83d47cc"] = (void *) &call_ca7587555378e3cc79833947d83d47cc ; 
	fmap["call_cb79ac6b604af5e44d8792256505212b"] = (void *) &call_cb79ac6b604af5e44d8792256505212b ; 
	fmap["call_cbf1bfec9da6c5673a05f5d8d609364f"] = (void *) &call_cbf1bfec9da6c5673a05f5d8d609364f ; 
	fmap["call_cd284c2516aa6afd8452a83bb37257c6"] = (void *) &call_cd284c2516aa6afd8452a83bb37257c6 ; 
	fmap["call_cdb74c65b31c8c9c808e6241378c9391"] = (void *) &call_cdb74c65b31c8c9c808e6241378c9391 ; 
	fmap["call_cf7bead502a5bf6dc5a1e4971f134e3a"] = (void *) &call_cf7bead502a5bf6dc5a1e4971f134e3a ; 
	fmap["call_d0466c6ecf77b654c738065f186c3244"] = (void *) &call_d0466c6ecf77b654c738065f186c3244 ; 
	fmap["call_d0b714f20d3618a23f5c379d8aba7e20"] = (void *) &call_d0b714f20d3618a23f5c379d8aba7e20 ; 
	fmap["call_d315f97464ca63ecc5c6f08af8957f1b"] = (void *) &call_d315f97464ca63ecc5c6f08af8957f1b ; 
	fmap["call_d31c90b62cf90ba21fda300ed65b3115"] = (void *) &call_d31c90b62cf90ba21fda300ed65b3115 ; 
	fmap["call_d570c94925faf90878c7477ec70a0faa"] = (void *) &call_d570c94925faf90878c7477ec70a0faa ; 
	fmap["call_d664126d6759cfa421f46dc3ccf153ea"] = (void *) &call_d664126d6759cfa421f46dc3ccf153ea ; 
	fmap["call_d94650c9f181b5719a909169c77653dc"] = (void *) &call_d94650c9f181b5719a909169c77653dc ; 
	fmap["call_db80f8c9e69321f883d324eb19079b48"] = (void *) &call_db80f8c9e69321f883d324eb19079b48 ; 
	fmap["call_dd889476d995a77a862ea2fb5d576952"] = (void *) &call_dd889476d995a77a862ea2fb5d576952 ; 
	fmap["call_deb0fee25f1e7b7bedb93714a46341b8"] = (void *) &call_deb0fee25f1e7b7bedb93714a46341b8 ; 
	fmap["call_dec2664a1fe34f6af692db579b083623"] = (void *) &call_dec2664a1fe34f6af692db579b083623 ; 
	fmap["call_df50b9eb5067c0b36c5a6fbb9fd7b389"] = (void *) &call_df50b9eb5067c0b36c5a6fbb9fd7b389 ; 
	fmap["call_df6ff67bdcd8961b3dc93e126e908cd4"] = (void *) &call_df6ff67bdcd8961b3dc93e126e908cd4 ; 
	fmap["call_e1d13c1c4e8e03ed66fa40881414a9cb"] = (void *) &call_e1d13c1c4e8e03ed66fa40881414a9cb ; 
	fmap["call_e275d27556904ee35697caff0b637bbd"] = (void *) &call_e275d27556904ee35697caff0b637bbd ; 
	fmap["call_e534e35af6b9563a11f771bb8c7e3c96"] = (void *) &call_e534e35af6b9563a11f771bb8c7e3c96 ; 
	fmap["call_e561000695f157d5cbe9ce6a549a2efb"] = (void *) &call_e561000695f157d5cbe9ce6a549a2efb ; 
	fmap["call_e5985f06daf02647b6fcd254e5c5882e"] = (void *) &call_e5985f06daf02647b6fcd254e5c5882e ; 
	fmap["call_e611523a7e6a087733ffc5df4968398b"] = (void *) &call_e611523a7e6a087733ffc5df4968398b ; 
	fmap["call_e8894ade3fc514d54ae656001a16a2f9"] = (void *) &call_e8894ade3fc514d54ae656001a16a2f9 ; 
	fmap["call_e8b17796de113e1b4ae5027aa31bdf46"] = (void *) &call_e8b17796de113e1b4ae5027aa31bdf46 ; 
	fmap["call_eb80c1ab146f7c5b5bb0dd426b22554f"] = (void *) &call_eb80c1ab146f7c5b5bb0dd426b22554f ; 
	fmap["call_ebe471ffc86c39419cb930d4c0d99376"] = (void *) &call_ebe471ffc86c39419cb930d4c0d99376 ; 
	fmap["call_edd318b850a586afb3c52877b989a956"] = (void *) &call_edd318b850a586afb3c52877b989a956 ; 
	fmap["call_eddf2b48584029d010051fd5e6738201"] = (void *) &call_eddf2b48584029d010051fd5e6738201 ; 
	fmap["call_edecbd49e6ae28211a12d42213fd7e44"] = (void *) &call_edecbd49e6ae28211a12d42213fd7e44 ; 
	fmap["call_ef7ce0528df23ebd0d6b0b275eac2722"] = (void *) &call_ef7ce0528df23ebd0d6b0b275eac2722 ; 
	fmap["call_f0669ee522ea85be5b0aa2d751d19bad"] = (void *) &call_f0669ee522ea85be5b0aa2d751d19bad ; 
	fmap["call_f481673829e119a23f29e6ab8d9bf5eb"] = (void *) &call_f481673829e119a23f29e6ab8d9bf5eb ; 
	fmap["call_f481e23187341d3d86076d1a9e9bbe18"] = (void *) &call_f481e23187341d3d86076d1a9e9bbe18 ; 
	fmap["call_f493065b9eab7f005dff6e70da4f2f57"] = (void *) &call_f493065b9eab7f005dff6e70da4f2f57 ; 
	fmap["call_f4f6614d2fe82ccc7912092d2c149eb1"] = (void *) &call_f4f6614d2fe82ccc7912092d2c149eb1 ; 
	fmap["call_f60c0734a432524a16089d5e525792e9"] = (void *) &call_f60c0734a432524a16089d5e525792e9 ; 
	fmap["call_f91ee53e472c2bb6604eafeac60dff98"] = (void *) &call_f91ee53e472c2bb6604eafeac60dff98 ; 
	fmap["call_fc0220403eac7c57c2b94a643bc8188f"] = (void *) &call_fc0220403eac7c57c2b94a643bc8188f ; 
	fmap["call_fdcb0169866a5dfe6abd49e991198542"] = (void *) &call_fdcb0169866a5dfe6abd49e991198542 ; 
	fmap["call_febdf4da78dbf024627e5159650c2693"] = (void *) &call_febdf4da78dbf024627e5159650c2693 ; 
	fmap["call_fef23e677f07f08a3802edcc480fa2b8"] = (void *) &call_fef23e677f07f08a3802edcc480fa2b8 ; 
	fmap["call_ff6e6d23b5563a7427b2d5326d46c48c"] = (void *) &call_ff6e6d23b5563a7427b2d5326d46c48c ; 
	fmap["call_ffd925f2ac6fb223ff612dea320fe3f8"] = (void *) &call_ffd925f2ac6fb223ff612dea320fe3f8 ; 

}
