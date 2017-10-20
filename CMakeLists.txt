cmake_minimum_required(VERSION 3.6.0)
project(StrongTypes)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-W -Wall -Werror)
endif(MSVC)

add_subdirectory(StrongTypedConstructors)
add_subdirectory(StrongTypedInterfaces)