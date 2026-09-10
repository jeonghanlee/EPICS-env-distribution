/** @file aCalcoutRecord.h
 * @brief Declarations for the @ref acalcoutRecord "acalcout" record type.
 *
 * This header was generated from aCalcoutRecord.dbd
 */

#ifndef INC_aCalcoutRecord_H
#define INC_aCalcoutRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef acalcoutINAV_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutINAV */
typedef enum {
    acalcoutINAV_EXT_NC             /**< @brief State string "Ext PV NC" */,
    acalcoutINAV_EXT                /**< @brief State string "Ext PV OK" */,
    acalcoutINAV_LOC                /**< @brief State string "Local PV" */,
    acalcoutINAV_CON                /**< @brief State string "Constant" */
} acalcoutINAV;
/** @brief Number of states defined for menu acalcoutINAV */
#define acalcoutINAV_NUM_CHOICES 4
#endif

#ifndef acalcoutOOPT_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutOOPT */
typedef enum {
    acalcoutOOPT_Every_Time         /**< @brief State string "Every Time" */,
    acalcoutOOPT_On_Change          /**< @brief State string "On Change" */,
    acalcoutOOPT_When_Zero          /**< @brief State string "When Zero" */,
    acalcoutOOPT_When_Non_zero      /**< @brief State string "When Non-zero" */,
    acalcoutOOPT_Transition_To_Zero /**< @brief State string "Transition To Zero" */,
    acalcoutOOPT_Transition_To_Non_zero /**< @brief State string "Transition To Non-zero" */,
    acalcoutOOPT_Never              /**< @brief State string "Never" */
} acalcoutOOPT;
/** @brief Number of states defined for menu acalcoutOOPT */
#define acalcoutOOPT_NUM_CHOICES 7
#endif

#ifndef acalcoutWAIT_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutWAIT */
typedef enum {
    acalcoutWAIT_NoWait             /**< @brief State string "NoWait" */,
    acalcoutWAIT_Wait               /**< @brief State string "Wait" */
} acalcoutWAIT;
/** @brief Number of states defined for menu acalcoutWAIT */
#define acalcoutWAIT_NUM_CHOICES 2
#endif

#ifndef acalcoutINAP_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutINAP */
typedef enum {
    acalcoutINAP_No                 /**< @brief State string "No PROC on Change" */,
    acalcoutINAP_Yes                /**< @brief State string "PROC on Change" */
} acalcoutINAP;
/** @brief Number of states defined for menu acalcoutINAP */
#define acalcoutINAP_NUM_CHOICES 2
#endif

#ifndef acalcoutSIZE_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutSIZE */
typedef enum {
    acalcoutSIZE_NELM               /**< @brief State string "NELM" */,
    acalcoutSIZE_NUSE               /**< @brief State string "NUSE" */
} acalcoutSIZE;
/** @brief Number of states defined for menu acalcoutSIZE */
#define acalcoutSIZE_NUM_CHOICES 2
#endif

#ifndef acalcoutDOPT_NUM_CHOICES
/** @brief Enumerated type from menu acalcoutDOPT */
typedef enum {
    acalcoutDOPT_Use_VAL            /**< @brief State string "Use CALC" */,
    acalcoutDOPT_Use_OVAL           /**< @brief State string "Use OCAL" */
} acalcoutDOPT;
/** @brief Number of states defined for menu acalcoutDOPT */
#define acalcoutDOPT_NUM_CHOICES 2
#endif

/** @brief Declaration of acalcout record type. */
typedef struct acalcoutRecord {
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
    epicsFloat64        vers;       /**< @brief Code Version */
    void *rpvt;                     /**< @brief Record Private */
    epicsFloat64        val;        /**< @brief Result */
    double *aval;                   /**< @brief Array Value */
    epicsUInt32         nelm;       /**< @brief Number of Elements */
    epicsUInt32         nuse;       /**< @brief # elem's in use */
    epicsFloat64        pval;       /**< @brief Previous Value */
    double *pavl;                   /**< @brief Prev. Array Value */
    char                calc[80];   /**< @brief Calculation */
    epicsInt32          clcv;       /**< @brief CALC Valid */
    DBLINK              inpa;       /**< @brief Input A */
    DBLINK              inpb;       /**< @brief Input B */
    DBLINK              inpc;       /**< @brief Input C */
    DBLINK              inpd;       /**< @brief Input D */
    DBLINK              inpe;       /**< @brief Input E */
    DBLINK              inpf;       /**< @brief Input F */
    DBLINK              inpg;       /**< @brief Input G */
    DBLINK              inph;       /**< @brief Input H */
    DBLINK              inpi;       /**< @brief Input I */
    DBLINK              inpj;       /**< @brief Input J */
    DBLINK              inpk;       /**< @brief Input K */
    DBLINK              inpl;       /**< @brief Input L */
    DBLINK              inaa;       /**< @brief Array input AA */
    DBLINK              inbb;       /**< @brief Array input BB */
    DBLINK              incc;       /**< @brief Array input CC */
    DBLINK              indd;       /**< @brief Array input DD */
    DBLINK              inee;       /**< @brief Array input EE */
    DBLINK              inff;       /**< @brief Array input FF */
    DBLINK              ingg;       /**< @brief Array input GG */
    DBLINK              inhh;       /**< @brief Array input HH */
    DBLINK              inii;       /**< @brief Array input II */
    DBLINK              injj;       /**< @brief Array input JJ */
    DBLINK              inkk;       /**< @brief Array input KK */
    DBLINK              inll;       /**< @brief Array input LL */
    DBLINK              out;        /**< @brief Output Link */
    epicsEnum16         inav;       /**< @brief INPA PV Status */
    epicsEnum16         inbv;       /**< @brief INPB PV Status */
    epicsEnum16         incv;       /**< @brief INPC PV Status */
    epicsEnum16         indv;       /**< @brief INPD PV Status */
    epicsEnum16         inev;       /**< @brief INPE PV Status */
    epicsEnum16         infv;       /**< @brief INPF PV Status */
    epicsEnum16         ingv;       /**< @brief INPG PV Status */
    epicsEnum16         inhv;       /**< @brief INPH PV Status */
    epicsEnum16         iniv;       /**< @brief INPI PV Status */
    epicsEnum16         injv;       /**< @brief INPJ PV Status */
    epicsEnum16         inkv;       /**< @brief INPK PV Status */
    epicsEnum16         inlv;       /**< @brief INPL PV Status */
    epicsEnum16         iaav;       /**< @brief INAA PV Status */
    epicsEnum16         ibbv;       /**< @brief INBB PV Status */
    epicsEnum16         iccv;       /**< @brief INCC PV Status */
    epicsEnum16         iddv;       /**< @brief INDD PV Status */
    epicsEnum16         ieev;       /**< @brief INEE PV Status */
    epicsEnum16         iffv;       /**< @brief INFF PV Status */
    epicsEnum16         iggv;       /**< @brief INGG PV Status */
    epicsEnum16         ihhv;       /**< @brief INHH PV Status */
    epicsEnum16         iiiv;       /**< @brief INII PV Status */
    epicsEnum16         ijjv;       /**< @brief INJJ PV Status */
    epicsEnum16         ikkv;       /**< @brief INKK PV Status */
    epicsEnum16         illv;       /**< @brief INLL PV Status */
    epicsEnum16         outv;       /**< @brief OUT PV Status */
    epicsEnum16         oopt;       /**< @brief Output Execute Opt */
    epicsFloat64        odly;       /**< @brief Output Execute Delay */
    epicsEnum16         wait;       /**< @brief Wait for completion? */
    epicsUInt16         dlya;       /**< @brief Output Delay Active */
    epicsEnum16         dopt;       /**< @brief Output Data Opt */
    char                ocal[80];   /**< @brief Output Calculation */
    epicsInt32          oclv;       /**< @brief OCAL Valid */
    epicsUInt16         oevt;       /**< @brief Event To Issue */
    epicsEnum16         ivoa;       /**< @brief INVALID output action */
    epicsFloat64        ivov;       /**< @brief INVALID output value */
    char                egu[16];    /**< @brief Units Name */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsFloat64        hopr;       /**< @brief High Operating Rng */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsFloat64        hihi;       /**< @brief Hihi Alarm Limit */
    epicsFloat64        lolo;       /**< @brief Lolo Alarm Limit */
    epicsFloat64        high;       /**< @brief High Alarm Limit */
    epicsFloat64        low;        /**< @brief Low Alarm Limit */
    epicsEnum16         hhsv;       /**< @brief Hihi Severity */
    epicsEnum16         llsv;       /**< @brief Lolo Severity */
    epicsEnum16         hsv;        /**< @brief High Severity */
    epicsEnum16         lsv;        /**< @brief Low Severity */
    epicsFloat64        hyst;       /**< @brief Alarm Deadband */
    epicsFloat64        adel;       /**< @brief Archive Deadband */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsFloat64        a;          /**< @brief Value of Input A */
    epicsFloat64        b;          /**< @brief Value of Input B */
    epicsFloat64        c;          /**< @brief Value of Input C */
    epicsFloat64        d;          /**< @brief Value of Input D */
    epicsFloat64        e;          /**< @brief Value of Input E */
    epicsFloat64        f;          /**< @brief Value of Input F */
    epicsFloat64        g;          /**< @brief Value of Input G */
    epicsFloat64        h;          /**< @brief Value of Input H */
    epicsFloat64        i;          /**< @brief Value of Input I */
    epicsFloat64        j;          /**< @brief Value of Input J */
    epicsFloat64        k;          /**< @brief Value of Input K */
    epicsFloat64        l;          /**< @brief Value of Input L */
    double *aa;                     /**< @brief Value of array input */
    double *bb;                     /**< @brief Value of array input */
    double *cc;                     /**< @brief Value of array input */
    double *dd;                     /**< @brief Value of array input */
    double *ee;                     /**< @brief Value of array input */
    double *ff;                     /**< @brief Value of array input */
    double *gg;                     /**< @brief Value of array input */
    double *hh;                     /**< @brief Value of array input */
    double *ii;                     /**< @brief Value of array input */
    double *jj;                     /**< @brief Value of array input */
    double *kk;                     /**< @brief Value of array input */
    double *ll;                     /**< @brief Value of array input */
    double *paa;                    /**< @brief Prev Val of array input */
    epicsUInt32         newm;       /**< @brief new array value mask */
    epicsFloat64        oval;       /**< @brief Output Value */
    double *oav;                    /**< @brief Output array value */
    double *poav;                   /**< @brief Output array value */
    epicsFloat64        pa;         /**< @brief Prev Value of A */
    epicsFloat64        pb;         /**< @brief Prev Value of B */
    epicsFloat64        pc;         /**< @brief Prev Value of C */
    epicsFloat64        pd;         /**< @brief Prev Value of D */
    epicsFloat64        pe;         /**< @brief Prev Value of E */
    epicsFloat64        pf;         /**< @brief Prev Value of F */
    epicsFloat64        pg;         /**< @brief Prev Value of G */
    epicsFloat64        ph;         /**< @brief Prev Value of H */
    epicsFloat64        pi;         /**< @brief Prev Value of I */
    epicsFloat64        pj;         /**< @brief Prev Value of J */
    epicsFloat64        pk;         /**< @brief Prev Value of K */
    epicsFloat64        pl;         /**< @brief Prev Value of L */
    epicsFloat64        povl;       /**< @brief Prev Value of OVAL */
    epicsFloat64        lalm;       /**< @brief Last Value Alarmed */
    epicsFloat64        alst;       /**< @brief Last Value Archived */
    epicsFloat64        mlst;       /**< @brief Last Val Monitored */
    unsigned char rpcl[282];        /**< @brief Reverse Polish Calc */
    unsigned char orpc[282];        /**< @brief Reverse Polish OCalc */
    epicsUInt8          cact;       /**< @brief Calc active */
    epicsInt32          cstat;      /**< @brief Calc status */
    epicsUInt32         amask;      /**< @brief Array mod */
    epicsEnum16         size;       /**< @brief Array size reported to clients */
    epicsInt32          amem;       /**< @brief Allocated array memory */
    epicsInt32          pmem;       /**< @brief Prev array memory */
} acalcoutRecord;

typedef enum {
	acalcoutRecordNAME = 0,
	acalcoutRecordDESC = 1,
	acalcoutRecordASG = 2,
	acalcoutRecordSCAN = 3,
	acalcoutRecordPINI = 4,
	acalcoutRecordPHAS = 5,
	acalcoutRecordEVNT = 6,
	acalcoutRecordTSE = 7,
	acalcoutRecordTSEL = 8,
	acalcoutRecordDTYP = 9,
	acalcoutRecordDISV = 10,
	acalcoutRecordDISA = 11,
	acalcoutRecordSDIS = 12,
	acalcoutRecordMLOK = 13,
	acalcoutRecordMLIS = 14,
	acalcoutRecordBKLNK = 15,
	acalcoutRecordDISP = 16,
	acalcoutRecordPROC = 17,
	acalcoutRecordSTAT = 18,
	acalcoutRecordSEVR = 19,
	acalcoutRecordAMSG = 20,
	acalcoutRecordNSTA = 21,
	acalcoutRecordNSEV = 22,
	acalcoutRecordNAMSG = 23,
	acalcoutRecordACKS = 24,
	acalcoutRecordACKT = 25,
	acalcoutRecordDISS = 26,
	acalcoutRecordLCNT = 27,
	acalcoutRecordPACT = 28,
	acalcoutRecordPUTF = 29,
	acalcoutRecordRPRO = 30,
	acalcoutRecordASP = 31,
	acalcoutRecordPPN = 32,
	acalcoutRecordPPNR = 33,
	acalcoutRecordSPVT = 34,
	acalcoutRecordRSET = 35,
	acalcoutRecordDSET = 36,
	acalcoutRecordDPVT = 37,
	acalcoutRecordRDES = 38,
	acalcoutRecordLSET = 39,
	acalcoutRecordPRIO = 40,
	acalcoutRecordTPRO = 41,
	acalcoutRecordBKPT = 42,
	acalcoutRecordUDF = 43,
	acalcoutRecordUDFS = 44,
	acalcoutRecordTIME = 45,
	acalcoutRecordUTAG = 46,
	acalcoutRecordFLNK = 47,
	acalcoutRecordVERS = 48,
	acalcoutRecordRPVT = 49,
	acalcoutRecordVAL = 50,
	acalcoutRecordAVAL = 51,
	acalcoutRecordNELM = 52,
	acalcoutRecordNUSE = 53,
	acalcoutRecordPVAL = 54,
	acalcoutRecordPAVL = 55,
	acalcoutRecordCALC = 56,
	acalcoutRecordCLCV = 57,
	acalcoutRecordINPA = 58,
	acalcoutRecordINPB = 59,
	acalcoutRecordINPC = 60,
	acalcoutRecordINPD = 61,
	acalcoutRecordINPE = 62,
	acalcoutRecordINPF = 63,
	acalcoutRecordINPG = 64,
	acalcoutRecordINPH = 65,
	acalcoutRecordINPI = 66,
	acalcoutRecordINPJ = 67,
	acalcoutRecordINPK = 68,
	acalcoutRecordINPL = 69,
	acalcoutRecordINAA = 70,
	acalcoutRecordINBB = 71,
	acalcoutRecordINCC = 72,
	acalcoutRecordINDD = 73,
	acalcoutRecordINEE = 74,
	acalcoutRecordINFF = 75,
	acalcoutRecordINGG = 76,
	acalcoutRecordINHH = 77,
	acalcoutRecordINII = 78,
	acalcoutRecordINJJ = 79,
	acalcoutRecordINKK = 80,
	acalcoutRecordINLL = 81,
	acalcoutRecordOUT = 82,
	acalcoutRecordINAV = 83,
	acalcoutRecordINBV = 84,
	acalcoutRecordINCV = 85,
	acalcoutRecordINDV = 86,
	acalcoutRecordINEV = 87,
	acalcoutRecordINFV = 88,
	acalcoutRecordINGV = 89,
	acalcoutRecordINHV = 90,
	acalcoutRecordINIV = 91,
	acalcoutRecordINJV = 92,
	acalcoutRecordINKV = 93,
	acalcoutRecordINLV = 94,
	acalcoutRecordIAAV = 95,
	acalcoutRecordIBBV = 96,
	acalcoutRecordICCV = 97,
	acalcoutRecordIDDV = 98,
	acalcoutRecordIEEV = 99,
	acalcoutRecordIFFV = 100,
	acalcoutRecordIGGV = 101,
	acalcoutRecordIHHV = 102,
	acalcoutRecordIIIV = 103,
	acalcoutRecordIJJV = 104,
	acalcoutRecordIKKV = 105,
	acalcoutRecordILLV = 106,
	acalcoutRecordOUTV = 107,
	acalcoutRecordOOPT = 108,
	acalcoutRecordODLY = 109,
	acalcoutRecordWAIT = 110,
	acalcoutRecordDLYA = 111,
	acalcoutRecordDOPT = 112,
	acalcoutRecordOCAL = 113,
	acalcoutRecordOCLV = 114,
	acalcoutRecordOEVT = 115,
	acalcoutRecordIVOA = 116,
	acalcoutRecordIVOV = 117,
	acalcoutRecordEGU = 118,
	acalcoutRecordPREC = 119,
	acalcoutRecordHOPR = 120,
	acalcoutRecordLOPR = 121,
	acalcoutRecordHIHI = 122,
	acalcoutRecordLOLO = 123,
	acalcoutRecordHIGH = 124,
	acalcoutRecordLOW = 125,
	acalcoutRecordHHSV = 126,
	acalcoutRecordLLSV = 127,
	acalcoutRecordHSV = 128,
	acalcoutRecordLSV = 129,
	acalcoutRecordHYST = 130,
	acalcoutRecordADEL = 131,
	acalcoutRecordMDEL = 132,
	acalcoutRecordA = 133,
	acalcoutRecordB = 134,
	acalcoutRecordC = 135,
	acalcoutRecordD = 136,
	acalcoutRecordE = 137,
	acalcoutRecordF = 138,
	acalcoutRecordG = 139,
	acalcoutRecordH = 140,
	acalcoutRecordI = 141,
	acalcoutRecordJ = 142,
	acalcoutRecordK = 143,
	acalcoutRecordL = 144,
	acalcoutRecordAA = 145,
	acalcoutRecordBB = 146,
	acalcoutRecordCC = 147,
	acalcoutRecordDD = 148,
	acalcoutRecordEE = 149,
	acalcoutRecordFF = 150,
	acalcoutRecordGG = 151,
	acalcoutRecordHH = 152,
	acalcoutRecordII = 153,
	acalcoutRecordJJ = 154,
	acalcoutRecordKK = 155,
	acalcoutRecordLL = 156,
	acalcoutRecordPAA = 157,
	acalcoutRecordNEWM = 158,
	acalcoutRecordOVAL = 159,
	acalcoutRecordOAV = 160,
	acalcoutRecordPOAV = 161,
	acalcoutRecordPA = 162,
	acalcoutRecordPB = 163,
	acalcoutRecordPC = 164,
	acalcoutRecordPD = 165,
	acalcoutRecordPE = 166,
	acalcoutRecordPF = 167,
	acalcoutRecordPG = 168,
	acalcoutRecordPH = 169,
	acalcoutRecordPI = 170,
	acalcoutRecordPJ = 171,
	acalcoutRecordPK = 172,
	acalcoutRecordPL = 173,
	acalcoutRecordPOVL = 174,
	acalcoutRecordLALM = 175,
	acalcoutRecordALST = 176,
	acalcoutRecordMLST = 177,
	acalcoutRecordRPCL = 178,
	acalcoutRecordORPC = 179,
	acalcoutRecordCACT = 180,
	acalcoutRecordCSTAT = 181,
	acalcoutRecordAMASK = 182,
	acalcoutRecordSIZE = 183,
	acalcoutRecordAMEM = 184,
	acalcoutRecordPMEM = 185
} acalcoutFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int acalcoutRecordSizeOffset(dbRecordType *prt)
{
    acalcoutRecord *prec = 0;

    if (prt->no_fields != 186) {
        cantProceed("IOC build or installation error:\n"
            "    The acalcoutRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 186.\n",
            prt->no_fields);
    }
    prt->papFldDes[acalcoutRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[acalcoutRecordNAME]->offset = (unsigned short)offsetof(acalcoutRecord, name);
    prt->papFldDes[acalcoutRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[acalcoutRecordDESC]->offset = (unsigned short)offsetof(acalcoutRecord, desc);
    prt->papFldDes[acalcoutRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[acalcoutRecordASG]->offset = (unsigned short)offsetof(acalcoutRecord, asg);
    prt->papFldDes[acalcoutRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[acalcoutRecordSCAN]->offset = (unsigned short)offsetof(acalcoutRecord, scan);
    prt->papFldDes[acalcoutRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[acalcoutRecordPINI]->offset = (unsigned short)offsetof(acalcoutRecord, pini);
    prt->papFldDes[acalcoutRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[acalcoutRecordPHAS]->offset = (unsigned short)offsetof(acalcoutRecord, phas);
    prt->papFldDes[acalcoutRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[acalcoutRecordEVNT]->offset = (unsigned short)offsetof(acalcoutRecord, evnt);
    prt->papFldDes[acalcoutRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[acalcoutRecordTSE]->offset = (unsigned short)offsetof(acalcoutRecord, tse);
    prt->papFldDes[acalcoutRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[acalcoutRecordTSEL]->offset = (unsigned short)offsetof(acalcoutRecord, tsel);
    prt->papFldDes[acalcoutRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[acalcoutRecordDTYP]->offset = (unsigned short)offsetof(acalcoutRecord, dtyp);
    prt->papFldDes[acalcoutRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[acalcoutRecordDISV]->offset = (unsigned short)offsetof(acalcoutRecord, disv);
    prt->papFldDes[acalcoutRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[acalcoutRecordDISA]->offset = (unsigned short)offsetof(acalcoutRecord, disa);
    prt->papFldDes[acalcoutRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[acalcoutRecordSDIS]->offset = (unsigned short)offsetof(acalcoutRecord, sdis);
    prt->papFldDes[acalcoutRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[acalcoutRecordMLOK]->offset = (unsigned short)offsetof(acalcoutRecord, mlok);
    prt->papFldDes[acalcoutRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[acalcoutRecordMLIS]->offset = (unsigned short)offsetof(acalcoutRecord, mlis);
    prt->papFldDes[acalcoutRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[acalcoutRecordBKLNK]->offset = (unsigned short)offsetof(acalcoutRecord, bklnk);
    prt->papFldDes[acalcoutRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[acalcoutRecordDISP]->offset = (unsigned short)offsetof(acalcoutRecord, disp);
    prt->papFldDes[acalcoutRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[acalcoutRecordPROC]->offset = (unsigned short)offsetof(acalcoutRecord, proc);
    prt->papFldDes[acalcoutRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[acalcoutRecordSTAT]->offset = (unsigned short)offsetof(acalcoutRecord, stat);
    prt->papFldDes[acalcoutRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[acalcoutRecordSEVR]->offset = (unsigned short)offsetof(acalcoutRecord, sevr);
    prt->papFldDes[acalcoutRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[acalcoutRecordAMSG]->offset = (unsigned short)offsetof(acalcoutRecord, amsg);
    prt->papFldDes[acalcoutRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[acalcoutRecordNSTA]->offset = (unsigned short)offsetof(acalcoutRecord, nsta);
    prt->papFldDes[acalcoutRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[acalcoutRecordNSEV]->offset = (unsigned short)offsetof(acalcoutRecord, nsev);
    prt->papFldDes[acalcoutRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[acalcoutRecordNAMSG]->offset = (unsigned short)offsetof(acalcoutRecord, namsg);
    prt->papFldDes[acalcoutRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[acalcoutRecordACKS]->offset = (unsigned short)offsetof(acalcoutRecord, acks);
    prt->papFldDes[acalcoutRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[acalcoutRecordACKT]->offset = (unsigned short)offsetof(acalcoutRecord, ackt);
    prt->papFldDes[acalcoutRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[acalcoutRecordDISS]->offset = (unsigned short)offsetof(acalcoutRecord, diss);
    prt->papFldDes[acalcoutRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[acalcoutRecordLCNT]->offset = (unsigned short)offsetof(acalcoutRecord, lcnt);
    prt->papFldDes[acalcoutRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[acalcoutRecordPACT]->offset = (unsigned short)offsetof(acalcoutRecord, pact);
    prt->papFldDes[acalcoutRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[acalcoutRecordPUTF]->offset = (unsigned short)offsetof(acalcoutRecord, putf);
    prt->papFldDes[acalcoutRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[acalcoutRecordRPRO]->offset = (unsigned short)offsetof(acalcoutRecord, rpro);
    prt->papFldDes[acalcoutRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[acalcoutRecordASP]->offset = (unsigned short)offsetof(acalcoutRecord, asp);
    prt->papFldDes[acalcoutRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[acalcoutRecordPPN]->offset = (unsigned short)offsetof(acalcoutRecord, ppn);
    prt->papFldDes[acalcoutRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[acalcoutRecordPPNR]->offset = (unsigned short)offsetof(acalcoutRecord, ppnr);
    prt->papFldDes[acalcoutRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[acalcoutRecordSPVT]->offset = (unsigned short)offsetof(acalcoutRecord, spvt);
    prt->papFldDes[acalcoutRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[acalcoutRecordRSET]->offset = (unsigned short)offsetof(acalcoutRecord, rset);
    prt->papFldDes[acalcoutRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[acalcoutRecordDSET]->offset = (unsigned short)offsetof(acalcoutRecord, dset);
    prt->papFldDes[acalcoutRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[acalcoutRecordDPVT]->offset = (unsigned short)offsetof(acalcoutRecord, dpvt);
    prt->papFldDes[acalcoutRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[acalcoutRecordRDES]->offset = (unsigned short)offsetof(acalcoutRecord, rdes);
    prt->papFldDes[acalcoutRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[acalcoutRecordLSET]->offset = (unsigned short)offsetof(acalcoutRecord, lset);
    prt->papFldDes[acalcoutRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[acalcoutRecordPRIO]->offset = (unsigned short)offsetof(acalcoutRecord, prio);
    prt->papFldDes[acalcoutRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[acalcoutRecordTPRO]->offset = (unsigned short)offsetof(acalcoutRecord, tpro);
    prt->papFldDes[acalcoutRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[acalcoutRecordBKPT]->offset = (unsigned short)offsetof(acalcoutRecord, bkpt);
    prt->papFldDes[acalcoutRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[acalcoutRecordUDF]->offset = (unsigned short)offsetof(acalcoutRecord, udf);
    prt->papFldDes[acalcoutRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[acalcoutRecordUDFS]->offset = (unsigned short)offsetof(acalcoutRecord, udfs);
    prt->papFldDes[acalcoutRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[acalcoutRecordTIME]->offset = (unsigned short)offsetof(acalcoutRecord, time);
    prt->papFldDes[acalcoutRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[acalcoutRecordUTAG]->offset = (unsigned short)offsetof(acalcoutRecord, utag);
    prt->papFldDes[acalcoutRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[acalcoutRecordFLNK]->offset = (unsigned short)offsetof(acalcoutRecord, flnk);
    prt->papFldDes[acalcoutRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[acalcoutRecordVERS]->offset = (unsigned short)offsetof(acalcoutRecord, vers);
    prt->papFldDes[acalcoutRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[acalcoutRecordRPVT]->offset = (unsigned short)offsetof(acalcoutRecord, rpvt);
    prt->papFldDes[acalcoutRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[acalcoutRecordVAL]->offset = (unsigned short)offsetof(acalcoutRecord, val);
    prt->papFldDes[acalcoutRecordAVAL]->size = sizeof(prec->aval);
    prt->papFldDes[acalcoutRecordAVAL]->offset = (unsigned short)offsetof(acalcoutRecord, aval);
    prt->papFldDes[acalcoutRecordNELM]->size = sizeof(prec->nelm);
    prt->papFldDes[acalcoutRecordNELM]->offset = (unsigned short)offsetof(acalcoutRecord, nelm);
    prt->papFldDes[acalcoutRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[acalcoutRecordNUSE]->offset = (unsigned short)offsetof(acalcoutRecord, nuse);
    prt->papFldDes[acalcoutRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[acalcoutRecordPVAL]->offset = (unsigned short)offsetof(acalcoutRecord, pval);
    prt->papFldDes[acalcoutRecordPAVL]->size = sizeof(prec->pavl);
    prt->papFldDes[acalcoutRecordPAVL]->offset = (unsigned short)offsetof(acalcoutRecord, pavl);
    prt->papFldDes[acalcoutRecordCALC]->size = sizeof(prec->calc);
    prt->papFldDes[acalcoutRecordCALC]->offset = (unsigned short)offsetof(acalcoutRecord, calc);
    prt->papFldDes[acalcoutRecordCLCV]->size = sizeof(prec->clcv);
    prt->papFldDes[acalcoutRecordCLCV]->offset = (unsigned short)offsetof(acalcoutRecord, clcv);
    prt->papFldDes[acalcoutRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[acalcoutRecordINPA]->offset = (unsigned short)offsetof(acalcoutRecord, inpa);
    prt->papFldDes[acalcoutRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[acalcoutRecordINPB]->offset = (unsigned short)offsetof(acalcoutRecord, inpb);
    prt->papFldDes[acalcoutRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[acalcoutRecordINPC]->offset = (unsigned short)offsetof(acalcoutRecord, inpc);
    prt->papFldDes[acalcoutRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[acalcoutRecordINPD]->offset = (unsigned short)offsetof(acalcoutRecord, inpd);
    prt->papFldDes[acalcoutRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[acalcoutRecordINPE]->offset = (unsigned short)offsetof(acalcoutRecord, inpe);
    prt->papFldDes[acalcoutRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[acalcoutRecordINPF]->offset = (unsigned short)offsetof(acalcoutRecord, inpf);
    prt->papFldDes[acalcoutRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[acalcoutRecordINPG]->offset = (unsigned short)offsetof(acalcoutRecord, inpg);
    prt->papFldDes[acalcoutRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[acalcoutRecordINPH]->offset = (unsigned short)offsetof(acalcoutRecord, inph);
    prt->papFldDes[acalcoutRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[acalcoutRecordINPI]->offset = (unsigned short)offsetof(acalcoutRecord, inpi);
    prt->papFldDes[acalcoutRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[acalcoutRecordINPJ]->offset = (unsigned short)offsetof(acalcoutRecord, inpj);
    prt->papFldDes[acalcoutRecordINPK]->size = sizeof(prec->inpk);
    prt->papFldDes[acalcoutRecordINPK]->offset = (unsigned short)offsetof(acalcoutRecord, inpk);
    prt->papFldDes[acalcoutRecordINPL]->size = sizeof(prec->inpl);
    prt->papFldDes[acalcoutRecordINPL]->offset = (unsigned short)offsetof(acalcoutRecord, inpl);
    prt->papFldDes[acalcoutRecordINAA]->size = sizeof(prec->inaa);
    prt->papFldDes[acalcoutRecordINAA]->offset = (unsigned short)offsetof(acalcoutRecord, inaa);
    prt->papFldDes[acalcoutRecordINBB]->size = sizeof(prec->inbb);
    prt->papFldDes[acalcoutRecordINBB]->offset = (unsigned short)offsetof(acalcoutRecord, inbb);
    prt->papFldDes[acalcoutRecordINCC]->size = sizeof(prec->incc);
    prt->papFldDes[acalcoutRecordINCC]->offset = (unsigned short)offsetof(acalcoutRecord, incc);
    prt->papFldDes[acalcoutRecordINDD]->size = sizeof(prec->indd);
    prt->papFldDes[acalcoutRecordINDD]->offset = (unsigned short)offsetof(acalcoutRecord, indd);
    prt->papFldDes[acalcoutRecordINEE]->size = sizeof(prec->inee);
    prt->papFldDes[acalcoutRecordINEE]->offset = (unsigned short)offsetof(acalcoutRecord, inee);
    prt->papFldDes[acalcoutRecordINFF]->size = sizeof(prec->inff);
    prt->papFldDes[acalcoutRecordINFF]->offset = (unsigned short)offsetof(acalcoutRecord, inff);
    prt->papFldDes[acalcoutRecordINGG]->size = sizeof(prec->ingg);
    prt->papFldDes[acalcoutRecordINGG]->offset = (unsigned short)offsetof(acalcoutRecord, ingg);
    prt->papFldDes[acalcoutRecordINHH]->size = sizeof(prec->inhh);
    prt->papFldDes[acalcoutRecordINHH]->offset = (unsigned short)offsetof(acalcoutRecord, inhh);
    prt->papFldDes[acalcoutRecordINII]->size = sizeof(prec->inii);
    prt->papFldDes[acalcoutRecordINII]->offset = (unsigned short)offsetof(acalcoutRecord, inii);
    prt->papFldDes[acalcoutRecordINJJ]->size = sizeof(prec->injj);
    prt->papFldDes[acalcoutRecordINJJ]->offset = (unsigned short)offsetof(acalcoutRecord, injj);
    prt->papFldDes[acalcoutRecordINKK]->size = sizeof(prec->inkk);
    prt->papFldDes[acalcoutRecordINKK]->offset = (unsigned short)offsetof(acalcoutRecord, inkk);
    prt->papFldDes[acalcoutRecordINLL]->size = sizeof(prec->inll);
    prt->papFldDes[acalcoutRecordINLL]->offset = (unsigned short)offsetof(acalcoutRecord, inll);
    prt->papFldDes[acalcoutRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[acalcoutRecordOUT]->offset = (unsigned short)offsetof(acalcoutRecord, out);
    prt->papFldDes[acalcoutRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[acalcoutRecordINAV]->offset = (unsigned short)offsetof(acalcoutRecord, inav);
    prt->papFldDes[acalcoutRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[acalcoutRecordINBV]->offset = (unsigned short)offsetof(acalcoutRecord, inbv);
    prt->papFldDes[acalcoutRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[acalcoutRecordINCV]->offset = (unsigned short)offsetof(acalcoutRecord, incv);
    prt->papFldDes[acalcoutRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[acalcoutRecordINDV]->offset = (unsigned short)offsetof(acalcoutRecord, indv);
    prt->papFldDes[acalcoutRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[acalcoutRecordINEV]->offset = (unsigned short)offsetof(acalcoutRecord, inev);
    prt->papFldDes[acalcoutRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[acalcoutRecordINFV]->offset = (unsigned short)offsetof(acalcoutRecord, infv);
    prt->papFldDes[acalcoutRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[acalcoutRecordINGV]->offset = (unsigned short)offsetof(acalcoutRecord, ingv);
    prt->papFldDes[acalcoutRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[acalcoutRecordINHV]->offset = (unsigned short)offsetof(acalcoutRecord, inhv);
    prt->papFldDes[acalcoutRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[acalcoutRecordINIV]->offset = (unsigned short)offsetof(acalcoutRecord, iniv);
    prt->papFldDes[acalcoutRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[acalcoutRecordINJV]->offset = (unsigned short)offsetof(acalcoutRecord, injv);
    prt->papFldDes[acalcoutRecordINKV]->size = sizeof(prec->inkv);
    prt->papFldDes[acalcoutRecordINKV]->offset = (unsigned short)offsetof(acalcoutRecord, inkv);
    prt->papFldDes[acalcoutRecordINLV]->size = sizeof(prec->inlv);
    prt->papFldDes[acalcoutRecordINLV]->offset = (unsigned short)offsetof(acalcoutRecord, inlv);
    prt->papFldDes[acalcoutRecordIAAV]->size = sizeof(prec->iaav);
    prt->papFldDes[acalcoutRecordIAAV]->offset = (unsigned short)offsetof(acalcoutRecord, iaav);
    prt->papFldDes[acalcoutRecordIBBV]->size = sizeof(prec->ibbv);
    prt->papFldDes[acalcoutRecordIBBV]->offset = (unsigned short)offsetof(acalcoutRecord, ibbv);
    prt->papFldDes[acalcoutRecordICCV]->size = sizeof(prec->iccv);
    prt->papFldDes[acalcoutRecordICCV]->offset = (unsigned short)offsetof(acalcoutRecord, iccv);
    prt->papFldDes[acalcoutRecordIDDV]->size = sizeof(prec->iddv);
    prt->papFldDes[acalcoutRecordIDDV]->offset = (unsigned short)offsetof(acalcoutRecord, iddv);
    prt->papFldDes[acalcoutRecordIEEV]->size = sizeof(prec->ieev);
    prt->papFldDes[acalcoutRecordIEEV]->offset = (unsigned short)offsetof(acalcoutRecord, ieev);
    prt->papFldDes[acalcoutRecordIFFV]->size = sizeof(prec->iffv);
    prt->papFldDes[acalcoutRecordIFFV]->offset = (unsigned short)offsetof(acalcoutRecord, iffv);
    prt->papFldDes[acalcoutRecordIGGV]->size = sizeof(prec->iggv);
    prt->papFldDes[acalcoutRecordIGGV]->offset = (unsigned short)offsetof(acalcoutRecord, iggv);
    prt->papFldDes[acalcoutRecordIHHV]->size = sizeof(prec->ihhv);
    prt->papFldDes[acalcoutRecordIHHV]->offset = (unsigned short)offsetof(acalcoutRecord, ihhv);
    prt->papFldDes[acalcoutRecordIIIV]->size = sizeof(prec->iiiv);
    prt->papFldDes[acalcoutRecordIIIV]->offset = (unsigned short)offsetof(acalcoutRecord, iiiv);
    prt->papFldDes[acalcoutRecordIJJV]->size = sizeof(prec->ijjv);
    prt->papFldDes[acalcoutRecordIJJV]->offset = (unsigned short)offsetof(acalcoutRecord, ijjv);
    prt->papFldDes[acalcoutRecordIKKV]->size = sizeof(prec->ikkv);
    prt->papFldDes[acalcoutRecordIKKV]->offset = (unsigned short)offsetof(acalcoutRecord, ikkv);
    prt->papFldDes[acalcoutRecordILLV]->size = sizeof(prec->illv);
    prt->papFldDes[acalcoutRecordILLV]->offset = (unsigned short)offsetof(acalcoutRecord, illv);
    prt->papFldDes[acalcoutRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[acalcoutRecordOUTV]->offset = (unsigned short)offsetof(acalcoutRecord, outv);
    prt->papFldDes[acalcoutRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[acalcoutRecordOOPT]->offset = (unsigned short)offsetof(acalcoutRecord, oopt);
    prt->papFldDes[acalcoutRecordODLY]->size = sizeof(prec->odly);
    prt->papFldDes[acalcoutRecordODLY]->offset = (unsigned short)offsetof(acalcoutRecord, odly);
    prt->papFldDes[acalcoutRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[acalcoutRecordWAIT]->offset = (unsigned short)offsetof(acalcoutRecord, wait);
    prt->papFldDes[acalcoutRecordDLYA]->size = sizeof(prec->dlya);
    prt->papFldDes[acalcoutRecordDLYA]->offset = (unsigned short)offsetof(acalcoutRecord, dlya);
    prt->papFldDes[acalcoutRecordDOPT]->size = sizeof(prec->dopt);
    prt->papFldDes[acalcoutRecordDOPT]->offset = (unsigned short)offsetof(acalcoutRecord, dopt);
    prt->papFldDes[acalcoutRecordOCAL]->size = sizeof(prec->ocal);
    prt->papFldDes[acalcoutRecordOCAL]->offset = (unsigned short)offsetof(acalcoutRecord, ocal);
    prt->papFldDes[acalcoutRecordOCLV]->size = sizeof(prec->oclv);
    prt->papFldDes[acalcoutRecordOCLV]->offset = (unsigned short)offsetof(acalcoutRecord, oclv);
    prt->papFldDes[acalcoutRecordOEVT]->size = sizeof(prec->oevt);
    prt->papFldDes[acalcoutRecordOEVT]->offset = (unsigned short)offsetof(acalcoutRecord, oevt);
    prt->papFldDes[acalcoutRecordIVOA]->size = sizeof(prec->ivoa);
    prt->papFldDes[acalcoutRecordIVOA]->offset = (unsigned short)offsetof(acalcoutRecord, ivoa);
    prt->papFldDes[acalcoutRecordIVOV]->size = sizeof(prec->ivov);
    prt->papFldDes[acalcoutRecordIVOV]->offset = (unsigned short)offsetof(acalcoutRecord, ivov);
    prt->papFldDes[acalcoutRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[acalcoutRecordEGU]->offset = (unsigned short)offsetof(acalcoutRecord, egu);
    prt->papFldDes[acalcoutRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[acalcoutRecordPREC]->offset = (unsigned short)offsetof(acalcoutRecord, prec);
    prt->papFldDes[acalcoutRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[acalcoutRecordHOPR]->offset = (unsigned short)offsetof(acalcoutRecord, hopr);
    prt->papFldDes[acalcoutRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[acalcoutRecordLOPR]->offset = (unsigned short)offsetof(acalcoutRecord, lopr);
    prt->papFldDes[acalcoutRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[acalcoutRecordHIHI]->offset = (unsigned short)offsetof(acalcoutRecord, hihi);
    prt->papFldDes[acalcoutRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[acalcoutRecordLOLO]->offset = (unsigned short)offsetof(acalcoutRecord, lolo);
    prt->papFldDes[acalcoutRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[acalcoutRecordHIGH]->offset = (unsigned short)offsetof(acalcoutRecord, high);
    prt->papFldDes[acalcoutRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[acalcoutRecordLOW]->offset = (unsigned short)offsetof(acalcoutRecord, low);
    prt->papFldDes[acalcoutRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[acalcoutRecordHHSV]->offset = (unsigned short)offsetof(acalcoutRecord, hhsv);
    prt->papFldDes[acalcoutRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[acalcoutRecordLLSV]->offset = (unsigned short)offsetof(acalcoutRecord, llsv);
    prt->papFldDes[acalcoutRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[acalcoutRecordHSV]->offset = (unsigned short)offsetof(acalcoutRecord, hsv);
    prt->papFldDes[acalcoutRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[acalcoutRecordLSV]->offset = (unsigned short)offsetof(acalcoutRecord, lsv);
    prt->papFldDes[acalcoutRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[acalcoutRecordHYST]->offset = (unsigned short)offsetof(acalcoutRecord, hyst);
    prt->papFldDes[acalcoutRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[acalcoutRecordADEL]->offset = (unsigned short)offsetof(acalcoutRecord, adel);
    prt->papFldDes[acalcoutRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[acalcoutRecordMDEL]->offset = (unsigned short)offsetof(acalcoutRecord, mdel);
    prt->papFldDes[acalcoutRecordA]->size = sizeof(prec->a);
    prt->papFldDes[acalcoutRecordA]->offset = (unsigned short)offsetof(acalcoutRecord, a);
    prt->papFldDes[acalcoutRecordB]->size = sizeof(prec->b);
    prt->papFldDes[acalcoutRecordB]->offset = (unsigned short)offsetof(acalcoutRecord, b);
    prt->papFldDes[acalcoutRecordC]->size = sizeof(prec->c);
    prt->papFldDes[acalcoutRecordC]->offset = (unsigned short)offsetof(acalcoutRecord, c);
    prt->papFldDes[acalcoutRecordD]->size = sizeof(prec->d);
    prt->papFldDes[acalcoutRecordD]->offset = (unsigned short)offsetof(acalcoutRecord, d);
    prt->papFldDes[acalcoutRecordE]->size = sizeof(prec->e);
    prt->papFldDes[acalcoutRecordE]->offset = (unsigned short)offsetof(acalcoutRecord, e);
    prt->papFldDes[acalcoutRecordF]->size = sizeof(prec->f);
    prt->papFldDes[acalcoutRecordF]->offset = (unsigned short)offsetof(acalcoutRecord, f);
    prt->papFldDes[acalcoutRecordG]->size = sizeof(prec->g);
    prt->papFldDes[acalcoutRecordG]->offset = (unsigned short)offsetof(acalcoutRecord, g);
    prt->papFldDes[acalcoutRecordH]->size = sizeof(prec->h);
    prt->papFldDes[acalcoutRecordH]->offset = (unsigned short)offsetof(acalcoutRecord, h);
    prt->papFldDes[acalcoutRecordI]->size = sizeof(prec->i);
    prt->papFldDes[acalcoutRecordI]->offset = (unsigned short)offsetof(acalcoutRecord, i);
    prt->papFldDes[acalcoutRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[acalcoutRecordJ]->offset = (unsigned short)offsetof(acalcoutRecord, j);
    prt->papFldDes[acalcoutRecordK]->size = sizeof(prec->k);
    prt->papFldDes[acalcoutRecordK]->offset = (unsigned short)offsetof(acalcoutRecord, k);
    prt->papFldDes[acalcoutRecordL]->size = sizeof(prec->l);
    prt->papFldDes[acalcoutRecordL]->offset = (unsigned short)offsetof(acalcoutRecord, l);
    prt->papFldDes[acalcoutRecordAA]->size = sizeof(prec->aa);
    prt->papFldDes[acalcoutRecordAA]->offset = (unsigned short)offsetof(acalcoutRecord, aa);
    prt->papFldDes[acalcoutRecordBB]->size = sizeof(prec->bb);
    prt->papFldDes[acalcoutRecordBB]->offset = (unsigned short)offsetof(acalcoutRecord, bb);
    prt->papFldDes[acalcoutRecordCC]->size = sizeof(prec->cc);
    prt->papFldDes[acalcoutRecordCC]->offset = (unsigned short)offsetof(acalcoutRecord, cc);
    prt->papFldDes[acalcoutRecordDD]->size = sizeof(prec->dd);
    prt->papFldDes[acalcoutRecordDD]->offset = (unsigned short)offsetof(acalcoutRecord, dd);
    prt->papFldDes[acalcoutRecordEE]->size = sizeof(prec->ee);
    prt->papFldDes[acalcoutRecordEE]->offset = (unsigned short)offsetof(acalcoutRecord, ee);
    prt->papFldDes[acalcoutRecordFF]->size = sizeof(prec->ff);
    prt->papFldDes[acalcoutRecordFF]->offset = (unsigned short)offsetof(acalcoutRecord, ff);
    prt->papFldDes[acalcoutRecordGG]->size = sizeof(prec->gg);
    prt->papFldDes[acalcoutRecordGG]->offset = (unsigned short)offsetof(acalcoutRecord, gg);
    prt->papFldDes[acalcoutRecordHH]->size = sizeof(prec->hh);
    prt->papFldDes[acalcoutRecordHH]->offset = (unsigned short)offsetof(acalcoutRecord, hh);
    prt->papFldDes[acalcoutRecordII]->size = sizeof(prec->ii);
    prt->papFldDes[acalcoutRecordII]->offset = (unsigned short)offsetof(acalcoutRecord, ii);
    prt->papFldDes[acalcoutRecordJJ]->size = sizeof(prec->jj);
    prt->papFldDes[acalcoutRecordJJ]->offset = (unsigned short)offsetof(acalcoutRecord, jj);
    prt->papFldDes[acalcoutRecordKK]->size = sizeof(prec->kk);
    prt->papFldDes[acalcoutRecordKK]->offset = (unsigned short)offsetof(acalcoutRecord, kk);
    prt->papFldDes[acalcoutRecordLL]->size = sizeof(prec->ll);
    prt->papFldDes[acalcoutRecordLL]->offset = (unsigned short)offsetof(acalcoutRecord, ll);
    prt->papFldDes[acalcoutRecordPAA]->size = sizeof(prec->paa);
    prt->papFldDes[acalcoutRecordPAA]->offset = (unsigned short)offsetof(acalcoutRecord, paa);
    prt->papFldDes[acalcoutRecordNEWM]->size = sizeof(prec->newm);
    prt->papFldDes[acalcoutRecordNEWM]->offset = (unsigned short)offsetof(acalcoutRecord, newm);
    prt->papFldDes[acalcoutRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[acalcoutRecordOVAL]->offset = (unsigned short)offsetof(acalcoutRecord, oval);
    prt->papFldDes[acalcoutRecordOAV]->size = sizeof(prec->oav);
    prt->papFldDes[acalcoutRecordOAV]->offset = (unsigned short)offsetof(acalcoutRecord, oav);
    prt->papFldDes[acalcoutRecordPOAV]->size = sizeof(prec->poav);
    prt->papFldDes[acalcoutRecordPOAV]->offset = (unsigned short)offsetof(acalcoutRecord, poav);
    prt->papFldDes[acalcoutRecordPA]->size = sizeof(prec->pa);
    prt->papFldDes[acalcoutRecordPA]->offset = (unsigned short)offsetof(acalcoutRecord, pa);
    prt->papFldDes[acalcoutRecordPB]->size = sizeof(prec->pb);
    prt->papFldDes[acalcoutRecordPB]->offset = (unsigned short)offsetof(acalcoutRecord, pb);
    prt->papFldDes[acalcoutRecordPC]->size = sizeof(prec->pc);
    prt->papFldDes[acalcoutRecordPC]->offset = (unsigned short)offsetof(acalcoutRecord, pc);
    prt->papFldDes[acalcoutRecordPD]->size = sizeof(prec->pd);
    prt->papFldDes[acalcoutRecordPD]->offset = (unsigned short)offsetof(acalcoutRecord, pd);
    prt->papFldDes[acalcoutRecordPE]->size = sizeof(prec->pe);
    prt->papFldDes[acalcoutRecordPE]->offset = (unsigned short)offsetof(acalcoutRecord, pe);
    prt->papFldDes[acalcoutRecordPF]->size = sizeof(prec->pf);
    prt->papFldDes[acalcoutRecordPF]->offset = (unsigned short)offsetof(acalcoutRecord, pf);
    prt->papFldDes[acalcoutRecordPG]->size = sizeof(prec->pg);
    prt->papFldDes[acalcoutRecordPG]->offset = (unsigned short)offsetof(acalcoutRecord, pg);
    prt->papFldDes[acalcoutRecordPH]->size = sizeof(prec->ph);
    prt->papFldDes[acalcoutRecordPH]->offset = (unsigned short)offsetof(acalcoutRecord, ph);
    prt->papFldDes[acalcoutRecordPI]->size = sizeof(prec->pi);
    prt->papFldDes[acalcoutRecordPI]->offset = (unsigned short)offsetof(acalcoutRecord, pi);
    prt->papFldDes[acalcoutRecordPJ]->size = sizeof(prec->pj);
    prt->papFldDes[acalcoutRecordPJ]->offset = (unsigned short)offsetof(acalcoutRecord, pj);
    prt->papFldDes[acalcoutRecordPK]->size = sizeof(prec->pk);
    prt->papFldDes[acalcoutRecordPK]->offset = (unsigned short)offsetof(acalcoutRecord, pk);
    prt->papFldDes[acalcoutRecordPL]->size = sizeof(prec->pl);
    prt->papFldDes[acalcoutRecordPL]->offset = (unsigned short)offsetof(acalcoutRecord, pl);
    prt->papFldDes[acalcoutRecordPOVL]->size = sizeof(prec->povl);
    prt->papFldDes[acalcoutRecordPOVL]->offset = (unsigned short)offsetof(acalcoutRecord, povl);
    prt->papFldDes[acalcoutRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[acalcoutRecordLALM]->offset = (unsigned short)offsetof(acalcoutRecord, lalm);
    prt->papFldDes[acalcoutRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[acalcoutRecordALST]->offset = (unsigned short)offsetof(acalcoutRecord, alst);
    prt->papFldDes[acalcoutRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[acalcoutRecordMLST]->offset = (unsigned short)offsetof(acalcoutRecord, mlst);
    prt->papFldDes[acalcoutRecordRPCL]->size = sizeof(prec->rpcl);
    prt->papFldDes[acalcoutRecordRPCL]->offset = (unsigned short)offsetof(acalcoutRecord, rpcl);
    prt->papFldDes[acalcoutRecordORPC]->size = sizeof(prec->orpc);
    prt->papFldDes[acalcoutRecordORPC]->offset = (unsigned short)offsetof(acalcoutRecord, orpc);
    prt->papFldDes[acalcoutRecordCACT]->size = sizeof(prec->cact);
    prt->papFldDes[acalcoutRecordCACT]->offset = (unsigned short)offsetof(acalcoutRecord, cact);
    prt->papFldDes[acalcoutRecordCSTAT]->size = sizeof(prec->cstat);
    prt->papFldDes[acalcoutRecordCSTAT]->offset = (unsigned short)offsetof(acalcoutRecord, cstat);
    prt->papFldDes[acalcoutRecordAMASK]->size = sizeof(prec->amask);
    prt->papFldDes[acalcoutRecordAMASK]->offset = (unsigned short)offsetof(acalcoutRecord, amask);
    prt->papFldDes[acalcoutRecordSIZE]->size = sizeof(prec->size);
    prt->papFldDes[acalcoutRecordSIZE]->offset = (unsigned short)offsetof(acalcoutRecord, size);
    prt->papFldDes[acalcoutRecordAMEM]->size = sizeof(prec->amem);
    prt->papFldDes[acalcoutRecordAMEM]->offset = (unsigned short)offsetof(acalcoutRecord, amem);
    prt->papFldDes[acalcoutRecordPMEM]->size = sizeof(prec->pmem);
    prt->papFldDes[acalcoutRecordPMEM]->offset = (unsigned short)offsetof(acalcoutRecord, pmem);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(acalcoutRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_aCalcoutRecord_H */
