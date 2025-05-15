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
    prt->papFldDes[scanparmRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[scanparmRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[scanparmRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[scanparmRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[scanparmRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[scanparmRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[scanparmRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[scanparmRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[scanparmRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[scanparmRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[scanparmRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[scanparmRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[scanparmRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[scanparmRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[scanparmRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[scanparmRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[scanparmRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[scanparmRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[scanparmRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[scanparmRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[scanparmRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[scanparmRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[scanparmRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[scanparmRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[scanparmRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[scanparmRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[scanparmRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[scanparmRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[scanparmRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[scanparmRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[scanparmRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[scanparmRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[scanparmRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[scanparmRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[scanparmRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[scanparmRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[scanparmRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[scanparmRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[scanparmRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[scanparmRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[scanparmRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[scanparmRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[scanparmRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[scanparmRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[scanparmRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[scanparmRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[scanparmRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[scanparmRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[scanparmRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[scanparmRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[scanparmRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[scanparmRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[scanparmRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[scanparmRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[scanparmRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[scanparmRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[scanparmRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[scanparmRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[scanparmRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[scanparmRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[scanparmRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[scanparmRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[scanparmRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[scanparmRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[scanparmRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[scanparmRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[scanparmRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[scanparmRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[scanparmRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[scanparmRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[scanparmRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[scanparmRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[scanparmRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[scanparmRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[scanparmRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[scanparmRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[scanparmRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[scanparmRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[scanparmRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[scanparmRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[scanparmRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[scanparmRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[scanparmRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[scanparmRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[scanparmRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[scanparmRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[scanparmRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[scanparmRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[scanparmRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[scanparmRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[scanparmRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[scanparmRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[scanparmRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[scanparmRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[scanparmRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[scanparmRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[scanparmRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[scanparmRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[scanparmRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[scanparmRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[scanparmRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[scanparmRecordPRE]->size = sizeof(prec->pre);
    prt->papFldDes[scanparmRecordPRE]->offset = (unsigned short)((char *)&prec->pre - (char *)prec);
    prt->papFldDes[scanparmRecordOPRE]->size = sizeof(prec->opre);
    prt->papFldDes[scanparmRecordOPRE]->offset = (unsigned short)((char *)&prec->opre - (char *)prec);
    prt->papFldDes[scanparmRecordSM]->size = sizeof(prec->sm);
    prt->papFldDes[scanparmRecordSM]->offset = (unsigned short)((char *)&prec->sm - (char *)prec);
    prt->papFldDes[scanparmRecordOSM]->size = sizeof(prec->osm);
    prt->papFldDes[scanparmRecordOSM]->offset = (unsigned short)((char *)&prec->osm - (char *)prec);
    prt->papFldDes[scanparmRecordAR]->size = sizeof(prec->ar);
    prt->papFldDes[scanparmRecordAR]->offset = (unsigned short)((char *)&prec->ar - (char *)prec);
    prt->papFldDes[scanparmRecordOAR]->size = sizeof(prec->oar);
    prt->papFldDes[scanparmRecordOAR]->offset = (unsigned short)((char *)&prec->oar - (char *)prec);
    prt->papFldDes[scanparmRecordAFT]->size = sizeof(prec->aft);
    prt->papFldDes[scanparmRecordAFT]->offset = (unsigned short)((char *)&prec->aft - (char *)prec);
    prt->papFldDes[scanparmRecordOAFT]->size = sizeof(prec->oaft);
    prt->papFldDes[scanparmRecordOAFT]->offset = (unsigned short)((char *)&prec->oaft - (char *)prec);
    prt->papFldDes[scanparmRecordPPV]->size = sizeof(prec->ppv);
    prt->papFldDes[scanparmRecordPPV]->offset = (unsigned short)((char *)&prec->ppv - (char *)prec);
    prt->papFldDes[scanparmRecordRPV]->size = sizeof(prec->rpv);
    prt->papFldDes[scanparmRecordRPV]->offset = (unsigned short)((char *)&prec->rpv - (char *)prec);
    prt->papFldDes[scanparmRecordDPV]->size = sizeof(prec->dpv);
    prt->papFldDes[scanparmRecordDPV]->offset = (unsigned short)((char *)&prec->dpv - (char *)prec);
    prt->papFldDes[scanparmRecordTPV]->size = sizeof(prec->tpv);
    prt->papFldDes[scanparmRecordTPV]->offset = (unsigned short)((char *)&prec->tpv - (char *)prec);
    prt->papFldDes[scanparmRecordOPPV]->size = sizeof(prec->oppv);
    prt->papFldDes[scanparmRecordOPPV]->offset = (unsigned short)((char *)&prec->oppv - (char *)prec);
    prt->papFldDes[scanparmRecordORPV]->size = sizeof(prec->orpv);
    prt->papFldDes[scanparmRecordORPV]->offset = (unsigned short)((char *)&prec->orpv - (char *)prec);
    prt->papFldDes[scanparmRecordODPV]->size = sizeof(prec->odpv);
    prt->papFldDes[scanparmRecordODPV]->offset = (unsigned short)((char *)&prec->odpv - (char *)prec);
    prt->papFldDes[scanparmRecordOTPV]->size = sizeof(prec->otpv);
    prt->papFldDes[scanparmRecordOTPV]->offset = (unsigned short)((char *)&prec->otpv - (char *)prec);
    prt->papFldDes[scanparmRecordSP]->size = sizeof(prec->sp);
    prt->papFldDes[scanparmRecordSP]->offset = (unsigned short)((char *)&prec->sp - (char *)prec);
    prt->papFldDes[scanparmRecordOSP]->size = sizeof(prec->osp);
    prt->papFldDes[scanparmRecordOSP]->offset = (unsigned short)((char *)&prec->osp - (char *)prec);
    prt->papFldDes[scanparmRecordEP]->size = sizeof(prec->ep);
    prt->papFldDes[scanparmRecordEP]->offset = (unsigned short)((char *)&prec->ep - (char *)prec);
    prt->papFldDes[scanparmRecordOEP]->size = sizeof(prec->oep);
    prt->papFldDes[scanparmRecordOEP]->offset = (unsigned short)((char *)&prec->oep - (char *)prec);
    prt->papFldDes[scanparmRecordNP]->size = sizeof(prec->np);
    prt->papFldDes[scanparmRecordNP]->offset = (unsigned short)((char *)&prec->np - (char *)prec);
    prt->papFldDes[scanparmRecordONP]->size = sizeof(prec->onp);
    prt->papFldDes[scanparmRecordONP]->offset = (unsigned short)((char *)&prec->onp - (char *)prec);
    prt->papFldDes[scanparmRecordSC]->size = sizeof(prec->sc);
    prt->papFldDes[scanparmRecordSC]->offset = (unsigned short)((char *)&prec->sc - (char *)prec);
    prt->papFldDes[scanparmRecordOSC]->size = sizeof(prec->osc);
    prt->papFldDes[scanparmRecordOSC]->offset = (unsigned short)((char *)&prec->osc - (char *)prec);
    prt->papFldDes[scanparmRecordAQT]->size = sizeof(prec->aqt);
    prt->papFldDes[scanparmRecordAQT]->offset = (unsigned short)((char *)&prec->aqt - (char *)prec);
    prt->papFldDes[scanparmRecordOAQT]->size = sizeof(prec->oaqt);
    prt->papFldDes[scanparmRecordOAQT]->offset = (unsigned short)((char *)&prec->oaqt - (char *)prec);
    prt->papFldDes[scanparmRecordMP]->size = sizeof(prec->mp);
    prt->papFldDes[scanparmRecordMP]->offset = (unsigned short)((char *)&prec->mp - (char *)prec);
    prt->papFldDes[scanparmRecordIMP]->size = sizeof(prec->imp);
    prt->papFldDes[scanparmRecordIMP]->offset = (unsigned short)((char *)&prec->imp - (char *)prec);
    prt->papFldDes[scanparmRecordACT]->size = sizeof(prec->act);
    prt->papFldDes[scanparmRecordACT]->offset = (unsigned short)((char *)&prec->act - (char *)prec);
    prt->papFldDes[scanparmRecordIACT]->size = sizeof(prec->iact);
    prt->papFldDes[scanparmRecordIACT]->offset = (unsigned short)((char *)&prec->iact - (char *)prec);
    prt->papFldDes[scanparmRecordLOAD]->size = sizeof(prec->load);
    prt->papFldDes[scanparmRecordLOAD]->offset = (unsigned short)((char *)&prec->load - (char *)prec);
    prt->papFldDes[scanparmRecordOLOAD]->size = sizeof(prec->oload);
    prt->papFldDes[scanparmRecordOLOAD]->offset = (unsigned short)((char *)&prec->oload - (char *)prec);
    prt->papFldDes[scanparmRecordGO]->size = sizeof(prec->go);
    prt->papFldDes[scanparmRecordGO]->offset = (unsigned short)((char *)&prec->go - (char *)prec);
    prt->papFldDes[scanparmRecordOGO]->size = sizeof(prec->ogo);
    prt->papFldDes[scanparmRecordOGO]->offset = (unsigned short)((char *)&prec->ogo - (char *)prec);
    prt->papFldDes[scanparmRecordSTEP]->size = sizeof(prec->step);
    prt->papFldDes[scanparmRecordSTEP]->offset = (unsigned short)((char *)&prec->step - (char *)prec);
    prt->papFldDes[scanparmRecordLSTP]->size = sizeof(prec->lstp);
    prt->papFldDes[scanparmRecordLSTP]->offset = (unsigned short)((char *)&prec->lstp - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(scanparmRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_scanparmRecord_H */
