cmake_minimum_required(VERSION 3.17.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_VERBOSE_MAKEFILE ON)
project(VulnurableCpp VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

add_executable(VulnurableCpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)

FetchContent_Declare(json
		GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
		GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
	FetchContent_Populate(json)
	add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

configure_file(config.json config.json COPYONLY)

target_link_libraries(VulnurableCpp PUBLIC nlohmann_json::nlohmann_json)


##POCO
#https://stackoverflow.com/questions/58592243/how-to-use-poco-library-in-a-simple-c-project
add_subdirectory(dependencies/poco)
target_link_libraries(VulnurableCpp PUBLIC PocoNet PocoXML) # replace `...` by all poco library you use