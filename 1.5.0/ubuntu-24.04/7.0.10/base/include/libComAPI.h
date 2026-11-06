/* This is a generated file, do not edit! */

#ifndef INC_libComAPI_H
#define INC_libComAPI_H

#if defined(_WIN32) || defined(__CYGWIN__)

#  if !defined(epicsStdCall)
#    define epicsStdCall __stdcall
#  endif

#  if defined(BUILDING_libCom_API) && defined(EPICS_BUILD_DLL)
/* Building library as dll */
#    define LIBCOM_API __declspec(dllexport)
#  elif !defined(BUILDING_libCom_API) && defined(EPICS_CALL_DLL)
/* Calling library in dll form */
#    define LIBCOM_API __declspec(dllimport)
#  endif

#elif __GNUC__ >= 4
#  define LIBCOM_API __attribute__ ((visibility("default")))
#endif

#if !defined(LIBCOM_API)
#  define LIBCOM_API
#endif

#if !defined(epicsStdCall)
#  define epicsStdCall
#endif

#endif /* INC_libComAPI_H */

