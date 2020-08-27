set(CC_FILES   "digital_input_state_test.c")

add_executable(digital_input_state_test ${CC_FILES})

target_link_libraries(  digital_input_state_test
    libDigitalInputState)

install(TARGETS digital_input_state_test
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
