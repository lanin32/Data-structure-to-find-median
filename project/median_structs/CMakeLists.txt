#include_directories()

set(This median_structs)

set(MEDIAN_STRUCTURES_SRC
	MedianList.h MedianList.cpp
	MedianHeap.h MedianHeap.cpp
)

SET (LIB_TYPE STATIC)

add_library (${This} ${LIB_TYPE} ${MEDIAN_STRUCTURES_SRC})