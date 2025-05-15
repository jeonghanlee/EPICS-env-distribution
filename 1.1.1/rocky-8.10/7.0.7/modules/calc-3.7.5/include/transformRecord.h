/** @file transformRecord.h
 * @brief Declarations for the @ref transformRecord "transform" record type.
 *
 * This header was generated from transformRecord.dbd
 */

#ifndef INC_transformRecord_H
#define INC_transformRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef transformIVLA_NUM_CHOICES
/** @brief Enumerated type from menu transformIVLA */
typedef enum {
    transformIVLA_IGNORE            /**< @brief State string "Ignore error" */,
    transformIVLA_DO_NOTHING        /**< @brief State string "Do Nothing" */
} transformIVLA;
/** @brief Number of states defined for menu transformIVLA */
#define transformIVLA_NUM_CHOICES 2
#endif

#ifndef transformIAV_NUM_CHOICES
/** @brief Enumerated type from menu transformIAV */
typedef enum {
    transformIAV_EXT_NC             /**< @brief State string "Ext PV NC" */,
    transformIAV_EXT                /**< @brief State string "Ext PV OK" */,
    transformIAV_LOC                /**< @brief State string "Local PV" */,
    transformIAV_CON                /**< @brief State string "Constant" */
} transformIAV;
/** @brief Number of states defined for menu transformIAV */
#define transformIAV_NUM_CHOICES 4
#endif

#ifndef transformCOPT_NUM_CHOICES
/** @brief Enumerated type from menu transformCOPT */
typedef enum {
    transformCOPT_CONDITIONAL       /**< @brief State string "Conditional" */,
    transformCOPT_ALWAYS            /**< @brief State string "Always" */
} transformCOPT;
/** @brief Number of states defined for menu transformCOPT */
#define transformCOPT_NUM_CHOICES 2
#endif

/** @brief Declaration of transform record type. */
typedef struct transformRecord {
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
    void *         rpvt;            /**< @brief Record Private */
    epicsEnum16         ivla;       /**< @brief Invalid link action */
    epicsEnum16         copt;       /**< @brief Calc option */
    epicsFloat64        val;        /**< @brief Result */
    char                clca[120];  /**< @brief Calculation A */
    char                clcb[120];  /**< @brief Calculation B */
    char                clcc[120];  /**< @brief Calculation C */
    char                clcd[120];  /**< @brief Calculation D */
    char                clce[120];  /**< @brief Calculation E */
    char                clcf[120];  /**< @brief Calculation F */
    char                clcg[120];  /**< @brief Calculation G */
    char                clch[120];  /**< @brief Calculation H */
    char                clci[120];  /**< @brief Calculation I */
    char                clcj[120];  /**< @brief Calculation J */
    char                clck[120];  /**< @brief Calculation K */
    char                clcl[120];  /**< @brief Calculation L */
    char                clcm[120];  /**< @brief Calculation M */
    char                clcn[120];  /**< @brief Calculation N */
    char                clco[120];  /**< @brief Calculation O */
    char                clcp[120];  /**< @brief Calculation P */
    epicsInt32          cav;        /**< @brief CALC Invalid */
    epicsInt32          cbv;        /**< @brief CALC Invalid */
    epicsInt32          ccv;        /**< @brief CALC Invalid */
    epicsInt32          cdv;        /**< @brief CALC Invalid */
    epicsInt32          cev;        /**< @brief CALC Invalid */
    epicsInt32          cfv;        /**< @brief CALC Invalid */
    epicsInt32          cgv;        /**< @brief CALC Invalid */
    epicsInt32          chv;        /**< @brief CALC Invalid */
    epicsInt32          civ;        /**< @brief CALC Invalid */
    epicsInt32          cjv;        /**< @brief CALC Invalid */
    epicsInt32          ckv;        /**< @brief CALC Invalid */
    epicsInt32          clv;        /**< @brief CALC Invalid */
    epicsInt32          cmv;        /**< @brief CALC Invalid */
    epicsInt32          cnv;        /**< @brief CALC Invalid */
    epicsInt32          cov;        /**< @brief CALC Invalid */
    epicsInt32          cpv;        /**< @brief CALC Invalid */
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
    DBLINK              inpk;       /**< @brief Input K */
    DBLINK              inpl;       /**< @brief Input L */
    DBLINK              inpm;       /**< @brief Input M */
    DBLINK              inpn;       /**< @brief Input N */
    DBLINK              inpo;       /**< @brief Input O */
    DBLINK              inpp;       /**< @brief Input P */
    DBLINK              outa;       /**< @brief Output A */
    DBLINK              outb;       /**< @brief Output B */
    DBLINK              outc;       /**< @brief Output C */
    DBLINK              outd;       /**< @brief Output D */
    DBLINK              oute;       /**< @brief Output E */
    DBLINK              outf;       /**< @brief Output F */
    DBLINK              outg;       /**< @brief Output G */
    DBLINK              outh;       /**< @brief Output H */
    DBLINK              outi;       /**< @brief Output I */
    DBLINK              outj;       /**< @brief Output J */
    DBLINK              outk;       /**< @brief Output K */
    DBLINK              outl;       /**< @brief Output L */
    DBLINK              outm;       /**< @brief Output M */
    DBLINK              outn;       /**< @brief Output N */
    DBLINK              outo;       /**< @brief Output O */
    DBLINK              outp;       /**< @brief Output P */
    char                egu[16];    /**< @brief Units Name */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsFloat64        a;          /**< @brief Value of A */
    epicsFloat64        b;          /**< @brief Value of B */
    epicsFloat64        c;          /**< @brief Value of C */
    epicsFloat64        d;          /**< @brief Value of D */
    epicsFloat64        e;          /**< @brief Value of E */
    epicsFloat64        f;          /**< @brief Value of F */
    epicsFloat64        g;          /**< @brief Value of G */
    epicsFloat64        h;          /**< @brief Value of H */
    epicsFloat64        i;          /**< @brief Value of I */
    epicsFloat64        j;          /**< @brief Value of J */
    epicsFloat64        k;          /**< @brief Value of K */
    epicsFloat64        l;          /**< @brief Value of L */
    epicsFloat64        m;          /**< @brief Value of M */
    epicsFloat64        n;          /**< @brief Value of N */
    epicsFloat64        o;          /**< @brief Value of O */
    epicsFloat64        p;          /**< @brief Value of P */
    epicsFloat64        la;         /**< @brief Prev Value of A */
    epicsFloat64        lb;         /**< @brief Prev Value of B */
    epicsFloat64        lc;         /**< @brief Prev Value of C */
    epicsFloat64        ld;         /**< @brief Prev Value of D */
    epicsFloat64        le;         /**< @brief Prev Value of E */
    epicsFloat64        lf;         /**< @brief Prev Value of F */
    epicsFloat64        lg;         /**< @brief Prev Value of G */
    epicsFloat64        lh;         /**< @brief Prev Value of H */
    epicsFloat64        li;         /**< @brief Prev Value of I */
    epicsFloat64        lj;         /**< @brief Prev Value of J */
    epicsFloat64        lk;         /**< @brief Prev Value of K */
    epicsFloat64        ll;         /**< @brief Prev Value of L */
    epicsFloat64        lm;         /**< @brief Prev Value of M */
    epicsFloat64        ln;         /**< @brief Prev Value of N */
    epicsFloat64        lo;         /**< @brief Prev Value of O */
    epicsFloat64        lp;         /**< @brief Prev Value of P */
    unsigned char rpca[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc A */
    unsigned char rpcb[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc B */
    unsigned char rpcc[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc C */
    unsigned char rpcd[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc D */
    unsigned char rpce[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc E */
    unsigned char rpcf[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc F */
    unsigned char rpcg[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc G */
    unsigned char rpch[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc H */
    unsigned char rpci[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc I */
    unsigned char rpcj[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc J */
    unsigned char rpck[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc K */
    unsigned char rpcl[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc L */
    unsigned char rpcm[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc M */
    unsigned char rpcn[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc N */
    unsigned char rpco[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc O */
    unsigned char rpcp[SCALC_INFIX_TO_POSTFIX_SIZE(120)]; /**< @brief Postfix Calc P */
    char                cmta[39];   /**< @brief Comment A */
    char                cmtb[39];   /**< @brief Comment B */
    char                cmtc[39];   /**< @brief Comment C */
    char                cmtd[39];   /**< @brief Comment D */
    char                cmte[39];   /**< @brief Comment E */
    char                cmtf[39];   /**< @brief Comment F */
    char                cmtg[39];   /**< @brief Comment G */
    char                cmth[39];   /**< @brief Comment H */
    char                cmti[39];   /**< @brief Comment I */
    char                cmtj[39];   /**< @brief Comment J */
    char                cmtk[39];   /**< @brief Comment K */
    char                cmtl[39];   /**< @brief Comment L */
    char                cmtm[39];   /**< @brief Comment M */
    char                cmtn[39];   /**< @brief Comment N */
    char                cmto[39];   /**< @brief Comment O */
    char                cmtp[39];   /**< @brief Comment P */
    epicsInt16          map;        /**< @brief Input bitmap */
    epicsEnum16         iav;        /**< @brief Input link valid */
    epicsEnum16         ibv;        /**< @brief Input link valid */
    epicsEnum16         icv;        /**< @brief Input link valid */
    epicsEnum16         idv;        /**< @brief Input link valid */
    epicsEnum16         iev;        /**< @brief Input link valid */
    epicsEnum16         ifv;        /**< @brief Input link valid */
    epicsEnum16         igv;        /**< @brief Input link valid */
    epicsEnum16         ihv;        /**< @brief Input link valid */
    epicsEnum16         iiv;        /**< @brief Input link valid */
    epicsEnum16         ijv;        /**< @brief Input link valid */
    epicsEnum16         ikv;        /**< @brief Input link valid */
    epicsEnum16         ilv;        /**< @brief Input link valid */
    epicsEnum16         imv;        /**< @brief Input link valid */
    epicsEnum16         inv;        /**< @brief Input link valid */
    epicsEnum16         iov;        /**< @brief Input link valid */
    epicsEnum16         ipv;        /**< @brief Input link valid */
    epicsEnum16         oav;        /**< @brief Output link valid */
    epicsEnum16         obv;        /**< @brief Output link valid */
    epicsEnum16         ocv;        /**< @brief Output link valid */
    epicsEnum16         odv;        /**< @brief Output link valid */
    epicsEnum16         oev;        /**< @brief Output link valid */
    epicsEnum16         ofv;        /**< @brief Output link valid */
    epicsEnum16         ogv;        /**< @brief Output link valid */
    epicsEnum16         ohv;        /**< @brief Output link valid */
    epicsEnum16         oiv;        /**< @brief Output link valid */
    epicsEnum16         ojv;        /**< @brief Output link valid */
    epicsEnum16         okv;        /**< @brief Output link valid */
    epicsEnum16         olv;        /**< @brief Output link valid */
    epicsEnum16         omv;        /**< @brief Output link valid */
    epicsEnum16         onv;        /**< @brief Output link valid */
    epicsEnum16         oov;        /**< @brief Output link valid */
    epicsEnum16         opv;        /**< @brief Output link valid */
} transformRecord;

typedef enum {
	transformRecordNAME = 0,
	transformRecordDESC = 1,
	transformRecordASG = 2,
	transformRecordSCAN = 3,
	transformRecordPINI = 4,
	transformRecordPHAS = 5,
	transformRecordEVNT = 6,
	transformRecordTSE = 7,
	transformRecordTSEL = 8,
	transformRecordDTYP = 9,
	transformRecordDISV = 10,
	transformRecordDISA = 11,
	transformRecordSDIS = 12,
	transformRecordMLOK = 13,
	transformRecordMLIS = 14,
	transformRecordBKLNK = 15,
	transformRecordDISP = 16,
	transformRecordPROC = 17,
	transformRecordSTAT = 18,
	transformRecordSEVR = 19,
	transformRecordAMSG = 20,
	transformRecordNSTA = 21,
	transformRecordNSEV = 22,
	transformRecordNAMSG = 23,
	transformRecordACKS = 24,
	transformRecordACKT = 25,
	transformRecordDISS = 26,
	transformRecordLCNT = 27,
	transformRecordPACT = 28,
	transformRecordPUTF = 29,
	transformRecordRPRO = 30,
	transformRecordASP = 31,
	transformRecordPPN = 32,
	transformRecordPPNR = 33,
	transformRecordSPVT = 34,
	transformRecordRSET = 35,
	transformRecordDSET = 36,
	transformRecordDPVT = 37,
	transformRecordRDES = 38,
	transformRecordLSET = 39,
	transformRecordPRIO = 40,
	transformRecordTPRO = 41,
	transformRecordBKPT = 42,
	transformRecordUDF = 43,
	transformRecordUDFS = 44,
	transformRecordTIME = 45,
	transformRecordUTAG = 46,
	transformRecordFLNK = 47,
	transformRecordVERS = 48,
	transformRecordRPVT = 49,
	transformRecordIVLA = 50,
	transformRecordCOPT = 51,
	transformRecordVAL = 52,
	transformRecordCLCA = 53,
	transformRecordCLCB = 54,
	transformRecordCLCC = 55,
	transformRecordCLCD = 56,
	transformRecordCLCE = 57,
	transformRecordCLCF = 58,
	transformRecordCLCG = 59,
	transformRecordCLCH = 60,
	transformRecordCLCI = 61,
	transformRecordCLCJ = 62,
	transformRecordCLCK = 63,
	transformRecordCLCL = 64,
	transformRecordCLCM = 65,
	transformRecordCLCN = 66,
	transformRecordCLCO = 67,
	transformRecordCLCP = 68,
	transformRecordCAV = 69,
	transformRecordCBV = 70,
	transformRecordCCV = 71,
	transformRecordCDV = 72,
	transformRecordCEV = 73,
	transformRecordCFV = 74,
	transformRecordCGV = 75,
	transformRecordCHV = 76,
	transformRecordCIV = 77,
	transformRecordCJV = 78,
	transformRecordCKV = 79,
	transformRecordCLV = 80,
	transformRecordCMV = 81,
	transformRecordCNV = 82,
	transformRecordCOV = 83,
	transformRecordCPV = 84,
	transformRecordINPA = 85,
	transformRecordINPB = 86,
	transformRecordINPC = 87,
	transformRecordINPD = 88,
	transformRecordINPE = 89,
	transformRecordINPF = 90,
	transformRecordINPG = 91,
	transformRecordINPH = 92,
	transformRecordINPI = 93,
	transformRecordINPJ = 94,
	transformRecordINPK = 95,
	transformRecordINPL = 96,
	transformRecordINPM = 97,
	transformRecordINPN = 98,
	transformRecordINPO = 99,
	transformRecordINPP = 100,
	transformRecordOUTA = 101,
	transformRecordOUTB = 102,
	transformRecordOUTC = 103,
	transformRecordOUTD = 104,
	transformRecordOUTE = 105,
	transformRecordOUTF = 106,
	transformRecordOUTG = 107,
	transformRecordOUTH = 108,
	transformRecordOUTI = 109,
	transformRecordOUTJ = 110,
	transformRecordOUTK = 111,
	transformRecordOUTL = 112,
	transformRecordOUTM = 113,
	transformRecordOUTN = 114,
	transformRecordOUTO = 115,
	transformRecordOUTP = 116,
	transformRecordEGU = 117,
	transformRecordPREC = 118,
	transformRecordA = 119,
	transformRecordB = 120,
	transformRecordC = 121,
	transformRecordD = 122,
	transformRecordE = 123,
	transformRecordF = 124,
	transformRecordG = 125,
	transformRecordH = 126,
	transformRecordI = 127,
	transformRecordJ = 128,
	transformRecordK = 129,
	transformRecordL = 130,
	transformRecordM = 131,
	transformRecordN = 132,
	transformRecordO = 133,
	transformRecordP = 134,
	transformRecordLA = 135,
	transformRecordLB = 136,
	transformRecordLC = 137,
	transformRecordLD = 138,
	transformRecordLE = 139,
	transformRecordLF = 140,
	transformRecordLG = 141,
	transformRecordLH = 142,
	transformRecordLI = 143,
	transformRecordLJ = 144,
	transformRecordLK = 145,
	transformRecordLL = 146,
	transformRecordLM = 147,
	transformRecordLN = 148,
	transformRecordLO = 149,
	transformRecordLP = 150,
	transformRecordRPCA = 151,
	transformRecordRPCB = 152,
	transformRecordRPCC = 153,
	transformRecordRPCD = 154,
	transformRecordRPCE = 155,
	transformRecordRPCF = 156,
	transformRecordRPCG = 157,
	transformRecordRPCH = 158,
	transformRecordRPCI = 159,
	transformRecordRPCJ = 160,
	transformRecordRPCK = 161,
	transformRecordRPCL = 162,
	transformRecordRPCM = 163,
	transformRecordRPCN = 164,
	transformRecordRPCO = 165,
	transformRecordRPCP = 166,
	transformRecordCMTA = 167,
	transformRecordCMTB = 168,
	transformRecordCMTC = 169,
	transformRecordCMTD = 170,
	transformRecordCMTE = 171,
	transformRecordCMTF = 172,
	transformRecordCMTG = 173,
	transformRecordCMTH = 174,
	transformRecordCMTI = 175,
	transformRecordCMTJ = 176,
	transformRecordCMTK = 177,
	transformRecordCMTL = 178,
	transformRecordCMTM = 179,
	transformRecordCMTN = 180,
	transformRecordCMTO = 181,
	transformRecordCMTP = 182,
	transformRecordMAP = 183,
	transformRecordIAV = 184,
	transformRecordIBV = 185,
	transformRecordICV = 186,
	transformRecordIDV = 187,
	transformRecordIEV = 188,
	transformRecordIFV = 189,
	transformRecordIGV = 190,
	transformRecordIHV = 191,
	transformRecordIIV = 192,
	transformRecordIJV = 193,
	transformRecordIKV = 194,
	transformRecordILV = 195,
	transformRecordIMV = 196,
	transformRecordINV = 197,
	transformRecordIOV = 198,
	transformRecordIPV = 199,
	transformRecordOAV = 200,
	transformRecordOBV = 201,
	transformRecordOCV = 202,
	transformRecordODV = 203,
	transformRecordOEV = 204,
	transformRecordOFV = 205,
	transformRecordOGV = 206,
	transformRecordOHV = 207,
	transformRecordOIV = 208,
	transformRecordOJV = 209,
	transformRecordOKV = 210,
	transformRecordOLV = 211,
	transformRecordOMV = 212,
	transformRecordONV = 213,
	transformRecordOOV = 214,
	transformRecordOPV = 215
} transformFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int transformRecordSizeOffset(dbRecordType *prt)
{
    transformRecord *prec = 0;

    if (prt->no_fields != 216) {
        cantProceed("IOC build or installation error:\n"
            "    The transformRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 216.\n",
            prt->no_fields);
    }
    prt->papFldDes[transformRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[transformRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[transformRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[transformRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[transformRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[transformRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[transformRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[transformRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[transformRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[transformRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[transformRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[transformRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[transformRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[transformRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[transformRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[transformRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[transformRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[transformRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[transformRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[transformRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[transformRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[transformRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[transformRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[transformRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[transformRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[transformRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[transformRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[transformRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[transformRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[transformRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[transformRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[transformRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[transformRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[transformRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[transformRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[transformRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[transformRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[transformRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[transformRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[transformRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[transformRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[transformRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[transformRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[transformRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[transformRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[transformRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[transformRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[transformRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[transformRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[transformRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[transformRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[transformRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[transformRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[transformRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[transformRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[transformRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[transformRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[transformRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[transformRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[transformRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[transformRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[transformRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[transformRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[transformRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[transformRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[transformRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[transformRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[transformRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[transformRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[transformRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[transformRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[transformRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[transformRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[transformRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[transformRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[transformRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[transformRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[transformRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[transformRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[transformRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[transformRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[transformRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[transformRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[transformRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[transformRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[transformRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[transformRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[transformRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[transformRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[transformRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[transformRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[transformRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[transformRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[transformRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[transformRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[transformRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[transformRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[transformRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[transformRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[transformRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[transformRecordIVLA]->size = sizeof(prec->ivla);
    prt->papFldDes[transformRecordIVLA]->offset = (unsigned short)((char *)&prec->ivla - (char *)prec);
    prt->papFldDes[transformRecordCOPT]->size = sizeof(prec->copt);
    prt->papFldDes[transformRecordCOPT]->offset = (unsigned short)((char *)&prec->copt - (char *)prec);
    prt->papFldDes[transformRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[transformRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[transformRecordCLCA]->size = sizeof(prec->clca);
    prt->papFldDes[transformRecordCLCA]->offset = (unsigned short)((char *)&prec->clca - (char *)prec);
    prt->papFldDes[transformRecordCLCB]->size = sizeof(prec->clcb);
    prt->papFldDes[transformRecordCLCB]->offset = (unsigned short)((char *)&prec->clcb - (char *)prec);
    prt->papFldDes[transformRecordCLCC]->size = sizeof(prec->clcc);
    prt->papFldDes[transformRecordCLCC]->offset = (unsigned short)((char *)&prec->clcc - (char *)prec);
    prt->papFldDes[transformRecordCLCD]->size = sizeof(prec->clcd);
    prt->papFldDes[transformRecordCLCD]->offset = (unsigned short)((char *)&prec->clcd - (char *)prec);
    prt->papFldDes[transformRecordCLCE]->size = sizeof(prec->clce);
    prt->papFldDes[transformRecordCLCE]->offset = (unsigned short)((char *)&prec->clce - (char *)prec);
    prt->papFldDes[transformRecordCLCF]->size = sizeof(prec->clcf);
    prt->papFldDes[transformRecordCLCF]->offset = (unsigned short)((char *)&prec->clcf - (char *)prec);
    prt->papFldDes[transformRecordCLCG]->size = sizeof(prec->clcg);
    prt->papFldDes[transformRecordCLCG]->offset = (unsigned short)((char *)&prec->clcg - (char *)prec);
    prt->papFldDes[transformRecordCLCH]->size = sizeof(prec->clch);
    prt->papFldDes[transformRecordCLCH]->offset = (unsigned short)((char *)&prec->clch - (char *)prec);
    prt->papFldDes[transformRecordCLCI]->size = sizeof(prec->clci);
    prt->papFldDes[transformRecordCLCI]->offset = (unsigned short)((char *)&prec->clci - (char *)prec);
    prt->papFldDes[transformRecordCLCJ]->size = sizeof(prec->clcj);
    prt->papFldDes[transformRecordCLCJ]->offset = (unsigned short)((char *)&prec->clcj - (char *)prec);
    prt->papFldDes[transformRecordCLCK]->size = sizeof(prec->clck);
    prt->papFldDes[transformRecordCLCK]->offset = (unsigned short)((char *)&prec->clck - (char *)prec);
    prt->papFldDes[transformRecordCLCL]->size = sizeof(prec->clcl);
    prt->papFldDes[transformRecordCLCL]->offset = (unsigned short)((char *)&prec->clcl - (char *)prec);
    prt->papFldDes[transformRecordCLCM]->size = sizeof(prec->clcm);
    prt->papFldDes[transformRecordCLCM]->offset = (unsigned short)((char *)&prec->clcm - (char *)prec);
    prt->papFldDes[transformRecordCLCN]->size = sizeof(prec->clcn);
    prt->papFldDes[transformRecordCLCN]->offset = (unsigned short)((char *)&prec->clcn - (char *)prec);
    prt->papFldDes[transformRecordCLCO]->size = sizeof(prec->clco);
    prt->papFldDes[transformRecordCLCO]->offset = (unsigned short)((char *)&prec->clco - (char *)prec);
    prt->papFldDes[transformRecordCLCP]->size = sizeof(prec->clcp);
    prt->papFldDes[transformRecordCLCP]->offset = (unsigned short)((char *)&prec->clcp - (char *)prec);
    prt->papFldDes[transformRecordCAV]->size = sizeof(prec->cav);
    prt->papFldDes[transformRecordCAV]->offset = (unsigned short)((char *)&prec->cav - (char *)prec);
    prt->papFldDes[transformRecordCBV]->size = sizeof(prec->cbv);
    prt->papFldDes[transformRecordCBV]->offset = (unsigned short)((char *)&prec->cbv - (char *)prec);
    prt->papFldDes[transformRecordCCV]->size = sizeof(prec->ccv);
    prt->papFldDes[transformRecordCCV]->offset = (unsigned short)((char *)&prec->ccv - (char *)prec);
    prt->papFldDes[transformRecordCDV]->size = sizeof(prec->cdv);
    prt->papFldDes[transformRecordCDV]->offset = (unsigned short)((char *)&prec->cdv - (char *)prec);
    prt->papFldDes[transformRecordCEV]->size = sizeof(prec->cev);
    prt->papFldDes[transformRecordCEV]->offset = (unsigned short)((char *)&prec->cev - (char *)prec);
    prt->papFldDes[transformRecordCFV]->size = sizeof(prec->cfv);
    prt->papFldDes[transformRecordCFV]->offset = (unsigned short)((char *)&prec->cfv - (char *)prec);
    prt->papFldDes[transformRecordCGV]->size = sizeof(prec->cgv);
    prt->papFldDes[transformRecordCGV]->offset = (unsigned short)((char *)&prec->cgv - (char *)prec);
    prt->papFldDes[transformRecordCHV]->size = sizeof(prec->chv);
    prt->papFldDes[transformRecordCHV]->offset = (unsigned short)((char *)&prec->chv - (char *)prec);
    prt->papFldDes[transformRecordCIV]->size = sizeof(prec->civ);
    prt->papFldDes[transformRecordCIV]->offset = (unsigned short)((char *)&prec->civ - (char *)prec);
    prt->papFldDes[transformRecordCJV]->size = sizeof(prec->cjv);
    prt->papFldDes[transformRecordCJV]->offset = (unsigned short)((char *)&prec->cjv - (char *)prec);
    prt->papFldDes[transformRecordCKV]->size = sizeof(prec->ckv);
    prt->papFldDes[transformRecordCKV]->offset = (unsigned short)((char *)&prec->ckv - (char *)prec);
    prt->papFldDes[transformRecordCLV]->size = sizeof(prec->clv);
    prt->papFldDes[transformRecordCLV]->offset = (unsigned short)((char *)&prec->clv - (char *)prec);
    prt->papFldDes[transformRecordCMV]->size = sizeof(prec->cmv);
    prt->papFldDes[transformRecordCMV]->offset = (unsigned short)((char *)&prec->cmv - (char *)prec);
    prt->papFldDes[transformRecordCNV]->size = sizeof(prec->cnv);
    prt->papFldDes[transformRecordCNV]->offset = (unsigned short)((char *)&prec->cnv - (char *)prec);
    prt->papFldDes[transformRecordCOV]->size = sizeof(prec->cov);
    prt->papFldDes[transformRecordCOV]->offset = (unsigned short)((char *)&prec->cov - (char *)prec);
    prt->papFldDes[transformRecordCPV]->size = sizeof(prec->cpv);
    prt->papFldDes[transformRecordCPV]->offset = (unsigned short)((char *)&prec->cpv - (char *)prec);
    prt->papFldDes[transformRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[transformRecordINPA]->offset = (unsigned short)((char *)&prec->inpa - (char *)prec);
    prt->papFldDes[transformRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[transformRecordINPB]->offset = (unsigned short)((char *)&prec->inpb - (char *)prec);
    prt->papFldDes[transformRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[transformRecordINPC]->offset = (unsigned short)((char *)&prec->inpc - (char *)prec);
    prt->papFldDes[transformRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[transformRecordINPD]->offset = (unsigned short)((char *)&prec->inpd - (char *)prec);
    prt->papFldDes[transformRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[transformRecordINPE]->offset = (unsigned short)((char *)&prec->inpe - (char *)prec);
    prt->papFldDes[transformRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[transformRecordINPF]->offset = (unsigned short)((char *)&prec->inpf - (char *)prec);
    prt->papFldDes[transformRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[transformRecordINPG]->offset = (unsigned short)((char *)&prec->inpg - (char *)prec);
    prt->papFldDes[transformRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[transformRecordINPH]->offset = (unsigned short)((char *)&prec->inph - (char *)prec);
    prt->papFldDes[transformRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[transformRecordINPI]->offset = (unsigned short)((char *)&prec->inpi - (char *)prec);
    prt->papFldDes[transformRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[transformRecordINPJ]->offset = (unsigned short)((char *)&prec->inpj - (char *)prec);
    prt->papFldDes[transformRecordINPK]->size = sizeof(prec->inpk);
    prt->papFldDes[transformRecordINPK]->offset = (unsigned short)((char *)&prec->inpk - (char *)prec);
    prt->papFldDes[transformRecordINPL]->size = sizeof(prec->inpl);
    prt->papFldDes[transformRecordINPL]->offset = (unsigned short)((char *)&prec->inpl - (char *)prec);
    prt->papFldDes[transformRecordINPM]->size = sizeof(prec->inpm);
    prt->papFldDes[transformRecordINPM]->offset = (unsigned short)((char *)&prec->inpm - (char *)prec);
    prt->papFldDes[transformRecordINPN]->size = sizeof(prec->inpn);
    prt->papFldDes[transformRecordINPN]->offset = (unsigned short)((char *)&prec->inpn - (char *)prec);
    prt->papFldDes[transformRecordINPO]->size = sizeof(prec->inpo);
    prt->papFldDes[transformRecordINPO]->offset = (unsigned short)((char *)&prec->inpo - (char *)prec);
    prt->papFldDes[transformRecordINPP]->size = sizeof(prec->inpp);
    prt->papFldDes[transformRecordINPP]->offset = (unsigned short)((char *)&prec->inpp - (char *)prec);
    prt->papFldDes[transformRecordOUTA]->size = sizeof(prec->outa);
    prt->papFldDes[transformRecordOUTA]->offset = (unsigned short)((char *)&prec->outa - (char *)prec);
    prt->papFldDes[transformRecordOUTB]->size = sizeof(prec->outb);
    prt->papFldDes[transformRecordOUTB]->offset = (unsigned short)((char *)&prec->outb - (char *)prec);
    prt->papFldDes[transformRecordOUTC]->size = sizeof(prec->outc);
    prt->papFldDes[transformRecordOUTC]->offset = (unsigned short)((char *)&prec->outc - (char *)prec);
    prt->papFldDes[transformRecordOUTD]->size = sizeof(prec->outd);
    prt->papFldDes[transformRecordOUTD]->offset = (unsigned short)((char *)&prec->outd - (char *)prec);
    prt->papFldDes[transformRecordOUTE]->size = sizeof(prec->oute);
    prt->papFldDes[transformRecordOUTE]->offset = (unsigned short)((char *)&prec->oute - (char *)prec);
    prt->papFldDes[transformRecordOUTF]->size = sizeof(prec->outf);
    prt->papFldDes[transformRecordOUTF]->offset = (unsigned short)((char *)&prec->outf - (char *)prec);
    prt->papFldDes[transformRecordOUTG]->size = sizeof(prec->outg);
    prt->papFldDes[transformRecordOUTG]->offset = (unsigned short)((char *)&prec->outg - (char *)prec);
    prt->papFldDes[transformRecordOUTH]->size = sizeof(prec->outh);
    prt->papFldDes[transformRecordOUTH]->offset = (unsigned short)((char *)&prec->outh - (char *)prec);
    prt->papFldDes[transformRecordOUTI]->size = sizeof(prec->outi);
    prt->papFldDes[transformRecordOUTI]->offset = (unsigned short)((char *)&prec->outi - (char *)prec);
    prt->papFldDes[transformRecordOUTJ]->size = sizeof(prec->outj);
    prt->papFldDes[transformRecordOUTJ]->offset = (unsigned short)((char *)&prec->outj - (char *)prec);
    prt->papFldDes[transformRecordOUTK]->size = sizeof(prec->outk);
    prt->papFldDes[transformRecordOUTK]->offset = (unsigned short)((char *)&prec->outk - (char *)prec);
    prt->papFldDes[transformRecordOUTL]->size = sizeof(prec->outl);
    prt->papFldDes[transformRecordOUTL]->offset = (unsigned short)((char *)&prec->outl - (char *)prec);
    prt->papFldDes[transformRecordOUTM]->size = sizeof(prec->outm);
    prt->papFldDes[transformRecordOUTM]->offset = (unsigned short)((char *)&prec->outm - (char *)prec);
    prt->papFldDes[transformRecordOUTN]->size = sizeof(prec->outn);
    prt->papFldDes[transformRecordOUTN]->offset = (unsigned short)((char *)&prec->outn - (char *)prec);
    prt->papFldDes[transformRecordOUTO]->size = sizeof(prec->outo);
    prt->papFldDes[transformRecordOUTO]->offset = (unsigned short)((char *)&prec->outo - (char *)prec);
    prt->papFldDes[transformRecordOUTP]->size = sizeof(prec->outp);
    prt->papFldDes[transformRecordOUTP]->offset = (unsigned short)((char *)&prec->outp - (char *)prec);
    prt->papFldDes[transformRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[transformRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[transformRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[transformRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[transformRecordA]->size = sizeof(prec->a);
    prt->papFldDes[transformRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[transformRecordB]->size = sizeof(prec->b);
    prt->papFldDes[transformRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[transformRecordC]->size = sizeof(prec->c);
    prt->papFldDes[transformRecordC]->offset = (unsigned short)((char *)&prec->c - (char *)prec);
    prt->papFldDes[transformRecordD]->size = sizeof(prec->d);
    prt->papFldDes[transformRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[transformRecordE]->size = sizeof(prec->e);
    prt->papFldDes[transformRecordE]->offset = (unsigned short)((char *)&prec->e - (char *)prec);
    prt->papFldDes[transformRecordF]->size = sizeof(prec->f);
    prt->papFldDes[transformRecordF]->offset = (unsigned short)((char *)&prec->f - (char *)prec);
    prt->papFldDes[transformRecordG]->size = sizeof(prec->g);
    prt->papFldDes[transformRecordG]->offset = (unsigned short)((char *)&prec->g - (char *)prec);
    prt->papFldDes[transformRecordH]->size = sizeof(prec->h);
    prt->papFldDes[transformRecordH]->offset = (unsigned short)((char *)&prec->h - (char *)prec);
    prt->papFldDes[transformRecordI]->size = sizeof(prec->i);
    prt->papFldDes[transformRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[transformRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[transformRecordJ]->offset = (unsigned short)((char *)&prec->j - (char *)prec);
    prt->papFldDes[transformRecordK]->size = sizeof(prec->k);
    prt->papFldDes[transformRecordK]->offset = (unsigned short)((char *)&prec->k - (char *)prec);
    prt->papFldDes[transformRecordL]->size = sizeof(prec->l);
    prt->papFldDes[transformRecordL]->offset = (unsigned short)((char *)&prec->l - (char *)prec);
    prt->papFldDes[transformRecordM]->size = sizeof(prec->m);
    prt->papFldDes[transformRecordM]->offset = (unsigned short)((char *)&prec->m - (char *)prec);
    prt->papFldDes[transformRecordN]->size = sizeof(prec->n);
    prt->papFldDes[transformRecordN]->offset = (unsigned short)((char *)&prec->n - (char *)prec);
    prt->papFldDes[transformRecordO]->size = sizeof(prec->o);
    prt->papFldDes[transformRecordO]->offset = (unsigned short)((char *)&prec->o - (char *)prec);
    prt->papFldDes[transformRecordP]->size = sizeof(prec->p);
    prt->papFldDes[transformRecordP]->offset = (unsigned short)((char *)&prec->p - (char *)prec);
    prt->papFldDes[transformRecordLA]->size = sizeof(prec->la);
    prt->papFldDes[transformRecordLA]->offset = (unsigned short)((char *)&prec->la - (char *)prec);
    prt->papFldDes[transformRecordLB]->size = sizeof(prec->lb);
    prt->papFldDes[transformRecordLB]->offset = (unsigned short)((char *)&prec->lb - (char *)prec);
    prt->papFldDes[transformRecordLC]->size = sizeof(prec->lc);
    prt->papFldDes[transformRecordLC]->offset = (unsigned short)((char *)&prec->lc - (char *)prec);
    prt->papFldDes[transformRecordLD]->size = sizeof(prec->ld);
    prt->papFldDes[transformRecordLD]->offset = (unsigned short)((char *)&prec->ld - (char *)prec);
    prt->papFldDes[transformRecordLE]->size = sizeof(prec->le);
    prt->papFldDes[transformRecordLE]->offset = (unsigned short)((char *)&prec->le - (char *)prec);
    prt->papFldDes[transformRecordLF]->size = sizeof(prec->lf);
    prt->papFldDes[transformRecordLF]->offset = (unsigned short)((char *)&prec->lf - (char *)prec);
    prt->papFldDes[transformRecordLG]->size = sizeof(prec->lg);
    prt->papFldDes[transformRecordLG]->offset = (unsigned short)((char *)&prec->lg - (char *)prec);
    prt->papFldDes[transformRecordLH]->size = sizeof(prec->lh);
    prt->papFldDes[transformRecordLH]->offset = (unsigned short)((char *)&prec->lh - (char *)prec);
    prt->papFldDes[transformRecordLI]->size = sizeof(prec->li);
    prt->papFldDes[transformRecordLI]->offset = (unsigned short)((char *)&prec->li - (char *)prec);
    prt->papFldDes[transformRecordLJ]->size = sizeof(prec->lj);
    prt->papFldDes[transformRecordLJ]->offset = (unsigned short)((char *)&prec->lj - (char *)prec);
    prt->papFldDes[transformRecordLK]->size = sizeof(prec->lk);
    prt->papFldDes[transformRecordLK]->offset = (unsigned short)((char *)&prec->lk - (char *)prec);
    prt->papFldDes[transformRecordLL]->size = sizeof(prec->ll);
    prt->papFldDes[transformRecordLL]->offset = (unsigned short)((char *)&prec->ll - (char *)prec);
    prt->papFldDes[transformRecordLM]->size = sizeof(prec->lm);
    prt->papFldDes[transformRecordLM]->offset = (unsigned short)((char *)&prec->lm - (char *)prec);
    prt->papFldDes[transformRecordLN]->size = sizeof(prec->ln);
    prt->papFldDes[transformRecordLN]->offset = (unsigned short)((char *)&prec->ln - (char *)prec);
    prt->papFldDes[transformRecordLO]->size = sizeof(prec->lo);
    prt->papFldDes[transformRecordLO]->offset = (unsigned short)((char *)&prec->lo - (char *)prec);
    prt->papFldDes[transformRecordLP]->size = sizeof(prec->lp);
    prt->papFldDes[transformRecordLP]->offset = (unsigned short)((char *)&prec->lp - (char *)prec);
    prt->papFldDes[transformRecordRPCA]->size = sizeof(prec->rpca);
    prt->papFldDes[transformRecordRPCA]->offset = (unsigned short)((char *)&prec->rpca - (char *)prec);
    prt->papFldDes[transformRecordRPCB]->size = sizeof(prec->rpcb);
    prt->papFldDes[transformRecordRPCB]->offset = (unsigned short)((char *)&prec->rpcb - (char *)prec);
    prt->papFldDes[transformRecordRPCC]->size = sizeof(prec->rpcc);
    prt->papFldDes[transformRecordRPCC]->offset = (unsigned short)((char *)&prec->rpcc - (char *)prec);
    prt->papFldDes[transformRecordRPCD]->size = sizeof(prec->rpcd);
    prt->papFldDes[transformRecordRPCD]->offset = (unsigned short)((char *)&prec->rpcd - (char *)prec);
    prt->papFldDes[transformRecordRPCE]->size = sizeof(prec->rpce);
    prt->papFldDes[transformRecordRPCE]->offset = (unsigned short)((char *)&prec->rpce - (char *)prec);
    prt->papFldDes[transformRecordRPCF]->size = sizeof(prec->rpcf);
    prt->papFldDes[transformRecordRPCF]->offset = (unsigned short)((char *)&prec->rpcf - (char *)prec);
    prt->papFldDes[transformRecordRPCG]->size = sizeof(prec->rpcg);
    prt->papFldDes[transformRecordRPCG]->offset = (unsigned short)((char *)&prec->rpcg - (char *)prec);
    prt->papFldDes[transformRecordRPCH]->size = sizeof(prec->rpch);
    prt->papFldDes[transformRecordRPCH]->offset = (unsigned short)((char *)&prec->rpch - (char *)prec);
    prt->papFldDes[transformRecordRPCI]->size = sizeof(prec->rpci);
    prt->papFldDes[transformRecordRPCI]->offset = (unsigned short)((char *)&prec->rpci - (char *)prec);
    prt->papFldDes[transformRecordRPCJ]->size = sizeof(prec->rpcj);
    prt->papFldDes[transformRecordRPCJ]->offset = (unsigned short)((char *)&prec->rpcj - (char *)prec);
    prt->papFldDes[transformRecordRPCK]->size = sizeof(prec->rpck);
    prt->papFldDes[transformRecordRPCK]->offset = (unsigned short)((char *)&prec->rpck - (char *)prec);
    prt->papFldDes[transformRecordRPCL]->size = sizeof(prec->rpcl);
    prt->papFldDes[transformRecordRPCL]->offset = (unsigned short)((char *)&prec->rpcl - (char *)prec);
    prt->papFldDes[transformRecordRPCM]->size = sizeof(prec->rpcm);
    prt->papFldDes[transformRecordRPCM]->offset = (unsigned short)((char *)&prec->rpcm - (char *)prec);
    prt->papFldDes[transformRecordRPCN]->size = sizeof(prec->rpcn);
    prt->papFldDes[transformRecordRPCN]->offset = (unsigned short)((char *)&prec->rpcn - (char *)prec);
    prt->papFldDes[transformRecordRPCO]->size = sizeof(prec->rpco);
    prt->papFldDes[transformRecordRPCO]->offset = (unsigned short)((char *)&prec->rpco - (char *)prec);
    prt->papFldDes[transformRecordRPCP]->size = sizeof(prec->rpcp);
    prt->papFldDes[transformRecordRPCP]->offset = (unsigned short)((char *)&prec->rpcp - (char *)prec);
    prt->papFldDes[transformRecordCMTA]->size = sizeof(prec->cmta);
    prt->papFldDes[transformRecordCMTA]->offset = (unsigned short)((char *)&prec->cmta - (char *)prec);
    prt->papFldDes[transformRecordCMTB]->size = sizeof(prec->cmtb);
    prt->papFldDes[transformRecordCMTB]->offset = (unsigned short)((char *)&prec->cmtb - (char *)prec);
    prt->papFldDes[transformRecordCMTC]->size = sizeof(prec->cmtc);
    prt->papFldDes[transformRecordCMTC]->offset = (unsigned short)((char *)&prec->cmtc - (char *)prec);
    prt->papFldDes[transformRecordCMTD]->size = sizeof(prec->cmtd);
    prt->papFldDes[transformRecordCMTD]->offset = (unsigned short)((char *)&prec->cmtd - (char *)prec);
    prt->papFldDes[transformRecordCMTE]->size = sizeof(prec->cmte);
    prt->papFldDes[transformRecordCMTE]->offset = (unsigned short)((char *)&prec->cmte - (char *)prec);
    prt->papFldDes[transformRecordCMTF]->size = sizeof(prec->cmtf);
    prt->papFldDes[transformRecordCMTF]->offset = (unsigned short)((char *)&prec->cmtf - (char *)prec);
    prt->papFldDes[transformRecordCMTG]->size = sizeof(prec->cmtg);
    prt->papFldDes[transformRecordCMTG]->offset = (unsigned short)((char *)&prec->cmtg - (char *)prec);
    prt->papFldDes[transformRecordCMTH]->size = sizeof(prec->cmth);
    prt->papFldDes[transformRecordCMTH]->offset = (unsigned short)((char *)&prec->cmth - (char *)prec);
    prt->papFldDes[transformRecordCMTI]->size = sizeof(prec->cmti);
    prt->papFldDes[transformRecordCMTI]->offset = (unsigned short)((char *)&prec->cmti - (char *)prec);
    prt->papFldDes[transformRecordCMTJ]->size = sizeof(prec->cmtj);
    prt->papFldDes[transformRecordCMTJ]->offset = (unsigned short)((char *)&prec->cmtj - (char *)prec);
    prt->papFldDes[transformRecordCMTK]->size = sizeof(prec->cmtk);
    prt->papFldDes[transformRecordCMTK]->offset = (unsigned short)((char *)&prec->cmtk - (char *)prec);
    prt->papFldDes[transformRecordCMTL]->size = sizeof(prec->cmtl);
    prt->papFldDes[transformRecordCMTL]->offset = (unsigned short)((char *)&prec->cmtl - (char *)prec);
    prt->papFldDes[transformRecordCMTM]->size = sizeof(prec->cmtm);
    prt->papFldDes[transformRecordCMTM]->offset = (unsigned short)((char *)&prec->cmtm - (char *)prec);
    prt->papFldDes[transformRecordCMTN]->size = sizeof(prec->cmtn);
    prt->papFldDes[transformRecordCMTN]->offset = (unsigned short)((char *)&prec->cmtn - (char *)prec);
    prt->papFldDes[transformRecordCMTO]->size = sizeof(prec->cmto);
    prt->papFldDes[transformRecordCMTO]->offset = (unsigned short)((char *)&prec->cmto - (char *)prec);
    prt->papFldDes[transformRecordCMTP]->size = sizeof(prec->cmtp);
    prt->papFldDes[transformRecordCMTP]->offset = (unsigned short)((char *)&prec->cmtp - (char *)prec);
    prt->papFldDes[transformRecordMAP]->size = sizeof(prec->map);
    prt->papFldDes[transformRecordMAP]->offset = (unsigned short)((char *)&prec->map - (char *)prec);
    prt->papFldDes[transformRecordIAV]->size = sizeof(prec->iav);
    prt->papFldDes[transformRecordIAV]->offset = (unsigned short)((char *)&prec->iav - (char *)prec);
    prt->papFldDes[transformRecordIBV]->size = sizeof(prec->ibv);
    prt->papFldDes[transformRecordIBV]->offset = (unsigned short)((char *)&prec->ibv - (char *)prec);
    prt->papFldDes[transformRecordICV]->size = sizeof(prec->icv);
    prt->papFldDes[transformRecordICV]->offset = (unsigned short)((char *)&prec->icv - (char *)prec);
    prt->papFldDes[transformRecordIDV]->size = sizeof(prec->idv);
    prt->papFldDes[transformRecordIDV]->offset = (unsigned short)((char *)&prec->idv - (char *)prec);
    prt->papFldDes[transformRecordIEV]->size = sizeof(prec->iev);
    prt->papFldDes[transformRecordIEV]->offset = (unsigned short)((char *)&prec->iev - (char *)prec);
    prt->papFldDes[transformRecordIFV]->size = sizeof(prec->ifv);
    prt->papFldDes[transformRecordIFV]->offset = (unsigned short)((char *)&prec->ifv - (char *)prec);
    prt->papFldDes[transformRecordIGV]->size = sizeof(prec->igv);
    prt->papFldDes[transformRecordIGV]->offset = (unsigned short)((char *)&prec->igv - (char *)prec);
    prt->papFldDes[transformRecordIHV]->size = sizeof(prec->ihv);
    prt->papFldDes[transformRecordIHV]->offset = (unsigned short)((char *)&prec->ihv - (char *)prec);
    prt->papFldDes[transformRecordIIV]->size = sizeof(prec->iiv);
    prt->papFldDes[transformRecordIIV]->offset = (unsigned short)((char *)&prec->iiv - (char *)prec);
    prt->papFldDes[transformRecordIJV]->size = sizeof(prec->ijv);
    prt->papFldDes[transformRecordIJV]->offset = (unsigned short)((char *)&prec->ijv - (char *)prec);
    prt->papFldDes[transformRecordIKV]->size = sizeof(prec->ikv);
    prt->papFldDes[transformRecordIKV]->offset = (unsigned short)((char *)&prec->ikv - (char *)prec);
    prt->papFldDes[transformRecordILV]->size = sizeof(prec->ilv);
    prt->papFldDes[transformRecordILV]->offset = (unsigned short)((char *)&prec->ilv - (char *)prec);
    prt->papFldDes[transformRecordIMV]->size = sizeof(prec->imv);
    prt->papFldDes[transformRecordIMV]->offset = (unsigned short)((char *)&prec->imv - (char *)prec);
    prt->papFldDes[transformRecordINV]->size = sizeof(prec->inv);
    prt->papFldDes[transformRecordINV]->offset = (unsigned short)((char *)&prec->inv - (char *)prec);
    prt->papFldDes[transformRecordIOV]->size = sizeof(prec->iov);
    prt->papFldDes[transformRecordIOV]->offset = (unsigned short)((char *)&prec->iov - (char *)prec);
    prt->papFldDes[transformRecordIPV]->size = sizeof(prec->ipv);
    prt->papFldDes[transformRecordIPV]->offset = (unsigned short)((char *)&prec->ipv - (char *)prec);
    prt->papFldDes[transformRecordOAV]->size = sizeof(prec->oav);
    prt->papFldDes[transformRecordOAV]->offset = (unsigned short)((char *)&prec->oav - (char *)prec);
    prt->papFldDes[transformRecordOBV]->size = sizeof(prec->obv);
    prt->papFldDes[transformRecordOBV]->offset = (unsigned short)((char *)&prec->obv - (char *)prec);
    prt->papFldDes[transformRecordOCV]->size = sizeof(prec->ocv);
    prt->papFldDes[transformRecordOCV]->offset = (unsigned short)((char *)&prec->ocv - (char *)prec);
    prt->papFldDes[transformRecordODV]->size = sizeof(prec->odv);
    prt->papFldDes[transformRecordODV]->offset = (unsigned short)((char *)&prec->odv - (char *)prec);
    prt->papFldDes[transformRecordOEV]->size = sizeof(prec->oev);
    prt->papFldDes[transformRecordOEV]->offset = (unsigned short)((char *)&prec->oev - (char *)prec);
    prt->papFldDes[transformRecordOFV]->size = sizeof(prec->ofv);
    prt->papFldDes[transformRecordOFV]->offset = (unsigned short)((char *)&prec->ofv - (char *)prec);
    prt->papFldDes[transformRecordOGV]->size = sizeof(prec->ogv);
    prt->papFldDes[transformRecordOGV]->offset = (unsigned short)((char *)&prec->ogv - (char *)prec);
    prt->papFldDes[transformRecordOHV]->size = sizeof(prec->ohv);
    prt->papFldDes[transformRecordOHV]->offset = (unsigned short)((char *)&prec->ohv - (char *)prec);
    prt->papFldDes[transformRecordOIV]->size = sizeof(prec->oiv);
    prt->papFldDes[transformRecordOIV]->offset = (unsigned short)((char *)&prec->oiv - (char *)prec);
    prt->papFldDes[transformRecordOJV]->size = sizeof(prec->ojv);
    prt->papFldDes[transformRecordOJV]->offset = (unsigned short)((char *)&prec->ojv - (char *)prec);
    prt->papFldDes[transformRecordOKV]->size = sizeof(prec->okv);
    prt->papFldDes[transformRecordOKV]->offset = (unsigned short)((char *)&prec->okv - (char *)prec);
    prt->papFldDes[transformRecordOLV]->size = sizeof(prec->olv);
    prt->papFldDes[transformRecordOLV]->offset = (unsigned short)((char *)&prec->olv - (char *)prec);
    prt->papFldDes[transformRecordOMV]->size = sizeof(prec->omv);
    prt->papFldDes[transformRecordOMV]->offset = (unsigned short)((char *)&prec->omv - (char *)prec);
    prt->papFldDes[transformRecordONV]->size = sizeof(prec->onv);
    prt->papFldDes[transformRecordONV]->offset = (unsigned short)((char *)&prec->onv - (char *)prec);
    prt->papFldDes[transformRecordOOV]->size = sizeof(prec->oov);
    prt->papFldDes[transformRecordOOV]->offset = (unsigned short)((char *)&prec->oov - (char *)prec);
    prt->papFldDes[transformRecordOPV]->size = sizeof(prec->opv);
    prt->papFldDes[transformRecordOPV]->offset = (unsigned short)((char *)&prec->opv - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(transformRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_transformRecord_H */
