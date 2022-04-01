cmake_minimum_required(VERSION 3.16)
project(Coast_Input_Simulation)

add_executable(coast_input_sim_test input_sim_test.cc)

if(WIN32)
    set(cis_sources win/input_sim_win.cc)
    message("win")
elseif(UNIX AND NOT APPLE)
    message("linux")
    set(cis_sources linux/input_sim_linux.cc)
endif()

add_library(coast_input_simulation STATIC ${cis_sources})

target_compile_definitions(coast_input_simulation PRIVATE EXPORT_SYMBOLS)

target_include_directories(coast_input_simulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(coast_input_sim_test PRIVATE coast_input_simulation)

install(TARGETS coast_input_sim_test DESTINATION bin)
install(TARGETS coast_input_simulation DESTINATION lib)
install(FILES input_sim_macros.h input_sim.h DESTINATION include)