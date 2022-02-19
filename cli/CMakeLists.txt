# Sanity-checking to make sure CMake was run against the correct directory
if (NOT DEFINED LIBFIVE_BUILD_FROM_ROOT)
    message(FATAL_ERROR "CMake must be called against top-level directory")
endif()

# Instruct CMake to run moc, uic, and rrc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SRCS cli.cpp)

if(WIN32)
    add_executable(Cli WIN32 ${SRCS})
else()
    add_executable(Cli ${SRCS})
endif()

if(UNIX AND NOT(APPLE))
    install(TARGETS Cli DESTINATION bin)
endif(UNIX AND NOT(APPLE))

target_include_directories(Cli PUBLIC include)
target_link_libraries(Cli libfive libfive-stdlib
    ${EXTRA_LIBS}
)

if (MSVC)
    # Copy the DLLs into the build directory, so that Cli.exe can find them
    add_custom_command(TARGET Cli POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:libfive>
            $<TARGET_FILE_DIR:Cli>)
    add_custom_command(TARGET Cli POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:libfive-stdlib>
            $<TARGET_FILE_DIR:Cli>)
endif(MSVC)
