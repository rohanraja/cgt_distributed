//#define trace(x)
#define trace(x)                 cerr << #x << ": " << x << endl;

// #define trace(x)                 printf("%s: %x\n", #x, x);

#define readf(f,v) f.read((char *)&v, sizeof(v))
#define readfs(f,v,s) f.read((char *)v, s)

#define rep(i,n) for(int i=0; i<n; i++)

#define writef(f,v) f.write((char *)&v, sizeof(v))
#define rep(i,n) for(int i=0; i<n; i++)

typedef int size_data;

#define ARGVEC vector<cgtTuple*>