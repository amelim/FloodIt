# This is FindGTSAM.cmake
# CMake module to locate the GTSAM package
# The following variables will be defined:
#
# GTSAM_FOUND          : TRUE if the package has been successfully found
# GTSAM_INCLUDE_DIR    : paths to GTSAM's INCLUDE directories
# GTSAM_LIBS           : paths to GTSAM's libraries

# Find include dirs
find_path(_gtsam_INCLUDE_DIR gtsam/inference/FactorGraph.h
  PATHS ${CMAKE_INSTALL_PREFIX}/include "$ENV{HOME}/include" /usr/local/include /usr/include )

# Find libraries
find_library(_gtsam_LIB NAMES gtsam
  HINTS ${CMAKE_INSTALL_PREFIX}/lib "$ENV{HOME}/lib" /usr/local/lib /usr/lib)

set (GTSAM_INCLUDE_DIR ${_gtsam_INCLUDE_DIR} CACHE STRING "GTSAM INCLUDE directories")
set (GTSAM_LIBS        ${_gtsam_LIB} CACHE STRING "GTSAM libraries")

# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GTSAM DEFAULT_MSG
                                  _gtsam_INCLUDE_DIR _gtsam_LIB)

mark_as_advanced(_gtsam_INCLUDE_DIR _gtsam_LIB )
 



