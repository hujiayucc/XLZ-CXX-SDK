cmake_minimum_required(VERSION 3.30)
project(main CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(nlohmann_json)

add_library(main SHARED main.cpp
        src/api.cpp
        src/appinfo.cpp
        src/TextCode.cpp
        src/MessageTools.cpp
        src/utils.cpp
)
add_executable(test test.cpp)

target_include_directories(main PUBLIC "include")
target_compile_definitions(main PUBLIC XLZ_EXPORTS)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

if(MSVC)
    # 除了MT其他都可以删除
    target_compile_options(main PRIVATE /MT /O2 /Ob3 /GL /arch:AVX2 /fp:fast /Qpar)
    target_link_options(main PRIVATE /LTCG:incremental /OPT:REF,ICF)
endif()
set_target_properties(main PROPERTIES OUTPUT_NAME "XLZ")
set_target_properties(test PROPERTIES OUTPUT_NAME "Test")