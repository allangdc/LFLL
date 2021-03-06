set(SOURCES_FILES

main.cpp
LFLLBenchmark.h
MamdaniAllTerms.cpp
MamdaniAllTerms.h
MamdaniBenchmark.cpp
SugenoAllTerms.cpp
SugenoAllTerms.h
SugenoBenchmark.cpp
)



set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake_modules" ${CMAKE_MODULE_PATH})
find_package(LFLL REQUIRED)
include_directories(${LFLL_INCLUDE_DIR})
message(STATUS "LFLL_INCLUDE_DIR = ${LFLL_INCLUDE_DIR}")

find_path(HAYAI_INCLUDE_DIR hayai.hpp 
  "${CMAKE_CURRENT_SOURCE_DIR}/hayai/src"
   ${CMAKE_SYSTEM_INCLUDE_DIRECTORIES}
)

message(STATUS "HAYAI_INCLUDE_DIR = ${HAYAI_INCLUDE_DIR}")
if(${HAYAI_INCLUDE_DIR} STREQUAL "HAYAI_INCLUDE_DIR-NOTFOUND")
	message(STATUS "Hayai not found, benchmark has been deactivated. "
		"You should run 'git submodule init && git submodule update' before running cmake")
else()

    if (${STRICT_MODE})
        # Hayai warning ignore
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-delete-non-virtual-dtor")
        elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND
            (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "4.7.0" OR
            CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL "4.7.0"))
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-delete-non-virtual-dtor")
        elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        endif()
    endif()
    
    include(CheckLibraryExists)
    CHECK_LIBRARY_EXISTS(rt clock_gettime "time.h" NEED_RT_LIB)
	
	include_directories(${HAYAI_INCLUDE_DIR})
	add_executable(benchmark ${SOURCES_FILES})
	if (${NEED_RT_LIB})
	    target_link_libraries(benchmark rt)
	endif()
endif()

