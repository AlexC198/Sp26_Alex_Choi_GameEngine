add_executable(Sp26_Alex_Choi 
Game.cpp
Player.cpp 
Bullet.cpp 
Enemy.cpp 
Counter.cpp 
)

target_link_libraries(Sp26_Alex_Choi Chug)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/Chug)
file(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
