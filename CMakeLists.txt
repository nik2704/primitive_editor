cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(vector_editor VERSION ${PROJECT_VERSION})

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

# Найти fmt
find_package(fmt REQUIRED)

add_executable(vector_editor
    main.cpp
    model/Document.cpp
    model/primitives/Circle.cpp
    model/primitives/Rectangle.cpp
    model/primitives/Line.cpp
    model/primitives/Polyline.cpp
    view/Renderer.cpp
    controller/Controller.cpp
)

set_target_properties(vector_editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(vector_editor
    PRIVATE "${CMAKE_BINARY_DIR}"
)

# Линковка с fmt
target_link_libraries(vector_editor PRIVATE fmt::fmt)

if (MSVC)
    target_compile_options(vector_editor PRIVATE
        /W4
    )
    target_compile_options(vector_editor PRIVATE
        /W4
    )
else ()
    target_compile_options(vector_editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS vector_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)