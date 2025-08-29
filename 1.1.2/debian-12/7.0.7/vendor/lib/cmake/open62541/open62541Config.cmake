
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was open62541Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

include("${CMAKE_CURRENT_LIST_DIR}/open62541Targets.cmake")

set (open62541_TOOLS_DIR ${PACKAGE_PREFIX_DIR}/share/open62541/tools CACHE PATH "Path to the directory that contains the tooling of the stack")
set (open62541_NODESET_DIR ${PACKAGE_PREFIX_DIR}/share/open62541/tools/ua-nodeset CACHE PATH "Path to the directory that contains the OPC UA schema repository")

include(CMakeFindDependencyMacro)
find_dependency(PythonInterp REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/open62541Macros.cmake")

set(open62541_COMPONENTS_ALL Methods;Subscriptions;Encryption;EncryptionOpenSSL;Events)

# find_dependency has no option to provide hints for modules, so temporary add the path to CMAKE_MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
list (FIND open62541_COMPONENTS_ALL "EncryptionMbedTLS" _index)
if((${_index} GREATER 0) OR (${_index} EQUAL 0))
    find_dependency(MbedTLS REQUIRED)
endif()

list(REMOVE_AT CMAKE_MODULE_PATH -1)

foreach(_comp ${open62541_FIND_COMPONENTS})
  list (FIND open62541_COMPONENTS_ALL "${_comp}" _index)
  if (${_index} LESS 0)
    set(open62541_FOUND False)
    set(open62541_NOTFOUND_MESSAGE "Unsupported open62541 component: ${_comp}")
    message(WARNING "${open62541_NOTFOUND_MESSAGE}")
  endif()
endforeach()
