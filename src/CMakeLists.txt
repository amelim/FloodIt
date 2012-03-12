FILE(GLOB sources *.cpp)
SET(libs tcod tcodxx tcodgui gtsam gtsam2)

ADD_EXECUTABLE(FloodIt ${sources})
TARGET_LINK_LIBRARIES(FloodIt ${libs})
