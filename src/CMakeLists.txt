include_directories(../lib)

set(BLABL_SOURCES
    key_binding.cpp
    key_listener.cpp
    process.cpp
    main.cpp
    utils.cpp
)

set(BLABL_HEADERS
    key_binding.h
    key_listener.h
    process.h
    utils.h
)

set(BLABL_RESOURCES
)

source_group("Source Files" FILES ${BLABL_SOURCES})
source_group("Header Files" FILES ${BLABL_HEADERS})

if (MINGW)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")

set(RES_FILES "../res/blabl.rc")
set(CMAKE_RC_COMPILER_INIT windres)
enable_language(RC)
set(CMAKE_RC_COMPILE_OBJECT
    "<CMAKE_RC_COMPILER> <FLAGS> -O coff <DEFINES> -i <SOURCE> -o <OBJECT>")
endif()

add_executable(Blabl WIN32 ${BLABL_SOURCES} ${BLABL_HEADERS} ${RES_FILES})

target_link_libraries(Blabl inih)