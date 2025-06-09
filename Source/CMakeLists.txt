cmake_minimum_required(VERSION 3.26)

# INCLUDE 3RD PARTY LIBRARIES
include("${CMAKE_SOURCE_DIR}/Scripts/FetchLibraries.cmake")

# POPULATE 3RD PARTY LIBRARIES
FetchContent_MakeAvailable(glfw)

# OBTER OS ARQUIVOS FONTE
file(GLOB_RECURSE SUBDIRECTORIES
    "${CMAKE_SOURCE_DIR}/Source/*.h"
    "${CMAKE_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_SOURCE_DIR}/Source/*.hpp"
)
source_group("Source" FILES ${SUBDIRECTORIES})

# CRIAR EXECUTÁVEL
add_executable(D3DTutorial ${SUBDIRECTORIES})

# INCLUDE DIRECTORIES E LINKAGEM
target_include_directories(D3DTutorial PRIVATE "${CMAKE_SOURCE_DIR}/Source")
target_link_libraries(D3DTutorial PRIVATE glfw)

# DEFINIÇÕES DE COMPILAÇÃO
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(D3DTutorial PUBLIC TUTORIAL_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(D3DTutorial PUBLIC TUTORIAL_RELEASE)
endif()

# DEFINIÇÕES DE MACROS POR COMPILADOR
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_definitions(D3DTutorial PUBLIC RUNTIME_API=__declspec\(dllexport\))
    target_compile_definitions(D3DTutorial PUBLIC FORCE_INLINE=__forceinline)
else()
    message(FATAL_ERROR "Unsupported Compiler")
endif()
