cmake_minimum_required(VERSION 3.23)

project(vector3d LANGUAGES CXX VERSION 1.0.0)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(GTest REQUIRED)

add_library(vector3d SHARED)
target_sources(vector3d
    PRIVATE
        vector3d.cpp
    PUBLIC
        FILE_SET HEADERS
            BASE_DIRS ${PROJECT_SOURCE_DIR}
            FILES
                vector3d.hpp
)
target_include_directories(vector3d
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(vector3d_unittests)
target_sources(vector3d_unittests PRIVATE vector3d_unittests.cpp)
target_include_directories(vector3d_unittests PRIVATE "${GTEST_INCLUDE_DIRS}")
target_link_libraries(vector3d_unittests
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        vector3d
)


install(TARGETS vector3d
    EXPORT vector3dTargets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

install(EXPORT vector3dTargets
    FILE vector3dTargets.cmake
    NAMESPACE vector3d::
    DESTINATION lib/cmake/vector3d)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "myLibraryConfigVersion.cmake"
    VERSION ${vector3d_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(
    FILES
        "vector3dConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/vector3dConfigVersion.cmake"
    DESTINATION lib/cmake/vector3d
)
