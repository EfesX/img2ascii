cmake_minimum_required(VERSION 3.14)

# set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE FILEPATH "vcpkg toolchain")

project(
    img2ascii
    VERSION 0.1.0
    DESCRIPTION "The converter images to ASCII art"
    HOMEPAGE_URL "https://github.com/EfesX/img2ascii"
    LANGUAGES CXX
)

find_package(OpenCV CONFIG REQUIRED)

add_executable(img2ascii img2ascii.cpp)
target_link_libraries(img2ascii PRIVATE ${OpenCV_LIBS})

include(GNUInstallDirs)
install(
    TARGETS img2ascii
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
