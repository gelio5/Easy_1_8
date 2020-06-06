set(SOURCES
        BinFile.cpp
        BinFile.h)
add_library(BinFile ${SOURCES})
target_include_directories(BinFile PUBLIC ${SRC_ROOT_DIR})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES})
add_subdirectory(tests)