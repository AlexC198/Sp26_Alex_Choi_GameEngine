add_executable(Sp26_Alex_Choi Game.cpp)

target_link_libraries(Sp26_Alex_Choi Chug)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})