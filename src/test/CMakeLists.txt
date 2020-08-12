# 指示在哪里找头文件
include_directories(${CMAKE_SOURCE_DIR}/p1)

# 指定在哪里找链接库
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable (p1Test  catch_cache.cpp "p1Test.cpp")


# 指定p1需要链接哪些库
target_link_libraries(p1Test "p1")
