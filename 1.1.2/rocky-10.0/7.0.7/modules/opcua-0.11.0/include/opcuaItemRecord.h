/** @file opcuaItemRecord.h
 * @brief Declarations for the @ref opcuaItemRecord "opcuaItem" record type.
 *
 * This header was generated from opcuaItemRecord.dbd
 */

#ifndef INC_opcuaItemRecord_H
#define INC_opcuaItemRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef menuBini_NUM_CHOICES
/** @brief Enumerated type from menu menuBini */
typedef enum {
    menuBiniREAD                    /**< @brief State string "read" */,
    menuBiniIGNORE                  /**< @brief State string "ignore" */,
    menuBiniWRITE                   /**< @brief State string "write" */
} menuBini;
/** @brief Number of states defined for menu menuBini */
#define menuBini_NUM_CHOICES 3
#endif

#ifndef menuWoc_NUM_CHOICES
/** @brief Enumerated type from menu menuWoc */
typedef enum {
    menuWocMANUAL                   /**< @brief State string "manual" */,
    menuWocIMMEDIATE                /**< @brief State string "immediate" */
} menuWoc;
/** @brief Number of states defined for menu menuWoc */
#define menuWoc_NUM_CHOICES 2
#endif

/** @brief Declaration of opcuaItem record type. */
typedef struct opcuaItemRecord {
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
    epicsUInt32         val;        /**< @brief Dummy Value */
    DBLINK              inp;        /**< @brief NodeId Specification */
    char                sess[41];   /**< @brief Session Specification */
    char                subs[41];   /**< @brief Subscription Specification */
    epicsEnum16         defactn;    /**< @brief Default Action */
    epicsEnum16         bini;       /**< @brief Behavior at Initialization */
    epicsUInt8          read;       /**< @brief Force Read Processing */
    epicsUInt8          write;      /**< @brief Force Write Processing */
    epicsUInt32         statcode;   /**< @brief OPC UA status code */
    epicsUInt32         ostatcode;  /**< @brief Old status code */
    char                stattext[41];/**< @brief OPC UA status string */
    epicsEnum16         woc;        /**< @brief Write-on-change mode */
} opcuaItemRecord;

typedef enum {
	opcuaItemRecordNAME = 0,
	opcuaItemRecordDESC = 1,
	opcuaItemRecordASG = 2,
	opcuaItemRecordSCAN = 3,
	opcuaItemRecordPINI = 4,
	opcuaItemRecordPHAS = 5,
	opcuaItemRecordEVNT = 6,
	opcuaItemRecordTSE = 7,
	opcuaItemRecordTSEL = 8,
	opcuaItemRecordDTYP = 9,
	opcuaItemRecordDISV = 10,
	opcuaItemRecordDISA = 11,
	opcuaItemRecordSDIS = 12,
	opcuaItemRecordMLOK = 13,
	opcuaItemRecordMLIS = 14,
	opcuaItemRecordBKLNK = 15,
	opcuaItemRecordDISP = 16,
	opcuaItemRecordPROC = 17,
	opcuaItemRecordSTAT = 18,
	opcuaItemRecordSEVR = 19,
	opcuaItemRecordAMSG = 20,
	opcuaItemRecordNSTA = 21,
	opcuaItemRecordNSEV = 22,
	opcuaItemRecordNAMSG = 23,
	opcuaItemRecordACKS = 24,
	opcuaItemRecordACKT = 25,
	opcuaItemRecordDISS = 26,
	opcuaItemRecordLCNT = 27,
	opcuaItemRecordPACT = 28,
	opcuaItemRecordPUTF = 29,
	opcuaItemRecordRPRO = 30,
	opcuaItemRecordASP = 31,
	opcuaItemRecordPPN = 32,
	opcuaItemRecordPPNR = 33,
	opcuaItemRecordSPVT = 34,
	opcuaItemRecordRSET = 35,
	opcuaItemRecordDSET = 36,
	opcuaItemRecordDPVT = 37,
	opcuaItemRecordRDES = 38,
	opcuaItemRecordLSET = 39,
	opcuaItemRecordPRIO = 40,
	opcuaItemRecordTPRO = 41,
	opcuaItemRecordBKPT = 42,
	opcuaItemRecordUDF = 43,
	opcuaItemRecordUDFS = 44,
	opcuaItemRecordTIME = 45,
	opcuaItemRecordUTAG = 46,
	opcuaItemRecordFLNK = 47,
	opcuaItemRecordVAL = 48,
	opcuaItemRecordINP = 49,
	opcuaItemRecordSESS = 50,
	opcuaItemRecordSUBS = 51,
	opcuaItemRecordDEFACTN = 52,
	opcuaItemRecordBINI = 53,
	opcuaItemRecordREAD = 54,
	opcuaItemRecordWRITE = 55,
	opcuaItemRecordSTATCODE = 56,
	opcuaItemRecordOSTATCODE = 57,
	opcuaItemRecordSTATTEXT = 58,
	opcuaItemRecordWOC = 59
} opcuaItemFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int opcuaItemRecordSizeOffset(dbRecordType *prt)
{
    opcuaItemRecord *prec = 0;

    if (prt->no_fields != 60) {
        cantProceed("IOC build or installation error:\n"
            "    The opcuaItemRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 60.\n",
            prt->no_fields);
    }
    prt->papFldDes[opcuaItemRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[opcuaItemRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[opcuaItemRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[opcuaItemRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[opcuaItemRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[opcuaItemRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[opcuaItemRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[opcuaItemRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[opcuaItemRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[opcuaItemRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[opcuaItemRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[opcuaItemRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[opcuaItemRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[opcuaItemRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[opcuaItemRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[opcuaItemRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[opcuaItemRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[opcuaItemRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[opcuaItemRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[opcuaItemRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[opcuaItemRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[opcuaItemRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[opcuaItemRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[opcuaItemRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[opcuaItemRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[opcuaItemRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[opcuaItemRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[opcuaItemRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[opcuaItemRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[opcuaItemRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[opcuaItemRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[opcuaItemRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[opcuaItemRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[opcuaItemRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[opcuaItemRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[opcuaItemRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[opcuaItemRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[opcuaItemRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[opcuaItemRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[opcuaItemRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[opcuaItemRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[opcuaItemRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[opcuaItemRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[opcuaItemRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[opcuaItemRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[opcuaItemRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[opcuaItemRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[opcuaItemRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[opcuaItemRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[opcuaItemRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[opcuaItemRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[opcuaItemRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[opcuaItemRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[opcuaItemRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[opcuaItemRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[opcuaItemRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[opcuaItemRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[opcuaItemRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[opcuaItemRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[opcuaItemRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[opcuaItemRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[opcuaItemRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[opcuaItemRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[opcuaItemRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[opcuaItemRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[opcuaItemRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[opcuaItemRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[opcuaItemRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[opcuaItemRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[opcuaItemRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[opcuaItemRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[opcuaItemRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[opcuaItemRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[opcuaItemRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[opcuaItemRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[opcuaItemRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[opcuaItemRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[opcuaItemRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[opcuaItemRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[opcuaItemRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[opcuaItemRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[opcuaItemRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[opcuaItemRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[opcuaItemRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[opcuaItemRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[opcuaItemRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[opcuaItemRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[opcuaItemRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[opcuaItemRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[opcuaItemRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[opcuaItemRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[opcuaItemRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[opcuaItemRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[opcuaItemRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[opcuaItemRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[opcuaItemRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[opcuaItemRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[opcuaItemRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[opcuaItemRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[opcuaItemRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[opcuaItemRecordSESS]->size = sizeof(prec->sess);
    prt->papFldDes[opcuaItemRecordSESS]->offset = (unsigned short)((char *)&prec->sess - (char *)prec);
    prt->papFldDes[opcuaItemRecordSUBS]->size = sizeof(prec->subs);
    prt->papFldDes[opcuaItemRecordSUBS]->offset = (unsigned short)((char *)&prec->subs - (char *)prec);
    prt->papFldDes[opcuaItemRecordDEFACTN]->size = sizeof(prec->defactn);
    prt->papFldDes[opcuaItemRecordDEFACTN]->offset = (unsigned short)((char *)&prec->defactn - (char *)prec);
    prt->papFldDes[opcuaItemRecordBINI]->size = sizeof(prec->bini);
    prt->papFldDes[opcuaItemRecordBINI]->offset = (unsigned short)((char *)&prec->bini - (char *)prec);
    prt->papFldDes[opcuaItemRecordREAD]->size = sizeof(prec->read);
    prt->papFldDes[opcuaItemRecordREAD]->offset = (unsigned short)((char *)&prec->read - (char *)prec);
    prt->papFldDes[opcuaItemRecordWRITE]->size = sizeof(prec->write);
    prt->papFldDes[opcuaItemRecordWRITE]->offset = (unsigned short)((char *)&prec->write - (char *)prec);
    prt->papFldDes[opcuaItemRecordSTATCODE]->size = sizeof(prec->statcode);
    prt->papFldDes[opcuaItemRecordSTATCODE]->offset = (unsigned short)((char *)&prec->statcode - (char *)prec);
    prt->papFldDes[opcuaItemRecordOSTATCODE]->size = sizeof(prec->ostatcode);
    prt->papFldDes[opcuaItemRecordOSTATCODE]->offset = (unsigned short)((char *)&prec->ostatcode - (char *)prec);
    prt->papFldDes[opcuaItemRecordSTATTEXT]->size = sizeof(prec->stattext);
    prt->papFldDes[opcuaItemRecordSTATTEXT]->offset = (unsigned short)((char *)&prec->stattext - (char *)prec);
    prt->papFldDes[opcuaItemRecordWOC]->size = sizeof(prec->woc);
    prt->papFldDes[opcuaItemRecordWOC]->offset = (unsigned short)((char *)&prec->woc - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(opcuaItemRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_opcuaItemRecord_H */
