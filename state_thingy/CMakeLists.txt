CMAKE_MINIMUM_REQUIRED (VERSION 3.11)

PROJECT ("state_thing")

set(LIBRARY_HEADERS
    "include/digital_input_state.h"
    )

set(LIBRARY_FILES
    "src/digital_input_state.c"
    )

add_library(libDigitalInputState SHARED ${LIBRARY_FILES} ${LIBRARY_HEADERS})

target_include_directories(libDigitalInputState PUBLIC include ${CURL_INCLUDE_DIRS})
link_directories( ${CURL_LIBRARIES} )

target_link_libraries(libDigitalInputState libcurl)

INSTALL(TARGETS libDigitalInputState DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_subdirectory(test)
