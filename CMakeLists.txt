cmake_minimum_required(VERSION 3.23)
project(Asteroids_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Asteroids_Game main.cpp src/Texture.cpp include/Texture.h Enums/textureEnum.h src/Rocket.cpp include/Rocket.h src/Asteroids.cpp include/Asteroids.h src/Bullet.cpp include/Bullet.h src/SpaceshipGun.cpp
        include/SpaceshipGun.h src/Fonts.cpp include/Fonts.h Enums/fontsEnum.h src/Heart.cpp include/Heart.h src/states.cpp include/states.h Enums/statesEnum.h src/Health.cpp include/Health.h include/ScoreBoard.h src/ScoreBoard.cpp)

target_link_libraries(Asteroids_Game sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)