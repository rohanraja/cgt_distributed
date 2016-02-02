cmake_minimum_required (VERSION 2.6)

OPTION (USE_OMP "Compile With OpenMP for parallel computing") 
OPTION (SIMP "simple executor")
OPTION (DLL "DLL" ON)

project("cgt")

ADD_DEFINITIONS(
    -std=c++11
    -D EXECU
)

if(DLL)
      ADD_DEFINITIONS(
        -Wl,-rpath,../build/OpenBLAS 
        -Wl,-rpath,'$$ORIGIN' 
      )
endif(DLL)

if(USE_OMP)
  find_package(OpenMP)
  if (OPENMP_FOUND)
      set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
      ADD_DEFINITIONS(
        -D OMP
      )
  endif()
endif(USE_OMP)

include_directories("../include")
include_directories(".")
include_directories("../build/OpenBLAS")

cmake_policy(SET CMP0015 NEW)
link_directories("../build/OpenBLAS")
link_directories("../build/lib")

set (SUPPORT_FILES 
  ../src/cgt_common.cpp 
  ../src/execution.cpp 
  trainingJob.cpp
)

if(SIMP)
  
add_executable(
  simp
  noinp.cpp   
  ${SUPPORT_FILES}
)
target_link_libraries(simp openblas pthread)

else(SIMP)

add_executable(
  cgt
  main.cpp   
  ${SUPPORT_FILES}
)
target_link_libraries(cgt openblas pthread)
endif(SIMP)
