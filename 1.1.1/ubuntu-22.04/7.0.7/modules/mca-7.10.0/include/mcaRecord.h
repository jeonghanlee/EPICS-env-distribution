/** @file mcaRecord.h
 * @brief Declarations for the @ref mcaRecord "mca" record type.
 *
 * This header was generated from mcaRecord.dbd
 */

#ifndef INC_mcaRecord_H
#define INC_mcaRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef mcaMODE_NUM_CHOICES
/** @brief Enumerated type from menu mcaMODE */
typedef enum {
    mcaMODE_PHA                     /**< @brief State string "PHA" */,
    mcaMODE_MCS                     /**< @brief State string "MCS" */,
    mcaMODE_List                    /**< @brief State string "List" */
} mcaMODE;
/** @brief Number of states defined for menu mcaMODE */
#define mcaMODE_NUM_CHOICES 3
#endif

#ifndef mcaSTRT_NUM_CHOICES
/** @brief Enumerated type from menu mcaSTRT */
typedef enum {
    mcaSTRT_Done                    /**< @brief State string "Done" */,
    mcaSTRT_Acquire                 /**< @brief State string "Acquire" */
} mcaSTRT;
/** @brief Number of states defined for menu mcaSTRT */
#define mcaSTRT_NUM_CHOICES 2
#endif

#ifndef mcaR0IP_NUM_CHOICES
/** @brief Enumerated type from menu mcaR0IP */
typedef enum {
    mcaR0IP_N                       /**< @brief State string "N" */,
    mcaR0IP_Y                       /**< @brief State string "Y" */
} mcaR0IP;
/** @brief Number of states defined for menu mcaR0IP */
#define mcaR0IP_NUM_CHOICES 2
#endif

#ifndef mcaCHAS_NUM_CHOICES
/** @brief Enumerated type from menu mcaCHAS */
typedef enum {
    mcaCHAS_Internal                /**< @brief State string "Internal" */,
    mcaCHAS_External                /**< @brief State string "External" */
} mcaCHAS;
/** @brief Number of states defined for menu mcaCHAS */
#define mcaCHAS_NUM_CHOICES 2
#endif

#ifndef mcaERAS_NUM_CHOICES
/** @brief Enumerated type from menu mcaERAS */
typedef enum {
    mcaERAS_Done                    /**< @brief State string "Done" */,
    mcaERAS_Erase                   /**< @brief State string "Erase" */
} mcaERAS;
/** @brief Number of states defined for menu mcaERAS */
#define mcaERAS_NUM_CHOICES 2
#endif

#ifndef mcaREAD_NUM_CHOICES
/** @brief Enumerated type from menu mcaREAD */
typedef enum {
    mcaREAD_Done                    /**< @brief State string "Done" */,
    mcaREAD_Read                    /**< @brief State string "Read" */
} mcaREAD;
/** @brief Number of states defined for menu mcaREAD */
#define mcaREAD_NUM_CHOICES 2
#endif

/** @brief Declaration of mca record type. */
typedef struct mcaRecord {
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
    epicsFloat64        vers;       /**< @brief Code Version */
    void *val;                      /**< @brief Value */
    void *bptr;                     /**< @brief Buffer Pointer */
    void *bg;                       /**< @brief Background */
    void *pbg;                      /**< @brief Background buffer */
    void *pstatus;                  /**< @brief Status buffer */
    epicsFloat64        hopr;       /**< @brief High Operating Range */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsInt32          nmax;       /**< @brief Max number of channels */
    epicsInt32          nord;       /**< @brief Number of channels read */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsEnum16         ftvl;       /**< @brief Field Type of Value */
    epicsEnum16         strt;       /**< @brief Start Acquire */
    epicsEnum16         erst;       /**< @brief Erase & Start Acquire */
    epicsEnum16         stop;       /**< @brief Stop Acquire */
    epicsEnum16         acqg;       /**< @brief Acquiring */
    epicsEnum16         read;       /**< @brief Read array */
    epicsEnum16         rdng;       /**< @brief Reading array */
    epicsEnum16         rdns;       /**< @brief Reading status */
    epicsEnum16         eras;       /**< @brief Erase array */
    epicsEnum16         chas;       /**< @brief Channel-advance source */
    epicsInt32          nuse;       /**< @brief  # of channels to use */
    epicsInt32          seq;        /**< @brief Time sequence # */
    epicsFloat64        dwel;       /**< @brief Dwell time per channel */
    epicsInt32          pscl;       /**< @brief Channel advance prescale */
    epicsFloat64        prtm;       /**< @brief Preset real time */
    epicsFloat64        pltm;       /**< @brief Preset live time */
    epicsFloat64        pct;        /**< @brief Preset counts */
    epicsInt32          pctl;       /**< @brief Preset count low channe */
    epicsInt32          pcth;       /**< @brief Preset count high chann */
    epicsInt32          pswp;       /**< @brief Preset number of sweeps */
    epicsEnum16         mode;       /**< @brief Mode PHA/MCS/LIST */
    epicsFloat64        calo;       /**< @brief Calibration offset */
    epicsFloat64        cals;       /**< @brief Calibration slope */
    epicsFloat64        calq;       /**< @brief Calibration quadratic */
    char                egu[16];    /**< @brief Calibration Units Name */
    epicsFloat64        tth;        /**< @brief Two-theta */
    epicsFloat64        ertm;       /**< @brief Elapsed real time */
    epicsFloat64        eltm;       /**< @brief Elapsed live time */
    epicsFloat64        dtim;       /**< @brief Average % dead time */
    epicsFloat64        idtim;      /**< @brief Instantaneous % dead time */
    char                stim[40];   /**< @brief Acquisition stop time */
    epicsFloat64        rtim;       /**< @brief Last read time */
    epicsInt32          act;        /**< @brief Actual counts in pregio */
    epicsInt16          nack;       /**< @brief Message not acknowledge */
    DBLINK              inp;        /**< @brief Input Specification */
    epicsFloat64        hihi;       /**< @brief Hihi Deviation Limit */
    epicsFloat64        lolo;       /**< @brief Lolo Deviation Limit */
    epicsFloat64        high;       /**< @brief High Deviation Limit */
    epicsFloat64        low;        /**< @brief Low Deviation Limit */
    epicsEnum16         hhsv;       /**< @brief Hihi Severity */
    epicsEnum16         llsv;       /**< @brief Lolo Severity */
    epicsEnum16         hsv;        /**< @brief High Severity */
    epicsEnum16         lsv;        /**< @brief Low Severity */
    epicsFloat64        hyst;       /**< @brief Alarm Deadband */
    epicsFloat64        lalm;       /**< @brief Last Value Alarmed */
    DBLINK              siol;       /**< @brief Sim Input Specifctn */
    DBLINK              siml;       /**< @brief Sim Mode Location */
    epicsEnum16         simm;       /**< @brief Simulation Mode */
    epicsEnum16         sims;       /**< @brief Sim mode Alarm Svrty */
    epicsUInt32         mmap;       /**< @brief Monitor map */
    epicsUInt32         rmap;       /**< @brief ROI monitor map */
    epicsUInt32         newv;       /**< @brief New Value map */
    epicsUInt32         newr;       /**< @brief New ROI Value map */
    epicsInt32          r0lo;       /**< @brief Region 0 low channel */
    epicsInt32          r0hi;       /**< @brief Region 0 high channel */
    epicsInt16          r0bg;       /**< @brief Region 0 bkgrnd chans */
    epicsEnum16         r0ip;       /**< @brief Region 0 is preset */
    epicsInt32          r1lo;       /**< @brief Region 1 low channel */
    epicsInt32          r1hi;       /**< @brief Region 1 high channel */
    epicsInt16          r1bg;       /**< @brief Region 1 bkgrnd chans */
    epicsEnum16         r1ip;       /**< @brief Region 1 is preset */
    epicsInt32          r2lo;       /**< @brief Region 2 low channel */
    epicsInt32          r2hi;       /**< @brief Region 2 high channel */
    epicsInt16          r2bg;       /**< @brief Region 2 bkgrnd chans */
    epicsEnum16         r2ip;       /**< @brief Region 2 is preset */
    epicsInt32          r3lo;       /**< @brief Region 3 low channel */
    epicsInt32          r3hi;       /**< @brief Region 3 high channel */
    epicsInt16          r3bg;       /**< @brief Region 3 bkgrnd chans */
    epicsEnum16         r3ip;       /**< @brief Region 3 is preset */
    epicsInt32          r4lo;       /**< @brief Region 4 low channel */
    epicsInt32          r4hi;       /**< @brief Region 4 high channel */
    epicsInt16          r4bg;       /**< @brief Region 4 bkgrnd chans */
    epicsEnum16         r4ip;       /**< @brief Region 4 is preset */
    epicsInt32          r5lo;       /**< @brief Region 5 low channel */
    epicsInt32          r5hi;       /**< @brief Region 5 high channel */
    epicsInt16          r5bg;       /**< @brief Region 5 bkgrnd chans */
    epicsEnum16         r5ip;       /**< @brief Region 5 is preset */
    epicsInt32          r6lo;       /**< @brief Region 6 low channel */
    epicsInt32          r6hi;       /**< @brief Region 6 high channel */
    epicsInt16          r6bg;       /**< @brief Region 6 bkgrnd chans */
    epicsEnum16         r6ip;       /**< @brief Region 6 is preset */
    epicsInt32          r7lo;       /**< @brief Region 7 low channel */
    epicsInt32          r7hi;       /**< @brief Region 7 high channel */
    epicsInt16          r7bg;       /**< @brief Region 7 bkgrnd chans */
    epicsEnum16         r7ip;       /**< @brief Region 7 is preset */
    epicsInt32          r8lo;       /**< @brief Region 8 low channel */
    epicsInt32          r8hi;       /**< @brief Region 8 high channel */
    epicsInt16          r8bg;       /**< @brief Region 8 bkgrnd chans */
    epicsEnum16         r8ip;       /**< @brief Region 8 is preset */
    epicsInt32          r9lo;       /**< @brief Region 9 low channel */
    epicsInt32          r9hi;       /**< @brief Region 9 high channel */
    epicsInt16          r9bg;       /**< @brief Region 9 bkgrnd chans */
    epicsEnum16         r9ip;       /**< @brief Region 9 is preset */
    epicsInt32          r10lo;      /**< @brief Region 10 low channel */
    epicsInt32          r10hi;      /**< @brief Region 10 high channel */
    epicsInt16          r10bg;      /**< @brief Region 10 bkgrnd chans */
    epicsEnum16         r10ip;      /**< @brief Region 10 is preset */
    epicsInt32          r11lo;      /**< @brief Region 11 low channel */
    epicsInt32          r11hi;      /**< @brief Region 11 high channel */
    epicsInt16          r11bg;      /**< @brief Region 11 bkgrnd chans */
    epicsEnum16         r11ip;      /**< @brief Region 11 is preset */
    epicsInt32          r12lo;      /**< @brief Region 12 low channel */
    epicsInt32          r12hi;      /**< @brief Region 12 high channel */
    epicsInt16          r12bg;      /**< @brief Region 12 bkgrnd chans */
    epicsEnum16         r12ip;      /**< @brief Region 12 is preset */
    epicsInt32          r13lo;      /**< @brief Region 13 low channel */
    epicsInt32          r13hi;      /**< @brief Region 13 high channel */
    epicsInt16          r13bg;      /**< @brief Region 13 bkgrnd chans */
    epicsEnum16         r13ip;      /**< @brief Region 13 is preset */
    epicsInt32          r14lo;      /**< @brief Region 14 low channel */
    epicsInt32          r14hi;      /**< @brief Region 14 high channel */
    epicsInt16          r14bg;      /**< @brief Region 14 bkgrnd chans */
    epicsEnum16         r14ip;      /**< @brief Region 14 is preset */
    epicsInt32          r15lo;      /**< @brief Region 15 low channel */
    epicsInt32          r15hi;      /**< @brief Region 15 high channel */
    epicsInt16          r15bg;      /**< @brief Region 15 bkgrnd chans */
    epicsEnum16         r15ip;      /**< @brief Region 15 is preset */
    epicsInt32          r16lo;      /**< @brief Region 16 low channel */
    epicsInt32          r16hi;      /**< @brief Region 16 high channel */
    epicsInt16          r16bg;      /**< @brief Region 16 bkgrnd chans */
    epicsEnum16         r16ip;      /**< @brief Region 16 is preset */
    epicsInt32          r17lo;      /**< @brief Region 17 low channel */
    epicsInt32          r17hi;      /**< @brief Region 17 high channel */
    epicsInt16          r17bg;      /**< @brief Region 17 bkgrnd chans */
    epicsEnum16         r17ip;      /**< @brief Region 17 is preset */
    epicsInt32          r18lo;      /**< @brief Region 18 low channel */
    epicsInt32          r18hi;      /**< @brief Region 18 high channel */
    epicsInt16          r18bg;      /**< @brief Region 18 bkgrnd chans */
    epicsEnum16         r18ip;      /**< @brief Region 18 is preset */
    epicsInt32          r19lo;      /**< @brief Region 19 low channel */
    epicsInt32          r19hi;      /**< @brief Region 19 high channel */
    epicsInt16          r19bg;      /**< @brief Region 19 bkgrnd chans */
    epicsEnum16         r19ip;      /**< @brief Region 19 is preset */
    epicsInt32          r20lo;      /**< @brief Region 20 low channel */
    epicsInt32          r20hi;      /**< @brief Region 20 high channel */
    epicsInt16          r20bg;      /**< @brief Region 20 bkgrnd chans */
    epicsEnum16         r20ip;      /**< @brief Region 20 is preset */
    epicsInt32          r21lo;      /**< @brief Region 21 low channel */
    epicsInt32          r21hi;      /**< @brief Region 21 high channel */
    epicsInt16          r21bg;      /**< @brief Region 21 bkgrnd chans */
    epicsEnum16         r21ip;      /**< @brief Region 21 is preset */
    epicsInt32          r22lo;      /**< @brief Region 22 low channel */
    epicsInt32          r22hi;      /**< @brief Region 22 high channel */
    epicsInt16          r22bg;      /**< @brief Region 22 bkgrnd chans */
    epicsEnum16         r22ip;      /**< @brief Region 22 is preset */
    epicsInt32          r23lo;      /**< @brief Region 23 low channel */
    epicsInt32          r23hi;      /**< @brief Region 23 high channel */
    epicsInt16          r23bg;      /**< @brief Region 23 bkgrnd chans */
    epicsEnum16         r23ip;      /**< @brief Region 23 is preset */
    epicsInt32          r24lo;      /**< @brief Region 24 low channel */
    epicsInt32          r24hi;      /**< @brief Region 24 high channel */
    epicsInt16          r24bg;      /**< @brief Region 24 bkgrnd chans */
    epicsEnum16         r24ip;      /**< @brief Region 24 is preset */
    epicsInt32          r25lo;      /**< @brief Region 25 low channel */
    epicsInt32          r25hi;      /**< @brief Region 25 high channel */
    epicsInt16          r25bg;      /**< @brief Region 25 bkgrnd chans */
    epicsEnum16         r25ip;      /**< @brief Region 25 is preset */
    epicsInt32          r26lo;      /**< @brief Region 26 low channel */
    epicsInt32          r26hi;      /**< @brief Region 26 high channel */
    epicsInt16          r26bg;      /**< @brief Region 26 bkgrnd chans */
    epicsEnum16         r26ip;      /**< @brief Region 26 is preset */
    epicsInt32          r27lo;      /**< @brief Region 27 low channel */
    epicsInt32          r27hi;      /**< @brief Region 27 high channel */
    epicsInt16          r27bg;      /**< @brief Region 27 bkgrnd chans */
    epicsEnum16         r27ip;      /**< @brief Region 27 is preset */
    epicsInt32          r28lo;      /**< @brief Region 28 low channel */
    epicsInt32          r28hi;      /**< @brief Region 28 high channel */
    epicsInt16          r28bg;      /**< @brief Region 28 bkgrnd chans */
    epicsEnum16         r28ip;      /**< @brief Region 28 is preset */
    epicsInt32          r29lo;      /**< @brief Region 29 low channel */
    epicsInt32          r29hi;      /**< @brief Region 29 high channel */
    epicsInt16          r29bg;      /**< @brief Region 29 bkgrnd chans */
    epicsEnum16         r29ip;      /**< @brief Region 29 is preset */
    epicsInt32          r30lo;      /**< @brief Region 30 low channel */
    epicsInt32          r30hi;      /**< @brief Region 30 high channel */
    epicsInt16          r30bg;      /**< @brief Region 30 bkgrnd chans */
    epicsEnum16         r30ip;      /**< @brief Region 30 is preset */
    epicsInt32          r31lo;      /**< @brief Region 31 low channel */
    epicsInt32          r31hi;      /**< @brief Region 31 high channel */
    epicsInt16          r31bg;      /**< @brief Region 31 bkgrnd chans */
    epicsEnum16         r31ip;      /**< @brief Region 31 is preset */
    epicsFloat64        r0;         /**< @brief Region 0 counts */
    epicsFloat64        r0n;        /**< @brief Region 0 net counts */
    epicsFloat64        r0p;        /**< @brief Region 0 preset count */
    epicsFloat64        r1;         /**< @brief Region 1 counts */
    epicsFloat64        r1n;        /**< @brief Region 1 net counts */
    epicsFloat64        r1p;        /**< @brief Region 1 preset count */
    epicsFloat64        r2;         /**< @brief Region 2 counts */
    epicsFloat64        r2n;        /**< @brief Region 2 net counts */
    epicsFloat64        r2p;        /**< @brief Region 2 preset count */
    epicsFloat64        r3;         /**< @brief Region 3 counts */
    epicsFloat64        r3n;        /**< @brief Region 3 net counts */
    epicsFloat64        r3p;        /**< @brief Region 3 preset count */
    epicsFloat64        r4;         /**< @brief Region 4 counts */
    epicsFloat64        r4n;        /**< @brief Region 4 net counts */
    epicsFloat64        r4p;        /**< @brief Region 4 preset count */
    epicsFloat64        r5;         /**< @brief Region 5 counts */
    epicsFloat64        r5n;        /**< @brief Region 5 net counts */
    epicsFloat64        r5p;        /**< @brief Region 5 preset count */
    epicsFloat64        r6;         /**< @brief Region 6 counts */
    epicsFloat64        r6n;        /**< @brief Region 6 net counts */
    epicsFloat64        r6p;        /**< @brief Region 6 preset */
    epicsFloat64        r7;         /**< @brief Region 7 counts */
    epicsFloat64        r7n;        /**< @brief Region 7 net counts */
    epicsFloat64        r7p;        /**< @brief Region 7 preset */
    epicsFloat64        r8;         /**< @brief Region 8 counts */
    epicsFloat64        r8n;        /**< @brief Region 8 net counts */
    epicsFloat64        r8p;        /**< @brief Region 8 preset */
    epicsFloat64        r9;         /**< @brief Region 9 counts */
    epicsFloat64        r9n;        /**< @brief Region 9 net counts */
    epicsFloat64        r9p;        /**< @brief Region 9 preset */
    epicsFloat64        r10;        /**< @brief Region 10 counts */
    epicsFloat64        r10n;       /**< @brief Region 10 net counts */
    epicsFloat64        r10p;       /**< @brief Region 10 preset */
    epicsFloat64        r11;        /**< @brief Region 11 counts */
    epicsFloat64        r11n;       /**< @brief Region 11 net counts */
    epicsFloat64        r11p;       /**< @brief Region 11 preset */
    epicsFloat64        r12;        /**< @brief Region 12 counts */
    epicsFloat64        r12n;       /**< @brief Region 12 net counts */
    epicsFloat64        r12p;       /**< @brief Region 12 preset */
    epicsFloat64        r13;        /**< @brief Region 13 counts */
    epicsFloat64        r13n;       /**< @brief Region 13 net counts */
    epicsFloat64        r13p;       /**< @brief Region 13 preset */
    epicsFloat64        r14;        /**< @brief Region 14 counts */
    epicsFloat64        r14n;       /**< @brief Region 14 net counts */
    epicsFloat64        r14p;       /**< @brief Region 14 preset */
    epicsFloat64        r15;        /**< @brief Region 15 counts */
    epicsFloat64        r15n;       /**< @brief Region 15 net counts */
    epicsFloat64        r15p;       /**< @brief Region 15 preset */
    epicsFloat64        r16;        /**< @brief Region 16 counts */
    epicsFloat64        r16n;       /**< @brief Region 16 net counts */
    epicsFloat64        r16p;       /**< @brief Region 16 preset */
    epicsFloat64        r17;        /**< @brief Region 17 counts */
    epicsFloat64        r17n;       /**< @brief Region 17 net counts */
    epicsFloat64        r17p;       /**< @brief Region 17 preset */
    epicsFloat64        r18;        /**< @brief Region 18 counts */
    epicsFloat64        r18n;       /**< @brief Region 18 net counts */
    epicsFloat64        r18p;       /**< @brief Region 18 preset */
    epicsFloat64        r19;        /**< @brief Region 19 counts */
    epicsFloat64        r19n;       /**< @brief Region 19 net counts */
    epicsFloat64        r19p;       /**< @brief Region 19 preset */
    epicsFloat64        r20;        /**< @brief Region 20 counts */
    epicsFloat64        r20n;       /**< @brief Region 20 net counts */
    epicsFloat64        r20p;       /**< @brief Region 20 preset */
    epicsFloat64        r21;        /**< @brief Region 21 counts */
    epicsFloat64        r21n;       /**< @brief Region 21 net counts */
    epicsFloat64        r21p;       /**< @brief Region 21 preset */
    epicsFloat64        r22;        /**< @brief Region 22 counts */
    epicsFloat64        r22n;       /**< @brief Region 22 net counts */
    epicsFloat64        r22p;       /**< @brief Region 22 preset */
    epicsFloat64        r23;        /**< @brief Region 23 counts */
    epicsFloat64        r23n;       /**< @brief Region 23 net counts */
    epicsFloat64        r23p;       /**< @brief Region 23 preset */
    epicsFloat64        r24;        /**< @brief Region 24 counts */
    epicsFloat64        r24n;       /**< @brief Region 24 net counts */
    epicsFloat64        r24p;       /**< @brief Region 24 preset */
    epicsFloat64        r25;        /**< @brief Region 25 counts */
    epicsFloat64        r25n;       /**< @brief Region 25 net counts */
    epicsFloat64        r25p;       /**< @brief Region 25 preset */
    epicsFloat64        r26;        /**< @brief Region 26 counts */
    epicsFloat64        r26n;       /**< @brief Region 26 net counts */
    epicsFloat64        r26p;       /**< @brief Region 26 preset */
    epicsFloat64        r27;        /**< @brief Region 27 counts */
    epicsFloat64        r27n;       /**< @brief Region 27 net counts */
    epicsFloat64        r27p;       /**< @brief Region 27 preset */
    epicsFloat64        r28;        /**< @brief Region 28 counts */
    epicsFloat64        r28n;       /**< @brief Region 28 net counts */
    epicsFloat64        r28p;       /**< @brief Region 28 preset */
    epicsFloat64        r29;        /**< @brief Region 29 counts */
    epicsFloat64        r29n;       /**< @brief Region 29 net counts */
    epicsFloat64        r29p;       /**< @brief Region 29 preset */
    epicsFloat64        r30;        /**< @brief Region 30 counts */
    epicsFloat64        r30n;       /**< @brief Region 30 net counts */
    epicsFloat64        r30p;       /**< @brief Region 30 preset */
    epicsFloat64        r31;        /**< @brief Region 31 counts */
    epicsFloat64        r31n;       /**< @brief Region 31 net counts */
    epicsFloat64        r31p;       /**< @brief Region 31 preset */
    char                r0nm[16];   /**< @brief Region 0 name */
    char                r1nm[16];   /**< @brief Region 1 name */
    char                r2nm[16];   /**< @brief Region 2 name */
    char                r3nm[16];   /**< @brief Region 3 name */
    char                r4nm[16];   /**< @brief Region 4 name */
    char                r5nm[16];   /**< @brief Region 5 name */
    char                r6nm[16];   /**< @brief Region 6 name */
    char                r7nm[16];   /**< @brief Region 7 name */
    char                r8nm[16];   /**< @brief Region 8 name */
    char                r9nm[16];   /**< @brief Region 9 name */
    char                r10nm[16];  /**< @brief Region 10 name */
    char                r11nm[16];  /**< @brief Region 11 name */
    char                r12nm[16];  /**< @brief Region 12 name */
    char                r13nm[16];  /**< @brief Region 13 name */
    char                r14nm[16];  /**< @brief Region 14 name */
    char                r15nm[16];  /**< @brief Region 15 name */
    char                r16nm[16];  /**< @brief Region 16 name */
    char                r17nm[16];  /**< @brief Region 17 name */
    char                r18nm[16];  /**< @brief Region 18 name */
    char                r19nm[16];  /**< @brief Region 19 name */
    char                r20nm[16];  /**< @brief Region 20 name */
    char                r21nm[16];  /**< @brief Region 21 name */
    char                r22nm[16];  /**< @brief Region 22 name */
    char                r23nm[16];  /**< @brief Region 23 name */
    char                r24nm[16];  /**< @brief Region 24 name */
    char                r25nm[16];  /**< @brief Region 25 name */
    char                r26nm[16];  /**< @brief Region 26 name */
    char                r27nm[16];  /**< @brief Region 27 name */
    char                r28nm[16];  /**< @brief Region 28 name */
    char                r29nm[16];  /**< @brief Region 29 name */
    char                r30nm[16];  /**< @brief Region 30 name */
    char                r31nm[16];  /**< @brief Region 31 name */
} mcaRecord;

typedef enum {
	mcaRecordNAME = 0,
	mcaRecordDESC = 1,
	mcaRecordASG = 2,
	mcaRecordSCAN = 3,
	mcaRecordPINI = 4,
	mcaRecordPHAS = 5,
	mcaRecordEVNT = 6,
	mcaRecordTSE = 7,
	mcaRecordTSEL = 8,
	mcaRecordDTYP = 9,
	mcaRecordDISV = 10,
	mcaRecordDISA = 11,
	mcaRecordSDIS = 12,
	mcaRecordMLOK = 13,
	mcaRecordMLIS = 14,
	mcaRecordBKLNK = 15,
	mcaRecordDISP = 16,
	mcaRecordPROC = 17,
	mcaRecordSTAT = 18,
	mcaRecordSEVR = 19,
	mcaRecordAMSG = 20,
	mcaRecordNSTA = 21,
	mcaRecordNSEV = 22,
	mcaRecordNAMSG = 23,
	mcaRecordACKS = 24,
	mcaRecordACKT = 25,
	mcaRecordDISS = 26,
	mcaRecordLCNT = 27,
	mcaRecordPACT = 28,
	mcaRecordPUTF = 29,
	mcaRecordRPRO = 30,
	mcaRecordASP = 31,
	mcaRecordPPN = 32,
	mcaRecordPPNR = 33,
	mcaRecordSPVT = 34,
	mcaRecordRSET = 35,
	mcaRecordDSET = 36,
	mcaRecordDPVT = 37,
	mcaRecordRDES = 38,
	mcaRecordLSET = 39,
	mcaRecordPRIO = 40,
	mcaRecordTPRO = 41,
	mcaRecordBKPT = 42,
	mcaRecordUDF = 43,
	mcaRecordUDFS = 44,
	mcaRecordTIME = 45,
	mcaRecordUTAG = 46,
	mcaRecordFLNK = 47,
	mcaRecordVERS = 48,
	mcaRecordVAL = 49,
	mcaRecordBPTR = 50,
	mcaRecordBG = 51,
	mcaRecordPBG = 52,
	mcaRecordPSTATUS = 53,
	mcaRecordHOPR = 54,
	mcaRecordLOPR = 55,
	mcaRecordNMAX = 56,
	mcaRecordNORD = 57,
	mcaRecordPREC = 58,
	mcaRecordFTVL = 59,
	mcaRecordSTRT = 60,
	mcaRecordERST = 61,
	mcaRecordSTOP = 62,
	mcaRecordACQG = 63,
	mcaRecordREAD = 64,
	mcaRecordRDNG = 65,
	mcaRecordRDNS = 66,
	mcaRecordERAS = 67,
	mcaRecordCHAS = 68,
	mcaRecordNUSE = 69,
	mcaRecordSEQ = 70,
	mcaRecordDWEL = 71,
	mcaRecordPSCL = 72,
	mcaRecordPRTM = 73,
	mcaRecordPLTM = 74,
	mcaRecordPCT = 75,
	mcaRecordPCTL = 76,
	mcaRecordPCTH = 77,
	mcaRecordPSWP = 78,
	mcaRecordMODE = 79,
	mcaRecordCALO = 80,
	mcaRecordCALS = 81,
	mcaRecordCALQ = 82,
	mcaRecordEGU = 83,
	mcaRecordTTH = 84,
	mcaRecordERTM = 85,
	mcaRecordELTM = 86,
	mcaRecordDTIM = 87,
	mcaRecordIDTIM = 88,
	mcaRecordSTIM = 89,
	mcaRecordRTIM = 90,
	mcaRecordACT = 91,
	mcaRecordNACK = 92,
	mcaRecordINP = 93,
	mcaRecordHIHI = 94,
	mcaRecordLOLO = 95,
	mcaRecordHIGH = 96,
	mcaRecordLOW = 97,
	mcaRecordHHSV = 98,
	mcaRecordLLSV = 99,
	mcaRecordHSV = 100,
	mcaRecordLSV = 101,
	mcaRecordHYST = 102,
	mcaRecordLALM = 103,
	mcaRecordSIOL = 104,
	mcaRecordSIML = 105,
	mcaRecordSIMM = 106,
	mcaRecordSIMS = 107,
	mcaRecordMMAP = 108,
	mcaRecordRMAP = 109,
	mcaRecordNEWV = 110,
	mcaRecordNEWR = 111,
	mcaRecordR0LO = 112,
	mcaRecordR0HI = 113,
	mcaRecordR0BG = 114,
	mcaRecordR0IP = 115,
	mcaRecordR1LO = 116,
	mcaRecordR1HI = 117,
	mcaRecordR1BG = 118,
	mcaRecordR1IP = 119,
	mcaRecordR2LO = 120,
	mcaRecordR2HI = 121,
	mcaRecordR2BG = 122,
	mcaRecordR2IP = 123,
	mcaRecordR3LO = 124,
	mcaRecordR3HI = 125,
	mcaRecordR3BG = 126,
	mcaRecordR3IP = 127,
	mcaRecordR4LO = 128,
	mcaRecordR4HI = 129,
	mcaRecordR4BG = 130,
	mcaRecordR4IP = 131,
	mcaRecordR5LO = 132,
	mcaRecordR5HI = 133,
	mcaRecordR5BG = 134,
	mcaRecordR5IP = 135,
	mcaRecordR6LO = 136,
	mcaRecordR6HI = 137,
	mcaRecordR6BG = 138,
	mcaRecordR6IP = 139,
	mcaRecordR7LO = 140,
	mcaRecordR7HI = 141,
	mcaRecordR7BG = 142,
	mcaRecordR7IP = 143,
	mcaRecordR8LO = 144,
	mcaRecordR8HI = 145,
	mcaRecordR8BG = 146,
	mcaRecordR8IP = 147,
	mcaRecordR9LO = 148,
	mcaRecordR9HI = 149,
	mcaRecordR9BG = 150,
	mcaRecordR9IP = 151,
	mcaRecordR10LO = 152,
	mcaRecordR10HI = 153,
	mcaRecordR10BG = 154,
	mcaRecordR10IP = 155,
	mcaRecordR11LO = 156,
	mcaRecordR11HI = 157,
	mcaRecordR11BG = 158,
	mcaRecordR11IP = 159,
	mcaRecordR12LO = 160,
	mcaRecordR12HI = 161,
	mcaRecordR12BG = 162,
	mcaRecordR12IP = 163,
	mcaRecordR13LO = 164,
	mcaRecordR13HI = 165,
	mcaRecordR13BG = 166,
	mcaRecordR13IP = 167,
	mcaRecordR14LO = 168,
	mcaRecordR14HI = 169,
	mcaRecordR14BG = 170,
	mcaRecordR14IP = 171,
	mcaRecordR15LO = 172,
	mcaRecordR15HI = 173,
	mcaRecordR15BG = 174,
	mcaRecordR15IP = 175,
	mcaRecordR16LO = 176,
	mcaRecordR16HI = 177,
	mcaRecordR16BG = 178,
	mcaRecordR16IP = 179,
	mcaRecordR17LO = 180,
	mcaRecordR17HI = 181,
	mcaRecordR17BG = 182,
	mcaRecordR17IP = 183,
	mcaRecordR18LO = 184,
	mcaRecordR18HI = 185,
	mcaRecordR18BG = 186,
	mcaRecordR18IP = 187,
	mcaRecordR19LO = 188,
	mcaRecordR19HI = 189,
	mcaRecordR19BG = 190,
	mcaRecordR19IP = 191,
	mcaRecordR20LO = 192,
	mcaRecordR20HI = 193,
	mcaRecordR20BG = 194,
	mcaRecordR20IP = 195,
	mcaRecordR21LO = 196,
	mcaRecordR21HI = 197,
	mcaRecordR21BG = 198,
	mcaRecordR21IP = 199,
	mcaRecordR22LO = 200,
	mcaRecordR22HI = 201,
	mcaRecordR22BG = 202,
	mcaRecordR22IP = 203,
	mcaRecordR23LO = 204,
	mcaRecordR23HI = 205,
	mcaRecordR23BG = 206,
	mcaRecordR23IP = 207,
	mcaRecordR24LO = 208,
	mcaRecordR24HI = 209,
	mcaRecordR24BG = 210,
	mcaRecordR24IP = 211,
	mcaRecordR25LO = 212,
	mcaRecordR25HI = 213,
	mcaRecordR25BG = 214,
	mcaRecordR25IP = 215,
	mcaRecordR26LO = 216,
	mcaRecordR26HI = 217,
	mcaRecordR26BG = 218,
	mcaRecordR26IP = 219,
	mcaRecordR27LO = 220,
	mcaRecordR27HI = 221,
	mcaRecordR27BG = 222,
	mcaRecordR27IP = 223,
	mcaRecordR28LO = 224,
	mcaRecordR28HI = 225,
	mcaRecordR28BG = 226,
	mcaRecordR28IP = 227,
	mcaRecordR29LO = 228,
	mcaRecordR29HI = 229,
	mcaRecordR29BG = 230,
	mcaRecordR29IP = 231,
	mcaRecordR30LO = 232,
	mcaRecordR30HI = 233,
	mcaRecordR30BG = 234,
	mcaRecordR30IP = 235,
	mcaRecordR31LO = 236,
	mcaRecordR31HI = 237,
	mcaRecordR31BG = 238,
	mcaRecordR31IP = 239,
	mcaRecordR0 = 240,
	mcaRecordR0N = 241,
	mcaRecordR0P = 242,
	mcaRecordR1 = 243,
	mcaRecordR1N = 244,
	mcaRecordR1P = 245,
	mcaRecordR2 = 246,
	mcaRecordR2N = 247,
	mcaRecordR2P = 248,
	mcaRecordR3 = 249,
	mcaRecordR3N = 250,
	mcaRecordR3P = 251,
	mcaRecordR4 = 252,
	mcaRecordR4N = 253,
	mcaRecordR4P = 254,
	mcaRecordR5 = 255,
	mcaRecordR5N = 256,
	mcaRecordR5P = 257,
	mcaRecordR6 = 258,
	mcaRecordR6N = 259,
	mcaRecordR6P = 260,
	mcaRecordR7 = 261,
	mcaRecordR7N = 262,
	mcaRecordR7P = 263,
	mcaRecordR8 = 264,
	mcaRecordR8N = 265,
	mcaRecordR8P = 266,
	mcaRecordR9 = 267,
	mcaRecordR9N = 268,
	mcaRecordR9P = 269,
	mcaRecordR10 = 270,
	mcaRecordR10N = 271,
	mcaRecordR10P = 272,
	mcaRecordR11 = 273,
	mcaRecordR11N = 274,
	mcaRecordR11P = 275,
	mcaRecordR12 = 276,
	mcaRecordR12N = 277,
	mcaRecordR12P = 278,
	mcaRecordR13 = 279,
	mcaRecordR13N = 280,
	mcaRecordR13P = 281,
	mcaRecordR14 = 282,
	mcaRecordR14N = 283,
	mcaRecordR14P = 284,
	mcaRecordR15 = 285,
	mcaRecordR15N = 286,
	mcaRecordR15P = 287,
	mcaRecordR16 = 288,
	mcaRecordR16N = 289,
	mcaRecordR16P = 290,
	mcaRecordR17 = 291,
	mcaRecordR17N = 292,
	mcaRecordR17P = 293,
	mcaRecordR18 = 294,
	mcaRecordR18N = 295,
	mcaRecordR18P = 296,
	mcaRecordR19 = 297,
	mcaRecordR19N = 298,
	mcaRecordR19P = 299,
	mcaRecordR20 = 300,
	mcaRecordR20N = 301,
	mcaRecordR20P = 302,
	mcaRecordR21 = 303,
	mcaRecordR21N = 304,
	mcaRecordR21P = 305,
	mcaRecordR22 = 306,
	mcaRecordR22N = 307,
	mcaRecordR22P = 308,
	mcaRecordR23 = 309,
	mcaRecordR23N = 310,
	mcaRecordR23P = 311,
	mcaRecordR24 = 312,
	mcaRecordR24N = 313,
	mcaRecordR24P = 314,
	mcaRecordR25 = 315,
	mcaRecordR25N = 316,
	mcaRecordR25P = 317,
	mcaRecordR26 = 318,
	mcaRecordR26N = 319,
	mcaRecordR26P = 320,
	mcaRecordR27 = 321,
	mcaRecordR27N = 322,
	mcaRecordR27P = 323,
	mcaRecordR28 = 324,
	mcaRecordR28N = 325,
	mcaRecordR28P = 326,
	mcaRecordR29 = 327,
	mcaRecordR29N = 328,
	mcaRecordR29P = 329,
	mcaRecordR30 = 330,
	mcaRecordR30N = 331,
	mcaRecordR30P = 332,
	mcaRecordR31 = 333,
	mcaRecordR31N = 334,
	mcaRecordR31P = 335,
	mcaRecordR0NM = 336,
	mcaRecordR1NM = 337,
	mcaRecordR2NM = 338,
	mcaRecordR3NM = 339,
	mcaRecordR4NM = 340,
	mcaRecordR5NM = 341,
	mcaRecordR6NM = 342,
	mcaRecordR7NM = 343,
	mcaRecordR8NM = 344,
	mcaRecordR9NM = 345,
	mcaRecordR10NM = 346,
	mcaRecordR11NM = 347,
	mcaRecordR12NM = 348,
	mcaRecordR13NM = 349,
	mcaRecordR14NM = 350,
	mcaRecordR15NM = 351,
	mcaRecordR16NM = 352,
	mcaRecordR17NM = 353,
	mcaRecordR18NM = 354,
	mcaRecordR19NM = 355,
	mcaRecordR20NM = 356,
	mcaRecordR21NM = 357,
	mcaRecordR22NM = 358,
	mcaRecordR23NM = 359,
	mcaRecordR24NM = 360,
	mcaRecordR25NM = 361,
	mcaRecordR26NM = 362,
	mcaRecordR27NM = 363,
	mcaRecordR28NM = 364,
	mcaRecordR29NM = 365,
	mcaRecordR30NM = 366,
	mcaRecordR31NM = 367
} mcaFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int mcaRecordSizeOffset(dbRecordType *prt)
{
    mcaRecord *prec = 0;

    if (prt->no_fields != 368) {
        cantProceed("IOC build or installation error:\n"
            "    The mcaRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 368.\n",
            prt->no_fields);
    }
    prt->papFldDes[mcaRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[mcaRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[mcaRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[mcaRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[mcaRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[mcaRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[mcaRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[mcaRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[mcaRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[mcaRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[mcaRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[mcaRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[mcaRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[mcaRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[mcaRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[mcaRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[mcaRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[mcaRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[mcaRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[mcaRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[mcaRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[mcaRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[mcaRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[mcaRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[mcaRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[mcaRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[mcaRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[mcaRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[mcaRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[mcaRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[mcaRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[mcaRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[mcaRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[mcaRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[mcaRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[mcaRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[mcaRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[mcaRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[mcaRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[mcaRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[mcaRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[mcaRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[mcaRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[mcaRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[mcaRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[mcaRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[mcaRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[mcaRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[mcaRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[mcaRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[mcaRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[mcaRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[mcaRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[mcaRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[mcaRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[mcaRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[mcaRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[mcaRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[mcaRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[mcaRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[mcaRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[mcaRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[mcaRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[mcaRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[mcaRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[mcaRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[mcaRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[mcaRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[mcaRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[mcaRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[mcaRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[mcaRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[mcaRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[mcaRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[mcaRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[mcaRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[mcaRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[mcaRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[mcaRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[mcaRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[mcaRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[mcaRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[mcaRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[mcaRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[mcaRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[mcaRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[mcaRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[mcaRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[mcaRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[mcaRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[mcaRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[mcaRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[mcaRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[mcaRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[mcaRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[mcaRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[mcaRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[mcaRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[mcaRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[mcaRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[mcaRecordBPTR]->size = sizeof(prec->bptr);
    prt->papFldDes[mcaRecordBPTR]->offset = (unsigned short)((char *)&prec->bptr - (char *)prec);
    prt->papFldDes[mcaRecordBG]->size = sizeof(prec->bg);
    prt->papFldDes[mcaRecordBG]->offset = (unsigned short)((char *)&prec->bg - (char *)prec);
    prt->papFldDes[mcaRecordPBG]->size = sizeof(prec->pbg);
    prt->papFldDes[mcaRecordPBG]->offset = (unsigned short)((char *)&prec->pbg - (char *)prec);
    prt->papFldDes[mcaRecordPSTATUS]->size = sizeof(prec->pstatus);
    prt->papFldDes[mcaRecordPSTATUS]->offset = (unsigned short)((char *)&prec->pstatus - (char *)prec);
    prt->papFldDes[mcaRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[mcaRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[mcaRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[mcaRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[mcaRecordNMAX]->size = sizeof(prec->nmax);
    prt->papFldDes[mcaRecordNMAX]->offset = (unsigned short)((char *)&prec->nmax - (char *)prec);
    prt->papFldDes[mcaRecordNORD]->size = sizeof(prec->nord);
    prt->papFldDes[mcaRecordNORD]->offset = (unsigned short)((char *)&prec->nord - (char *)prec);
    prt->papFldDes[mcaRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[mcaRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[mcaRecordFTVL]->size = sizeof(prec->ftvl);
    prt->papFldDes[mcaRecordFTVL]->offset = (unsigned short)((char *)&prec->ftvl - (char *)prec);
    prt->papFldDes[mcaRecordSTRT]->size = sizeof(prec->strt);
    prt->papFldDes[mcaRecordSTRT]->offset = (unsigned short)((char *)&prec->strt - (char *)prec);
    prt->papFldDes[mcaRecordERST]->size = sizeof(prec->erst);
    prt->papFldDes[mcaRecordERST]->offset = (unsigned short)((char *)&prec->erst - (char *)prec);
    prt->papFldDes[mcaRecordSTOP]->size = sizeof(prec->stop);
    prt->papFldDes[mcaRecordSTOP]->offset = (unsigned short)((char *)&prec->stop - (char *)prec);
    prt->papFldDes[mcaRecordACQG]->size = sizeof(prec->acqg);
    prt->papFldDes[mcaRecordACQG]->offset = (unsigned short)((char *)&prec->acqg - (char *)prec);
    prt->papFldDes[mcaRecordREAD]->size = sizeof(prec->read);
    prt->papFldDes[mcaRecordREAD]->offset = (unsigned short)((char *)&prec->read - (char *)prec);
    prt->papFldDes[mcaRecordRDNG]->size = sizeof(prec->rdng);
    prt->papFldDes[mcaRecordRDNG]->offset = (unsigned short)((char *)&prec->rdng - (char *)prec);
    prt->papFldDes[mcaRecordRDNS]->size = sizeof(prec->rdns);
    prt->papFldDes[mcaRecordRDNS]->offset = (unsigned short)((char *)&prec->rdns - (char *)prec);
    prt->papFldDes[mcaRecordERAS]->size = sizeof(prec->eras);
    prt->papFldDes[mcaRecordERAS]->offset = (unsigned short)((char *)&prec->eras - (char *)prec);
    prt->papFldDes[mcaRecordCHAS]->size = sizeof(prec->chas);
    prt->papFldDes[mcaRecordCHAS]->offset = (unsigned short)((char *)&prec->chas - (char *)prec);
    prt->papFldDes[mcaRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[mcaRecordNUSE]->offset = (unsigned short)((char *)&prec->nuse - (char *)prec);
    prt->papFldDes[mcaRecordSEQ]->size = sizeof(prec->seq);
    prt->papFldDes[mcaRecordSEQ]->offset = (unsigned short)((char *)&prec->seq - (char *)prec);
    prt->papFldDes[mcaRecordDWEL]->size = sizeof(prec->dwel);
    prt->papFldDes[mcaRecordDWEL]->offset = (unsigned short)((char *)&prec->dwel - (char *)prec);
    prt->papFldDes[mcaRecordPSCL]->size = sizeof(prec->pscl);
    prt->papFldDes[mcaRecordPSCL]->offset = (unsigned short)((char *)&prec->pscl - (char *)prec);
    prt->papFldDes[mcaRecordPRTM]->size = sizeof(prec->prtm);
    prt->papFldDes[mcaRecordPRTM]->offset = (unsigned short)((char *)&prec->prtm - (char *)prec);
    prt->papFldDes[mcaRecordPLTM]->size = sizeof(prec->pltm);
    prt->papFldDes[mcaRecordPLTM]->offset = (unsigned short)((char *)&prec->pltm - (char *)prec);
    prt->papFldDes[mcaRecordPCT]->size = sizeof(prec->pct);
    prt->papFldDes[mcaRecordPCT]->offset = (unsigned short)((char *)&prec->pct - (char *)prec);
    prt->papFldDes[mcaRecordPCTL]->size = sizeof(prec->pctl);
    prt->papFldDes[mcaRecordPCTL]->offset = (unsigned short)((char *)&prec->pctl - (char *)prec);
    prt->papFldDes[mcaRecordPCTH]->size = sizeof(prec->pcth);
    prt->papFldDes[mcaRecordPCTH]->offset = (unsigned short)((char *)&prec->pcth - (char *)prec);
    prt->papFldDes[mcaRecordPSWP]->size = sizeof(prec->pswp);
    prt->papFldDes[mcaRecordPSWP]->offset = (unsigned short)((char *)&prec->pswp - (char *)prec);
    prt->papFldDes[mcaRecordMODE]->size = sizeof(prec->mode);
    prt->papFldDes[mcaRecordMODE]->offset = (unsigned short)((char *)&prec->mode - (char *)prec);
    prt->papFldDes[mcaRecordCALO]->size = sizeof(prec->calo);
    prt->papFldDes[mcaRecordCALO]->offset = (unsigned short)((char *)&prec->calo - (char *)prec);
    prt->papFldDes[mcaRecordCALS]->size = sizeof(prec->cals);
    prt->papFldDes[mcaRecordCALS]->offset = (unsigned short)((char *)&prec->cals - (char *)prec);
    prt->papFldDes[mcaRecordCALQ]->size = sizeof(prec->calq);
    prt->papFldDes[mcaRecordCALQ]->offset = (unsigned short)((char *)&prec->calq - (char *)prec);
    prt->papFldDes[mcaRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[mcaRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[mcaRecordTTH]->size = sizeof(prec->tth);
    prt->papFldDes[mcaRecordTTH]->offset = (unsigned short)((char *)&prec->tth - (char *)prec);
    prt->papFldDes[mcaRecordERTM]->size = sizeof(prec->ertm);
    prt->papFldDes[mcaRecordERTM]->offset = (unsigned short)((char *)&prec->ertm - (char *)prec);
    prt->papFldDes[mcaRecordELTM]->size = sizeof(prec->eltm);
    prt->papFldDes[mcaRecordELTM]->offset = (unsigned short)((char *)&prec->eltm - (char *)prec);
    prt->papFldDes[mcaRecordDTIM]->size = sizeof(prec->dtim);
    prt->papFldDes[mcaRecordDTIM]->offset = (unsigned short)((char *)&prec->dtim - (char *)prec);
    prt->papFldDes[mcaRecordIDTIM]->size = sizeof(prec->idtim);
    prt->papFldDes[mcaRecordIDTIM]->offset = (unsigned short)((char *)&prec->idtim - (char *)prec);
    prt->papFldDes[mcaRecordSTIM]->size = sizeof(prec->stim);
    prt->papFldDes[mcaRecordSTIM]->offset = (unsigned short)((char *)&prec->stim - (char *)prec);
    prt->papFldDes[mcaRecordRTIM]->size = sizeof(prec->rtim);
    prt->papFldDes[mcaRecordRTIM]->offset = (unsigned short)((char *)&prec->rtim - (char *)prec);
    prt->papFldDes[mcaRecordACT]->size = sizeof(prec->act);
    prt->papFldDes[mcaRecordACT]->offset = (unsigned short)((char *)&prec->act - (char *)prec);
    prt->papFldDes[mcaRecordNACK]->size = sizeof(prec->nack);
    prt->papFldDes[mcaRecordNACK]->offset = (unsigned short)((char *)&prec->nack - (char *)prec);
    prt->papFldDes[mcaRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[mcaRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[mcaRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[mcaRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[mcaRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[mcaRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[mcaRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[mcaRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[mcaRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[mcaRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[mcaRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[mcaRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[mcaRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[mcaRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[mcaRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[mcaRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[mcaRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[mcaRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[mcaRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[mcaRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[mcaRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[mcaRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[mcaRecordSIOL]->size = sizeof(prec->siol);
    prt->papFldDes[mcaRecordSIOL]->offset = (unsigned short)((char *)&prec->siol - (char *)prec);
    prt->papFldDes[mcaRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[mcaRecordSIML]->offset = (unsigned short)((char *)&prec->siml - (char *)prec);
    prt->papFldDes[mcaRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[mcaRecordSIMM]->offset = (unsigned short)((char *)&prec->simm - (char *)prec);
    prt->papFldDes[mcaRecordSIMS]->size = sizeof(prec->sims);
    prt->papFldDes[mcaRecordSIMS]->offset = (unsigned short)((char *)&prec->sims - (char *)prec);
    prt->papFldDes[mcaRecordMMAP]->size = sizeof(prec->mmap);
    prt->papFldDes[mcaRecordMMAP]->offset = (unsigned short)((char *)&prec->mmap - (char *)prec);
    prt->papFldDes[mcaRecordRMAP]->size = sizeof(prec->rmap);
    prt->papFldDes[mcaRecordRMAP]->offset = (unsigned short)((char *)&prec->rmap - (char *)prec);
    prt->papFldDes[mcaRecordNEWV]->size = sizeof(prec->newv);
    prt->papFldDes[mcaRecordNEWV]->offset = (unsigned short)((char *)&prec->newv - (char *)prec);
    prt->papFldDes[mcaRecordNEWR]->size = sizeof(prec->newr);
    prt->papFldDes[mcaRecordNEWR]->offset = (unsigned short)((char *)&prec->newr - (char *)prec);
    prt->papFldDes[mcaRecordR0LO]->size = sizeof(prec->r0lo);
    prt->papFldDes[mcaRecordR0LO]->offset = (unsigned short)((char *)&prec->r0lo - (char *)prec);
    prt->papFldDes[mcaRecordR0HI]->size = sizeof(prec->r0hi);
    prt->papFldDes[mcaRecordR0HI]->offset = (unsigned short)((char *)&prec->r0hi - (char *)prec);
    prt->papFldDes[mcaRecordR0BG]->size = sizeof(prec->r0bg);
    prt->papFldDes[mcaRecordR0BG]->offset = (unsigned short)((char *)&prec->r0bg - (char *)prec);
    prt->papFldDes[mcaRecordR0IP]->size = sizeof(prec->r0ip);
    prt->papFldDes[mcaRecordR0IP]->offset = (unsigned short)((char *)&prec->r0ip - (char *)prec);
    prt->papFldDes[mcaRecordR1LO]->size = sizeof(prec->r1lo);
    prt->papFldDes[mcaRecordR1LO]->offset = (unsigned short)((char *)&prec->r1lo - (char *)prec);
    prt->papFldDes[mcaRecordR1HI]->size = sizeof(prec->r1hi);
    prt->papFldDes[mcaRecordR1HI]->offset = (unsigned short)((char *)&prec->r1hi - (char *)prec);
    prt->papFldDes[mcaRecordR1BG]->size = sizeof(prec->r1bg);
    prt->papFldDes[mcaRecordR1BG]->offset = (unsigned short)((char *)&prec->r1bg - (char *)prec);
    prt->papFldDes[mcaRecordR1IP]->size = sizeof(prec->r1ip);
    prt->papFldDes[mcaRecordR1IP]->offset = (unsigned short)((char *)&prec->r1ip - (char *)prec);
    prt->papFldDes[mcaRecordR2LO]->size = sizeof(prec->r2lo);
    prt->papFldDes[mcaRecordR2LO]->offset = (unsigned short)((char *)&prec->r2lo - (char *)prec);
    prt->papFldDes[mcaRecordR2HI]->size = sizeof(prec->r2hi);
    prt->papFldDes[mcaRecordR2HI]->offset = (unsigned short)((char *)&prec->r2hi - (char *)prec);
    prt->papFldDes[mcaRecordR2BG]->size = sizeof(prec->r2bg);
    prt->papFldDes[mcaRecordR2BG]->offset = (unsigned short)((char *)&prec->r2bg - (char *)prec);
    prt->papFldDes[mcaRecordR2IP]->size = sizeof(prec->r2ip);
    prt->papFldDes[mcaRecordR2IP]->offset = (unsigned short)((char *)&prec->r2ip - (char *)prec);
    prt->papFldDes[mcaRecordR3LO]->size = sizeof(prec->r3lo);
    prt->papFldDes[mcaRecordR3LO]->offset = (unsigned short)((char *)&prec->r3lo - (char *)prec);
    prt->papFldDes[mcaRecordR3HI]->size = sizeof(prec->r3hi);
    prt->papFldDes[mcaRecordR3HI]->offset = (unsigned short)((char *)&prec->r3hi - (char *)prec);
    prt->papFldDes[mcaRecordR3BG]->size = sizeof(prec->r3bg);
    prt->papFldDes[mcaRecordR3BG]->offset = (unsigned short)((char *)&prec->r3bg - (char *)prec);
    prt->papFldDes[mcaRecordR3IP]->size = sizeof(prec->r3ip);
    prt->papFldDes[mcaRecordR3IP]->offset = (unsigned short)((char *)&prec->r3ip - (char *)prec);
    prt->papFldDes[mcaRecordR4LO]->size = sizeof(prec->r4lo);
    prt->papFldDes[mcaRecordR4LO]->offset = (unsigned short)((char *)&prec->r4lo - (char *)prec);
    prt->papFldDes[mcaRecordR4HI]->size = sizeof(prec->r4hi);
    prt->papFldDes[mcaRecordR4HI]->offset = (unsigned short)((char *)&prec->r4hi - (char *)prec);
    prt->papFldDes[mcaRecordR4BG]->size = sizeof(prec->r4bg);
    prt->papFldDes[mcaRecordR4BG]->offset = (unsigned short)((char *)&prec->r4bg - (char *)prec);
    prt->papFldDes[mcaRecordR4IP]->size = sizeof(prec->r4ip);
    prt->papFldDes[mcaRecordR4IP]->offset = (unsigned short)((char *)&prec->r4ip - (char *)prec);
    prt->papFldDes[mcaRecordR5LO]->size = sizeof(prec->r5lo);
    prt->papFldDes[mcaRecordR5LO]->offset = (unsigned short)((char *)&prec->r5lo - (char *)prec);
    prt->papFldDes[mcaRecordR5HI]->size = sizeof(prec->r5hi);
    prt->papFldDes[mcaRecordR5HI]->offset = (unsigned short)((char *)&prec->r5hi - (char *)prec);
    prt->papFldDes[mcaRecordR5BG]->size = sizeof(prec->r5bg);
    prt->papFldDes[mcaRecordR5BG]->offset = (unsigned short)((char *)&prec->r5bg - (char *)prec);
    prt->papFldDes[mcaRecordR5IP]->size = sizeof(prec->r5ip);
    prt->papFldDes[mcaRecordR5IP]->offset = (unsigned short)((char *)&prec->r5ip - (char *)prec);
    prt->papFldDes[mcaRecordR6LO]->size = sizeof(prec->r6lo);
    prt->papFldDes[mcaRecordR6LO]->offset = (unsigned short)((char *)&prec->r6lo - (char *)prec);
    prt->papFldDes[mcaRecordR6HI]->size = sizeof(prec->r6hi);
    prt->papFldDes[mcaRecordR6HI]->offset = (unsigned short)((char *)&prec->r6hi - (char *)prec);
    prt->papFldDes[mcaRecordR6BG]->size = sizeof(prec->r6bg);
    prt->papFldDes[mcaRecordR6BG]->offset = (unsigned short)((char *)&prec->r6bg - (char *)prec);
    prt->papFldDes[mcaRecordR6IP]->size = sizeof(prec->r6ip);
    prt->papFldDes[mcaRecordR6IP]->offset = (unsigned short)((char *)&prec->r6ip - (char *)prec);
    prt->papFldDes[mcaRecordR7LO]->size = sizeof(prec->r7lo);
    prt->papFldDes[mcaRecordR7LO]->offset = (unsigned short)((char *)&prec->r7lo - (char *)prec);
    prt->papFldDes[mcaRecordR7HI]->size = sizeof(prec->r7hi);
    prt->papFldDes[mcaRecordR7HI]->offset = (unsigned short)((char *)&prec->r7hi - (char *)prec);
    prt->papFldDes[mcaRecordR7BG]->size = sizeof(prec->r7bg);
    prt->papFldDes[mcaRecordR7BG]->offset = (unsigned short)((char *)&prec->r7bg - (char *)prec);
    prt->papFldDes[mcaRecordR7IP]->size = sizeof(prec->r7ip);
    prt->papFldDes[mcaRecordR7IP]->offset = (unsigned short)((char *)&prec->r7ip - (char *)prec);
    prt->papFldDes[mcaRecordR8LO]->size = sizeof(prec->r8lo);
    prt->papFldDes[mcaRecordR8LO]->offset = (unsigned short)((char *)&prec->r8lo - (char *)prec);
    prt->papFldDes[mcaRecordR8HI]->size = sizeof(prec->r8hi);
    prt->papFldDes[mcaRecordR8HI]->offset = (unsigned short)((char *)&prec->r8hi - (char *)prec);
    prt->papFldDes[mcaRecordR8BG]->size = sizeof(prec->r8bg);
    prt->papFldDes[mcaRecordR8BG]->offset = (unsigned short)((char *)&prec->r8bg - (char *)prec);
    prt->papFldDes[mcaRecordR8IP]->size = sizeof(prec->r8ip);
    prt->papFldDes[mcaRecordR8IP]->offset = (unsigned short)((char *)&prec->r8ip - (char *)prec);
    prt->papFldDes[mcaRecordR9LO]->size = sizeof(prec->r9lo);
    prt->papFldDes[mcaRecordR9LO]->offset = (unsigned short)((char *)&prec->r9lo - (char *)prec);
    prt->papFldDes[mcaRecordR9HI]->size = sizeof(prec->r9hi);
    prt->papFldDes[mcaRecordR9HI]->offset = (unsigned short)((char *)&prec->r9hi - (char *)prec);
    prt->papFldDes[mcaRecordR9BG]->size = sizeof(prec->r9bg);
    prt->papFldDes[mcaRecordR9BG]->offset = (unsigned short)((char *)&prec->r9bg - (char *)prec);
    prt->papFldDes[mcaRecordR9IP]->size = sizeof(prec->r9ip);
    prt->papFldDes[mcaRecordR9IP]->offset = (unsigned short)((char *)&prec->r9ip - (char *)prec);
    prt->papFldDes[mcaRecordR10LO]->size = sizeof(prec->r10lo);
    prt->papFldDes[mcaRecordR10LO]->offset = (unsigned short)((char *)&prec->r10lo - (char *)prec);
    prt->papFldDes[mcaRecordR10HI]->size = sizeof(prec->r10hi);
    prt->papFldDes[mcaRecordR10HI]->offset = (unsigned short)((char *)&prec->r10hi - (char *)prec);
    prt->papFldDes[mcaRecordR10BG]->size = sizeof(prec->r10bg);
    prt->papFldDes[mcaRecordR10BG]->offset = (unsigned short)((char *)&prec->r10bg - (char *)prec);
    prt->papFldDes[mcaRecordR10IP]->size = sizeof(prec->r10ip);
    prt->papFldDes[mcaRecordR10IP]->offset = (unsigned short)((char *)&prec->r10ip - (char *)prec);
    prt->papFldDes[mcaRecordR11LO]->size = sizeof(prec->r11lo);
    prt->papFldDes[mcaRecordR11LO]->offset = (unsigned short)((char *)&prec->r11lo - (char *)prec);
    prt->papFldDes[mcaRecordR11HI]->size = sizeof(prec->r11hi);
    prt->papFldDes[mcaRecordR11HI]->offset = (unsigned short)((char *)&prec->r11hi - (char *)prec);
    prt->papFldDes[mcaRecordR11BG]->size = sizeof(prec->r11bg);
    prt->papFldDes[mcaRecordR11BG]->offset = (unsigned short)((char *)&prec->r11bg - (char *)prec);
    prt->papFldDes[mcaRecordR11IP]->size = sizeof(prec->r11ip);
    prt->papFldDes[mcaRecordR11IP]->offset = (unsigned short)((char *)&prec->r11ip - (char *)prec);
    prt->papFldDes[mcaRecordR12LO]->size = sizeof(prec->r12lo);
    prt->papFldDes[mcaRecordR12LO]->offset = (unsigned short)((char *)&prec->r12lo - (char *)prec);
    prt->papFldDes[mcaRecordR12HI]->size = sizeof(prec->r12hi);
    prt->papFldDes[mcaRecordR12HI]->offset = (unsigned short)((char *)&prec->r12hi - (char *)prec);
    prt->papFldDes[mcaRecordR12BG]->size = sizeof(prec->r12bg);
    prt->papFldDes[mcaRecordR12BG]->offset = (unsigned short)((char *)&prec->r12bg - (char *)prec);
    prt->papFldDes[mcaRecordR12IP]->size = sizeof(prec->r12ip);
    prt->papFldDes[mcaRecordR12IP]->offset = (unsigned short)((char *)&prec->r12ip - (char *)prec);
    prt->papFldDes[mcaRecordR13LO]->size = sizeof(prec->r13lo);
    prt->papFldDes[mcaRecordR13LO]->offset = (unsigned short)((char *)&prec->r13lo - (char *)prec);
    prt->papFldDes[mcaRecordR13HI]->size = sizeof(prec->r13hi);
    prt->papFldDes[mcaRecordR13HI]->offset = (unsigned short)((char *)&prec->r13hi - (char *)prec);
    prt->papFldDes[mcaRecordR13BG]->size = sizeof(prec->r13bg);
    prt->papFldDes[mcaRecordR13BG]->offset = (unsigned short)((char *)&prec->r13bg - (char *)prec);
    prt->papFldDes[mcaRecordR13IP]->size = sizeof(prec->r13ip);
    prt->papFldDes[mcaRecordR13IP]->offset = (unsigned short)((char *)&prec->r13ip - (char *)prec);
    prt->papFldDes[mcaRecordR14LO]->size = sizeof(prec->r14lo);
    prt->papFldDes[mcaRecordR14LO]->offset = (unsigned short)((char *)&prec->r14lo - (char *)prec);
    prt->papFldDes[mcaRecordR14HI]->size = sizeof(prec->r14hi);
    prt->papFldDes[mcaRecordR14HI]->offset = (unsigned short)((char *)&prec->r14hi - (char *)prec);
    prt->papFldDes[mcaRecordR14BG]->size = sizeof(prec->r14bg);
    prt->papFldDes[mcaRecordR14BG]->offset = (unsigned short)((char *)&prec->r14bg - (char *)prec);
    prt->papFldDes[mcaRecordR14IP]->size = sizeof(prec->r14ip);
    prt->papFldDes[mcaRecordR14IP]->offset = (unsigned short)((char *)&prec->r14ip - (char *)prec);
    prt->papFldDes[mcaRecordR15LO]->size = sizeof(prec->r15lo);
    prt->papFldDes[mcaRecordR15LO]->offset = (unsigned short)((char *)&prec->r15lo - (char *)prec);
    prt->papFldDes[mcaRecordR15HI]->size = sizeof(prec->r15hi);
    prt->papFldDes[mcaRecordR15HI]->offset = (unsigned short)((char *)&prec->r15hi - (char *)prec);
    prt->papFldDes[mcaRecordR15BG]->size = sizeof(prec->r15bg);
    prt->papFldDes[mcaRecordR15BG]->offset = (unsigned short)((char *)&prec->r15bg - (char *)prec);
    prt->papFldDes[mcaRecordR15IP]->size = sizeof(prec->r15ip);
    prt->papFldDes[mcaRecordR15IP]->offset = (unsigned short)((char *)&prec->r15ip - (char *)prec);
    prt->papFldDes[mcaRecordR16LO]->size = sizeof(prec->r16lo);
    prt->papFldDes[mcaRecordR16LO]->offset = (unsigned short)((char *)&prec->r16lo - (char *)prec);
    prt->papFldDes[mcaRecordR16HI]->size = sizeof(prec->r16hi);
    prt->papFldDes[mcaRecordR16HI]->offset = (unsigned short)((char *)&prec->r16hi - (char *)prec);
    prt->papFldDes[mcaRecordR16BG]->size = sizeof(prec->r16bg);
    prt->papFldDes[mcaRecordR16BG]->offset = (unsigned short)((char *)&prec->r16bg - (char *)prec);
    prt->papFldDes[mcaRecordR16IP]->size = sizeof(prec->r16ip);
    prt->papFldDes[mcaRecordR16IP]->offset = (unsigned short)((char *)&prec->r16ip - (char *)prec);
    prt->papFldDes[mcaRecordR17LO]->size = sizeof(prec->r17lo);
    prt->papFldDes[mcaRecordR17LO]->offset = (unsigned short)((char *)&prec->r17lo - (char *)prec);
    prt->papFldDes[mcaRecordR17HI]->size = sizeof(prec->r17hi);
    prt->papFldDes[mcaRecordR17HI]->offset = (unsigned short)((char *)&prec->r17hi - (char *)prec);
    prt->papFldDes[mcaRecordR17BG]->size = sizeof(prec->r17bg);
    prt->papFldDes[mcaRecordR17BG]->offset = (unsigned short)((char *)&prec->r17bg - (char *)prec);
    prt->papFldDes[mcaRecordR17IP]->size = sizeof(prec->r17ip);
    prt->papFldDes[mcaRecordR17IP]->offset = (unsigned short)((char *)&prec->r17ip - (char *)prec);
    prt->papFldDes[mcaRecordR18LO]->size = sizeof(prec->r18lo);
    prt->papFldDes[mcaRecordR18LO]->offset = (unsigned short)((char *)&prec->r18lo - (char *)prec);
    prt->papFldDes[mcaRecordR18HI]->size = sizeof(prec->r18hi);
    prt->papFldDes[mcaRecordR18HI]->offset = (unsigned short)((char *)&prec->r18hi - (char *)prec);
    prt->papFldDes[mcaRecordR18BG]->size = sizeof(prec->r18bg);
    prt->papFldDes[mcaRecordR18BG]->offset = (unsigned short)((char *)&prec->r18bg - (char *)prec);
    prt->papFldDes[mcaRecordR18IP]->size = sizeof(prec->r18ip);
    prt->papFldDes[mcaRecordR18IP]->offset = (unsigned short)((char *)&prec->r18ip - (char *)prec);
    prt->papFldDes[mcaRecordR19LO]->size = sizeof(prec->r19lo);
    prt->papFldDes[mcaRecordR19LO]->offset = (unsigned short)((char *)&prec->r19lo - (char *)prec);
    prt->papFldDes[mcaRecordR19HI]->size = sizeof(prec->r19hi);
    prt->papFldDes[mcaRecordR19HI]->offset = (unsigned short)((char *)&prec->r19hi - (char *)prec);
    prt->papFldDes[mcaRecordR19BG]->size = sizeof(prec->r19bg);
    prt->papFldDes[mcaRecordR19BG]->offset = (unsigned short)((char *)&prec->r19bg - (char *)prec);
    prt->papFldDes[mcaRecordR19IP]->size = sizeof(prec->r19ip);
    prt->papFldDes[mcaRecordR19IP]->offset = (unsigned short)((char *)&prec->r19ip - (char *)prec);
    prt->papFldDes[mcaRecordR20LO]->size = sizeof(prec->r20lo);
    prt->papFldDes[mcaRecordR20LO]->offset = (unsigned short)((char *)&prec->r20lo - (char *)prec);
    prt->papFldDes[mcaRecordR20HI]->size = sizeof(prec->r20hi);
    prt->papFldDes[mcaRecordR20HI]->offset = (unsigned short)((char *)&prec->r20hi - (char *)prec);
    prt->papFldDes[mcaRecordR20BG]->size = sizeof(prec->r20bg);
    prt->papFldDes[mcaRecordR20BG]->offset = (unsigned short)((char *)&prec->r20bg - (char *)prec);
    prt->papFldDes[mcaRecordR20IP]->size = sizeof(prec->r20ip);
    prt->papFldDes[mcaRecordR20IP]->offset = (unsigned short)((char *)&prec->r20ip - (char *)prec);
    prt->papFldDes[mcaRecordR21LO]->size = sizeof(prec->r21lo);
    prt->papFldDes[mcaRecordR21LO]->offset = (unsigned short)((char *)&prec->r21lo - (char *)prec);
    prt->papFldDes[mcaRecordR21HI]->size = sizeof(prec->r21hi);
    prt->papFldDes[mcaRecordR21HI]->offset = (unsigned short)((char *)&prec->r21hi - (char *)prec);
    prt->papFldDes[mcaRecordR21BG]->size = sizeof(prec->r21bg);
    prt->papFldDes[mcaRecordR21BG]->offset = (unsigned short)((char *)&prec->r21bg - (char *)prec);
    prt->papFldDes[mcaRecordR21IP]->size = sizeof(prec->r21ip);
    prt->papFldDes[mcaRecordR21IP]->offset = (unsigned short)((char *)&prec->r21ip - (char *)prec);
    prt->papFldDes[mcaRecordR22LO]->size = sizeof(prec->r22lo);
    prt->papFldDes[mcaRecordR22LO]->offset = (unsigned short)((char *)&prec->r22lo - (char *)prec);
    prt->papFldDes[mcaRecordR22HI]->size = sizeof(prec->r22hi);
    prt->papFldDes[mcaRecordR22HI]->offset = (unsigned short)((char *)&prec->r22hi - (char *)prec);
    prt->papFldDes[mcaRecordR22BG]->size = sizeof(prec->r22bg);
    prt->papFldDes[mcaRecordR22BG]->offset = (unsigned short)((char *)&prec->r22bg - (char *)prec);
    prt->papFldDes[mcaRecordR22IP]->size = sizeof(prec->r22ip);
    prt->papFldDes[mcaRecordR22IP]->offset = (unsigned short)((char *)&prec->r22ip - (char *)prec);
    prt->papFldDes[mcaRecordR23LO]->size = sizeof(prec->r23lo);
    prt->papFldDes[mcaRecordR23LO]->offset = (unsigned short)((char *)&prec->r23lo - (char *)prec);
    prt->papFldDes[mcaRecordR23HI]->size = sizeof(prec->r23hi);
    prt->papFldDes[mcaRecordR23HI]->offset = (unsigned short)((char *)&prec->r23hi - (char *)prec);
    prt->papFldDes[mcaRecordR23BG]->size = sizeof(prec->r23bg);
    prt->papFldDes[mcaRecordR23BG]->offset = (unsigned short)((char *)&prec->r23bg - (char *)prec);
    prt->papFldDes[mcaRecordR23IP]->size = sizeof(prec->r23ip);
    prt->papFldDes[mcaRecordR23IP]->offset = (unsigned short)((char *)&prec->r23ip - (char *)prec);
    prt->papFldDes[mcaRecordR24LO]->size = sizeof(prec->r24lo);
    prt->papFldDes[mcaRecordR24LO]->offset = (unsigned short)((char *)&prec->r24lo - (char *)prec);
    prt->papFldDes[mcaRecordR24HI]->size = sizeof(prec->r24hi);
    prt->papFldDes[mcaRecordR24HI]->offset = (unsigned short)((char *)&prec->r24hi - (char *)prec);
    prt->papFldDes[mcaRecordR24BG]->size = sizeof(prec->r24bg);
    prt->papFldDes[mcaRecordR24BG]->offset = (unsigned short)((char *)&prec->r24bg - (char *)prec);
    prt->papFldDes[mcaRecordR24IP]->size = sizeof(prec->r24ip);
    prt->papFldDes[mcaRecordR24IP]->offset = (unsigned short)((char *)&prec->r24ip - (char *)prec);
    prt->papFldDes[mcaRecordR25LO]->size = sizeof(prec->r25lo);
    prt->papFldDes[mcaRecordR25LO]->offset = (unsigned short)((char *)&prec->r25lo - (char *)prec);
    prt->papFldDes[mcaRecordR25HI]->size = sizeof(prec->r25hi);
    prt->papFldDes[mcaRecordR25HI]->offset = (unsigned short)((char *)&prec->r25hi - (char *)prec);
    prt->papFldDes[mcaRecordR25BG]->size = sizeof(prec->r25bg);
    prt->papFldDes[mcaRecordR25BG]->offset = (unsigned short)((char *)&prec->r25bg - (char *)prec);
    prt->papFldDes[mcaRecordR25IP]->size = sizeof(prec->r25ip);
    prt->papFldDes[mcaRecordR25IP]->offset = (unsigned short)((char *)&prec->r25ip - (char *)prec);
    prt->papFldDes[mcaRecordR26LO]->size = sizeof(prec->r26lo);
    prt->papFldDes[mcaRecordR26LO]->offset = (unsigned short)((char *)&prec->r26lo - (char *)prec);
    prt->papFldDes[mcaRecordR26HI]->size = sizeof(prec->r26hi);
    prt->papFldDes[mcaRecordR26HI]->offset = (unsigned short)((char *)&prec->r26hi - (char *)prec);
    prt->papFldDes[mcaRecordR26BG]->size = sizeof(prec->r26bg);
    prt->papFldDes[mcaRecordR26BG]->offset = (unsigned short)((char *)&prec->r26bg - (char *)prec);
    prt->papFldDes[mcaRecordR26IP]->size = sizeof(prec->r26ip);
    prt->papFldDes[mcaRecordR26IP]->offset = (unsigned short)((char *)&prec->r26ip - (char *)prec);
    prt->papFldDes[mcaRecordR27LO]->size = sizeof(prec->r27lo);
    prt->papFldDes[mcaRecordR27LO]->offset = (unsigned short)((char *)&prec->r27lo - (char *)prec);
    prt->papFldDes[mcaRecordR27HI]->size = sizeof(prec->r27hi);
    prt->papFldDes[mcaRecordR27HI]->offset = (unsigned short)((char *)&prec->r27hi - (char *)prec);
    prt->papFldDes[mcaRecordR27BG]->size = sizeof(prec->r27bg);
    prt->papFldDes[mcaRecordR27BG]->offset = (unsigned short)((char *)&prec->r27bg - (char *)prec);
    prt->papFldDes[mcaRecordR27IP]->size = sizeof(prec->r27ip);
    prt->papFldDes[mcaRecordR27IP]->offset = (unsigned short)((char *)&prec->r27ip - (char *)prec);
    prt->papFldDes[mcaRecordR28LO]->size = sizeof(prec->r28lo);
    prt->papFldDes[mcaRecordR28LO]->offset = (unsigned short)((char *)&prec->r28lo - (char *)prec);
    prt->papFldDes[mcaRecordR28HI]->size = sizeof(prec->r28hi);
    prt->papFldDes[mcaRecordR28HI]->offset = (unsigned short)((char *)&prec->r28hi - (char *)prec);
    prt->papFldDes[mcaRecordR28BG]->size = sizeof(prec->r28bg);
    prt->papFldDes[mcaRecordR28BG]->offset = (unsigned short)((char *)&prec->r28bg - (char *)prec);
    prt->papFldDes[mcaRecordR28IP]->size = sizeof(prec->r28ip);
    prt->papFldDes[mcaRecordR28IP]->offset = (unsigned short)((char *)&prec->r28ip - (char *)prec);
    prt->papFldDes[mcaRecordR29LO]->size = sizeof(prec->r29lo);
    prt->papFldDes[mcaRecordR29LO]->offset = (unsigned short)((char *)&prec->r29lo - (char *)prec);
    prt->papFldDes[mcaRecordR29HI]->size = sizeof(prec->r29hi);
    prt->papFldDes[mcaRecordR29HI]->offset = (unsigned short)((char *)&prec->r29hi - (char *)prec);
    prt->papFldDes[mcaRecordR29BG]->size = sizeof(prec->r29bg);
    prt->papFldDes[mcaRecordR29BG]->offset = (unsigned short)((char *)&prec->r29bg - (char *)prec);
    prt->papFldDes[mcaRecordR29IP]->size = sizeof(prec->r29ip);
    prt->papFldDes[mcaRecordR29IP]->offset = (unsigned short)((char *)&prec->r29ip - (char *)prec);
    prt->papFldDes[mcaRecordR30LO]->size = sizeof(prec->r30lo);
    prt->papFldDes[mcaRecordR30LO]->offset = (unsigned short)((char *)&prec->r30lo - (char *)prec);
    prt->papFldDes[mcaRecordR30HI]->size = sizeof(prec->r30hi);
    prt->papFldDes[mcaRecordR30HI]->offset = (unsigned short)((char *)&prec->r30hi - (char *)prec);
    prt->papFldDes[mcaRecordR30BG]->size = sizeof(prec->r30bg);
    prt->papFldDes[mcaRecordR30BG]->offset = (unsigned short)((char *)&prec->r30bg - (char *)prec);
    prt->papFldDes[mcaRecordR30IP]->size = sizeof(prec->r30ip);
    prt->papFldDes[mcaRecordR30IP]->offset = (unsigned short)((char *)&prec->r30ip - (char *)prec);
    prt->papFldDes[mcaRecordR31LO]->size = sizeof(prec->r31lo);
    prt->papFldDes[mcaRecordR31LO]->offset = (unsigned short)((char *)&prec->r31lo - (char *)prec);
    prt->papFldDes[mcaRecordR31HI]->size = sizeof(prec->r31hi);
    prt->papFldDes[mcaRecordR31HI]->offset = (unsigned short)((char *)&prec->r31hi - (char *)prec);
    prt->papFldDes[mcaRecordR31BG]->size = sizeof(prec->r31bg);
    prt->papFldDes[mcaRecordR31BG]->offset = (unsigned short)((char *)&prec->r31bg - (char *)prec);
    prt->papFldDes[mcaRecordR31IP]->size = sizeof(prec->r31ip);
    prt->papFldDes[mcaRecordR31IP]->offset = (unsigned short)((char *)&prec->r31ip - (char *)prec);
    prt->papFldDes[mcaRecordR0]->size = sizeof(prec->r0);
    prt->papFldDes[mcaRecordR0]->offset = (unsigned short)((char *)&prec->r0 - (char *)prec);
    prt->papFldDes[mcaRecordR0N]->size = sizeof(prec->r0n);
    prt->papFldDes[mcaRecordR0N]->offset = (unsigned short)((char *)&prec->r0n - (char *)prec);
    prt->papFldDes[mcaRecordR0P]->size = sizeof(prec->r0p);
    prt->papFldDes[mcaRecordR0P]->offset = (unsigned short)((char *)&prec->r0p - (char *)prec);
    prt->papFldDes[mcaRecordR1]->size = sizeof(prec->r1);
    prt->papFldDes[mcaRecordR1]->offset = (unsigned short)((char *)&prec->r1 - (char *)prec);
    prt->papFldDes[mcaRecordR1N]->size = sizeof(prec->r1n);
    prt->papFldDes[mcaRecordR1N]->offset = (unsigned short)((char *)&prec->r1n - (char *)prec);
    prt->papFldDes[mcaRecordR1P]->size = sizeof(prec->r1p);
    prt->papFldDes[mcaRecordR1P]->offset = (unsigned short)((char *)&prec->r1p - (char *)prec);
    prt->papFldDes[mcaRecordR2]->size = sizeof(prec->r2);
    prt->papFldDes[mcaRecordR2]->offset = (unsigned short)((char *)&prec->r2 - (char *)prec);
    prt->papFldDes[mcaRecordR2N]->size = sizeof(prec->r2n);
    prt->papFldDes[mcaRecordR2N]->offset = (unsigned short)((char *)&prec->r2n - (char *)prec);
    prt->papFldDes[mcaRecordR2P]->size = sizeof(prec->r2p);
    prt->papFldDes[mcaRecordR2P]->offset = (unsigned short)((char *)&prec->r2p - (char *)prec);
    prt->papFldDes[mcaRecordR3]->size = sizeof(prec->r3);
    prt->papFldDes[mcaRecordR3]->offset = (unsigned short)((char *)&prec->r3 - (char *)prec);
    prt->papFldDes[mcaRecordR3N]->size = sizeof(prec->r3n);
    prt->papFldDes[mcaRecordR3N]->offset = (unsigned short)((char *)&prec->r3n - (char *)prec);
    prt->papFldDes[mcaRecordR3P]->size = sizeof(prec->r3p);
    prt->papFldDes[mcaRecordR3P]->offset = (unsigned short)((char *)&prec->r3p - (char *)prec);
    prt->papFldDes[mcaRecordR4]->size = sizeof(prec->r4);
    prt->papFldDes[mcaRecordR4]->offset = (unsigned short)((char *)&prec->r4 - (char *)prec);
    prt->papFldDes[mcaRecordR4N]->size = sizeof(prec->r4n);
    prt->papFldDes[mcaRecordR4N]->offset = (unsigned short)((char *)&prec->r4n - (char *)prec);
    prt->papFldDes[mcaRecordR4P]->size = sizeof(prec->r4p);
    prt->papFldDes[mcaRecordR4P]->offset = (unsigned short)((char *)&prec->r4p - (char *)prec);
    prt->papFldDes[mcaRecordR5]->size = sizeof(prec->r5);
    prt->papFldDes[mcaRecordR5]->offset = (unsigned short)((char *)&prec->r5 - (char *)prec);
    prt->papFldDes[mcaRecordR5N]->size = sizeof(prec->r5n);
    prt->papFldDes[mcaRecordR5N]->offset = (unsigned short)((char *)&prec->r5n - (char *)prec);
    prt->papFldDes[mcaRecordR5P]->size = sizeof(prec->r5p);
    prt->papFldDes[mcaRecordR5P]->offset = (unsigned short)((char *)&prec->r5p - (char *)prec);
    prt->papFldDes[mcaRecordR6]->size = sizeof(prec->r6);
    prt->papFldDes[mcaRecordR6]->offset = (unsigned short)((char *)&prec->r6 - (char *)prec);
    prt->papFldDes[mcaRecordR6N]->size = sizeof(prec->r6n);
    prt->papFldDes[mcaRecordR6N]->offset = (unsigned short)((char *)&prec->r6n - (char *)prec);
    prt->papFldDes[mcaRecordR6P]->size = sizeof(prec->r6p);
    prt->papFldDes[mcaRecordR6P]->offset = (unsigned short)((char *)&prec->r6p - (char *)prec);
    prt->papFldDes[mcaRecordR7]->size = sizeof(prec->r7);
    prt->papFldDes[mcaRecordR7]->offset = (unsigned short)((char *)&prec->r7 - (char *)prec);
    prt->papFldDes[mcaRecordR7N]->size = sizeof(prec->r7n);
    prt->papFldDes[mcaRecordR7N]->offset = (unsigned short)((char *)&prec->r7n - (char *)prec);
    prt->papFldDes[mcaRecordR7P]->size = sizeof(prec->r7p);
    prt->papFldDes[mcaRecordR7P]->offset = (unsigned short)((char *)&prec->r7p - (char *)prec);
    prt->papFldDes[mcaRecordR8]->size = sizeof(prec->r8);
    prt->papFldDes[mcaRecordR8]->offset = (unsigned short)((char *)&prec->r8 - (char *)prec);
    prt->papFldDes[mcaRecordR8N]->size = sizeof(prec->r8n);
    prt->papFldDes[mcaRecordR8N]->offset = (unsigned short)((char *)&prec->r8n - (char *)prec);
    prt->papFldDes[mcaRecordR8P]->size = sizeof(prec->r8p);
    prt->papFldDes[mcaRecordR8P]->offset = (unsigned short)((char *)&prec->r8p - (char *)prec);
    prt->papFldDes[mcaRecordR9]->size = sizeof(prec->r9);
    prt->papFldDes[mcaRecordR9]->offset = (unsigned short)((char *)&prec->r9 - (char *)prec);
    prt->papFldDes[mcaRecordR9N]->size = sizeof(prec->r9n);
    prt->papFldDes[mcaRecordR9N]->offset = (unsigned short)((char *)&prec->r9n - (char *)prec);
    prt->papFldDes[mcaRecordR9P]->size = sizeof(prec->r9p);
    prt->papFldDes[mcaRecordR9P]->offset = (unsigned short)((char *)&prec->r9p - (char *)prec);
    prt->papFldDes[mcaRecordR10]->size = sizeof(prec->r10);
    prt->papFldDes[mcaRecordR10]->offset = (unsigned short)((char *)&prec->r10 - (char *)prec);
    prt->papFldDes[mcaRecordR10N]->size = sizeof(prec->r10n);
    prt->papFldDes[mcaRecordR10N]->offset = (unsigned short)((char *)&prec->r10n - (char *)prec);
    prt->papFldDes[mcaRecordR10P]->size = sizeof(prec->r10p);
    prt->papFldDes[mcaRecordR10P]->offset = (unsigned short)((char *)&prec->r10p - (char *)prec);
    prt->papFldDes[mcaRecordR11]->size = sizeof(prec->r11);
    prt->papFldDes[mcaRecordR11]->offset = (unsigned short)((char *)&prec->r11 - (char *)prec);
    prt->papFldDes[mcaRecordR11N]->size = sizeof(prec->r11n);
    prt->papFldDes[mcaRecordR11N]->offset = (unsigned short)((char *)&prec->r11n - (char *)prec);
    prt->papFldDes[mcaRecordR11P]->size = sizeof(prec->r11p);
    prt->papFldDes[mcaRecordR11P]->offset = (unsigned short)((char *)&prec->r11p - (char *)prec);
    prt->papFldDes[mcaRecordR12]->size = sizeof(prec->r12);
    prt->papFldDes[mcaRecordR12]->offset = (unsigned short)((char *)&prec->r12 - (char *)prec);
    prt->papFldDes[mcaRecordR12N]->size = sizeof(prec->r12n);
    prt->papFldDes[mcaRecordR12N]->offset = (unsigned short)((char *)&prec->r12n - (char *)prec);
    prt->papFldDes[mcaRecordR12P]->size = sizeof(prec->r12p);
    prt->papFldDes[mcaRecordR12P]->offset = (unsigned short)((char *)&prec->r12p - (char *)prec);
    prt->papFldDes[mcaRecordR13]->size = sizeof(prec->r13);
    prt->papFldDes[mcaRecordR13]->offset = (unsigned short)((char *)&prec->r13 - (char *)prec);
    prt->papFldDes[mcaRecordR13N]->size = sizeof(prec->r13n);
    prt->papFldDes[mcaRecordR13N]->offset = (unsigned short)((char *)&prec->r13n - (char *)prec);
    prt->papFldDes[mcaRecordR13P]->size = sizeof(prec->r13p);
    prt->papFldDes[mcaRecordR13P]->offset = (unsigned short)((char *)&prec->r13p - (char *)prec);
    prt->papFldDes[mcaRecordR14]->size = sizeof(prec->r14);
    prt->papFldDes[mcaRecordR14]->offset = (unsigned short)((char *)&prec->r14 - (char *)prec);
    prt->papFldDes[mcaRecordR14N]->size = sizeof(prec->r14n);
    prt->papFldDes[mcaRecordR14N]->offset = (unsigned short)((char *)&prec->r14n - (char *)prec);
    prt->papFldDes[mcaRecordR14P]->size = sizeof(prec->r14p);
    prt->papFldDes[mcaRecordR14P]->offset = (unsigned short)((char *)&prec->r14p - (char *)prec);
    prt->papFldDes[mcaRecordR15]->size = sizeof(prec->r15);
    prt->papFldDes[mcaRecordR15]->offset = (unsigned short)((char *)&prec->r15 - (char *)prec);
    prt->papFldDes[mcaRecordR15N]->size = sizeof(prec->r15n);
    prt->papFldDes[mcaRecordR15N]->offset = (unsigned short)((char *)&prec->r15n - (char *)prec);
    prt->papFldDes[mcaRecordR15P]->size = sizeof(prec->r15p);
    prt->papFldDes[mcaRecordR15P]->offset = (unsigned short)((char *)&prec->r15p - (char *)prec);
    prt->papFldDes[mcaRecordR16]->size = sizeof(prec->r16);
    prt->papFldDes[mcaRecordR16]->offset = (unsigned short)((char *)&prec->r16 - (char *)prec);
    prt->papFldDes[mcaRecordR16N]->size = sizeof(prec->r16n);
    prt->papFldDes[mcaRecordR16N]->offset = (unsigned short)((char *)&prec->r16n - (char *)prec);
    prt->papFldDes[mcaRecordR16P]->size = sizeof(prec->r16p);
    prt->papFldDes[mcaRecordR16P]->offset = (unsigned short)((char *)&prec->r16p - (char *)prec);
    prt->papFldDes[mcaRecordR17]->size = sizeof(prec->r17);
    prt->papFldDes[mcaRecordR17]->offset = (unsigned short)((char *)&prec->r17 - (char *)prec);
    prt->papFldDes[mcaRecordR17N]->size = sizeof(prec->r17n);
    prt->papFldDes[mcaRecordR17N]->offset = (unsigned short)((char *)&prec->r17n - (char *)prec);
    prt->papFldDes[mcaRecordR17P]->size = sizeof(prec->r17p);
    prt->papFldDes[mcaRecordR17P]->offset = (unsigned short)((char *)&prec->r17p - (char *)prec);
    prt->papFldDes[mcaRecordR18]->size = sizeof(prec->r18);
    prt->papFldDes[mcaRecordR18]->offset = (unsigned short)((char *)&prec->r18 - (char *)prec);
    prt->papFldDes[mcaRecordR18N]->size = sizeof(prec->r18n);
    prt->papFldDes[mcaRecordR18N]->offset = (unsigned short)((char *)&prec->r18n - (char *)prec);
    prt->papFldDes[mcaRecordR18P]->size = sizeof(prec->r18p);
    prt->papFldDes[mcaRecordR18P]->offset = (unsigned short)((char *)&prec->r18p - (char *)prec);
    prt->papFldDes[mcaRecordR19]->size = sizeof(prec->r19);
    prt->papFldDes[mcaRecordR19]->offset = (unsigned short)((char *)&prec->r19 - (char *)prec);
    prt->papFldDes[mcaRecordR19N]->size = sizeof(prec->r19n);
    prt->papFldDes[mcaRecordR19N]->offset = (unsigned short)((char *)&prec->r19n - (char *)prec);
    prt->papFldDes[mcaRecordR19P]->size = sizeof(prec->r19p);
    prt->papFldDes[mcaRecordR19P]->offset = (unsigned short)((char *)&prec->r19p - (char *)prec);
    prt->papFldDes[mcaRecordR20]->size = sizeof(prec->r20);
    prt->papFldDes[mcaRecordR20]->offset = (unsigned short)((char *)&prec->r20 - (char *)prec);
    prt->papFldDes[mcaRecordR20N]->size = sizeof(prec->r20n);
    prt->papFldDes[mcaRecordR20N]->offset = (unsigned short)((char *)&prec->r20n - (char *)prec);
    prt->papFldDes[mcaRecordR20P]->size = sizeof(prec->r20p);
    prt->papFldDes[mcaRecordR20P]->offset = (unsigned short)((char *)&prec->r20p - (char *)prec);
    prt->papFldDes[mcaRecordR21]->size = sizeof(prec->r21);
    prt->papFldDes[mcaRecordR21]->offset = (unsigned short)((char *)&prec->r21 - (char *)prec);
    prt->papFldDes[mcaRecordR21N]->size = sizeof(prec->r21n);
    prt->papFldDes[mcaRecordR21N]->offset = (unsigned short)((char *)&prec->r21n - (char *)prec);
    prt->papFldDes[mcaRecordR21P]->size = sizeof(prec->r21p);
    prt->papFldDes[mcaRecordR21P]->offset = (unsigned short)((char *)&prec->r21p - (char *)prec);
    prt->papFldDes[mcaRecordR22]->size = sizeof(prec->r22);
    prt->papFldDes[mcaRecordR22]->offset = (unsigned short)((char *)&prec->r22 - (char *)prec);
    prt->papFldDes[mcaRecordR22N]->size = sizeof(prec->r22n);
    prt->papFldDes[mcaRecordR22N]->offset = (unsigned short)((char *)&prec->r22n - (char *)prec);
    prt->papFldDes[mcaRecordR22P]->size = sizeof(prec->r22p);
    prt->papFldDes[mcaRecordR22P]->offset = (unsigned short)((char *)&prec->r22p - (char *)prec);
    prt->papFldDes[mcaRecordR23]->size = sizeof(prec->r23);
    prt->papFldDes[mcaRecordR23]->offset = (unsigned short)((char *)&prec->r23 - (char *)prec);
    prt->papFldDes[mcaRecordR23N]->size = sizeof(prec->r23n);
    prt->papFldDes[mcaRecordR23N]->offset = (unsigned short)((char *)&prec->r23n - (char *)prec);
    prt->papFldDes[mcaRecordR23P]->size = sizeof(prec->r23p);
    prt->papFldDes[mcaRecordR23P]->offset = (unsigned short)((char *)&prec->r23p - (char *)prec);
    prt->papFldDes[mcaRecordR24]->size = sizeof(prec->r24);
    prt->papFldDes[mcaRecordR24]->offset = (unsigned short)((char *)&prec->r24 - (char *)prec);
    prt->papFldDes[mcaRecordR24N]->size = sizeof(prec->r24n);
    prt->papFldDes[mcaRecordR24N]->offset = (unsigned short)((char *)&prec->r24n - (char *)prec);
    prt->papFldDes[mcaRecordR24P]->size = sizeof(prec->r24p);
    prt->papFldDes[mcaRecordR24P]->offset = (unsigned short)((char *)&prec->r24p - (char *)prec);
    prt->papFldDes[mcaRecordR25]->size = sizeof(prec->r25);
    prt->papFldDes[mcaRecordR25]->offset = (unsigned short)((char *)&prec->r25 - (char *)prec);
    prt->papFldDes[mcaRecordR25N]->size = sizeof(prec->r25n);
    prt->papFldDes[mcaRecordR25N]->offset = (unsigned short)((char *)&prec->r25n - (char *)prec);
    prt->papFldDes[mcaRecordR25P]->size = sizeof(prec->r25p);
    prt->papFldDes[mcaRecordR25P]->offset = (unsigned short)((char *)&prec->r25p - (char *)prec);
    prt->papFldDes[mcaRecordR26]->size = sizeof(prec->r26);
    prt->papFldDes[mcaRecordR26]->offset = (unsigned short)((char *)&prec->r26 - (char *)prec);
    prt->papFldDes[mcaRecordR26N]->size = sizeof(prec->r26n);
    prt->papFldDes[mcaRecordR26N]->offset = (unsigned short)((char *)&prec->r26n - (char *)prec);
    prt->papFldDes[mcaRecordR26P]->size = sizeof(prec->r26p);
    prt->papFldDes[mcaRecordR26P]->offset = (unsigned short)((char *)&prec->r26p - (char *)prec);
    prt->papFldDes[mcaRecordR27]->size = sizeof(prec->r27);
    prt->papFldDes[mcaRecordR27]->offset = (unsigned short)((char *)&prec->r27 - (char *)prec);
    prt->papFldDes[mcaRecordR27N]->size = sizeof(prec->r27n);
    prt->papFldDes[mcaRecordR27N]->offset = (unsigned short)((char *)&prec->r27n - (char *)prec);
    prt->papFldDes[mcaRecordR27P]->size = sizeof(prec->r27p);
    prt->papFldDes[mcaRecordR27P]->offset = (unsigned short)((char *)&prec->r27p - (char *)prec);
    prt->papFldDes[mcaRecordR28]->size = sizeof(prec->r28);
    prt->papFldDes[mcaRecordR28]->offset = (unsigned short)((char *)&prec->r28 - (char *)prec);
    prt->papFldDes[mcaRecordR28N]->size = sizeof(prec->r28n);
    prt->papFldDes[mcaRecordR28N]->offset = (unsigned short)((char *)&prec->r28n - (char *)prec);
    prt->papFldDes[mcaRecordR28P]->size = sizeof(prec->r28p);
    prt->papFldDes[mcaRecordR28P]->offset = (unsigned short)((char *)&prec->r28p - (char *)prec);
    prt->papFldDes[mcaRecordR29]->size = sizeof(prec->r29);
    prt->papFldDes[mcaRecordR29]->offset = (unsigned short)((char *)&prec->r29 - (char *)prec);
    prt->papFldDes[mcaRecordR29N]->size = sizeof(prec->r29n);
    prt->papFldDes[mcaRecordR29N]->offset = (unsigned short)((char *)&prec->r29n - (char *)prec);
    prt->papFldDes[mcaRecordR29P]->size = sizeof(prec->r29p);
    prt->papFldDes[mcaRecordR29P]->offset = (unsigned short)((char *)&prec->r29p - (char *)prec);
    prt->papFldDes[mcaRecordR30]->size = sizeof(prec->r30);
    prt->papFldDes[mcaRecordR30]->offset = (unsigned short)((char *)&prec->r30 - (char *)prec);
    prt->papFldDes[mcaRecordR30N]->size = sizeof(prec->r30n);
    prt->papFldDes[mcaRecordR30N]->offset = (unsigned short)((char *)&prec->r30n - (char *)prec);
    prt->papFldDes[mcaRecordR30P]->size = sizeof(prec->r30p);
    prt->papFldDes[mcaRecordR30P]->offset = (unsigned short)((char *)&prec->r30p - (char *)prec);
    prt->papFldDes[mcaRecordR31]->size = sizeof(prec->r31);
    prt->papFldDes[mcaRecordR31]->offset = (unsigned short)((char *)&prec->r31 - (char *)prec);
    prt->papFldDes[mcaRecordR31N]->size = sizeof(prec->r31n);
    prt->papFldDes[mcaRecordR31N]->offset = (unsigned short)((char *)&prec->r31n - (char *)prec);
    prt->papFldDes[mcaRecordR31P]->size = sizeof(prec->r31p);
    prt->papFldDes[mcaRecordR31P]->offset = (unsigned short)((char *)&prec->r31p - (char *)prec);
    prt->papFldDes[mcaRecordR0NM]->size = sizeof(prec->r0nm);
    prt->papFldDes[mcaRecordR0NM]->offset = (unsigned short)((char *)&prec->r0nm - (char *)prec);
    prt->papFldDes[mcaRecordR1NM]->size = sizeof(prec->r1nm);
    prt->papFldDes[mcaRecordR1NM]->offset = (unsigned short)((char *)&prec->r1nm - (char *)prec);
    prt->papFldDes[mcaRecordR2NM]->size = sizeof(prec->r2nm);
    prt->papFldDes[mcaRecordR2NM]->offset = (unsigned short)((char *)&prec->r2nm - (char *)prec);
    prt->papFldDes[mcaRecordR3NM]->size = sizeof(prec->r3nm);
    prt->papFldDes[mcaRecordR3NM]->offset = (unsigned short)((char *)&prec->r3nm - (char *)prec);
    prt->papFldDes[mcaRecordR4NM]->size = sizeof(prec->r4nm);
    prt->papFldDes[mcaRecordR4NM]->offset = (unsigned short)((char *)&prec->r4nm - (char *)prec);
    prt->papFldDes[mcaRecordR5NM]->size = sizeof(prec->r5nm);
    prt->papFldDes[mcaRecordR5NM]->offset = (unsigned short)((char *)&prec->r5nm - (char *)prec);
    prt->papFldDes[mcaRecordR6NM]->size = sizeof(prec->r6nm);
    prt->papFldDes[mcaRecordR6NM]->offset = (unsigned short)((char *)&prec->r6nm - (char *)prec);
    prt->papFldDes[mcaRecordR7NM]->size = sizeof(prec->r7nm);
    prt->papFldDes[mcaRecordR7NM]->offset = (unsigned short)((char *)&prec->r7nm - (char *)prec);
    prt->papFldDes[mcaRecordR8NM]->size = sizeof(prec->r8nm);
    prt->papFldDes[mcaRecordR8NM]->offset = (unsigned short)((char *)&prec->r8nm - (char *)prec);
    prt->papFldDes[mcaRecordR9NM]->size = sizeof(prec->r9nm);
    prt->papFldDes[mcaRecordR9NM]->offset = (unsigned short)((char *)&prec->r9nm - (char *)prec);
    prt->papFldDes[mcaRecordR10NM]->size = sizeof(prec->r10nm);
    prt->papFldDes[mcaRecordR10NM]->offset = (unsigned short)((char *)&prec->r10nm - (char *)prec);
    prt->papFldDes[mcaRecordR11NM]->size = sizeof(prec->r11nm);
    prt->papFldDes[mcaRecordR11NM]->offset = (unsigned short)((char *)&prec->r11nm - (char *)prec);
    prt->papFldDes[mcaRecordR12NM]->size = sizeof(prec->r12nm);
    prt->papFldDes[mcaRecordR12NM]->offset = (unsigned short)((char *)&prec->r12nm - (char *)prec);
    prt->papFldDes[mcaRecordR13NM]->size = sizeof(prec->r13nm);
    prt->papFldDes[mcaRecordR13NM]->offset = (unsigned short)((char *)&prec->r13nm - (char *)prec);
    prt->papFldDes[mcaRecordR14NM]->size = sizeof(prec->r14nm);
    prt->papFldDes[mcaRecordR14NM]->offset = (unsigned short)((char *)&prec->r14nm - (char *)prec);
    prt->papFldDes[mcaRecordR15NM]->size = sizeof(prec->r15nm);
    prt->papFldDes[mcaRecordR15NM]->offset = (unsigned short)((char *)&prec->r15nm - (char *)prec);
    prt->papFldDes[mcaRecordR16NM]->size = sizeof(prec->r16nm);
    prt->papFldDes[mcaRecordR16NM]->offset = (unsigned short)((char *)&prec->r16nm - (char *)prec);
    prt->papFldDes[mcaRecordR17NM]->size = sizeof(prec->r17nm);
    prt->papFldDes[mcaRecordR17NM]->offset = (unsigned short)((char *)&prec->r17nm - (char *)prec);
    prt->papFldDes[mcaRecordR18NM]->size = sizeof(prec->r18nm);
    prt->papFldDes[mcaRecordR18NM]->offset = (unsigned short)((char *)&prec->r18nm - (char *)prec);
    prt->papFldDes[mcaRecordR19NM]->size = sizeof(prec->r19nm);
    prt->papFldDes[mcaRecordR19NM]->offset = (unsigned short)((char *)&prec->r19nm - (char *)prec);
    prt->papFldDes[mcaRecordR20NM]->size = sizeof(prec->r20nm);
    prt->papFldDes[mcaRecordR20NM]->offset = (unsigned short)((char *)&prec->r20nm - (char *)prec);
    prt->papFldDes[mcaRecordR21NM]->size = sizeof(prec->r21nm);
    prt->papFldDes[mcaRecordR21NM]->offset = (unsigned short)((char *)&prec->r21nm - (char *)prec);
    prt->papFldDes[mcaRecordR22NM]->size = sizeof(prec->r22nm);
    prt->papFldDes[mcaRecordR22NM]->offset = (unsigned short)((char *)&prec->r22nm - (char *)prec);
    prt->papFldDes[mcaRecordR23NM]->size = sizeof(prec->r23nm);
    prt->papFldDes[mcaRecordR23NM]->offset = (unsigned short)((char *)&prec->r23nm - (char *)prec);
    prt->papFldDes[mcaRecordR24NM]->size = sizeof(prec->r24nm);
    prt->papFldDes[mcaRecordR24NM]->offset = (unsigned short)((char *)&prec->r24nm - (char *)prec);
    prt->papFldDes[mcaRecordR25NM]->size = sizeof(prec->r25nm);
    prt->papFldDes[mcaRecordR25NM]->offset = (unsigned short)((char *)&prec->r25nm - (char *)prec);
    prt->papFldDes[mcaRecordR26NM]->size = sizeof(prec->r26nm);
    prt->papFldDes[mcaRecordR26NM]->offset = (unsigned short)((char *)&prec->r26nm - (char *)prec);
    prt->papFldDes[mcaRecordR27NM]->size = sizeof(prec->r27nm);
    prt->papFldDes[mcaRecordR27NM]->offset = (unsigned short)((char *)&prec->r27nm - (char *)prec);
    prt->papFldDes[mcaRecordR28NM]->size = sizeof(prec->r28nm);
    prt->papFldDes[mcaRecordR28NM]->offset = (unsigned short)((char *)&prec->r28nm - (char *)prec);
    prt->papFldDes[mcaRecordR29NM]->size = sizeof(prec->r29nm);
    prt->papFldDes[mcaRecordR29NM]->offset = (unsigned short)((char *)&prec->r29nm - (char *)prec);
    prt->papFldDes[mcaRecordR30NM]->size = sizeof(prec->r30nm);
    prt->papFldDes[mcaRecordR30NM]->offset = (unsigned short)((char *)&prec->r30nm - (char *)prec);
    prt->papFldDes[mcaRecordR31NM]->size = sizeof(prec->r31nm);
    prt->papFldDes[mcaRecordR31NM]->offset = (unsigned short)((char *)&prec->r31nm - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(mcaRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_mcaRecord_H */
