/** @file asynRecord.h
 * @brief Declarations for the @ref asynRecord "asyn" record type.
 *
 * This header was generated from asynRecord.dbd
 */

#ifndef INC_asynRecord_H
#define INC_asynRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef serialFCTL_NUM_CHOICES
/** @brief Enumerated type from menu serialFCTL */
typedef enum {
    serialFCTL_unknown              /**< @brief State string "Unknown" */,
    serialFCTL_None                 /**< @brief State string "None" */,
    serialFCTL_Hardware             /**< @brief State string "Hardware" */
} serialFCTL;
/** @brief Number of states defined for menu serialFCTL */
#define serialFCTL_NUM_CHOICES 3
#endif

#ifndef asynEOMREASON_NUM_CHOICES
/** @brief Enumerated type from menu asynEOMREASON */
typedef enum {
    asynEOMREASONNone               /**< @brief State string "None" */,
    asynEOMREASONCNT                /**< @brief State string "Count" */,
    asynEOMREASONEOS                /**< @brief State string "Eos" */,
    asynEOMREASONCNTEOS             /**< @brief State string "Count Eos" */,
    asynEOMREASONEND                /**< @brief State string "End" */,
    asynEOMREASONCNTEND             /**< @brief State string "Count End" */,
    asynEOMREASONEOSEND             /**< @brief State string "Eos End" */,
    asynEOMREASONCNTEOSEND          /**< @brief State string "Count Eos End" */
} asynEOMREASON;
/** @brief Number of states defined for menu asynEOMREASON */
#define asynEOMREASON_NUM_CHOICES 8
#endif

#ifndef asynENABLE_NUM_CHOICES
/** @brief Enumerated type from menu asynENABLE */
typedef enum {
    asynENABLE_Disable              /**< @brief State string "Disable" */,
    asynENABLE_Enable               /**< @brief State string "Enable" */
} asynENABLE;
/** @brief Number of states defined for menu asynENABLE */
#define asynENABLE_NUM_CHOICES 2
#endif

#ifndef asynTMOD_NUM_CHOICES
/** @brief Enumerated type from menu asynTMOD */
typedef enum {
    asynTMOD_Write_Read             /**< @brief State string "Write/Read" */,
    asynTMOD_Write                  /**< @brief State string "Write" */,
    asynTMOD_Read                   /**< @brief State string "Read" */,
    asynTMOD_Flush                  /**< @brief State string "Flush" */,
    asynTMOD_NoIO                   /**< @brief State string "NoI/O" */
} asynTMOD;
/** @brief Number of states defined for menu asynTMOD */
#define asynTMOD_NUM_CHOICES 5
#endif

#ifndef asynFMT_NUM_CHOICES
/** @brief Enumerated type from menu asynFMT */
typedef enum {
    asynFMT_ASCII                   /**< @brief State string "ASCII" */,
    asynFMT_Hybrid                  /**< @brief State string "Hybrid" */,
    asynFMT_Binary                  /**< @brief State string "Binary" */
} asynFMT;
/** @brief Number of states defined for menu asynFMT */
#define asynFMT_NUM_CHOICES 3
#endif

#ifndef serialPRTY_NUM_CHOICES
/** @brief Enumerated type from menu serialPRTY */
typedef enum {
    serialPRTY_unknown              /**< @brief State string "Unknown" */,
    serialPRTY_None                 /**< @brief State string "None" */,
    serialPRTY_Even                 /**< @brief State string "Even" */,
    serialPRTY_Odd                  /**< @brief State string "Odd" */
} serialPRTY;
/** @brief Number of states defined for menu serialPRTY */
#define serialPRTY_NUM_CHOICES 4
#endif

#ifndef serialMCTL_NUM_CHOICES
/** @brief Enumerated type from menu serialMCTL */
typedef enum {
    serialMCTL_unknown              /**< @brief State string "Unknown" */,
    serialMCTL_CLOCAL               /**< @brief State string "CLOCAL" */,
    serialMCTL_Yes                  /**< @brief State string "YES" */
} serialMCTL;
/** @brief Number of states defined for menu serialMCTL */
#define serialMCTL_NUM_CHOICES 3
#endif

#ifndef serialSBIT_NUM_CHOICES
/** @brief Enumerated type from menu serialSBIT */
typedef enum {
    serialSBIT_unknown              /**< @brief State string "Unknown" */,
    serialSBIT_1                    /**< @brief State string "1" */,
    serialSBIT_2                    /**< @brief State string "2" */
} serialSBIT;
/** @brief Number of states defined for menu serialSBIT */
#define serialSBIT_NUM_CHOICES 3
#endif

#ifndef serialDBIT_NUM_CHOICES
/** @brief Enumerated type from menu serialDBIT */
typedef enum {
    serialDBIT_unknown              /**< @brief State string "Unknown" */,
    serialDBIT_5                    /**< @brief State string "5" */,
    serialDBIT_6                    /**< @brief State string "6" */,
    serialDBIT_7                    /**< @brief State string "7" */,
    serialDBIT_8                    /**< @brief State string "8" */
} serialDBIT;
/** @brief Number of states defined for menu serialDBIT */
#define serialDBIT_NUM_CHOICES 5
#endif

#ifndef serialBAUD_NUM_CHOICES
/** @brief Enumerated type from menu serialBAUD */
typedef enum {
    serialBAUD_unknown              /**< @brief State string "Unknown" */,
    serialBAUD_300                  /**< @brief State string "300" */,
    serialBAUD_600                  /**< @brief State string "600" */,
    serialBAUD_1200                 /**< @brief State string "1200" */,
    serialBAUD_2400                 /**< @brief State string "2400" */,
    serialBAUD_4800                 /**< @brief State string "4800" */,
    serialBAUD_9600                 /**< @brief State string "9600" */,
    serialBAUD_19200                /**< @brief State string "19200" */,
    serialBAUD_38400                /**< @brief State string "38400" */,
    serialBAUD_57600                /**< @brief State string "57600" */,
    serialBAUD_115200               /**< @brief State string "115200" */,
    serialBAUD_230400               /**< @brief State string "230400" */,
    serialBAUD_460800               /**< @brief State string "460800" */,
    serialBAUD_576000               /**< @brief State string "576000" */,
    serialBAUD_921600               /**< @brief State string "921600" */,
    serialBAUD_1152000              /**< @brief State string "1152000" */
} serialBAUD;
/** @brief Number of states defined for menu serialBAUD */
#define serialBAUD_NUM_CHOICES 16
#endif

#ifndef asynCONNECT_NUM_CHOICES
/** @brief Enumerated type from menu asynCONNECT */
typedef enum {
    asynCONNECT_Disconnect          /**< @brief State string "Disconnect" */,
    asynCONNECT_Connect             /**< @brief State string "Connect" */
} asynCONNECT;
/** @brief Number of states defined for menu asynCONNECT */
#define asynCONNECT_NUM_CHOICES 2
#endif

#ifndef gpibUCMD_NUM_CHOICES
/** @brief Enumerated type from menu gpibUCMD */
typedef enum {
    gpibUCMD_None                   /**< @brief State string "None" */,
    gpibUCMD_Device_Clear__DCL_     /**< @brief State string "Device Clear (DCL)" */,
    gpibUCMD_Local_Lockout__LL0_    /**< @brief State string "Local Lockout (LL0)" */,
    gpibUCMD_Serial_Poll_Disable__SPD_ /**< @brief State string "Serial Poll Disable (SPD)" */,
    gpibUCMD_Serial_Poll_Enable__SPE_ /**< @brief State string "Serial Poll Enable (SPE)" */,
    gpibUCMD_Unlisten__UNL_         /**< @brief State string "Unlisten (UNL)" */,
    gpibUCMD_Untalk__UNT_           /**< @brief State string "Untalk (UNT)" */
} gpibUCMD;
/** @brief Number of states defined for menu gpibUCMD */
#define gpibUCMD_NUM_CHOICES 7
#endif

#ifndef asynINTERFACE_NUM_CHOICES
/** @brief Enumerated type from menu asynINTERFACE */
typedef enum {
    asynINTERFACE_OCTET             /**< @brief State string "asynOctet" */,
    asynINTERFACE_INT32             /**< @brief State string "asynInt32" */,
    asynINTERFACE_UINT32            /**< @brief State string "asynUInt32Digital" */,
    asynINTERFACE_FLOAT64           /**< @brief State string "asynFloat64" */
} asynINTERFACE;
/** @brief Number of states defined for menu asynINTERFACE */
#define asynINTERFACE_NUM_CHOICES 4
#endif

#ifndef serialIX_NUM_CHOICES
/** @brief Enumerated type from menu serialIX */
typedef enum {
    serialIX_unknown                /**< @brief State string "Unknown" */,
    serialIX_No                     /**< @brief State string "No" */,
    serialIX_Yes                    /**< @brief State string "Yes" */
} serialIX;
/** @brief Number of states defined for menu serialIX */
#define serialIX_NUM_CHOICES 3
#endif

#ifndef asynTRACE_NUM_CHOICES
/** @brief Enumerated type from menu asynTRACE */
typedef enum {
    asynTRACE_Off                   /**< @brief State string "Off" */,
    asynTRACE_On                    /**< @brief State string "On" */
} asynTRACE;
/** @brief Number of states defined for menu asynTRACE */
#define asynTRACE_NUM_CHOICES 2
#endif

#ifndef ipDRTO_NUM_CHOICES
/** @brief Enumerated type from menu ipDRTO */
typedef enum {
    ipDRTO_unknown                  /**< @brief State string "Unknown" */,
    ipDRTO_No                       /**< @brief State string "No" */,
    ipDRTO_Yes                      /**< @brief State string "Yes" */
} ipDRTO;
/** @brief Number of states defined for menu ipDRTO */
#define ipDRTO_NUM_CHOICES 3
#endif

#ifndef gpibACMD_NUM_CHOICES
/** @brief Enumerated type from menu gpibACMD */
typedef enum {
    gpibACMD_None                   /**< @brief State string "None" */,
    gpibACMD_Group_Execute_Trig___GET_ /**< @brief State string "Group Execute Trig. (GET)" */,
    gpibACMD_Go_To_Local__GTL_      /**< @brief State string "Go To Local (GTL)" */,
    gpibACMD_Selected_Dev__Clear__SDC_ /**< @brief State string "Selected Dev. Clear (SDC)" */,
    gpibACMD_Take_Control__TCT_     /**< @brief State string "Take Control (TCT)" */,
    gpibACMD_Serial_Poll            /**< @brief State string "Serial Poll" */
} gpibACMD;
/** @brief Number of states defined for menu gpibACMD */
#define gpibACMD_NUM_CHOICES 6
#endif

#ifndef asynAUTOCONNECT_NUM_CHOICES
/** @brief Enumerated type from menu asynAUTOCONNECT */
typedef enum {
    asynAUTOCONNECT_noAutoConnect   /**< @brief State string "noAutoConnect" */,
    asynAUTOCONNECT_autoConnect     /**< @brief State string "autoConnect" */
} asynAUTOCONNECT;
/** @brief Number of states defined for menu asynAUTOCONNECT */
#define asynAUTOCONNECT_NUM_CHOICES 2
#endif

/** @brief Declaration of asyn record type. */
typedef struct asynRecord {
    char                name[61];   /**< @brief Record Name */
    char                desc[41];   /**< @brief Descriptor */
    char                asg[29];    /**< @brief Access Security Group */
    epicsEnum16         scan;       /**< @brief Scan Mechanism */
    epicsEnum16         pini;       /**< @brief Process at iocInit */
    epicsInt16          phas;       /**< @brief Scan Phase */
    char                evnt[40];   /**< @brief Event Name */
    epicsInt16          tse;        /**< @brief Time Stamp Event */
    DBLINK              tsel;       /**< @brief Time Stamp Link */
    epicsEnum16         dtyp;       /**< @brief Device Type */
    epicsInt16          disv;       /**< @brief Disable Value */
    epicsInt16          disa;       /**< @brief Disable */
    DBLINK              sdis;       /**< @brief Scanning Disable */
    epicsMutexId        mlok;       /**< @brief Monitor lock */
    ELLLIST             mlis;       /**< @brief Monitor List */
    ELLLIST             bklnk;      /**< @brief Backwards link tracking */
    epicsUInt8          disp;       /**< @brief Disable putField */
    epicsUInt8          proc;       /**< @brief Force Processing */
    epicsEnum16         stat;       /**< @brief Alarm Status */
    epicsEnum16         sevr;       /**< @brief Alarm Severity */
    char                amsg[40];   /**< @brief Alarm Message */
    epicsEnum16         nsta;       /**< @brief New Alarm Status */
    epicsEnum16         nsev;       /**< @brief New Alarm Severity */
    char                namsg[40];  /**< @brief New Alarm Message */
    epicsEnum16         acks;       /**< @brief Alarm Ack Severity */
    epicsEnum16         ackt;       /**< @brief Alarm Ack Transient */
    epicsEnum16         diss;       /**< @brief Disable Alarm Sevrty */
    epicsUInt8          lcnt;       /**< @brief Lock Count */
    epicsUInt8          pact;       /**< @brief Record active */
    epicsUInt8          putf;       /**< @brief dbPutField process */
    epicsUInt8          rpro;       /**< @brief Reprocess  */
    struct asgMember    *asp;       /**< @brief Access Security Pvt */
    struct processNotify *ppn;      /**< @brief pprocessNotify */
    struct processNotifyRecord *ppnr; /**< @brief pprocessNotifyRecord */
    struct scan_element *spvt;      /**< @brief Scan Private */
    struct typed_rset   *rset;      /**< @brief Address of RSET */
    unambiguous_dset    *dset;      /**< @brief DSET address */
    void                *dpvt;      /**< @brief Device Private */
    struct dbRecordType *rdes;      /**< @brief Address of dbRecordType */
    struct lockRecord   *lset;      /**< @brief Lock Set */
    epicsEnum16         prio;       /**< @brief Scheduling Priority */
    epicsUInt8          tpro;       /**< @brief Trace Processing */
    epicsUInt8          bkpt;       /**< @brief Break Point */
    epicsUInt8          udf;        /**< @brief Undefined */
    epicsEnum16         udfs;       /**< @brief Undefined Alarm Sevrty */
    epicsTimeStamp      time;       /**< @brief Time */
    epicsUInt64         utag;       /**< @brief Time Tag */
    DBLINK              flnk;       /**< @brief Forward Process Link */
    epicsInt32          val;        /**< @brief Value field (unused) */
    char                port[40];   /**< @brief asyn port */
    epicsInt32          addr;       /**< @brief asyn address */
    epicsEnum16         pcnct;      /**< @brief Port Connect/Disconnect */
    char                drvinfo[40];/**< @brief Driver info string */
    epicsInt32          reason;     /**< @brief asynUser->reason */
    epicsEnum16         tmod;       /**< @brief Transaction mode */
    epicsFloat64        tmot;       /**< @brief Timeout (sec) */
    epicsEnum16         iface;      /**< @brief Interface */
    epicsInt32          octetiv;    /**< @brief asynOctet is valid */
    epicsInt32          optioniv;   /**< @brief asynOption is valid */
    epicsInt32          gpibiv;     /**< @brief asynGPIB is valid */
    epicsInt32          i32iv;      /**< @brief asynInt32 is valid */
    epicsInt32          ui32iv;     /**< @brief asynUInt32Digital is valid */
    epicsInt32          f64iv;      /**< @brief asynFloat64 is valid */
    char                aout[40];   /**< @brief Output (command) string */
    char                oeos[40];   /**< @brief Output delimiter */
    epicsInt8           bout;       /**< @brief Output binary data */
    void *optr;                     /**< @brief Output buffer pointer */
    epicsInt32          omax;       /**< @brief Max. size of output array */
    epicsInt32          nowt;       /**< @brief Number of bytes to write */
    epicsInt32          nawt;       /**< @brief Number of bytes actually written */
    epicsEnum16         ofmt;       /**< @brief Output format */
    char                ainp[40];   /**< @brief Input (response) string */
    char                tinp[40];   /**< @brief Translated input string */
    char                ieos[40];   /**< @brief Input Delimiter */
    epicsInt8           binp;       /**< @brief Input binary data */
    void *iptr;                     /**< @brief Input buffer pointer */
    epicsInt32          imax;       /**< @brief Max. size of input array */
    epicsInt32          nrrd;       /**< @brief Number of bytes to read */
    epicsInt32          nord;       /**< @brief Number of bytes read */
    epicsEnum16         ifmt;       /**< @brief Input format */
    epicsEnum16         eomr;       /**< @brief EOM reason */
    epicsInt32          i32inp;     /**< @brief asynInt32 input */
    epicsInt32          i32out;     /**< @brief asynInt32 output */
    epicsUInt32         ui32inp;    /**< @brief asynUInt32Digital input */
    epicsUInt32         ui32out;    /**< @brief asynUInt32Digital output */
    epicsUInt32         ui32mask;   /**< @brief asynUInt32Digital mask */
    epicsFloat64        f64inp;     /**< @brief asynFloat64 input */
    epicsFloat64        f64out;     /**< @brief asynFloat64 output */
    epicsEnum16         baud;       /**< @brief Baud rate */
    epicsInt32          lbaud;      /**< @brief Baud rate */
    epicsEnum16         prty;       /**< @brief Parity */
    epicsEnum16         dbit;       /**< @brief Data bits */
    epicsEnum16         sbit;       /**< @brief Stop bits */
    epicsEnum16         mctl;       /**< @brief Modem control */
    epicsEnum16         fctl;       /**< @brief Flow control */
    epicsEnum16         ixon;       /**< @brief Output XON/XOFF */
    epicsEnum16         ixoff;      /**< @brief Input XON/XOFF */
    epicsEnum16         ixany;      /**< @brief XON=any character */
    char                hostinfo[40];/**< @brief host info */
    epicsEnum16         drto;       /**< @brief Disconnect on timeout */
    epicsEnum16         ucmd;       /**< @brief Universal command */
    epicsEnum16         acmd;       /**< @brief Addressed command */
    epicsUInt8          spr;        /**< @brief Serial poll response */
    epicsInt32          tmsk;       /**< @brief Trace mask */
    epicsEnum16         tb0;        /**< @brief Trace error */
    epicsEnum16         tb1;        /**< @brief Trace IO device */
    epicsEnum16         tb2;        /**< @brief Trace IO filter */
    epicsEnum16         tb3;        /**< @brief Trace IO driver */
    epicsEnum16         tb4;        /**< @brief Trace flow */
    epicsEnum16         tb5;        /**< @brief Trace warning */
    epicsInt32          tiom;       /**< @brief Trace I/O mask */
    epicsEnum16         tib0;       /**< @brief Trace IO ASCII */
    epicsEnum16         tib1;       /**< @brief Trace IO escape */
    epicsEnum16         tib2;       /**< @brief Trace IO hex */
    epicsInt32          tinm;       /**< @brief Trace Info mask */
    epicsEnum16         tinb0;      /**< @brief Trace Info Time */
    epicsEnum16         tinb1;      /**< @brief Trace Info Port */
    epicsEnum16         tinb2;      /**< @brief Trace Info Source */
    epicsEnum16         tinb3;      /**< @brief Trace Info Thread */
    epicsInt32          tsiz;       /**< @brief Trace IO truncate size */
    char                tfil[40];   /**< @brief Trace IO file */
    epicsEnum16         auct;       /**< @brief Autoconnect */
    epicsEnum16         cnct;       /**< @brief Connect/Disconnect */
    epicsEnum16         enbl;       /**< @brief Enable/Disable */
    char *errs;                     /**< @brief Error string */
    epicsUInt8          aqr;        /**< @brief Abort queueRequest */
} asynRecord;

typedef enum {
	asynRecordNAME = 0,
	asynRecordDESC = 1,
	asynRecordASG = 2,
	asynRecordSCAN = 3,
	asynRecordPINI = 4,
	asynRecordPHAS = 5,
	asynRecordEVNT = 6,
	asynRecordTSE = 7,
	asynRecordTSEL = 8,
	asynRecordDTYP = 9,
	asynRecordDISV = 10,
	asynRecordDISA = 11,
	asynRecordSDIS = 12,
	asynRecordMLOK = 13,
	asynRecordMLIS = 14,
	asynRecordBKLNK = 15,
	asynRecordDISP = 16,
	asynRecordPROC = 17,
	asynRecordSTAT = 18,
	asynRecordSEVR = 19,
	asynRecordAMSG = 20,
	asynRecordNSTA = 21,
	asynRecordNSEV = 22,
	asynRecordNAMSG = 23,
	asynRecordACKS = 24,
	asynRecordACKT = 25,
	asynRecordDISS = 26,
	asynRecordLCNT = 27,
	asynRecordPACT = 28,
	asynRecordPUTF = 29,
	asynRecordRPRO = 30,
	asynRecordASP = 31,
	asynRecordPPN = 32,
	asynRecordPPNR = 33,
	asynRecordSPVT = 34,
	asynRecordRSET = 35,
	asynRecordDSET = 36,
	asynRecordDPVT = 37,
	asynRecordRDES = 38,
	asynRecordLSET = 39,
	asynRecordPRIO = 40,
	asynRecordTPRO = 41,
	asynRecordBKPT = 42,
	asynRecordUDF = 43,
	asynRecordUDFS = 44,
	asynRecordTIME = 45,
	asynRecordUTAG = 46,
	asynRecordFLNK = 47,
	asynRecordVAL = 48,
	asynRecordPORT = 49,
	asynRecordADDR = 50,
	asynRecordPCNCT = 51,
	asynRecordDRVINFO = 52,
	asynRecordREASON = 53,
	asynRecordTMOD = 54,
	asynRecordTMOT = 55,
	asynRecordIFACE = 56,
	asynRecordOCTETIV = 57,
	asynRecordOPTIONIV = 58,
	asynRecordGPIBIV = 59,
	asynRecordI32IV = 60,
	asynRecordUI32IV = 61,
	asynRecordF64IV = 62,
	asynRecordAOUT = 63,
	asynRecordOEOS = 64,
	asynRecordBOUT = 65,
	asynRecordOPTR = 66,
	asynRecordOMAX = 67,
	asynRecordNOWT = 68,
	asynRecordNAWT = 69,
	asynRecordOFMT = 70,
	asynRecordAINP = 71,
	asynRecordTINP = 72,
	asynRecordIEOS = 73,
	asynRecordBINP = 74,
	asynRecordIPTR = 75,
	asynRecordIMAX = 76,
	asynRecordNRRD = 77,
	asynRecordNORD = 78,
	asynRecordIFMT = 79,
	asynRecordEOMR = 80,
	asynRecordI32INP = 81,
	asynRecordI32OUT = 82,
	asynRecordUI32INP = 83,
	asynRecordUI32OUT = 84,
	asynRecordUI32MASK = 85,
	asynRecordF64INP = 86,
	asynRecordF64OUT = 87,
	asynRecordBAUD = 88,
	asynRecordLBAUD = 89,
	asynRecordPRTY = 90,
	asynRecordDBIT = 91,
	asynRecordSBIT = 92,
	asynRecordMCTL = 93,
	asynRecordFCTL = 94,
	asynRecordIXON = 95,
	asynRecordIXOFF = 96,
	asynRecordIXANY = 97,
	asynRecordHOSTINFO = 98,
	asynRecordDRTO = 99,
	asynRecordUCMD = 100,
	asynRecordACMD = 101,
	asynRecordSPR = 102,
	asynRecordTMSK = 103,
	asynRecordTB0 = 104,
	asynRecordTB1 = 105,
	asynRecordTB2 = 106,
	asynRecordTB3 = 107,
	asynRecordTB4 = 108,
	asynRecordTB5 = 109,
	asynRecordTIOM = 110,
	asynRecordTIB0 = 111,
	asynRecordTIB1 = 112,
	asynRecordTIB2 = 113,
	asynRecordTINM = 114,
	asynRecordTINB0 = 115,
	asynRecordTINB1 = 116,
	asynRecordTINB2 = 117,
	asynRecordTINB3 = 118,
	asynRecordTSIZ = 119,
	asynRecordTFIL = 120,
	asynRecordAUCT = 121,
	asynRecordCNCT = 122,
	asynRecordENBL = 123,
	asynRecordERRS = 124,
	asynRecordAQR = 125
} asynFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int asynRecordSizeOffset(dbRecordType *prt)
{
    asynRecord *prec = 0;

    if (prt->no_fields != 126) {
        cantProceed("IOC build or installation error:\n"
            "    The asynRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 126.\n",
            prt->no_fields);
    }
    prt->papFldDes[asynRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[asynRecordNAME]->offset = (unsigned short)offsetof(asynRecord, name);
    prt->papFldDes[asynRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[asynRecordDESC]->offset = (unsigned short)offsetof(asynRecord, desc);
    prt->papFldDes[asynRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[asynRecordASG]->offset = (unsigned short)offsetof(asynRecord, asg);
    prt->papFldDes[asynRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[asynRecordSCAN]->offset = (unsigned short)offsetof(asynRecord, scan);
    prt->papFldDes[asynRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[asynRecordPINI]->offset = (unsigned short)offsetof(asynRecord, pini);
    prt->papFldDes[asynRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[asynRecordPHAS]->offset = (unsigned short)offsetof(asynRecord, phas);
    prt->papFldDes[asynRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[asynRecordEVNT]->offset = (unsigned short)offsetof(asynRecord, evnt);
    prt->papFldDes[asynRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[asynRecordTSE]->offset = (unsigned short)offsetof(asynRecord, tse);
    prt->papFldDes[asynRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[asynRecordTSEL]->offset = (unsigned short)offsetof(asynRecord, tsel);
    prt->papFldDes[asynRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[asynRecordDTYP]->offset = (unsigned short)offsetof(asynRecord, dtyp);
    prt->papFldDes[asynRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[asynRecordDISV]->offset = (unsigned short)offsetof(asynRecord, disv);
    prt->papFldDes[asynRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[asynRecordDISA]->offset = (unsigned short)offsetof(asynRecord, disa);
    prt->papFldDes[asynRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[asynRecordSDIS]->offset = (unsigned short)offsetof(asynRecord, sdis);
    prt->papFldDes[asynRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[asynRecordMLOK]->offset = (unsigned short)offsetof(asynRecord, mlok);
    prt->papFldDes[asynRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[asynRecordMLIS]->offset = (unsigned short)offsetof(asynRecord, mlis);
    prt->papFldDes[asynRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[asynRecordBKLNK]->offset = (unsigned short)offsetof(asynRecord, bklnk);
    prt->papFldDes[asynRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[asynRecordDISP]->offset = (unsigned short)offsetof(asynRecord, disp);
    prt->papFldDes[asynRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[asynRecordPROC]->offset = (unsigned short)offsetof(asynRecord, proc);
    prt->papFldDes[asynRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[asynRecordSTAT]->offset = (unsigned short)offsetof(asynRecord, stat);
    prt->papFldDes[asynRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[asynRecordSEVR]->offset = (unsigned short)offsetof(asynRecord, sevr);
    prt->papFldDes[asynRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[asynRecordAMSG]->offset = (unsigned short)offsetof(asynRecord, amsg);
    prt->papFldDes[asynRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[asynRecordNSTA]->offset = (unsigned short)offsetof(asynRecord, nsta);
    prt->papFldDes[asynRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[asynRecordNSEV]->offset = (unsigned short)offsetof(asynRecord, nsev);
    prt->papFldDes[asynRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[asynRecordNAMSG]->offset = (unsigned short)offsetof(asynRecord, namsg);
    prt->papFldDes[asynRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[asynRecordACKS]->offset = (unsigned short)offsetof(asynRecord, acks);
    prt->papFldDes[asynRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[asynRecordACKT]->offset = (unsigned short)offsetof(asynRecord, ackt);
    prt->papFldDes[asynRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[asynRecordDISS]->offset = (unsigned short)offsetof(asynRecord, diss);
    prt->papFldDes[asynRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[asynRecordLCNT]->offset = (unsigned short)offsetof(asynRecord, lcnt);
    prt->papFldDes[asynRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[asynRecordPACT]->offset = (unsigned short)offsetof(asynRecord, pact);
    prt->papFldDes[asynRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[asynRecordPUTF]->offset = (unsigned short)offsetof(asynRecord, putf);
    prt->papFldDes[asynRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[asynRecordRPRO]->offset = (unsigned short)offsetof(asynRecord, rpro);
    prt->papFldDes[asynRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[asynRecordASP]->offset = (unsigned short)offsetof(asynRecord, asp);
    prt->papFldDes[asynRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[asynRecordPPN]->offset = (unsigned short)offsetof(asynRecord, ppn);
    prt->papFldDes[asynRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[asynRecordPPNR]->offset = (unsigned short)offsetof(asynRecord, ppnr);
    prt->papFldDes[asynRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[asynRecordSPVT]->offset = (unsigned short)offsetof(asynRecord, spvt);
    prt->papFldDes[asynRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[asynRecordRSET]->offset = (unsigned short)offsetof(asynRecord, rset);
    prt->papFldDes[asynRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[asynRecordDSET]->offset = (unsigned short)offsetof(asynRecord, dset);
    prt->papFldDes[asynRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[asynRecordDPVT]->offset = (unsigned short)offsetof(asynRecord, dpvt);
    prt->papFldDes[asynRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[asynRecordRDES]->offset = (unsigned short)offsetof(asynRecord, rdes);
    prt->papFldDes[asynRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[asynRecordLSET]->offset = (unsigned short)offsetof(asynRecord, lset);
    prt->papFldDes[asynRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[asynRecordPRIO]->offset = (unsigned short)offsetof(asynRecord, prio);
    prt->papFldDes[asynRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[asynRecordTPRO]->offset = (unsigned short)offsetof(asynRecord, tpro);
    prt->papFldDes[asynRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[asynRecordBKPT]->offset = (unsigned short)offsetof(asynRecord, bkpt);
    prt->papFldDes[asynRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[asynRecordUDF]->offset = (unsigned short)offsetof(asynRecord, udf);
    prt->papFldDes[asynRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[asynRecordUDFS]->offset = (unsigned short)offsetof(asynRecord, udfs);
    prt->papFldDes[asynRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[asynRecordTIME]->offset = (unsigned short)offsetof(asynRecord, time);
    prt->papFldDes[asynRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[asynRecordUTAG]->offset = (unsigned short)offsetof(asynRecord, utag);
    prt->papFldDes[asynRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[asynRecordFLNK]->offset = (unsigned short)offsetof(asynRecord, flnk);
    prt->papFldDes[asynRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[asynRecordVAL]->offset = (unsigned short)offsetof(asynRecord, val);
    prt->papFldDes[asynRecordPORT]->size = sizeof(prec->port);
    prt->papFldDes[asynRecordPORT]->offset = (unsigned short)offsetof(asynRecord, port);
    prt->papFldDes[asynRecordADDR]->size = sizeof(prec->addr);
    prt->papFldDes[asynRecordADDR]->offset = (unsigned short)offsetof(asynRecord, addr);
    prt->papFldDes[asynRecordPCNCT]->size = sizeof(prec->pcnct);
    prt->papFldDes[asynRecordPCNCT]->offset = (unsigned short)offsetof(asynRecord, pcnct);
    prt->papFldDes[asynRecordDRVINFO]->size = sizeof(prec->drvinfo);
    prt->papFldDes[asynRecordDRVINFO]->offset = (unsigned short)offsetof(asynRecord, drvinfo);
    prt->papFldDes[asynRecordREASON]->size = sizeof(prec->reason);
    prt->papFldDes[asynRecordREASON]->offset = (unsigned short)offsetof(asynRecord, reason);
    prt->papFldDes[asynRecordTMOD]->size = sizeof(prec->tmod);
    prt->papFldDes[asynRecordTMOD]->offset = (unsigned short)offsetof(asynRecord, tmod);
    prt->papFldDes[asynRecordTMOT]->size = sizeof(prec->tmot);
    prt->papFldDes[asynRecordTMOT]->offset = (unsigned short)offsetof(asynRecord, tmot);
    prt->papFldDes[asynRecordIFACE]->size = sizeof(prec->iface);
    prt->papFldDes[asynRecordIFACE]->offset = (unsigned short)offsetof(asynRecord, iface);
    prt->papFldDes[asynRecordOCTETIV]->size = sizeof(prec->octetiv);
    prt->papFldDes[asynRecordOCTETIV]->offset = (unsigned short)offsetof(asynRecord, octetiv);
    prt->papFldDes[asynRecordOPTIONIV]->size = sizeof(prec->optioniv);
    prt->papFldDes[asynRecordOPTIONIV]->offset = (unsigned short)offsetof(asynRecord, optioniv);
    prt->papFldDes[asynRecordGPIBIV]->size = sizeof(prec->gpibiv);
    prt->papFldDes[asynRecordGPIBIV]->offset = (unsigned short)offsetof(asynRecord, gpibiv);
    prt->papFldDes[asynRecordI32IV]->size = sizeof(prec->i32iv);
    prt->papFldDes[asynRecordI32IV]->offset = (unsigned short)offsetof(asynRecord, i32iv);
    prt->papFldDes[asynRecordUI32IV]->size = sizeof(prec->ui32iv);
    prt->papFldDes[asynRecordUI32IV]->offset = (unsigned short)offsetof(asynRecord, ui32iv);
    prt->papFldDes[asynRecordF64IV]->size = sizeof(prec->f64iv);
    prt->papFldDes[asynRecordF64IV]->offset = (unsigned short)offsetof(asynRecord, f64iv);
    prt->papFldDes[asynRecordAOUT]->size = sizeof(prec->aout);
    prt->papFldDes[asynRecordAOUT]->offset = (unsigned short)offsetof(asynRecord, aout);
    prt->papFldDes[asynRecordOEOS]->size = sizeof(prec->oeos);
    prt->papFldDes[asynRecordOEOS]->offset = (unsigned short)offsetof(asynRecord, oeos);
    prt->papFldDes[asynRecordBOUT]->size = sizeof(prec->bout);
    prt->papFldDes[asynRecordBOUT]->offset = (unsigned short)offsetof(asynRecord, bout);
    prt->papFldDes[asynRecordOPTR]->size = sizeof(prec->optr);
    prt->papFldDes[asynRecordOPTR]->offset = (unsigned short)offsetof(asynRecord, optr);
    prt->papFldDes[asynRecordOMAX]->size = sizeof(prec->omax);
    prt->papFldDes[asynRecordOMAX]->offset = (unsigned short)offsetof(asynRecord, omax);
    prt->papFldDes[asynRecordNOWT]->size = sizeof(prec->nowt);
    prt->papFldDes[asynRecordNOWT]->offset = (unsigned short)offsetof(asynRecord, nowt);
    prt->papFldDes[asynRecordNAWT]->size = sizeof(prec->nawt);
    prt->papFldDes[asynRecordNAWT]->offset = (unsigned short)offsetof(asynRecord, nawt);
    prt->papFldDes[asynRecordOFMT]->size = sizeof(prec->ofmt);
    prt->papFldDes[asynRecordOFMT]->offset = (unsigned short)offsetof(asynRecord, ofmt);
    prt->papFldDes[asynRecordAINP]->size = sizeof(prec->ainp);
    prt->papFldDes[asynRecordAINP]->offset = (unsigned short)offsetof(asynRecord, ainp);
    prt->papFldDes[asynRecordTINP]->size = sizeof(prec->tinp);
    prt->papFldDes[asynRecordTINP]->offset = (unsigned short)offsetof(asynRecord, tinp);
    prt->papFldDes[asynRecordIEOS]->size = sizeof(prec->ieos);
    prt->papFldDes[asynRecordIEOS]->offset = (unsigned short)offsetof(asynRecord, ieos);
    prt->papFldDes[asynRecordBINP]->size = sizeof(prec->binp);
    prt->papFldDes[asynRecordBINP]->offset = (unsigned short)offsetof(asynRecord, binp);
    prt->papFldDes[asynRecordIPTR]->size = sizeof(prec->iptr);
    prt->papFldDes[asynRecordIPTR]->offset = (unsigned short)offsetof(asynRecord, iptr);
    prt->papFldDes[asynRecordIMAX]->size = sizeof(prec->imax);
    prt->papFldDes[asynRecordIMAX]->offset = (unsigned short)offsetof(asynRecord, imax);
    prt->papFldDes[asynRecordNRRD]->size = sizeof(prec->nrrd);
    prt->papFldDes[asynRecordNRRD]->offset = (unsigned short)offsetof(asynRecord, nrrd);
    prt->papFldDes[asynRecordNORD]->size = sizeof(prec->nord);
    prt->papFldDes[asynRecordNORD]->offset = (unsigned short)offsetof(asynRecord, nord);
    prt->papFldDes[asynRecordIFMT]->size = sizeof(prec->ifmt);
    prt->papFldDes[asynRecordIFMT]->offset = (unsigned short)offsetof(asynRecord, ifmt);
    prt->papFldDes[asynRecordEOMR]->size = sizeof(prec->eomr);
    prt->papFldDes[asynRecordEOMR]->offset = (unsigned short)offsetof(asynRecord, eomr);
    prt->papFldDes[asynRecordI32INP]->size = sizeof(prec->i32inp);
    prt->papFldDes[asynRecordI32INP]->offset = (unsigned short)offsetof(asynRecord, i32inp);
    prt->papFldDes[asynRecordI32OUT]->size = sizeof(prec->i32out);
    prt->papFldDes[asynRecordI32OUT]->offset = (unsigned short)offsetof(asynRecord, i32out);
    prt->papFldDes[asynRecordUI32INP]->size = sizeof(prec->ui32inp);
    prt->papFldDes[asynRecordUI32INP]->offset = (unsigned short)offsetof(asynRecord, ui32inp);
    prt->papFldDes[asynRecordUI32OUT]->size = sizeof(prec->ui32out);
    prt->papFldDes[asynRecordUI32OUT]->offset = (unsigned short)offsetof(asynRecord, ui32out);
    prt->papFldDes[asynRecordUI32MASK]->size = sizeof(prec->ui32mask);
    prt->papFldDes[asynRecordUI32MASK]->offset = (unsigned short)offsetof(asynRecord, ui32mask);
    prt->papFldDes[asynRecordF64INP]->size = sizeof(prec->f64inp);
    prt->papFldDes[asynRecordF64INP]->offset = (unsigned short)offsetof(asynRecord, f64inp);
    prt->papFldDes[asynRecordF64OUT]->size = sizeof(prec->f64out);
    prt->papFldDes[asynRecordF64OUT]->offset = (unsigned short)offsetof(asynRecord, f64out);
    prt->papFldDes[asynRecordBAUD]->size = sizeof(prec->baud);
    prt->papFldDes[asynRecordBAUD]->offset = (unsigned short)offsetof(asynRecord, baud);
    prt->papFldDes[asynRecordLBAUD]->size = sizeof(prec->lbaud);
    prt->papFldDes[asynRecordLBAUD]->offset = (unsigned short)offsetof(asynRecord, lbaud);
    prt->papFldDes[asynRecordPRTY]->size = sizeof(prec->prty);
    prt->papFldDes[asynRecordPRTY]->offset = (unsigned short)offsetof(asynRecord, prty);
    prt->papFldDes[asynRecordDBIT]->size = sizeof(prec->dbit);
    prt->papFldDes[asynRecordDBIT]->offset = (unsigned short)offsetof(asynRecord, dbit);
    prt->papFldDes[asynRecordSBIT]->size = sizeof(prec->sbit);
    prt->papFldDes[asynRecordSBIT]->offset = (unsigned short)offsetof(asynRecord, sbit);
    prt->papFldDes[asynRecordMCTL]->size = sizeof(prec->mctl);
    prt->papFldDes[asynRecordMCTL]->offset = (unsigned short)offsetof(asynRecord, mctl);
    prt->papFldDes[asynRecordFCTL]->size = sizeof(prec->fctl);
    prt->papFldDes[asynRecordFCTL]->offset = (unsigned short)offsetof(asynRecord, fctl);
    prt->papFldDes[asynRecordIXON]->size = sizeof(prec->ixon);
    prt->papFldDes[asynRecordIXON]->offset = (unsigned short)offsetof(asynRecord, ixon);
    prt->papFldDes[asynRecordIXOFF]->size = sizeof(prec->ixoff);
    prt->papFldDes[asynRecordIXOFF]->offset = (unsigned short)offsetof(asynRecord, ixoff);
    prt->papFldDes[asynRecordIXANY]->size = sizeof(prec->ixany);
    prt->papFldDes[asynRecordIXANY]->offset = (unsigned short)offsetof(asynRecord, ixany);
    prt->papFldDes[asynRecordHOSTINFO]->size = sizeof(prec->hostinfo);
    prt->papFldDes[asynRecordHOSTINFO]->offset = (unsigned short)offsetof(asynRecord, hostinfo);
    prt->papFldDes[asynRecordDRTO]->size = sizeof(prec->drto);
    prt->papFldDes[asynRecordDRTO]->offset = (unsigned short)offsetof(asynRecord, drto);
    prt->papFldDes[asynRecordUCMD]->size = sizeof(prec->ucmd);
    prt->papFldDes[asynRecordUCMD]->offset = (unsigned short)offsetof(asynRecord, ucmd);
    prt->papFldDes[asynRecordACMD]->size = sizeof(prec->acmd);
    prt->papFldDes[asynRecordACMD]->offset = (unsigned short)offsetof(asynRecord, acmd);
    prt->papFldDes[asynRecordSPR]->size = sizeof(prec->spr);
    prt->papFldDes[asynRecordSPR]->offset = (unsigned short)offsetof(asynRecord, spr);
    prt->papFldDes[asynRecordTMSK]->size = sizeof(prec->tmsk);
    prt->papFldDes[asynRecordTMSK]->offset = (unsigned short)offsetof(asynRecord, tmsk);
    prt->papFldDes[asynRecordTB0]->size = sizeof(prec->tb0);
    prt->papFldDes[asynRecordTB0]->offset = (unsigned short)offsetof(asynRecord, tb0);
    prt->papFldDes[asynRecordTB1]->size = sizeof(prec->tb1);
    prt->papFldDes[asynRecordTB1]->offset = (unsigned short)offsetof(asynRecord, tb1);
    prt->papFldDes[asynRecordTB2]->size = sizeof(prec->tb2);
    prt->papFldDes[asynRecordTB2]->offset = (unsigned short)offsetof(asynRecord, tb2);
    prt->papFldDes[asynRecordTB3]->size = sizeof(prec->tb3);
    prt->papFldDes[asynRecordTB3]->offset = (unsigned short)offsetof(asynRecord, tb3);
    prt->papFldDes[asynRecordTB4]->size = sizeof(prec->tb4);
    prt->papFldDes[asynRecordTB4]->offset = (unsigned short)offsetof(asynRecord, tb4);
    prt->papFldDes[asynRecordTB5]->size = sizeof(prec->tb5);
    prt->papFldDes[asynRecordTB5]->offset = (unsigned short)offsetof(asynRecord, tb5);
    prt->papFldDes[asynRecordTIOM]->size = sizeof(prec->tiom);
    prt->papFldDes[asynRecordTIOM]->offset = (unsigned short)offsetof(asynRecord, tiom);
    prt->papFldDes[asynRecordTIB0]->size = sizeof(prec->tib0);
    prt->papFldDes[asynRecordTIB0]->offset = (unsigned short)offsetof(asynRecord, tib0);
    prt->papFldDes[asynRecordTIB1]->size = sizeof(prec->tib1);
    prt->papFldDes[asynRecordTIB1]->offset = (unsigned short)offsetof(asynRecord, tib1);
    prt->papFldDes[asynRecordTIB2]->size = sizeof(prec->tib2);
    prt->papFldDes[asynRecordTIB2]->offset = (unsigned short)offsetof(asynRecord, tib2);
    prt->papFldDes[asynRecordTINM]->size = sizeof(prec->tinm);
    prt->papFldDes[asynRecordTINM]->offset = (unsigned short)offsetof(asynRecord, tinm);
    prt->papFldDes[asynRecordTINB0]->size = sizeof(prec->tinb0);
    prt->papFldDes[asynRecordTINB0]->offset = (unsigned short)offsetof(asynRecord, tinb0);
    prt->papFldDes[asynRecordTINB1]->size = sizeof(prec->tinb1);
    prt->papFldDes[asynRecordTINB1]->offset = (unsigned short)offsetof(asynRecord, tinb1);
    prt->papFldDes[asynRecordTINB2]->size = sizeof(prec->tinb2);
    prt->papFldDes[asynRecordTINB2]->offset = (unsigned short)offsetof(asynRecord, tinb2);
    prt->papFldDes[asynRecordTINB3]->size = sizeof(prec->tinb3);
    prt->papFldDes[asynRecordTINB3]->offset = (unsigned short)offsetof(asynRecord, tinb3);
    prt->papFldDes[asynRecordTSIZ]->size = sizeof(prec->tsiz);
    prt->papFldDes[asynRecordTSIZ]->offset = (unsigned short)offsetof(asynRecord, tsiz);
    prt->papFldDes[asynRecordTFIL]->size = sizeof(prec->tfil);
    prt->papFldDes[asynRecordTFIL]->offset = (unsigned short)offsetof(asynRecord, tfil);
    prt->papFldDes[asynRecordAUCT]->size = sizeof(prec->auct);
    prt->papFldDes[asynRecordAUCT]->offset = (unsigned short)offsetof(asynRecord, auct);
    prt->papFldDes[asynRecordCNCT]->size = sizeof(prec->cnct);
    prt->papFldDes[asynRecordCNCT]->offset = (unsigned short)offsetof(asynRecord, cnct);
    prt->papFldDes[asynRecordENBL]->size = sizeof(prec->enbl);
    prt->papFldDes[asynRecordENBL]->offset = (unsigned short)offsetof(asynRecord, enbl);
    prt->papFldDes[asynRecordERRS]->size = sizeof(prec->errs);
    prt->papFldDes[asynRecordERRS]->offset = (unsigned short)offsetof(asynRecord, errs);
    prt->papFldDes[asynRecordAQR]->size = sizeof(prec->aqr);
    prt->papFldDes[asynRecordAQR]->offset = (unsigned short)offsetof(asynRecord, aqr);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(asynRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_asynRecord_H */
