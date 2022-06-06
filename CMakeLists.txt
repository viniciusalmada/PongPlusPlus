cmake_minimum_required(VERSION 3.15.0)
project(PongPlusPlus VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

###############################################################################
## GLOBAL VARIABLES
###############################################################################
if (UNIX)
add_compile_options(-Wall -Wextra -Werror)
elseif(WIN32)
add_compile_options(/W4 /WX)
endif(UNIX)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

###############################################################################
## MAIN EXECUTABLE
###############################################################################
add_executable(PongPlusPlus src/main.cpp
                            src/ball.cpp
                            src/board.cpp
                            src/game_app.cpp
                            src/game_window.cpp
                            src/player.cpp)

target_include_directories(PongPlusPlus PRIVATE vendor include)

if(UNIX)
target_link_directories(PongPlusPlus 
  PRIVATE "${PROJECT_SOURCE_DIR}/lib/linux/GraRen/"
  PRIVATE "${PROJECT_SOURCE_DIR}/lib/linux/GL3H/")
target_link_libraries(PongPlusPlus -lGraRen -lGL3H -lglfw -lGLEW -lGL)
elseif(WIN32)
target_link_libraries(PongPlusPlus 
  ${PROJECT_SOURCE_DIR}/lib/win/GLFW/glfw3dll.lib 
  ${PROJECT_SOURCE_DIR}/lib/win/GLEW/glew32.lib 
  ${PROJECT_SOURCE_DIR}/lib/win/GraRen/GraRen.lib 
  opengl32.lib)

target_link_options(PongPlusPlus PRIVATE /NODEFAULTLIB:LIBCMT)

add_custom_command(TARGET PongPlusPlus POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GLEW/glew32.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GLFW/glfw3.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GraRen/GraRen.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GL3H/GL3H.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>)
endif(UNIX)
