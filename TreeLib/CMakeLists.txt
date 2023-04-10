project(bTree_implementation)
set(HEADER_FILES
        bTree.h
        huffmantree.h)
set (SOURCE_FILES main.cpp)
add_executable(binarytree ${SOURCE_FILES})
add_library(BTreeLib STATIC ${HEADER_FILES})
set_target_properties(BTreeLib PROPERTIES LINKER_LANGUAGE CXX)
