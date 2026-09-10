/* This is a generated file, do not edit! */

#ifndef INC_libCaAPI_H
#define INC_libCaAPI_H

#if defined(_WIN32) || defined(__CYGWIN__)

#  if !defined(epicsStdCall)
#    define epicsStdCall __stdcall
#  endif

#  if defined(BUILDING_libCa_API) && defined(EPICS_BUILD_DLL)
/* Building library as dll */
#    define LIBCA_API __declspec(dllexport)
#  elif !defined(BUILDING_libCa_API) && defined(EPICS_CALL_DLL)
/* Calling library in dll form */
#    define LIBCA_API __declspec(dllimport)
#  endif

#elif __GNUC__ >= 4
#  define LIBCA_API __attribute__ ((visibility("default")))
#endif

#if !defined(LIBCA_API)
#  define LIBCA_API
#endif

#if !defined(epicsStdCall)
#  define epicsStdCall
#endif

#endif /* INC_libCaAPI_H */

