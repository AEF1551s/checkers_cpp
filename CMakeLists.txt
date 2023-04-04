# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.22)

# Set the project name
project(checkers_cpp)

set (CMAKE_CXX_STANDARD 23)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
    # src/game.cpp
    # src/checkers.cpp
    src/texture_manager.cpp
    src/game_window.cpp
    src/event_manager.cpp
    src/game_board.cpp
    src/game_manager.cpp
)

# Add an executable with the above sources
add_executable(checkers_cpp ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(checkers_cpp
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)