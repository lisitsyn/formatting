cmake_minimum_required(VERSION 2.6)
project(Format)

set (FORMATTER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set (FORMATTER_TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${FORMATTER_INCLUDE_DIR})

if(MSVC)
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	# Update if necessary
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

option(BUILD_TESTS "Build tests" ON)

if (BUILD_TESTS)
	if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/gtest-1.6.0/)
		add_subdirectory(gtest-1.6.0)
		set(GTEST_SOURCE_DIR ${gtest_SOURCE_DIR})
		include_directories(SYSTEM ${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})
	else()
		if (NOT GTEST_SOURCE_DIR)
			# try with default ubuntu location
			set(GTEST_SOURCE_DIR /usr/src/gtest)
		endif()
		if (NOT GTEST_INCLUDE_DIR)
			# try with default ubuntu location
			set(GTEST_INCLUDE_DIR /usr/include/gtest)
		endif()
		if (GTEST_SOURCE_DIR AND GTEST_INCLUDE_DIR)
			include_directories(${GTEST_SOURCE_DIR})
			include_directories(${GTEST_INCLUDE_DIR}/include)
			add_library(gtest STATIC ${GTEST_SOURCE_DIR}/src/gtest-all.cc)
			add_library(gtest_main STATIC ${GTEST_SOURCE_DIR}/src/gtest_main.cc)
			target_link_libraries(gtest_main gtest)
			find_package(Threads)
			target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})
		else()
			message(FATAL_ERROR "gtest-1.6.0 is required to be available in the root of the project or reachable 
			                     by GTEST_SOURCE_DIR and GTEST_INCLUDE_DIR")
		endif()
	endif()
	enable_testing()

	aux_source_directory(${FORMATTER_TESTS_DIR} FORMATTER_TESTS_SOURCES)
	foreach(i ${FORMATTER_TESTS_SOURCES})
		get_filename_component(exe ${i} NAME_WE)
		add_executable(test_${exe} ${i})
		target_link_libraries(test_${exe} gtest gtest_main)
		add_test(
			NAME ${exe}
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
			COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_${exe}
			--gtest_color=yes)
	endforeach()
endif()

