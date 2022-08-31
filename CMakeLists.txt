project(lsspinlock)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(include)

link_directories(/usr/local/lib)

aux_source_directory(src/ls SRC)

aux_source_directory(sample SAMPLE)

add_library(lsspinlock SHARED  ${SRC})

add_executable(testcase ${SAMPLE} ${SRC})

target_link_libraries(testcase pthread)

install(TARGETS lsspinlock DESTINATION lib)

install(DIRECTORY include/ls DESTINATION include)
