/** @file sCalcoutRecord.h
 * @brief Declarations for the @ref scalcoutRecord "scalcout" record type.
 *
 * This header was generated from sCalcoutRecord.dbd
 */

#ifndef INC_sCalcoutRecord_H
#define INC_sCalcoutRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef scalcoutWAIT_NUM_CHOICES
/** @brief Enumerated type from menu scalcoutWAIT */
typedef enum {
    scalcoutWAIT_NoWait             /**< @brief State string "NoWait" */,
    scalcoutWAIT_Wait               /**< @brief State string "Wait" */
} scalcoutWAIT;
/** @brief Number of states defined for menu scalcoutWAIT */
#define scalcoutWAIT_NUM_CHOICES 2
#endif

#ifndef scalcoutOOPT_NUM_CHOICES
/** @brief Enumerated type from menu scalcoutOOPT */
typedef enum {
    scalcoutOOPT_Every_Time         /**< @brief State string "Every Time" */,
    scalcoutOOPT_On_Change          /**< @brief State string "On Change" */,
    scalcoutOOPT_When_Zero          /**< @brief State string "When Zero" */,
    scalcoutOOPT_When_Non_zero      /**< @brief State string "When Non-zero" */,
    scalcoutOOPT_Transition_To_Zero /**< @brief State string "Transition To Zero" */,
    scalcoutOOPT_Transition_To_Non_zero /**< @brief State string "Transition To Non-zero" */,
    scalcoutOOPT_Never              /**< @brief State string "Never" */
} scalcoutOOPT;
/** @brief Number of states defined for menu scalcoutOOPT */
#define scalcoutOOPT_NUM_CHOICES 7
#endif

#ifndef scalcoutINAV_NUM_CHOICES
/** @brief Enumerated type from menu scalcoutINAV */
typedef enum {
    scalcoutINAV_EXT_NC             /**< @brief State string "Ext PV NC" */,
    scalcoutINAV_EXT                /**< @brief State string "Ext PV OK" */,
    scalcoutINAV_LOC                /**< @brief State string "Local PV" */,
    scalcoutINAV_CON                /**< @brief State string "Constant" */
} scalcoutINAV;
/** @brief Number of states defined for menu scalcoutINAV */
#define scalcoutINAV_NUM_CHOICES 4
#endif

#ifndef scalcoutDOPT_NUM_CHOICES
/** @brief Enumerated type from menu scalcoutDOPT */
typedef enum {
    scalcoutDOPT_Use_VAL            /**< @brief State string "Use CALC" */,
    scalcoutDOPT_Use_OVAL           /**< @brief State string "Use OCAL" */
} scalcoutDOPT;
/** @brief Number of states defined for menu scalcoutDOPT */
#define scalcoutDOPT_NUM_CHOICES 2
#endif

#ifndef scalcoutINAP_NUM_CHOICES
/** @brief Enumerated type from menu scalcoutINAP */
typedef enum {
    scalcoutINAP_No                 /**< @brief State string "No PROC on Change" */,
    scalcoutINAP_Yes                /**< @brief State string "PROC on Change" */
} scalcoutINAP;
/** @brief Number of states defined for menu scalcoutINAP */
#define scalcoutINAP_NUM_CHOICES 2
#endif

/** @brief Declaration of scalcout record type. */
typedef struct scalcoutRecord {
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
    char                sval[40];   /**< @brief String result */
    epicsFloat64        pval;       /**< @brief Previous Value */
    char                psvl[40];   /**< @brief Previous string result */
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
    DBLINK              inaa;       /**< @brief String input AA */
    DBLINK              inbb;       /**< @brief String input BB */
    DBLINK              incc;       /**< @brief String input CC */
    DBLINK              indd;       /**< @brief String input DD */
    DBLINK              inee;       /**< @brief String input EE */
    DBLINK              inff;       /**< @brief String input FF */
    DBLINK              ingg;       /**< @brief String input GG */
    DBLINK              inhh;       /**< @brief String input HH */
    DBLINK              inii;       /**< @brief String input II */
    DBLINK              injj;       /**< @brief String input JJ */
    DBLINK              inkk;       /**< @brief String input KK */
    DBLINK              inll;       /**< @brief String input LL */
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
    char **strs;                    /**< @brief Array of string pointers */
    char                aa[40];     /**< @brief Value of string input AA */
    char                bb[40];     /**< @brief Value of string input BB */
    char                cc[40];     /**< @brief Value of string input CC */
    char                dd[40];     /**< @brief Value of string input DD */
    char                ee[40];     /**< @brief Value of string input EE */
    char                ff[40];     /**< @brief Value of string input FF */
    char                gg[40];     /**< @brief Value of string input GG */
    char                hh[40];     /**< @brief Value of string input HH */
    char                ii[40];     /**< @brief Value of string input II */
    char                jj[40];     /**< @brief Value of string input JJ */
    char                kk[40];     /**< @brief Value of string input KK */
    char                ll[40];     /**< @brief Value of string input LL */
    char *paa;                      /**< @brief Prev Value of AA */
    char *pbb;                      /**< @brief Prev Value of BB */
    char *pcc;                      /**< @brief Prev Value of CC */
    char *pdd;                      /**< @brief Prev Value of DD */
    char *pee;                      /**< @brief Prev Value of EE */
    char *pff;                      /**< @brief Prev Value of FF */
    char *pgg;                      /**< @brief Prev Value of GG */
    char *phh;                      /**< @brief Prev Value of HH */
    char *pii;                      /**< @brief Prev Value of II */
    char *pjj;                      /**< @brief Prev Value of JJ */
    char *pkk;                      /**< @brief Prev Value of KK */
    char *pll;                      /**< @brief Prev Value of LL */
    epicsFloat64        oval;       /**< @brief Output Value */
    char                osv[40];    /**< @brief Output string value */
    char                posv[40];   /**< @brief Previous output string value */
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
    unsigned char rpcl[282];        /**< @brief Postfix Calc */
    unsigned char orpc[282];        /**< @brief Postfix OCalc */
} scalcoutRecord;

typedef enum {
	scalcoutRecordNAME = 0,
	scalcoutRecordDESC = 1,
	scalcoutRecordASG = 2,
	scalcoutRecordSCAN = 3,
	scalcoutRecordPINI = 4,
	scalcoutRecordPHAS = 5,
	scalcoutRecordEVNT = 6,
	scalcoutRecordTSE = 7,
	scalcoutRecordTSEL = 8,
	scalcoutRecordDTYP = 9,
	scalcoutRecordDISV = 10,
	scalcoutRecordDISA = 11,
	scalcoutRecordSDIS = 12,
	scalcoutRecordMLOK = 13,
	scalcoutRecordMLIS = 14,
	scalcoutRecordBKLNK = 15,
	scalcoutRecordDISP = 16,
	scalcoutRecordPROC = 17,
	scalcoutRecordSTAT = 18,
	scalcoutRecordSEVR = 19,
	scalcoutRecordAMSG = 20,
	scalcoutRecordNSTA = 21,
	scalcoutRecordNSEV = 22,
	scalcoutRecordNAMSG = 23,
	scalcoutRecordACKS = 24,
	scalcoutRecordACKT = 25,
	scalcoutRecordDISS = 26,
	scalcoutRecordLCNT = 27,
	scalcoutRecordPACT = 28,
	scalcoutRecordPUTF = 29,
	scalcoutRecordRPRO = 30,
	scalcoutRecordASP = 31,
	scalcoutRecordPPN = 32,
	scalcoutRecordPPNR = 33,
	scalcoutRecordSPVT = 34,
	scalcoutRecordRSET = 35,
	scalcoutRecordDSET = 36,
	scalcoutRecordDPVT = 37,
	scalcoutRecordRDES = 38,
	scalcoutRecordLSET = 39,
	scalcoutRecordPRIO = 40,
	scalcoutRecordTPRO = 41,
	scalcoutRecordBKPT = 42,
	scalcoutRecordUDF = 43,
	scalcoutRecordUDFS = 44,
	scalcoutRecordTIME = 45,
	scalcoutRecordUTAG = 46,
	scalcoutRecordFLNK = 47,
	scalcoutRecordVERS = 48,
	scalcoutRecordRPVT = 49,
	scalcoutRecordVAL = 50,
	scalcoutRecordSVAL = 51,
	scalcoutRecordPVAL = 52,
	scalcoutRecordPSVL = 53,
	scalcoutRecordCALC = 54,
	scalcoutRecordCLCV = 55,
	scalcoutRecordINPA = 56,
	scalcoutRecordINPB = 57,
	scalcoutRecordINPC = 58,
	scalcoutRecordINPD = 59,
	scalcoutRecordINPE = 60,
	scalcoutRecordINPF = 61,
	scalcoutRecordINPG = 62,
	scalcoutRecordINPH = 63,
	scalcoutRecordINPI = 64,
	scalcoutRecordINPJ = 65,
	scalcoutRecordINPK = 66,
	scalcoutRecordINPL = 67,
	scalcoutRecordINAA = 68,
	scalcoutRecordINBB = 69,
	scalcoutRecordINCC = 70,
	scalcoutRecordINDD = 71,
	scalcoutRecordINEE = 72,
	scalcoutRecordINFF = 73,
	scalcoutRecordINGG = 74,
	scalcoutRecordINHH = 75,
	scalcoutRecordINII = 76,
	scalcoutRecordINJJ = 77,
	scalcoutRecordINKK = 78,
	scalcoutRecordINLL = 79,
	scalcoutRecordOUT = 80,
	scalcoutRecordINAV = 81,
	scalcoutRecordINBV = 82,
	scalcoutRecordINCV = 83,
	scalcoutRecordINDV = 84,
	scalcoutRecordINEV = 85,
	scalcoutRecordINFV = 86,
	scalcoutRecordINGV = 87,
	scalcoutRecordINHV = 88,
	scalcoutRecordINIV = 89,
	scalcoutRecordINJV = 90,
	scalcoutRecordINKV = 91,
	scalcoutRecordINLV = 92,
	scalcoutRecordIAAV = 93,
	scalcoutRecordIBBV = 94,
	scalcoutRecordICCV = 95,
	scalcoutRecordIDDV = 96,
	scalcoutRecordIEEV = 97,
	scalcoutRecordIFFV = 98,
	scalcoutRecordIGGV = 99,
	scalcoutRecordIHHV = 100,
	scalcoutRecordIIIV = 101,
	scalcoutRecordIJJV = 102,
	scalcoutRecordIKKV = 103,
	scalcoutRecordILLV = 104,
	scalcoutRecordOUTV = 105,
	scalcoutRecordOOPT = 106,
	scalcoutRecordODLY = 107,
	scalcoutRecordWAIT = 108,
	scalcoutRecordDLYA = 109,
	scalcoutRecordDOPT = 110,
	scalcoutRecordOCAL = 111,
	scalcoutRecordOCLV = 112,
	scalcoutRecordOEVT = 113,
	scalcoutRecordIVOA = 114,
	scalcoutRecordIVOV = 115,
	scalcoutRecordEGU = 116,
	scalcoutRecordPREC = 117,
	scalcoutRecordHOPR = 118,
	scalcoutRecordLOPR = 119,
	scalcoutRecordHIHI = 120,
	scalcoutRecordLOLO = 121,
	scalcoutRecordHIGH = 122,
	scalcoutRecordLOW = 123,
	scalcoutRecordHHSV = 124,
	scalcoutRecordLLSV = 125,
	scalcoutRecordHSV = 126,
	scalcoutRecordLSV = 127,
	scalcoutRecordHYST = 128,
	scalcoutRecordADEL = 129,
	scalcoutRecordMDEL = 130,
	scalcoutRecordA = 131,
	scalcoutRecordB = 132,
	scalcoutRecordC = 133,
	scalcoutRecordD = 134,
	scalcoutRecordE = 135,
	scalcoutRecordF = 136,
	scalcoutRecordG = 137,
	scalcoutRecordH = 138,
	scalcoutRecordI = 139,
	scalcoutRecordJ = 140,
	scalcoutRecordK = 141,
	scalcoutRecordL = 142,
	scalcoutRecordSTRS = 143,
	scalcoutRecordAA = 144,
	scalcoutRecordBB = 145,
	scalcoutRecordCC = 146,
	scalcoutRecordDD = 147,
	scalcoutRecordEE = 148,
	scalcoutRecordFF = 149,
	scalcoutRecordGG = 150,
	scalcoutRecordHH = 151,
	scalcoutRecordII = 152,
	scalcoutRecordJJ = 153,
	scalcoutRecordKK = 154,
	scalcoutRecordLL = 155,
	scalcoutRecordPAA = 156,
	scalcoutRecordPBB = 157,
	scalcoutRecordPCC = 158,
	scalcoutRecordPDD = 159,
	scalcoutRecordPEE = 160,
	scalcoutRecordPFF = 161,
	scalcoutRecordPGG = 162,
	scalcoutRecordPHH = 163,
	scalcoutRecordPII = 164,
	scalcoutRecordPJJ = 165,
	scalcoutRecordPKK = 166,
	scalcoutRecordPLL = 167,
	scalcoutRecordOVAL = 168,
	scalcoutRecordOSV = 169,
	scalcoutRecordPOSV = 170,
	scalcoutRecordPA = 171,
	scalcoutRecordPB = 172,
	scalcoutRecordPC = 173,
	scalcoutRecordPD = 174,
	scalcoutRecordPE = 175,
	scalcoutRecordPF = 176,
	scalcoutRecordPG = 177,
	scalcoutRecordPH = 178,
	scalcoutRecordPI = 179,
	scalcoutRecordPJ = 180,
	scalcoutRecordPK = 181,
	scalcoutRecordPL = 182,
	scalcoutRecordPOVL = 183,
	scalcoutRecordLALM = 184,
	scalcoutRecordALST = 185,
	scalcoutRecordMLST = 186,
	scalcoutRecordRPCL = 187,
	scalcoutRecordORPC = 188
} scalcoutFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int scalcoutRecordSizeOffset(dbRecordType *prt)
{
    scalcoutRecord *prec = 0;

    if (prt->no_fields != 189) {
        cantProceed("IOC build or installation error:\n"
            "    The scalcoutRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 189.\n",
            prt->no_fields);
    }
    prt->papFldDes[scalcoutRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[scalcoutRecordNAME]->offset = (unsigned short)offsetof(scalcoutRecord, name);
    prt->papFldDes[scalcoutRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[scalcoutRecordDESC]->offset = (unsigned short)offsetof(scalcoutRecord, desc);
    prt->papFldDes[scalcoutRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[scalcoutRecordASG]->offset = (unsigned short)offsetof(scalcoutRecord, asg);
    prt->papFldDes[scalcoutRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[scalcoutRecordSCAN]->offset = (unsigned short)offsetof(scalcoutRecord, scan);
    prt->papFldDes[scalcoutRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[scalcoutRecordPINI]->offset = (unsigned short)offsetof(scalcoutRecord, pini);
    prt->papFldDes[scalcoutRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[scalcoutRecordPHAS]->offset = (unsigned short)offsetof(scalcoutRecord, phas);
    prt->papFldDes[scalcoutRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[scalcoutRecordEVNT]->offset = (unsigned short)offsetof(scalcoutRecord, evnt);
    prt->papFldDes[scalcoutRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[scalcoutRecordTSE]->offset = (unsigned short)offsetof(scalcoutRecord, tse);
    prt->papFldDes[scalcoutRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[scalcoutRecordTSEL]->offset = (unsigned short)offsetof(scalcoutRecord, tsel);
    prt->papFldDes[scalcoutRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[scalcoutRecordDTYP]->offset = (unsigned short)offsetof(scalcoutRecord, dtyp);
    prt->papFldDes[scalcoutRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[scalcoutRecordDISV]->offset = (unsigned short)offsetof(scalcoutRecord, disv);
    prt->papFldDes[scalcoutRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[scalcoutRecordDISA]->offset = (unsigned short)offsetof(scalcoutRecord, disa);
    prt->papFldDes[scalcoutRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[scalcoutRecordSDIS]->offset = (unsigned short)offsetof(scalcoutRecord, sdis);
    prt->papFldDes[scalcoutRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[scalcoutRecordMLOK]->offset = (unsigned short)offsetof(scalcoutRecord, mlok);
    prt->papFldDes[scalcoutRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[scalcoutRecordMLIS]->offset = (unsigned short)offsetof(scalcoutRecord, mlis);
    prt->papFldDes[scalcoutRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[scalcoutRecordBKLNK]->offset = (unsigned short)offsetof(scalcoutRecord, bklnk);
    prt->papFldDes[scalcoutRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[scalcoutRecordDISP]->offset = (unsigned short)offsetof(scalcoutRecord, disp);
    prt->papFldDes[scalcoutRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[scalcoutRecordPROC]->offset = (unsigned short)offsetof(scalcoutRecord, proc);
    prt->papFldDes[scalcoutRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[scalcoutRecordSTAT]->offset = (unsigned short)offsetof(scalcoutRecord, stat);
    prt->papFldDes[scalcoutRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[scalcoutRecordSEVR]->offset = (unsigned short)offsetof(scalcoutRecord, sevr);
    prt->papFldDes[scalcoutRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[scalcoutRecordAMSG]->offset = (unsigned short)offsetof(scalcoutRecord, amsg);
    prt->papFldDes[scalcoutRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[scalcoutRecordNSTA]->offset = (unsigned short)offsetof(scalcoutRecord, nsta);
    prt->papFldDes[scalcoutRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[scalcoutRecordNSEV]->offset = (unsigned short)offsetof(scalcoutRecord, nsev);
    prt->papFldDes[scalcoutRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[scalcoutRecordNAMSG]->offset = (unsigned short)offsetof(scalcoutRecord, namsg);
    prt->papFldDes[scalcoutRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[scalcoutRecordACKS]->offset = (unsigned short)offsetof(scalcoutRecord, acks);
    prt->papFldDes[scalcoutRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[scalcoutRecordACKT]->offset = (unsigned short)offsetof(scalcoutRecord, ackt);
    prt->papFldDes[scalcoutRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[scalcoutRecordDISS]->offset = (unsigned short)offsetof(scalcoutRecord, diss);
    prt->papFldDes[scalcoutRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[scalcoutRecordLCNT]->offset = (unsigned short)offsetof(scalcoutRecord, lcnt);
    prt->papFldDes[scalcoutRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[scalcoutRecordPACT]->offset = (unsigned short)offsetof(scalcoutRecord, pact);
    prt->papFldDes[scalcoutRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[scalcoutRecordPUTF]->offset = (unsigned short)offsetof(scalcoutRecord, putf);
    prt->papFldDes[scalcoutRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[scalcoutRecordRPRO]->offset = (unsigned short)offsetof(scalcoutRecord, rpro);
    prt->papFldDes[scalcoutRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[scalcoutRecordASP]->offset = (unsigned short)offsetof(scalcoutRecord, asp);
    prt->papFldDes[scalcoutRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[scalcoutRecordPPN]->offset = (unsigned short)offsetof(scalcoutRecord, ppn);
    prt->papFldDes[scalcoutRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[scalcoutRecordPPNR]->offset = (unsigned short)offsetof(scalcoutRecord, ppnr);
    prt->papFldDes[scalcoutRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[scalcoutRecordSPVT]->offset = (unsigned short)offsetof(scalcoutRecord, spvt);
    prt->papFldDes[scalcoutRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[scalcoutRecordRSET]->offset = (unsigned short)offsetof(scalcoutRecord, rset);
    prt->papFldDes[scalcoutRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[scalcoutRecordDSET]->offset = (unsigned short)offsetof(scalcoutRecord, dset);
    prt->papFldDes[scalcoutRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[scalcoutRecordDPVT]->offset = (unsigned short)offsetof(scalcoutRecord, dpvt);
    prt->papFldDes[scalcoutRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[scalcoutRecordRDES]->offset = (unsigned short)offsetof(scalcoutRecord, rdes);
    prt->papFldDes[scalcoutRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[scalcoutRecordLSET]->offset = (unsigned short)offsetof(scalcoutRecord, lset);
    prt->papFldDes[scalcoutRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[scalcoutRecordPRIO]->offset = (unsigned short)offsetof(scalcoutRecord, prio);
    prt->papFldDes[scalcoutRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[scalcoutRecordTPRO]->offset = (unsigned short)offsetof(scalcoutRecord, tpro);
    prt->papFldDes[scalcoutRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[scalcoutRecordBKPT]->offset = (unsigned short)offsetof(scalcoutRecord, bkpt);
    prt->papFldDes[scalcoutRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[scalcoutRecordUDF]->offset = (unsigned short)offsetof(scalcoutRecord, udf);
    prt->papFldDes[scalcoutRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[scalcoutRecordUDFS]->offset = (unsigned short)offsetof(scalcoutRecord, udfs);
    prt->papFldDes[scalcoutRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[scalcoutRecordTIME]->offset = (unsigned short)offsetof(scalcoutRecord, time);
    prt->papFldDes[scalcoutRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[scalcoutRecordUTAG]->offset = (unsigned short)offsetof(scalcoutRecord, utag);
    prt->papFldDes[scalcoutRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[scalcoutRecordFLNK]->offset = (unsigned short)offsetof(scalcoutRecord, flnk);
    prt->papFldDes[scalcoutRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[scalcoutRecordVERS]->offset = (unsigned short)offsetof(scalcoutRecord, vers);
    prt->papFldDes[scalcoutRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[scalcoutRecordRPVT]->offset = (unsigned short)offsetof(scalcoutRecord, rpvt);
    prt->papFldDes[scalcoutRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[scalcoutRecordVAL]->offset = (unsigned short)offsetof(scalcoutRecord, val);
    prt->papFldDes[scalcoutRecordSVAL]->size = sizeof(prec->sval);
    prt->papFldDes[scalcoutRecordSVAL]->offset = (unsigned short)offsetof(scalcoutRecord, sval);
    prt->papFldDes[scalcoutRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[scalcoutRecordPVAL]->offset = (unsigned short)offsetof(scalcoutRecord, pval);
    prt->papFldDes[scalcoutRecordPSVL]->size = sizeof(prec->psvl);
    prt->papFldDes[scalcoutRecordPSVL]->offset = (unsigned short)offsetof(scalcoutRecord, psvl);
    prt->papFldDes[scalcoutRecordCALC]->size = sizeof(prec->calc);
    prt->papFldDes[scalcoutRecordCALC]->offset = (unsigned short)offsetof(scalcoutRecord, calc);
    prt->papFldDes[scalcoutRecordCLCV]->size = sizeof(prec->clcv);
    prt->papFldDes[scalcoutRecordCLCV]->offset = (unsigned short)offsetof(scalcoutRecord, clcv);
    prt->papFldDes[scalcoutRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[scalcoutRecordINPA]->offset = (unsigned short)offsetof(scalcoutRecord, inpa);
    prt->papFldDes[scalcoutRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[scalcoutRecordINPB]->offset = (unsigned short)offsetof(scalcoutRecord, inpb);
    prt->papFldDes[scalcoutRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[scalcoutRecordINPC]->offset = (unsigned short)offsetof(scalcoutRecord, inpc);
    prt->papFldDes[scalcoutRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[scalcoutRecordINPD]->offset = (unsigned short)offsetof(scalcoutRecord, inpd);
    prt->papFldDes[scalcoutRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[scalcoutRecordINPE]->offset = (unsigned short)offsetof(scalcoutRecord, inpe);
    prt->papFldDes[scalcoutRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[scalcoutRecordINPF]->offset = (unsigned short)offsetof(scalcoutRecord, inpf);
    prt->papFldDes[scalcoutRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[scalcoutRecordINPG]->offset = (unsigned short)offsetof(scalcoutRecord, inpg);
    prt->papFldDes[scalcoutRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[scalcoutRecordINPH]->offset = (unsigned short)offsetof(scalcoutRecord, inph);
    prt->papFldDes[scalcoutRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[scalcoutRecordINPI]->offset = (unsigned short)offsetof(scalcoutRecord, inpi);
    prt->papFldDes[scalcoutRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[scalcoutRecordINPJ]->offset = (unsigned short)offsetof(scalcoutRecord, inpj);
    prt->papFldDes[scalcoutRecordINPK]->size = sizeof(prec->inpk);
    prt->papFldDes[scalcoutRecordINPK]->offset = (unsigned short)offsetof(scalcoutRecord, inpk);
    prt->papFldDes[scalcoutRecordINPL]->size = sizeof(prec->inpl);
    prt->papFldDes[scalcoutRecordINPL]->offset = (unsigned short)offsetof(scalcoutRecord, inpl);
    prt->papFldDes[scalcoutRecordINAA]->size = sizeof(prec->inaa);
    prt->papFldDes[scalcoutRecordINAA]->offset = (unsigned short)offsetof(scalcoutRecord, inaa);
    prt->papFldDes[scalcoutRecordINBB]->size = sizeof(prec->inbb);
    prt->papFldDes[scalcoutRecordINBB]->offset = (unsigned short)offsetof(scalcoutRecord, inbb);
    prt->papFldDes[scalcoutRecordINCC]->size = sizeof(prec->incc);
    prt->papFldDes[scalcoutRecordINCC]->offset = (unsigned short)offsetof(scalcoutRecord, incc);
    prt->papFldDes[scalcoutRecordINDD]->size = sizeof(prec->indd);
    prt->papFldDes[scalcoutRecordINDD]->offset = (unsigned short)offsetof(scalcoutRecord, indd);
    prt->papFldDes[scalcoutRecordINEE]->size = sizeof(prec->inee);
    prt->papFldDes[scalcoutRecordINEE]->offset = (unsigned short)offsetof(scalcoutRecord, inee);
    prt->papFldDes[scalcoutRecordINFF]->size = sizeof(prec->inff);
    prt->papFldDes[scalcoutRecordINFF]->offset = (unsigned short)offsetof(scalcoutRecord, inff);
    prt->papFldDes[scalcoutRecordINGG]->size = sizeof(prec->ingg);
    prt->papFldDes[scalcoutRecordINGG]->offset = (unsigned short)offsetof(scalcoutRecord, ingg);
    prt->papFldDes[scalcoutRecordINHH]->size = sizeof(prec->inhh);
    prt->papFldDes[scalcoutRecordINHH]->offset = (unsigned short)offsetof(scalcoutRecord, inhh);
    prt->papFldDes[scalcoutRecordINII]->size = sizeof(prec->inii);
    prt->papFldDes[scalcoutRecordINII]->offset = (unsigned short)offsetof(scalcoutRecord, inii);
    prt->papFldDes[scalcoutRecordINJJ]->size = sizeof(prec->injj);
    prt->papFldDes[scalcoutRecordINJJ]->offset = (unsigned short)offsetof(scalcoutRecord, injj);
    prt->papFldDes[scalcoutRecordINKK]->size = sizeof(prec->inkk);
    prt->papFldDes[scalcoutRecordINKK]->offset = (unsigned short)offsetof(scalcoutRecord, inkk);
    prt->papFldDes[scalcoutRecordINLL]->size = sizeof(prec->inll);
    prt->papFldDes[scalcoutRecordINLL]->offset = (unsigned short)offsetof(scalcoutRecord, inll);
    prt->papFldDes[scalcoutRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[scalcoutRecordOUT]->offset = (unsigned short)offsetof(scalcoutRecord, out);
    prt->papFldDes[scalcoutRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[scalcoutRecordINAV]->offset = (unsigned short)offsetof(scalcoutRecord, inav);
    prt->papFldDes[scalcoutRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[scalcoutRecordINBV]->offset = (unsigned short)offsetof(scalcoutRecord, inbv);
    prt->papFldDes[scalcoutRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[scalcoutRecordINCV]->offset = (unsigned short)offsetof(scalcoutRecord, incv);
    prt->papFldDes[scalcoutRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[scalcoutRecordINDV]->offset = (unsigned short)offsetof(scalcoutRecord, indv);
    prt->papFldDes[scalcoutRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[scalcoutRecordINEV]->offset = (unsigned short)offsetof(scalcoutRecord, inev);
    prt->papFldDes[scalcoutRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[scalcoutRecordINFV]->offset = (unsigned short)offsetof(scalcoutRecord, infv);
    prt->papFldDes[scalcoutRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[scalcoutRecordINGV]->offset = (unsigned short)offsetof(scalcoutRecord, ingv);
    prt->papFldDes[scalcoutRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[scalcoutRecordINHV]->offset = (unsigned short)offsetof(scalcoutRecord, inhv);
    prt->papFldDes[scalcoutRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[scalcoutRecordINIV]->offset = (unsigned short)offsetof(scalcoutRecord, iniv);
    prt->papFldDes[scalcoutRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[scalcoutRecordINJV]->offset = (unsigned short)offsetof(scalcoutRecord, injv);
    prt->papFldDes[scalcoutRecordINKV]->size = sizeof(prec->inkv);
    prt->papFldDes[scalcoutRecordINKV]->offset = (unsigned short)offsetof(scalcoutRecord, inkv);
    prt->papFldDes[scalcoutRecordINLV]->size = sizeof(prec->inlv);
    prt->papFldDes[scalcoutRecordINLV]->offset = (unsigned short)offsetof(scalcoutRecord, inlv);
    prt->papFldDes[scalcoutRecordIAAV]->size = sizeof(prec->iaav);
    prt->papFldDes[scalcoutRecordIAAV]->offset = (unsigned short)offsetof(scalcoutRecord, iaav);
    prt->papFldDes[scalcoutRecordIBBV]->size = sizeof(prec->ibbv);
    prt->papFldDes[scalcoutRecordIBBV]->offset = (unsigned short)offsetof(scalcoutRecord, ibbv);
    prt->papFldDes[scalcoutRecordICCV]->size = sizeof(prec->iccv);
    prt->papFldDes[scalcoutRecordICCV]->offset = (unsigned short)offsetof(scalcoutRecord, iccv);
    prt->papFldDes[scalcoutRecordIDDV]->size = sizeof(prec->iddv);
    prt->papFldDes[scalcoutRecordIDDV]->offset = (unsigned short)offsetof(scalcoutRecord, iddv);
    prt->papFldDes[scalcoutRecordIEEV]->size = sizeof(prec->ieev);
    prt->papFldDes[scalcoutRecordIEEV]->offset = (unsigned short)offsetof(scalcoutRecord, ieev);
    prt->papFldDes[scalcoutRecordIFFV]->size = sizeof(prec->iffv);
    prt->papFldDes[scalcoutRecordIFFV]->offset = (unsigned short)offsetof(scalcoutRecord, iffv);
    prt->papFldDes[scalcoutRecordIGGV]->size = sizeof(prec->iggv);
    prt->papFldDes[scalcoutRecordIGGV]->offset = (unsigned short)offsetof(scalcoutRecord, iggv);
    prt->papFldDes[scalcoutRecordIHHV]->size = sizeof(prec->ihhv);
    prt->papFldDes[scalcoutRecordIHHV]->offset = (unsigned short)offsetof(scalcoutRecord, ihhv);
    prt->papFldDes[scalcoutRecordIIIV]->size = sizeof(prec->iiiv);
    prt->papFldDes[scalcoutRecordIIIV]->offset = (unsigned short)offsetof(scalcoutRecord, iiiv);
    prt->papFldDes[scalcoutRecordIJJV]->size = sizeof(prec->ijjv);
    prt->papFldDes[scalcoutRecordIJJV]->offset = (unsigned short)offsetof(scalcoutRecord, ijjv);
    prt->papFldDes[scalcoutRecordIKKV]->size = sizeof(prec->ikkv);
    prt->papFldDes[scalcoutRecordIKKV]->offset = (unsigned short)offsetof(scalcoutRecord, ikkv);
    prt->papFldDes[scalcoutRecordILLV]->size = sizeof(prec->illv);
    prt->papFldDes[scalcoutRecordILLV]->offset = (unsigned short)offsetof(scalcoutRecord, illv);
    prt->papFldDes[scalcoutRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[scalcoutRecordOUTV]->offset = (unsigned short)offsetof(scalcoutRecord, outv);
    prt->papFldDes[scalcoutRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[scalcoutRecordOOPT]->offset = (unsigned short)offsetof(scalcoutRecord, oopt);
    prt->papFldDes[scalcoutRecordODLY]->size = sizeof(prec->odly);
    prt->papFldDes[scalcoutRecordODLY]->offset = (unsigned short)offsetof(scalcoutRecord, odly);
    prt->papFldDes[scalcoutRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[scalcoutRecordWAIT]->offset = (unsigned short)offsetof(scalcoutRecord, wait);
    prt->papFldDes[scalcoutRecordDLYA]->size = sizeof(prec->dlya);
    prt->papFldDes[scalcoutRecordDLYA]->offset = (unsigned short)offsetof(scalcoutRecord, dlya);
    prt->papFldDes[scalcoutRecordDOPT]->size = sizeof(prec->dopt);
    prt->papFldDes[scalcoutRecordDOPT]->offset = (unsigned short)offsetof(scalcoutRecord, dopt);
    prt->papFldDes[scalcoutRecordOCAL]->size = sizeof(prec->ocal);
    prt->papFldDes[scalcoutRecordOCAL]->offset = (unsigned short)offsetof(scalcoutRecord, ocal);
    prt->papFldDes[scalcoutRecordOCLV]->size = sizeof(prec->oclv);
    prt->papFldDes[scalcoutRecordOCLV]->offset = (unsigned short)offsetof(scalcoutRecord, oclv);
    prt->papFldDes[scalcoutRecordOEVT]->size = sizeof(prec->oevt);
    prt->papFldDes[scalcoutRecordOEVT]->offset = (unsigned short)offsetof(scalcoutRecord, oevt);
    prt->papFldDes[scalcoutRecordIVOA]->size = sizeof(prec->ivoa);
    prt->papFldDes[scalcoutRecordIVOA]->offset = (unsigned short)offsetof(scalcoutRecord, ivoa);
    prt->papFldDes[scalcoutRecordIVOV]->size = sizeof(prec->ivov);
    prt->papFldDes[scalcoutRecordIVOV]->offset = (unsigned short)offsetof(scalcoutRecord, ivov);
    prt->papFldDes[scalcoutRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[scalcoutRecordEGU]->offset = (unsigned short)offsetof(scalcoutRecord, egu);
    prt->papFldDes[scalcoutRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[scalcoutRecordPREC]->offset = (unsigned short)offsetof(scalcoutRecord, prec);
    prt->papFldDes[scalcoutRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[scalcoutRecordHOPR]->offset = (unsigned short)offsetof(scalcoutRecord, hopr);
    prt->papFldDes[scalcoutRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[scalcoutRecordLOPR]->offset = (unsigned short)offsetof(scalcoutRecord, lopr);
    prt->papFldDes[scalcoutRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[scalcoutRecordHIHI]->offset = (unsigned short)offsetof(scalcoutRecord, hihi);
    prt->papFldDes[scalcoutRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[scalcoutRecordLOLO]->offset = (unsigned short)offsetof(scalcoutRecord, lolo);
    prt->papFldDes[scalcoutRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[scalcoutRecordHIGH]->offset = (unsigned short)offsetof(scalcoutRecord, high);
    prt->papFldDes[scalcoutRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[scalcoutRecordLOW]->offset = (unsigned short)offsetof(scalcoutRecord, low);
    prt->papFldDes[scalcoutRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[scalcoutRecordHHSV]->offset = (unsigned short)offsetof(scalcoutRecord, hhsv);
    prt->papFldDes[scalcoutRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[scalcoutRecordLLSV]->offset = (unsigned short)offsetof(scalcoutRecord, llsv);
    prt->papFldDes[scalcoutRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[scalcoutRecordHSV]->offset = (unsigned short)offsetof(scalcoutRecord, hsv);
    prt->papFldDes[scalcoutRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[scalcoutRecordLSV]->offset = (unsigned short)offsetof(scalcoutRecord, lsv);
    prt->papFldDes[scalcoutRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[scalcoutRecordHYST]->offset = (unsigned short)offsetof(scalcoutRecord, hyst);
    prt->papFldDes[scalcoutRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[scalcoutRecordADEL]->offset = (unsigned short)offsetof(scalcoutRecord, adel);
    prt->papFldDes[scalcoutRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[scalcoutRecordMDEL]->offset = (unsigned short)offsetof(scalcoutRecord, mdel);
    prt->papFldDes[scalcoutRecordA]->size = sizeof(prec->a);
    prt->papFldDes[scalcoutRecordA]->offset = (unsigned short)offsetof(scalcoutRecord, a);
    prt->papFldDes[scalcoutRecordB]->size = sizeof(prec->b);
    prt->papFldDes[scalcoutRecordB]->offset = (unsigned short)offsetof(scalcoutRecord, b);
    prt->papFldDes[scalcoutRecordC]->size = sizeof(prec->c);
    prt->papFldDes[scalcoutRecordC]->offset = (unsigned short)offsetof(scalcoutRecord, c);
    prt->papFldDes[scalcoutRecordD]->size = sizeof(prec->d);
    prt->papFldDes[scalcoutRecordD]->offset = (unsigned short)offsetof(scalcoutRecord, d);
    prt->papFldDes[scalcoutRecordE]->size = sizeof(prec->e);
    prt->papFldDes[scalcoutRecordE]->offset = (unsigned short)offsetof(scalcoutRecord, e);
    prt->papFldDes[scalcoutRecordF]->size = sizeof(prec->f);
    prt->papFldDes[scalcoutRecordF]->offset = (unsigned short)offsetof(scalcoutRecord, f);
    prt->papFldDes[scalcoutRecordG]->size = sizeof(prec->g);
    prt->papFldDes[scalcoutRecordG]->offset = (unsigned short)offsetof(scalcoutRecord, g);
    prt->papFldDes[scalcoutRecordH]->size = sizeof(prec->h);
    prt->papFldDes[scalcoutRecordH]->offset = (unsigned short)offsetof(scalcoutRecord, h);
    prt->papFldDes[scalcoutRecordI]->size = sizeof(prec->i);
    prt->papFldDes[scalcoutRecordI]->offset = (unsigned short)offsetof(scalcoutRecord, i);
    prt->papFldDes[scalcoutRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[scalcoutRecordJ]->offset = (unsigned short)offsetof(scalcoutRecord, j);
    prt->papFldDes[scalcoutRecordK]->size = sizeof(prec->k);
    prt->papFldDes[scalcoutRecordK]->offset = (unsigned short)offsetof(scalcoutRecord, k);
    prt->papFldDes[scalcoutRecordL]->size = sizeof(prec->l);
    prt->papFldDes[scalcoutRecordL]->offset = (unsigned short)offsetof(scalcoutRecord, l);
    prt->papFldDes[scalcoutRecordSTRS]->size = sizeof(prec->strs);
    prt->papFldDes[scalcoutRecordSTRS]->offset = (unsigned short)offsetof(scalcoutRecord, strs);
    prt->papFldDes[scalcoutRecordAA]->size = sizeof(prec->aa);
    prt->papFldDes[scalcoutRecordAA]->offset = (unsigned short)offsetof(scalcoutRecord, aa);
    prt->papFldDes[scalcoutRecordBB]->size = sizeof(prec->bb);
    prt->papFldDes[scalcoutRecordBB]->offset = (unsigned short)offsetof(scalcoutRecord, bb);
    prt->papFldDes[scalcoutRecordCC]->size = sizeof(prec->cc);
    prt->papFldDes[scalcoutRecordCC]->offset = (unsigned short)offsetof(scalcoutRecord, cc);
    prt->papFldDes[scalcoutRecordDD]->size = sizeof(prec->dd);
    prt->papFldDes[scalcoutRecordDD]->offset = (unsigned short)offsetof(scalcoutRecord, dd);
    prt->papFldDes[scalcoutRecordEE]->size = sizeof(prec->ee);
    prt->papFldDes[scalcoutRecordEE]->offset = (unsigned short)offsetof(scalcoutRecord, ee);
    prt->papFldDes[scalcoutRecordFF]->size = sizeof(prec->ff);
    prt->papFldDes[scalcoutRecordFF]->offset = (unsigned short)offsetof(scalcoutRecord, ff);
    prt->papFldDes[scalcoutRecordGG]->size = sizeof(prec->gg);
    prt->papFldDes[scalcoutRecordGG]->offset = (unsigned short)offsetof(scalcoutRecord, gg);
    prt->papFldDes[scalcoutRecordHH]->size = sizeof(prec->hh);
    prt->papFldDes[scalcoutRecordHH]->offset = (unsigned short)offsetof(scalcoutRecord, hh);
    prt->papFldDes[scalcoutRecordII]->size = sizeof(prec->ii);
    prt->papFldDes[scalcoutRecordII]->offset = (unsigned short)offsetof(scalcoutRecord, ii);
    prt->papFldDes[scalcoutRecordJJ]->size = sizeof(prec->jj);
    prt->papFldDes[scalcoutRecordJJ]->offset = (unsigned short)offsetof(scalcoutRecord, jj);
    prt->papFldDes[scalcoutRecordKK]->size = sizeof(prec->kk);
    prt->papFldDes[scalcoutRecordKK]->offset = (unsigned short)offsetof(scalcoutRecord, kk);
    prt->papFldDes[scalcoutRecordLL]->size = sizeof(prec->ll);
    prt->papFldDes[scalcoutRecordLL]->offset = (unsigned short)offsetof(scalcoutRecord, ll);
    prt->papFldDes[scalcoutRecordPAA]->size = sizeof(prec->paa);
    prt->papFldDes[scalcoutRecordPAA]->offset = (unsigned short)offsetof(scalcoutRecord, paa);
    prt->papFldDes[scalcoutRecordPBB]->size = sizeof(prec->pbb);
    prt->papFldDes[scalcoutRecordPBB]->offset = (unsigned short)offsetof(scalcoutRecord, pbb);
    prt->papFldDes[scalcoutRecordPCC]->size = sizeof(prec->pcc);
    prt->papFldDes[scalcoutRecordPCC]->offset = (unsigned short)offsetof(scalcoutRecord, pcc);
    prt->papFldDes[scalcoutRecordPDD]->size = sizeof(prec->pdd);
    prt->papFldDes[scalcoutRecordPDD]->offset = (unsigned short)offsetof(scalcoutRecord, pdd);
    prt->papFldDes[scalcoutRecordPEE]->size = sizeof(prec->pee);
    prt->papFldDes[scalcoutRecordPEE]->offset = (unsigned short)offsetof(scalcoutRecord, pee);
    prt->papFldDes[scalcoutRecordPFF]->size = sizeof(prec->pff);
    prt->papFldDes[scalcoutRecordPFF]->offset = (unsigned short)offsetof(scalcoutRecord, pff);
    prt->papFldDes[scalcoutRecordPGG]->size = sizeof(prec->pgg);
    prt->papFldDes[scalcoutRecordPGG]->offset = (unsigned short)offsetof(scalcoutRecord, pgg);
    prt->papFldDes[scalcoutRecordPHH]->size = sizeof(prec->phh);
    prt->papFldDes[scalcoutRecordPHH]->offset = (unsigned short)offsetof(scalcoutRecord, phh);
    prt->papFldDes[scalcoutRecordPII]->size = sizeof(prec->pii);
    prt->papFldDes[scalcoutRecordPII]->offset = (unsigned short)offsetof(scalcoutRecord, pii);
    prt->papFldDes[scalcoutRecordPJJ]->size = sizeof(prec->pjj);
    prt->papFldDes[scalcoutRecordPJJ]->offset = (unsigned short)offsetof(scalcoutRecord, pjj);
    prt->papFldDes[scalcoutRecordPKK]->size = sizeof(prec->pkk);
    prt->papFldDes[scalcoutRecordPKK]->offset = (unsigned short)offsetof(scalcoutRecord, pkk);
    prt->papFldDes[scalcoutRecordPLL]->size = sizeof(prec->pll);
    prt->papFldDes[scalcoutRecordPLL]->offset = (unsigned short)offsetof(scalcoutRecord, pll);
    prt->papFldDes[scalcoutRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[scalcoutRecordOVAL]->offset = (unsigned short)offsetof(scalcoutRecord, oval);
    prt->papFldDes[scalcoutRecordOSV]->size = sizeof(prec->osv);
    prt->papFldDes[scalcoutRecordOSV]->offset = (unsigned short)offsetof(scalcoutRecord, osv);
    prt->papFldDes[scalcoutRecordPOSV]->size = sizeof(prec->posv);
    prt->papFldDes[scalcoutRecordPOSV]->offset = (unsigned short)offsetof(scalcoutRecord, posv);
    prt->papFldDes[scalcoutRecordPA]->size = sizeof(prec->pa);
    prt->papFldDes[scalcoutRecordPA]->offset = (unsigned short)offsetof(scalcoutRecord, pa);
    prt->papFldDes[scalcoutRecordPB]->size = sizeof(prec->pb);
    prt->papFldDes[scalcoutRecordPB]->offset = (unsigned short)offsetof(scalcoutRecord, pb);
    prt->papFldDes[scalcoutRecordPC]->size = sizeof(prec->pc);
    prt->papFldDes[scalcoutRecordPC]->offset = (unsigned short)offsetof(scalcoutRecord, pc);
    prt->papFldDes[scalcoutRecordPD]->size = sizeof(prec->pd);
    prt->papFldDes[scalcoutRecordPD]->offset = (unsigned short)offsetof(scalcoutRecord, pd);
    prt->papFldDes[scalcoutRecordPE]->size = sizeof(prec->pe);
    prt->papFldDes[scalcoutRecordPE]->offset = (unsigned short)offsetof(scalcoutRecord, pe);
    prt->papFldDes[scalcoutRecordPF]->size = sizeof(prec->pf);
    prt->papFldDes[scalcoutRecordPF]->offset = (unsigned short)offsetof(scalcoutRecord, pf);
    prt->papFldDes[scalcoutRecordPG]->size = sizeof(prec->pg);
    prt->papFldDes[scalcoutRecordPG]->offset = (unsigned short)offsetof(scalcoutRecord, pg);
    prt->papFldDes[scalcoutRecordPH]->size = sizeof(prec->ph);
    prt->papFldDes[scalcoutRecordPH]->offset = (unsigned short)offsetof(scalcoutRecord, ph);
    prt->papFldDes[scalcoutRecordPI]->size = sizeof(prec->pi);
    prt->papFldDes[scalcoutRecordPI]->offset = (unsigned short)offsetof(scalcoutRecord, pi);
    prt->papFldDes[scalcoutRecordPJ]->size = sizeof(prec->pj);
    prt->papFldDes[scalcoutRecordPJ]->offset = (unsigned short)offsetof(scalcoutRecord, pj);
    prt->papFldDes[scalcoutRecordPK]->size = sizeof(prec->pk);
    prt->papFldDes[scalcoutRecordPK]->offset = (unsigned short)offsetof(scalcoutRecord, pk);
    prt->papFldDes[scalcoutRecordPL]->size = sizeof(prec->pl);
    prt->papFldDes[scalcoutRecordPL]->offset = (unsigned short)offsetof(scalcoutRecord, pl);
    prt->papFldDes[scalcoutRecordPOVL]->size = sizeof(prec->povl);
    prt->papFldDes[scalcoutRecordPOVL]->offset = (unsigned short)offsetof(scalcoutRecord, povl);
    prt->papFldDes[scalcoutRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[scalcoutRecordLALM]->offset = (unsigned short)offsetof(scalcoutRecord, lalm);
    prt->papFldDes[scalcoutRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[scalcoutRecordALST]->offset = (unsigned short)offsetof(scalcoutRecord, alst);
    prt->papFldDes[scalcoutRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[scalcoutRecordMLST]->offset = (unsigned short)offsetof(scalcoutRecord, mlst);
    prt->papFldDes[scalcoutRecordRPCL]->size = sizeof(prec->rpcl);
    prt->papFldDes[scalcoutRecordRPCL]->offset = (unsigned short)offsetof(scalcoutRecord, rpcl);
    prt->papFldDes[scalcoutRecordORPC]->size = sizeof(prec->orpc);
    prt->papFldDes[scalcoutRecordORPC]->offset = (unsigned short)offsetof(scalcoutRecord, orpc);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(scalcoutRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_sCalcoutRecord_H */
