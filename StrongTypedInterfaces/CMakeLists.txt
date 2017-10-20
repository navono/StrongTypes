set(MODULE_NAME STInterfaces)
file(GLOB SOURCES "./*.cpp")

add_executable(${MODULE_NAME} ${SOURCES})
set_target_properties(${MODULE_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)