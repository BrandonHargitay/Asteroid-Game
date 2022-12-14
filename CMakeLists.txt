cmake_minimum_required(VERSION 3.23)
project(Asteroids_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Asteroids_Game main.cpp Texture.cpp Texture.h Enums/textureEnum.h Rocket.cpp Rocket.h Asteroids.cpp Asteroids.h Bullet.cpp Bullet.h SpaceshipGun.cpp
        SpaceshipGun.h Fonts.cpp Fonts.h Enums/fontsEnum.h Heart.cpp Heart.h states.cpp states.h Enums/statesEnum.h Health.cpp Health.h ScoreBoard.h ScoreBoard.cpp)

target_link_libraries(Asteroids_Game sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)