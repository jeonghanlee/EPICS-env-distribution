#ifndef INCLseqStatsh
#define INCLseqStatsh

#include "shareLib.h"

#ifdef __cplusplus
extern "C" {
#endif

epicsShareFunc void seqGatherStats(
    unsigned *num_programs,
    unsigned *num_channels,
    unsigned *num_connected
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif	/*INCLseqStatsh*/
