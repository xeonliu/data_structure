project(stack_implementation)
set(HEADER_FILES
        stack.h
        seqStack.h listStack.h)
add_library(StackLib STATIC ${HEADER_FILES})
set_target_properties(StackLib PROPERTIES LINKER_LANGUAGE CXX)