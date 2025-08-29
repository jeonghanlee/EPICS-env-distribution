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
    prt->papFldDes[acalcoutRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[acalcoutRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[acalcoutRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[acalcoutRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[acalcoutRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[acalcoutRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[acalcoutRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[acalcoutRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[acalcoutRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[acalcoutRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[acalcoutRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[acalcoutRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[acalcoutRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[acalcoutRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[acalcoutRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[acalcoutRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[acalcoutRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[acalcoutRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[acalcoutRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[acalcoutRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[acalcoutRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[acalcoutRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[acalcoutRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[acalcoutRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[acalcoutRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[acalcoutRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[acalcoutRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[acalcoutRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[acalcoutRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[acalcoutRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[acalcoutRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[acalcoutRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[acalcoutRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[acalcoutRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[acalcoutRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[acalcoutRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[acalcoutRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[acalcoutRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[acalcoutRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[acalcoutRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[acalcoutRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[acalcoutRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[acalcoutRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[acalcoutRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[acalcoutRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[acalcoutRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[acalcoutRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[acalcoutRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[acalcoutRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[acalcoutRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[acalcoutRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[acalcoutRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[acalcoutRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[acalcoutRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[acalcoutRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[acalcoutRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[acalcoutRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[acalcoutRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[acalcoutRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[acalcoutRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[acalcoutRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[acalcoutRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[acalcoutRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[acalcoutRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[acalcoutRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[acalcoutRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[acalcoutRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[acalcoutRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[acalcoutRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[acalcoutRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[acalcoutRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[acalcoutRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[acalcoutRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[acalcoutRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[acalcoutRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[acalcoutRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[acalcoutRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[acalcoutRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[acalcoutRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[acalcoutRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[acalcoutRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[acalcoutRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[acalcoutRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[acalcoutRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[acalcoutRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[acalcoutRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[acalcoutRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[acalcoutRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[acalcoutRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[acalcoutRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[acalcoutRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[acalcoutRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[acalcoutRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[acalcoutRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[acalcoutRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[acalcoutRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[acalcoutRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[acalcoutRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[acalcoutRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[acalcoutRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[acalcoutRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[acalcoutRecordAVAL]->size = sizeof(prec->aval);
    prt->papFldDes[acalcoutRecordAVAL]->offset = (unsigned short)((char *)&prec->aval - (char *)prec);
    prt->papFldDes[acalcoutRecordNELM]->size = sizeof(prec->nelm);
    prt->papFldDes[acalcoutRecordNELM]->offset = (unsigned short)((char *)&prec->nelm - (char *)prec);
    prt->papFldDes[acalcoutRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[acalcoutRecordNUSE]->offset = (unsigned short)((char *)&prec->nuse - (char *)prec);
    prt->papFldDes[acalcoutRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[acalcoutRecordPVAL]->offset = (unsigned short)((char *)&prec->pval - (char *)prec);
    prt->papFldDes[acalcoutRecordPAVL]->size = sizeof(prec->pavl);
    prt->papFldDes[acalcoutRecordPAVL]->offset = (unsigned short)((char *)&prec->pavl - (char *)prec);
    prt->papFldDes[acalcoutRecordCALC]->size = sizeof(prec->calc);
    prt->papFldDes[acalcoutRecordCALC]->offset = (unsigned short)((char *)&prec->calc - (char *)prec);
    prt->papFldDes[acalcoutRecordCLCV]->size = sizeof(prec->clcv);
    prt->papFldDes[acalcoutRecordCLCV]->offset = (unsigned short)((char *)&prec->clcv - (char *)prec);
    prt->papFldDes[acalcoutRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[acalcoutRecordINPA]->offset = (unsigned short)((char *)&prec->inpa - (char *)prec);
    prt->papFldDes[acalcoutRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[acalcoutRecordINPB]->offset = (unsigned short)((char *)&prec->inpb - (char *)prec);
    prt->papFldDes[acalcoutRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[acalcoutRecordINPC]->offset = (unsigned short)((char *)&prec->inpc - (char *)prec);
    prt->papFldDes[acalcoutRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[acalcoutRecordINPD]->offset = (unsigned short)((char *)&prec->inpd - (char *)prec);
    prt->papFldDes[acalcoutRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[acalcoutRecordINPE]->offset = (unsigned short)((char *)&prec->inpe - (char *)prec);
    prt->papFldDes[acalcoutRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[acalcoutRecordINPF]->offset = (unsigned short)((char *)&prec->inpf - (char *)prec);
    prt->papFldDes[acalcoutRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[acalcoutRecordINPG]->offset = (unsigned short)((char *)&prec->inpg - (char *)prec);
    prt->papFldDes[acalcoutRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[acalcoutRecordINPH]->offset = (unsigned short)((char *)&prec->inph - (char *)prec);
    prt->papFldDes[acalcoutRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[acalcoutRecordINPI]->offset = (unsigned short)((char *)&prec->inpi - (char *)prec);
    prt->papFldDes[acalcoutRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[acalcoutRecordINPJ]->offset = (unsigned short)((char *)&prec->inpj - (char *)prec);
    prt->papFldDes[acalcoutRecordINPK]->size = sizeof(prec->inpk);
    prt->papFldDes[acalcoutRecordINPK]->offset = (unsigned short)((char *)&prec->inpk - (char *)prec);
    prt->papFldDes[acalcoutRecordINPL]->size = sizeof(prec->inpl);
    prt->papFldDes[acalcoutRecordINPL]->offset = (unsigned short)((char *)&prec->inpl - (char *)prec);
    prt->papFldDes[acalcoutRecordINAA]->size = sizeof(prec->inaa);
    prt->papFldDes[acalcoutRecordINAA]->offset = (unsigned short)((char *)&prec->inaa - (char *)prec);
    prt->papFldDes[acalcoutRecordINBB]->size = sizeof(prec->inbb);
    prt->papFldDes[acalcoutRecordINBB]->offset = (unsigned short)((char *)&prec->inbb - (char *)prec);
    prt->papFldDes[acalcoutRecordINCC]->size = sizeof(prec->incc);
    prt->papFldDes[acalcoutRecordINCC]->offset = (unsigned short)((char *)&prec->incc - (char *)prec);
    prt->papFldDes[acalcoutRecordINDD]->size = sizeof(prec->indd);
    prt->papFldDes[acalcoutRecordINDD]->offset = (unsigned short)((char *)&prec->indd - (char *)prec);
    prt->papFldDes[acalcoutRecordINEE]->size = sizeof(prec->inee);
    prt->papFldDes[acalcoutRecordINEE]->offset = (unsigned short)((char *)&prec->inee - (char *)prec);
    prt->papFldDes[acalcoutRecordINFF]->size = sizeof(prec->inff);
    prt->papFldDes[acalcoutRecordINFF]->offset = (unsigned short)((char *)&prec->inff - (char *)prec);
    prt->papFldDes[acalcoutRecordINGG]->size = sizeof(prec->ingg);
    prt->papFldDes[acalcoutRecordINGG]->offset = (unsigned short)((char *)&prec->ingg - (char *)prec);
    prt->papFldDes[acalcoutRecordINHH]->size = sizeof(prec->inhh);
    prt->papFldDes[acalcoutRecordINHH]->offset = (unsigned short)((char *)&prec->inhh - (char *)prec);
    prt->papFldDes[acalcoutRecordINII]->size = sizeof(prec->inii);
    prt->papFldDes[acalcoutRecordINII]->offset = (unsigned short)((char *)&prec->inii - (char *)prec);
    prt->papFldDes[acalcoutRecordINJJ]->size = sizeof(prec->injj);
    prt->papFldDes[acalcoutRecordINJJ]->offset = (unsigned short)((char *)&prec->injj - (char *)prec);
    prt->papFldDes[acalcoutRecordINKK]->size = sizeof(prec->inkk);
    prt->papFldDes[acalcoutRecordINKK]->offset = (unsigned short)((char *)&prec->inkk - (char *)prec);
    prt->papFldDes[acalcoutRecordINLL]->size = sizeof(prec->inll);
    prt->papFldDes[acalcoutRecordINLL]->offset = (unsigned short)((char *)&prec->inll - (char *)prec);
    prt->papFldDes[acalcoutRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[acalcoutRecordOUT]->offset = (unsigned short)((char *)&prec->out - (char *)prec);
    prt->papFldDes[acalcoutRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[acalcoutRecordINAV]->offset = (unsigned short)((char *)&prec->inav - (char *)prec);
    prt->papFldDes[acalcoutRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[acalcoutRecordINBV]->offset = (unsigned short)((char *)&prec->inbv - (char *)prec);
    prt->papFldDes[acalcoutRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[acalcoutRecordINCV]->offset = (unsigned short)((char *)&prec->incv - (char *)prec);
    prt->papFldDes[acalcoutRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[acalcoutRecordINDV]->offset = (unsigned short)((char *)&prec->indv - (char *)prec);
    prt->papFldDes[acalcoutRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[acalcoutRecordINEV]->offset = (unsigned short)((char *)&prec->inev - (char *)prec);
    prt->papFldDes[acalcoutRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[acalcoutRecordINFV]->offset = (unsigned short)((char *)&prec->infv - (char *)prec);
    prt->papFldDes[acalcoutRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[acalcoutRecordINGV]->offset = (unsigned short)((char *)&prec->ingv - (char *)prec);
    prt->papFldDes[acalcoutRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[acalcoutRecordINHV]->offset = (unsigned short)((char *)&prec->inhv - (char *)prec);
    prt->papFldDes[acalcoutRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[acalcoutRecordINIV]->offset = (unsigned short)((char *)&prec->iniv - (char *)prec);
    prt->papFldDes[acalcoutRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[acalcoutRecordINJV]->offset = (unsigned short)((char *)&prec->injv - (char *)prec);
    prt->papFldDes[acalcoutRecordINKV]->size = sizeof(prec->inkv);
    prt->papFldDes[acalcoutRecordINKV]->offset = (unsigned short)((char *)&prec->inkv - (char *)prec);
    prt->papFldDes[acalcoutRecordINLV]->size = sizeof(prec->inlv);
    prt->papFldDes[acalcoutRecordINLV]->offset = (unsigned short)((char *)&prec->inlv - (char *)prec);
    prt->papFldDes[acalcoutRecordIAAV]->size = sizeof(prec->iaav);
    prt->papFldDes[acalcoutRecordIAAV]->offset = (unsigned short)((char *)&prec->iaav - (char *)prec);
    prt->papFldDes[acalcoutRecordIBBV]->size = sizeof(prec->ibbv);
    prt->papFldDes[acalcoutRecordIBBV]->offset = (unsigned short)((char *)&prec->ibbv - (char *)prec);
    prt->papFldDes[acalcoutRecordICCV]->size = sizeof(prec->iccv);
    prt->papFldDes[acalcoutRecordICCV]->offset = (unsigned short)((char *)&prec->iccv - (char *)prec);
    prt->papFldDes[acalcoutRecordIDDV]->size = sizeof(prec->iddv);
    prt->papFldDes[acalcoutRecordIDDV]->offset = (unsigned short)((char *)&prec->iddv - (char *)prec);
    prt->papFldDes[acalcoutRecordIEEV]->size = sizeof(prec->ieev);
    prt->papFldDes[acalcoutRecordIEEV]->offset = (unsigned short)((char *)&prec->ieev - (char *)prec);
    prt->papFldDes[acalcoutRecordIFFV]->size = sizeof(prec->iffv);
    prt->papFldDes[acalcoutRecordIFFV]->offset = (unsigned short)((char *)&prec->iffv - (char *)prec);
    prt->papFldDes[acalcoutRecordIGGV]->size = sizeof(prec->iggv);
    prt->papFldDes[acalcoutRecordIGGV]->offset = (unsigned short)((char *)&prec->iggv - (char *)prec);
    prt->papFldDes[acalcoutRecordIHHV]->size = sizeof(prec->ihhv);
    prt->papFldDes[acalcoutRecordIHHV]->offset = (unsigned short)((char *)&prec->ihhv - (char *)prec);
    prt->papFldDes[acalcoutRecordIIIV]->size = sizeof(prec->iiiv);
    prt->papFldDes[acalcoutRecordIIIV]->offset = (unsigned short)((char *)&prec->iiiv - (char *)prec);
    prt->papFldDes[acalcoutRecordIJJV]->size = sizeof(prec->ijjv);
    prt->papFldDes[acalcoutRecordIJJV]->offset = (unsigned short)((char *)&prec->ijjv - (char *)prec);
    prt->papFldDes[acalcoutRecordIKKV]->size = sizeof(prec->ikkv);
    prt->papFldDes[acalcoutRecordIKKV]->offset = (unsigned short)((char *)&prec->ikkv - (char *)prec);
    prt->papFldDes[acalcoutRecordILLV]->size = sizeof(prec->illv);
    prt->papFldDes[acalcoutRecordILLV]->offset = (unsigned short)((char *)&prec->illv - (char *)prec);
    prt->papFldDes[acalcoutRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[acalcoutRecordOUTV]->offset = (unsigned short)((char *)&prec->outv - (char *)prec);
    prt->papFldDes[acalcoutRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[acalcoutRecordOOPT]->offset = (unsigned short)((char *)&prec->oopt - (char *)prec);
    prt->papFldDes[acalcoutRecordODLY]->size = sizeof(prec->odly);
    prt->papFldDes[acalcoutRecordODLY]->offset = (unsigned short)((char *)&prec->odly - (char *)prec);
    prt->papFldDes[acalcoutRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[acalcoutRecordWAIT]->offset = (unsigned short)((char *)&prec->wait - (char *)prec);
    prt->papFldDes[acalcoutRecordDLYA]->size = sizeof(prec->dlya);
    prt->papFldDes[acalcoutRecordDLYA]->offset = (unsigned short)((char *)&prec->dlya - (char *)prec);
    prt->papFldDes[acalcoutRecordDOPT]->size = sizeof(prec->dopt);
    prt->papFldDes[acalcoutRecordDOPT]->offset = (unsigned short)((char *)&prec->dopt - (char *)prec);
    prt->papFldDes[acalcoutRecordOCAL]->size = sizeof(prec->ocal);
    prt->papFldDes[acalcoutRecordOCAL]->offset = (unsigned short)((char *)&prec->ocal - (char *)prec);
    prt->papFldDes[acalcoutRecordOCLV]->size = sizeof(prec->oclv);
    prt->papFldDes[acalcoutRecordOCLV]->offset = (unsigned short)((char *)&prec->oclv - (char *)prec);
    prt->papFldDes[acalcoutRecordOEVT]->size = sizeof(prec->oevt);
    prt->papFldDes[acalcoutRecordOEVT]->offset = (unsigned short)((char *)&prec->oevt - (char *)prec);
    prt->papFldDes[acalcoutRecordIVOA]->size = sizeof(prec->ivoa);
    prt->papFldDes[acalcoutRecordIVOA]->offset = (unsigned short)((char *)&prec->ivoa - (char *)prec);
    prt->papFldDes[acalcoutRecordIVOV]->size = sizeof(prec->ivov);
    prt->papFldDes[acalcoutRecordIVOV]->offset = (unsigned short)((char *)&prec->ivov - (char *)prec);
    prt->papFldDes[acalcoutRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[acalcoutRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[acalcoutRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[acalcoutRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[acalcoutRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[acalcoutRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[acalcoutRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[acalcoutRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[acalcoutRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[acalcoutRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[acalcoutRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[acalcoutRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[acalcoutRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[acalcoutRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[acalcoutRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[acalcoutRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[acalcoutRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[acalcoutRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[acalcoutRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[acalcoutRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[acalcoutRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[acalcoutRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[acalcoutRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[acalcoutRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[acalcoutRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[acalcoutRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[acalcoutRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[acalcoutRecordADEL]->offset = (unsigned short)((char *)&prec->adel - (char *)prec);
    prt->papFldDes[acalcoutRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[acalcoutRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[acalcoutRecordA]->size = sizeof(prec->a);
    prt->papFldDes[acalcoutRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[acalcoutRecordB]->size = sizeof(prec->b);
    prt->papFldDes[acalcoutRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[acalcoutRecordC]->size = sizeof(prec->c);
    prt->papFldDes[acalcoutRecordC]->offset = (unsigned short)((char *)&prec->c - (char *)prec);
    prt->papFldDes[acalcoutRecordD]->size = sizeof(prec->d);
    prt->papFldDes[acalcoutRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[acalcoutRecordE]->size = sizeof(prec->e);
    prt->papFldDes[acalcoutRecordE]->offset = (unsigned short)((char *)&prec->e - (char *)prec);
    prt->papFldDes[acalcoutRecordF]->size = sizeof(prec->f);
    prt->papFldDes[acalcoutRecordF]->offset = (unsigned short)((char *)&prec->f - (char *)prec);
    prt->papFldDes[acalcoutRecordG]->size = sizeof(prec->g);
    prt->papFldDes[acalcoutRecordG]->offset = (unsigned short)((char *)&prec->g - (char *)prec);
    prt->papFldDes[acalcoutRecordH]->size = sizeof(prec->h);
    prt->papFldDes[acalcoutRecordH]->offset = (unsigned short)((char *)&prec->h - (char *)prec);
    prt->papFldDes[acalcoutRecordI]->size = sizeof(prec->i);
    prt->papFldDes[acalcoutRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[acalcoutRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[acalcoutRecordJ]->offset = (unsigned short)((char *)&prec->j - (char *)prec);
    prt->papFldDes[acalcoutRecordK]->size = sizeof(prec->k);
    prt->papFldDes[acalcoutRecordK]->offset = (unsigned short)((char *)&prec->k - (char *)prec);
    prt->papFldDes[acalcoutRecordL]->size = sizeof(prec->l);
    prt->papFldDes[acalcoutRecordL]->offset = (unsigned short)((char *)&prec->l - (char *)prec);
    prt->papFldDes[acalcoutRecordAA]->size = sizeof(prec->aa);
    prt->papFldDes[acalcoutRecordAA]->offset = (unsigned short)((char *)&prec->aa - (char *)prec);
    prt->papFldDes[acalcoutRecordBB]->size = sizeof(prec->bb);
    prt->papFldDes[acalcoutRecordBB]->offset = (unsigned short)((char *)&prec->bb - (char *)prec);
    prt->papFldDes[acalcoutRecordCC]->size = sizeof(prec->cc);
    prt->papFldDes[acalcoutRecordCC]->offset = (unsigned short)((char *)&prec->cc - (char *)prec);
    prt->papFldDes[acalcoutRecordDD]->size = sizeof(prec->dd);
    prt->papFldDes[acalcoutRecordDD]->offset = (unsigned short)((char *)&prec->dd - (char *)prec);
    prt->papFldDes[acalcoutRecordEE]->size = sizeof(prec->ee);
    prt->papFldDes[acalcoutRecordEE]->offset = (unsigned short)((char *)&prec->ee - (char *)prec);
    prt->papFldDes[acalcoutRecordFF]->size = sizeof(prec->ff);
    prt->papFldDes[acalcoutRecordFF]->offset = (unsigned short)((char *)&prec->ff - (char *)prec);
    prt->papFldDes[acalcoutRecordGG]->size = sizeof(prec->gg);
    prt->papFldDes[acalcoutRecordGG]->offset = (unsigned short)((char *)&prec->gg - (char *)prec);
    prt->papFldDes[acalcoutRecordHH]->size = sizeof(prec->hh);
    prt->papFldDes[acalcoutRecordHH]->offset = (unsigned short)((char *)&prec->hh - (char *)prec);
    prt->papFldDes[acalcoutRecordII]->size = sizeof(prec->ii);
    prt->papFldDes[acalcoutRecordII]->offset = (unsigned short)((char *)&prec->ii - (char *)prec);
    prt->papFldDes[acalcoutRecordJJ]->size = sizeof(prec->jj);
    prt->papFldDes[acalcoutRecordJJ]->offset = (unsigned short)((char *)&prec->jj - (char *)prec);
    prt->papFldDes[acalcoutRecordKK]->size = sizeof(prec->kk);
    prt->papFldDes[acalcoutRecordKK]->offset = (unsigned short)((char *)&prec->kk - (char *)prec);
    prt->papFldDes[acalcoutRecordLL]->size = sizeof(prec->ll);
    prt->papFldDes[acalcoutRecordLL]->offset = (unsigned short)((char *)&prec->ll - (char *)prec);
    prt->papFldDes[acalcoutRecordPAA]->size = sizeof(prec->paa);
    prt->papFldDes[acalcoutRecordPAA]->offset = (unsigned short)((char *)&prec->paa - (char *)prec);
    prt->papFldDes[acalcoutRecordNEWM]->size = sizeof(prec->newm);
    prt->papFldDes[acalcoutRecordNEWM]->offset = (unsigned short)((char *)&prec->newm - (char *)prec);
    prt->papFldDes[acalcoutRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[acalcoutRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[acalcoutRecordOAV]->size = sizeof(prec->oav);
    prt->papFldDes[acalcoutRecordOAV]->offset = (unsigned short)((char *)&prec->oav - (char *)prec);
    prt->papFldDes[acalcoutRecordPOAV]->size = sizeof(prec->poav);
    prt->papFldDes[acalcoutRecordPOAV]->offset = (unsigned short)((char *)&prec->poav - (char *)prec);
    prt->papFldDes[acalcoutRecordPA]->size = sizeof(prec->pa);
    prt->papFldDes[acalcoutRecordPA]->offset = (unsigned short)((char *)&prec->pa - (char *)prec);
    prt->papFldDes[acalcoutRecordPB]->size = sizeof(prec->pb);
    prt->papFldDes[acalcoutRecordPB]->offset = (unsigned short)((char *)&prec->pb - (char *)prec);
    prt->papFldDes[acalcoutRecordPC]->size = sizeof(prec->pc);
    prt->papFldDes[acalcoutRecordPC]->offset = (unsigned short)((char *)&prec->pc - (char *)prec);
    prt->papFldDes[acalcoutRecordPD]->size = sizeof(prec->pd);
    prt->papFldDes[acalcoutRecordPD]->offset = (unsigned short)((char *)&prec->pd - (char *)prec);
    prt->papFldDes[acalcoutRecordPE]->size = sizeof(prec->pe);
    prt->papFldDes[acalcoutRecordPE]->offset = (unsigned short)((char *)&prec->pe - (char *)prec);
    prt->papFldDes[acalcoutRecordPF]->size = sizeof(prec->pf);
    prt->papFldDes[acalcoutRecordPF]->offset = (unsigned short)((char *)&prec->pf - (char *)prec);
    prt->papFldDes[acalcoutRecordPG]->size = sizeof(prec->pg);
    prt->papFldDes[acalcoutRecordPG]->offset = (unsigned short)((char *)&prec->pg - (char *)prec);
    prt->papFldDes[acalcoutRecordPH]->size = sizeof(prec->ph);
    prt->papFldDes[acalcoutRecordPH]->offset = (unsigned short)((char *)&prec->ph - (char *)prec);
    prt->papFldDes[acalcoutRecordPI]->size = sizeof(prec->pi);
    prt->papFldDes[acalcoutRecordPI]->offset = (unsigned short)((char *)&prec->pi - (char *)prec);
    prt->papFldDes[acalcoutRecordPJ]->size = sizeof(prec->pj);
    prt->papFldDes[acalcoutRecordPJ]->offset = (unsigned short)((char *)&prec->pj - (char *)prec);
    prt->papFldDes[acalcoutRecordPK]->size = sizeof(prec->pk);
    prt->papFldDes[acalcoutRecordPK]->offset = (unsigned short)((char *)&prec->pk - (char *)prec);
    prt->papFldDes[acalcoutRecordPL]->size = sizeof(prec->pl);
    prt->papFldDes[acalcoutRecordPL]->offset = (unsigned short)((char *)&prec->pl - (char *)prec);
    prt->papFldDes[acalcoutRecordPOVL]->size = sizeof(prec->povl);
    prt->papFldDes[acalcoutRecordPOVL]->offset = (unsigned short)((char *)&prec->povl - (char *)prec);
    prt->papFldDes[acalcoutRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[acalcoutRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[acalcoutRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[acalcoutRecordALST]->offset = (unsigned short)((char *)&prec->alst - (char *)prec);
    prt->papFldDes[acalcoutRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[acalcoutRecordMLST]->offset = (unsigned short)((char *)&prec->mlst - (char *)prec);
    prt->papFldDes[acalcoutRecordRPCL]->size = sizeof(prec->rpcl);
    prt->papFldDes[acalcoutRecordRPCL]->offset = (unsigned short)((char *)&prec->rpcl - (char *)prec);
    prt->papFldDes[acalcoutRecordORPC]->size = sizeof(prec->orpc);
    prt->papFldDes[acalcoutRecordORPC]->offset = (unsigned short)((char *)&prec->orpc - (char *)prec);
    prt->papFldDes[acalcoutRecordCACT]->size = sizeof(prec->cact);
    prt->papFldDes[acalcoutRecordCACT]->offset = (unsigned short)((char *)&prec->cact - (char *)prec);
    prt->papFldDes[acalcoutRecordCSTAT]->size = sizeof(prec->cstat);
    prt->papFldDes[acalcoutRecordCSTAT]->offset = (unsigned short)((char *)&prec->cstat - (char *)prec);
    prt->papFldDes[acalcoutRecordAMASK]->size = sizeof(prec->amask);
    prt->papFldDes[acalcoutRecordAMASK]->offset = (unsigned short)((char *)&prec->amask - (char *)prec);
    prt->papFldDes[acalcoutRecordSIZE]->size = sizeof(prec->size);
    prt->papFldDes[acalcoutRecordSIZE]->offset = (unsigned short)((char *)&prec->size - (char *)prec);
    prt->papFldDes[acalcoutRecordAMEM]->size = sizeof(prec->amem);
    prt->papFldDes[acalcoutRecordAMEM]->offset = (unsigned short)((char *)&prec->amem - (char *)prec);
    prt->papFldDes[acalcoutRecordPMEM]->size = sizeof(prec->pmem);
    prt->papFldDes[acalcoutRecordPMEM]->offset = (unsigned short)((char *)&prec->pmem - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(acalcoutRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_aCalcoutRecord_H */
