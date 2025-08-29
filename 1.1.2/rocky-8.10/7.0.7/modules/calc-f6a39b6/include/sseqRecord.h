/** @file sseqRecord.h
 * @brief Declarations for the @ref sseqRecord "sseq" record type.
 *
 * This header was generated from sseqRecord.dbd
 */

#ifndef INC_sseqRecord_H
#define INC_sseqRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef sseqLNKV_NUM_CHOICES
/** @brief Enumerated type from menu sseqLNKV */
typedef enum {
    sseqLNKV_EXT_NC                 /**< @brief State string "Ext PV NC" */,
    sseqLNKV_EXT                    /**< @brief State string "Ext PV OK" */,
    sseqLNKV_LOC                    /**< @brief State string "Local PV" */,
    sseqLNKV_CON                    /**< @brief State string "Constant" */
} sseqLNKV;
/** @brief Number of states defined for menu sseqLNKV */
#define sseqLNKV_NUM_CHOICES 4
#endif

#ifndef sseqWAIT_NUM_CHOICES
/** @brief Enumerated type from menu sseqWAIT */
typedef enum {
    sseqWAIT_NoWait                 /**< @brief State string "NoWait" */,
    sseqWAIT_Wait                   /**< @brief State string "Wait" */,
    sseqWAIT_Wait1                  /**< @brief State string "After1" */,
    sseqWAIT_Wait2                  /**< @brief State string "After2" */,
    sseqWAIT_Wait3                  /**< @brief State string "After3" */,
    sseqWAIT_Wait4                  /**< @brief State string "After4" */,
    sseqWAIT_Wait5                  /**< @brief State string "After5" */,
    sseqWAIT_Wait6                  /**< @brief State string "After6" */,
    sseqWAIT_Wait7                  /**< @brief State string "After7" */,
    sseqWAIT_Wait8                  /**< @brief State string "After8" */,
    sseqWAIT_Wait9                  /**< @brief State string "After9" */,
    sseqWAIT_Wait10                 /**< @brief State string "AfterA" */
} sseqWAIT;
/** @brief Number of states defined for menu sseqWAIT */
#define sseqWAIT_NUM_CHOICES 12
#endif

#ifndef sseqSELM_NUM_CHOICES
/** @brief Enumerated type from menu sseqSELM */
typedef enum {
    sseqSELM_All                    /**< @brief State string "All" */,
    sseqSELM_Specified              /**< @brief State string "Specified" */,
    sseqSELM_Mask                   /**< @brief State string "Mask" */
} sseqSELM;
/** @brief Number of states defined for menu sseqSELM */
#define sseqSELM_NUM_CHOICES 3
#endif

/** @brief Declaration of sseq record type. */
typedef struct sseqRecord {
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
    epicsInt32          val;        /**< @brief Used to trigger */
    epicsEnum16         selm;       /**< @brief Select Mechanism */
    epicsUInt16         seln;       /**< @brief Link Selection */
    DBLINK              sell;       /**< @brief Link Selection Loc */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsFloat64        dly1;       /**< @brief Delay 1 */
    DBLINK              dol1;       /**< @brief Input link1 */
    epicsFloat64        do1;        /**< @brief Constant input 1 */
    DBLINK              lnk1;       /**< @brief Output Link 1 */
    char                str1[40];   /**< @brief String value 1 */
    epicsInt16          dt1;        /**< @brief DOL link type */
    epicsInt16          lt1;        /**< @brief LNK link type */
    epicsEnum16         wait1;      /**< @brief Wait for completion? */
    epicsInt16          werr1;      
    epicsInt16          wtg1;       
    epicsInt16          ix1;        
    epicsEnum16         dol1v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk1v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly2;       /**< @brief Delay 2 */
    DBLINK              dol2;       /**< @brief Input link 2 */
    epicsFloat64        do2;        /**< @brief Constant input 2 */
    DBLINK              lnk2;       /**< @brief Output Link 2 */
    char                str2[40];   /**< @brief String value 2 */
    epicsInt16          dt2;        /**< @brief DOL link type */
    epicsInt16          lt2;        /**< @brief LNK link type */
    epicsEnum16         wait2;      /**< @brief Wait for completion? */
    epicsInt16          werr2;      
    epicsInt16          wtg2;       
    epicsInt16          ix2;        
    epicsEnum16         dol2v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk2v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly3;       /**< @brief Delay 3 */
    DBLINK              dol3;       /**< @brief Input link 3 */
    epicsFloat64        do3;        /**< @brief Constant input 3 */
    DBLINK              lnk3;       /**< @brief Output Link 3 */
    char                str3[40];   /**< @brief String value 3 */
    epicsInt16          dt3;        /**< @brief DOL link type */
    epicsInt16          lt3;        /**< @brief LNK link type */
    epicsEnum16         wait3;      /**< @brief Wait for completion? */
    epicsInt16          werr3;      
    epicsInt16          wtg3;       
    epicsInt16          ix3;        
    epicsEnum16         dol3v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk3v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly4;       /**< @brief Delay 4 */
    DBLINK              dol4;       /**< @brief Input link 4 */
    epicsFloat64        do4;        /**< @brief Constant input 4 */
    DBLINK              lnk4;       /**< @brief Output Link 4 */
    char                str4[40];   /**< @brief String value 4 */
    epicsInt16          dt4;        /**< @brief DOL link type */
    epicsInt16          lt4;        /**< @brief LNK link type */
    epicsEnum16         wait4;      /**< @brief Wait for completion? */
    epicsInt16          werr4;      
    epicsInt16          wtg4;       
    epicsInt16          ix4;        
    epicsEnum16         dol4v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk4v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly5;       /**< @brief Delay 5 */
    DBLINK              dol5;       /**< @brief Input link 5 */
    epicsFloat64        do5;        /**< @brief Constant input 5 */
    DBLINK              lnk5;       /**< @brief Output Link 5 */
    char                str5[40];   /**< @brief String value 5 */
    epicsInt16          dt5;        /**< @brief DOL link type */
    epicsInt16          lt5;        /**< @brief LNK link type */
    epicsEnum16         wait5;      /**< @brief Wait for completion? */
    epicsInt16          werr5;      
    epicsInt16          wtg5;       
    epicsInt16          ix5;        
    epicsEnum16         dol5v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk5v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly6;       /**< @brief Delay 6 */
    DBLINK              dol6;       /**< @brief Input link 6 */
    epicsFloat64        do6;        /**< @brief Constant input 6 */
    DBLINK              lnk6;       /**< @brief Output Link 6 */
    char                str6[40];   /**< @brief String value 6 */
    epicsInt16          dt6;        /**< @brief DOL link type */
    epicsInt16          lt6;        /**< @brief LNK link type */
    epicsEnum16         wait6;      /**< @brief Wait for completion? */
    epicsInt16          werr6;      
    epicsInt16          wtg6;       
    epicsInt16          ix6;        
    epicsEnum16         dol6v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk6v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly7;       /**< @brief Delay 7 */
    DBLINK              dol7;       /**< @brief Input link 7 */
    epicsFloat64        do7;        /**< @brief Constant input 7 */
    DBLINK              lnk7;       /**< @brief Output Link 7 */
    char                str7[40];   /**< @brief String value 7 */
    epicsInt16          dt7;        /**< @brief DOL link type */
    epicsInt16          lt7;        /**< @brief LNK link type */
    epicsEnum16         wait7;      /**< @brief Wait for completion? */
    epicsInt16          werr7;      
    epicsInt16          wtg7;       
    epicsInt16          ix7;        
    epicsEnum16         dol7v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk7v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly8;       /**< @brief Delay 8 */
    DBLINK              dol8;       /**< @brief Input link 8 */
    epicsFloat64        do8;        /**< @brief Constant input 8 */
    DBLINK              lnk8;       /**< @brief Output Link 8 */
    char                str8[40];   /**< @brief String value 8 */
    epicsInt16          dt8;        /**< @brief DOL link type */
    epicsInt16          lt8;        /**< @brief LNK link type */
    epicsEnum16         wait8;      /**< @brief Wait for completion? */
    epicsInt16          werr8;      
    epicsInt16          wtg8;       
    epicsInt16          ix8;        
    epicsEnum16         dol8v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk8v;      /**< @brief LNK LINK Status */
    epicsFloat64        dly9;       /**< @brief Delay 9 */
    DBLINK              dol9;       /**< @brief Input link 9 */
    epicsFloat64        do9;        /**< @brief Constant input 9 */
    DBLINK              lnk9;       /**< @brief Output Link 9 */
    char                str9[40];   /**< @brief String value 9 */
    epicsInt16          dt9;        /**< @brief DOL link type */
    epicsInt16          lt9;        /**< @brief LNK link type */
    epicsEnum16         wait9;      /**< @brief Wait for completion? */
    epicsInt16          werr9;      
    epicsInt16          wtg9;       
    epicsInt16          ix9;        
    epicsEnum16         dol9v;      /**< @brief DOL LINK Status */
    epicsEnum16         lnk9v;      /**< @brief LNK LINK Status */
    epicsFloat64        dlya;       /**< @brief Delay 10 */
    DBLINK              dola;       /**< @brief Input link 10 */
    epicsFloat64        doa;        /**< @brief Constant input 10 */
    DBLINK              lnka;       /**< @brief Output Link 10 */
    char                stra[40];   /**< @brief String value A */
    epicsInt16          dta;        /**< @brief DOL link type */
    epicsInt16          lta;        /**< @brief LNK link type */
    epicsEnum16         waita;      /**< @brief Wait for completion? */
    epicsInt16          werra;      
    epicsInt16          wtga;       
    epicsInt16          ixa;        
    epicsEnum16         dolav;      /**< @brief DOL LINK Status */
    epicsEnum16         lnkav;      /**< @brief LNK LINK Status */
    epicsInt16          abort;      /**< @brief Abort sequence */
    epicsInt16          aborting;   /**< @brief Aborting */
    epicsInt16          busy;       /**< @brief Sequence active */
} sseqRecord;

typedef enum {
	sseqRecordNAME = 0,
	sseqRecordDESC = 1,
	sseqRecordASG = 2,
	sseqRecordSCAN = 3,
	sseqRecordPINI = 4,
	sseqRecordPHAS = 5,
	sseqRecordEVNT = 6,
	sseqRecordTSE = 7,
	sseqRecordTSEL = 8,
	sseqRecordDTYP = 9,
	sseqRecordDISV = 10,
	sseqRecordDISA = 11,
	sseqRecordSDIS = 12,
	sseqRecordMLOK = 13,
	sseqRecordMLIS = 14,
	sseqRecordBKLNK = 15,
	sseqRecordDISP = 16,
	sseqRecordPROC = 17,
	sseqRecordSTAT = 18,
	sseqRecordSEVR = 19,
	sseqRecordAMSG = 20,
	sseqRecordNSTA = 21,
	sseqRecordNSEV = 22,
	sseqRecordNAMSG = 23,
	sseqRecordACKS = 24,
	sseqRecordACKT = 25,
	sseqRecordDISS = 26,
	sseqRecordLCNT = 27,
	sseqRecordPACT = 28,
	sseqRecordPUTF = 29,
	sseqRecordRPRO = 30,
	sseqRecordASP = 31,
	sseqRecordPPN = 32,
	sseqRecordPPNR = 33,
	sseqRecordSPVT = 34,
	sseqRecordRSET = 35,
	sseqRecordDSET = 36,
	sseqRecordDPVT = 37,
	sseqRecordRDES = 38,
	sseqRecordLSET = 39,
	sseqRecordPRIO = 40,
	sseqRecordTPRO = 41,
	sseqRecordBKPT = 42,
	sseqRecordUDF = 43,
	sseqRecordUDFS = 44,
	sseqRecordTIME = 45,
	sseqRecordUTAG = 46,
	sseqRecordFLNK = 47,
	sseqRecordVAL = 48,
	sseqRecordSELM = 49,
	sseqRecordSELN = 50,
	sseqRecordSELL = 51,
	sseqRecordPREC = 52,
	sseqRecordDLY1 = 53,
	sseqRecordDOL1 = 54,
	sseqRecordDO1 = 55,
	sseqRecordLNK1 = 56,
	sseqRecordSTR1 = 57,
	sseqRecordDT1 = 58,
	sseqRecordLT1 = 59,
	sseqRecordWAIT1 = 60,
	sseqRecordWERR1 = 61,
	sseqRecordWTG1 = 62,
	sseqRecordIX1 = 63,
	sseqRecordDOL1V = 64,
	sseqRecordLNK1V = 65,
	sseqRecordDLY2 = 66,
	sseqRecordDOL2 = 67,
	sseqRecordDO2 = 68,
	sseqRecordLNK2 = 69,
	sseqRecordSTR2 = 70,
	sseqRecordDT2 = 71,
	sseqRecordLT2 = 72,
	sseqRecordWAIT2 = 73,
	sseqRecordWERR2 = 74,
	sseqRecordWTG2 = 75,
	sseqRecordIX2 = 76,
	sseqRecordDOL2V = 77,
	sseqRecordLNK2V = 78,
	sseqRecordDLY3 = 79,
	sseqRecordDOL3 = 80,
	sseqRecordDO3 = 81,
	sseqRecordLNK3 = 82,
	sseqRecordSTR3 = 83,
	sseqRecordDT3 = 84,
	sseqRecordLT3 = 85,
	sseqRecordWAIT3 = 86,
	sseqRecordWERR3 = 87,
	sseqRecordWTG3 = 88,
	sseqRecordIX3 = 89,
	sseqRecordDOL3V = 90,
	sseqRecordLNK3V = 91,
	sseqRecordDLY4 = 92,
	sseqRecordDOL4 = 93,
	sseqRecordDO4 = 94,
	sseqRecordLNK4 = 95,
	sseqRecordSTR4 = 96,
	sseqRecordDT4 = 97,
	sseqRecordLT4 = 98,
	sseqRecordWAIT4 = 99,
	sseqRecordWERR4 = 100,
	sseqRecordWTG4 = 101,
	sseqRecordIX4 = 102,
	sseqRecordDOL4V = 103,
	sseqRecordLNK4V = 104,
	sseqRecordDLY5 = 105,
	sseqRecordDOL5 = 106,
	sseqRecordDO5 = 107,
	sseqRecordLNK5 = 108,
	sseqRecordSTR5 = 109,
	sseqRecordDT5 = 110,
	sseqRecordLT5 = 111,
	sseqRecordWAIT5 = 112,
	sseqRecordWERR5 = 113,
	sseqRecordWTG5 = 114,
	sseqRecordIX5 = 115,
	sseqRecordDOL5V = 116,
	sseqRecordLNK5V = 117,
	sseqRecordDLY6 = 118,
	sseqRecordDOL6 = 119,
	sseqRecordDO6 = 120,
	sseqRecordLNK6 = 121,
	sseqRecordSTR6 = 122,
	sseqRecordDT6 = 123,
	sseqRecordLT6 = 124,
	sseqRecordWAIT6 = 125,
	sseqRecordWERR6 = 126,
	sseqRecordWTG6 = 127,
	sseqRecordIX6 = 128,
	sseqRecordDOL6V = 129,
	sseqRecordLNK6V = 130,
	sseqRecordDLY7 = 131,
	sseqRecordDOL7 = 132,
	sseqRecordDO7 = 133,
	sseqRecordLNK7 = 134,
	sseqRecordSTR7 = 135,
	sseqRecordDT7 = 136,
	sseqRecordLT7 = 137,
	sseqRecordWAIT7 = 138,
	sseqRecordWERR7 = 139,
	sseqRecordWTG7 = 140,
	sseqRecordIX7 = 141,
	sseqRecordDOL7V = 142,
	sseqRecordLNK7V = 143,
	sseqRecordDLY8 = 144,
	sseqRecordDOL8 = 145,
	sseqRecordDO8 = 146,
	sseqRecordLNK8 = 147,
	sseqRecordSTR8 = 148,
	sseqRecordDT8 = 149,
	sseqRecordLT8 = 150,
	sseqRecordWAIT8 = 151,
	sseqRecordWERR8 = 152,
	sseqRecordWTG8 = 153,
	sseqRecordIX8 = 154,
	sseqRecordDOL8V = 155,
	sseqRecordLNK8V = 156,
	sseqRecordDLY9 = 157,
	sseqRecordDOL9 = 158,
	sseqRecordDO9 = 159,
	sseqRecordLNK9 = 160,
	sseqRecordSTR9 = 161,
	sseqRecordDT9 = 162,
	sseqRecordLT9 = 163,
	sseqRecordWAIT9 = 164,
	sseqRecordWERR9 = 165,
	sseqRecordWTG9 = 166,
	sseqRecordIX9 = 167,
	sseqRecordDOL9V = 168,
	sseqRecordLNK9V = 169,
	sseqRecordDLYA = 170,
	sseqRecordDOLA = 171,
	sseqRecordDOA = 172,
	sseqRecordLNKA = 173,
	sseqRecordSTRA = 174,
	sseqRecordDTA = 175,
	sseqRecordLTA = 176,
	sseqRecordWAITA = 177,
	sseqRecordWERRA = 178,
	sseqRecordWTGA = 179,
	sseqRecordIXA = 180,
	sseqRecordDOLAV = 181,
	sseqRecordLNKAV = 182,
	sseqRecordABORT = 183,
	sseqRecordABORTING = 184,
	sseqRecordBUSY = 185
} sseqFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int sseqRecordSizeOffset(dbRecordType *prt)
{
    sseqRecord *prec = 0;

    if (prt->no_fields != 186) {
        cantProceed("IOC build or installation error:\n"
            "    The sseqRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 186.\n",
            prt->no_fields);
    }
    prt->papFldDes[sseqRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[sseqRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[sseqRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[sseqRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[sseqRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[sseqRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[sseqRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[sseqRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[sseqRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[sseqRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[sseqRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[sseqRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[sseqRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[sseqRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[sseqRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[sseqRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[sseqRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[sseqRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[sseqRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[sseqRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[sseqRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[sseqRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[sseqRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[sseqRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[sseqRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[sseqRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[sseqRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[sseqRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[sseqRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[sseqRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[sseqRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[sseqRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[sseqRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[sseqRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[sseqRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[sseqRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[sseqRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[sseqRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[sseqRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[sseqRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[sseqRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[sseqRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[sseqRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[sseqRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[sseqRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[sseqRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[sseqRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[sseqRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[sseqRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[sseqRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[sseqRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[sseqRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[sseqRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[sseqRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[sseqRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[sseqRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[sseqRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[sseqRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[sseqRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[sseqRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[sseqRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[sseqRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[sseqRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[sseqRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[sseqRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[sseqRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[sseqRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[sseqRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[sseqRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[sseqRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[sseqRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[sseqRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[sseqRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[sseqRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[sseqRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[sseqRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[sseqRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[sseqRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[sseqRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[sseqRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[sseqRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[sseqRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[sseqRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[sseqRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[sseqRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[sseqRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[sseqRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[sseqRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[sseqRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[sseqRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[sseqRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[sseqRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[sseqRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[sseqRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[sseqRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[sseqRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[sseqRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[sseqRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[sseqRecordSELM]->size = sizeof(prec->selm);
    prt->papFldDes[sseqRecordSELM]->offset = (unsigned short)((char *)&prec->selm - (char *)prec);
    prt->papFldDes[sseqRecordSELN]->size = sizeof(prec->seln);
    prt->papFldDes[sseqRecordSELN]->offset = (unsigned short)((char *)&prec->seln - (char *)prec);
    prt->papFldDes[sseqRecordSELL]->size = sizeof(prec->sell);
    prt->papFldDes[sseqRecordSELL]->offset = (unsigned short)((char *)&prec->sell - (char *)prec);
    prt->papFldDes[sseqRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[sseqRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[sseqRecordDLY1]->size = sizeof(prec->dly1);
    prt->papFldDes[sseqRecordDLY1]->offset = (unsigned short)((char *)&prec->dly1 - (char *)prec);
    prt->papFldDes[sseqRecordDOL1]->size = sizeof(prec->dol1);
    prt->papFldDes[sseqRecordDOL1]->offset = (unsigned short)((char *)&prec->dol1 - (char *)prec);
    prt->papFldDes[sseqRecordDO1]->size = sizeof(prec->do1);
    prt->papFldDes[sseqRecordDO1]->offset = (unsigned short)((char *)&prec->do1 - (char *)prec);
    prt->papFldDes[sseqRecordLNK1]->size = sizeof(prec->lnk1);
    prt->papFldDes[sseqRecordLNK1]->offset = (unsigned short)((char *)&prec->lnk1 - (char *)prec);
    prt->papFldDes[sseqRecordSTR1]->size = sizeof(prec->str1);
    prt->papFldDes[sseqRecordSTR1]->offset = (unsigned short)((char *)&prec->str1 - (char *)prec);
    prt->papFldDes[sseqRecordDT1]->size = sizeof(prec->dt1);
    prt->papFldDes[sseqRecordDT1]->offset = (unsigned short)((char *)&prec->dt1 - (char *)prec);
    prt->papFldDes[sseqRecordLT1]->size = sizeof(prec->lt1);
    prt->papFldDes[sseqRecordLT1]->offset = (unsigned short)((char *)&prec->lt1 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT1]->size = sizeof(prec->wait1);
    prt->papFldDes[sseqRecordWAIT1]->offset = (unsigned short)((char *)&prec->wait1 - (char *)prec);
    prt->papFldDes[sseqRecordWERR1]->size = sizeof(prec->werr1);
    prt->papFldDes[sseqRecordWERR1]->offset = (unsigned short)((char *)&prec->werr1 - (char *)prec);
    prt->papFldDes[sseqRecordWTG1]->size = sizeof(prec->wtg1);
    prt->papFldDes[sseqRecordWTG1]->offset = (unsigned short)((char *)&prec->wtg1 - (char *)prec);
    prt->papFldDes[sseqRecordIX1]->size = sizeof(prec->ix1);
    prt->papFldDes[sseqRecordIX1]->offset = (unsigned short)((char *)&prec->ix1 - (char *)prec);
    prt->papFldDes[sseqRecordDOL1V]->size = sizeof(prec->dol1v);
    prt->papFldDes[sseqRecordDOL1V]->offset = (unsigned short)((char *)&prec->dol1v - (char *)prec);
    prt->papFldDes[sseqRecordLNK1V]->size = sizeof(prec->lnk1v);
    prt->papFldDes[sseqRecordLNK1V]->offset = (unsigned short)((char *)&prec->lnk1v - (char *)prec);
    prt->papFldDes[sseqRecordDLY2]->size = sizeof(prec->dly2);
    prt->papFldDes[sseqRecordDLY2]->offset = (unsigned short)((char *)&prec->dly2 - (char *)prec);
    prt->papFldDes[sseqRecordDOL2]->size = sizeof(prec->dol2);
    prt->papFldDes[sseqRecordDOL2]->offset = (unsigned short)((char *)&prec->dol2 - (char *)prec);
    prt->papFldDes[sseqRecordDO2]->size = sizeof(prec->do2);
    prt->papFldDes[sseqRecordDO2]->offset = (unsigned short)((char *)&prec->do2 - (char *)prec);
    prt->papFldDes[sseqRecordLNK2]->size = sizeof(prec->lnk2);
    prt->papFldDes[sseqRecordLNK2]->offset = (unsigned short)((char *)&prec->lnk2 - (char *)prec);
    prt->papFldDes[sseqRecordSTR2]->size = sizeof(prec->str2);
    prt->papFldDes[sseqRecordSTR2]->offset = (unsigned short)((char *)&prec->str2 - (char *)prec);
    prt->papFldDes[sseqRecordDT2]->size = sizeof(prec->dt2);
    prt->papFldDes[sseqRecordDT2]->offset = (unsigned short)((char *)&prec->dt2 - (char *)prec);
    prt->papFldDes[sseqRecordLT2]->size = sizeof(prec->lt2);
    prt->papFldDes[sseqRecordLT2]->offset = (unsigned short)((char *)&prec->lt2 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT2]->size = sizeof(prec->wait2);
    prt->papFldDes[sseqRecordWAIT2]->offset = (unsigned short)((char *)&prec->wait2 - (char *)prec);
    prt->papFldDes[sseqRecordWERR2]->size = sizeof(prec->werr2);
    prt->papFldDes[sseqRecordWERR2]->offset = (unsigned short)((char *)&prec->werr2 - (char *)prec);
    prt->papFldDes[sseqRecordWTG2]->size = sizeof(prec->wtg2);
    prt->papFldDes[sseqRecordWTG2]->offset = (unsigned short)((char *)&prec->wtg2 - (char *)prec);
    prt->papFldDes[sseqRecordIX2]->size = sizeof(prec->ix2);
    prt->papFldDes[sseqRecordIX2]->offset = (unsigned short)((char *)&prec->ix2 - (char *)prec);
    prt->papFldDes[sseqRecordDOL2V]->size = sizeof(prec->dol2v);
    prt->papFldDes[sseqRecordDOL2V]->offset = (unsigned short)((char *)&prec->dol2v - (char *)prec);
    prt->papFldDes[sseqRecordLNK2V]->size = sizeof(prec->lnk2v);
    prt->papFldDes[sseqRecordLNK2V]->offset = (unsigned short)((char *)&prec->lnk2v - (char *)prec);
    prt->papFldDes[sseqRecordDLY3]->size = sizeof(prec->dly3);
    prt->papFldDes[sseqRecordDLY3]->offset = (unsigned short)((char *)&prec->dly3 - (char *)prec);
    prt->papFldDes[sseqRecordDOL3]->size = sizeof(prec->dol3);
    prt->papFldDes[sseqRecordDOL3]->offset = (unsigned short)((char *)&prec->dol3 - (char *)prec);
    prt->papFldDes[sseqRecordDO3]->size = sizeof(prec->do3);
    prt->papFldDes[sseqRecordDO3]->offset = (unsigned short)((char *)&prec->do3 - (char *)prec);
    prt->papFldDes[sseqRecordLNK3]->size = sizeof(prec->lnk3);
    prt->papFldDes[sseqRecordLNK3]->offset = (unsigned short)((char *)&prec->lnk3 - (char *)prec);
    prt->papFldDes[sseqRecordSTR3]->size = sizeof(prec->str3);
    prt->papFldDes[sseqRecordSTR3]->offset = (unsigned short)((char *)&prec->str3 - (char *)prec);
    prt->papFldDes[sseqRecordDT3]->size = sizeof(prec->dt3);
    prt->papFldDes[sseqRecordDT3]->offset = (unsigned short)((char *)&prec->dt3 - (char *)prec);
    prt->papFldDes[sseqRecordLT3]->size = sizeof(prec->lt3);
    prt->papFldDes[sseqRecordLT3]->offset = (unsigned short)((char *)&prec->lt3 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT3]->size = sizeof(prec->wait3);
    prt->papFldDes[sseqRecordWAIT3]->offset = (unsigned short)((char *)&prec->wait3 - (char *)prec);
    prt->papFldDes[sseqRecordWERR3]->size = sizeof(prec->werr3);
    prt->papFldDes[sseqRecordWERR3]->offset = (unsigned short)((char *)&prec->werr3 - (char *)prec);
    prt->papFldDes[sseqRecordWTG3]->size = sizeof(prec->wtg3);
    prt->papFldDes[sseqRecordWTG3]->offset = (unsigned short)((char *)&prec->wtg3 - (char *)prec);
    prt->papFldDes[sseqRecordIX3]->size = sizeof(prec->ix3);
    prt->papFldDes[sseqRecordIX3]->offset = (unsigned short)((char *)&prec->ix3 - (char *)prec);
    prt->papFldDes[sseqRecordDOL3V]->size = sizeof(prec->dol3v);
    prt->papFldDes[sseqRecordDOL3V]->offset = (unsigned short)((char *)&prec->dol3v - (char *)prec);
    prt->papFldDes[sseqRecordLNK3V]->size = sizeof(prec->lnk3v);
    prt->papFldDes[sseqRecordLNK3V]->offset = (unsigned short)((char *)&prec->lnk3v - (char *)prec);
    prt->papFldDes[sseqRecordDLY4]->size = sizeof(prec->dly4);
    prt->papFldDes[sseqRecordDLY4]->offset = (unsigned short)((char *)&prec->dly4 - (char *)prec);
    prt->papFldDes[sseqRecordDOL4]->size = sizeof(prec->dol4);
    prt->papFldDes[sseqRecordDOL4]->offset = (unsigned short)((char *)&prec->dol4 - (char *)prec);
    prt->papFldDes[sseqRecordDO4]->size = sizeof(prec->do4);
    prt->papFldDes[sseqRecordDO4]->offset = (unsigned short)((char *)&prec->do4 - (char *)prec);
    prt->papFldDes[sseqRecordLNK4]->size = sizeof(prec->lnk4);
    prt->papFldDes[sseqRecordLNK4]->offset = (unsigned short)((char *)&prec->lnk4 - (char *)prec);
    prt->papFldDes[sseqRecordSTR4]->size = sizeof(prec->str4);
    prt->papFldDes[sseqRecordSTR4]->offset = (unsigned short)((char *)&prec->str4 - (char *)prec);
    prt->papFldDes[sseqRecordDT4]->size = sizeof(prec->dt4);
    prt->papFldDes[sseqRecordDT4]->offset = (unsigned short)((char *)&prec->dt4 - (char *)prec);
    prt->papFldDes[sseqRecordLT4]->size = sizeof(prec->lt4);
    prt->papFldDes[sseqRecordLT4]->offset = (unsigned short)((char *)&prec->lt4 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT4]->size = sizeof(prec->wait4);
    prt->papFldDes[sseqRecordWAIT4]->offset = (unsigned short)((char *)&prec->wait4 - (char *)prec);
    prt->papFldDes[sseqRecordWERR4]->size = sizeof(prec->werr4);
    prt->papFldDes[sseqRecordWERR4]->offset = (unsigned short)((char *)&prec->werr4 - (char *)prec);
    prt->papFldDes[sseqRecordWTG4]->size = sizeof(prec->wtg4);
    prt->papFldDes[sseqRecordWTG4]->offset = (unsigned short)((char *)&prec->wtg4 - (char *)prec);
    prt->papFldDes[sseqRecordIX4]->size = sizeof(prec->ix4);
    prt->papFldDes[sseqRecordIX4]->offset = (unsigned short)((char *)&prec->ix4 - (char *)prec);
    prt->papFldDes[sseqRecordDOL4V]->size = sizeof(prec->dol4v);
    prt->papFldDes[sseqRecordDOL4V]->offset = (unsigned short)((char *)&prec->dol4v - (char *)prec);
    prt->papFldDes[sseqRecordLNK4V]->size = sizeof(prec->lnk4v);
    prt->papFldDes[sseqRecordLNK4V]->offset = (unsigned short)((char *)&prec->lnk4v - (char *)prec);
    prt->papFldDes[sseqRecordDLY5]->size = sizeof(prec->dly5);
    prt->papFldDes[sseqRecordDLY5]->offset = (unsigned short)((char *)&prec->dly5 - (char *)prec);
    prt->papFldDes[sseqRecordDOL5]->size = sizeof(prec->dol5);
    prt->papFldDes[sseqRecordDOL5]->offset = (unsigned short)((char *)&prec->dol5 - (char *)prec);
    prt->papFldDes[sseqRecordDO5]->size = sizeof(prec->do5);
    prt->papFldDes[sseqRecordDO5]->offset = (unsigned short)((char *)&prec->do5 - (char *)prec);
    prt->papFldDes[sseqRecordLNK5]->size = sizeof(prec->lnk5);
    prt->papFldDes[sseqRecordLNK5]->offset = (unsigned short)((char *)&prec->lnk5 - (char *)prec);
    prt->papFldDes[sseqRecordSTR5]->size = sizeof(prec->str5);
    prt->papFldDes[sseqRecordSTR5]->offset = (unsigned short)((char *)&prec->str5 - (char *)prec);
    prt->papFldDes[sseqRecordDT5]->size = sizeof(prec->dt5);
    prt->papFldDes[sseqRecordDT5]->offset = (unsigned short)((char *)&prec->dt5 - (char *)prec);
    prt->papFldDes[sseqRecordLT5]->size = sizeof(prec->lt5);
    prt->papFldDes[sseqRecordLT5]->offset = (unsigned short)((char *)&prec->lt5 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT5]->size = sizeof(prec->wait5);
    prt->papFldDes[sseqRecordWAIT5]->offset = (unsigned short)((char *)&prec->wait5 - (char *)prec);
    prt->papFldDes[sseqRecordWERR5]->size = sizeof(prec->werr5);
    prt->papFldDes[sseqRecordWERR5]->offset = (unsigned short)((char *)&prec->werr5 - (char *)prec);
    prt->papFldDes[sseqRecordWTG5]->size = sizeof(prec->wtg5);
    prt->papFldDes[sseqRecordWTG5]->offset = (unsigned short)((char *)&prec->wtg5 - (char *)prec);
    prt->papFldDes[sseqRecordIX5]->size = sizeof(prec->ix5);
    prt->papFldDes[sseqRecordIX5]->offset = (unsigned short)((char *)&prec->ix5 - (char *)prec);
    prt->papFldDes[sseqRecordDOL5V]->size = sizeof(prec->dol5v);
    prt->papFldDes[sseqRecordDOL5V]->offset = (unsigned short)((char *)&prec->dol5v - (char *)prec);
    prt->papFldDes[sseqRecordLNK5V]->size = sizeof(prec->lnk5v);
    prt->papFldDes[sseqRecordLNK5V]->offset = (unsigned short)((char *)&prec->lnk5v - (char *)prec);
    prt->papFldDes[sseqRecordDLY6]->size = sizeof(prec->dly6);
    prt->papFldDes[sseqRecordDLY6]->offset = (unsigned short)((char *)&prec->dly6 - (char *)prec);
    prt->papFldDes[sseqRecordDOL6]->size = sizeof(prec->dol6);
    prt->papFldDes[sseqRecordDOL6]->offset = (unsigned short)((char *)&prec->dol6 - (char *)prec);
    prt->papFldDes[sseqRecordDO6]->size = sizeof(prec->do6);
    prt->papFldDes[sseqRecordDO6]->offset = (unsigned short)((char *)&prec->do6 - (char *)prec);
    prt->papFldDes[sseqRecordLNK6]->size = sizeof(prec->lnk6);
    prt->papFldDes[sseqRecordLNK6]->offset = (unsigned short)((char *)&prec->lnk6 - (char *)prec);
    prt->papFldDes[sseqRecordSTR6]->size = sizeof(prec->str6);
    prt->papFldDes[sseqRecordSTR6]->offset = (unsigned short)((char *)&prec->str6 - (char *)prec);
    prt->papFldDes[sseqRecordDT6]->size = sizeof(prec->dt6);
    prt->papFldDes[sseqRecordDT6]->offset = (unsigned short)((char *)&prec->dt6 - (char *)prec);
    prt->papFldDes[sseqRecordLT6]->size = sizeof(prec->lt6);
    prt->papFldDes[sseqRecordLT6]->offset = (unsigned short)((char *)&prec->lt6 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT6]->size = sizeof(prec->wait6);
    prt->papFldDes[sseqRecordWAIT6]->offset = (unsigned short)((char *)&prec->wait6 - (char *)prec);
    prt->papFldDes[sseqRecordWERR6]->size = sizeof(prec->werr6);
    prt->papFldDes[sseqRecordWERR6]->offset = (unsigned short)((char *)&prec->werr6 - (char *)prec);
    prt->papFldDes[sseqRecordWTG6]->size = sizeof(prec->wtg6);
    prt->papFldDes[sseqRecordWTG6]->offset = (unsigned short)((char *)&prec->wtg6 - (char *)prec);
    prt->papFldDes[sseqRecordIX6]->size = sizeof(prec->ix6);
    prt->papFldDes[sseqRecordIX6]->offset = (unsigned short)((char *)&prec->ix6 - (char *)prec);
    prt->papFldDes[sseqRecordDOL6V]->size = sizeof(prec->dol6v);
    prt->papFldDes[sseqRecordDOL6V]->offset = (unsigned short)((char *)&prec->dol6v - (char *)prec);
    prt->papFldDes[sseqRecordLNK6V]->size = sizeof(prec->lnk6v);
    prt->papFldDes[sseqRecordLNK6V]->offset = (unsigned short)((char *)&prec->lnk6v - (char *)prec);
    prt->papFldDes[sseqRecordDLY7]->size = sizeof(prec->dly7);
    prt->papFldDes[sseqRecordDLY7]->offset = (unsigned short)((char *)&prec->dly7 - (char *)prec);
    prt->papFldDes[sseqRecordDOL7]->size = sizeof(prec->dol7);
    prt->papFldDes[sseqRecordDOL7]->offset = (unsigned short)((char *)&prec->dol7 - (char *)prec);
    prt->papFldDes[sseqRecordDO7]->size = sizeof(prec->do7);
    prt->papFldDes[sseqRecordDO7]->offset = (unsigned short)((char *)&prec->do7 - (char *)prec);
    prt->papFldDes[sseqRecordLNK7]->size = sizeof(prec->lnk7);
    prt->papFldDes[sseqRecordLNK7]->offset = (unsigned short)((char *)&prec->lnk7 - (char *)prec);
    prt->papFldDes[sseqRecordSTR7]->size = sizeof(prec->str7);
    prt->papFldDes[sseqRecordSTR7]->offset = (unsigned short)((char *)&prec->str7 - (char *)prec);
    prt->papFldDes[sseqRecordDT7]->size = sizeof(prec->dt7);
    prt->papFldDes[sseqRecordDT7]->offset = (unsigned short)((char *)&prec->dt7 - (char *)prec);
    prt->papFldDes[sseqRecordLT7]->size = sizeof(prec->lt7);
    prt->papFldDes[sseqRecordLT7]->offset = (unsigned short)((char *)&prec->lt7 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT7]->size = sizeof(prec->wait7);
    prt->papFldDes[sseqRecordWAIT7]->offset = (unsigned short)((char *)&prec->wait7 - (char *)prec);
    prt->papFldDes[sseqRecordWERR7]->size = sizeof(prec->werr7);
    prt->papFldDes[sseqRecordWERR7]->offset = (unsigned short)((char *)&prec->werr7 - (char *)prec);
    prt->papFldDes[sseqRecordWTG7]->size = sizeof(prec->wtg7);
    prt->papFldDes[sseqRecordWTG7]->offset = (unsigned short)((char *)&prec->wtg7 - (char *)prec);
    prt->papFldDes[sseqRecordIX7]->size = sizeof(prec->ix7);
    prt->papFldDes[sseqRecordIX7]->offset = (unsigned short)((char *)&prec->ix7 - (char *)prec);
    prt->papFldDes[sseqRecordDOL7V]->size = sizeof(prec->dol7v);
    prt->papFldDes[sseqRecordDOL7V]->offset = (unsigned short)((char *)&prec->dol7v - (char *)prec);
    prt->papFldDes[sseqRecordLNK7V]->size = sizeof(prec->lnk7v);
    prt->papFldDes[sseqRecordLNK7V]->offset = (unsigned short)((char *)&prec->lnk7v - (char *)prec);
    prt->papFldDes[sseqRecordDLY8]->size = sizeof(prec->dly8);
    prt->papFldDes[sseqRecordDLY8]->offset = (unsigned short)((char *)&prec->dly8 - (char *)prec);
    prt->papFldDes[sseqRecordDOL8]->size = sizeof(prec->dol8);
    prt->papFldDes[sseqRecordDOL8]->offset = (unsigned short)((char *)&prec->dol8 - (char *)prec);
    prt->papFldDes[sseqRecordDO8]->size = sizeof(prec->do8);
    prt->papFldDes[sseqRecordDO8]->offset = (unsigned short)((char *)&prec->do8 - (char *)prec);
    prt->papFldDes[sseqRecordLNK8]->size = sizeof(prec->lnk8);
    prt->papFldDes[sseqRecordLNK8]->offset = (unsigned short)((char *)&prec->lnk8 - (char *)prec);
    prt->papFldDes[sseqRecordSTR8]->size = sizeof(prec->str8);
    prt->papFldDes[sseqRecordSTR8]->offset = (unsigned short)((char *)&prec->str8 - (char *)prec);
    prt->papFldDes[sseqRecordDT8]->size = sizeof(prec->dt8);
    prt->papFldDes[sseqRecordDT8]->offset = (unsigned short)((char *)&prec->dt8 - (char *)prec);
    prt->papFldDes[sseqRecordLT8]->size = sizeof(prec->lt8);
    prt->papFldDes[sseqRecordLT8]->offset = (unsigned short)((char *)&prec->lt8 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT8]->size = sizeof(prec->wait8);
    prt->papFldDes[sseqRecordWAIT8]->offset = (unsigned short)((char *)&prec->wait8 - (char *)prec);
    prt->papFldDes[sseqRecordWERR8]->size = sizeof(prec->werr8);
    prt->papFldDes[sseqRecordWERR8]->offset = (unsigned short)((char *)&prec->werr8 - (char *)prec);
    prt->papFldDes[sseqRecordWTG8]->size = sizeof(prec->wtg8);
    prt->papFldDes[sseqRecordWTG8]->offset = (unsigned short)((char *)&prec->wtg8 - (char *)prec);
    prt->papFldDes[sseqRecordIX8]->size = sizeof(prec->ix8);
    prt->papFldDes[sseqRecordIX8]->offset = (unsigned short)((char *)&prec->ix8 - (char *)prec);
    prt->papFldDes[sseqRecordDOL8V]->size = sizeof(prec->dol8v);
    prt->papFldDes[sseqRecordDOL8V]->offset = (unsigned short)((char *)&prec->dol8v - (char *)prec);
    prt->papFldDes[sseqRecordLNK8V]->size = sizeof(prec->lnk8v);
    prt->papFldDes[sseqRecordLNK8V]->offset = (unsigned short)((char *)&prec->lnk8v - (char *)prec);
    prt->papFldDes[sseqRecordDLY9]->size = sizeof(prec->dly9);
    prt->papFldDes[sseqRecordDLY9]->offset = (unsigned short)((char *)&prec->dly9 - (char *)prec);
    prt->papFldDes[sseqRecordDOL9]->size = sizeof(prec->dol9);
    prt->papFldDes[sseqRecordDOL9]->offset = (unsigned short)((char *)&prec->dol9 - (char *)prec);
    prt->papFldDes[sseqRecordDO9]->size = sizeof(prec->do9);
    prt->papFldDes[sseqRecordDO9]->offset = (unsigned short)((char *)&prec->do9 - (char *)prec);
    prt->papFldDes[sseqRecordLNK9]->size = sizeof(prec->lnk9);
    prt->papFldDes[sseqRecordLNK9]->offset = (unsigned short)((char *)&prec->lnk9 - (char *)prec);
    prt->papFldDes[sseqRecordSTR9]->size = sizeof(prec->str9);
    prt->papFldDes[sseqRecordSTR9]->offset = (unsigned short)((char *)&prec->str9 - (char *)prec);
    prt->papFldDes[sseqRecordDT9]->size = sizeof(prec->dt9);
    prt->papFldDes[sseqRecordDT9]->offset = (unsigned short)((char *)&prec->dt9 - (char *)prec);
    prt->papFldDes[sseqRecordLT9]->size = sizeof(prec->lt9);
    prt->papFldDes[sseqRecordLT9]->offset = (unsigned short)((char *)&prec->lt9 - (char *)prec);
    prt->papFldDes[sseqRecordWAIT9]->size = sizeof(prec->wait9);
    prt->papFldDes[sseqRecordWAIT9]->offset = (unsigned short)((char *)&prec->wait9 - (char *)prec);
    prt->papFldDes[sseqRecordWERR9]->size = sizeof(prec->werr9);
    prt->papFldDes[sseqRecordWERR9]->offset = (unsigned short)((char *)&prec->werr9 - (char *)prec);
    prt->papFldDes[sseqRecordWTG9]->size = sizeof(prec->wtg9);
    prt->papFldDes[sseqRecordWTG9]->offset = (unsigned short)((char *)&prec->wtg9 - (char *)prec);
    prt->papFldDes[sseqRecordIX9]->size = sizeof(prec->ix9);
    prt->papFldDes[sseqRecordIX9]->offset = (unsigned short)((char *)&prec->ix9 - (char *)prec);
    prt->papFldDes[sseqRecordDOL9V]->size = sizeof(prec->dol9v);
    prt->papFldDes[sseqRecordDOL9V]->offset = (unsigned short)((char *)&prec->dol9v - (char *)prec);
    prt->papFldDes[sseqRecordLNK9V]->size = sizeof(prec->lnk9v);
    prt->papFldDes[sseqRecordLNK9V]->offset = (unsigned short)((char *)&prec->lnk9v - (char *)prec);
    prt->papFldDes[sseqRecordDLYA]->size = sizeof(prec->dlya);
    prt->papFldDes[sseqRecordDLYA]->offset = (unsigned short)((char *)&prec->dlya - (char *)prec);
    prt->papFldDes[sseqRecordDOLA]->size = sizeof(prec->dola);
    prt->papFldDes[sseqRecordDOLA]->offset = (unsigned short)((char *)&prec->dola - (char *)prec);
    prt->papFldDes[sseqRecordDOA]->size = sizeof(prec->doa);
    prt->papFldDes[sseqRecordDOA]->offset = (unsigned short)((char *)&prec->doa - (char *)prec);
    prt->papFldDes[sseqRecordLNKA]->size = sizeof(prec->lnka);
    prt->papFldDes[sseqRecordLNKA]->offset = (unsigned short)((char *)&prec->lnka - (char *)prec);
    prt->papFldDes[sseqRecordSTRA]->size = sizeof(prec->stra);
    prt->papFldDes[sseqRecordSTRA]->offset = (unsigned short)((char *)&prec->stra - (char *)prec);
    prt->papFldDes[sseqRecordDTA]->size = sizeof(prec->dta);
    prt->papFldDes[sseqRecordDTA]->offset = (unsigned short)((char *)&prec->dta - (char *)prec);
    prt->papFldDes[sseqRecordLTA]->size = sizeof(prec->lta);
    prt->papFldDes[sseqRecordLTA]->offset = (unsigned short)((char *)&prec->lta - (char *)prec);
    prt->papFldDes[sseqRecordWAITA]->size = sizeof(prec->waita);
    prt->papFldDes[sseqRecordWAITA]->offset = (unsigned short)((char *)&prec->waita - (char *)prec);
    prt->papFldDes[sseqRecordWERRA]->size = sizeof(prec->werra);
    prt->papFldDes[sseqRecordWERRA]->offset = (unsigned short)((char *)&prec->werra - (char *)prec);
    prt->papFldDes[sseqRecordWTGA]->size = sizeof(prec->wtga);
    prt->papFldDes[sseqRecordWTGA]->offset = (unsigned short)((char *)&prec->wtga - (char *)prec);
    prt->papFldDes[sseqRecordIXA]->size = sizeof(prec->ixa);
    prt->papFldDes[sseqRecordIXA]->offset = (unsigned short)((char *)&prec->ixa - (char *)prec);
    prt->papFldDes[sseqRecordDOLAV]->size = sizeof(prec->dolav);
    prt->papFldDes[sseqRecordDOLAV]->offset = (unsigned short)((char *)&prec->dolav - (char *)prec);
    prt->papFldDes[sseqRecordLNKAV]->size = sizeof(prec->lnkav);
    prt->papFldDes[sseqRecordLNKAV]->offset = (unsigned short)((char *)&prec->lnkav - (char *)prec);
    prt->papFldDes[sseqRecordABORT]->size = sizeof(prec->abort);
    prt->papFldDes[sseqRecordABORT]->offset = (unsigned short)((char *)&prec->abort - (char *)prec);
    prt->papFldDes[sseqRecordABORTING]->size = sizeof(prec->aborting);
    prt->papFldDes[sseqRecordABORTING]->offset = (unsigned short)((char *)&prec->aborting - (char *)prec);
    prt->papFldDes[sseqRecordBUSY]->size = sizeof(prec->busy);
    prt->papFldDes[sseqRecordBUSY]->offset = (unsigned short)((char *)&prec->busy - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(sseqRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_sseqRecord_H */
