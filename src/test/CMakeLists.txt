# 指定在哪里找链接库
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(questions 1 2 3 4 5 6 18)

foreach(X IN LISTS questions)
	# 指示在哪里找头文件
	include_directories(${CMAKE_SOURCE_DIR}/p${X})

	add_executable (p${X}Test  catch_cache.cpp "p${X}Test.cpp")

	# 指定pX需要链接哪些库
	target_link_libraries(p${X}Test "p${X}")
endforeach()

