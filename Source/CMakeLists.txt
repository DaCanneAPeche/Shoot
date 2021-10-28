# Settings
include_directories(${CMAKE_SOURCE_DIR}/../Header)

# Files
file(GLOB_RECURSE SHOOT_SOURCES *.cpp *.c)
file(GLOB_RECURSE SHOOT_HEADERS *.hpp *.h *.inl)

add_executable(${PROJECT_NAME} ${SHOOT_SOURCES} ${SHOOT_HEADERS})

include(FetchContent)

FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/master.tar.gz
)

FetchContent_MakeAvailable(raylib)

target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
