
import glob



allso = glob.glob("/Users/rraja/.cgt_cache/*.so") 
prefixes = map(lambda f: f.split("/")[-1].split(".")[0], allso)
print prefixes
files = map(lambda p: "/Users/rraja/.cgt_cache/" + p + "_0.cpp", prefixes)
funcs = map(lambda p: "call_" + p, prefixes)
print funcs

out = """
"""

for fil in files:
    f = open(fil, 'r')

    out += "\n"
    out += f.read()
    f.close

map_code = """

#include<map>
std::map<std::string, void *> fmap;

void create_functions_map(){

"""

for func in funcs:
    fcode = "\tfmap[\"%s\"] = (void *) &%s ; \n" % (func, func)
    map_code += fcode

map_code += """
}
"""


out += map_code



print out

f = open("all.cpp", 'w')
f.write(out)
f.close()

outnew = ""
incls = []

f = open("all.cpp", 'r')

while True:
    line = f.readline()
    if not line:
        break
    if "#include" in line:
        if line not in incls:
            incls.append(line)
        continue
    outnew += line

f.close()

f = open("all.cpp", 'w')
heads = '\n'.join(incls)
f.write(heads + outnew)
f.close()
