/** @file swaitRecord.h
 * @brief Declarations for the @ref swaitRecord "swait" record type.
 *
 * This header was generated from swaitRecord.dbd
 */

#ifndef INC_swaitRecord_H
#define INC_swaitRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef swaitDOPT_NUM_CHOICES
/** @brief Enumerated type from menu swaitDOPT */
typedef enum {
    swaitDOPT_Use_VAL               /**< @brief State string "Use VAL" */,
    swaitDOPT_Use_DOL               /**< @brief State string "Use DOL" */
} swaitDOPT;
/** @brief Number of states defined for menu swaitDOPT */
#define swaitDOPT_NUM_CHOICES 2
#endif

#ifndef swaitINAP_NUM_CHOICES
/** @brief Enumerated type from menu swaitINAP */
typedef enum {
    swaitINAP_No                    /**< @brief State string "No" */,
    swaitINAP_Yes                   /**< @brief State string "Yes" */
} swaitINAP;
/** @brief Number of states defined for menu swaitINAP */
#define swaitINAP_NUM_CHOICES 2
#endif

#ifndef swaitINAV_NUM_CHOICES
/** @brief Enumerated type from menu swaitINAV */
typedef enum {
    swaitINAV_PV_OK                 /**< @brief State string "PV OK" */,
    swaitINAV_PV_BAD                /**< @brief State string "PV BAD" */,
    swaitINAV_No_PV                 /**< @brief State string "No PV" */
} swaitINAV;
/** @brief Number of states defined for menu swaitINAV */
#define swaitINAV_NUM_CHOICES 3
#endif

#ifndef swaitOOPT_NUM_CHOICES
/** @brief Enumerated type from menu swaitOOPT */
typedef enum {
    swaitOOPT_Every_Time            /**< @brief State string "Every Time" */,
    swaitOOPT_On_Change             /**< @brief State string "On Change" */,
    swaitOOPT_When_Zero             /**< @brief State string "When Zero" */,
    swaitOOPT_When_Non_zero         /**< @brief State string "When Non-zero" */,
    swaitOOPT_Transition_To_Zero    /**< @brief State string "Transition To Zero" */,
    swaitOOPT_Transition_To_Non_zero /**< @brief State string "Transition To Non-zero" */,
    swaitOOPT_Never                 /**< @brief State string "Never" */
} swaitOOPT;
/** @brief Number of states defined for menu swaitOOPT */
#define swaitOOPT_NUM_CHOICES 7
#endif

/** @brief Declaration of swait record type. */
typedef struct swaitRecord {
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
    epicsFloat32        vers;       /**< @brief Code Version */
    epicsFloat32        hopr;       /**< @brief High Operating Range */
    epicsFloat32        lopr;       /**< @brief Low Operating Range */
    epicsInt16          init;       /**< @brief Initialized? */
    void *         cbst;            /**< @brief Pointer to cbStruct */
    char                inan[40];   /**< @brief INPA PV Name */
    char                inbn[40];   /**< @brief INPB PV Name */
    char                incn[40];   /**< @brief INPC PV Name */
    char                indn[40];   /**< @brief INPD PV Name */
    char                inen[40];   /**< @brief INPE PV Name */
    char                infn[40];   /**< @brief INPF PV Name */
    char                ingn[40];   /**< @brief INPG PV Name */
    char                inhn[40];   /**< @brief INPH PV Name */
    char                inin[40];   /**< @brief INPI PV Name */
    char                injn[40];   /**< @brief INPJ PV Name */
    char                inkn[40];   /**< @brief INPK PV Name */
    char                inln[40];   /**< @brief INPL PV Name */
    char                doln[40];   /**< @brief DOL  PV Name */
    char                outn[40];   /**< @brief OUT  PV Name */
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
    epicsEnum16         dolv;       /**< @brief DOL  PV Status */
    epicsEnum16         outv;       /**< @brief OUT  PV Status */
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
    epicsFloat64        la;         /**< @brief Last Val of Input A */
    epicsFloat64        lb;         /**< @brief Last Val of Input B */
    epicsFloat64        lc;         /**< @brief Last Val of Input C */
    epicsFloat64        ld;         /**< @brief Last Val of Input D */
    epicsFloat64        le;         /**< @brief Last Val of Input E */
    epicsFloat64        lf;         /**< @brief Last Val of Input F */
    epicsFloat64        lg;         /**< @brief Last Val of Input G */
    epicsFloat64        lh;         /**< @brief Last Val of Input H */
    epicsFloat64        li;         /**< @brief Last Val of Input I */
    epicsFloat64        lj;         /**< @brief Last Val of Input J */
    epicsFloat64        lk;         /**< @brief Last Val of Input K */
    epicsFloat64        ll;         /**< @brief Last Val of Input L */
    epicsEnum16         inap;       /**< @brief INPA causes I/O INTR */
    epicsEnum16         inbp;       /**< @brief INPB causes I/O INTR */
    epicsEnum16         incp;       /**< @brief INPC causes I/O INTR */
    epicsEnum16         indp;       /**< @brief INPD causes I/O INTR */
    epicsEnum16         inep;       /**< @brief INPE causes I/O INTR */
    epicsEnum16         infp;       /**< @brief INPF causes I/O INTR */
    epicsEnum16         ingp;       /**< @brief INPG causes I/O INTR */
    epicsEnum16         inhp;       /**< @brief INPH causes I/O INTR */
    epicsEnum16         inip;       /**< @brief INPI causes I/O INTR */
    epicsEnum16         injp;       /**< @brief INPJ causes I/O INTR */
    epicsEnum16         inkp;       /**< @brief INPK causes I/O INTR */
    epicsEnum16         inlp;       /**< @brief INPL causes I/O INTR */
    char                calc[36];   /**< @brief Calculation */
    char    rpcl[184];              /**< @brief Reverse Polish Calc */
    epicsInt32          clcv;       /**< @brief CALC Valid */
    epicsFloat64        val;        /**< @brief Value Field */
    epicsFloat64        oval;       /**< @brief Old Value */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsEnum16         oopt;       /**< @brief Output Execute Opt */
    epicsFloat32        odly;       /**< @brief Output Execute Delay */
    epicsEnum16         dopt;       /**< @brief Output Data Option */
    epicsFloat64        dold;       /**< @brief Desired Output Data */
    epicsUInt16         oevt;       /**< @brief Event To Issue */
    epicsFloat64        adel;       /**< @brief Archive Deadband */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsFloat64        alst;       /**< @brief Last Value Archived */
    epicsFloat64        mlst;       /**< @brief Last Val Monitored */
    DBLINK              siol;       /**< @brief Sim Input Specifctn */
    epicsFloat64        sval;       /**< @brief Simulation Value */
    DBLINK              siml;       /**< @brief Sim Mode Location */
    epicsEnum16         simm;       /**< @brief Simulation Mode */
    epicsEnum16         sims;       /**< @brief Sim mode Alarm Svrty */
} swaitRecord;

typedef enum {
	swaitRecordNAME = 0,
	swaitRecordDESC = 1,
	swaitRecordASG = 2,
	swaitRecordSCAN = 3,
	swaitRecordPINI = 4,
	swaitRecordPHAS = 5,
	swaitRecordEVNT = 6,
	swaitRecordTSE = 7,
	swaitRecordTSEL = 8,
	swaitRecordDTYP = 9,
	swaitRecordDISV = 10,
	swaitRecordDISA = 11,
	swaitRecordSDIS = 12,
	swaitRecordMLOK = 13,
	swaitRecordMLIS = 14,
	swaitRecordBKLNK = 15,
	swaitRecordDISP = 16,
	swaitRecordPROC = 17,
	swaitRecordSTAT = 18,
	swaitRecordSEVR = 19,
	swaitRecordAMSG = 20,
	swaitRecordNSTA = 21,
	swaitRecordNSEV = 22,
	swaitRecordNAMSG = 23,
	swaitRecordACKS = 24,
	swaitRecordACKT = 25,
	swaitRecordDISS = 26,
	swaitRecordLCNT = 27,
	swaitRecordPACT = 28,
	swaitRecordPUTF = 29,
	swaitRecordRPRO = 30,
	swaitRecordASP = 31,
	swaitRecordPPN = 32,
	swaitRecordPPNR = 33,
	swaitRecordSPVT = 34,
	swaitRecordRSET = 35,
	swaitRecordDSET = 36,
	swaitRecordDPVT = 37,
	swaitRecordRDES = 38,
	swaitRecordLSET = 39,
	swaitRecordPRIO = 40,
	swaitRecordTPRO = 41,
	swaitRecordBKPT = 42,
	swaitRecordUDF = 43,
	swaitRecordUDFS = 44,
	swaitRecordTIME = 45,
	swaitRecordUTAG = 46,
	swaitRecordFLNK = 47,
	swaitRecordVERS = 48,
	swaitRecordHOPR = 49,
	swaitRecordLOPR = 50,
	swaitRecordINIT = 51,
	swaitRecordCBST = 52,
	swaitRecordINAN = 53,
	swaitRecordINBN = 54,
	swaitRecordINCN = 55,
	swaitRecordINDN = 56,
	swaitRecordINEN = 57,
	swaitRecordINFN = 58,
	swaitRecordINGN = 59,
	swaitRecordINHN = 60,
	swaitRecordININ = 61,
	swaitRecordINJN = 62,
	swaitRecordINKN = 63,
	swaitRecordINLN = 64,
	swaitRecordDOLN = 65,
	swaitRecordOUTN = 66,
	swaitRecordINAV = 67,
	swaitRecordINBV = 68,
	swaitRecordINCV = 69,
	swaitRecordINDV = 70,
	swaitRecordINEV = 71,
	swaitRecordINFV = 72,
	swaitRecordINGV = 73,
	swaitRecordINHV = 74,
	swaitRecordINIV = 75,
	swaitRecordINJV = 76,
	swaitRecordINKV = 77,
	swaitRecordINLV = 78,
	swaitRecordDOLV = 79,
	swaitRecordOUTV = 80,
	swaitRecordA = 81,
	swaitRecordB = 82,
	swaitRecordC = 83,
	swaitRecordD = 84,
	swaitRecordE = 85,
	swaitRecordF = 86,
	swaitRecordG = 87,
	swaitRecordH = 88,
	swaitRecordI = 89,
	swaitRecordJ = 90,
	swaitRecordK = 91,
	swaitRecordL = 92,
	swaitRecordLA = 93,
	swaitRecordLB = 94,
	swaitRecordLC = 95,
	swaitRecordLD = 96,
	swaitRecordLE = 97,
	swaitRecordLF = 98,
	swaitRecordLG = 99,
	swaitRecordLH = 100,
	swaitRecordLI = 101,
	swaitRecordLJ = 102,
	swaitRecordLK = 103,
	swaitRecordLL = 104,
	swaitRecordINAP = 105,
	swaitRecordINBP = 106,
	swaitRecordINCP = 107,
	swaitRecordINDP = 108,
	swaitRecordINEP = 109,
	swaitRecordINFP = 110,
	swaitRecordINGP = 111,
	swaitRecordINHP = 112,
	swaitRecordINIP = 113,
	swaitRecordINJP = 114,
	swaitRecordINKP = 115,
	swaitRecordINLP = 116,
	swaitRecordCALC = 117,
	swaitRecordRPCL = 118,
	swaitRecordCLCV = 119,
	swaitRecordVAL = 120,
	swaitRecordOVAL = 121,
	swaitRecordPREC = 122,
	swaitRecordOOPT = 123,
	swaitRecordODLY = 124,
	swaitRecordDOPT = 125,
	swaitRecordDOLD = 126,
	swaitRecordOEVT = 127,
	swaitRecordADEL = 128,
	swaitRecordMDEL = 129,
	swaitRecordALST = 130,
	swaitRecordMLST = 131,
	swaitRecordSIOL = 132,
	swaitRecordSVAL = 133,
	swaitRecordSIML = 134,
	swaitRecordSIMM = 135,
	swaitRecordSIMS = 136
} swaitFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int swaitRecordSizeOffset(dbRecordType *prt)
{
    swaitRecord *prec = 0;

    if (prt->no_fields != 137) {
        cantProceed("IOC build or installation error:\n"
            "    The swaitRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 137.\n",
            prt->no_fields);
    }
    prt->papFldDes[swaitRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[swaitRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[swaitRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[swaitRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[swaitRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[swaitRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[swaitRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[swaitRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[swaitRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[swaitRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[swaitRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[swaitRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[swaitRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[swaitRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[swaitRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[swaitRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[swaitRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[swaitRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[swaitRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[swaitRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[swaitRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[swaitRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[swaitRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[swaitRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[swaitRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[swaitRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[swaitRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[swaitRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[swaitRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[swaitRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[swaitRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[swaitRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[swaitRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[swaitRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[swaitRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[swaitRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[swaitRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[swaitRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[swaitRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[swaitRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[swaitRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[swaitRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[swaitRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[swaitRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[swaitRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[swaitRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[swaitRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[swaitRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[swaitRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[swaitRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[swaitRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[swaitRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[swaitRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[swaitRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[swaitRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[swaitRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[swaitRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[swaitRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[swaitRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[swaitRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[swaitRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[swaitRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[swaitRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[swaitRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[swaitRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[swaitRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[swaitRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[swaitRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[swaitRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[swaitRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[swaitRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[swaitRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[swaitRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[swaitRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[swaitRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[swaitRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[swaitRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[swaitRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[swaitRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[swaitRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[swaitRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[swaitRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[swaitRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[swaitRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[swaitRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[swaitRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[swaitRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[swaitRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[swaitRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[swaitRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[swaitRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[swaitRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[swaitRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[swaitRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[swaitRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[swaitRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[swaitRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[swaitRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[swaitRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[swaitRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[swaitRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[swaitRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[swaitRecordINIT]->size = sizeof(prec->init);
    prt->papFldDes[swaitRecordINIT]->offset = (unsigned short)((char *)&prec->init - (char *)prec);
    prt->papFldDes[swaitRecordCBST]->size = sizeof(prec->cbst);
    prt->papFldDes[swaitRecordCBST]->offset = (unsigned short)((char *)&prec->cbst - (char *)prec);
    prt->papFldDes[swaitRecordINAN]->size = sizeof(prec->inan);
    prt->papFldDes[swaitRecordINAN]->offset = (unsigned short)((char *)&prec->inan - (char *)prec);
    prt->papFldDes[swaitRecordINBN]->size = sizeof(prec->inbn);
    prt->papFldDes[swaitRecordINBN]->offset = (unsigned short)((char *)&prec->inbn - (char *)prec);
    prt->papFldDes[swaitRecordINCN]->size = sizeof(prec->incn);
    prt->papFldDes[swaitRecordINCN]->offset = (unsigned short)((char *)&prec->incn - (char *)prec);
    prt->papFldDes[swaitRecordINDN]->size = sizeof(prec->indn);
    prt->papFldDes[swaitRecordINDN]->offset = (unsigned short)((char *)&prec->indn - (char *)prec);
    prt->papFldDes[swaitRecordINEN]->size = sizeof(prec->inen);
    prt->papFldDes[swaitRecordINEN]->offset = (unsigned short)((char *)&prec->inen - (char *)prec);
    prt->papFldDes[swaitRecordINFN]->size = sizeof(prec->infn);
    prt->papFldDes[swaitRecordINFN]->offset = (unsigned short)((char *)&prec->infn - (char *)prec);
    prt->papFldDes[swaitRecordINGN]->size = sizeof(prec->ingn);
    prt->papFldDes[swaitRecordINGN]->offset = (unsigned short)((char *)&prec->ingn - (char *)prec);
    prt->papFldDes[swaitRecordINHN]->size = sizeof(prec->inhn);
    prt->papFldDes[swaitRecordINHN]->offset = (unsigned short)((char *)&prec->inhn - (char *)prec);
    prt->papFldDes[swaitRecordININ]->size = sizeof(prec->inin);
    prt->papFldDes[swaitRecordININ]->offset = (unsigned short)((char *)&prec->inin - (char *)prec);
    prt->papFldDes[swaitRecordINJN]->size = sizeof(prec->injn);
    prt->papFldDes[swaitRecordINJN]->offset = (unsigned short)((char *)&prec->injn - (char *)prec);
    prt->papFldDes[swaitRecordINKN]->size = sizeof(prec->inkn);
    prt->papFldDes[swaitRecordINKN]->offset = (unsigned short)((char *)&prec->inkn - (char *)prec);
    prt->papFldDes[swaitRecordINLN]->size = sizeof(prec->inln);
    prt->papFldDes[swaitRecordINLN]->offset = (unsigned short)((char *)&prec->inln - (char *)prec);
    prt->papFldDes[swaitRecordDOLN]->size = sizeof(prec->doln);
    prt->papFldDes[swaitRecordDOLN]->offset = (unsigned short)((char *)&prec->doln - (char *)prec);
    prt->papFldDes[swaitRecordOUTN]->size = sizeof(prec->outn);
    prt->papFldDes[swaitRecordOUTN]->offset = (unsigned short)((char *)&prec->outn - (char *)prec);
    prt->papFldDes[swaitRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[swaitRecordINAV]->offset = (unsigned short)((char *)&prec->inav - (char *)prec);
    prt->papFldDes[swaitRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[swaitRecordINBV]->offset = (unsigned short)((char *)&prec->inbv - (char *)prec);
    prt->papFldDes[swaitRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[swaitRecordINCV]->offset = (unsigned short)((char *)&prec->incv - (char *)prec);
    prt->papFldDes[swaitRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[swaitRecordINDV]->offset = (unsigned short)((char *)&prec->indv - (char *)prec);
    prt->papFldDes[swaitRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[swaitRecordINEV]->offset = (unsigned short)((char *)&prec->inev - (char *)prec);
    prt->papFldDes[swaitRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[swaitRecordINFV]->offset = (unsigned short)((char *)&prec->infv - (char *)prec);
    prt->papFldDes[swaitRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[swaitRecordINGV]->offset = (unsigned short)((char *)&prec->ingv - (char *)prec);
    prt->papFldDes[swaitRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[swaitRecordINHV]->offset = (unsigned short)((char *)&prec->inhv - (char *)prec);
    prt->papFldDes[swaitRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[swaitRecordINIV]->offset = (unsigned short)((char *)&prec->iniv - (char *)prec);
    prt->papFldDes[swaitRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[swaitRecordINJV]->offset = (unsigned short)((char *)&prec->injv - (char *)prec);
    prt->papFldDes[swaitRecordINKV]->size = sizeof(prec->inkv);
    prt->papFldDes[swaitRecordINKV]->offset = (unsigned short)((char *)&prec->inkv - (char *)prec);
    prt->papFldDes[swaitRecordINLV]->size = sizeof(prec->inlv);
    prt->papFldDes[swaitRecordINLV]->offset = (unsigned short)((char *)&prec->inlv - (char *)prec);
    prt->papFldDes[swaitRecordDOLV]->size = sizeof(prec->dolv);
    prt->papFldDes[swaitRecordDOLV]->offset = (unsigned short)((char *)&prec->dolv - (char *)prec);
    prt->papFldDes[swaitRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[swaitRecordOUTV]->offset = (unsigned short)((char *)&prec->outv - (char *)prec);
    prt->papFldDes[swaitRecordA]->size = sizeof(prec->a);
    prt->papFldDes[swaitRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[swaitRecordB]->size = sizeof(prec->b);
    prt->papFldDes[swaitRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[swaitRecordC]->size = sizeof(prec->c);
    prt->papFldDes[swaitRecordC]->offset = (unsigned short)((char *)&prec->c - (char *)prec);
    prt->papFldDes[swaitRecordD]->size = sizeof(prec->d);
    prt->papFldDes[swaitRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[swaitRecordE]->size = sizeof(prec->e);
    prt->papFldDes[swaitRecordE]->offset = (unsigned short)((char *)&prec->e - (char *)prec);
    prt->papFldDes[swaitRecordF]->size = sizeof(prec->f);
    prt->papFldDes[swaitRecordF]->offset = (unsigned short)((char *)&prec->f - (char *)prec);
    prt->papFldDes[swaitRecordG]->size = sizeof(prec->g);
    prt->papFldDes[swaitRecordG]->offset = (unsigned short)((char *)&prec->g - (char *)prec);
    prt->papFldDes[swaitRecordH]->size = sizeof(prec->h);
    prt->papFldDes[swaitRecordH]->offset = (unsigned short)((char *)&prec->h - (char *)prec);
    prt->papFldDes[swaitRecordI]->size = sizeof(prec->i);
    prt->papFldDes[swaitRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[swaitRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[swaitRecordJ]->offset = (unsigned short)((char *)&prec->j - (char *)prec);
    prt->papFldDes[swaitRecordK]->size = sizeof(prec->k);
    prt->papFldDes[swaitRecordK]->offset = (unsigned short)((char *)&prec->k - (char *)prec);
    prt->papFldDes[swaitRecordL]->size = sizeof(prec->l);
    prt->papFldDes[swaitRecordL]->offset = (unsigned short)((char *)&prec->l - (char *)prec);
    prt->papFldDes[swaitRecordLA]->size = sizeof(prec->la);
    prt->papFldDes[swaitRecordLA]->offset = (unsigned short)((char *)&prec->la - (char *)prec);
    prt->papFldDes[swaitRecordLB]->size = sizeof(prec->lb);
    prt->papFldDes[swaitRecordLB]->offset = (unsigned short)((char *)&prec->lb - (char *)prec);
    prt->papFldDes[swaitRecordLC]->size = sizeof(prec->lc);
    prt->papFldDes[swaitRecordLC]->offset = (unsigned short)((char *)&prec->lc - (char *)prec);
    prt->papFldDes[swaitRecordLD]->size = sizeof(prec->ld);
    prt->papFldDes[swaitRecordLD]->offset = (unsigned short)((char *)&prec->ld - (char *)prec);
    prt->papFldDes[swaitRecordLE]->size = sizeof(prec->le);
    prt->papFldDes[swaitRecordLE]->offset = (unsigned short)((char *)&prec->le - (char *)prec);
    prt->papFldDes[swaitRecordLF]->size = sizeof(prec->lf);
    prt->papFldDes[swaitRecordLF]->offset = (unsigned short)((char *)&prec->lf - (char *)prec);
    prt->papFldDes[swaitRecordLG]->size = sizeof(prec->lg);
    prt->papFldDes[swaitRecordLG]->offset = (unsigned short)((char *)&prec->lg - (char *)prec);
    prt->papFldDes[swaitRecordLH]->size = sizeof(prec->lh);
    prt->papFldDes[swaitRecordLH]->offset = (unsigned short)((char *)&prec->lh - (char *)prec);
    prt->papFldDes[swaitRecordLI]->size = sizeof(prec->li);
    prt->papFldDes[swaitRecordLI]->offset = (unsigned short)((char *)&prec->li - (char *)prec);
    prt->papFldDes[swaitRecordLJ]->size = sizeof(prec->lj);
    prt->papFldDes[swaitRecordLJ]->offset = (unsigned short)((char *)&prec->lj - (char *)prec);
    prt->papFldDes[swaitRecordLK]->size = sizeof(prec->lk);
    prt->papFldDes[swaitRecordLK]->offset = (unsigned short)((char *)&prec->lk - (char *)prec);
    prt->papFldDes[swaitRecordLL]->size = sizeof(prec->ll);
    prt->papFldDes[swaitRecordLL]->offset = (unsigned short)((char *)&prec->ll - (char *)prec);
    prt->papFldDes[swaitRecordINAP]->size = sizeof(prec->inap);
    prt->papFldDes[swaitRecordINAP]->offset = (unsigned short)((char *)&prec->inap - (char *)prec);
    prt->papFldDes[swaitRecordINBP]->size = sizeof(prec->inbp);
    prt->papFldDes[swaitRecordINBP]->offset = (unsigned short)((char *)&prec->inbp - (char *)prec);
    prt->papFldDes[swaitRecordINCP]->size = sizeof(prec->incp);
    prt->papFldDes[swaitRecordINCP]->offset = (unsigned short)((char *)&prec->incp - (char *)prec);
    prt->papFldDes[swaitRecordINDP]->size = sizeof(prec->indp);
    prt->papFldDes[swaitRecordINDP]->offset = (unsigned short)((char *)&prec->indp - (char *)prec);
    prt->papFldDes[swaitRecordINEP]->size = sizeof(prec->inep);
    prt->papFldDes[swaitRecordINEP]->offset = (unsigned short)((char *)&prec->inep - (char *)prec);
    prt->papFldDes[swaitRecordINFP]->size = sizeof(prec->infp);
    prt->papFldDes[swaitRecordINFP]->offset = (unsigned short)((char *)&prec->infp - (char *)prec);
    prt->papFldDes[swaitRecordINGP]->size = sizeof(prec->ingp);
    prt->papFldDes[swaitRecordINGP]->offset = (unsigned short)((char *)&prec->ingp - (char *)prec);
    prt->papFldDes[swaitRecordINHP]->size = sizeof(prec->inhp);
    prt->papFldDes[swaitRecordINHP]->offset = (unsigned short)((char *)&prec->inhp - (char *)prec);
    prt->papFldDes[swaitRecordINIP]->size = sizeof(prec->inip);
    prt->papFldDes[swaitRecordINIP]->offset = (unsigned short)((char *)&prec->inip - (char *)prec);
    prt->papFldDes[swaitRecordINJP]->size = sizeof(prec->injp);
    prt->papFldDes[swaitRecordINJP]->offset = (unsigned short)((char *)&prec->injp - (char *)prec);
    prt->papFldDes[swaitRecordINKP]->size = sizeof(prec->inkp);
    prt->papFldDes[swaitRecordINKP]->offset = (unsigned short)((char *)&prec->inkp - (char *)prec);
    prt->papFldDes[swaitRecordINLP]->size = sizeof(prec->inlp);
    prt->papFldDes[swaitRecordINLP]->offset = (unsigned short)((char *)&prec->inlp - (char *)prec);
    prt->papFldDes[swaitRecordCALC]->size = sizeof(prec->calc);
    prt->papFldDes[swaitRecordCALC]->offset = (unsigned short)((char *)&prec->calc - (char *)prec);
    prt->papFldDes[swaitRecordRPCL]->size = sizeof(prec->rpcl);
    prt->papFldDes[swaitRecordRPCL]->offset = (unsigned short)((char *)&prec->rpcl - (char *)prec);
    prt->papFldDes[swaitRecordCLCV]->size = sizeof(prec->clcv);
    prt->papFldDes[swaitRecordCLCV]->offset = (unsigned short)((char *)&prec->clcv - (char *)prec);
    prt->papFldDes[swaitRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[swaitRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[swaitRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[swaitRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[swaitRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[swaitRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[swaitRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[swaitRecordOOPT]->offset = (unsigned short)((char *)&prec->oopt - (char *)prec);
    prt->papFldDes[swaitRecordODLY]->size = sizeof(prec->odly);
    prt->papFldDes[swaitRecordODLY]->offset = (unsigned short)((char *)&prec->odly - (char *)prec);
    prt->papFldDes[swaitRecordDOPT]->size = sizeof(prec->dopt);
    prt->papFldDes[swaitRecordDOPT]->offset = (unsigned short)((char *)&prec->dopt - (char *)prec);
    prt->papFldDes[swaitRecordDOLD]->size = sizeof(prec->dold);
    prt->papFldDes[swaitRecordDOLD]->offset = (unsigned short)((char *)&prec->dold - (char *)prec);
    prt->papFldDes[swaitRecordOEVT]->size = sizeof(prec->oevt);
    prt->papFldDes[swaitRecordOEVT]->offset = (unsigned short)((char *)&prec->oevt - (char *)prec);
    prt->papFldDes[swaitRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[swaitRecordADEL]->offset = (unsigned short)((char *)&prec->adel - (char *)prec);
    prt->papFldDes[swaitRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[swaitRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[swaitRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[swaitRecordALST]->offset = (unsigned short)((char *)&prec->alst - (char *)prec);
    prt->papFldDes[swaitRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[swaitRecordMLST]->offset = (unsigned short)((char *)&prec->mlst - (char *)prec);
    prt->papFldDes[swaitRecordSIOL]->size = sizeof(prec->siol);
    prt->papFldDes[swaitRecordSIOL]->offset = (unsigned short)((char *)&prec->siol - (char *)prec);
    prt->papFldDes[swaitRecordSVAL]->size = sizeof(prec->sval);
    prt->papFldDes[swaitRecordSVAL]->offset = (unsigned short)((char *)&prec->sval - (char *)prec);
    prt->papFldDes[swaitRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[swaitRecordSIML]->offset = (unsigned short)((char *)&prec->siml - (char *)prec);
    prt->papFldDes[swaitRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[swaitRecordSIMM]->offset = (unsigned short)((char *)&prec->simm - (char *)prec);
    prt->papFldDes[swaitRecordSIMS]->size = sizeof(prec->sims);
    prt->papFldDes[swaitRecordSIMS]->offset = (unsigned short)((char *)&prec->sims - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(swaitRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_swaitRecord_H */
