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

###############################################################################
## MAIN EXECUTABLE
###############################################################################
add_executable(PongPlusPlus src/main.cpp
                            src/ball.cpp
                            src/board.cpp
                            src/game_app.cpp
                            src/game_window.cpp
                            src/player.cpp)

target_compile_definitions(PongPlusPlus PRIVATE $<$<CONFIG:Debug>:DEBUG>)

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
  opengl32.lib)

target_link_libraries(PongPlusPlus
  optimized ${PROJECT_SOURCE_DIR}/lib/win/GraRen/Release/GraRen.lib
  debug ${PROJECT_SOURCE_DIR}/lib/win/GraRen/Debug/GraRen.lib)

target_link_options(PongPlusPlus PRIVATE /NODEFAULTLIB:LIBCMT)

add_custom_command(TARGET PongPlusPlus POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GLEW/glew32.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/lib/win/GLFW/glfw3.dll"
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<IF:$<CONFIG:Debug>,"${PROJECT_SOURCE_DIR}/lib/win/GraRen/Debug/GraRen.dll","${PROJECT_SOURCE_DIR}/lib/win/GraRen/Release/GraRen.dll">
    $<TARGET_FILE_DIR:PongPlusPlus>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<IF:$<CONFIG:Debug>,"${PROJECT_SOURCE_DIR}/lib/win/GL3H/Debug/GL3H.dll","${PROJECT_SOURCE_DIR}/lib/win/GL3H/Release/GL3H.dll">
    $<TARGET_FILE_DIR:PongPlusPlus>)

set(INCLUDE_PDB $<$CONFIG:Debug>:YES>)

if (INCLUDE_PDB STREQUAL YES)
  add_custom_command(TARGET PongPlusPlus POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<$<CONFIG:Debug>:"${PROJECT_SOURCE_DIR}/lib/win/GraRen/Debug/GraRen.pdb">
      $<TARGET_FILE_DIR:PongPlusPlus>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<$<CONFIG:Debug>:"${PROJECT_SOURCE_DIR}/lib/win/GL3H/Debug/GL3H.pdb">
      $<TARGET_FILE_DIR:PongPlusPlus>)
  endif(UNIX)
endif()