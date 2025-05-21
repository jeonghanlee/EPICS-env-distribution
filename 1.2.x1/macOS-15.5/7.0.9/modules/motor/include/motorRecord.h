/** @file motorRecord.h
 * @brief Declarations for the @ref motorRecord "motor" record type.
 *
 * This header was generated from motorRecord.dbd
 */

#ifndef INC_motorRecord_H
#define INC_motorRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef motorUEIP_NUM_CHOICES
/** @brief Enumerated type from menu motorUEIP */
typedef enum {
    motorUEIP_No                    /**< @brief State string "No" */,
    motorUEIP_Yes                   /**< @brief State string "Yes" */
} motorUEIP;
/** @brief Number of states defined for menu motorUEIP */
#define motorUEIP_NUM_CHOICES 2
#endif

#ifndef menuOmsl_NUM_CHOICES
/** @brief Enumerated type from menu menuOmsl */
typedef enum {
    menuOmslsupervisory             /**< @brief State string "supervisory" */,
    menuOmslclosed_loop             /**< @brief State string "closed_loop" */
} menuOmsl;
/** @brief Number of states defined for menu menuOmsl */
#define menuOmsl_NUM_CHOICES 2
#endif

#ifndef motorFOFF_NUM_CHOICES
/** @brief Enumerated type from menu motorFOFF */
typedef enum {
    motorFOFF_Variable              /**< @brief State string "Variable" */,
    motorFOFF_Frozen                /**< @brief State string "Frozen" */
} motorFOFF;
/** @brief Number of states defined for menu motorFOFF */
#define motorFOFF_NUM_CHOICES 2
#endif

#ifndef motorSET_NUM_CHOICES
/** @brief Enumerated type from menu motorSET */
typedef enum {
    motorSET_Use                    /**< @brief State string "Use" */,
    motorSET_Set                    /**< @brief State string "Set" */
} motorSET;
/** @brief Number of states defined for menu motorSET */
#define motorSET_NUM_CHOICES 2
#endif

#ifndef motorRMOD_NUM_CHOICES
/** @brief Enumerated type from menu motorRMOD */
typedef enum {
    motorRMOD_D                     /**< @brief State string "Default" */,
    motorRMOD_A                     /**< @brief State string "Arithmetic" */,
    motorRMOD_G                     /**< @brief State string "Geometric" */,
    motorRMOD_I                     /**< @brief State string "In-Position" */
} motorRMOD;
/** @brief Number of states defined for menu motorRMOD */
#define motorRMOD_NUM_CHOICES 4
#endif

#ifndef motorTORQ_NUM_CHOICES
/** @brief Enumerated type from menu motorTORQ */
typedef enum {
    motorTORQ_Disable               /**< @brief State string "Disable" */,
    motorTORQ_Enable                /**< @brief State string "Enable" */
} motorTORQ;
/** @brief Number of states defined for menu motorTORQ */
#define motorTORQ_NUM_CHOICES 2
#endif

#ifndef motorMODE_NUM_CHOICES
/** @brief Enumerated type from menu motorMODE */
typedef enum {
    motorMODE_Position              /**< @brief State string "Position" */,
    motorMODE_Velocity              /**< @brief State string "Velocity" */
} motorMODE;
/** @brief Number of states defined for menu motorMODE */
#define motorMODE_NUM_CHOICES 2
#endif

#ifndef menuYesNo_NUM_CHOICES
/** @brief Enumerated type from menu menuYesNo */
typedef enum {
    menuYesNoNO                     /**< @brief State string "NO" */,
    menuYesNoYES                    /**< @brief State string "YES" */
} menuYesNo;
/** @brief Number of states defined for menu menuYesNo */
#define menuYesNo_NUM_CHOICES 2
#endif

#ifndef motorACCU_NUM_CHOICES
/** @brief Enumerated type from menu motorACCU */
typedef enum {
    motorACCU_Accl                  /**< @brief State string "Use ACCL" */,
    motorACCU_Accs                  /**< @brief State string "Use ACCS" */
} motorACCU;
/** @brief Number of states defined for menu motorACCU */
#define motorACCU_NUM_CHOICES 2
#endif

#ifndef motorRSTM_NUM_CHOICES
/** @brief Enumerated type from menu motorRSTM */
typedef enum {
    motorRSTM_Never                 /**< @brief State string "Never" */,
    motorRSTM_Always                /**< @brief State string "Always" */,
    motorRSTM_NearZero              /**< @brief State string "NearZero" */,
    motorRSTM_Conditional           /**< @brief State string "Conditional" */
} motorRSTM;
/** @brief Number of states defined for menu motorRSTM */
#define motorRSTM_NUM_CHOICES 4
#endif

#ifndef motorDIR_NUM_CHOICES
/** @brief Enumerated type from menu motorDIR */
typedef enum {
    motorDIR_Pos                    /**< @brief State string "Pos" */,
    motorDIR_Neg                    /**< @brief State string "Neg" */
} motorDIR;
/** @brief Number of states defined for menu motorDIR */
#define motorDIR_NUM_CHOICES 2
#endif

#ifndef motorSPMG_NUM_CHOICES
/** @brief Enumerated type from menu motorSPMG */
typedef enum {
    motorSPMG_Stop                  /**< @brief State string "Stop" */,
    motorSPMG_Pause                 /**< @brief State string "Pause" */,
    motorSPMG_Move                  /**< @brief State string "Move" */,
    motorSPMG_Go                    /**< @brief State string "Go" */
} motorSPMG;
/** @brief Number of states defined for menu motorSPMG */
#define motorSPMG_NUM_CHOICES 4
#endif

#ifndef motorSTUP_NUM_CHOICES
/** @brief Enumerated type from menu motorSTUP */
typedef enum {
    motorSTUP_OFF                   /**< @brief State string "OFF" */,
    motorSTUP_ON                    /**< @brief State string "ON" */,
    motorSTUP_BUSY                  /**< @brief State string "BUSY" */
} motorSTUP;
/** @brief Number of states defined for menu motorSTUP */
#define motorSTUP_NUM_CHOICES 3
#endif

/** @brief Declaration of motor record type. */
typedef struct motorRecord {
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
    epicsFloat64        off;        /**< @brief User Offset (EGU) */
    epicsEnum16         foff;       /**< @brief Offset-Freeze Switch */
    epicsInt16          fof;        /**< @brief Freeze Offset */
    epicsInt16          vof;        /**< @brief Variable Offset */
    epicsEnum16         dir;        /**< @brief User Direction */
    epicsEnum16         set;        /**< @brief Set/Use Switch */
    epicsInt16          sset;       /**< @brief Set SET Mode */
    epicsInt16          suse;       /**< @brief Set USE Mode */
    epicsFloat64        velo;       /**< @brief Velocity (EGU/s) */
    epicsFloat64        vbas;       /**< @brief Base Velocity (EGU/s) */
    epicsFloat64        vmax;       /**< @brief Max. Velocity (EGU/s) */
    epicsFloat64        s;          /**< @brief Speed (revolutions/sec) */
    epicsFloat64        sbas;       /**< @brief Base Speed (RPS) */
    epicsFloat64        smax;       /**< @brief Max. Speed (RPS) */
    epicsFloat64        accl;       /**< @brief Seconds to Velocity */
    epicsFloat64        accs;       /**< @brief Move Accel. (EGU/s^2) */
    epicsEnum16         accu;       /**< @brief Acceleration used */
    epicsFloat64        bdst;       /**< @brief BL Distance (EGU) */
    epicsFloat64        bvel;       /**< @brief BL Velocity (EGU/s) */
    epicsFloat64        sbak;       /**< @brief BL Speed (RPS) */
    epicsFloat64        bacc;       /**< @brief BL Seconds to Velocity */
    epicsFloat32        frac;       /**< @brief Move Fraction */
    DBLINK              out;        /**< @brief Output Specification */
    epicsInt16          card;       /**< @brief Card Number */
    DBLINK              rdbl;       /**< @brief Readback Location */
    DBLINK              dol;        /**< @brief Desired Output Loc */
    epicsEnum16         omsl;       /**< @brief Output Mode Select */
    DBLINK              rlnk;       /**< @brief Readback OutLink */
    epicsInt32          srev;       /**< @brief Steps per Revolution */
    epicsFloat64        urev;       /**< @brief EGU's per Revolution */
    epicsFloat64        mres;       /**< @brief Motor Step Size (EGU) */
    epicsFloat64        eres;       /**< @brief Encoder Step Size (EGU) */
    epicsFloat64        rres;       /**< @brief Readback Step Size (EGU */
    epicsEnum16         ueip;       /**< @brief Use Encoder If Present */
    epicsEnum16         urip;       /**< @brief Use RDBL Link If Presen */
    epicsInt16          prec;       /**< @brief Display Precision */
    char                egu[16];    /**< @brief Engineering Units */
    epicsFloat64        rhlm;       /**< @brief Raw High Limit */
    epicsFloat64        rllm;       /**< @brief Raw Low Limit */
    epicsFloat64        hlm;        /**< @brief User High Limit */
    epicsFloat64        llm;        /**< @brief User Low Limit */
    epicsFloat64        dhlm;       /**< @brief Dial High Limit */
    epicsFloat64        dllm;       /**< @brief Dial Low Limit */
    epicsFloat64        hopr;       /**< @brief High Operating Range */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsInt16          hls;        /**< @brief User High Limit Switch */
    epicsInt16          lls;        /**< @brief User Low Limit Switch */
    epicsInt16          rhls;       /**< @brief Raw High Limit Switch */
    epicsInt16          rlls;       /**< @brief Raw Low Limit Switch */
    epicsFloat64        hihi;       /**< @brief Hihi Alarm Limit (EGU) */
    epicsFloat64        lolo;       /**< @brief Lolo Alarm Limit (EGU) */
    epicsFloat64        high;       /**< @brief High Alarm Limit (EGU) */
    epicsFloat64        low;        /**< @brief Low Alarm Limit (EGU) */
    epicsEnum16         hhsv;       /**< @brief Hihi Severity */
    epicsEnum16         llsv;       /**< @brief Lolo Severity */
    epicsEnum16         hsv;        /**< @brief High Severity */
    epicsEnum16         lsv;        /**< @brief Low Severity */
    epicsEnum16         hlsv;       /**< @brief HW Limit Violation Svr */
    epicsFloat64        rdbd;       /**< @brief Retry Deadband (EGU) */
    epicsFloat64        spdb;       /**< @brief Setpoint Deadband (EGU) */
    epicsInt16          rcnt;       /**< @brief Retry count */
    epicsInt16          rtry;       /**< @brief Max retry count */
    epicsInt16          miss;       /**< @brief Ran out of retries */
    epicsEnum16         spmg;       /**< @brief Stop/Pause/Move/Go */
    epicsEnum16         lspg;       /**< @brief Last SPMG */
    epicsInt16          stop;       /**< @brief Stop */
    epicsInt16          homf;       /**< @brief Home Forward */
    epicsInt16          homr;       /**< @brief Home Reverse */
    epicsInt16          jogf;       /**< @brief Jog motor Forward */
    epicsInt16          jogr;       /**< @brief Jog motor Reverse */
    epicsInt16          twf;        /**< @brief Tweak motor Forward */
    epicsInt16          twr;        /**< @brief Tweak motor Reverse */
    epicsFloat64        twv;        /**< @brief Tweak Step Size (EGU) */
    epicsFloat64        val;        /**< @brief User Desired Value (EGU */
    epicsFloat64        lval;       /**< @brief Last User Des Val (EGU) */
    epicsFloat64        dval;       /**< @brief Dial Desired Value (EGU */
    epicsFloat64        ldvl;       /**< @brief Last Dial Des Val (EGU) */
    epicsInt32          rval;       /**< @brief Raw Desired Value (step */
    epicsInt32          lrvl;       /**< @brief Last Raw Des Val (steps */
    epicsFloat64        rlv;        /**< @brief Relative Value (EGU) */
    epicsFloat64        lrlv;       /**< @brief Last Rel Value (EGU) */
    epicsFloat64        rbv;        /**< @brief User Readback Value */
    epicsFloat64        drbv;       /**< @brief Dial Readback Value */
    epicsFloat64        diff;       /**< @brief Difference dval-drbv */
    epicsInt32          rdif;       /**< @brief Difference rval-rrbv */
    epicsInt16          cdir;       /**< @brief Raw cmnd direction */
    epicsInt32          rrbv;       /**< @brief Raw Readback Value */
    epicsInt32          rmp;        /**< @brief Raw Motor Position */
    epicsInt32          rep;        /**< @brief Raw Encoder Position */
    epicsInt32          rvel;       /**< @brief Raw Velocity */
    epicsInt16          dmov;       /**< @brief Done moving to value */
    epicsInt16          movn;       /**< @brief Motor is moving */
    epicsUInt32         msta;       /**< @brief Motor Status */
    epicsInt16          lvio;       /**< @brief Limit violation */
    epicsInt16          tdir;       /**< @brief Direction of Travel */
    epicsInt16          athm;       /**< @brief At HOME */
    epicsInt16          pp;         /**< @brief Post process command */
    epicsUInt16         mip;        /**< @brief Motion In Progress */
    epicsUInt32         mmap;       /**< @brief Monitor Mask */
    epicsUInt32         nmap;       /**< @brief Monitor Mask (more) */
    epicsFloat64        dly;        /**< @brief Readback settle time (s) */
    void             *cbak;         /**< @brief Callback structure */
    epicsFloat64        pcof;       /**< @brief Proportional Gain */
    epicsFloat64        icof;       /**< @brief Integral Gain */
    epicsFloat64        dcof;       /**< @brief Derivative Gain */
    epicsEnum16         cnen;       /**< @brief Enable control */
    char                init[40];   /**< @brief Startup commands */
    char                prem[40];   /**< @brief Pre-move commands */
    char                post[40];   /**< @brief Post-move commands */
    DBLINK              stoo;       /**< @brief STOP OutLink */
    DBLINK              dinp;       /**< @brief DMOV Input Link */
    DBLINK              rinp;       /**< @brief RMP Input Link */
    epicsFloat64        jvel;       /**< @brief Jog Velocity (EGU/s) */
    epicsFloat64        jar;        /**< @brief Jog Accel. (EGU/s^2) */
    epicsEnum16         lock;       /**< @brief Soft Channel Position Lock */
    epicsEnum16         ntm;        /**< @brief New Target Monitor */
    epicsUInt16         ntmf;       /**< @brief NTM Deadband Factor */
    epicsFloat64        hvel;       /**< @brief Home Velocity (EGU/s) */
    epicsEnum16         stup;       /**< @brief Status Update */
    epicsEnum16         rmod;       /**< @brief Retry Mode */
    epicsFloat64        adel;       /**< @brief Archive Deadband */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsFloat64        alst;       /**< @brief Last Value Archived */
    epicsFloat64        mlst;       /**< @brief Last Val Monitored */
    epicsInt16          sync;       /**< @brief Sync position */
    epicsInt16          igset;      /**< @brief Ignore SET field */
    epicsEnum16         rstm;       /**< @brief Restore Mode */
} motorRecord;

typedef enum {
	motorRecordNAME = 0,
	motorRecordDESC = 1,
	motorRecordASG = 2,
	motorRecordSCAN = 3,
	motorRecordPINI = 4,
	motorRecordPHAS = 5,
	motorRecordEVNT = 6,
	motorRecordTSE = 7,
	motorRecordTSEL = 8,
	motorRecordDTYP = 9,
	motorRecordDISV = 10,
	motorRecordDISA = 11,
	motorRecordSDIS = 12,
	motorRecordMLOK = 13,
	motorRecordMLIS = 14,
	motorRecordBKLNK = 15,
	motorRecordDISP = 16,
	motorRecordPROC = 17,
	motorRecordSTAT = 18,
	motorRecordSEVR = 19,
	motorRecordAMSG = 20,
	motorRecordNSTA = 21,
	motorRecordNSEV = 22,
	motorRecordNAMSG = 23,
	motorRecordACKS = 24,
	motorRecordACKT = 25,
	motorRecordDISS = 26,
	motorRecordLCNT = 27,
	motorRecordPACT = 28,
	motorRecordPUTF = 29,
	motorRecordRPRO = 30,
	motorRecordASP = 31,
	motorRecordPPN = 32,
	motorRecordPPNR = 33,
	motorRecordSPVT = 34,
	motorRecordRSET = 35,
	motorRecordDSET = 36,
	motorRecordDPVT = 37,
	motorRecordRDES = 38,
	motorRecordLSET = 39,
	motorRecordPRIO = 40,
	motorRecordTPRO = 41,
	motorRecordBKPT = 42,
	motorRecordUDF = 43,
	motorRecordUDFS = 44,
	motorRecordTIME = 45,
	motorRecordUTAG = 46,
	motorRecordFLNK = 47,
	motorRecordVERS = 48,
	motorRecordOFF = 49,
	motorRecordFOFF = 50,
	motorRecordFOF = 51,
	motorRecordVOF = 52,
	motorRecordDIR = 53,
	motorRecordSET = 54,
	motorRecordSSET = 55,
	motorRecordSUSE = 56,
	motorRecordVELO = 57,
	motorRecordVBAS = 58,
	motorRecordVMAX = 59,
	motorRecordS = 60,
	motorRecordSBAS = 61,
	motorRecordSMAX = 62,
	motorRecordACCL = 63,
	motorRecordACCS = 64,
	motorRecordACCU = 65,
	motorRecordBDST = 66,
	motorRecordBVEL = 67,
	motorRecordSBAK = 68,
	motorRecordBACC = 69,
	motorRecordFRAC = 70,
	motorRecordOUT = 71,
	motorRecordCARD = 72,
	motorRecordRDBL = 73,
	motorRecordDOL = 74,
	motorRecordOMSL = 75,
	motorRecordRLNK = 76,
	motorRecordSREV = 77,
	motorRecordUREV = 78,
	motorRecordMRES = 79,
	motorRecordERES = 80,
	motorRecordRRES = 81,
	motorRecordUEIP = 82,
	motorRecordURIP = 83,
	motorRecordPREC = 84,
	motorRecordEGU = 85,
	motorRecordRHLM = 86,
	motorRecordRLLM = 87,
	motorRecordHLM = 88,
	motorRecordLLM = 89,
	motorRecordDHLM = 90,
	motorRecordDLLM = 91,
	motorRecordHOPR = 92,
	motorRecordLOPR = 93,
	motorRecordHLS = 94,
	motorRecordLLS = 95,
	motorRecordRHLS = 96,
	motorRecordRLLS = 97,
	motorRecordHIHI = 98,
	motorRecordLOLO = 99,
	motorRecordHIGH = 100,
	motorRecordLOW = 101,
	motorRecordHHSV = 102,
	motorRecordLLSV = 103,
	motorRecordHSV = 104,
	motorRecordLSV = 105,
	motorRecordHLSV = 106,
	motorRecordRDBD = 107,
	motorRecordSPDB = 108,
	motorRecordRCNT = 109,
	motorRecordRTRY = 110,
	motorRecordMISS = 111,
	motorRecordSPMG = 112,
	motorRecordLSPG = 113,
	motorRecordSTOP = 114,
	motorRecordHOMF = 115,
	motorRecordHOMR = 116,
	motorRecordJOGF = 117,
	motorRecordJOGR = 118,
	motorRecordTWF = 119,
	motorRecordTWR = 120,
	motorRecordTWV = 121,
	motorRecordVAL = 122,
	motorRecordLVAL = 123,
	motorRecordDVAL = 124,
	motorRecordLDVL = 125,
	motorRecordRVAL = 126,
	motorRecordLRVL = 127,
	motorRecordRLV = 128,
	motorRecordLRLV = 129,
	motorRecordRBV = 130,
	motorRecordDRBV = 131,
	motorRecordDIFF = 132,
	motorRecordRDIF = 133,
	motorRecordCDIR = 134,
	motorRecordRRBV = 135,
	motorRecordRMP = 136,
	motorRecordREP = 137,
	motorRecordRVEL = 138,
	motorRecordDMOV = 139,
	motorRecordMOVN = 140,
	motorRecordMSTA = 141,
	motorRecordLVIO = 142,
	motorRecordTDIR = 143,
	motorRecordATHM = 144,
	motorRecordPP = 145,
	motorRecordMIP = 146,
	motorRecordMMAP = 147,
	motorRecordNMAP = 148,
	motorRecordDLY = 149,
	motorRecordCBAK = 150,
	motorRecordPCOF = 151,
	motorRecordICOF = 152,
	motorRecordDCOF = 153,
	motorRecordCNEN = 154,
	motorRecordINIT = 155,
	motorRecordPREM = 156,
	motorRecordPOST = 157,
	motorRecordSTOO = 158,
	motorRecordDINP = 159,
	motorRecordRINP = 160,
	motorRecordJVEL = 161,
	motorRecordJAR = 162,
	motorRecordLOCK = 163,
	motorRecordNTM = 164,
	motorRecordNTMF = 165,
	motorRecordHVEL = 166,
	motorRecordSTUP = 167,
	motorRecordRMOD = 168,
	motorRecordADEL = 169,
	motorRecordMDEL = 170,
	motorRecordALST = 171,
	motorRecordMLST = 172,
	motorRecordSYNC = 173,
	motorRecordIGSET = 174,
	motorRecordRSTM = 175
} motorFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int motorRecordSizeOffset(dbRecordType *prt)
{
    motorRecord *prec = 0;

    if (prt->no_fields != 176) {
        cantProceed("IOC build or installation error:\n"
            "    The motorRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 176.\n",
            prt->no_fields);
    }
    prt->papFldDes[motorRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[motorRecordNAME]->offset = (unsigned short)offsetof(motorRecord, name);
    prt->papFldDes[motorRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[motorRecordDESC]->offset = (unsigned short)offsetof(motorRecord, desc);
    prt->papFldDes[motorRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[motorRecordASG]->offset = (unsigned short)offsetof(motorRecord, asg);
    prt->papFldDes[motorRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[motorRecordSCAN]->offset = (unsigned short)offsetof(motorRecord, scan);
    prt->papFldDes[motorRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[motorRecordPINI]->offset = (unsigned short)offsetof(motorRecord, pini);
    prt->papFldDes[motorRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[motorRecordPHAS]->offset = (unsigned short)offsetof(motorRecord, phas);
    prt->papFldDes[motorRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[motorRecordEVNT]->offset = (unsigned short)offsetof(motorRecord, evnt);
    prt->papFldDes[motorRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[motorRecordTSE]->offset = (unsigned short)offsetof(motorRecord, tse);
    prt->papFldDes[motorRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[motorRecordTSEL]->offset = (unsigned short)offsetof(motorRecord, tsel);
    prt->papFldDes[motorRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[motorRecordDTYP]->offset = (unsigned short)offsetof(motorRecord, dtyp);
    prt->papFldDes[motorRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[motorRecordDISV]->offset = (unsigned short)offsetof(motorRecord, disv);
    prt->papFldDes[motorRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[motorRecordDISA]->offset = (unsigned short)offsetof(motorRecord, disa);
    prt->papFldDes[motorRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[motorRecordSDIS]->offset = (unsigned short)offsetof(motorRecord, sdis);
    prt->papFldDes[motorRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[motorRecordMLOK]->offset = (unsigned short)offsetof(motorRecord, mlok);
    prt->papFldDes[motorRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[motorRecordMLIS]->offset = (unsigned short)offsetof(motorRecord, mlis);
    prt->papFldDes[motorRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[motorRecordBKLNK]->offset = (unsigned short)offsetof(motorRecord, bklnk);
    prt->papFldDes[motorRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[motorRecordDISP]->offset = (unsigned short)offsetof(motorRecord, disp);
    prt->papFldDes[motorRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[motorRecordPROC]->offset = (unsigned short)offsetof(motorRecord, proc);
    prt->papFldDes[motorRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[motorRecordSTAT]->offset = (unsigned short)offsetof(motorRecord, stat);
    prt->papFldDes[motorRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[motorRecordSEVR]->offset = (unsigned short)offsetof(motorRecord, sevr);
    prt->papFldDes[motorRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[motorRecordAMSG]->offset = (unsigned short)offsetof(motorRecord, amsg);
    prt->papFldDes[motorRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[motorRecordNSTA]->offset = (unsigned short)offsetof(motorRecord, nsta);
    prt->papFldDes[motorRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[motorRecordNSEV]->offset = (unsigned short)offsetof(motorRecord, nsev);
    prt->papFldDes[motorRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[motorRecordNAMSG]->offset = (unsigned short)offsetof(motorRecord, namsg);
    prt->papFldDes[motorRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[motorRecordACKS]->offset = (unsigned short)offsetof(motorRecord, acks);
    prt->papFldDes[motorRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[motorRecordACKT]->offset = (unsigned short)offsetof(motorRecord, ackt);
    prt->papFldDes[motorRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[motorRecordDISS]->offset = (unsigned short)offsetof(motorRecord, diss);
    prt->papFldDes[motorRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[motorRecordLCNT]->offset = (unsigned short)offsetof(motorRecord, lcnt);
    prt->papFldDes[motorRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[motorRecordPACT]->offset = (unsigned short)offsetof(motorRecord, pact);
    prt->papFldDes[motorRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[motorRecordPUTF]->offset = (unsigned short)offsetof(motorRecord, putf);
    prt->papFldDes[motorRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[motorRecordRPRO]->offset = (unsigned short)offsetof(motorRecord, rpro);
    prt->papFldDes[motorRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[motorRecordASP]->offset = (unsigned short)offsetof(motorRecord, asp);
    prt->papFldDes[motorRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[motorRecordPPN]->offset = (unsigned short)offsetof(motorRecord, ppn);
    prt->papFldDes[motorRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[motorRecordPPNR]->offset = (unsigned short)offsetof(motorRecord, ppnr);
    prt->papFldDes[motorRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[motorRecordSPVT]->offset = (unsigned short)offsetof(motorRecord, spvt);
    prt->papFldDes[motorRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[motorRecordRSET]->offset = (unsigned short)offsetof(motorRecord, rset);
    prt->papFldDes[motorRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[motorRecordDSET]->offset = (unsigned short)offsetof(motorRecord, dset);
    prt->papFldDes[motorRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[motorRecordDPVT]->offset = (unsigned short)offsetof(motorRecord, dpvt);
    prt->papFldDes[motorRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[motorRecordRDES]->offset = (unsigned short)offsetof(motorRecord, rdes);
    prt->papFldDes[motorRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[motorRecordLSET]->offset = (unsigned short)offsetof(motorRecord, lset);
    prt->papFldDes[motorRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[motorRecordPRIO]->offset = (unsigned short)offsetof(motorRecord, prio);
    prt->papFldDes[motorRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[motorRecordTPRO]->offset = (unsigned short)offsetof(motorRecord, tpro);
    prt->papFldDes[motorRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[motorRecordBKPT]->offset = (unsigned short)offsetof(motorRecord, bkpt);
    prt->papFldDes[motorRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[motorRecordUDF]->offset = (unsigned short)offsetof(motorRecord, udf);
    prt->papFldDes[motorRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[motorRecordUDFS]->offset = (unsigned short)offsetof(motorRecord, udfs);
    prt->papFldDes[motorRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[motorRecordTIME]->offset = (unsigned short)offsetof(motorRecord, time);
    prt->papFldDes[motorRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[motorRecordUTAG]->offset = (unsigned short)offsetof(motorRecord, utag);
    prt->papFldDes[motorRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[motorRecordFLNK]->offset = (unsigned short)offsetof(motorRecord, flnk);
    prt->papFldDes[motorRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[motorRecordVERS]->offset = (unsigned short)offsetof(motorRecord, vers);
    prt->papFldDes[motorRecordOFF]->size = sizeof(prec->off);
    prt->papFldDes[motorRecordOFF]->offset = (unsigned short)offsetof(motorRecord, off);
    prt->papFldDes[motorRecordFOFF]->size = sizeof(prec->foff);
    prt->papFldDes[motorRecordFOFF]->offset = (unsigned short)offsetof(motorRecord, foff);
    prt->papFldDes[motorRecordFOF]->size = sizeof(prec->fof);
    prt->papFldDes[motorRecordFOF]->offset = (unsigned short)offsetof(motorRecord, fof);
    prt->papFldDes[motorRecordVOF]->size = sizeof(prec->vof);
    prt->papFldDes[motorRecordVOF]->offset = (unsigned short)offsetof(motorRecord, vof);
    prt->papFldDes[motorRecordDIR]->size = sizeof(prec->dir);
    prt->papFldDes[motorRecordDIR]->offset = (unsigned short)offsetof(motorRecord, dir);
    prt->papFldDes[motorRecordSET]->size = sizeof(prec->set);
    prt->papFldDes[motorRecordSET]->offset = (unsigned short)offsetof(motorRecord, set);
    prt->papFldDes[motorRecordSSET]->size = sizeof(prec->sset);
    prt->papFldDes[motorRecordSSET]->offset = (unsigned short)offsetof(motorRecord, sset);
    prt->papFldDes[motorRecordSUSE]->size = sizeof(prec->suse);
    prt->papFldDes[motorRecordSUSE]->offset = (unsigned short)offsetof(motorRecord, suse);
    prt->papFldDes[motorRecordVELO]->size = sizeof(prec->velo);
    prt->papFldDes[motorRecordVELO]->offset = (unsigned short)offsetof(motorRecord, velo);
    prt->papFldDes[motorRecordVBAS]->size = sizeof(prec->vbas);
    prt->papFldDes[motorRecordVBAS]->offset = (unsigned short)offsetof(motorRecord, vbas);
    prt->papFldDes[motorRecordVMAX]->size = sizeof(prec->vmax);
    prt->papFldDes[motorRecordVMAX]->offset = (unsigned short)offsetof(motorRecord, vmax);
    prt->papFldDes[motorRecordS]->size = sizeof(prec->s);
    prt->papFldDes[motorRecordS]->offset = (unsigned short)offsetof(motorRecord, s);
    prt->papFldDes[motorRecordSBAS]->size = sizeof(prec->sbas);
    prt->papFldDes[motorRecordSBAS]->offset = (unsigned short)offsetof(motorRecord, sbas);
    prt->papFldDes[motorRecordSMAX]->size = sizeof(prec->smax);
    prt->papFldDes[motorRecordSMAX]->offset = (unsigned short)offsetof(motorRecord, smax);
    prt->papFldDes[motorRecordACCL]->size = sizeof(prec->accl);
    prt->papFldDes[motorRecordACCL]->offset = (unsigned short)offsetof(motorRecord, accl);
    prt->papFldDes[motorRecordACCS]->size = sizeof(prec->accs);
    prt->papFldDes[motorRecordACCS]->offset = (unsigned short)offsetof(motorRecord, accs);
    prt->papFldDes[motorRecordACCU]->size = sizeof(prec->accu);
    prt->papFldDes[motorRecordACCU]->offset = (unsigned short)offsetof(motorRecord, accu);
    prt->papFldDes[motorRecordBDST]->size = sizeof(prec->bdst);
    prt->papFldDes[motorRecordBDST]->offset = (unsigned short)offsetof(motorRecord, bdst);
    prt->papFldDes[motorRecordBVEL]->size = sizeof(prec->bvel);
    prt->papFldDes[motorRecordBVEL]->offset = (unsigned short)offsetof(motorRecord, bvel);
    prt->papFldDes[motorRecordSBAK]->size = sizeof(prec->sbak);
    prt->papFldDes[motorRecordSBAK]->offset = (unsigned short)offsetof(motorRecord, sbak);
    prt->papFldDes[motorRecordBACC]->size = sizeof(prec->bacc);
    prt->papFldDes[motorRecordBACC]->offset = (unsigned short)offsetof(motorRecord, bacc);
    prt->papFldDes[motorRecordFRAC]->size = sizeof(prec->frac);
    prt->papFldDes[motorRecordFRAC]->offset = (unsigned short)offsetof(motorRecord, frac);
    prt->papFldDes[motorRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[motorRecordOUT]->offset = (unsigned short)offsetof(motorRecord, out);
    prt->papFldDes[motorRecordCARD]->size = sizeof(prec->card);
    prt->papFldDes[motorRecordCARD]->offset = (unsigned short)offsetof(motorRecord, card);
    prt->papFldDes[motorRecordRDBL]->size = sizeof(prec->rdbl);
    prt->papFldDes[motorRecordRDBL]->offset = (unsigned short)offsetof(motorRecord, rdbl);
    prt->papFldDes[motorRecordDOL]->size = sizeof(prec->dol);
    prt->papFldDes[motorRecordDOL]->offset = (unsigned short)offsetof(motorRecord, dol);
    prt->papFldDes[motorRecordOMSL]->size = sizeof(prec->omsl);
    prt->papFldDes[motorRecordOMSL]->offset = (unsigned short)offsetof(motorRecord, omsl);
    prt->papFldDes[motorRecordRLNK]->size = sizeof(prec->rlnk);
    prt->papFldDes[motorRecordRLNK]->offset = (unsigned short)offsetof(motorRecord, rlnk);
    prt->papFldDes[motorRecordSREV]->size = sizeof(prec->srev);
    prt->papFldDes[motorRecordSREV]->offset = (unsigned short)offsetof(motorRecord, srev);
    prt->papFldDes[motorRecordUREV]->size = sizeof(prec->urev);
    prt->papFldDes[motorRecordUREV]->offset = (unsigned short)offsetof(motorRecord, urev);
    prt->papFldDes[motorRecordMRES]->size = sizeof(prec->mres);
    prt->papFldDes[motorRecordMRES]->offset = (unsigned short)offsetof(motorRecord, mres);
    prt->papFldDes[motorRecordERES]->size = sizeof(prec->eres);
    prt->papFldDes[motorRecordERES]->offset = (unsigned short)offsetof(motorRecord, eres);
    prt->papFldDes[motorRecordRRES]->size = sizeof(prec->rres);
    prt->papFldDes[motorRecordRRES]->offset = (unsigned short)offsetof(motorRecord, rres);
    prt->papFldDes[motorRecordUEIP]->size = sizeof(prec->ueip);
    prt->papFldDes[motorRecordUEIP]->offset = (unsigned short)offsetof(motorRecord, ueip);
    prt->papFldDes[motorRecordURIP]->size = sizeof(prec->urip);
    prt->papFldDes[motorRecordURIP]->offset = (unsigned short)offsetof(motorRecord, urip);
    prt->papFldDes[motorRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[motorRecordPREC]->offset = (unsigned short)offsetof(motorRecord, prec);
    prt->papFldDes[motorRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[motorRecordEGU]->offset = (unsigned short)offsetof(motorRecord, egu);
    prt->papFldDes[motorRecordRHLM]->size = sizeof(prec->rhlm);
    prt->papFldDes[motorRecordRHLM]->offset = (unsigned short)offsetof(motorRecord, rhlm);
    prt->papFldDes[motorRecordRLLM]->size = sizeof(prec->rllm);
    prt->papFldDes[motorRecordRLLM]->offset = (unsigned short)offsetof(motorRecord, rllm);
    prt->papFldDes[motorRecordHLM]->size = sizeof(prec->hlm);
    prt->papFldDes[motorRecordHLM]->offset = (unsigned short)offsetof(motorRecord, hlm);
    prt->papFldDes[motorRecordLLM]->size = sizeof(prec->llm);
    prt->papFldDes[motorRecordLLM]->offset = (unsigned short)offsetof(motorRecord, llm);
    prt->papFldDes[motorRecordDHLM]->size = sizeof(prec->dhlm);
    prt->papFldDes[motorRecordDHLM]->offset = (unsigned short)offsetof(motorRecord, dhlm);
    prt->papFldDes[motorRecordDLLM]->size = sizeof(prec->dllm);
    prt->papFldDes[motorRecordDLLM]->offset = (unsigned short)offsetof(motorRecord, dllm);
    prt->papFldDes[motorRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[motorRecordHOPR]->offset = (unsigned short)offsetof(motorRecord, hopr);
    prt->papFldDes[motorRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[motorRecordLOPR]->offset = (unsigned short)offsetof(motorRecord, lopr);
    prt->papFldDes[motorRecordHLS]->size = sizeof(prec->hls);
    prt->papFldDes[motorRecordHLS]->offset = (unsigned short)offsetof(motorRecord, hls);
    prt->papFldDes[motorRecordLLS]->size = sizeof(prec->lls);
    prt->papFldDes[motorRecordLLS]->offset = (unsigned short)offsetof(motorRecord, lls);
    prt->papFldDes[motorRecordRHLS]->size = sizeof(prec->rhls);
    prt->papFldDes[motorRecordRHLS]->offset = (unsigned short)offsetof(motorRecord, rhls);
    prt->papFldDes[motorRecordRLLS]->size = sizeof(prec->rlls);
    prt->papFldDes[motorRecordRLLS]->offset = (unsigned short)offsetof(motorRecord, rlls);
    prt->papFldDes[motorRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[motorRecordHIHI]->offset = (unsigned short)offsetof(motorRecord, hihi);
    prt->papFldDes[motorRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[motorRecordLOLO]->offset = (unsigned short)offsetof(motorRecord, lolo);
    prt->papFldDes[motorRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[motorRecordHIGH]->offset = (unsigned short)offsetof(motorRecord, high);
    prt->papFldDes[motorRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[motorRecordLOW]->offset = (unsigned short)offsetof(motorRecord, low);
    prt->papFldDes[motorRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[motorRecordHHSV]->offset = (unsigned short)offsetof(motorRecord, hhsv);
    prt->papFldDes[motorRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[motorRecordLLSV]->offset = (unsigned short)offsetof(motorRecord, llsv);
    prt->papFldDes[motorRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[motorRecordHSV]->offset = (unsigned short)offsetof(motorRecord, hsv);
    prt->papFldDes[motorRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[motorRecordLSV]->offset = (unsigned short)offsetof(motorRecord, lsv);
    prt->papFldDes[motorRecordHLSV]->size = sizeof(prec->hlsv);
    prt->papFldDes[motorRecordHLSV]->offset = (unsigned short)offsetof(motorRecord, hlsv);
    prt->papFldDes[motorRecordRDBD]->size = sizeof(prec->rdbd);
    prt->papFldDes[motorRecordRDBD]->offset = (unsigned short)offsetof(motorRecord, rdbd);
    prt->papFldDes[motorRecordSPDB]->size = sizeof(prec->spdb);
    prt->papFldDes[motorRecordSPDB]->offset = (unsigned short)offsetof(motorRecord, spdb);
    prt->papFldDes[motorRecordRCNT]->size = sizeof(prec->rcnt);
    prt->papFldDes[motorRecordRCNT]->offset = (unsigned short)offsetof(motorRecord, rcnt);
    prt->papFldDes[motorRecordRTRY]->size = sizeof(prec->rtry);
    prt->papFldDes[motorRecordRTRY]->offset = (unsigned short)offsetof(motorRecord, rtry);
    prt->papFldDes[motorRecordMISS]->size = sizeof(prec->miss);
    prt->papFldDes[motorRecordMISS]->offset = (unsigned short)offsetof(motorRecord, miss);
    prt->papFldDes[motorRecordSPMG]->size = sizeof(prec->spmg);
    prt->papFldDes[motorRecordSPMG]->offset = (unsigned short)offsetof(motorRecord, spmg);
    prt->papFldDes[motorRecordLSPG]->size = sizeof(prec->lspg);
    prt->papFldDes[motorRecordLSPG]->offset = (unsigned short)offsetof(motorRecord, lspg);
    prt->papFldDes[motorRecordSTOP]->size = sizeof(prec->stop);
    prt->papFldDes[motorRecordSTOP]->offset = (unsigned short)offsetof(motorRecord, stop);
    prt->papFldDes[motorRecordHOMF]->size = sizeof(prec->homf);
    prt->papFldDes[motorRecordHOMF]->offset = (unsigned short)offsetof(motorRecord, homf);
    prt->papFldDes[motorRecordHOMR]->size = sizeof(prec->homr);
    prt->papFldDes[motorRecordHOMR]->offset = (unsigned short)offsetof(motorRecord, homr);
    prt->papFldDes[motorRecordJOGF]->size = sizeof(prec->jogf);
    prt->papFldDes[motorRecordJOGF]->offset = (unsigned short)offsetof(motorRecord, jogf);
    prt->papFldDes[motorRecordJOGR]->size = sizeof(prec->jogr);
    prt->papFldDes[motorRecordJOGR]->offset = (unsigned short)offsetof(motorRecord, jogr);
    prt->papFldDes[motorRecordTWF]->size = sizeof(prec->twf);
    prt->papFldDes[motorRecordTWF]->offset = (unsigned short)offsetof(motorRecord, twf);
    prt->papFldDes[motorRecordTWR]->size = sizeof(prec->twr);
    prt->papFldDes[motorRecordTWR]->offset = (unsigned short)offsetof(motorRecord, twr);
    prt->papFldDes[motorRecordTWV]->size = sizeof(prec->twv);
    prt->papFldDes[motorRecordTWV]->offset = (unsigned short)offsetof(motorRecord, twv);
    prt->papFldDes[motorRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[motorRecordVAL]->offset = (unsigned short)offsetof(motorRecord, val);
    prt->papFldDes[motorRecordLVAL]->size = sizeof(prec->lval);
    prt->papFldDes[motorRecordLVAL]->offset = (unsigned short)offsetof(motorRecord, lval);
    prt->papFldDes[motorRecordDVAL]->size = sizeof(prec->dval);
    prt->papFldDes[motorRecordDVAL]->offset = (unsigned short)offsetof(motorRecord, dval);
    prt->papFldDes[motorRecordLDVL]->size = sizeof(prec->ldvl);
    prt->papFldDes[motorRecordLDVL]->offset = (unsigned short)offsetof(motorRecord, ldvl);
    prt->papFldDes[motorRecordRVAL]->size = sizeof(prec->rval);
    prt->papFldDes[motorRecordRVAL]->offset = (unsigned short)offsetof(motorRecord, rval);
    prt->papFldDes[motorRecordLRVL]->size = sizeof(prec->lrvl);
    prt->papFldDes[motorRecordLRVL]->offset = (unsigned short)offsetof(motorRecord, lrvl);
    prt->papFldDes[motorRecordRLV]->size = sizeof(prec->rlv);
    prt->papFldDes[motorRecordRLV]->offset = (unsigned short)offsetof(motorRecord, rlv);
    prt->papFldDes[motorRecordLRLV]->size = sizeof(prec->lrlv);
    prt->papFldDes[motorRecordLRLV]->offset = (unsigned short)offsetof(motorRecord, lrlv);
    prt->papFldDes[motorRecordRBV]->size = sizeof(prec->rbv);
    prt->papFldDes[motorRecordRBV]->offset = (unsigned short)offsetof(motorRecord, rbv);
    prt->papFldDes[motorRecordDRBV]->size = sizeof(prec->drbv);
    prt->papFldDes[motorRecordDRBV]->offset = (unsigned short)offsetof(motorRecord, drbv);
    prt->papFldDes[motorRecordDIFF]->size = sizeof(prec->diff);
    prt->papFldDes[motorRecordDIFF]->offset = (unsigned short)offsetof(motorRecord, diff);
    prt->papFldDes[motorRecordRDIF]->size = sizeof(prec->rdif);
    prt->papFldDes[motorRecordRDIF]->offset = (unsigned short)offsetof(motorRecord, rdif);
    prt->papFldDes[motorRecordCDIR]->size = sizeof(prec->cdir);
    prt->papFldDes[motorRecordCDIR]->offset = (unsigned short)offsetof(motorRecord, cdir);
    prt->papFldDes[motorRecordRRBV]->size = sizeof(prec->rrbv);
    prt->papFldDes[motorRecordRRBV]->offset = (unsigned short)offsetof(motorRecord, rrbv);
    prt->papFldDes[motorRecordRMP]->size = sizeof(prec->rmp);
    prt->papFldDes[motorRecordRMP]->offset = (unsigned short)offsetof(motorRecord, rmp);
    prt->papFldDes[motorRecordREP]->size = sizeof(prec->rep);
    prt->papFldDes[motorRecordREP]->offset = (unsigned short)offsetof(motorRecord, rep);
    prt->papFldDes[motorRecordRVEL]->size = sizeof(prec->rvel);
    prt->papFldDes[motorRecordRVEL]->offset = (unsigned short)offsetof(motorRecord, rvel);
    prt->papFldDes[motorRecordDMOV]->size = sizeof(prec->dmov);
    prt->papFldDes[motorRecordDMOV]->offset = (unsigned short)offsetof(motorRecord, dmov);
    prt->papFldDes[motorRecordMOVN]->size = sizeof(prec->movn);
    prt->papFldDes[motorRecordMOVN]->offset = (unsigned short)offsetof(motorRecord, movn);
    prt->papFldDes[motorRecordMSTA]->size = sizeof(prec->msta);
    prt->papFldDes[motorRecordMSTA]->offset = (unsigned short)offsetof(motorRecord, msta);
    prt->papFldDes[motorRecordLVIO]->size = sizeof(prec->lvio);
    prt->papFldDes[motorRecordLVIO]->offset = (unsigned short)offsetof(motorRecord, lvio);
    prt->papFldDes[motorRecordTDIR]->size = sizeof(prec->tdir);
    prt->papFldDes[motorRecordTDIR]->offset = (unsigned short)offsetof(motorRecord, tdir);
    prt->papFldDes[motorRecordATHM]->size = sizeof(prec->athm);
    prt->papFldDes[motorRecordATHM]->offset = (unsigned short)offsetof(motorRecord, athm);
    prt->papFldDes[motorRecordPP]->size = sizeof(prec->pp);
    prt->papFldDes[motorRecordPP]->offset = (unsigned short)offsetof(motorRecord, pp);
    prt->papFldDes[motorRecordMIP]->size = sizeof(prec->mip);
    prt->papFldDes[motorRecordMIP]->offset = (unsigned short)offsetof(motorRecord, mip);
    prt->papFldDes[motorRecordMMAP]->size = sizeof(prec->mmap);
    prt->papFldDes[motorRecordMMAP]->offset = (unsigned short)offsetof(motorRecord, mmap);
    prt->papFldDes[motorRecordNMAP]->size = sizeof(prec->nmap);
    prt->papFldDes[motorRecordNMAP]->offset = (unsigned short)offsetof(motorRecord, nmap);
    prt->papFldDes[motorRecordDLY]->size = sizeof(prec->dly);
    prt->papFldDes[motorRecordDLY]->offset = (unsigned short)offsetof(motorRecord, dly);
    prt->papFldDes[motorRecordCBAK]->size = sizeof(prec->cbak);
    prt->papFldDes[motorRecordCBAK]->offset = (unsigned short)offsetof(motorRecord, cbak);
    prt->papFldDes[motorRecordPCOF]->size = sizeof(prec->pcof);
    prt->papFldDes[motorRecordPCOF]->offset = (unsigned short)offsetof(motorRecord, pcof);
    prt->papFldDes[motorRecordICOF]->size = sizeof(prec->icof);
    prt->papFldDes[motorRecordICOF]->offset = (unsigned short)offsetof(motorRecord, icof);
    prt->papFldDes[motorRecordDCOF]->size = sizeof(prec->dcof);
    prt->papFldDes[motorRecordDCOF]->offset = (unsigned short)offsetof(motorRecord, dcof);
    prt->papFldDes[motorRecordCNEN]->size = sizeof(prec->cnen);
    prt->papFldDes[motorRecordCNEN]->offset = (unsigned short)offsetof(motorRecord, cnen);
    prt->papFldDes[motorRecordINIT]->size = sizeof(prec->init);
    prt->papFldDes[motorRecordINIT]->offset = (unsigned short)offsetof(motorRecord, init);
    prt->papFldDes[motorRecordPREM]->size = sizeof(prec->prem);
    prt->papFldDes[motorRecordPREM]->offset = (unsigned short)offsetof(motorRecord, prem);
    prt->papFldDes[motorRecordPOST]->size = sizeof(prec->post);
    prt->papFldDes[motorRecordPOST]->offset = (unsigned short)offsetof(motorRecord, post);
    prt->papFldDes[motorRecordSTOO]->size = sizeof(prec->stoo);
    prt->papFldDes[motorRecordSTOO]->offset = (unsigned short)offsetof(motorRecord, stoo);
    prt->papFldDes[motorRecordDINP]->size = sizeof(prec->dinp);
    prt->papFldDes[motorRecordDINP]->offset = (unsigned short)offsetof(motorRecord, dinp);
    prt->papFldDes[motorRecordRINP]->size = sizeof(prec->rinp);
    prt->papFldDes[motorRecordRINP]->offset = (unsigned short)offsetof(motorRecord, rinp);
    prt->papFldDes[motorRecordJVEL]->size = sizeof(prec->jvel);
    prt->papFldDes[motorRecordJVEL]->offset = (unsigned short)offsetof(motorRecord, jvel);
    prt->papFldDes[motorRecordJAR]->size = sizeof(prec->jar);
    prt->papFldDes[motorRecordJAR]->offset = (unsigned short)offsetof(motorRecord, jar);
    prt->papFldDes[motorRecordLOCK]->size = sizeof(prec->lock);
    prt->papFldDes[motorRecordLOCK]->offset = (unsigned short)offsetof(motorRecord, lock);
    prt->papFldDes[motorRecordNTM]->size = sizeof(prec->ntm);
    prt->papFldDes[motorRecordNTM]->offset = (unsigned short)offsetof(motorRecord, ntm);
    prt->papFldDes[motorRecordNTMF]->size = sizeof(prec->ntmf);
    prt->papFldDes[motorRecordNTMF]->offset = (unsigned short)offsetof(motorRecord, ntmf);
    prt->papFldDes[motorRecordHVEL]->size = sizeof(prec->hvel);
    prt->papFldDes[motorRecordHVEL]->offset = (unsigned short)offsetof(motorRecord, hvel);
    prt->papFldDes[motorRecordSTUP]->size = sizeof(prec->stup);
    prt->papFldDes[motorRecordSTUP]->offset = (unsigned short)offsetof(motorRecord, stup);
    prt->papFldDes[motorRecordRMOD]->size = sizeof(prec->rmod);
    prt->papFldDes[motorRecordRMOD]->offset = (unsigned short)offsetof(motorRecord, rmod);
    prt->papFldDes[motorRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[motorRecordADEL]->offset = (unsigned short)offsetof(motorRecord, adel);
    prt->papFldDes[motorRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[motorRecordMDEL]->offset = (unsigned short)offsetof(motorRecord, mdel);
    prt->papFldDes[motorRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[motorRecordALST]->offset = (unsigned short)offsetof(motorRecord, alst);
    prt->papFldDes[motorRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[motorRecordMLST]->offset = (unsigned short)offsetof(motorRecord, mlst);
    prt->papFldDes[motorRecordSYNC]->size = sizeof(prec->sync);
    prt->papFldDes[motorRecordSYNC]->offset = (unsigned short)offsetof(motorRecord, sync);
    prt->papFldDes[motorRecordIGSET]->size = sizeof(prec->igset);
    prt->papFldDes[motorRecordIGSET]->offset = (unsigned short)offsetof(motorRecord, igset);
    prt->papFldDes[motorRecordRSTM]->size = sizeof(prec->rstm);
    prt->papFldDes[motorRecordRSTM]->offset = (unsigned short)offsetof(motorRecord, rstm);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(motorRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_motorRecord_H */
