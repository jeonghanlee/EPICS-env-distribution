/** @file busyRecord.h
 * @brief Declarations for the @ref busyRecord "busy" record type.
 *
 * This header was generated from busyRecord.dbd
 */

#ifndef INC_busyRecord_H
#define INC_busyRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

/** @brief Declaration of busy record type. */
typedef struct busyRecord {
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
    epicsEnum16         val;        /**< @brief Current Value */
    epicsEnum16         omsl;       /**< @brief Output Mode Select */
    DBLINK              dol;        /**< @brief Desired Output Loc */
    DBLINK              out;        /**< @brief Output Specification */
    epicsFloat64        high;       /**< @brief Seconds to Hold High */
    char                znam[26];   /**< @brief Zero Name */
    char                onam[26];   /**< @brief One Name */
    epicsUInt32         rval;       /**< @brief Raw Value */
    epicsUInt32         oraw;       /**< @brief prev Raw Value */
    epicsUInt32         oval;       /**< @brief prev Value */
    epicsUInt32         mask;       /**< @brief Hardware Mask */
    void *  rpvt;                   /**< @brief Record Private */
    void *	wdpt;                    /**< @brief Watch Dog Timer ID */
    epicsEnum16         zsv;        /**< @brief Zero Error Severity */
    epicsEnum16         osv;        /**< @brief One Error Severity */
    epicsEnum16         cosv;       /**< @brief Change of State Sevr */
    epicsUInt32         rbv;        /**< @brief Readback Value */
    epicsUInt32         orbv;       /**< @brief Prev Readback Value */
    epicsUInt16         mlst;       /**< @brief Last Value Monitored */
    epicsUInt16         lalm;       /**< @brief Last Value Alarmed */
    DBLINK              siol;       /**< @brief Sim Output Specifctn */
    DBLINK              siml;       /**< @brief Sim Mode Location */
    epicsEnum16         simm;       /**< @brief Simulation Mode */
    epicsEnum16         sims;       /**< @brief Sim mode Alarm Svrty */
    epicsEnum16         ivoa;       /**< @brief INVALID outpt action */
    epicsUInt16         ivov;       /**< @brief INVALID output value */
} busyRecord;

typedef enum {
	busyRecordNAME = 0,
	busyRecordDESC = 1,
	busyRecordASG = 2,
	busyRecordSCAN = 3,
	busyRecordPINI = 4,
	busyRecordPHAS = 5,
	busyRecordEVNT = 6,
	busyRecordTSE = 7,
	busyRecordTSEL = 8,
	busyRecordDTYP = 9,
	busyRecordDISV = 10,
	busyRecordDISA = 11,
	busyRecordSDIS = 12,
	busyRecordMLOK = 13,
	busyRecordMLIS = 14,
	busyRecordBKLNK = 15,
	busyRecordDISP = 16,
	busyRecordPROC = 17,
	busyRecordSTAT = 18,
	busyRecordSEVR = 19,
	busyRecordAMSG = 20,
	busyRecordNSTA = 21,
	busyRecordNSEV = 22,
	busyRecordNAMSG = 23,
	busyRecordACKS = 24,
	busyRecordACKT = 25,
	busyRecordDISS = 26,
	busyRecordLCNT = 27,
	busyRecordPACT = 28,
	busyRecordPUTF = 29,
	busyRecordRPRO = 30,
	busyRecordASP = 31,
	busyRecordPPN = 32,
	busyRecordPPNR = 33,
	busyRecordSPVT = 34,
	busyRecordRSET = 35,
	busyRecordDSET = 36,
	busyRecordDPVT = 37,
	busyRecordRDES = 38,
	busyRecordLSET = 39,
	busyRecordPRIO = 40,
	busyRecordTPRO = 41,
	busyRecordBKPT = 42,
	busyRecordUDF = 43,
	busyRecordUDFS = 44,
	busyRecordTIME = 45,
	busyRecordUTAG = 46,
	busyRecordFLNK = 47,
	busyRecordVAL = 48,
	busyRecordOMSL = 49,
	busyRecordDOL = 50,
	busyRecordOUT = 51,
	busyRecordHIGH = 52,
	busyRecordZNAM = 53,
	busyRecordONAM = 54,
	busyRecordRVAL = 55,
	busyRecordORAW = 56,
	busyRecordOVAL = 57,
	busyRecordMASK = 58,
	busyRecordRPVT = 59,
	busyRecordWDPT = 60,
	busyRecordZSV = 61,
	busyRecordOSV = 62,
	busyRecordCOSV = 63,
	busyRecordRBV = 64,
	busyRecordORBV = 65,
	busyRecordMLST = 66,
	busyRecordLALM = 67,
	busyRecordSIOL = 68,
	busyRecordSIML = 69,
	busyRecordSIMM = 70,
	busyRecordSIMS = 71,
	busyRecordIVOA = 72,
	busyRecordIVOV = 73
} busyFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int busyRecordSizeOffset(dbRecordType *prt)
{
    busyRecord *prec = 0;

    if (prt->no_fields != 74) {
        cantProceed("IOC build or installation error:\n"
            "    The busyRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 74.\n",
            prt->no_fields);
    }
    prt->papFldDes[busyRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[busyRecordNAME]->offset = (unsigned short)offsetof(busyRecord, name);
    prt->papFldDes[busyRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[busyRecordDESC]->offset = (unsigned short)offsetof(busyRecord, desc);
    prt->papFldDes[busyRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[busyRecordASG]->offset = (unsigned short)offsetof(busyRecord, asg);
    prt->papFldDes[busyRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[busyRecordSCAN]->offset = (unsigned short)offsetof(busyRecord, scan);
    prt->papFldDes[busyRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[busyRecordPINI]->offset = (unsigned short)offsetof(busyRecord, pini);
    prt->papFldDes[busyRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[busyRecordPHAS]->offset = (unsigned short)offsetof(busyRecord, phas);
    prt->papFldDes[busyRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[busyRecordEVNT]->offset = (unsigned short)offsetof(busyRecord, evnt);
    prt->papFldDes[busyRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[busyRecordTSE]->offset = (unsigned short)offsetof(busyRecord, tse);
    prt->papFldDes[busyRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[busyRecordTSEL]->offset = (unsigned short)offsetof(busyRecord, tsel);
    prt->papFldDes[busyRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[busyRecordDTYP]->offset = (unsigned short)offsetof(busyRecord, dtyp);
    prt->papFldDes[busyRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[busyRecordDISV]->offset = (unsigned short)offsetof(busyRecord, disv);
    prt->papFldDes[busyRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[busyRecordDISA]->offset = (unsigned short)offsetof(busyRecord, disa);
    prt->papFldDes[busyRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[busyRecordSDIS]->offset = (unsigned short)offsetof(busyRecord, sdis);
    prt->papFldDes[busyRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[busyRecordMLOK]->offset = (unsigned short)offsetof(busyRecord, mlok);
    prt->papFldDes[busyRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[busyRecordMLIS]->offset = (unsigned short)offsetof(busyRecord, mlis);
    prt->papFldDes[busyRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[busyRecordBKLNK]->offset = (unsigned short)offsetof(busyRecord, bklnk);
    prt->papFldDes[busyRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[busyRecordDISP]->offset = (unsigned short)offsetof(busyRecord, disp);
    prt->papFldDes[busyRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[busyRecordPROC]->offset = (unsigned short)offsetof(busyRecord, proc);
    prt->papFldDes[busyRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[busyRecordSTAT]->offset = (unsigned short)offsetof(busyRecord, stat);
    prt->papFldDes[busyRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[busyRecordSEVR]->offset = (unsigned short)offsetof(busyRecord, sevr);
    prt->papFldDes[busyRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[busyRecordAMSG]->offset = (unsigned short)offsetof(busyRecord, amsg);
    prt->papFldDes[busyRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[busyRecordNSTA]->offset = (unsigned short)offsetof(busyRecord, nsta);
    prt->papFldDes[busyRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[busyRecordNSEV]->offset = (unsigned short)offsetof(busyRecord, nsev);
    prt->papFldDes[busyRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[busyRecordNAMSG]->offset = (unsigned short)offsetof(busyRecord, namsg);
    prt->papFldDes[busyRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[busyRecordACKS]->offset = (unsigned short)offsetof(busyRecord, acks);
    prt->papFldDes[busyRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[busyRecordACKT]->offset = (unsigned short)offsetof(busyRecord, ackt);
    prt->papFldDes[busyRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[busyRecordDISS]->offset = (unsigned short)offsetof(busyRecord, diss);
    prt->papFldDes[busyRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[busyRecordLCNT]->offset = (unsigned short)offsetof(busyRecord, lcnt);
    prt->papFldDes[busyRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[busyRecordPACT]->offset = (unsigned short)offsetof(busyRecord, pact);
    prt->papFldDes[busyRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[busyRecordPUTF]->offset = (unsigned short)offsetof(busyRecord, putf);
    prt->papFldDes[busyRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[busyRecordRPRO]->offset = (unsigned short)offsetof(busyRecord, rpro);
    prt->papFldDes[busyRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[busyRecordASP]->offset = (unsigned short)offsetof(busyRecord, asp);
    prt->papFldDes[busyRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[busyRecordPPN]->offset = (unsigned short)offsetof(busyRecord, ppn);
    prt->papFldDes[busyRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[busyRecordPPNR]->offset = (unsigned short)offsetof(busyRecord, ppnr);
    prt->papFldDes[busyRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[busyRecordSPVT]->offset = (unsigned short)offsetof(busyRecord, spvt);
    prt->papFldDes[busyRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[busyRecordRSET]->offset = (unsigned short)offsetof(busyRecord, rset);
    prt->papFldDes[busyRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[busyRecordDSET]->offset = (unsigned short)offsetof(busyRecord, dset);
    prt->papFldDes[busyRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[busyRecordDPVT]->offset = (unsigned short)offsetof(busyRecord, dpvt);
    prt->papFldDes[busyRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[busyRecordRDES]->offset = (unsigned short)offsetof(busyRecord, rdes);
    prt->papFldDes[busyRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[busyRecordLSET]->offset = (unsigned short)offsetof(busyRecord, lset);
    prt->papFldDes[busyRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[busyRecordPRIO]->offset = (unsigned short)offsetof(busyRecord, prio);
    prt->papFldDes[busyRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[busyRecordTPRO]->offset = (unsigned short)offsetof(busyRecord, tpro);
    prt->papFldDes[busyRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[busyRecordBKPT]->offset = (unsigned short)offsetof(busyRecord, bkpt);
    prt->papFldDes[busyRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[busyRecordUDF]->offset = (unsigned short)offsetof(busyRecord, udf);
    prt->papFldDes[busyRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[busyRecordUDFS]->offset = (unsigned short)offsetof(busyRecord, udfs);
    prt->papFldDes[busyRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[busyRecordTIME]->offset = (unsigned short)offsetof(busyRecord, time);
    prt->papFldDes[busyRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[busyRecordUTAG]->offset = (unsigned short)offsetof(busyRecord, utag);
    prt->papFldDes[busyRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[busyRecordFLNK]->offset = (unsigned short)offsetof(busyRecord, flnk);
    prt->papFldDes[busyRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[busyRecordVAL]->offset = (unsigned short)offsetof(busyRecord, val);
    prt->papFldDes[busyRecordOMSL]->size = sizeof(prec->omsl);
    prt->papFldDes[busyRecordOMSL]->offset = (unsigned short)offsetof(busyRecord, omsl);
    prt->papFldDes[busyRecordDOL]->size = sizeof(prec->dol);
    prt->papFldDes[busyRecordDOL]->offset = (unsigned short)offsetof(busyRecord, dol);
    prt->papFldDes[busyRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[busyRecordOUT]->offset = (unsigned short)offsetof(busyRecord, out);
    prt->papFldDes[busyRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[busyRecordHIGH]->offset = (unsigned short)offsetof(busyRecord, high);
    prt->papFldDes[busyRecordZNAM]->size = sizeof(prec->znam);
    prt->papFldDes[busyRecordZNAM]->offset = (unsigned short)offsetof(busyRecord, znam);
    prt->papFldDes[busyRecordONAM]->size = sizeof(prec->onam);
    prt->papFldDes[busyRecordONAM]->offset = (unsigned short)offsetof(busyRecord, onam);
    prt->papFldDes[busyRecordRVAL]->size = sizeof(prec->rval);
    prt->papFldDes[busyRecordRVAL]->offset = (unsigned short)offsetof(busyRecord, rval);
    prt->papFldDes[busyRecordORAW]->size = sizeof(prec->oraw);
    prt->papFldDes[busyRecordORAW]->offset = (unsigned short)offsetof(busyRecord, oraw);
    prt->papFldDes[busyRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[busyRecordOVAL]->offset = (unsigned short)offsetof(busyRecord, oval);
    prt->papFldDes[busyRecordMASK]->size = sizeof(prec->mask);
    prt->papFldDes[busyRecordMASK]->offset = (unsigned short)offsetof(busyRecord, mask);
    prt->papFldDes[busyRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[busyRecordRPVT]->offset = (unsigned short)offsetof(busyRecord, rpvt);
    prt->papFldDes[busyRecordWDPT]->size = sizeof(prec->wdpt);
    prt->papFldDes[busyRecordWDPT]->offset = (unsigned short)offsetof(busyRecord, wdpt);
    prt->papFldDes[busyRecordZSV]->size = sizeof(prec->zsv);
    prt->papFldDes[busyRecordZSV]->offset = (unsigned short)offsetof(busyRecord, zsv);
    prt->papFldDes[busyRecordOSV]->size = sizeof(prec->osv);
    prt->papFldDes[busyRecordOSV]->offset = (unsigned short)offsetof(busyRecord, osv);
    prt->papFldDes[busyRecordCOSV]->size = sizeof(prec->cosv);
    prt->papFldDes[busyRecordCOSV]->offset = (unsigned short)offsetof(busyRecord, cosv);
    prt->papFldDes[busyRecordRBV]->size = sizeof(prec->rbv);
    prt->papFldDes[busyRecordRBV]->offset = (unsigned short)offsetof(busyRecord, rbv);
    prt->papFldDes[busyRecordORBV]->size = sizeof(prec->orbv);
    prt->papFldDes[busyRecordORBV]->offset = (unsigned short)offsetof(busyRecord, orbv);
    prt->papFldDes[busyRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[busyRecordMLST]->offset = (unsigned short)offsetof(busyRecord, mlst);
    prt->papFldDes[busyRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[busyRecordLALM]->offset = (unsigned short)offsetof(busyRecord, lalm);
    prt->papFldDes[busyRecordSIOL]->size = sizeof(prec->siol);
    prt->papFldDes[busyRecordSIOL]->offset = (unsigned short)offsetof(busyRecord, siol);
    prt->papFldDes[busyRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[busyRecordSIML]->offset = (unsigned short)offsetof(busyRecord, siml);
    prt->papFldDes[busyRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[busyRecordSIMM]->offset = (unsigned short)offsetof(busyRecord, simm);
    prt->papFldDes[busyRecordSIMS]->size = sizeof(prec->sims);
    prt->papFldDes[busyRecordSIMS]->offset = (unsigned short)offsetof(busyRecord, sims);
    prt->papFldDes[busyRecordIVOA]->size = sizeof(prec->ivoa);
    prt->papFldDes[busyRecordIVOA]->offset = (unsigned short)offsetof(busyRecord, ivoa);
    prt->papFldDes[busyRecordIVOV]->size = sizeof(prec->ivov);
    prt->papFldDes[busyRecordIVOV]->offset = (unsigned short)offsetof(busyRecord, ivov);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(busyRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_busyRecord_H */
