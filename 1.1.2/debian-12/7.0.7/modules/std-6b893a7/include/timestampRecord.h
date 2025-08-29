/** @file timestampRecord.h
 * @brief Declarations for the @ref timestampRecord "timestamp" record type.
 *
 * This header was generated from timestampRecord.dbd
 */

#ifndef INC_timestampRecord_H
#define INC_timestampRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef timestampTST_NUM_CHOICES
/** @brief Enumerated type from menu timestampTST */
typedef enum {
    timestampTST_YY_MM_DD_HH_MM_SS  /**< @brief State string "YY/MM/DD HH:MM:SS" */,
    timestampTST_MM_DD_YY_HH_MM_SS  /**< @brief State string "MM/DD/YY HH:MM:SS" */,
    timestampTST_MM_DD_HH_MM_SS_YY  /**< @brief State string "Mon DD HH:MM:SS YY" */,
    timestampTST_MM_DD_HH_MM_SS     /**< @brief State string "Mon DD HH:MM:SS" */,
    timestampTST_HH_MM_SS           /**< @brief State string "HH:MM:SS" */,
    timestampTST_HH_MM              /**< @brief State string "HH:MM" */,
    timestampTST_DD_MM_YY_HH_MM_SS  /**< @brief State string "DD/MM/YY HH:MM:SS" */,
    timestampTST_DD_MM_HH_MM_SS_YY  /**< @brief State string "DD Mon HH:MM:SS YY" */,
    timestampTST_VMS                /**< @brief State string "DD-Mon-YYYY HH:MM:SS" */,
    timestampTST_MM_DD_YYYY         /**< @brief State string "Mon DD, YYYY HH:MM:SS.ns" */,
    timestampTST_MM_DD_YY           /**< @brief State string "MM/DD/YY HH:MM:SS.ns" */
} timestampTST;
/** @brief Number of states defined for menu timestampTST */
#define timestampTST_NUM_CHOICES 11
#endif

/** @brief Declaration of timestamp record type. */
typedef struct timestampRecord {
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
    char                val[40];    /**< @brief Current Value */
    char                oval[40];   /**< @brief Previous Value */
    epicsUInt32         rval;       /**< @brief Current Raw Value */
    epicsEnum16         tst;        /**< @brief Time Stamp Type */
} timestampRecord;

typedef enum {
	timestampRecordNAME = 0,
	timestampRecordDESC = 1,
	timestampRecordASG = 2,
	timestampRecordSCAN = 3,
	timestampRecordPINI = 4,
	timestampRecordPHAS = 5,
	timestampRecordEVNT = 6,
	timestampRecordTSE = 7,
	timestampRecordTSEL = 8,
	timestampRecordDTYP = 9,
	timestampRecordDISV = 10,
	timestampRecordDISA = 11,
	timestampRecordSDIS = 12,
	timestampRecordMLOK = 13,
	timestampRecordMLIS = 14,
	timestampRecordBKLNK = 15,
	timestampRecordDISP = 16,
	timestampRecordPROC = 17,
	timestampRecordSTAT = 18,
	timestampRecordSEVR = 19,
	timestampRecordAMSG = 20,
	timestampRecordNSTA = 21,
	timestampRecordNSEV = 22,
	timestampRecordNAMSG = 23,
	timestampRecordACKS = 24,
	timestampRecordACKT = 25,
	timestampRecordDISS = 26,
	timestampRecordLCNT = 27,
	timestampRecordPACT = 28,
	timestampRecordPUTF = 29,
	timestampRecordRPRO = 30,
	timestampRecordASP = 31,
	timestampRecordPPN = 32,
	timestampRecordPPNR = 33,
	timestampRecordSPVT = 34,
	timestampRecordRSET = 35,
	timestampRecordDSET = 36,
	timestampRecordDPVT = 37,
	timestampRecordRDES = 38,
	timestampRecordLSET = 39,
	timestampRecordPRIO = 40,
	timestampRecordTPRO = 41,
	timestampRecordBKPT = 42,
	timestampRecordUDF = 43,
	timestampRecordUDFS = 44,
	timestampRecordTIME = 45,
	timestampRecordUTAG = 46,
	timestampRecordFLNK = 47,
	timestampRecordVAL = 48,
	timestampRecordOVAL = 49,
	timestampRecordRVAL = 50,
	timestampRecordTST = 51
} timestampFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int timestampRecordSizeOffset(dbRecordType *prt)
{
    timestampRecord *prec = 0;

    if (prt->no_fields != 52) {
        cantProceed("IOC build or installation error:\n"
            "    The timestampRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 52.\n",
            prt->no_fields);
    }
    prt->papFldDes[timestampRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[timestampRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[timestampRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[timestampRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[timestampRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[timestampRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[timestampRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[timestampRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[timestampRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[timestampRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[timestampRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[timestampRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[timestampRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[timestampRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[timestampRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[timestampRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[timestampRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[timestampRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[timestampRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[timestampRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[timestampRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[timestampRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[timestampRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[timestampRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[timestampRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[timestampRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[timestampRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[timestampRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[timestampRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[timestampRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[timestampRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[timestampRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[timestampRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[timestampRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[timestampRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[timestampRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[timestampRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[timestampRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[timestampRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[timestampRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[timestampRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[timestampRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[timestampRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[timestampRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[timestampRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[timestampRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[timestampRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[timestampRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[timestampRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[timestampRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[timestampRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[timestampRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[timestampRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[timestampRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[timestampRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[timestampRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[timestampRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[timestampRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[timestampRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[timestampRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[timestampRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[timestampRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[timestampRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[timestampRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[timestampRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[timestampRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[timestampRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[timestampRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[timestampRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[timestampRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[timestampRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[timestampRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[timestampRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[timestampRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[timestampRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[timestampRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[timestampRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[timestampRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[timestampRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[timestampRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[timestampRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[timestampRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[timestampRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[timestampRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[timestampRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[timestampRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[timestampRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[timestampRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[timestampRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[timestampRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[timestampRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[timestampRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[timestampRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[timestampRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[timestampRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[timestampRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[timestampRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[timestampRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[timestampRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[timestampRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[timestampRecordRVAL]->size = sizeof(prec->rval);
    prt->papFldDes[timestampRecordRVAL]->offset = (unsigned short)((char *)&prec->rval - (char *)prec);
    prt->papFldDes[timestampRecordTST]->size = sizeof(prec->tst);
    prt->papFldDes[timestampRecordTST]->offset = (unsigned short)((char *)&prec->tst - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(timestampRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_timestampRecord_H */
