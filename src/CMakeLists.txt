FILE(GLOB sources *.cpp)
SET(libs tcod tcodxx tcodgui)

ADD_EXECUTABLE(FloodIt ${sources})
TARGET_LINK_LIBRARIES(FloodIt ${libs})
