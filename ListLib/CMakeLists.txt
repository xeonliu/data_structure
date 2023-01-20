project(list_implementation)
set(HEADER_FILES
        list.h
        seqList.h
        SLList.h
        DLList.h)
add_library(ListLib STATIC ${HEADER_FILES})
set_target_properties(ListLib PROPERTIES LINKER_LANGUAGE CXX)
