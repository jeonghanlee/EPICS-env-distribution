#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "open62541::open62541" for configuration "RelWithDebInfo"
set_property(TARGET open62541::open62541 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(open62541::open62541 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libopen62541.so.1.3.15"
  IMPORTED_SONAME_RELWITHDEBINFO "libopen62541.so.1"
  )

list(APPEND _cmake_import_check_targets open62541::open62541 )
list(APPEND _cmake_import_check_files_for_open62541::open62541 "${_IMPORT_PREFIX}/lib/libopen62541.so.1.3.15" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
