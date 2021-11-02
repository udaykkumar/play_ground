
# Minimum CMake
cmake_minimum_required (VERSION 2.8,9)
project(play_offline)
enable_testing()

add_subdirectory( play_c )
add_subdirectory( play_cpp )
add_subdirectory( play_ping_pong )
add_subdirectory( play_servers )
#add_subdirectory( play_graphics )
add_subdirectory( play_books )
