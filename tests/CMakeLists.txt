add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest)
set(TEST_BINARY ${PROJECT_NAME}_test)