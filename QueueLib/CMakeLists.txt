project(queue_implementation)
set(HEADER_FILES
        queue.h
        seqQueue.h linkedQueue.h)
add_library(QueueLib STATIC ${HEADER_FILES})
set_target_properties(QueueLib PROPERTIES LINKER_LANGUAGE CXX)