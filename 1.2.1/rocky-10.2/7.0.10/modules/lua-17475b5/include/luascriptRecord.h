/** @file luascriptRecord.h
 * @brief Declarations for the @ref luascriptRecord "luascript" record type.
 *
 * This header was generated from luascriptRecord.dbd
 */

#ifndef INC_luascriptRecord_H
#define INC_luascriptRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef luascriptINAV_NUM_CHOICES
/** @brief Enumerated type from menu luascriptINAV */
typedef enum {
    luascriptINAV_EXT_NC            /**< @brief State string "Ext PV NC" */,
    luascriptINAV_EXT               /**< @brief State string "Ext PV OK" */,
    luascriptINAV_LOC               /**< @brief State string "Local PV" */,
    luascriptINAV_CON               /**< @brief State string "Constant" */
} luascriptINAV;
/** @brief Number of states defined for menu luascriptINAV */
#define luascriptINAV_NUM_CHOICES 4
#endif

#ifndef luascriptWAIT_NUM_CHOICES
/** @brief Enumerated type from menu luascriptWAIT */
typedef enum {
    luascriptWAIT_NoWait            /**< @brief State string "NoWait" */,
    luascriptWAIT_Wait              /**< @brief State string "Wait" */
} luascriptWAIT;
/** @brief Number of states defined for menu luascriptWAIT */
#define luascriptWAIT_NUM_CHOICES 2
#endif

#ifndef luascriptOOPT_NUM_CHOICES
/** @brief Enumerated type from menu luascriptOOPT */
typedef enum {
    luascriptOOPT_Every_Time        /**< @brief State string "Every Time" */,
    luascriptOOPT_On_Change         /**< @brief State string "On Change" */,
    luascriptOOPT_When_Zero         /**< @brief State string "When Zero" */,
    luascriptOOPT_When_Non_zero     /**< @brief State string "When Non-zero" */,
    luascriptOOPT_Transition_To_Zero /**< @brief State string "Transition To Zero" */,
    luascriptOOPT_Transition_To_Non_zero /**< @brief State string "Transition To Non-zero" */,
    luascriptOOPT_Never             /**< @brief State string "Never" */
} luascriptOOPT;
/** @brief Number of states defined for menu luascriptOOPT */
#define luascriptOOPT_NUM_CHOICES 7
#endif

#ifndef luascriptAVALType_NUM_CHOICES
/** @brief Enumerated type from menu luascriptAVALType */
typedef enum {
    luascriptAVALType_Integer       /**< @brief State string "Int" */,
    luascriptAVALType_Double        /**< @brief State string "Double" */,
    luascriptAVALType_Char          /**< @brief State string "Char" */
} luascriptAVALType;
/** @brief Number of states defined for menu luascriptAVALType */
#define luascriptAVALType_NUM_CHOICES 3
#endif

#ifndef luascriptSYNC_NUM_CHOICES
/** @brief Enumerated type from menu luascriptSYNC */
typedef enum {
    luascriptSYNC_Synchronous       /**< @brief State string "Sync" */,
    luascriptSYNC_Asynchronous      /**< @brief State string "Async" */
} luascriptSYNC;
/** @brief Number of states defined for menu luascriptSYNC */
#define luascriptSYNC_NUM_CHOICES 2
#endif

#ifndef luascriptRELO_NUM_CHOICES
/** @brief Enumerated type from menu luascriptRELO */
typedef enum {
    luascriptRELO_NewFile           /**< @brief State string "Every New File" */,
    luascriptRELO_NewFunction       /**< @brief State string "Every New Change" */,
    luascriptRELO_Always            /**< @brief State string "Every Processing" */
} luascriptRELO;
/** @brief Number of states defined for menu luascriptRELO */
#define luascriptRELO_NUM_CHOICES 3
#endif

/** @brief Declaration of luascript record type. */
typedef struct luascriptRecord {
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
    void* state;                    /**< @brief Lua State */
    void *rpvt;                     /**< @brief Record Private */
    epicsEnum16         sync;       /**< @brief Sync/Async processing */
    epicsEnum16         relo;       /**< @brief When to reload state? */
    epicsInt16          frld;       /**< @brief Force Reload */
    char                err[200];   /**< @brief Last Error Msg */
    char                code[121];  /**< @brief LUA Code */
    char* pcode;                    /**< @brief Previous CODE */
    char* call;                     /**< @brief Function call subtring */
    epicsEnum16         oopt;       /**< @brief Output Execute Opt */
    epicsEnum16         wait;       /**< @brief Wait for completion? */
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
    epicsEnum16         outv;       /**< @brief OUT PV Status */
    char                adsc[20];   /**< @brief Input A Description */
    char                bdsc[20];   /**< @brief Input B Description */
    char                cdsc[20];   /**< @brief Input C Description */
    char                ddsc[20];   /**< @brief Input D Description */
    char                edsc[20];   /**< @brief Input E Description */
    char                fdsc[20];   /**< @brief Input F Description */
    char                gdsc[20];   /**< @brief Input G Description */
    char                hdsc[20];   /**< @brief Input H Description */
    char                idsc[20];   /**< @brief Input I Description */
    char                jdsc[20];   /**< @brief Input J Description */
    char                aadn[20];   /**< @brief Input AA Description */
    char                bbdn[20];   /**< @brief Input BB Description */
    char                ccdn[20];   /**< @brief Input CC Description */
    char                dddn[20];   /**< @brief Input DD Description */
    char                eedn[20];   /**< @brief Input EE Description */
    char                ffdn[20];   /**< @brief Input FF Description */
    char                ggdn[20];   /**< @brief Input GG Description */
    char                hhdn[20];   /**< @brief Input HH Description */
    char                iidn[20];   /**< @brief Input II Description */
    char                jjdn[20];   /**< @brief Input JJ Description */
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
    epicsFloat64        val;        /**< @brief Result */
    char                sval[40];   /**< @brief String result 1 */
    void* aval;                     /**< @brief Array output pointer */
    epicsInt32          asiz;       /**< @brief Array output size */
    epicsEnum16         atyp;       /**< @brief Array output type */
    epicsFloat64        pval;       /**< @brief Previous Value */
    char                psvl[40];   /**< @brief Previous string result */
    void* pavl;                     /**< @brief Previous aval pointer */
    epicsInt32          pasz;       /**< @brief Previous aval size */
    epicsEnum16         patp;       /**< @brief Previous aval type */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsInt16          prec;       /**< @brief Display Precision */
} luascriptRecord;

typedef enum {
	luascriptRecordNAME = 0,
	luascriptRecordDESC = 1,
	luascriptRecordASG = 2,
	luascriptRecordSCAN = 3,
	luascriptRecordPINI = 4,
	luascriptRecordPHAS = 5,
	luascriptRecordEVNT = 6,
	luascriptRecordTSE = 7,
	luascriptRecordTSEL = 8,
	luascriptRecordDTYP = 9,
	luascriptRecordDISV = 10,
	luascriptRecordDISA = 11,
	luascriptRecordSDIS = 12,
	luascriptRecordMLOK = 13,
	luascriptRecordMLIS = 14,
	luascriptRecordBKLNK = 15,
	luascriptRecordDISP = 16,
	luascriptRecordPROC = 17,
	luascriptRecordSTAT = 18,
	luascriptRecordSEVR = 19,
	luascriptRecordAMSG = 20,
	luascriptRecordNSTA = 21,
	luascriptRecordNSEV = 22,
	luascriptRecordNAMSG = 23,
	luascriptRecordACKS = 24,
	luascriptRecordACKT = 25,
	luascriptRecordDISS = 26,
	luascriptRecordLCNT = 27,
	luascriptRecordPACT = 28,
	luascriptRecordPUTF = 29,
	luascriptRecordRPRO = 30,
	luascriptRecordASP = 31,
	luascriptRecordPPN = 32,
	luascriptRecordPPNR = 33,
	luascriptRecordSPVT = 34,
	luascriptRecordRSET = 35,
	luascriptRecordDSET = 36,
	luascriptRecordDPVT = 37,
	luascriptRecordRDES = 38,
	luascriptRecordLSET = 39,
	luascriptRecordPRIO = 40,
	luascriptRecordTPRO = 41,
	luascriptRecordBKPT = 42,
	luascriptRecordUDF = 43,
	luascriptRecordUDFS = 44,
	luascriptRecordTIME = 45,
	luascriptRecordUTAG = 46,
	luascriptRecordFLNK = 47,
	luascriptRecordSTATE = 48,
	luascriptRecordRPVT = 49,
	luascriptRecordSYNC = 50,
	luascriptRecordRELO = 51,
	luascriptRecordFRLD = 52,
	luascriptRecordERR = 53,
	luascriptRecordCODE = 54,
	luascriptRecordPCODE = 55,
	luascriptRecordCALL = 56,
	luascriptRecordOOPT = 57,
	luascriptRecordWAIT = 58,
	luascriptRecordINPA = 59,
	luascriptRecordINPB = 60,
	luascriptRecordINPC = 61,
	luascriptRecordINPD = 62,
	luascriptRecordINPE = 63,
	luascriptRecordINPF = 64,
	luascriptRecordINPG = 65,
	luascriptRecordINPH = 66,
	luascriptRecordINPI = 67,
	luascriptRecordINPJ = 68,
	luascriptRecordINAA = 69,
	luascriptRecordINBB = 70,
	luascriptRecordINCC = 71,
	luascriptRecordINDD = 72,
	luascriptRecordINEE = 73,
	luascriptRecordINFF = 74,
	luascriptRecordINGG = 75,
	luascriptRecordINHH = 76,
	luascriptRecordINII = 77,
	luascriptRecordINJJ = 78,
	luascriptRecordOUT = 79,
	luascriptRecordINAV = 80,
	luascriptRecordINBV = 81,
	luascriptRecordINCV = 82,
	luascriptRecordINDV = 83,
	luascriptRecordINEV = 84,
	luascriptRecordINFV = 85,
	luascriptRecordINGV = 86,
	luascriptRecordINHV = 87,
	luascriptRecordINIV = 88,
	luascriptRecordINJV = 89,
	luascriptRecordIAAV = 90,
	luascriptRecordIBBV = 91,
	luascriptRecordICCV = 92,
	luascriptRecordIDDV = 93,
	luascriptRecordIEEV = 94,
	luascriptRecordIFFV = 95,
	luascriptRecordIGGV = 96,
	luascriptRecordIHHV = 97,
	luascriptRecordIIIV = 98,
	luascriptRecordIJJV = 99,
	luascriptRecordOUTV = 100,
	luascriptRecordADSC = 101,
	luascriptRecordBDSC = 102,
	luascriptRecordCDSC = 103,
	luascriptRecordDDSC = 104,
	luascriptRecordEDSC = 105,
	luascriptRecordFDSC = 106,
	luascriptRecordGDSC = 107,
	luascriptRecordHDSC = 108,
	luascriptRecordIDSC = 109,
	luascriptRecordJDSC = 110,
	luascriptRecordAADN = 111,
	luascriptRecordBBDN = 112,
	luascriptRecordCCDN = 113,
	luascriptRecordDDDN = 114,
	luascriptRecordEEDN = 115,
	luascriptRecordFFDN = 116,
	luascriptRecordGGDN = 117,
	luascriptRecordHHDN = 118,
	luascriptRecordIIDN = 119,
	luascriptRecordJJDN = 120,
	luascriptRecordA = 121,
	luascriptRecordB = 122,
	luascriptRecordC = 123,
	luascriptRecordD = 124,
	luascriptRecordE = 125,
	luascriptRecordF = 126,
	luascriptRecordG = 127,
	luascriptRecordH = 128,
	luascriptRecordI = 129,
	luascriptRecordJ = 130,
	luascriptRecordAA = 131,
	luascriptRecordBB = 132,
	luascriptRecordCC = 133,
	luascriptRecordDD = 134,
	luascriptRecordEE = 135,
	luascriptRecordFF = 136,
	luascriptRecordGG = 137,
	luascriptRecordHH = 138,
	luascriptRecordII = 139,
	luascriptRecordJJ = 140,
	luascriptRecordPA = 141,
	luascriptRecordPB = 142,
	luascriptRecordPC = 143,
	luascriptRecordPD = 144,
	luascriptRecordPE = 145,
	luascriptRecordPF = 146,
	luascriptRecordPG = 147,
	luascriptRecordPH = 148,
	luascriptRecordPI = 149,
	luascriptRecordPJ = 150,
	luascriptRecordPAA = 151,
	luascriptRecordPBB = 152,
	luascriptRecordPCC = 153,
	luascriptRecordPDD = 154,
	luascriptRecordPEE = 155,
	luascriptRecordPFF = 156,
	luascriptRecordPGG = 157,
	luascriptRecordPHH = 158,
	luascriptRecordPII = 159,
	luascriptRecordPJJ = 160,
	luascriptRecordVAL = 161,
	luascriptRecordSVAL = 162,
	luascriptRecordAVAL = 163,
	luascriptRecordASIZ = 164,
	luascriptRecordATYP = 165,
	luascriptRecordPVAL = 166,
	luascriptRecordPSVL = 167,
	luascriptRecordPAVL = 168,
	luascriptRecordPASZ = 169,
	luascriptRecordPATP = 170,
	luascriptRecordMDEL = 171,
	luascriptRecordPREC = 172
} luascriptFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int luascriptRecordSizeOffset(dbRecordType *prt)
{
    luascriptRecord *prec = 0;

    if (prt->no_fields != 173) {
        cantProceed("IOC build or installation error:\n"
            "    The luascriptRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 173.\n",
            prt->no_fields);
    }
    prt->papFldDes[luascriptRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[luascriptRecordNAME]->offset = (unsigned short)offsetof(luascriptRecord, name);
    prt->papFldDes[luascriptRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[luascriptRecordDESC]->offset = (unsigned short)offsetof(luascriptRecord, desc);
    prt->papFldDes[luascriptRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[luascriptRecordASG]->offset = (unsigned short)offsetof(luascriptRecord, asg);
    prt->papFldDes[luascriptRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[luascriptRecordSCAN]->offset = (unsigned short)offsetof(luascriptRecord, scan);
    prt->papFldDes[luascriptRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[luascriptRecordPINI]->offset = (unsigned short)offsetof(luascriptRecord, pini);
    prt->papFldDes[luascriptRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[luascriptRecordPHAS]->offset = (unsigned short)offsetof(luascriptRecord, phas);
    prt->papFldDes[luascriptRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[luascriptRecordEVNT]->offset = (unsigned short)offsetof(luascriptRecord, evnt);
    prt->papFldDes[luascriptRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[luascriptRecordTSE]->offset = (unsigned short)offsetof(luascriptRecord, tse);
    prt->papFldDes[luascriptRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[luascriptRecordTSEL]->offset = (unsigned short)offsetof(luascriptRecord, tsel);
    prt->papFldDes[luascriptRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[luascriptRecordDTYP]->offset = (unsigned short)offsetof(luascriptRecord, dtyp);
    prt->papFldDes[luascriptRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[luascriptRecordDISV]->offset = (unsigned short)offsetof(luascriptRecord, disv);
    prt->papFldDes[luascriptRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[luascriptRecordDISA]->offset = (unsigned short)offsetof(luascriptRecord, disa);
    prt->papFldDes[luascriptRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[luascriptRecordSDIS]->offset = (unsigned short)offsetof(luascriptRecord, sdis);
    prt->papFldDes[luascriptRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[luascriptRecordMLOK]->offset = (unsigned short)offsetof(luascriptRecord, mlok);
    prt->papFldDes[luascriptRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[luascriptRecordMLIS]->offset = (unsigned short)offsetof(luascriptRecord, mlis);
    prt->papFldDes[luascriptRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[luascriptRecordBKLNK]->offset = (unsigned short)offsetof(luascriptRecord, bklnk);
    prt->papFldDes[luascriptRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[luascriptRecordDISP]->offset = (unsigned short)offsetof(luascriptRecord, disp);
    prt->papFldDes[luascriptRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[luascriptRecordPROC]->offset = (unsigned short)offsetof(luascriptRecord, proc);
    prt->papFldDes[luascriptRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[luascriptRecordSTAT]->offset = (unsigned short)offsetof(luascriptRecord, stat);
    prt->papFldDes[luascriptRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[luascriptRecordSEVR]->offset = (unsigned short)offsetof(luascriptRecord, sevr);
    prt->papFldDes[luascriptRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[luascriptRecordAMSG]->offset = (unsigned short)offsetof(luascriptRecord, amsg);
    prt->papFldDes[luascriptRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[luascriptRecordNSTA]->offset = (unsigned short)offsetof(luascriptRecord, nsta);
    prt->papFldDes[luascriptRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[luascriptRecordNSEV]->offset = (unsigned short)offsetof(luascriptRecord, nsev);
    prt->papFldDes[luascriptRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[luascriptRecordNAMSG]->offset = (unsigned short)offsetof(luascriptRecord, namsg);
    prt->papFldDes[luascriptRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[luascriptRecordACKS]->offset = (unsigned short)offsetof(luascriptRecord, acks);
    prt->papFldDes[luascriptRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[luascriptRecordACKT]->offset = (unsigned short)offsetof(luascriptRecord, ackt);
    prt->papFldDes[luascriptRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[luascriptRecordDISS]->offset = (unsigned short)offsetof(luascriptRecord, diss);
    prt->papFldDes[luascriptRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[luascriptRecordLCNT]->offset = (unsigned short)offsetof(luascriptRecord, lcnt);
    prt->papFldDes[luascriptRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[luascriptRecordPACT]->offset = (unsigned short)offsetof(luascriptRecord, pact);
    prt->papFldDes[luascriptRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[luascriptRecordPUTF]->offset = (unsigned short)offsetof(luascriptRecord, putf);
    prt->papFldDes[luascriptRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[luascriptRecordRPRO]->offset = (unsigned short)offsetof(luascriptRecord, rpro);
    prt->papFldDes[luascriptRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[luascriptRecordASP]->offset = (unsigned short)offsetof(luascriptRecord, asp);
    prt->papFldDes[luascriptRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[luascriptRecordPPN]->offset = (unsigned short)offsetof(luascriptRecord, ppn);
    prt->papFldDes[luascriptRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[luascriptRecordPPNR]->offset = (unsigned short)offsetof(luascriptRecord, ppnr);
    prt->papFldDes[luascriptRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[luascriptRecordSPVT]->offset = (unsigned short)offsetof(luascriptRecord, spvt);
    prt->papFldDes[luascriptRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[luascriptRecordRSET]->offset = (unsigned short)offsetof(luascriptRecord, rset);
    prt->papFldDes[luascriptRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[luascriptRecordDSET]->offset = (unsigned short)offsetof(luascriptRecord, dset);
    prt->papFldDes[luascriptRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[luascriptRecordDPVT]->offset = (unsigned short)offsetof(luascriptRecord, dpvt);
    prt->papFldDes[luascriptRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[luascriptRecordRDES]->offset = (unsigned short)offsetof(luascriptRecord, rdes);
    prt->papFldDes[luascriptRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[luascriptRecordLSET]->offset = (unsigned short)offsetof(luascriptRecord, lset);
    prt->papFldDes[luascriptRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[luascriptRecordPRIO]->offset = (unsigned short)offsetof(luascriptRecord, prio);
    prt->papFldDes[luascriptRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[luascriptRecordTPRO]->offset = (unsigned short)offsetof(luascriptRecord, tpro);
    prt->papFldDes[luascriptRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[luascriptRecordBKPT]->offset = (unsigned short)offsetof(luascriptRecord, bkpt);
    prt->papFldDes[luascriptRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[luascriptRecordUDF]->offset = (unsigned short)offsetof(luascriptRecord, udf);
    prt->papFldDes[luascriptRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[luascriptRecordUDFS]->offset = (unsigned short)offsetof(luascriptRecord, udfs);
    prt->papFldDes[luascriptRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[luascriptRecordTIME]->offset = (unsigned short)offsetof(luascriptRecord, time);
    prt->papFldDes[luascriptRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[luascriptRecordUTAG]->offset = (unsigned short)offsetof(luascriptRecord, utag);
    prt->papFldDes[luascriptRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[luascriptRecordFLNK]->offset = (unsigned short)offsetof(luascriptRecord, flnk);
    prt->papFldDes[luascriptRecordSTATE]->size = sizeof(prec->state);
    prt->papFldDes[luascriptRecordSTATE]->offset = (unsigned short)offsetof(luascriptRecord, state);
    prt->papFldDes[luascriptRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[luascriptRecordRPVT]->offset = (unsigned short)offsetof(luascriptRecord, rpvt);
    prt->papFldDes[luascriptRecordSYNC]->size = sizeof(prec->sync);
    prt->papFldDes[luascriptRecordSYNC]->offset = (unsigned short)offsetof(luascriptRecord, sync);
    prt->papFldDes[luascriptRecordRELO]->size = sizeof(prec->relo);
    prt->papFldDes[luascriptRecordRELO]->offset = (unsigned short)offsetof(luascriptRecord, relo);
    prt->papFldDes[luascriptRecordFRLD]->size = sizeof(prec->frld);
    prt->papFldDes[luascriptRecordFRLD]->offset = (unsigned short)offsetof(luascriptRecord, frld);
    prt->papFldDes[luascriptRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[luascriptRecordERR]->offset = (unsigned short)offsetof(luascriptRecord, err);
    prt->papFldDes[luascriptRecordCODE]->size = sizeof(prec->code);
    prt->papFldDes[luascriptRecordCODE]->offset = (unsigned short)offsetof(luascriptRecord, code);
    prt->papFldDes[luascriptRecordPCODE]->size = sizeof(prec->pcode);
    prt->papFldDes[luascriptRecordPCODE]->offset = (unsigned short)offsetof(luascriptRecord, pcode);
    prt->papFldDes[luascriptRecordCALL]->size = sizeof(prec->call);
    prt->papFldDes[luascriptRecordCALL]->offset = (unsigned short)offsetof(luascriptRecord, call);
    prt->papFldDes[luascriptRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[luascriptRecordOOPT]->offset = (unsigned short)offsetof(luascriptRecord, oopt);
    prt->papFldDes[luascriptRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[luascriptRecordWAIT]->offset = (unsigned short)offsetof(luascriptRecord, wait);
    prt->papFldDes[luascriptRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[luascriptRecordINPA]->offset = (unsigned short)offsetof(luascriptRecord, inpa);
    prt->papFldDes[luascriptRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[luascriptRecordINPB]->offset = (unsigned short)offsetof(luascriptRecord, inpb);
    prt->papFldDes[luascriptRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[luascriptRecordINPC]->offset = (unsigned short)offsetof(luascriptRecord, inpc);
    prt->papFldDes[luascriptRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[luascriptRecordINPD]->offset = (unsigned short)offsetof(luascriptRecord, inpd);
    prt->papFldDes[luascriptRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[luascriptRecordINPE]->offset = (unsigned short)offsetof(luascriptRecord, inpe);
    prt->papFldDes[luascriptRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[luascriptRecordINPF]->offset = (unsigned short)offsetof(luascriptRecord, inpf);
    prt->papFldDes[luascriptRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[luascriptRecordINPG]->offset = (unsigned short)offsetof(luascriptRecord, inpg);
    prt->papFldDes[luascriptRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[luascriptRecordINPH]->offset = (unsigned short)offsetof(luascriptRecord, inph);
    prt->papFldDes[luascriptRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[luascriptRecordINPI]->offset = (unsigned short)offsetof(luascriptRecord, inpi);
    prt->papFldDes[luascriptRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[luascriptRecordINPJ]->offset = (unsigned short)offsetof(luascriptRecord, inpj);
    prt->papFldDes[luascriptRecordINAA]->size = sizeof(prec->inaa);
    prt->papFldDes[luascriptRecordINAA]->offset = (unsigned short)offsetof(luascriptRecord, inaa);
    prt->papFldDes[luascriptRecordINBB]->size = sizeof(prec->inbb);
    prt->papFldDes[luascriptRecordINBB]->offset = (unsigned short)offsetof(luascriptRecord, inbb);
    prt->papFldDes[luascriptRecordINCC]->size = sizeof(prec->incc);
    prt->papFldDes[luascriptRecordINCC]->offset = (unsigned short)offsetof(luascriptRecord, incc);
    prt->papFldDes[luascriptRecordINDD]->size = sizeof(prec->indd);
    prt->papFldDes[luascriptRecordINDD]->offset = (unsigned short)offsetof(luascriptRecord, indd);
    prt->papFldDes[luascriptRecordINEE]->size = sizeof(prec->inee);
    prt->papFldDes[luascriptRecordINEE]->offset = (unsigned short)offsetof(luascriptRecord, inee);
    prt->papFldDes[luascriptRecordINFF]->size = sizeof(prec->inff);
    prt->papFldDes[luascriptRecordINFF]->offset = (unsigned short)offsetof(luascriptRecord, inff);
    prt->papFldDes[luascriptRecordINGG]->size = sizeof(prec->ingg);
    prt->papFldDes[luascriptRecordINGG]->offset = (unsigned short)offsetof(luascriptRecord, ingg);
    prt->papFldDes[luascriptRecordINHH]->size = sizeof(prec->inhh);
    prt->papFldDes[luascriptRecordINHH]->offset = (unsigned short)offsetof(luascriptRecord, inhh);
    prt->papFldDes[luascriptRecordINII]->size = sizeof(prec->inii);
    prt->papFldDes[luascriptRecordINII]->offset = (unsigned short)offsetof(luascriptRecord, inii);
    prt->papFldDes[luascriptRecordINJJ]->size = sizeof(prec->injj);
    prt->papFldDes[luascriptRecordINJJ]->offset = (unsigned short)offsetof(luascriptRecord, injj);
    prt->papFldDes[luascriptRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[luascriptRecordOUT]->offset = (unsigned short)offsetof(luascriptRecord, out);
    prt->papFldDes[luascriptRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[luascriptRecordINAV]->offset = (unsigned short)offsetof(luascriptRecord, inav);
    prt->papFldDes[luascriptRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[luascriptRecordINBV]->offset = (unsigned short)offsetof(luascriptRecord, inbv);
    prt->papFldDes[luascriptRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[luascriptRecordINCV]->offset = (unsigned short)offsetof(luascriptRecord, incv);
    prt->papFldDes[luascriptRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[luascriptRecordINDV]->offset = (unsigned short)offsetof(luascriptRecord, indv);
    prt->papFldDes[luascriptRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[luascriptRecordINEV]->offset = (unsigned short)offsetof(luascriptRecord, inev);
    prt->papFldDes[luascriptRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[luascriptRecordINFV]->offset = (unsigned short)offsetof(luascriptRecord, infv);
    prt->papFldDes[luascriptRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[luascriptRecordINGV]->offset = (unsigned short)offsetof(luascriptRecord, ingv);
    prt->papFldDes[luascriptRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[luascriptRecordINHV]->offset = (unsigned short)offsetof(luascriptRecord, inhv);
    prt->papFldDes[luascriptRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[luascriptRecordINIV]->offset = (unsigned short)offsetof(luascriptRecord, iniv);
    prt->papFldDes[luascriptRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[luascriptRecordINJV]->offset = (unsigned short)offsetof(luascriptRecord, injv);
    prt->papFldDes[luascriptRecordIAAV]->size = sizeof(prec->iaav);
    prt->papFldDes[luascriptRecordIAAV]->offset = (unsigned short)offsetof(luascriptRecord, iaav);
    prt->papFldDes[luascriptRecordIBBV]->size = sizeof(prec->ibbv);
    prt->papFldDes[luascriptRecordIBBV]->offset = (unsigned short)offsetof(luascriptRecord, ibbv);
    prt->papFldDes[luascriptRecordICCV]->size = sizeof(prec->iccv);
    prt->papFldDes[luascriptRecordICCV]->offset = (unsigned short)offsetof(luascriptRecord, iccv);
    prt->papFldDes[luascriptRecordIDDV]->size = sizeof(prec->iddv);
    prt->papFldDes[luascriptRecordIDDV]->offset = (unsigned short)offsetof(luascriptRecord, iddv);
    prt->papFldDes[luascriptRecordIEEV]->size = sizeof(prec->ieev);
    prt->papFldDes[luascriptRecordIEEV]->offset = (unsigned short)offsetof(luascriptRecord, ieev);
    prt->papFldDes[luascriptRecordIFFV]->size = sizeof(prec->iffv);
    prt->papFldDes[luascriptRecordIFFV]->offset = (unsigned short)offsetof(luascriptRecord, iffv);
    prt->papFldDes[luascriptRecordIGGV]->size = sizeof(prec->iggv);
    prt->papFldDes[luascriptRecordIGGV]->offset = (unsigned short)offsetof(luascriptRecord, iggv);
    prt->papFldDes[luascriptRecordIHHV]->size = sizeof(prec->ihhv);
    prt->papFldDes[luascriptRecordIHHV]->offset = (unsigned short)offsetof(luascriptRecord, ihhv);
    prt->papFldDes[luascriptRecordIIIV]->size = sizeof(prec->iiiv);
    prt->papFldDes[luascriptRecordIIIV]->offset = (unsigned short)offsetof(luascriptRecord, iiiv);
    prt->papFldDes[luascriptRecordIJJV]->size = sizeof(prec->ijjv);
    prt->papFldDes[luascriptRecordIJJV]->offset = (unsigned short)offsetof(luascriptRecord, ijjv);
    prt->papFldDes[luascriptRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[luascriptRecordOUTV]->offset = (unsigned short)offsetof(luascriptRecord, outv);
    prt->papFldDes[luascriptRecordADSC]->size = sizeof(prec->adsc);
    prt->papFldDes[luascriptRecordADSC]->offset = (unsigned short)offsetof(luascriptRecord, adsc);
    prt->papFldDes[luascriptRecordBDSC]->size = sizeof(prec->bdsc);
    prt->papFldDes[luascriptRecordBDSC]->offset = (unsigned short)offsetof(luascriptRecord, bdsc);
    prt->papFldDes[luascriptRecordCDSC]->size = sizeof(prec->cdsc);
    prt->papFldDes[luascriptRecordCDSC]->offset = (unsigned short)offsetof(luascriptRecord, cdsc);
    prt->papFldDes[luascriptRecordDDSC]->size = sizeof(prec->ddsc);
    prt->papFldDes[luascriptRecordDDSC]->offset = (unsigned short)offsetof(luascriptRecord, ddsc);
    prt->papFldDes[luascriptRecordEDSC]->size = sizeof(prec->edsc);
    prt->papFldDes[luascriptRecordEDSC]->offset = (unsigned short)offsetof(luascriptRecord, edsc);
    prt->papFldDes[luascriptRecordFDSC]->size = sizeof(prec->fdsc);
    prt->papFldDes[luascriptRecordFDSC]->offset = (unsigned short)offsetof(luascriptRecord, fdsc);
    prt->papFldDes[luascriptRecordGDSC]->size = sizeof(prec->gdsc);
    prt->papFldDes[luascriptRecordGDSC]->offset = (unsigned short)offsetof(luascriptRecord, gdsc);
    prt->papFldDes[luascriptRecordHDSC]->size = sizeof(prec->hdsc);
    prt->papFldDes[luascriptRecordHDSC]->offset = (unsigned short)offsetof(luascriptRecord, hdsc);
    prt->papFldDes[luascriptRecordIDSC]->size = sizeof(prec->idsc);
    prt->papFldDes[luascriptRecordIDSC]->offset = (unsigned short)offsetof(luascriptRecord, idsc);
    prt->papFldDes[luascriptRecordJDSC]->size = sizeof(prec->jdsc);
    prt->papFldDes[luascriptRecordJDSC]->offset = (unsigned short)offsetof(luascriptRecord, jdsc);
    prt->papFldDes[luascriptRecordAADN]->size = sizeof(prec->aadn);
    prt->papFldDes[luascriptRecordAADN]->offset = (unsigned short)offsetof(luascriptRecord, aadn);
    prt->papFldDes[luascriptRecordBBDN]->size = sizeof(prec->bbdn);
    prt->papFldDes[luascriptRecordBBDN]->offset = (unsigned short)offsetof(luascriptRecord, bbdn);
    prt->papFldDes[luascriptRecordCCDN]->size = sizeof(prec->ccdn);
    prt->papFldDes[luascriptRecordCCDN]->offset = (unsigned short)offsetof(luascriptRecord, ccdn);
    prt->papFldDes[luascriptRecordDDDN]->size = sizeof(prec->dddn);
    prt->papFldDes[luascriptRecordDDDN]->offset = (unsigned short)offsetof(luascriptRecord, dddn);
    prt->papFldDes[luascriptRecordEEDN]->size = sizeof(prec->eedn);
    prt->papFldDes[luascriptRecordEEDN]->offset = (unsigned short)offsetof(luascriptRecord, eedn);
    prt->papFldDes[luascriptRecordFFDN]->size = sizeof(prec->ffdn);
    prt->papFldDes[luascriptRecordFFDN]->offset = (unsigned short)offsetof(luascriptRecord, ffdn);
    prt->papFldDes[luascriptRecordGGDN]->size = sizeof(prec->ggdn);
    prt->papFldDes[luascriptRecordGGDN]->offset = (unsigned short)offsetof(luascriptRecord, ggdn);
    prt->papFldDes[luascriptRecordHHDN]->size = sizeof(prec->hhdn);
    prt->papFldDes[luascriptRecordHHDN]->offset = (unsigned short)offsetof(luascriptRecord, hhdn);
    prt->papFldDes[luascriptRecordIIDN]->size = sizeof(prec->iidn);
    prt->papFldDes[luascriptRecordIIDN]->offset = (unsigned short)offsetof(luascriptRecord, iidn);
    prt->papFldDes[luascriptRecordJJDN]->size = sizeof(prec->jjdn);
    prt->papFldDes[luascriptRecordJJDN]->offset = (unsigned short)offsetof(luascriptRecord, jjdn);
    prt->papFldDes[luascriptRecordA]->size = sizeof(prec->a);
    prt->papFldDes[luascriptRecordA]->offset = (unsigned short)offsetof(luascriptRecord, a);
    prt->papFldDes[luascriptRecordB]->size = sizeof(prec->b);
    prt->papFldDes[luascriptRecordB]->offset = (unsigned short)offsetof(luascriptRecord, b);
    prt->papFldDes[luascriptRecordC]->size = sizeof(prec->c);
    prt->papFldDes[luascriptRecordC]->offset = (unsigned short)offsetof(luascriptRecord, c);
    prt->papFldDes[luascriptRecordD]->size = sizeof(prec->d);
    prt->papFldDes[luascriptRecordD]->offset = (unsigned short)offsetof(luascriptRecord, d);
    prt->papFldDes[luascriptRecordE]->size = sizeof(prec->e);
    prt->papFldDes[luascriptRecordE]->offset = (unsigned short)offsetof(luascriptRecord, e);
    prt->papFldDes[luascriptRecordF]->size = sizeof(prec->f);
    prt->papFldDes[luascriptRecordF]->offset = (unsigned short)offsetof(luascriptRecord, f);
    prt->papFldDes[luascriptRecordG]->size = sizeof(prec->g);
    prt->papFldDes[luascriptRecordG]->offset = (unsigned short)offsetof(luascriptRecord, g);
    prt->papFldDes[luascriptRecordH]->size = sizeof(prec->h);
    prt->papFldDes[luascriptRecordH]->offset = (unsigned short)offsetof(luascriptRecord, h);
    prt->papFldDes[luascriptRecordI]->size = sizeof(prec->i);
    prt->papFldDes[luascriptRecordI]->offset = (unsigned short)offsetof(luascriptRecord, i);
    prt->papFldDes[luascriptRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[luascriptRecordJ]->offset = (unsigned short)offsetof(luascriptRecord, j);
    prt->papFldDes[luascriptRecordAA]->size = sizeof(prec->aa);
    prt->papFldDes[luascriptRecordAA]->offset = (unsigned short)offsetof(luascriptRecord, aa);
    prt->papFldDes[luascriptRecordBB]->size = sizeof(prec->bb);
    prt->papFldDes[luascriptRecordBB]->offset = (unsigned short)offsetof(luascriptRecord, bb);
    prt->papFldDes[luascriptRecordCC]->size = sizeof(prec->cc);
    prt->papFldDes[luascriptRecordCC]->offset = (unsigned short)offsetof(luascriptRecord, cc);
    prt->papFldDes[luascriptRecordDD]->size = sizeof(prec->dd);
    prt->papFldDes[luascriptRecordDD]->offset = (unsigned short)offsetof(luascriptRecord, dd);
    prt->papFldDes[luascriptRecordEE]->size = sizeof(prec->ee);
    prt->papFldDes[luascriptRecordEE]->offset = (unsigned short)offsetof(luascriptRecord, ee);
    prt->papFldDes[luascriptRecordFF]->size = sizeof(prec->ff);
    prt->papFldDes[luascriptRecordFF]->offset = (unsigned short)offsetof(luascriptRecord, ff);
    prt->papFldDes[luascriptRecordGG]->size = sizeof(prec->gg);
    prt->papFldDes[luascriptRecordGG]->offset = (unsigned short)offsetof(luascriptRecord, gg);
    prt->papFldDes[luascriptRecordHH]->size = sizeof(prec->hh);
    prt->papFldDes[luascriptRecordHH]->offset = (unsigned short)offsetof(luascriptRecord, hh);
    prt->papFldDes[luascriptRecordII]->size = sizeof(prec->ii);
    prt->papFldDes[luascriptRecordII]->offset = (unsigned short)offsetof(luascriptRecord, ii);
    prt->papFldDes[luascriptRecordJJ]->size = sizeof(prec->jj);
    prt->papFldDes[luascriptRecordJJ]->offset = (unsigned short)offsetof(luascriptRecord, jj);
    prt->papFldDes[luascriptRecordPA]->size = sizeof(prec->pa);
    prt->papFldDes[luascriptRecordPA]->offset = (unsigned short)offsetof(luascriptRecord, pa);
    prt->papFldDes[luascriptRecordPB]->size = sizeof(prec->pb);
    prt->papFldDes[luascriptRecordPB]->offset = (unsigned short)offsetof(luascriptRecord, pb);
    prt->papFldDes[luascriptRecordPC]->size = sizeof(prec->pc);
    prt->papFldDes[luascriptRecordPC]->offset = (unsigned short)offsetof(luascriptRecord, pc);
    prt->papFldDes[luascriptRecordPD]->size = sizeof(prec->pd);
    prt->papFldDes[luascriptRecordPD]->offset = (unsigned short)offsetof(luascriptRecord, pd);
    prt->papFldDes[luascriptRecordPE]->size = sizeof(prec->pe);
    prt->papFldDes[luascriptRecordPE]->offset = (unsigned short)offsetof(luascriptRecord, pe);
    prt->papFldDes[luascriptRecordPF]->size = sizeof(prec->pf);
    prt->papFldDes[luascriptRecordPF]->offset = (unsigned short)offsetof(luascriptRecord, pf);
    prt->papFldDes[luascriptRecordPG]->size = sizeof(prec->pg);
    prt->papFldDes[luascriptRecordPG]->offset = (unsigned short)offsetof(luascriptRecord, pg);
    prt->papFldDes[luascriptRecordPH]->size = sizeof(prec->ph);
    prt->papFldDes[luascriptRecordPH]->offset = (unsigned short)offsetof(luascriptRecord, ph);
    prt->papFldDes[luascriptRecordPI]->size = sizeof(prec->pi);
    prt->papFldDes[luascriptRecordPI]->offset = (unsigned short)offsetof(luascriptRecord, pi);
    prt->papFldDes[luascriptRecordPJ]->size = sizeof(prec->pj);
    prt->papFldDes[luascriptRecordPJ]->offset = (unsigned short)offsetof(luascriptRecord, pj);
    prt->papFldDes[luascriptRecordPAA]->size = sizeof(prec->paa);
    prt->papFldDes[luascriptRecordPAA]->offset = (unsigned short)offsetof(luascriptRecord, paa);
    prt->papFldDes[luascriptRecordPBB]->size = sizeof(prec->pbb);
    prt->papFldDes[luascriptRecordPBB]->offset = (unsigned short)offsetof(luascriptRecord, pbb);
    prt->papFldDes[luascriptRecordPCC]->size = sizeof(prec->pcc);
    prt->papFldDes[luascriptRecordPCC]->offset = (unsigned short)offsetof(luascriptRecord, pcc);
    prt->papFldDes[luascriptRecordPDD]->size = sizeof(prec->pdd);
    prt->papFldDes[luascriptRecordPDD]->offset = (unsigned short)offsetof(luascriptRecord, pdd);
    prt->papFldDes[luascriptRecordPEE]->size = sizeof(prec->pee);
    prt->papFldDes[luascriptRecordPEE]->offset = (unsigned short)offsetof(luascriptRecord, pee);
    prt->papFldDes[luascriptRecordPFF]->size = sizeof(prec->pff);
    prt->papFldDes[luascriptRecordPFF]->offset = (unsigned short)offsetof(luascriptRecord, pff);
    prt->papFldDes[luascriptRecordPGG]->size = sizeof(prec->pgg);
    prt->papFldDes[luascriptRecordPGG]->offset = (unsigned short)offsetof(luascriptRecord, pgg);
    prt->papFldDes[luascriptRecordPHH]->size = sizeof(prec->phh);
    prt->papFldDes[luascriptRecordPHH]->offset = (unsigned short)offsetof(luascriptRecord, phh);
    prt->papFldDes[luascriptRecordPII]->size = sizeof(prec->pii);
    prt->papFldDes[luascriptRecordPII]->offset = (unsigned short)offsetof(luascriptRecord, pii);
    prt->papFldDes[luascriptRecordPJJ]->size = sizeof(prec->pjj);
    prt->papFldDes[luascriptRecordPJJ]->offset = (unsigned short)offsetof(luascriptRecord, pjj);
    prt->papFldDes[luascriptRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[luascriptRecordVAL]->offset = (unsigned short)offsetof(luascriptRecord, val);
    prt->papFldDes[luascriptRecordSVAL]->size = sizeof(prec->sval);
    prt->papFldDes[luascriptRecordSVAL]->offset = (unsigned short)offsetof(luascriptRecord, sval);
    prt->papFldDes[luascriptRecordAVAL]->size = sizeof(prec->aval);
    prt->papFldDes[luascriptRecordAVAL]->offset = (unsigned short)offsetof(luascriptRecord, aval);
    prt->papFldDes[luascriptRecordASIZ]->size = sizeof(prec->asiz);
    prt->papFldDes[luascriptRecordASIZ]->offset = (unsigned short)offsetof(luascriptRecord, asiz);
    prt->papFldDes[luascriptRecordATYP]->size = sizeof(prec->atyp);
    prt->papFldDes[luascriptRecordATYP]->offset = (unsigned short)offsetof(luascriptRecord, atyp);
    prt->papFldDes[luascriptRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[luascriptRecordPVAL]->offset = (unsigned short)offsetof(luascriptRecord, pval);
    prt->papFldDes[luascriptRecordPSVL]->size = sizeof(prec->psvl);
    prt->papFldDes[luascriptRecordPSVL]->offset = (unsigned short)offsetof(luascriptRecord, psvl);
    prt->papFldDes[luascriptRecordPAVL]->size = sizeof(prec->pavl);
    prt->papFldDes[luascriptRecordPAVL]->offset = (unsigned short)offsetof(luascriptRecord, pavl);
    prt->papFldDes[luascriptRecordPASZ]->size = sizeof(prec->pasz);
    prt->papFldDes[luascriptRecordPASZ]->offset = (unsigned short)offsetof(luascriptRecord, pasz);
    prt->papFldDes[luascriptRecordPATP]->size = sizeof(prec->patp);
    prt->papFldDes[luascriptRecordPATP]->offset = (unsigned short)offsetof(luascriptRecord, patp);
    prt->papFldDes[luascriptRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[luascriptRecordMDEL]->offset = (unsigned short)offsetof(luascriptRecord, mdel);
    prt->papFldDes[luascriptRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[luascriptRecordPREC]->offset = (unsigned short)offsetof(luascriptRecord, prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(luascriptRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_luascriptRecord_H */
