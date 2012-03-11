# This is FindGTSAM.cmake
# CMake module to locate the GTSAM package
# The following variables will be defined:
#
# GTSAM_FOUND          : TRUE if the package has been successfully found
# GTSAM_INCLUDE_DIR    : paths to GTSAM's INCLUDE directories
# GTSAM_LIBS           : paths to GTSAM's libraries

# Find include dirs
find_path(_gtsam2_INCLUDE_DIR gtsam2/discrete/DiscreteFactorGraph.h
  PATHS ${CMAKE_INSTALL_PREFIX}/include "$ENV{HOME}/include" /usr/local/include /usr/include )

# Find libraries
find_library(_gtsam2_LIB NAMES gtsam2
  HINTS ${CMAKE_INSTALL_PREFIX}/lib "$ENV{HOME}/lib" /usr/local/lib /usr/lib)

set (GTSAM2_INCLUDE_DIR ${_gtsam2_INCLUDE_DIR} CACHE STRING "GTSAM2 INCLUDE directories")
set (GTSAM2_LIBS        ${_gtsam2_LIB} CACHE STRING "GTSAM2 libraries")

# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GTSAM2 DEFAULT_MSG
                                  _gtsam2_INCLUDE_DIR _gtsam2_LIB)

mark_as_advanced(_gtsam2_INCLUDE_DIR _gtsam2_LIB )
 



