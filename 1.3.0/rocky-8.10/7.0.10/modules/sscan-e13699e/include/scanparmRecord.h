/** @file scanparmRecord.h
 * @brief Declarations for the @ref scanparmRecord "scanparm" record type.
 *
 * This header was generated from scanparmRecord.dbd
 */

#ifndef INC_scanparmRecord_H
#define INC_scanparmRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

/** @brief Declaration of scanparm record type. */
typedef struct scanparmRecord {
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
    epicsFloat64        val;        /**< @brief Result */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsInt16          pre;        /**< @brief PRE-write command */
    DBLINK              opre;       /**< @brief PRE-write OutLink */
    epicsEnum16         sm;         /**< @brief StepMode */
    DBLINK              osm;        /**< @brief SM OutLink */
    epicsEnum16         ar;         /**< @brief absRel */
    DBLINK              oar;        /**< @brief AR OutLink */
    epicsEnum16         aft;        /**< @brief After */
    DBLINK              oaft;       /**< @brief AFT OutLink */
    char                ppv[40];    /**< @brief PositionerPVName */
    char                rpv[40];    /**< @brief ReadbackPVName */
    char                dpv[40];    /**< @brief DetPVName */
    char                tpv[40];    /**< @brief TrigPVName */
    DBLINK              oppv;       /**< @brief P1PV OutLink */
    DBLINK              orpv;       /**< @brief R1PV OutLink */
    DBLINK              odpv;       /**< @brief D1PV OutLink */
    DBLINK              otpv;       /**< @brief T1PV OutLink */
    epicsFloat64        sp;         /**< @brief StartPos */
    DBLINK              osp;        /**< @brief SP OutLink */
    epicsFloat64        ep;         /**< @brief EndPos */
    DBLINK              oep;        /**< @brief EP OutLink */
    epicsInt32          np;         /**< @brief nPts */
    DBLINK              onp;        /**< @brief NP OutLink */
    epicsInt16          sc;         /**< @brief StartCmd */
    DBLINK              osc;        /**< @brief SC OutLink */
    epicsFloat64        aqt;        /**< @brief Acquire time */
    DBLINK              oaqt;       /**< @brief AQT OutLink */
    epicsInt32          mp;         /**< @brief MaxPts */
    DBLINK              imp;        /**< @brief MP InLink */
    epicsInt16          act;        /**< @brief ScanActive */
    DBLINK              iact;       /**< @brief InLink */
    epicsInt16          load;       /**< @brief Load */
    DBLINK              oload;      /**< @brief LOAD OutLink */
    epicsInt16          go;         /**< @brief Go */
    DBLINK              ogo;        /**< @brief GO OutLink */
    epicsFloat64        step;       /**< @brief StepSize */
    epicsFloat64        lstp;       /**< @brief Last stepSize */
} scanparmRecord;

typedef enum {
	scanparmRecordNAME = 0,
	scanparmRecordDESC = 1,
	scanparmRecordASG = 2,
	scanparmRecordSCAN = 3,
	scanparmRecordPINI = 4,
	scanparmRecordPHAS = 5,
	scanparmRecordEVNT = 6,
	scanparmRecordTSE = 7,
	scanparmRecordTSEL = 8,
	scanparmRecordDTYP = 9,
	scanparmRecordDISV = 10,
	scanparmRecordDISA = 11,
	scanparmRecordSDIS = 12,
	scanparmRecordMLOK = 13,
	scanparmRecordMLIS = 14,
	scanparmRecordBKLNK = 15,
	scanparmRecordDISP = 16,
	scanparmRecordPROC = 17,
	scanparmRecordSTAT = 18,
	scanparmRecordSEVR = 19,
	scanparmRecordAMSG = 20,
	scanparmRecordNSTA = 21,
	scanparmRecordNSEV = 22,
	scanparmRecordNAMSG = 23,
	scanparmRecordACKS = 24,
	scanparmRecordACKT = 25,
	scanparmRecordDISS = 26,
	scanparmRecordLCNT = 27,
	scanparmRecordPACT = 28,
	scanparmRecordPUTF = 29,
	scanparmRecordRPRO = 30,
	scanparmRecordASP = 31,
	scanparmRecordPPN = 32,
	scanparmRecordPPNR = 33,
	scanparmRecordSPVT = 34,
	scanparmRecordRSET = 35,
	scanparmRecordDSET = 36,
	scanparmRecordDPVT = 37,
	scanparmRecordRDES = 38,
	scanparmRecordLSET = 39,
	scanparmRecordPRIO = 40,
	scanparmRecordTPRO = 41,
	scanparmRecordBKPT = 42,
	scanparmRecordUDF = 43,
	scanparmRecordUDFS = 44,
	scanparmRecordTIME = 45,
	scanparmRecordUTAG = 46,
	scanparmRecordFLNK = 47,
	scanparmRecordVERS = 48,
	scanparmRecordVAL = 49,
	scanparmRecordPREC = 50,
	scanparmRecordPRE = 51,
	scanparmRecordOPRE = 52,
	scanparmRecordSM = 53,
	scanparmRecordOSM = 54,
	scanparmRecordAR = 55,
	scanparmRecordOAR = 56,
	scanparmRecordAFT = 57,
	scanparmRecordOAFT = 58,
	scanparmRecordPPV = 59,
	scanparmRecordRPV = 60,
	scanparmRecordDPV = 61,
	scanparmRecordTPV = 62,
	scanparmRecordOPPV = 63,
	scanparmRecordORPV = 64,
	scanparmRecordODPV = 65,
	scanparmRecordOTPV = 66,
	scanparmRecordSP = 67,
	scanparmRecordOSP = 68,
	scanparmRecordEP = 69,
	scanparmRecordOEP = 70,
	scanparmRecordNP = 71,
	scanparmRecordONP = 72,
	scanparmRecordSC = 73,
	scanparmRecordOSC = 74,
	scanparmRecordAQT = 75,
	scanparmRecordOAQT = 76,
	scanparmRecordMP = 77,
	scanparmRecordIMP = 78,
	scanparmRecordACT = 79,
	scanparmRecordIACT = 80,
	scanparmRecordLOAD = 81,
	scanparmRecordOLOAD = 82,
	scanparmRecordGO = 83,
	scanparmRecordOGO = 84,
	scanparmRecordSTEP = 85,
	scanparmRecordLSTP = 86
} scanparmFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int scanparmRecordSizeOffset(dbRecordType *prt)
{
    scanparmRecord *prec = 0;

    if (prt->no_fields != 87) {
        cantProceed("IOC build or installation error:\n"
            "    The scanparmRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 87.\n",
            prt->no_fields);
    }
    prt->papFldDes[scanparmRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[scanparmRecordNAME]->offset = (unsigned short)offsetof(scanparmRecord, name);
    prt->papFldDes[scanparmRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[scanparmRecordDESC]->offset = (unsigned short)offsetof(scanparmRecord, desc);
    prt->papFldDes[scanparmRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[scanparmRecordASG]->offset = (unsigned short)offsetof(scanparmRecord, asg);
    prt->papFldDes[scanparmRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[scanparmRecordSCAN]->offset = (unsigned short)offsetof(scanparmRecord, scan);
    prt->papFldDes[scanparmRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[scanparmRecordPINI]->offset = (unsigned short)offsetof(scanparmRecord, pini);
    prt->papFldDes[scanparmRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[scanparmRecordPHAS]->offset = (unsigned short)offsetof(scanparmRecord, phas);
    prt->papFldDes[scanparmRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[scanparmRecordEVNT]->offset = (unsigned short)offsetof(scanparmRecord, evnt);
    prt->papFldDes[scanparmRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[scanparmRecordTSE]->offset = (unsigned short)offsetof(scanparmRecord, tse);
    prt->papFldDes[scanparmRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[scanparmRecordTSEL]->offset = (unsigned short)offsetof(scanparmRecord, tsel);
    prt->papFldDes[scanparmRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[scanparmRecordDTYP]->offset = (unsigned short)offsetof(scanparmRecord, dtyp);
    prt->papFldDes[scanparmRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[scanparmRecordDISV]->offset = (unsigned short)offsetof(scanparmRecord, disv);
    prt->papFldDes[scanparmRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[scanparmRecordDISA]->offset = (unsigned short)offsetof(scanparmRecord, disa);
    prt->papFldDes[scanparmRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[scanparmRecordSDIS]->offset = (unsigned short)offsetof(scanparmRecord, sdis);
    prt->papFldDes[scanparmRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[scanparmRecordMLOK]->offset = (unsigned short)offsetof(scanparmRecord, mlok);
    prt->papFldDes[scanparmRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[scanparmRecordMLIS]->offset = (unsigned short)offsetof(scanparmRecord, mlis);
    prt->papFldDes[scanparmRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[scanparmRecordBKLNK]->offset = (unsigned short)offsetof(scanparmRecord, bklnk);
    prt->papFldDes[scanparmRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[scanparmRecordDISP]->offset = (unsigned short)offsetof(scanparmRecord, disp);
    prt->papFldDes[scanparmRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[scanparmRecordPROC]->offset = (unsigned short)offsetof(scanparmRecord, proc);
    prt->papFldDes[scanparmRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[scanparmRecordSTAT]->offset = (unsigned short)offsetof(scanparmRecord, stat);
    prt->papFldDes[scanparmRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[scanparmRecordSEVR]->offset = (unsigned short)offsetof(scanparmRecord, sevr);
    prt->papFldDes[scanparmRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[scanparmRecordAMSG]->offset = (unsigned short)offsetof(scanparmRecord, amsg);
    prt->papFldDes[scanparmRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[scanparmRecordNSTA]->offset = (unsigned short)offsetof(scanparmRecord, nsta);
    prt->papFldDes[scanparmRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[scanparmRecordNSEV]->offset = (unsigned short)offsetof(scanparmRecord, nsev);
    prt->papFldDes[scanparmRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[scanparmRecordNAMSG]->offset = (unsigned short)offsetof(scanparmRecord, namsg);
    prt->papFldDes[scanparmRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[scanparmRecordACKS]->offset = (unsigned short)offsetof(scanparmRecord, acks);
    prt->papFldDes[scanparmRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[scanparmRecordACKT]->offset = (unsigned short)offsetof(scanparmRecord, ackt);
    prt->papFldDes[scanparmRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[scanparmRecordDISS]->offset = (unsigned short)offsetof(scanparmRecord, diss);
    prt->papFldDes[scanparmRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[scanparmRecordLCNT]->offset = (unsigned short)offsetof(scanparmRecord, lcnt);
    prt->papFldDes[scanparmRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[scanparmRecordPACT]->offset = (unsigned short)offsetof(scanparmRecord, pact);
    prt->papFldDes[scanparmRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[scanparmRecordPUTF]->offset = (unsigned short)offsetof(scanparmRecord, putf);
    prt->papFldDes[scanparmRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[scanparmRecordRPRO]->offset = (unsigned short)offsetof(scanparmRecord, rpro);
    prt->papFldDes[scanparmRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[scanparmRecordASP]->offset = (unsigned short)offsetof(scanparmRecord, asp);
    prt->papFldDes[scanparmRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[scanparmRecordPPN]->offset = (unsigned short)offsetof(scanparmRecord, ppn);
    prt->papFldDes[scanparmRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[scanparmRecordPPNR]->offset = (unsigned short)offsetof(scanparmRecord, ppnr);
    prt->papFldDes[scanparmRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[scanparmRecordSPVT]->offset = (unsigned short)offsetof(scanparmRecord, spvt);
    prt->papFldDes[scanparmRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[scanparmRecordRSET]->offset = (unsigned short)offsetof(scanparmRecord, rset);
    prt->papFldDes[scanparmRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[scanparmRecordDSET]->offset = (unsigned short)offsetof(scanparmRecord, dset);
    prt->papFldDes[scanparmRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[scanparmRecordDPVT]->offset = (unsigned short)offsetof(scanparmRecord, dpvt);
    prt->papFldDes[scanparmRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[scanparmRecordRDES]->offset = (unsigned short)offsetof(scanparmRecord, rdes);
    prt->papFldDes[scanparmRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[scanparmRecordLSET]->offset = (unsigned short)offsetof(scanparmRecord, lset);
    prt->papFldDes[scanparmRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[scanparmRecordPRIO]->offset = (unsigned short)offsetof(scanparmRecord, prio);
    prt->papFldDes[scanparmRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[scanparmRecordTPRO]->offset = (unsigned short)offsetof(scanparmRecord, tpro);
    prt->papFldDes[scanparmRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[scanparmRecordBKPT]->offset = (unsigned short)offsetof(scanparmRecord, bkpt);
    prt->papFldDes[scanparmRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[scanparmRecordUDF]->offset = (unsigned short)offsetof(scanparmRecord, udf);
    prt->papFldDes[scanparmRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[scanparmRecordUDFS]->offset = (unsigned short)offsetof(scanparmRecord, udfs);
    prt->papFldDes[scanparmRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[scanparmRecordTIME]->offset = (unsigned short)offsetof(scanparmRecord, time);
    prt->papFldDes[scanparmRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[scanparmRecordUTAG]->offset = (unsigned short)offsetof(scanparmRecord, utag);
    prt->papFldDes[scanparmRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[scanparmRecordFLNK]->offset = (unsigned short)offsetof(scanparmRecord, flnk);
    prt->papFldDes[scanparmRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[scanparmRecordVERS]->offset = (unsigned short)offsetof(scanparmRecord, vers);
    prt->papFldDes[scanparmRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[scanparmRecordVAL]->offset = (unsigned short)offsetof(scanparmRecord, val);
    prt->papFldDes[scanparmRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[scanparmRecordPREC]->offset = (unsigned short)offsetof(scanparmRecord, prec);
    prt->papFldDes[scanparmRecordPRE]->size = sizeof(prec->pre);
    prt->papFldDes[scanparmRecordPRE]->offset = (unsigned short)offsetof(scanparmRecord, pre);
    prt->papFldDes[scanparmRecordOPRE]->size = sizeof(prec->opre);
    prt->papFldDes[scanparmRecordOPRE]->offset = (unsigned short)offsetof(scanparmRecord, opre);
    prt->papFldDes[scanparmRecordSM]->size = sizeof(prec->sm);
    prt->papFldDes[scanparmRecordSM]->offset = (unsigned short)offsetof(scanparmRecord, sm);
    prt->papFldDes[scanparmRecordOSM]->size = sizeof(prec->osm);
    prt->papFldDes[scanparmRecordOSM]->offset = (unsigned short)offsetof(scanparmRecord, osm);
    prt->papFldDes[scanparmRecordAR]->size = sizeof(prec->ar);
    prt->papFldDes[scanparmRecordAR]->offset = (unsigned short)offsetof(scanparmRecord, ar);
    prt->papFldDes[scanparmRecordOAR]->size = sizeof(prec->oar);
    prt->papFldDes[scanparmRecordOAR]->offset = (unsigned short)offsetof(scanparmRecord, oar);
    prt->papFldDes[scanparmRecordAFT]->size = sizeof(prec->aft);
    prt->papFldDes[scanparmRecordAFT]->offset = (unsigned short)offsetof(scanparmRecord, aft);
    prt->papFldDes[scanparmRecordOAFT]->size = sizeof(prec->oaft);
    prt->papFldDes[scanparmRecordOAFT]->offset = (unsigned short)offsetof(scanparmRecord, oaft);
    prt->papFldDes[scanparmRecordPPV]->size = sizeof(prec->ppv);
    prt->papFldDes[scanparmRecordPPV]->offset = (unsigned short)offsetof(scanparmRecord, ppv);
    prt->papFldDes[scanparmRecordRPV]->size = sizeof(prec->rpv);
    prt->papFldDes[scanparmRecordRPV]->offset = (unsigned short)offsetof(scanparmRecord, rpv);
    prt->papFldDes[scanparmRecordDPV]->size = sizeof(prec->dpv);
    prt->papFldDes[scanparmRecordDPV]->offset = (unsigned short)offsetof(scanparmRecord, dpv);
    prt->papFldDes[scanparmRecordTPV]->size = sizeof(prec->tpv);
    prt->papFldDes[scanparmRecordTPV]->offset = (unsigned short)offsetof(scanparmRecord, tpv);
    prt->papFldDes[scanparmRecordOPPV]->size = sizeof(prec->oppv);
    prt->papFldDes[scanparmRecordOPPV]->offset = (unsigned short)offsetof(scanparmRecord, oppv);
    prt->papFldDes[scanparmRecordORPV]->size = sizeof(prec->orpv);
    prt->papFldDes[scanparmRecordORPV]->offset = (unsigned short)offsetof(scanparmRecord, orpv);
    prt->papFldDes[scanparmRecordODPV]->size = sizeof(prec->odpv);
    prt->papFldDes[scanparmRecordODPV]->offset = (unsigned short)offsetof(scanparmRecord, odpv);
    prt->papFldDes[scanparmRecordOTPV]->size = sizeof(prec->otpv);
    prt->papFldDes[scanparmRecordOTPV]->offset = (unsigned short)offsetof(scanparmRecord, otpv);
    prt->papFldDes[scanparmRecordSP]->size = sizeof(prec->sp);
    prt->papFldDes[scanparmRecordSP]->offset = (unsigned short)offsetof(scanparmRecord, sp);
    prt->papFldDes[scanparmRecordOSP]->size = sizeof(prec->osp);
    prt->papFldDes[scanparmRecordOSP]->offset = (unsigned short)offsetof(scanparmRecord, osp);
    prt->papFldDes[scanparmRecordEP]->size = sizeof(prec->ep);
    prt->papFldDes[scanparmRecordEP]->offset = (unsigned short)offsetof(scanparmRecord, ep);
    prt->papFldDes[scanparmRecordOEP]->size = sizeof(prec->oep);
    prt->papFldDes[scanparmRecordOEP]->offset = (unsigned short)offsetof(scanparmRecord, oep);
    prt->papFldDes[scanparmRecordNP]->size = sizeof(prec->np);
    prt->papFldDes[scanparmRecordNP]->offset = (unsigned short)offsetof(scanparmRecord, np);
    prt->papFldDes[scanparmRecordONP]->size = sizeof(prec->onp);
    prt->papFldDes[scanparmRecordONP]->offset = (unsigned short)offsetof(scanparmRecord, onp);
    prt->papFldDes[scanparmRecordSC]->size = sizeof(prec->sc);
    prt->papFldDes[scanparmRecordSC]->offset = (unsigned short)offsetof(scanparmRecord, sc);
    prt->papFldDes[scanparmRecordOSC]->size = sizeof(prec->osc);
    prt->papFldDes[scanparmRecordOSC]->offset = (unsigned short)offsetof(scanparmRecord, osc);
    prt->papFldDes[scanparmRecordAQT]->size = sizeof(prec->aqt);
    prt->papFldDes[scanparmRecordAQT]->offset = (unsigned short)offsetof(scanparmRecord, aqt);
    prt->papFldDes[scanparmRecordOAQT]->size = sizeof(prec->oaqt);
    prt->papFldDes[scanparmRecordOAQT]->offset = (unsigned short)offsetof(scanparmRecord, oaqt);
    prt->papFldDes[scanparmRecordMP]->size = sizeof(prec->mp);
    prt->papFldDes[scanparmRecordMP]->offset = (unsigned short)offsetof(scanparmRecord, mp);
    prt->papFldDes[scanparmRecordIMP]->size = sizeof(prec->imp);
    prt->papFldDes[scanparmRecordIMP]->offset = (unsigned short)offsetof(scanparmRecord, imp);
    prt->papFldDes[scanparmRecordACT]->size = sizeof(prec->act);
    prt->papFldDes[scanparmRecordACT]->offset = (unsigned short)offsetof(scanparmRecord, act);
    prt->papFldDes[scanparmRecordIACT]->size = sizeof(prec->iact);
    prt->papFldDes[scanparmRecordIACT]->offset = (unsigned short)offsetof(scanparmRecord, iact);
    prt->papFldDes[scanparmRecordLOAD]->size = sizeof(prec->load);
    prt->papFldDes[scanparmRecordLOAD]->offset = (unsigned short)offsetof(scanparmRecord, load);
    prt->papFldDes[scanparmRecordOLOAD]->size = sizeof(prec->oload);
    prt->papFldDes[scanparmRecordOLOAD]->offset = (unsigned short)offsetof(scanparmRecord, oload);
    prt->papFldDes[scanparmRecordGO]->size = sizeof(prec->go);
    prt->papFldDes[scanparmRecordGO]->offset = (unsigned short)offsetof(scanparmRecord, go);
    prt->papFldDes[scanparmRecordOGO]->size = sizeof(prec->ogo);
    prt->papFldDes[scanparmRecordOGO]->offset = (unsigned short)offsetof(scanparmRecord, ogo);
    prt->papFldDes[scanparmRecordSTEP]->size = sizeof(prec->step);
    prt->papFldDes[scanparmRecordSTEP]->offset = (unsigned short)offsetof(scanparmRecord, step);
    prt->papFldDes[scanparmRecordLSTP]->size = sizeof(prec->lstp);
    prt->papFldDes[scanparmRecordLSTP]->offset = (unsigned short)offsetof(scanparmRecord, lstp);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(scanparmRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_scanparmRecord_H */
