/** @file throttleRecord.h
 * @brief Declarations for the @ref throttleRecord "throttle" record type.
 *
 * This header was generated from throttleRecord.dbd
 */

#ifndef INC_throttleRecord_H
#define INC_throttleRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef throttleSYNC_NUM_CHOICES
/** @brief Enumerated type from menu throttleSYNC */
typedef enum {
    throttleSYNC_IDLE               /**< @brief State string "Idle" */,
    throttleSYNC_PROC               /**< @brief State string "Process" */
} throttleSYNC;
/** @brief Number of states defined for menu throttleSYNC */
#define throttleSYNC_NUM_CHOICES 2
#endif

#ifndef throttleSTS_NUM_CHOICES
/** @brief Enumerated type from menu throttleSTS */
typedef enum {
    throttleSTS_UNK                 /**< @brief State string "Unknown" */,
    throttleSTS_ERR                 /**< @brief State string "Error" */,
    throttleSTS_SUC                 /**< @brief State string "Success" */
} throttleSTS;
/** @brief Number of states defined for menu throttleSTS */
#define throttleSTS_NUM_CHOICES 3
#endif

#ifndef throttleDRVLS_NUM_CHOICES
/** @brief Enumerated type from menu throttleDRVLS */
typedef enum {
    throttleDRVLS_NORM              /**< @brief State string "Normal" */,
    throttleDRVLS_LOW               /**< @brief State string "Low Limit" */,
    throttleDRVLS_HIGH              /**< @brief State string "High Limit" */
} throttleDRVLS;
/** @brief Number of states defined for menu throttleDRVLS */
#define throttleDRVLS_NUM_CHOICES 3
#endif

#ifndef throttleWAIT_NUM_CHOICES
/** @brief Enumerated type from menu throttleWAIT */
typedef enum {
    throttleWAIT_FALSE              /**< @brief State string "False" */,
    throttleWAIT_TRUE               /**< @brief State string "True" */
} throttleWAIT;
/** @brief Number of states defined for menu throttleWAIT */
#define throttleWAIT_NUM_CHOICES 2
#endif

#ifndef throttleDRVLC_NUM_CHOICES
/** @brief Enumerated type from menu throttleDRVLC */
typedef enum {
    throttleDRVLC_OFF               /**< @brief State string "Off" */,
    throttleDRVLC_ON                /**< @brief State string "On" */
} throttleDRVLC;
/** @brief Number of states defined for menu throttleDRVLC */
#define throttleDRVLC_NUM_CHOICES 2
#endif

#ifndef throttleOV_NUM_CHOICES
/** @brief Enumerated type from menu throttleOV */
typedef enum {
    throttleOV_EXT_NC               /**< @brief State string "Ext PV NC" */,
    throttleOV_EXT                  /**< @brief State string "Ext PV OK" */,
    throttleOV_LOC                  /**< @brief State string "Local PV" */,
    throttleOV_CON                  /**< @brief State string "Constant" */
} throttleOV;
/** @brief Number of states defined for menu throttleOV */
#define throttleOV_NUM_CHOICES 4
#endif

/** @brief Declaration of throttle record type. */
typedef struct throttleRecord {
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
    epicsFloat64        val;        /**< @brief Set Value */
    epicsFloat64        oval;       /**< @brief Previous Set Value */
    epicsFloat64        sent;       /**< @brief Sent Value */
    epicsFloat64        osent;      /**< @brief Previous Sent Value */
    epicsEnum16         wait;       /**< @brief Busy */
    epicsFloat64        hopr;       /**< @brief High Operating Range */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsFloat64        drvlh;      /**< @brief High Limit */
    epicsFloat64        drvll;      /**< @brief Low Limit */
    epicsEnum16         drvls;      /**< @brief Limit Status */
    epicsEnum16         drvlc;      /**< @brief Limit Clipping */
    char                ver[20];    /**< @brief Code Version */
    void *rpvt;                     /**< @brief Record Private */
    epicsEnum16         sts;        /**< @brief Record Status */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsInt16          dprec;      /**< @brief Delay Display Precision */
    epicsFloat64        dly;        /**< @brief Delay value */
    DBLINK              out;        /**< @brief Output */
    epicsEnum16         ov;         /**< @brief Output link valid */
    DBLINK              sinp;       /**< @brief Sync Input */
    epicsEnum16         siv;        /**< @brief Sync Input link valid */
    epicsEnum16         sync;       /**< @brief Sync values */
} throttleRecord;

typedef enum {
	throttleRecordNAME = 0,
	throttleRecordDESC = 1,
	throttleRecordASG = 2,
	throttleRecordSCAN = 3,
	throttleRecordPINI = 4,
	throttleRecordPHAS = 5,
	throttleRecordEVNT = 6,
	throttleRecordTSE = 7,
	throttleRecordTSEL = 8,
	throttleRecordDTYP = 9,
	throttleRecordDISV = 10,
	throttleRecordDISA = 11,
	throttleRecordSDIS = 12,
	throttleRecordMLOK = 13,
	throttleRecordMLIS = 14,
	throttleRecordBKLNK = 15,
	throttleRecordDISP = 16,
	throttleRecordPROC = 17,
	throttleRecordSTAT = 18,
	throttleRecordSEVR = 19,
	throttleRecordAMSG = 20,
	throttleRecordNSTA = 21,
	throttleRecordNSEV = 22,
	throttleRecordNAMSG = 23,
	throttleRecordACKS = 24,
	throttleRecordACKT = 25,
	throttleRecordDISS = 26,
	throttleRecordLCNT = 27,
	throttleRecordPACT = 28,
	throttleRecordPUTF = 29,
	throttleRecordRPRO = 30,
	throttleRecordASP = 31,
	throttleRecordPPN = 32,
	throttleRecordPPNR = 33,
	throttleRecordSPVT = 34,
	throttleRecordRSET = 35,
	throttleRecordDSET = 36,
	throttleRecordDPVT = 37,
	throttleRecordRDES = 38,
	throttleRecordLSET = 39,
	throttleRecordPRIO = 40,
	throttleRecordTPRO = 41,
	throttleRecordBKPT = 42,
	throttleRecordUDF = 43,
	throttleRecordUDFS = 44,
	throttleRecordTIME = 45,
	throttleRecordUTAG = 46,
	throttleRecordFLNK = 47,
	throttleRecordVAL = 48,
	throttleRecordOVAL = 49,
	throttleRecordSENT = 50,
	throttleRecordOSENT = 51,
	throttleRecordWAIT = 52,
	throttleRecordHOPR = 53,
	throttleRecordLOPR = 54,
	throttleRecordDRVLH = 55,
	throttleRecordDRVLL = 56,
	throttleRecordDRVLS = 57,
	throttleRecordDRVLC = 58,
	throttleRecordVER = 59,
	throttleRecordRPVT = 60,
	throttleRecordSTS = 61,
	throttleRecordPREC = 62,
	throttleRecordDPREC = 63,
	throttleRecordDLY = 64,
	throttleRecordOUT = 65,
	throttleRecordOV = 66,
	throttleRecordSINP = 67,
	throttleRecordSIV = 68,
	throttleRecordSYNC = 69
} throttleFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int throttleRecordSizeOffset(dbRecordType *prt)
{
    throttleRecord *prec = 0;

    if (prt->no_fields != 70) {
        cantProceed("IOC build or installation error:\n"
            "    The throttleRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 70.\n",
            prt->no_fields);
    }
    prt->papFldDes[throttleRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[throttleRecordNAME]->offset = (unsigned short)offsetof(throttleRecord, name);
    prt->papFldDes[throttleRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[throttleRecordDESC]->offset = (unsigned short)offsetof(throttleRecord, desc);
    prt->papFldDes[throttleRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[throttleRecordASG]->offset = (unsigned short)offsetof(throttleRecord, asg);
    prt->papFldDes[throttleRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[throttleRecordSCAN]->offset = (unsigned short)offsetof(throttleRecord, scan);
    prt->papFldDes[throttleRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[throttleRecordPINI]->offset = (unsigned short)offsetof(throttleRecord, pini);
    prt->papFldDes[throttleRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[throttleRecordPHAS]->offset = (unsigned short)offsetof(throttleRecord, phas);
    prt->papFldDes[throttleRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[throttleRecordEVNT]->offset = (unsigned short)offsetof(throttleRecord, evnt);
    prt->papFldDes[throttleRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[throttleRecordTSE]->offset = (unsigned short)offsetof(throttleRecord, tse);
    prt->papFldDes[throttleRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[throttleRecordTSEL]->offset = (unsigned short)offsetof(throttleRecord, tsel);
    prt->papFldDes[throttleRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[throttleRecordDTYP]->offset = (unsigned short)offsetof(throttleRecord, dtyp);
    prt->papFldDes[throttleRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[throttleRecordDISV]->offset = (unsigned short)offsetof(throttleRecord, disv);
    prt->papFldDes[throttleRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[throttleRecordDISA]->offset = (unsigned short)offsetof(throttleRecord, disa);
    prt->papFldDes[throttleRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[throttleRecordSDIS]->offset = (unsigned short)offsetof(throttleRecord, sdis);
    prt->papFldDes[throttleRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[throttleRecordMLOK]->offset = (unsigned short)offsetof(throttleRecord, mlok);
    prt->papFldDes[throttleRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[throttleRecordMLIS]->offset = (unsigned short)offsetof(throttleRecord, mlis);
    prt->papFldDes[throttleRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[throttleRecordBKLNK]->offset = (unsigned short)offsetof(throttleRecord, bklnk);
    prt->papFldDes[throttleRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[throttleRecordDISP]->offset = (unsigned short)offsetof(throttleRecord, disp);
    prt->papFldDes[throttleRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[throttleRecordPROC]->offset = (unsigned short)offsetof(throttleRecord, proc);
    prt->papFldDes[throttleRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[throttleRecordSTAT]->offset = (unsigned short)offsetof(throttleRecord, stat);
    prt->papFldDes[throttleRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[throttleRecordSEVR]->offset = (unsigned short)offsetof(throttleRecord, sevr);
    prt->papFldDes[throttleRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[throttleRecordAMSG]->offset = (unsigned short)offsetof(throttleRecord, amsg);
    prt->papFldDes[throttleRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[throttleRecordNSTA]->offset = (unsigned short)offsetof(throttleRecord, nsta);
    prt->papFldDes[throttleRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[throttleRecordNSEV]->offset = (unsigned short)offsetof(throttleRecord, nsev);
    prt->papFldDes[throttleRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[throttleRecordNAMSG]->offset = (unsigned short)offsetof(throttleRecord, namsg);
    prt->papFldDes[throttleRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[throttleRecordACKS]->offset = (unsigned short)offsetof(throttleRecord, acks);
    prt->papFldDes[throttleRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[throttleRecordACKT]->offset = (unsigned short)offsetof(throttleRecord, ackt);
    prt->papFldDes[throttleRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[throttleRecordDISS]->offset = (unsigned short)offsetof(throttleRecord, diss);
    prt->papFldDes[throttleRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[throttleRecordLCNT]->offset = (unsigned short)offsetof(throttleRecord, lcnt);
    prt->papFldDes[throttleRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[throttleRecordPACT]->offset = (unsigned short)offsetof(throttleRecord, pact);
    prt->papFldDes[throttleRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[throttleRecordPUTF]->offset = (unsigned short)offsetof(throttleRecord, putf);
    prt->papFldDes[throttleRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[throttleRecordRPRO]->offset = (unsigned short)offsetof(throttleRecord, rpro);
    prt->papFldDes[throttleRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[throttleRecordASP]->offset = (unsigned short)offsetof(throttleRecord, asp);
    prt->papFldDes[throttleRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[throttleRecordPPN]->offset = (unsigned short)offsetof(throttleRecord, ppn);
    prt->papFldDes[throttleRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[throttleRecordPPNR]->offset = (unsigned short)offsetof(throttleRecord, ppnr);
    prt->papFldDes[throttleRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[throttleRecordSPVT]->offset = (unsigned short)offsetof(throttleRecord, spvt);
    prt->papFldDes[throttleRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[throttleRecordRSET]->offset = (unsigned short)offsetof(throttleRecord, rset);
    prt->papFldDes[throttleRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[throttleRecordDSET]->offset = (unsigned short)offsetof(throttleRecord, dset);
    prt->papFldDes[throttleRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[throttleRecordDPVT]->offset = (unsigned short)offsetof(throttleRecord, dpvt);
    prt->papFldDes[throttleRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[throttleRecordRDES]->offset = (unsigned short)offsetof(throttleRecord, rdes);
    prt->papFldDes[throttleRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[throttleRecordLSET]->offset = (unsigned short)offsetof(throttleRecord, lset);
    prt->papFldDes[throttleRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[throttleRecordPRIO]->offset = (unsigned short)offsetof(throttleRecord, prio);
    prt->papFldDes[throttleRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[throttleRecordTPRO]->offset = (unsigned short)offsetof(throttleRecord, tpro);
    prt->papFldDes[throttleRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[throttleRecordBKPT]->offset = (unsigned short)offsetof(throttleRecord, bkpt);
    prt->papFldDes[throttleRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[throttleRecordUDF]->offset = (unsigned short)offsetof(throttleRecord, udf);
    prt->papFldDes[throttleRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[throttleRecordUDFS]->offset = (unsigned short)offsetof(throttleRecord, udfs);
    prt->papFldDes[throttleRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[throttleRecordTIME]->offset = (unsigned short)offsetof(throttleRecord, time);
    prt->papFldDes[throttleRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[throttleRecordUTAG]->offset = (unsigned short)offsetof(throttleRecord, utag);
    prt->papFldDes[throttleRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[throttleRecordFLNK]->offset = (unsigned short)offsetof(throttleRecord, flnk);
    prt->papFldDes[throttleRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[throttleRecordVAL]->offset = (unsigned short)offsetof(throttleRecord, val);
    prt->papFldDes[throttleRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[throttleRecordOVAL]->offset = (unsigned short)offsetof(throttleRecord, oval);
    prt->papFldDes[throttleRecordSENT]->size = sizeof(prec->sent);
    prt->papFldDes[throttleRecordSENT]->offset = (unsigned short)offsetof(throttleRecord, sent);
    prt->papFldDes[throttleRecordOSENT]->size = sizeof(prec->osent);
    prt->papFldDes[throttleRecordOSENT]->offset = (unsigned short)offsetof(throttleRecord, osent);
    prt->papFldDes[throttleRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[throttleRecordWAIT]->offset = (unsigned short)offsetof(throttleRecord, wait);
    prt->papFldDes[throttleRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[throttleRecordHOPR]->offset = (unsigned short)offsetof(throttleRecord, hopr);
    prt->papFldDes[throttleRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[throttleRecordLOPR]->offset = (unsigned short)offsetof(throttleRecord, lopr);
    prt->papFldDes[throttleRecordDRVLH]->size = sizeof(prec->drvlh);
    prt->papFldDes[throttleRecordDRVLH]->offset = (unsigned short)offsetof(throttleRecord, drvlh);
    prt->papFldDes[throttleRecordDRVLL]->size = sizeof(prec->drvll);
    prt->papFldDes[throttleRecordDRVLL]->offset = (unsigned short)offsetof(throttleRecord, drvll);
    prt->papFldDes[throttleRecordDRVLS]->size = sizeof(prec->drvls);
    prt->papFldDes[throttleRecordDRVLS]->offset = (unsigned short)offsetof(throttleRecord, drvls);
    prt->papFldDes[throttleRecordDRVLC]->size = sizeof(prec->drvlc);
    prt->papFldDes[throttleRecordDRVLC]->offset = (unsigned short)offsetof(throttleRecord, drvlc);
    prt->papFldDes[throttleRecordVER]->size = sizeof(prec->ver);
    prt->papFldDes[throttleRecordVER]->offset = (unsigned short)offsetof(throttleRecord, ver);
    prt->papFldDes[throttleRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[throttleRecordRPVT]->offset = (unsigned short)offsetof(throttleRecord, rpvt);
    prt->papFldDes[throttleRecordSTS]->size = sizeof(prec->sts);
    prt->papFldDes[throttleRecordSTS]->offset = (unsigned short)offsetof(throttleRecord, sts);
    prt->papFldDes[throttleRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[throttleRecordPREC]->offset = (unsigned short)offsetof(throttleRecord, prec);
    prt->papFldDes[throttleRecordDPREC]->size = sizeof(prec->dprec);
    prt->papFldDes[throttleRecordDPREC]->offset = (unsigned short)offsetof(throttleRecord, dprec);
    prt->papFldDes[throttleRecordDLY]->size = sizeof(prec->dly);
    prt->papFldDes[throttleRecordDLY]->offset = (unsigned short)offsetof(throttleRecord, dly);
    prt->papFldDes[throttleRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[throttleRecordOUT]->offset = (unsigned short)offsetof(throttleRecord, out);
    prt->papFldDes[throttleRecordOV]->size = sizeof(prec->ov);
    prt->papFldDes[throttleRecordOV]->offset = (unsigned short)offsetof(throttleRecord, ov);
    prt->papFldDes[throttleRecordSINP]->size = sizeof(prec->sinp);
    prt->papFldDes[throttleRecordSINP]->offset = (unsigned short)offsetof(throttleRecord, sinp);
    prt->papFldDes[throttleRecordSIV]->size = sizeof(prec->siv);
    prt->papFldDes[throttleRecordSIV]->offset = (unsigned short)offsetof(throttleRecord, siv);
    prt->papFldDes[throttleRecordSYNC]->size = sizeof(prec->sync);
    prt->papFldDes[throttleRecordSYNC]->offset = (unsigned short)offsetof(throttleRecord, sync);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(throttleRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_throttleRecord_H */
