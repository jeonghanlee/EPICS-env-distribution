#ifndef INCLseq_maskh
#define INCLseq_maskh

#include "epicsTypes.h"

typedef epicsUInt32 seqMask;				/* for event masks and options */

#define NBITS			(8*sizeof(seqMask))	/* # bits in seqMask word */
#define NWORDS(maxBitNum)	(1+(maxBitNum)/NBITS)	/* # words in seqMask */

#define bitSet(words, bitnum)	( (words)[(bitnum)/NBITS] |=  (1u<<((bitnum)%NBITS)))
#define bitClear(words, bitnum)	( (words)[(bitnum)/NBITS] &= ~(1u<<((bitnum)%NBITS)))
#define bitTest(words, bitnum)	(((words)[(bitnum)/NBITS] &  (1u<<((bitnum)%NBITS))) != 0)

#endif	/*INCLseq_maskh*/
