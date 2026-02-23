/* This is a generated file, do not edit! */

#ifndef INC_dbCoreAPI_H
#define INC_dbCoreAPI_H

#if defined(_WIN32) || defined(__CYGWIN__)

#  if !defined(epicsStdCall)
#    define epicsStdCall __stdcall
#  endif

#  if defined(BUILDING_dbCore_API) && defined(EPICS_BUILD_DLL)
/* Building library as dll */
#    define DBCORE_API __declspec(dllexport)
#  elif !defined(BUILDING_dbCore_API) && defined(EPICS_CALL_DLL)
/* Calling library in dll form */
#    define DBCORE_API __declspec(dllimport)
#  endif

#elif __GNUC__ >= 4
#  define DBCORE_API __attribute__ ((visibility("default")))
#endif

#if !defined(DBCORE_API)
#  define DBCORE_API
#endif

#if !defined(epicsStdCall)
#  define epicsStdCall
#endif

#endif /* INC_dbCoreAPI_H */

