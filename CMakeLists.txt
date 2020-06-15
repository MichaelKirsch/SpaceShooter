set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME SpaceShooter)
project(${PROJECT_NAME})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp") #glob all the source files intp one place
file(COPY libs/SFML-2.5.1/bin/openal32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

find_package(OpenGL REQUIRED)
file(COPY "data"  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system ${OPENGL_LIBRARIES} )