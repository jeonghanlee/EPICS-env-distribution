/* This is a generated file, do not edit! */

#ifndef INC_dbRecStdAPI_H
#define INC_dbRecStdAPI_H

#if defined(_WIN32) || defined(__CYGWIN__)

#  if !defined(epicsStdCall)
#    define epicsStdCall __stdcall
#  endif

#  if defined(BUILDING_dbRecStd_API) && defined(EPICS_BUILD_DLL)
/* Building library as dll */
#    define DBRECSTD_API __declspec(dllexport)
#  elif !defined(BUILDING_dbRecStd_API) && defined(EPICS_CALL_DLL)
/* Calling library in dll form */
#    define DBRECSTD_API __declspec(dllimport)
#  endif

#elif __GNUC__ >= 4
#  define DBRECSTD_API __attribute__ ((visibility("default")))
#endif

#if !defined(DBRECSTD_API)
#  define DBRECSTD_API
#endif

#if !defined(epicsStdCall)
#  define epicsStdCall
#endif

#endif /* INC_dbRecStdAPI_H */

