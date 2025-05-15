/** @file epidRecord.h
 * @brief Declarations for the @ref epidRecord "epid" record type.
 *
 * This header was generated from epidRecord.dbd
 */

#ifndef INC_epidRecord_H
#define INC_epidRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef epidFeedbackMode_NUM_CHOICES
/** @brief Enumerated type from menu epidFeedbackMode */
typedef enum {
    epidFeedbackMode_PID            /**< @brief State string "PID" */,
    epidFeedbackMode_MaxMin         /**< @brief State string "Max/Min" */
} epidFeedbackMode;
/** @brief Number of states defined for menu epidFeedbackMode */
#define epidFeedbackMode_NUM_CHOICES 2
#endif

#ifndef epidFeedbackState_NUM_CHOICES
/** @brief Enumerated type from menu epidFeedbackState */
typedef enum {
    epidFeedbackState_Off           /**< @brief State string "Off" */,
    epidFeedbackState_On            /**< @brief State string "On" */
} epidFeedbackState;
/** @brief Number of states defined for menu epidFeedbackState */
#define epidFeedbackState_NUM_CHOICES 2
#endif

/** @brief Declaration of epid record type. */
typedef struct epidRecord {
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
    epicsFloat64        val;        /**< @brief Setpoint */
    epicsEnum16         smsl;       /**< @brief Setpoint Mode Select */
    DBLINK              stpl;       /**< @brief Setpoint Location */
    DBLINK              inp;        /**< @brief Controlled Value Loc */
    DBLINK              outl;       /**< @brief Output Location */
    DBLINK              trig;       /**< @brief Readback Trigger */
    epicsFloat64        tval;       /**< @brief Trigger Value */
    epicsFloat64        cval;       /**< @brief Controlled Value */
    epicsFloat64        cvlp;       /**< @brief Prev. Controlled Value */
    epicsFloat64        oval;       /**< @brief Output value */
    epicsFloat64        ovlp;       /**< @brief Prev output */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsFloat64        mdt;        /**< @brief Min Delta T */
    epicsEnum16         fmod;       /**< @brief Feedback Mode */
    epicsEnum16         fbon;       /**< @brief Feedback On/Off */
    epicsEnum16         fbop;       /**< @brief Prev. feedback On/Off */
    epicsFloat64        kp;         /**< @brief Proportional Gain */
    epicsFloat64        ki;         /**< @brief Intergral Gain */
    epicsFloat64        kd;         /**< @brief Derivative Gain */
    char                egu[16];    /**< @brief Engineering Units */
    epicsFloat64        hopr;       /**< @brief High Operating Range */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsFloat64        drvh;       /**< @brief High Drive Limit */
    epicsFloat64        drvl;       /**< @brief Low Drive Limit */
    epicsFloat64        hihi;       /**< @brief Hihi Deviation Limit */
    epicsFloat64        lolo;       /**< @brief Lolo Deviation Limit */
    epicsFloat64        high;       /**< @brief High Deviation Limit */
    epicsFloat64        low;        /**< @brief Low Deviation Limit */
    epicsEnum16         hhsv;       /**< @brief Hihi Severity */
    epicsEnum16         llsv;       /**< @brief Lolo Severity */
    epicsEnum16         hsv;        /**< @brief High Severity */
    epicsEnum16         lsv;        /**< @brief Low Severity */
    epicsFloat64        hyst;       /**< @brief Alarm Deadband */
    epicsFloat64        adel;       /**< @brief Archive Deadband */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsFloat64        odel;       /**< @brief Output Deadband */
    epicsFloat64        p;          /**< @brief P component */
    epicsFloat64        pp;         /**< @brief Prev. P component */
    epicsFloat64        i;          /**< @brief I component */
    epicsFloat64        ip;         /**< @brief Prev. I component */
    epicsFloat64        d;          /**< @brief D component */
    epicsFloat64        dp;         /**< @brief Prev. D component */
    epicsTimeStamp  ct;             /**< @brief Time */
    epicsTimeStamp   ctp;           /**< @brief Previous time */
    epicsFloat64        dt;         /**< @brief Delta T */
    epicsFloat64        dtp;        /**< @brief Prev. Delta T */
    epicsFloat64        err;        /**< @brief Error */
    epicsFloat64        errp;       /**< @brief Prev. Error */
    epicsFloat64        lalm;       /**< @brief Last Value Alarmed */
    epicsFloat64        alst;       /**< @brief Last Value Archived */
    epicsFloat64        mlst;       /**< @brief Last Value Monitored */
} epidRecord;

typedef enum {
	epidRecordNAME = 0,
	epidRecordDESC = 1,
	epidRecordASG = 2,
	epidRecordSCAN = 3,
	epidRecordPINI = 4,
	epidRecordPHAS = 5,
	epidRecordEVNT = 6,
	epidRecordTSE = 7,
	epidRecordTSEL = 8,
	epidRecordDTYP = 9,
	epidRecordDISV = 10,
	epidRecordDISA = 11,
	epidRecordSDIS = 12,
	epidRecordMLOK = 13,
	epidRecordMLIS = 14,
	epidRecordBKLNK = 15,
	epidRecordDISP = 16,
	epidRecordPROC = 17,
	epidRecordSTAT = 18,
	epidRecordSEVR = 19,
	epidRecordAMSG = 20,
	epidRecordNSTA = 21,
	epidRecordNSEV = 22,
	epidRecordNAMSG = 23,
	epidRecordACKS = 24,
	epidRecordACKT = 25,
	epidRecordDISS = 26,
	epidRecordLCNT = 27,
	epidRecordPACT = 28,
	epidRecordPUTF = 29,
	epidRecordRPRO = 30,
	epidRecordASP = 31,
	epidRecordPPN = 32,
	epidRecordPPNR = 33,
	epidRecordSPVT = 34,
	epidRecordRSET = 35,
	epidRecordDSET = 36,
	epidRecordDPVT = 37,
	epidRecordRDES = 38,
	epidRecordLSET = 39,
	epidRecordPRIO = 40,
	epidRecordTPRO = 41,
	epidRecordBKPT = 42,
	epidRecordUDF = 43,
	epidRecordUDFS = 44,
	epidRecordTIME = 45,
	epidRecordUTAG = 46,
	epidRecordFLNK = 47,
	epidRecordVAL = 48,
	epidRecordSMSL = 49,
	epidRecordSTPL = 50,
	epidRecordINP = 51,
	epidRecordOUTL = 52,
	epidRecordTRIG = 53,
	epidRecordTVAL = 54,
	epidRecordCVAL = 55,
	epidRecordCVLP = 56,
	epidRecordOVAL = 57,
	epidRecordOVLP = 58,
	epidRecordPREC = 59,
	epidRecordMDT = 60,
	epidRecordFMOD = 61,
	epidRecordFBON = 62,
	epidRecordFBOP = 63,
	epidRecordKP = 64,
	epidRecordKI = 65,
	epidRecordKD = 66,
	epidRecordEGU = 67,
	epidRecordHOPR = 68,
	epidRecordLOPR = 69,
	epidRecordDRVH = 70,
	epidRecordDRVL = 71,
	epidRecordHIHI = 72,
	epidRecordLOLO = 73,
	epidRecordHIGH = 74,
	epidRecordLOW = 75,
	epidRecordHHSV = 76,
	epidRecordLLSV = 77,
	epidRecordHSV = 78,
	epidRecordLSV = 79,
	epidRecordHYST = 80,
	epidRecordADEL = 81,
	epidRecordMDEL = 82,
	epidRecordODEL = 83,
	epidRecordP = 84,
	epidRecordPP = 85,
	epidRecordI = 86,
	epidRecordIP = 87,
	epidRecordD = 88,
	epidRecordDP = 89,
	epidRecordCT = 90,
	epidRecordCTP = 91,
	epidRecordDT = 92,
	epidRecordDTP = 93,
	epidRecordERR = 94,
	epidRecordERRP = 95,
	epidRecordLALM = 96,
	epidRecordALST = 97,
	epidRecordMLST = 98
} epidFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int epidRecordSizeOffset(dbRecordType *prt)
{
    epidRecord *prec = 0;

    if (prt->no_fields != 99) {
        cantProceed("IOC build or installation error:\n"
            "    The epidRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 99.\n",
            prt->no_fields);
    }
    prt->papFldDes[epidRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[epidRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[epidRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[epidRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[epidRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[epidRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[epidRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[epidRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[epidRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[epidRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[epidRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[epidRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[epidRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[epidRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[epidRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[epidRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[epidRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[epidRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[epidRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[epidRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[epidRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[epidRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[epidRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[epidRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[epidRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[epidRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[epidRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[epidRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[epidRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[epidRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[epidRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[epidRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[epidRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[epidRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[epidRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[epidRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[epidRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[epidRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[epidRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[epidRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[epidRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[epidRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[epidRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[epidRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[epidRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[epidRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[epidRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[epidRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[epidRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[epidRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[epidRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[epidRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[epidRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[epidRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[epidRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[epidRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[epidRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[epidRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[epidRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[epidRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[epidRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[epidRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[epidRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[epidRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[epidRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[epidRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[epidRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[epidRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[epidRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[epidRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[epidRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[epidRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[epidRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[epidRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[epidRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[epidRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[epidRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[epidRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[epidRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[epidRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[epidRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[epidRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[epidRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[epidRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[epidRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[epidRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[epidRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[epidRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[epidRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[epidRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[epidRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[epidRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[epidRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[epidRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[epidRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[epidRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[epidRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[epidRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[epidRecordSMSL]->size = sizeof(prec->smsl);
    prt->papFldDes[epidRecordSMSL]->offset = (unsigned short)((char *)&prec->smsl - (char *)prec);
    prt->papFldDes[epidRecordSTPL]->size = sizeof(prec->stpl);
    prt->papFldDes[epidRecordSTPL]->offset = (unsigned short)((char *)&prec->stpl - (char *)prec);
    prt->papFldDes[epidRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[epidRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[epidRecordOUTL]->size = sizeof(prec->outl);
    prt->papFldDes[epidRecordOUTL]->offset = (unsigned short)((char *)&prec->outl - (char *)prec);
    prt->papFldDes[epidRecordTRIG]->size = sizeof(prec->trig);
    prt->papFldDes[epidRecordTRIG]->offset = (unsigned short)((char *)&prec->trig - (char *)prec);
    prt->papFldDes[epidRecordTVAL]->size = sizeof(prec->tval);
    prt->papFldDes[epidRecordTVAL]->offset = (unsigned short)((char *)&prec->tval - (char *)prec);
    prt->papFldDes[epidRecordCVAL]->size = sizeof(prec->cval);
    prt->papFldDes[epidRecordCVAL]->offset = (unsigned short)((char *)&prec->cval - (char *)prec);
    prt->papFldDes[epidRecordCVLP]->size = sizeof(prec->cvlp);
    prt->papFldDes[epidRecordCVLP]->offset = (unsigned short)((char *)&prec->cvlp - (char *)prec);
    prt->papFldDes[epidRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[epidRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[epidRecordOVLP]->size = sizeof(prec->ovlp);
    prt->papFldDes[epidRecordOVLP]->offset = (unsigned short)((char *)&prec->ovlp - (char *)prec);
    prt->papFldDes[epidRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[epidRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[epidRecordMDT]->size = sizeof(prec->mdt);
    prt->papFldDes[epidRecordMDT]->offset = (unsigned short)((char *)&prec->mdt - (char *)prec);
    prt->papFldDes[epidRecordFMOD]->size = sizeof(prec->fmod);
    prt->papFldDes[epidRecordFMOD]->offset = (unsigned short)((char *)&prec->fmod - (char *)prec);
    prt->papFldDes[epidRecordFBON]->size = sizeof(prec->fbon);
    prt->papFldDes[epidRecordFBON]->offset = (unsigned short)((char *)&prec->fbon - (char *)prec);
    prt->papFldDes[epidRecordFBOP]->size = sizeof(prec->fbop);
    prt->papFldDes[epidRecordFBOP]->offset = (unsigned short)((char *)&prec->fbop - (char *)prec);
    prt->papFldDes[epidRecordKP]->size = sizeof(prec->kp);
    prt->papFldDes[epidRecordKP]->offset = (unsigned short)((char *)&prec->kp - (char *)prec);
    prt->papFldDes[epidRecordKI]->size = sizeof(prec->ki);
    prt->papFldDes[epidRecordKI]->offset = (unsigned short)((char *)&prec->ki - (char *)prec);
    prt->papFldDes[epidRecordKD]->size = sizeof(prec->kd);
    prt->papFldDes[epidRecordKD]->offset = (unsigned short)((char *)&prec->kd - (char *)prec);
    prt->papFldDes[epidRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[epidRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[epidRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[epidRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[epidRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[epidRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[epidRecordDRVH]->size = sizeof(prec->drvh);
    prt->papFldDes[epidRecordDRVH]->offset = (unsigned short)((char *)&prec->drvh - (char *)prec);
    prt->papFldDes[epidRecordDRVL]->size = sizeof(prec->drvl);
    prt->papFldDes[epidRecordDRVL]->offset = (unsigned short)((char *)&prec->drvl - (char *)prec);
    prt->papFldDes[epidRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[epidRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[epidRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[epidRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[epidRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[epidRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[epidRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[epidRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[epidRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[epidRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[epidRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[epidRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[epidRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[epidRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[epidRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[epidRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[epidRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[epidRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[epidRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[epidRecordADEL]->offset = (unsigned short)((char *)&prec->adel - (char *)prec);
    prt->papFldDes[epidRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[epidRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[epidRecordODEL]->size = sizeof(prec->odel);
    prt->papFldDes[epidRecordODEL]->offset = (unsigned short)((char *)&prec->odel - (char *)prec);
    prt->papFldDes[epidRecordP]->size = sizeof(prec->p);
    prt->papFldDes[epidRecordP]->offset = (unsigned short)((char *)&prec->p - (char *)prec);
    prt->papFldDes[epidRecordPP]->size = sizeof(prec->pp);
    prt->papFldDes[epidRecordPP]->offset = (unsigned short)((char *)&prec->pp - (char *)prec);
    prt->papFldDes[epidRecordI]->size = sizeof(prec->i);
    prt->papFldDes[epidRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[epidRecordIP]->size = sizeof(prec->ip);
    prt->papFldDes[epidRecordIP]->offset = (unsigned short)((char *)&prec->ip - (char *)prec);
    prt->papFldDes[epidRecordD]->size = sizeof(prec->d);
    prt->papFldDes[epidRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[epidRecordDP]->size = sizeof(prec->dp);
    prt->papFldDes[epidRecordDP]->offset = (unsigned short)((char *)&prec->dp - (char *)prec);
    prt->papFldDes[epidRecordCT]->size = sizeof(prec->ct);
    prt->papFldDes[epidRecordCT]->offset = (unsigned short)((char *)&prec->ct - (char *)prec);
    prt->papFldDes[epidRecordCTP]->size = sizeof(prec->ctp);
    prt->papFldDes[epidRecordCTP]->offset = (unsigned short)((char *)&prec->ctp - (char *)prec);
    prt->papFldDes[epidRecordDT]->size = sizeof(prec->dt);
    prt->papFldDes[epidRecordDT]->offset = (unsigned short)((char *)&prec->dt - (char *)prec);
    prt->papFldDes[epidRecordDTP]->size = sizeof(prec->dtp);
    prt->papFldDes[epidRecordDTP]->offset = (unsigned short)((char *)&prec->dtp - (char *)prec);
    prt->papFldDes[epidRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[epidRecordERR]->offset = (unsigned short)((char *)&prec->err - (char *)prec);
    prt->papFldDes[epidRecordERRP]->size = sizeof(prec->errp);
    prt->papFldDes[epidRecordERRP]->offset = (unsigned short)((char *)&prec->errp - (char *)prec);
    prt->papFldDes[epidRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[epidRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[epidRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[epidRecordALST]->offset = (unsigned short)((char *)&prec->alst - (char *)prec);
    prt->papFldDes[epidRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[epidRecordMLST]->offset = (unsigned short)((char *)&prec->mlst - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(epidRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_epidRecord_H */
