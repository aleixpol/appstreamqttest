cmake_minimum_required(VERSION 3.0)

project(appstreamqttest)

find_package(Qt5 COMPONENTS Core)
find_package(AppstreamQt)

add_executable(appstreamqttest main.cpp)
target_link_libraries(appstreamqttest AppstreamQt)

install(TARGETS appstreamqttest RUNTIME DESTINATION bin)
