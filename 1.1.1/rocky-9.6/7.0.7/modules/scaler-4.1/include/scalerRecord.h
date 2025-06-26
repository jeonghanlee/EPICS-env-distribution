/** @file scalerRecord.h
 * @brief Declarations for the @ref scalerRecord "scaler" record type.
 *
 * This header was generated from scalerRecord.dbd
 */

#ifndef INC_scalerRecord_H
#define INC_scalerRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

#ifndef scalerCONT_NUM_CHOICES
/** @brief Enumerated type from menu scalerCONT */
typedef enum {
    scalerCONT_OneShot              /**< @brief State string "OneShot" */,
    scalerCONT_AutoCount            /**< @brief State string "AutoCount" */
} scalerCONT;
/** @brief Number of states defined for menu scalerCONT */
#define scalerCONT_NUM_CHOICES 2
#endif

#ifndef scalerG1_NUM_CHOICES
/** @brief Enumerated type from menu scalerG1 */
typedef enum {
    scalerG1_N                      /**< @brief State string "N" */,
    scalerG1_Y                      /**< @brief State string "Y" */
} scalerG1;
/** @brief Number of states defined for menu scalerG1 */
#define scalerG1_NUM_CHOICES 2
#endif

#ifndef scalerD1_NUM_CHOICES
/** @brief Enumerated type from menu scalerD1 */
typedef enum {
    scalerD1_Up                     /**< @brief State string "Up" */,
    scalerD1_Dn                     /**< @brief State string "Dn" */
} scalerD1;
/** @brief Number of states defined for menu scalerD1 */
#define scalerD1_NUM_CHOICES 2
#endif

#ifndef scalerCNT_NUM_CHOICES
/** @brief Enumerated type from menu scalerCNT */
typedef enum {
    scalerCNT_Done                  /**< @brief State string "Done" */,
    scalerCNT_Count                 /**< @brief State string "Count" */
} scalerCNT;
/** @brief Number of states defined for menu scalerCNT */
#define scalerCNT_NUM_CHOICES 2
#endif

/** @brief Declaration of scaler record type. */
typedef struct scalerRecord {
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
    void *rpvt;                     /**< @brief Record Private */
    epicsFloat64        val;        /**< @brief Result */
    epicsFloat64        freq;       /**< @brief Time base freq */
    epicsEnum16         cnt;        /**< @brief Count */
    epicsEnum16         pcnt;       /**< @brief Prev Count */
    epicsInt16          ss;         /**< @brief Scaler state */
    epicsInt16          us;         /**< @brief User state */
    epicsEnum16         cont;       /**< @brief OneShot/AutoCount */
    DBLINK              out;        /**< @brief Output Specification */
    epicsFloat32        rate;       /**< @brief Display Rate (Hz.) */
    epicsFloat32        rat1;       /**< @brief Auto Display Rate (Hz.) */
    epicsFloat32        dly;        /**< @brief Delay */
    epicsFloat32        dly1;       /**< @brief Auto-mode Delay */
    epicsInt16          nch;        /**< @brief Number of Channels */
    epicsEnum16         d1;         /**< @brief Count Direction 1 */
    epicsEnum16         d2;         /**< @brief Count Direction 2 */
    epicsEnum16         d3;         /**< @brief Count Direction 3 */
    epicsEnum16         d4;         /**< @brief Count Direction 4 */
    epicsEnum16         d5;         /**< @brief Count Direction 5 */
    epicsEnum16         d6;         /**< @brief Count Direction 6 */
    epicsEnum16         d7;         /**< @brief Count Direction 7 */
    epicsEnum16         d8;         /**< @brief Count Direction 8 */
    epicsEnum16         d9;         /**< @brief Count Direction 9 */
    epicsEnum16         d10;        /**< @brief Count Direction 10 */
    epicsEnum16         d11;        /**< @brief Count Direction 11 */
    epicsEnum16         d12;        /**< @brief Count Direction 12 */
    epicsEnum16         d13;        /**< @brief Count Direction 13 */
    epicsEnum16         d14;        /**< @brief Count Direction 14 */
    epicsEnum16         d15;        /**< @brief Count Direction 15 */
    epicsEnum16         d16;        /**< @brief Count Direction 16 */
    epicsEnum16         d17;        /**< @brief Count Direction 17 */
    epicsEnum16         d18;        /**< @brief Count Direction 18 */
    epicsEnum16         d19;        /**< @brief Count Direction 19 */
    epicsEnum16         d20;        /**< @brief Count Direction 20 */
    epicsEnum16         d21;        /**< @brief Count Direction 21 */
    epicsEnum16         d22;        /**< @brief Count Direction 22 */
    epicsEnum16         d23;        /**< @brief Count Direction 23 */
    epicsEnum16         d24;        /**< @brief Count Direction 24 */
    epicsEnum16         d25;        /**< @brief Count Direction 25 */
    epicsEnum16         d26;        /**< @brief Count Direction 26 */
    epicsEnum16         d27;        /**< @brief Count Direction 27 */
    epicsEnum16         d28;        /**< @brief Count Direction 28 */
    epicsEnum16         d29;        /**< @brief Count Direction 29 */
    epicsEnum16         d30;        /**< @brief Count Direction 30 */
    epicsEnum16         d31;        /**< @brief Count Direction 31 */
    epicsEnum16         d32;        /**< @brief Count Direction 32 */
    epicsEnum16         d33;        /**< @brief Count Direction 33 */
    epicsEnum16         d34;        /**< @brief Count Direction 34 */
    epicsEnum16         d35;        /**< @brief Count Direction 35 */
    epicsEnum16         d36;        /**< @brief Count Direction 36 */
    epicsEnum16         d37;        /**< @brief Count Direction 37 */
    epicsEnum16         d38;        /**< @brief Count Direction 38 */
    epicsEnum16         d39;        /**< @brief Count Direction 39 */
    epicsEnum16         d40;        /**< @brief Count Direction 40 */
    epicsEnum16         d41;        /**< @brief Count Direction 41 */
    epicsEnum16         d42;        /**< @brief Count Direction 42 */
    epicsEnum16         d43;        /**< @brief Count Direction 43 */
    epicsEnum16         d44;        /**< @brief Count Direction 44 */
    epicsEnum16         d45;        /**< @brief Count Direction 45 */
    epicsEnum16         d46;        /**< @brief Count Direction 46 */
    epicsEnum16         d47;        /**< @brief Count Direction 47 */
    epicsEnum16         d48;        /**< @brief Count Direction 48 */
    epicsEnum16         d49;        /**< @brief Count Direction 49 */
    epicsEnum16         d50;        /**< @brief Count Direction 50 */
    epicsEnum16         d51;        /**< @brief Count Direction 51 */
    epicsEnum16         d52;        /**< @brief Count Direction 52 */
    epicsEnum16         d53;        /**< @brief Count Direction 53 */
    epicsEnum16         d54;        /**< @brief Count Direction 54 */
    epicsEnum16         d55;        /**< @brief Count Direction 55 */
    epicsEnum16         d56;        /**< @brief Count Direction 56 */
    epicsEnum16         d57;        /**< @brief Count Direction 57 */
    epicsEnum16         d58;        /**< @brief Count Direction 58 */
    epicsEnum16         d59;        /**< @brief Count Direction 59 */
    epicsEnum16         d60;        /**< @brief Count Direction 60 */
    epicsEnum16         d61;        /**< @brief Count Direction 61 */
    epicsEnum16         d62;        /**< @brief Count Direction 62 */
    epicsEnum16         d63;        /**< @brief Count Direction 63 */
    epicsEnum16         d64;        /**< @brief Count Direction 64 */
    epicsEnum16         g1;         /**< @brief Gate Control 1 */
    epicsEnum16         g2;         /**< @brief Gate Control 2 */
    epicsEnum16         g3;         /**< @brief Gate Control 3 */
    epicsEnum16         g4;         /**< @brief Gate Control 4 */
    epicsEnum16         g5;         /**< @brief Gate Control 5 */
    epicsEnum16         g6;         /**< @brief Gate Control 6 */
    epicsEnum16         g7;         /**< @brief Gate Control 7 */
    epicsEnum16         g8;         /**< @brief Gate Control 8 */
    epicsEnum16         g9;         /**< @brief Gate Control 9 */
    epicsEnum16         g10;        /**< @brief Gate Control 10 */
    epicsEnum16         g11;        /**< @brief Gate Control 11 */
    epicsEnum16         g12;        /**< @brief Gate Control 12 */
    epicsEnum16         g13;        /**< @brief Gate Control 13 */
    epicsEnum16         g14;        /**< @brief Gate Control 14 */
    epicsEnum16         g15;        /**< @brief Gate Control 15 */
    epicsEnum16         g16;        /**< @brief Gate Control 16 */
    epicsEnum16         g17;        /**< @brief Gate Control 17 */
    epicsEnum16         g18;        /**< @brief Gate Control 18 */
    epicsEnum16         g19;        /**< @brief Gate Control 19 */
    epicsEnum16         g20;        /**< @brief Gate Control 20 */
    epicsEnum16         g21;        /**< @brief Gate Control 21 */
    epicsEnum16         g22;        /**< @brief Gate Control 22 */
    epicsEnum16         g23;        /**< @brief Gate Control 23 */
    epicsEnum16         g24;        /**< @brief Gate Control 24 */
    epicsEnum16         g25;        /**< @brief Gate Control 25 */
    epicsEnum16         g26;        /**< @brief Gate Control 26 */
    epicsEnum16         g27;        /**< @brief Gate Control 27 */
    epicsEnum16         g28;        /**< @brief Gate Control 28 */
    epicsEnum16         g29;        /**< @brief Gate Control 29 */
    epicsEnum16         g30;        /**< @brief Gate Control 30 */
    epicsEnum16         g31;        /**< @brief Gate Control 31 */
    epicsEnum16         g32;        /**< @brief Gate Control 32 */
    epicsEnum16         g33;        /**< @brief Gate Control */
    epicsEnum16         g34;        /**< @brief Gate Control */
    epicsEnum16         g35;        /**< @brief Gate Control */
    epicsEnum16         g36;        /**< @brief Gate Control */
    epicsEnum16         g37;        /**< @brief Gate Control */
    epicsEnum16         g38;        /**< @brief Gate Control */
    epicsEnum16         g39;        /**< @brief Gate Control */
    epicsEnum16         g40;        /**< @brief Gate Control */
    epicsEnum16         g41;        /**< @brief Gate Control */
    epicsEnum16         g42;        /**< @brief Gate Control */
    epicsEnum16         g43;        /**< @brief Gate Control */
    epicsEnum16         g44;        /**< @brief Gate Control */
    epicsEnum16         g45;        /**< @brief Gate Control */
    epicsEnum16         g46;        /**< @brief Gate Control */
    epicsEnum16         g47;        /**< @brief Gate Control */
    epicsEnum16         g48;        /**< @brief Gate Control */
    epicsEnum16         g49;        /**< @brief Gate Control */
    epicsEnum16         g50;        /**< @brief Gate Control */
    epicsEnum16         g51;        /**< @brief Gate Control */
    epicsEnum16         g52;        /**< @brief Gate Control */
    epicsEnum16         g53;        /**< @brief Gate Control */
    epicsEnum16         g54;        /**< @brief Gate Control */
    epicsEnum16         g55;        /**< @brief Gate Control */
    epicsEnum16         g56;        /**< @brief Gate Control */
    epicsEnum16         g57;        /**< @brief Gate Control */
    epicsEnum16         g58;        /**< @brief Gate Control */
    epicsEnum16         g59;        /**< @brief Gate Control */
    epicsEnum16         g60;        /**< @brief Gate Control */
    epicsEnum16         g61;        /**< @brief Gate Control */
    epicsEnum16         g62;        /**< @brief Gate Control */
    epicsEnum16         g63;        /**< @brief Gate Control */
    epicsEnum16         g64;        /**< @brief Gate Control */
    epicsFloat64        tp;         /**< @brief Time Preset */
    epicsFloat64        tp1;        /**< @brief Time Preset */
    epicsUInt32         pr1;        /**< @brief Preset 1 */
    epicsUInt32         pr2;        /**< @brief Preset 2 */
    epicsUInt32         pr3;        /**< @brief Preset 3 */
    epicsUInt32         pr4;        /**< @brief Preset 4 */
    epicsUInt32         pr5;        /**< @brief Preset 5 */
    epicsUInt32         pr6;        /**< @brief Preset 6 */
    epicsUInt32         pr7;        /**< @brief Preset 7 */
    epicsUInt32         pr8;        /**< @brief Preset 8 */
    epicsUInt32         pr9;        /**< @brief Preset 9 */
    epicsUInt32         pr10;       /**< @brief Preset 10 */
    epicsUInt32         pr11;       /**< @brief Preset 11 */
    epicsUInt32         pr12;       /**< @brief Preset 12 */
    epicsUInt32         pr13;       /**< @brief Preset 13 */
    epicsUInt32         pr14;       /**< @brief Preset 14 */
    epicsUInt32         pr15;       /**< @brief Preset 15 */
    epicsUInt32         pr16;       /**< @brief Preset 16 */
    epicsUInt32         pr17;       /**< @brief Preset 17 */
    epicsUInt32         pr18;       /**< @brief Preset 18 */
    epicsUInt32         pr19;       /**< @brief Preset 19 */
    epicsUInt32         pr20;       /**< @brief Preset 20 */
    epicsUInt32         pr21;       /**< @brief Preset 21 */
    epicsUInt32         pr22;       /**< @brief Preset 22 */
    epicsUInt32         pr23;       /**< @brief Preset 23 */
    epicsUInt32         pr24;       /**< @brief Preset 24 */
    epicsUInt32         pr25;       /**< @brief Preset 25 */
    epicsUInt32         pr26;       /**< @brief Preset 26 */
    epicsUInt32         pr27;       /**< @brief Preset 27 */
    epicsUInt32         pr28;       /**< @brief Preset 28 */
    epicsUInt32         pr29;       /**< @brief Preset 29 */
    epicsUInt32         pr30;       /**< @brief Preset 30 */
    epicsUInt32         pr31;       /**< @brief Preset 31 */
    epicsUInt32         pr32;       /**< @brief Preset 32 */
    epicsUInt32         pr33;       /**< @brief Preset */
    epicsUInt32         pr34;       /**< @brief Preset */
    epicsUInt32         pr35;       /**< @brief Preset */
    epicsUInt32         pr36;       /**< @brief Preset */
    epicsUInt32         pr37;       /**< @brief Preset */
    epicsUInt32         pr38;       /**< @brief Preset */
    epicsUInt32         pr39;       /**< @brief Preset */
    epicsUInt32         pr40;       /**< @brief Preset */
    epicsUInt32         pr41;       /**< @brief Preset */
    epicsUInt32         pr42;       /**< @brief Preset */
    epicsUInt32         pr43;       /**< @brief Preset */
    epicsUInt32         pr44;       /**< @brief Preset */
    epicsUInt32         pr45;       /**< @brief Preset */
    epicsUInt32         pr46;       /**< @brief Preset */
    epicsUInt32         pr47;       /**< @brief Preset */
    epicsUInt32         pr48;       /**< @brief Preset */
    epicsUInt32         pr49;       /**< @brief Preset */
    epicsUInt32         pr50;       /**< @brief Preset */
    epicsUInt32         pr51;       /**< @brief Preset */
    epicsUInt32         pr52;       /**< @brief Preset */
    epicsUInt32         pr53;       /**< @brief Preset */
    epicsUInt32         pr54;       /**< @brief Preset */
    epicsUInt32         pr55;       /**< @brief Preset */
    epicsUInt32         pr56;       /**< @brief Preset */
    epicsUInt32         pr57;       /**< @brief Preset */
    epicsUInt32         pr58;       /**< @brief Preset */
    epicsUInt32         pr59;       /**< @brief Preset */
    epicsUInt32         pr60;       /**< @brief Preset */
    epicsUInt32         pr61;       /**< @brief Preset */
    epicsUInt32         pr62;       /**< @brief Preset */
    epicsUInt32         pr63;       /**< @brief Preset */
    epicsUInt32         pr64;       /**< @brief Preset */
    epicsFloat64        t;          /**< @brief Timer */
    epicsUInt32         s1;         /**< @brief Count */
    epicsUInt32         s2;         /**< @brief Count */
    epicsUInt32         s3;         /**< @brief Count */
    epicsUInt32         s4;         /**< @brief Count */
    epicsUInt32         s5;         /**< @brief Count */
    epicsUInt32         s6;         /**< @brief Count */
    epicsUInt32         s7;         /**< @brief Count */
    epicsUInt32         s8;         /**< @brief Count */
    epicsUInt32         s9;         /**< @brief Count */
    epicsUInt32         s10;        /**< @brief Count */
    epicsUInt32         s11;        /**< @brief Count */
    epicsUInt32         s12;        /**< @brief Count */
    epicsUInt32         s13;        /**< @brief Count */
    epicsUInt32         s14;        /**< @brief Count */
    epicsUInt32         s15;        /**< @brief Count */
    epicsUInt32         s16;        /**< @brief Count */
    epicsUInt32         s17;        /**< @brief Count */
    epicsUInt32         s18;        /**< @brief Count */
    epicsUInt32         s19;        /**< @brief Count */
    epicsUInt32         s20;        /**< @brief Count */
    epicsUInt32         s21;        /**< @brief Count */
    epicsUInt32         s22;        /**< @brief Count */
    epicsUInt32         s23;        /**< @brief Count */
    epicsUInt32         s24;        /**< @brief Count */
    epicsUInt32         s25;        /**< @brief Count */
    epicsUInt32         s26;        /**< @brief Count */
    epicsUInt32         s27;        /**< @brief Count */
    epicsUInt32         s28;        /**< @brief Count */
    epicsUInt32         s29;        /**< @brief Count */
    epicsUInt32         s30;        /**< @brief Count */
    epicsUInt32         s31;        /**< @brief Count */
    epicsUInt32         s32;        /**< @brief Count */
    epicsUInt32         s33;        /**< @brief Count */
    epicsUInt32         s34;        /**< @brief Count */
    epicsUInt32         s35;        /**< @brief Count */
    epicsUInt32         s36;        /**< @brief Count */
    epicsUInt32         s37;        /**< @brief Count */
    epicsUInt32         s38;        /**< @brief Count */
    epicsUInt32         s39;        /**< @brief Count */
    epicsUInt32         s40;        /**< @brief Count */
    epicsUInt32         s41;        /**< @brief Count */
    epicsUInt32         s42;        /**< @brief Count */
    epicsUInt32         s43;        /**< @brief Count */
    epicsUInt32         s44;        /**< @brief Count */
    epicsUInt32         s45;        /**< @brief Count */
    epicsUInt32         s46;        /**< @brief Count */
    epicsUInt32         s47;        /**< @brief Count */
    epicsUInt32         s48;        /**< @brief Count */
    epicsUInt32         s49;        /**< @brief Count */
    epicsUInt32         s50;        /**< @brief Count */
    epicsUInt32         s51;        /**< @brief Count */
    epicsUInt32         s52;        /**< @brief Count */
    epicsUInt32         s53;        /**< @brief Count */
    epicsUInt32         s54;        /**< @brief Count */
    epicsUInt32         s55;        /**< @brief Count */
    epicsUInt32         s56;        /**< @brief Count */
    epicsUInt32         s57;        /**< @brief Count */
    epicsUInt32         s58;        /**< @brief Count */
    epicsUInt32         s59;        /**< @brief Count */
    epicsUInt32         s60;        /**< @brief Count */
    epicsUInt32         s61;        /**< @brief Count */
    epicsUInt32         s62;        /**< @brief Count */
    epicsUInt32         s63;        /**< @brief Count */
    epicsUInt32         s64;        /**< @brief Count */
    char                nm1[16];    /**< @brief Scaler 1 name */
    char                nm2[16];    /**< @brief Scaler 2 name */
    char                nm3[16];    /**< @brief Scaler 3 name */
    char                nm4[16];    /**< @brief Scaler 4 name */
    char                nm5[16];    /**< @brief Scaler 5 name */
    char                nm6[16];    /**< @brief Scaler 6 name */
    char                nm7[16];    /**< @brief Scaler 7 name */
    char                nm8[16];    /**< @brief Scaler 8 name */
    char                nm9[16];    /**< @brief Scaler 9 name */
    char                nm10[16];   /**< @brief Scaler 10 name */
    char                nm11[16];   /**< @brief Scaler 11 name */
    char                nm12[16];   /**< @brief Scaler 12 name */
    char                nm13[16];   /**< @brief Scaler 13 name */
    char                nm14[16];   /**< @brief Scaler 14 name */
    char                nm15[16];   /**< @brief Scaler 15 name */
    char                nm16[16];   /**< @brief Scaler 16 name */
    char                nm17[16];   /**< @brief Scaler 17 name */
    char                nm18[16];   /**< @brief Scaler 18 name */
    char                nm19[16];   /**< @brief Scaler 19 name */
    char                nm20[16];   /**< @brief Scaler 20 name */
    char                nm21[16];   /**< @brief Scaler 21 name */
    char                nm22[16];   /**< @brief Scaler 22 name */
    char                nm23[16];   /**< @brief Scaler 23 name */
    char                nm24[16];   /**< @brief Scaler 24 name */
    char                nm25[16];   /**< @brief Scaler 25 name */
    char                nm26[16];   /**< @brief Scaler 26 name */
    char                nm27[16];   /**< @brief Scaler 27 name */
    char                nm28[16];   /**< @brief Scaler 28 name */
    char                nm29[16];   /**< @brief Scaler 29 name */
    char                nm30[16];   /**< @brief Scaler 30 name */
    char                nm31[16];   /**< @brief Scaler 31 name */
    char                nm32[16];   /**< @brief Scaler 32 name */
    char                nm33[16];   /**< @brief Scaler name */
    char                nm34[16];   /**< @brief Scaler name */
    char                nm35[16];   /**< @brief Scaler name */
    char                nm36[16];   /**< @brief Scaler name */
    char                nm37[16];   /**< @brief Scaler name */
    char                nm38[16];   /**< @brief Scaler name */
    char                nm39[16];   /**< @brief Scaler name */
    char                nm40[16];   /**< @brief Scaler name */
    char                nm41[16];   /**< @brief Scaler name */
    char                nm42[16];   /**< @brief Scaler name */
    char                nm43[16];   /**< @brief Scaler name */
    char                nm44[16];   /**< @brief Scaler name */
    char                nm45[16];   /**< @brief Scaler name */
    char                nm46[16];   /**< @brief Scaler name */
    char                nm47[16];   /**< @brief Scaler name */
    char                nm48[16];   /**< @brief Scaler name */
    char                nm49[16];   /**< @brief Scaler name */
    char                nm50[16];   /**< @brief Scaler name */
    char                nm51[16];   /**< @brief Scaler name */
    char                nm52[16];   /**< @brief Scaler name */
    char                nm53[16];   /**< @brief Scaler name */
    char                nm54[16];   /**< @brief Scaler name */
    char                nm55[16];   /**< @brief Scaler name */
    char                nm56[16];   /**< @brief Scaler name */
    char                nm57[16];   /**< @brief Scaler name */
    char                nm58[16];   /**< @brief Scaler name */
    char                nm59[16];   /**< @brief Scaler name */
    char                nm60[16];   /**< @brief Scaler name */
    char                nm61[16];   /**< @brief Scaler name */
    char                nm62[16];   /**< @brief Scaler name */
    char                nm63[16];   /**< @brief Scaler name */
    char                nm64[16];   /**< @brief Scaler name */
    char                egu[16];    /**< @brief Units Name */
    epicsInt16          prec;       /**< @brief Display Precision */
    DBLINK              cout;       /**< @brief CNT Output */
    DBLINK              coutp;      /**< @brief CNT Output Prompt */
} scalerRecord;

typedef enum {
	scalerRecordNAME = 0,
	scalerRecordDESC = 1,
	scalerRecordASG = 2,
	scalerRecordSCAN = 3,
	scalerRecordPINI = 4,
	scalerRecordPHAS = 5,
	scalerRecordEVNT = 6,
	scalerRecordTSE = 7,
	scalerRecordTSEL = 8,
	scalerRecordDTYP = 9,
	scalerRecordDISV = 10,
	scalerRecordDISA = 11,
	scalerRecordSDIS = 12,
	scalerRecordMLOK = 13,
	scalerRecordMLIS = 14,
	scalerRecordBKLNK = 15,
	scalerRecordDISP = 16,
	scalerRecordPROC = 17,
	scalerRecordSTAT = 18,
	scalerRecordSEVR = 19,
	scalerRecordAMSG = 20,
	scalerRecordNSTA = 21,
	scalerRecordNSEV = 22,
	scalerRecordNAMSG = 23,
	scalerRecordACKS = 24,
	scalerRecordACKT = 25,
	scalerRecordDISS = 26,
	scalerRecordLCNT = 27,
	scalerRecordPACT = 28,
	scalerRecordPUTF = 29,
	scalerRecordRPRO = 30,
	scalerRecordASP = 31,
	scalerRecordPPN = 32,
	scalerRecordPPNR = 33,
	scalerRecordSPVT = 34,
	scalerRecordRSET = 35,
	scalerRecordDSET = 36,
	scalerRecordDPVT = 37,
	scalerRecordRDES = 38,
	scalerRecordLSET = 39,
	scalerRecordPRIO = 40,
	scalerRecordTPRO = 41,
	scalerRecordBKPT = 42,
	scalerRecordUDF = 43,
	scalerRecordUDFS = 44,
	scalerRecordTIME = 45,
	scalerRecordUTAG = 46,
	scalerRecordFLNK = 47,
	scalerRecordVERS = 48,
	scalerRecordRPVT = 49,
	scalerRecordVAL = 50,
	scalerRecordFREQ = 51,
	scalerRecordCNT = 52,
	scalerRecordPCNT = 53,
	scalerRecordSS = 54,
	scalerRecordUS = 55,
	scalerRecordCONT = 56,
	scalerRecordOUT = 57,
	scalerRecordRATE = 58,
	scalerRecordRAT1 = 59,
	scalerRecordDLY = 60,
	scalerRecordDLY1 = 61,
	scalerRecordNCH = 62,
	scalerRecordD1 = 63,
	scalerRecordD2 = 64,
	scalerRecordD3 = 65,
	scalerRecordD4 = 66,
	scalerRecordD5 = 67,
	scalerRecordD6 = 68,
	scalerRecordD7 = 69,
	scalerRecordD8 = 70,
	scalerRecordD9 = 71,
	scalerRecordD10 = 72,
	scalerRecordD11 = 73,
	scalerRecordD12 = 74,
	scalerRecordD13 = 75,
	scalerRecordD14 = 76,
	scalerRecordD15 = 77,
	scalerRecordD16 = 78,
	scalerRecordD17 = 79,
	scalerRecordD18 = 80,
	scalerRecordD19 = 81,
	scalerRecordD20 = 82,
	scalerRecordD21 = 83,
	scalerRecordD22 = 84,
	scalerRecordD23 = 85,
	scalerRecordD24 = 86,
	scalerRecordD25 = 87,
	scalerRecordD26 = 88,
	scalerRecordD27 = 89,
	scalerRecordD28 = 90,
	scalerRecordD29 = 91,
	scalerRecordD30 = 92,
	scalerRecordD31 = 93,
	scalerRecordD32 = 94,
	scalerRecordD33 = 95,
	scalerRecordD34 = 96,
	scalerRecordD35 = 97,
	scalerRecordD36 = 98,
	scalerRecordD37 = 99,
	scalerRecordD38 = 100,
	scalerRecordD39 = 101,
	scalerRecordD40 = 102,
	scalerRecordD41 = 103,
	scalerRecordD42 = 104,
	scalerRecordD43 = 105,
	scalerRecordD44 = 106,
	scalerRecordD45 = 107,
	scalerRecordD46 = 108,
	scalerRecordD47 = 109,
	scalerRecordD48 = 110,
	scalerRecordD49 = 111,
	scalerRecordD50 = 112,
	scalerRecordD51 = 113,
	scalerRecordD52 = 114,
	scalerRecordD53 = 115,
	scalerRecordD54 = 116,
	scalerRecordD55 = 117,
	scalerRecordD56 = 118,
	scalerRecordD57 = 119,
	scalerRecordD58 = 120,
	scalerRecordD59 = 121,
	scalerRecordD60 = 122,
	scalerRecordD61 = 123,
	scalerRecordD62 = 124,
	scalerRecordD63 = 125,
	scalerRecordD64 = 126,
	scalerRecordG1 = 127,
	scalerRecordG2 = 128,
	scalerRecordG3 = 129,
	scalerRecordG4 = 130,
	scalerRecordG5 = 131,
	scalerRecordG6 = 132,
	scalerRecordG7 = 133,
	scalerRecordG8 = 134,
	scalerRecordG9 = 135,
	scalerRecordG10 = 136,
	scalerRecordG11 = 137,
	scalerRecordG12 = 138,
	scalerRecordG13 = 139,
	scalerRecordG14 = 140,
	scalerRecordG15 = 141,
	scalerRecordG16 = 142,
	scalerRecordG17 = 143,
	scalerRecordG18 = 144,
	scalerRecordG19 = 145,
	scalerRecordG20 = 146,
	scalerRecordG21 = 147,
	scalerRecordG22 = 148,
	scalerRecordG23 = 149,
	scalerRecordG24 = 150,
	scalerRecordG25 = 151,
	scalerRecordG26 = 152,
	scalerRecordG27 = 153,
	scalerRecordG28 = 154,
	scalerRecordG29 = 155,
	scalerRecordG30 = 156,
	scalerRecordG31 = 157,
	scalerRecordG32 = 158,
	scalerRecordG33 = 159,
	scalerRecordG34 = 160,
	scalerRecordG35 = 161,
	scalerRecordG36 = 162,
	scalerRecordG37 = 163,
	scalerRecordG38 = 164,
	scalerRecordG39 = 165,
	scalerRecordG40 = 166,
	scalerRecordG41 = 167,
	scalerRecordG42 = 168,
	scalerRecordG43 = 169,
	scalerRecordG44 = 170,
	scalerRecordG45 = 171,
	scalerRecordG46 = 172,
	scalerRecordG47 = 173,
	scalerRecordG48 = 174,
	scalerRecordG49 = 175,
	scalerRecordG50 = 176,
	scalerRecordG51 = 177,
	scalerRecordG52 = 178,
	scalerRecordG53 = 179,
	scalerRecordG54 = 180,
	scalerRecordG55 = 181,
	scalerRecordG56 = 182,
	scalerRecordG57 = 183,
	scalerRecordG58 = 184,
	scalerRecordG59 = 185,
	scalerRecordG60 = 186,
	scalerRecordG61 = 187,
	scalerRecordG62 = 188,
	scalerRecordG63 = 189,
	scalerRecordG64 = 190,
	scalerRecordTP = 191,
	scalerRecordTP1 = 192,
	scalerRecordPR1 = 193,
	scalerRecordPR2 = 194,
	scalerRecordPR3 = 195,
	scalerRecordPR4 = 196,
	scalerRecordPR5 = 197,
	scalerRecordPR6 = 198,
	scalerRecordPR7 = 199,
	scalerRecordPR8 = 200,
	scalerRecordPR9 = 201,
	scalerRecordPR10 = 202,
	scalerRecordPR11 = 203,
	scalerRecordPR12 = 204,
	scalerRecordPR13 = 205,
	scalerRecordPR14 = 206,
	scalerRecordPR15 = 207,
	scalerRecordPR16 = 208,
	scalerRecordPR17 = 209,
	scalerRecordPR18 = 210,
	scalerRecordPR19 = 211,
	scalerRecordPR20 = 212,
	scalerRecordPR21 = 213,
	scalerRecordPR22 = 214,
	scalerRecordPR23 = 215,
	scalerRecordPR24 = 216,
	scalerRecordPR25 = 217,
	scalerRecordPR26 = 218,
	scalerRecordPR27 = 219,
	scalerRecordPR28 = 220,
	scalerRecordPR29 = 221,
	scalerRecordPR30 = 222,
	scalerRecordPR31 = 223,
	scalerRecordPR32 = 224,
	scalerRecordPR33 = 225,
	scalerRecordPR34 = 226,
	scalerRecordPR35 = 227,
	scalerRecordPR36 = 228,
	scalerRecordPR37 = 229,
	scalerRecordPR38 = 230,
	scalerRecordPR39 = 231,
	scalerRecordPR40 = 232,
	scalerRecordPR41 = 233,
	scalerRecordPR42 = 234,
	scalerRecordPR43 = 235,
	scalerRecordPR44 = 236,
	scalerRecordPR45 = 237,
	scalerRecordPR46 = 238,
	scalerRecordPR47 = 239,
	scalerRecordPR48 = 240,
	scalerRecordPR49 = 241,
	scalerRecordPR50 = 242,
	scalerRecordPR51 = 243,
	scalerRecordPR52 = 244,
	scalerRecordPR53 = 245,
	scalerRecordPR54 = 246,
	scalerRecordPR55 = 247,
	scalerRecordPR56 = 248,
	scalerRecordPR57 = 249,
	scalerRecordPR58 = 250,
	scalerRecordPR59 = 251,
	scalerRecordPR60 = 252,
	scalerRecordPR61 = 253,
	scalerRecordPR62 = 254,
	scalerRecordPR63 = 255,
	scalerRecordPR64 = 256,
	scalerRecordT = 257,
	scalerRecordS1 = 258,
	scalerRecordS2 = 259,
	scalerRecordS3 = 260,
	scalerRecordS4 = 261,
	scalerRecordS5 = 262,
	scalerRecordS6 = 263,
	scalerRecordS7 = 264,
	scalerRecordS8 = 265,
	scalerRecordS9 = 266,
	scalerRecordS10 = 267,
	scalerRecordS11 = 268,
	scalerRecordS12 = 269,
	scalerRecordS13 = 270,
	scalerRecordS14 = 271,
	scalerRecordS15 = 272,
	scalerRecordS16 = 273,
	scalerRecordS17 = 274,
	scalerRecordS18 = 275,
	scalerRecordS19 = 276,
	scalerRecordS20 = 277,
	scalerRecordS21 = 278,
	scalerRecordS22 = 279,
	scalerRecordS23 = 280,
	scalerRecordS24 = 281,
	scalerRecordS25 = 282,
	scalerRecordS26 = 283,
	scalerRecordS27 = 284,
	scalerRecordS28 = 285,
	scalerRecordS29 = 286,
	scalerRecordS30 = 287,
	scalerRecordS31 = 288,
	scalerRecordS32 = 289,
	scalerRecordS33 = 290,
	scalerRecordS34 = 291,
	scalerRecordS35 = 292,
	scalerRecordS36 = 293,
	scalerRecordS37 = 294,
	scalerRecordS38 = 295,
	scalerRecordS39 = 296,
	scalerRecordS40 = 297,
	scalerRecordS41 = 298,
	scalerRecordS42 = 299,
	scalerRecordS43 = 300,
	scalerRecordS44 = 301,
	scalerRecordS45 = 302,
	scalerRecordS46 = 303,
	scalerRecordS47 = 304,
	scalerRecordS48 = 305,
	scalerRecordS49 = 306,
	scalerRecordS50 = 307,
	scalerRecordS51 = 308,
	scalerRecordS52 = 309,
	scalerRecordS53 = 310,
	scalerRecordS54 = 311,
	scalerRecordS55 = 312,
	scalerRecordS56 = 313,
	scalerRecordS57 = 314,
	scalerRecordS58 = 315,
	scalerRecordS59 = 316,
	scalerRecordS60 = 317,
	scalerRecordS61 = 318,
	scalerRecordS62 = 319,
	scalerRecordS63 = 320,
	scalerRecordS64 = 321,
	scalerRecordNM1 = 322,
	scalerRecordNM2 = 323,
	scalerRecordNM3 = 324,
	scalerRecordNM4 = 325,
	scalerRecordNM5 = 326,
	scalerRecordNM6 = 327,
	scalerRecordNM7 = 328,
	scalerRecordNM8 = 329,
	scalerRecordNM9 = 330,
	scalerRecordNM10 = 331,
	scalerRecordNM11 = 332,
	scalerRecordNM12 = 333,
	scalerRecordNM13 = 334,
	scalerRecordNM14 = 335,
	scalerRecordNM15 = 336,
	scalerRecordNM16 = 337,
	scalerRecordNM17 = 338,
	scalerRecordNM18 = 339,
	scalerRecordNM19 = 340,
	scalerRecordNM20 = 341,
	scalerRecordNM21 = 342,
	scalerRecordNM22 = 343,
	scalerRecordNM23 = 344,
	scalerRecordNM24 = 345,
	scalerRecordNM25 = 346,
	scalerRecordNM26 = 347,
	scalerRecordNM27 = 348,
	scalerRecordNM28 = 349,
	scalerRecordNM29 = 350,
	scalerRecordNM30 = 351,
	scalerRecordNM31 = 352,
	scalerRecordNM32 = 353,
	scalerRecordNM33 = 354,
	scalerRecordNM34 = 355,
	scalerRecordNM35 = 356,
	scalerRecordNM36 = 357,
	scalerRecordNM37 = 358,
	scalerRecordNM38 = 359,
	scalerRecordNM39 = 360,
	scalerRecordNM40 = 361,
	scalerRecordNM41 = 362,
	scalerRecordNM42 = 363,
	scalerRecordNM43 = 364,
	scalerRecordNM44 = 365,
	scalerRecordNM45 = 366,
	scalerRecordNM46 = 367,
	scalerRecordNM47 = 368,
	scalerRecordNM48 = 369,
	scalerRecordNM49 = 370,
	scalerRecordNM50 = 371,
	scalerRecordNM51 = 372,
	scalerRecordNM52 = 373,
	scalerRecordNM53 = 374,
	scalerRecordNM54 = 375,
	scalerRecordNM55 = 376,
	scalerRecordNM56 = 377,
	scalerRecordNM57 = 378,
	scalerRecordNM58 = 379,
	scalerRecordNM59 = 380,
	scalerRecordNM60 = 381,
	scalerRecordNM61 = 382,
	scalerRecordNM62 = 383,
	scalerRecordNM63 = 384,
	scalerRecordNM64 = 385,
	scalerRecordEGU = 386,
	scalerRecordPREC = 387,
	scalerRecordCOUT = 388,
	scalerRecordCOUTP = 389
} scalerFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int scalerRecordSizeOffset(dbRecordType *prt)
{
    scalerRecord *prec = 0;

    if (prt->no_fields != 390) {
        cantProceed("IOC build or installation error:\n"
            "    The scalerRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 390.\n",
            prt->no_fields);
    }
    prt->papFldDes[scalerRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[scalerRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[scalerRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[scalerRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[scalerRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[scalerRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[scalerRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[scalerRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[scalerRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[scalerRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[scalerRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[scalerRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[scalerRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[scalerRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[scalerRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[scalerRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[scalerRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[scalerRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[scalerRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[scalerRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[scalerRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[scalerRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[scalerRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[scalerRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[scalerRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[scalerRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[scalerRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[scalerRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[scalerRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[scalerRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[scalerRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[scalerRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[scalerRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[scalerRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[scalerRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[scalerRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[scalerRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[scalerRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[scalerRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[scalerRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[scalerRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[scalerRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[scalerRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[scalerRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[scalerRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[scalerRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[scalerRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[scalerRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[scalerRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[scalerRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[scalerRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[scalerRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[scalerRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[scalerRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[scalerRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[scalerRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[scalerRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[scalerRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[scalerRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[scalerRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[scalerRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[scalerRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[scalerRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[scalerRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[scalerRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[scalerRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[scalerRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[scalerRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[scalerRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[scalerRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[scalerRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[scalerRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[scalerRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[scalerRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[scalerRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[scalerRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[scalerRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[scalerRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[scalerRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[scalerRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[scalerRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[scalerRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[scalerRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[scalerRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[scalerRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[scalerRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[scalerRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[scalerRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[scalerRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[scalerRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[scalerRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[scalerRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[scalerRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[scalerRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[scalerRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[scalerRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[scalerRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[scalerRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[scalerRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[scalerRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[scalerRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[scalerRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[scalerRecordFREQ]->size = sizeof(prec->freq);
    prt->papFldDes[scalerRecordFREQ]->offset = (unsigned short)((char *)&prec->freq - (char *)prec);
    prt->papFldDes[scalerRecordCNT]->size = sizeof(prec->cnt);
    prt->papFldDes[scalerRecordCNT]->offset = (unsigned short)((char *)&prec->cnt - (char *)prec);
    prt->papFldDes[scalerRecordPCNT]->size = sizeof(prec->pcnt);
    prt->papFldDes[scalerRecordPCNT]->offset = (unsigned short)((char *)&prec->pcnt - (char *)prec);
    prt->papFldDes[scalerRecordSS]->size = sizeof(prec->ss);
    prt->papFldDes[scalerRecordSS]->offset = (unsigned short)((char *)&prec->ss - (char *)prec);
    prt->papFldDes[scalerRecordUS]->size = sizeof(prec->us);
    prt->papFldDes[scalerRecordUS]->offset = (unsigned short)((char *)&prec->us - (char *)prec);
    prt->papFldDes[scalerRecordCONT]->size = sizeof(prec->cont);
    prt->papFldDes[scalerRecordCONT]->offset = (unsigned short)((char *)&prec->cont - (char *)prec);
    prt->papFldDes[scalerRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[scalerRecordOUT]->offset = (unsigned short)((char *)&prec->out - (char *)prec);
    prt->papFldDes[scalerRecordRATE]->size = sizeof(prec->rate);
    prt->papFldDes[scalerRecordRATE]->offset = (unsigned short)((char *)&prec->rate - (char *)prec);
    prt->papFldDes[scalerRecordRAT1]->size = sizeof(prec->rat1);
    prt->papFldDes[scalerRecordRAT1]->offset = (unsigned short)((char *)&prec->rat1 - (char *)prec);
    prt->papFldDes[scalerRecordDLY]->size = sizeof(prec->dly);
    prt->papFldDes[scalerRecordDLY]->offset = (unsigned short)((char *)&prec->dly - (char *)prec);
    prt->papFldDes[scalerRecordDLY1]->size = sizeof(prec->dly1);
    prt->papFldDes[scalerRecordDLY1]->offset = (unsigned short)((char *)&prec->dly1 - (char *)prec);
    prt->papFldDes[scalerRecordNCH]->size = sizeof(prec->nch);
    prt->papFldDes[scalerRecordNCH]->offset = (unsigned short)((char *)&prec->nch - (char *)prec);
    prt->papFldDes[scalerRecordD1]->size = sizeof(prec->d1);
    prt->papFldDes[scalerRecordD1]->offset = (unsigned short)((char *)&prec->d1 - (char *)prec);
    prt->papFldDes[scalerRecordD2]->size = sizeof(prec->d2);
    prt->papFldDes[scalerRecordD2]->offset = (unsigned short)((char *)&prec->d2 - (char *)prec);
    prt->papFldDes[scalerRecordD3]->size = sizeof(prec->d3);
    prt->papFldDes[scalerRecordD3]->offset = (unsigned short)((char *)&prec->d3 - (char *)prec);
    prt->papFldDes[scalerRecordD4]->size = sizeof(prec->d4);
    prt->papFldDes[scalerRecordD4]->offset = (unsigned short)((char *)&prec->d4 - (char *)prec);
    prt->papFldDes[scalerRecordD5]->size = sizeof(prec->d5);
    prt->papFldDes[scalerRecordD5]->offset = (unsigned short)((char *)&prec->d5 - (char *)prec);
    prt->papFldDes[scalerRecordD6]->size = sizeof(prec->d6);
    prt->papFldDes[scalerRecordD6]->offset = (unsigned short)((char *)&prec->d6 - (char *)prec);
    prt->papFldDes[scalerRecordD7]->size = sizeof(prec->d7);
    prt->papFldDes[scalerRecordD7]->offset = (unsigned short)((char *)&prec->d7 - (char *)prec);
    prt->papFldDes[scalerRecordD8]->size = sizeof(prec->d8);
    prt->papFldDes[scalerRecordD8]->offset = (unsigned short)((char *)&prec->d8 - (char *)prec);
    prt->papFldDes[scalerRecordD9]->size = sizeof(prec->d9);
    prt->papFldDes[scalerRecordD9]->offset = (unsigned short)((char *)&prec->d9 - (char *)prec);
    prt->papFldDes[scalerRecordD10]->size = sizeof(prec->d10);
    prt->papFldDes[scalerRecordD10]->offset = (unsigned short)((char *)&prec->d10 - (char *)prec);
    prt->papFldDes[scalerRecordD11]->size = sizeof(prec->d11);
    prt->papFldDes[scalerRecordD11]->offset = (unsigned short)((char *)&prec->d11 - (char *)prec);
    prt->papFldDes[scalerRecordD12]->size = sizeof(prec->d12);
    prt->papFldDes[scalerRecordD12]->offset = (unsigned short)((char *)&prec->d12 - (char *)prec);
    prt->papFldDes[scalerRecordD13]->size = sizeof(prec->d13);
    prt->papFldDes[scalerRecordD13]->offset = (unsigned short)((char *)&prec->d13 - (char *)prec);
    prt->papFldDes[scalerRecordD14]->size = sizeof(prec->d14);
    prt->papFldDes[scalerRecordD14]->offset = (unsigned short)((char *)&prec->d14 - (char *)prec);
    prt->papFldDes[scalerRecordD15]->size = sizeof(prec->d15);
    prt->papFldDes[scalerRecordD15]->offset = (unsigned short)((char *)&prec->d15 - (char *)prec);
    prt->papFldDes[scalerRecordD16]->size = sizeof(prec->d16);
    prt->papFldDes[scalerRecordD16]->offset = (unsigned short)((char *)&prec->d16 - (char *)prec);
    prt->papFldDes[scalerRecordD17]->size = sizeof(prec->d17);
    prt->papFldDes[scalerRecordD17]->offset = (unsigned short)((char *)&prec->d17 - (char *)prec);
    prt->papFldDes[scalerRecordD18]->size = sizeof(prec->d18);
    prt->papFldDes[scalerRecordD18]->offset = (unsigned short)((char *)&prec->d18 - (char *)prec);
    prt->papFldDes[scalerRecordD19]->size = sizeof(prec->d19);
    prt->papFldDes[scalerRecordD19]->offset = (unsigned short)((char *)&prec->d19 - (char *)prec);
    prt->papFldDes[scalerRecordD20]->size = sizeof(prec->d20);
    prt->papFldDes[scalerRecordD20]->offset = (unsigned short)((char *)&prec->d20 - (char *)prec);
    prt->papFldDes[scalerRecordD21]->size = sizeof(prec->d21);
    prt->papFldDes[scalerRecordD21]->offset = (unsigned short)((char *)&prec->d21 - (char *)prec);
    prt->papFldDes[scalerRecordD22]->size = sizeof(prec->d22);
    prt->papFldDes[scalerRecordD22]->offset = (unsigned short)((char *)&prec->d22 - (char *)prec);
    prt->papFldDes[scalerRecordD23]->size = sizeof(prec->d23);
    prt->papFldDes[scalerRecordD23]->offset = (unsigned short)((char *)&prec->d23 - (char *)prec);
    prt->papFldDes[scalerRecordD24]->size = sizeof(prec->d24);
    prt->papFldDes[scalerRecordD24]->offset = (unsigned short)((char *)&prec->d24 - (char *)prec);
    prt->papFldDes[scalerRecordD25]->size = sizeof(prec->d25);
    prt->papFldDes[scalerRecordD25]->offset = (unsigned short)((char *)&prec->d25 - (char *)prec);
    prt->papFldDes[scalerRecordD26]->size = sizeof(prec->d26);
    prt->papFldDes[scalerRecordD26]->offset = (unsigned short)((char *)&prec->d26 - (char *)prec);
    prt->papFldDes[scalerRecordD27]->size = sizeof(prec->d27);
    prt->papFldDes[scalerRecordD27]->offset = (unsigned short)((char *)&prec->d27 - (char *)prec);
    prt->papFldDes[scalerRecordD28]->size = sizeof(prec->d28);
    prt->papFldDes[scalerRecordD28]->offset = (unsigned short)((char *)&prec->d28 - (char *)prec);
    prt->papFldDes[scalerRecordD29]->size = sizeof(prec->d29);
    prt->papFldDes[scalerRecordD29]->offset = (unsigned short)((char *)&prec->d29 - (char *)prec);
    prt->papFldDes[scalerRecordD30]->size = sizeof(prec->d30);
    prt->papFldDes[scalerRecordD30]->offset = (unsigned short)((char *)&prec->d30 - (char *)prec);
    prt->papFldDes[scalerRecordD31]->size = sizeof(prec->d31);
    prt->papFldDes[scalerRecordD31]->offset = (unsigned short)((char *)&prec->d31 - (char *)prec);
    prt->papFldDes[scalerRecordD32]->size = sizeof(prec->d32);
    prt->papFldDes[scalerRecordD32]->offset = (unsigned short)((char *)&prec->d32 - (char *)prec);
    prt->papFldDes[scalerRecordD33]->size = sizeof(prec->d33);
    prt->papFldDes[scalerRecordD33]->offset = (unsigned short)((char *)&prec->d33 - (char *)prec);
    prt->papFldDes[scalerRecordD34]->size = sizeof(prec->d34);
    prt->papFldDes[scalerRecordD34]->offset = (unsigned short)((char *)&prec->d34 - (char *)prec);
    prt->papFldDes[scalerRecordD35]->size = sizeof(prec->d35);
    prt->papFldDes[scalerRecordD35]->offset = (unsigned short)((char *)&prec->d35 - (char *)prec);
    prt->papFldDes[scalerRecordD36]->size = sizeof(prec->d36);
    prt->papFldDes[scalerRecordD36]->offset = (unsigned short)((char *)&prec->d36 - (char *)prec);
    prt->papFldDes[scalerRecordD37]->size = sizeof(prec->d37);
    prt->papFldDes[scalerRecordD37]->offset = (unsigned short)((char *)&prec->d37 - (char *)prec);
    prt->papFldDes[scalerRecordD38]->size = sizeof(prec->d38);
    prt->papFldDes[scalerRecordD38]->offset = (unsigned short)((char *)&prec->d38 - (char *)prec);
    prt->papFldDes[scalerRecordD39]->size = sizeof(prec->d39);
    prt->papFldDes[scalerRecordD39]->offset = (unsigned short)((char *)&prec->d39 - (char *)prec);
    prt->papFldDes[scalerRecordD40]->size = sizeof(prec->d40);
    prt->papFldDes[scalerRecordD40]->offset = (unsigned short)((char *)&prec->d40 - (char *)prec);
    prt->papFldDes[scalerRecordD41]->size = sizeof(prec->d41);
    prt->papFldDes[scalerRecordD41]->offset = (unsigned short)((char *)&prec->d41 - (char *)prec);
    prt->papFldDes[scalerRecordD42]->size = sizeof(prec->d42);
    prt->papFldDes[scalerRecordD42]->offset = (unsigned short)((char *)&prec->d42 - (char *)prec);
    prt->papFldDes[scalerRecordD43]->size = sizeof(prec->d43);
    prt->papFldDes[scalerRecordD43]->offset = (unsigned short)((char *)&prec->d43 - (char *)prec);
    prt->papFldDes[scalerRecordD44]->size = sizeof(prec->d44);
    prt->papFldDes[scalerRecordD44]->offset = (unsigned short)((char *)&prec->d44 - (char *)prec);
    prt->papFldDes[scalerRecordD45]->size = sizeof(prec->d45);
    prt->papFldDes[scalerRecordD45]->offset = (unsigned short)((char *)&prec->d45 - (char *)prec);
    prt->papFldDes[scalerRecordD46]->size = sizeof(prec->d46);
    prt->papFldDes[scalerRecordD46]->offset = (unsigned short)((char *)&prec->d46 - (char *)prec);
    prt->papFldDes[scalerRecordD47]->size = sizeof(prec->d47);
    prt->papFldDes[scalerRecordD47]->offset = (unsigned short)((char *)&prec->d47 - (char *)prec);
    prt->papFldDes[scalerRecordD48]->size = sizeof(prec->d48);
    prt->papFldDes[scalerRecordD48]->offset = (unsigned short)((char *)&prec->d48 - (char *)prec);
    prt->papFldDes[scalerRecordD49]->size = sizeof(prec->d49);
    prt->papFldDes[scalerRecordD49]->offset = (unsigned short)((char *)&prec->d49 - (char *)prec);
    prt->papFldDes[scalerRecordD50]->size = sizeof(prec->d50);
    prt->papFldDes[scalerRecordD50]->offset = (unsigned short)((char *)&prec->d50 - (char *)prec);
    prt->papFldDes[scalerRecordD51]->size = sizeof(prec->d51);
    prt->papFldDes[scalerRecordD51]->offset = (unsigned short)((char *)&prec->d51 - (char *)prec);
    prt->papFldDes[scalerRecordD52]->size = sizeof(prec->d52);
    prt->papFldDes[scalerRecordD52]->offset = (unsigned short)((char *)&prec->d52 - (char *)prec);
    prt->papFldDes[scalerRecordD53]->size = sizeof(prec->d53);
    prt->papFldDes[scalerRecordD53]->offset = (unsigned short)((char *)&prec->d53 - (char *)prec);
    prt->papFldDes[scalerRecordD54]->size = sizeof(prec->d54);
    prt->papFldDes[scalerRecordD54]->offset = (unsigned short)((char *)&prec->d54 - (char *)prec);
    prt->papFldDes[scalerRecordD55]->size = sizeof(prec->d55);
    prt->papFldDes[scalerRecordD55]->offset = (unsigned short)((char *)&prec->d55 - (char *)prec);
    prt->papFldDes[scalerRecordD56]->size = sizeof(prec->d56);
    prt->papFldDes[scalerRecordD56]->offset = (unsigned short)((char *)&prec->d56 - (char *)prec);
    prt->papFldDes[scalerRecordD57]->size = sizeof(prec->d57);
    prt->papFldDes[scalerRecordD57]->offset = (unsigned short)((char *)&prec->d57 - (char *)prec);
    prt->papFldDes[scalerRecordD58]->size = sizeof(prec->d58);
    prt->papFldDes[scalerRecordD58]->offset = (unsigned short)((char *)&prec->d58 - (char *)prec);
    prt->papFldDes[scalerRecordD59]->size = sizeof(prec->d59);
    prt->papFldDes[scalerRecordD59]->offset = (unsigned short)((char *)&prec->d59 - (char *)prec);
    prt->papFldDes[scalerRecordD60]->size = sizeof(prec->d60);
    prt->papFldDes[scalerRecordD60]->offset = (unsigned short)((char *)&prec->d60 - (char *)prec);
    prt->papFldDes[scalerRecordD61]->size = sizeof(prec->d61);
    prt->papFldDes[scalerRecordD61]->offset = (unsigned short)((char *)&prec->d61 - (char *)prec);
    prt->papFldDes[scalerRecordD62]->size = sizeof(prec->d62);
    prt->papFldDes[scalerRecordD62]->offset = (unsigned short)((char *)&prec->d62 - (char *)prec);
    prt->papFldDes[scalerRecordD63]->size = sizeof(prec->d63);
    prt->papFldDes[scalerRecordD63]->offset = (unsigned short)((char *)&prec->d63 - (char *)prec);
    prt->papFldDes[scalerRecordD64]->size = sizeof(prec->d64);
    prt->papFldDes[scalerRecordD64]->offset = (unsigned short)((char *)&prec->d64 - (char *)prec);
    prt->papFldDes[scalerRecordG1]->size = sizeof(prec->g1);
    prt->papFldDes[scalerRecordG1]->offset = (unsigned short)((char *)&prec->g1 - (char *)prec);
    prt->papFldDes[scalerRecordG2]->size = sizeof(prec->g2);
    prt->papFldDes[scalerRecordG2]->offset = (unsigned short)((char *)&prec->g2 - (char *)prec);
    prt->papFldDes[scalerRecordG3]->size = sizeof(prec->g3);
    prt->papFldDes[scalerRecordG3]->offset = (unsigned short)((char *)&prec->g3 - (char *)prec);
    prt->papFldDes[scalerRecordG4]->size = sizeof(prec->g4);
    prt->papFldDes[scalerRecordG4]->offset = (unsigned short)((char *)&prec->g4 - (char *)prec);
    prt->papFldDes[scalerRecordG5]->size = sizeof(prec->g5);
    prt->papFldDes[scalerRecordG5]->offset = (unsigned short)((char *)&prec->g5 - (char *)prec);
    prt->papFldDes[scalerRecordG6]->size = sizeof(prec->g6);
    prt->papFldDes[scalerRecordG6]->offset = (unsigned short)((char *)&prec->g6 - (char *)prec);
    prt->papFldDes[scalerRecordG7]->size = sizeof(prec->g7);
    prt->papFldDes[scalerRecordG7]->offset = (unsigned short)((char *)&prec->g7 - (char *)prec);
    prt->papFldDes[scalerRecordG8]->size = sizeof(prec->g8);
    prt->papFldDes[scalerRecordG8]->offset = (unsigned short)((char *)&prec->g8 - (char *)prec);
    prt->papFldDes[scalerRecordG9]->size = sizeof(prec->g9);
    prt->papFldDes[scalerRecordG9]->offset = (unsigned short)((char *)&prec->g9 - (char *)prec);
    prt->papFldDes[scalerRecordG10]->size = sizeof(prec->g10);
    prt->papFldDes[scalerRecordG10]->offset = (unsigned short)((char *)&prec->g10 - (char *)prec);
    prt->papFldDes[scalerRecordG11]->size = sizeof(prec->g11);
    prt->papFldDes[scalerRecordG11]->offset = (unsigned short)((char *)&prec->g11 - (char *)prec);
    prt->papFldDes[scalerRecordG12]->size = sizeof(prec->g12);
    prt->papFldDes[scalerRecordG12]->offset = (unsigned short)((char *)&prec->g12 - (char *)prec);
    prt->papFldDes[scalerRecordG13]->size = sizeof(prec->g13);
    prt->papFldDes[scalerRecordG13]->offset = (unsigned short)((char *)&prec->g13 - (char *)prec);
    prt->papFldDes[scalerRecordG14]->size = sizeof(prec->g14);
    prt->papFldDes[scalerRecordG14]->offset = (unsigned short)((char *)&prec->g14 - (char *)prec);
    prt->papFldDes[scalerRecordG15]->size = sizeof(prec->g15);
    prt->papFldDes[scalerRecordG15]->offset = (unsigned short)((char *)&prec->g15 - (char *)prec);
    prt->papFldDes[scalerRecordG16]->size = sizeof(prec->g16);
    prt->papFldDes[scalerRecordG16]->offset = (unsigned short)((char *)&prec->g16 - (char *)prec);
    prt->papFldDes[scalerRecordG17]->size = sizeof(prec->g17);
    prt->papFldDes[scalerRecordG17]->offset = (unsigned short)((char *)&prec->g17 - (char *)prec);
    prt->papFldDes[scalerRecordG18]->size = sizeof(prec->g18);
    prt->papFldDes[scalerRecordG18]->offset = (unsigned short)((char *)&prec->g18 - (char *)prec);
    prt->papFldDes[scalerRecordG19]->size = sizeof(prec->g19);
    prt->papFldDes[scalerRecordG19]->offset = (unsigned short)((char *)&prec->g19 - (char *)prec);
    prt->papFldDes[scalerRecordG20]->size = sizeof(prec->g20);
    prt->papFldDes[scalerRecordG20]->offset = (unsigned short)((char *)&prec->g20 - (char *)prec);
    prt->papFldDes[scalerRecordG21]->size = sizeof(prec->g21);
    prt->papFldDes[scalerRecordG21]->offset = (unsigned short)((char *)&prec->g21 - (char *)prec);
    prt->papFldDes[scalerRecordG22]->size = sizeof(prec->g22);
    prt->papFldDes[scalerRecordG22]->offset = (unsigned short)((char *)&prec->g22 - (char *)prec);
    prt->papFldDes[scalerRecordG23]->size = sizeof(prec->g23);
    prt->papFldDes[scalerRecordG23]->offset = (unsigned short)((char *)&prec->g23 - (char *)prec);
    prt->papFldDes[scalerRecordG24]->size = sizeof(prec->g24);
    prt->papFldDes[scalerRecordG24]->offset = (unsigned short)((char *)&prec->g24 - (char *)prec);
    prt->papFldDes[scalerRecordG25]->size = sizeof(prec->g25);
    prt->papFldDes[scalerRecordG25]->offset = (unsigned short)((char *)&prec->g25 - (char *)prec);
    prt->papFldDes[scalerRecordG26]->size = sizeof(prec->g26);
    prt->papFldDes[scalerRecordG26]->offset = (unsigned short)((char *)&prec->g26 - (char *)prec);
    prt->papFldDes[scalerRecordG27]->size = sizeof(prec->g27);
    prt->papFldDes[scalerRecordG27]->offset = (unsigned short)((char *)&prec->g27 - (char *)prec);
    prt->papFldDes[scalerRecordG28]->size = sizeof(prec->g28);
    prt->papFldDes[scalerRecordG28]->offset = (unsigned short)((char *)&prec->g28 - (char *)prec);
    prt->papFldDes[scalerRecordG29]->size = sizeof(prec->g29);
    prt->papFldDes[scalerRecordG29]->offset = (unsigned short)((char *)&prec->g29 - (char *)prec);
    prt->papFldDes[scalerRecordG30]->size = sizeof(prec->g30);
    prt->papFldDes[scalerRecordG30]->offset = (unsigned short)((char *)&prec->g30 - (char *)prec);
    prt->papFldDes[scalerRecordG31]->size = sizeof(prec->g31);
    prt->papFldDes[scalerRecordG31]->offset = (unsigned short)((char *)&prec->g31 - (char *)prec);
    prt->papFldDes[scalerRecordG32]->size = sizeof(prec->g32);
    prt->papFldDes[scalerRecordG32]->offset = (unsigned short)((char *)&prec->g32 - (char *)prec);
    prt->papFldDes[scalerRecordG33]->size = sizeof(prec->g33);
    prt->papFldDes[scalerRecordG33]->offset = (unsigned short)((char *)&prec->g33 - (char *)prec);
    prt->papFldDes[scalerRecordG34]->size = sizeof(prec->g34);
    prt->papFldDes[scalerRecordG34]->offset = (unsigned short)((char *)&prec->g34 - (char *)prec);
    prt->papFldDes[scalerRecordG35]->size = sizeof(prec->g35);
    prt->papFldDes[scalerRecordG35]->offset = (unsigned short)((char *)&prec->g35 - (char *)prec);
    prt->papFldDes[scalerRecordG36]->size = sizeof(prec->g36);
    prt->papFldDes[scalerRecordG36]->offset = (unsigned short)((char *)&prec->g36 - (char *)prec);
    prt->papFldDes[scalerRecordG37]->size = sizeof(prec->g37);
    prt->papFldDes[scalerRecordG37]->offset = (unsigned short)((char *)&prec->g37 - (char *)prec);
    prt->papFldDes[scalerRecordG38]->size = sizeof(prec->g38);
    prt->papFldDes[scalerRecordG38]->offset = (unsigned short)((char *)&prec->g38 - (char *)prec);
    prt->papFldDes[scalerRecordG39]->size = sizeof(prec->g39);
    prt->papFldDes[scalerRecordG39]->offset = (unsigned short)((char *)&prec->g39 - (char *)prec);
    prt->papFldDes[scalerRecordG40]->size = sizeof(prec->g40);
    prt->papFldDes[scalerRecordG40]->offset = (unsigned short)((char *)&prec->g40 - (char *)prec);
    prt->papFldDes[scalerRecordG41]->size = sizeof(prec->g41);
    prt->papFldDes[scalerRecordG41]->offset = (unsigned short)((char *)&prec->g41 - (char *)prec);
    prt->papFldDes[scalerRecordG42]->size = sizeof(prec->g42);
    prt->papFldDes[scalerRecordG42]->offset = (unsigned short)((char *)&prec->g42 - (char *)prec);
    prt->papFldDes[scalerRecordG43]->size = sizeof(prec->g43);
    prt->papFldDes[scalerRecordG43]->offset = (unsigned short)((char *)&prec->g43 - (char *)prec);
    prt->papFldDes[scalerRecordG44]->size = sizeof(prec->g44);
    prt->papFldDes[scalerRecordG44]->offset = (unsigned short)((char *)&prec->g44 - (char *)prec);
    prt->papFldDes[scalerRecordG45]->size = sizeof(prec->g45);
    prt->papFldDes[scalerRecordG45]->offset = (unsigned short)((char *)&prec->g45 - (char *)prec);
    prt->papFldDes[scalerRecordG46]->size = sizeof(prec->g46);
    prt->papFldDes[scalerRecordG46]->offset = (unsigned short)((char *)&prec->g46 - (char *)prec);
    prt->papFldDes[scalerRecordG47]->size = sizeof(prec->g47);
    prt->papFldDes[scalerRecordG47]->offset = (unsigned short)((char *)&prec->g47 - (char *)prec);
    prt->papFldDes[scalerRecordG48]->size = sizeof(prec->g48);
    prt->papFldDes[scalerRecordG48]->offset = (unsigned short)((char *)&prec->g48 - (char *)prec);
    prt->papFldDes[scalerRecordG49]->size = sizeof(prec->g49);
    prt->papFldDes[scalerRecordG49]->offset = (unsigned short)((char *)&prec->g49 - (char *)prec);
    prt->papFldDes[scalerRecordG50]->size = sizeof(prec->g50);
    prt->papFldDes[scalerRecordG50]->offset = (unsigned short)((char *)&prec->g50 - (char *)prec);
    prt->papFldDes[scalerRecordG51]->size = sizeof(prec->g51);
    prt->papFldDes[scalerRecordG51]->offset = (unsigned short)((char *)&prec->g51 - (char *)prec);
    prt->papFldDes[scalerRecordG52]->size = sizeof(prec->g52);
    prt->papFldDes[scalerRecordG52]->offset = (unsigned short)((char *)&prec->g52 - (char *)prec);
    prt->papFldDes[scalerRecordG53]->size = sizeof(prec->g53);
    prt->papFldDes[scalerRecordG53]->offset = (unsigned short)((char *)&prec->g53 - (char *)prec);
    prt->papFldDes[scalerRecordG54]->size = sizeof(prec->g54);
    prt->papFldDes[scalerRecordG54]->offset = (unsigned short)((char *)&prec->g54 - (char *)prec);
    prt->papFldDes[scalerRecordG55]->size = sizeof(prec->g55);
    prt->papFldDes[scalerRecordG55]->offset = (unsigned short)((char *)&prec->g55 - (char *)prec);
    prt->papFldDes[scalerRecordG56]->size = sizeof(prec->g56);
    prt->papFldDes[scalerRecordG56]->offset = (unsigned short)((char *)&prec->g56 - (char *)prec);
    prt->papFldDes[scalerRecordG57]->size = sizeof(prec->g57);
    prt->papFldDes[scalerRecordG57]->offset = (unsigned short)((char *)&prec->g57 - (char *)prec);
    prt->papFldDes[scalerRecordG58]->size = sizeof(prec->g58);
    prt->papFldDes[scalerRecordG58]->offset = (unsigned short)((char *)&prec->g58 - (char *)prec);
    prt->papFldDes[scalerRecordG59]->size = sizeof(prec->g59);
    prt->papFldDes[scalerRecordG59]->offset = (unsigned short)((char *)&prec->g59 - (char *)prec);
    prt->papFldDes[scalerRecordG60]->size = sizeof(prec->g60);
    prt->papFldDes[scalerRecordG60]->offset = (unsigned short)((char *)&prec->g60 - (char *)prec);
    prt->papFldDes[scalerRecordG61]->size = sizeof(prec->g61);
    prt->papFldDes[scalerRecordG61]->offset = (unsigned short)((char *)&prec->g61 - (char *)prec);
    prt->papFldDes[scalerRecordG62]->size = sizeof(prec->g62);
    prt->papFldDes[scalerRecordG62]->offset = (unsigned short)((char *)&prec->g62 - (char *)prec);
    prt->papFldDes[scalerRecordG63]->size = sizeof(prec->g63);
    prt->papFldDes[scalerRecordG63]->offset = (unsigned short)((char *)&prec->g63 - (char *)prec);
    prt->papFldDes[scalerRecordG64]->size = sizeof(prec->g64);
    prt->papFldDes[scalerRecordG64]->offset = (unsigned short)((char *)&prec->g64 - (char *)prec);
    prt->papFldDes[scalerRecordTP]->size = sizeof(prec->tp);
    prt->papFldDes[scalerRecordTP]->offset = (unsigned short)((char *)&prec->tp - (char *)prec);
    prt->papFldDes[scalerRecordTP1]->size = sizeof(prec->tp1);
    prt->papFldDes[scalerRecordTP1]->offset = (unsigned short)((char *)&prec->tp1 - (char *)prec);
    prt->papFldDes[scalerRecordPR1]->size = sizeof(prec->pr1);
    prt->papFldDes[scalerRecordPR1]->offset = (unsigned short)((char *)&prec->pr1 - (char *)prec);
    prt->papFldDes[scalerRecordPR2]->size = sizeof(prec->pr2);
    prt->papFldDes[scalerRecordPR2]->offset = (unsigned short)((char *)&prec->pr2 - (char *)prec);
    prt->papFldDes[scalerRecordPR3]->size = sizeof(prec->pr3);
    prt->papFldDes[scalerRecordPR3]->offset = (unsigned short)((char *)&prec->pr3 - (char *)prec);
    prt->papFldDes[scalerRecordPR4]->size = sizeof(prec->pr4);
    prt->papFldDes[scalerRecordPR4]->offset = (unsigned short)((char *)&prec->pr4 - (char *)prec);
    prt->papFldDes[scalerRecordPR5]->size = sizeof(prec->pr5);
    prt->papFldDes[scalerRecordPR5]->offset = (unsigned short)((char *)&prec->pr5 - (char *)prec);
    prt->papFldDes[scalerRecordPR6]->size = sizeof(prec->pr6);
    prt->papFldDes[scalerRecordPR6]->offset = (unsigned short)((char *)&prec->pr6 - (char *)prec);
    prt->papFldDes[scalerRecordPR7]->size = sizeof(prec->pr7);
    prt->papFldDes[scalerRecordPR7]->offset = (unsigned short)((char *)&prec->pr7 - (char *)prec);
    prt->papFldDes[scalerRecordPR8]->size = sizeof(prec->pr8);
    prt->papFldDes[scalerRecordPR8]->offset = (unsigned short)((char *)&prec->pr8 - (char *)prec);
    prt->papFldDes[scalerRecordPR9]->size = sizeof(prec->pr9);
    prt->papFldDes[scalerRecordPR9]->offset = (unsigned short)((char *)&prec->pr9 - (char *)prec);
    prt->papFldDes[scalerRecordPR10]->size = sizeof(prec->pr10);
    prt->papFldDes[scalerRecordPR10]->offset = (unsigned short)((char *)&prec->pr10 - (char *)prec);
    prt->papFldDes[scalerRecordPR11]->size = sizeof(prec->pr11);
    prt->papFldDes[scalerRecordPR11]->offset = (unsigned short)((char *)&prec->pr11 - (char *)prec);
    prt->papFldDes[scalerRecordPR12]->size = sizeof(prec->pr12);
    prt->papFldDes[scalerRecordPR12]->offset = (unsigned short)((char *)&prec->pr12 - (char *)prec);
    prt->papFldDes[scalerRecordPR13]->size = sizeof(prec->pr13);
    prt->papFldDes[scalerRecordPR13]->offset = (unsigned short)((char *)&prec->pr13 - (char *)prec);
    prt->papFldDes[scalerRecordPR14]->size = sizeof(prec->pr14);
    prt->papFldDes[scalerRecordPR14]->offset = (unsigned short)((char *)&prec->pr14 - (char *)prec);
    prt->papFldDes[scalerRecordPR15]->size = sizeof(prec->pr15);
    prt->papFldDes[scalerRecordPR15]->offset = (unsigned short)((char *)&prec->pr15 - (char *)prec);
    prt->papFldDes[scalerRecordPR16]->size = sizeof(prec->pr16);
    prt->papFldDes[scalerRecordPR16]->offset = (unsigned short)((char *)&prec->pr16 - (char *)prec);
    prt->papFldDes[scalerRecordPR17]->size = sizeof(prec->pr17);
    prt->papFldDes[scalerRecordPR17]->offset = (unsigned short)((char *)&prec->pr17 - (char *)prec);
    prt->papFldDes[scalerRecordPR18]->size = sizeof(prec->pr18);
    prt->papFldDes[scalerRecordPR18]->offset = (unsigned short)((char *)&prec->pr18 - (char *)prec);
    prt->papFldDes[scalerRecordPR19]->size = sizeof(prec->pr19);
    prt->papFldDes[scalerRecordPR19]->offset = (unsigned short)((char *)&prec->pr19 - (char *)prec);
    prt->papFldDes[scalerRecordPR20]->size = sizeof(prec->pr20);
    prt->papFldDes[scalerRecordPR20]->offset = (unsigned short)((char *)&prec->pr20 - (char *)prec);
    prt->papFldDes[scalerRecordPR21]->size = sizeof(prec->pr21);
    prt->papFldDes[scalerRecordPR21]->offset = (unsigned short)((char *)&prec->pr21 - (char *)prec);
    prt->papFldDes[scalerRecordPR22]->size = sizeof(prec->pr22);
    prt->papFldDes[scalerRecordPR22]->offset = (unsigned short)((char *)&prec->pr22 - (char *)prec);
    prt->papFldDes[scalerRecordPR23]->size = sizeof(prec->pr23);
    prt->papFldDes[scalerRecordPR23]->offset = (unsigned short)((char *)&prec->pr23 - (char *)prec);
    prt->papFldDes[scalerRecordPR24]->size = sizeof(prec->pr24);
    prt->papFldDes[scalerRecordPR24]->offset = (unsigned short)((char *)&prec->pr24 - (char *)prec);
    prt->papFldDes[scalerRecordPR25]->size = sizeof(prec->pr25);
    prt->papFldDes[scalerRecordPR25]->offset = (unsigned short)((char *)&prec->pr25 - (char *)prec);
    prt->papFldDes[scalerRecordPR26]->size = sizeof(prec->pr26);
    prt->papFldDes[scalerRecordPR26]->offset = (unsigned short)((char *)&prec->pr26 - (char *)prec);
    prt->papFldDes[scalerRecordPR27]->size = sizeof(prec->pr27);
    prt->papFldDes[scalerRecordPR27]->offset = (unsigned short)((char *)&prec->pr27 - (char *)prec);
    prt->papFldDes[scalerRecordPR28]->size = sizeof(prec->pr28);
    prt->papFldDes[scalerRecordPR28]->offset = (unsigned short)((char *)&prec->pr28 - (char *)prec);
    prt->papFldDes[scalerRecordPR29]->size = sizeof(prec->pr29);
    prt->papFldDes[scalerRecordPR29]->offset = (unsigned short)((char *)&prec->pr29 - (char *)prec);
    prt->papFldDes[scalerRecordPR30]->size = sizeof(prec->pr30);
    prt->papFldDes[scalerRecordPR30]->offset = (unsigned short)((char *)&prec->pr30 - (char *)prec);
    prt->papFldDes[scalerRecordPR31]->size = sizeof(prec->pr31);
    prt->papFldDes[scalerRecordPR31]->offset = (unsigned short)((char *)&prec->pr31 - (char *)prec);
    prt->papFldDes[scalerRecordPR32]->size = sizeof(prec->pr32);
    prt->papFldDes[scalerRecordPR32]->offset = (unsigned short)((char *)&prec->pr32 - (char *)prec);
    prt->papFldDes[scalerRecordPR33]->size = sizeof(prec->pr33);
    prt->papFldDes[scalerRecordPR33]->offset = (unsigned short)((char *)&prec->pr33 - (char *)prec);
    prt->papFldDes[scalerRecordPR34]->size = sizeof(prec->pr34);
    prt->papFldDes[scalerRecordPR34]->offset = (unsigned short)((char *)&prec->pr34 - (char *)prec);
    prt->papFldDes[scalerRecordPR35]->size = sizeof(prec->pr35);
    prt->papFldDes[scalerRecordPR35]->offset = (unsigned short)((char *)&prec->pr35 - (char *)prec);
    prt->papFldDes[scalerRecordPR36]->size = sizeof(prec->pr36);
    prt->papFldDes[scalerRecordPR36]->offset = (unsigned short)((char *)&prec->pr36 - (char *)prec);
    prt->papFldDes[scalerRecordPR37]->size = sizeof(prec->pr37);
    prt->papFldDes[scalerRecordPR37]->offset = (unsigned short)((char *)&prec->pr37 - (char *)prec);
    prt->papFldDes[scalerRecordPR38]->size = sizeof(prec->pr38);
    prt->papFldDes[scalerRecordPR38]->offset = (unsigned short)((char *)&prec->pr38 - (char *)prec);
    prt->papFldDes[scalerRecordPR39]->size = sizeof(prec->pr39);
    prt->papFldDes[scalerRecordPR39]->offset = (unsigned short)((char *)&prec->pr39 - (char *)prec);
    prt->papFldDes[scalerRecordPR40]->size = sizeof(prec->pr40);
    prt->papFldDes[scalerRecordPR40]->offset = (unsigned short)((char *)&prec->pr40 - (char *)prec);
    prt->papFldDes[scalerRecordPR41]->size = sizeof(prec->pr41);
    prt->papFldDes[scalerRecordPR41]->offset = (unsigned short)((char *)&prec->pr41 - (char *)prec);
    prt->papFldDes[scalerRecordPR42]->size = sizeof(prec->pr42);
    prt->papFldDes[scalerRecordPR42]->offset = (unsigned short)((char *)&prec->pr42 - (char *)prec);
    prt->papFldDes[scalerRecordPR43]->size = sizeof(prec->pr43);
    prt->papFldDes[scalerRecordPR43]->offset = (unsigned short)((char *)&prec->pr43 - (char *)prec);
    prt->papFldDes[scalerRecordPR44]->size = sizeof(prec->pr44);
    prt->papFldDes[scalerRecordPR44]->offset = (unsigned short)((char *)&prec->pr44 - (char *)prec);
    prt->papFldDes[scalerRecordPR45]->size = sizeof(prec->pr45);
    prt->papFldDes[scalerRecordPR45]->offset = (unsigned short)((char *)&prec->pr45 - (char *)prec);
    prt->papFldDes[scalerRecordPR46]->size = sizeof(prec->pr46);
    prt->papFldDes[scalerRecordPR46]->offset = (unsigned short)((char *)&prec->pr46 - (char *)prec);
    prt->papFldDes[scalerRecordPR47]->size = sizeof(prec->pr47);
    prt->papFldDes[scalerRecordPR47]->offset = (unsigned short)((char *)&prec->pr47 - (char *)prec);
    prt->papFldDes[scalerRecordPR48]->size = sizeof(prec->pr48);
    prt->papFldDes[scalerRecordPR48]->offset = (unsigned short)((char *)&prec->pr48 - (char *)prec);
    prt->papFldDes[scalerRecordPR49]->size = sizeof(prec->pr49);
    prt->papFldDes[scalerRecordPR49]->offset = (unsigned short)((char *)&prec->pr49 - (char *)prec);
    prt->papFldDes[scalerRecordPR50]->size = sizeof(prec->pr50);
    prt->papFldDes[scalerRecordPR50]->offset = (unsigned short)((char *)&prec->pr50 - (char *)prec);
    prt->papFldDes[scalerRecordPR51]->size = sizeof(prec->pr51);
    prt->papFldDes[scalerRecordPR51]->offset = (unsigned short)((char *)&prec->pr51 - (char *)prec);
    prt->papFldDes[scalerRecordPR52]->size = sizeof(prec->pr52);
    prt->papFldDes[scalerRecordPR52]->offset = (unsigned short)((char *)&prec->pr52 - (char *)prec);
    prt->papFldDes[scalerRecordPR53]->size = sizeof(prec->pr53);
    prt->papFldDes[scalerRecordPR53]->offset = (unsigned short)((char *)&prec->pr53 - (char *)prec);
    prt->papFldDes[scalerRecordPR54]->size = sizeof(prec->pr54);
    prt->papFldDes[scalerRecordPR54]->offset = (unsigned short)((char *)&prec->pr54 - (char *)prec);
    prt->papFldDes[scalerRecordPR55]->size = sizeof(prec->pr55);
    prt->papFldDes[scalerRecordPR55]->offset = (unsigned short)((char *)&prec->pr55 - (char *)prec);
    prt->papFldDes[scalerRecordPR56]->size = sizeof(prec->pr56);
    prt->papFldDes[scalerRecordPR56]->offset = (unsigned short)((char *)&prec->pr56 - (char *)prec);
    prt->papFldDes[scalerRecordPR57]->size = sizeof(prec->pr57);
    prt->papFldDes[scalerRecordPR57]->offset = (unsigned short)((char *)&prec->pr57 - (char *)prec);
    prt->papFldDes[scalerRecordPR58]->size = sizeof(prec->pr58);
    prt->papFldDes[scalerRecordPR58]->offset = (unsigned short)((char *)&prec->pr58 - (char *)prec);
    prt->papFldDes[scalerRecordPR59]->size = sizeof(prec->pr59);
    prt->papFldDes[scalerRecordPR59]->offset = (unsigned short)((char *)&prec->pr59 - (char *)prec);
    prt->papFldDes[scalerRecordPR60]->size = sizeof(prec->pr60);
    prt->papFldDes[scalerRecordPR60]->offset = (unsigned short)((char *)&prec->pr60 - (char *)prec);
    prt->papFldDes[scalerRecordPR61]->size = sizeof(prec->pr61);
    prt->papFldDes[scalerRecordPR61]->offset = (unsigned short)((char *)&prec->pr61 - (char *)prec);
    prt->papFldDes[scalerRecordPR62]->size = sizeof(prec->pr62);
    prt->papFldDes[scalerRecordPR62]->offset = (unsigned short)((char *)&prec->pr62 - (char *)prec);
    prt->papFldDes[scalerRecordPR63]->size = sizeof(prec->pr63);
    prt->papFldDes[scalerRecordPR63]->offset = (unsigned short)((char *)&prec->pr63 - (char *)prec);
    prt->papFldDes[scalerRecordPR64]->size = sizeof(prec->pr64);
    prt->papFldDes[scalerRecordPR64]->offset = (unsigned short)((char *)&prec->pr64 - (char *)prec);
    prt->papFldDes[scalerRecordT]->size = sizeof(prec->t);
    prt->papFldDes[scalerRecordT]->offset = (unsigned short)((char *)&prec->t - (char *)prec);
    prt->papFldDes[scalerRecordS1]->size = sizeof(prec->s1);
    prt->papFldDes[scalerRecordS1]->offset = (unsigned short)((char *)&prec->s1 - (char *)prec);
    prt->papFldDes[scalerRecordS2]->size = sizeof(prec->s2);
    prt->papFldDes[scalerRecordS2]->offset = (unsigned short)((char *)&prec->s2 - (char *)prec);
    prt->papFldDes[scalerRecordS3]->size = sizeof(prec->s3);
    prt->papFldDes[scalerRecordS3]->offset = (unsigned short)((char *)&prec->s3 - (char *)prec);
    prt->papFldDes[scalerRecordS4]->size = sizeof(prec->s4);
    prt->papFldDes[scalerRecordS4]->offset = (unsigned short)((char *)&prec->s4 - (char *)prec);
    prt->papFldDes[scalerRecordS5]->size = sizeof(prec->s5);
    prt->papFldDes[scalerRecordS5]->offset = (unsigned short)((char *)&prec->s5 - (char *)prec);
    prt->papFldDes[scalerRecordS6]->size = sizeof(prec->s6);
    prt->papFldDes[scalerRecordS6]->offset = (unsigned short)((char *)&prec->s6 - (char *)prec);
    prt->papFldDes[scalerRecordS7]->size = sizeof(prec->s7);
    prt->papFldDes[scalerRecordS7]->offset = (unsigned short)((char *)&prec->s7 - (char *)prec);
    prt->papFldDes[scalerRecordS8]->size = sizeof(prec->s8);
    prt->papFldDes[scalerRecordS8]->offset = (unsigned short)((char *)&prec->s8 - (char *)prec);
    prt->papFldDes[scalerRecordS9]->size = sizeof(prec->s9);
    prt->papFldDes[scalerRecordS9]->offset = (unsigned short)((char *)&prec->s9 - (char *)prec);
    prt->papFldDes[scalerRecordS10]->size = sizeof(prec->s10);
    prt->papFldDes[scalerRecordS10]->offset = (unsigned short)((char *)&prec->s10 - (char *)prec);
    prt->papFldDes[scalerRecordS11]->size = sizeof(prec->s11);
    prt->papFldDes[scalerRecordS11]->offset = (unsigned short)((char *)&prec->s11 - (char *)prec);
    prt->papFldDes[scalerRecordS12]->size = sizeof(prec->s12);
    prt->papFldDes[scalerRecordS12]->offset = (unsigned short)((char *)&prec->s12 - (char *)prec);
    prt->papFldDes[scalerRecordS13]->size = sizeof(prec->s13);
    prt->papFldDes[scalerRecordS13]->offset = (unsigned short)((char *)&prec->s13 - (char *)prec);
    prt->papFldDes[scalerRecordS14]->size = sizeof(prec->s14);
    prt->papFldDes[scalerRecordS14]->offset = (unsigned short)((char *)&prec->s14 - (char *)prec);
    prt->papFldDes[scalerRecordS15]->size = sizeof(prec->s15);
    prt->papFldDes[scalerRecordS15]->offset = (unsigned short)((char *)&prec->s15 - (char *)prec);
    prt->papFldDes[scalerRecordS16]->size = sizeof(prec->s16);
    prt->papFldDes[scalerRecordS16]->offset = (unsigned short)((char *)&prec->s16 - (char *)prec);
    prt->papFldDes[scalerRecordS17]->size = sizeof(prec->s17);
    prt->papFldDes[scalerRecordS17]->offset = (unsigned short)((char *)&prec->s17 - (char *)prec);
    prt->papFldDes[scalerRecordS18]->size = sizeof(prec->s18);
    prt->papFldDes[scalerRecordS18]->offset = (unsigned short)((char *)&prec->s18 - (char *)prec);
    prt->papFldDes[scalerRecordS19]->size = sizeof(prec->s19);
    prt->papFldDes[scalerRecordS19]->offset = (unsigned short)((char *)&prec->s19 - (char *)prec);
    prt->papFldDes[scalerRecordS20]->size = sizeof(prec->s20);
    prt->papFldDes[scalerRecordS20]->offset = (unsigned short)((char *)&prec->s20 - (char *)prec);
    prt->papFldDes[scalerRecordS21]->size = sizeof(prec->s21);
    prt->papFldDes[scalerRecordS21]->offset = (unsigned short)((char *)&prec->s21 - (char *)prec);
    prt->papFldDes[scalerRecordS22]->size = sizeof(prec->s22);
    prt->papFldDes[scalerRecordS22]->offset = (unsigned short)((char *)&prec->s22 - (char *)prec);
    prt->papFldDes[scalerRecordS23]->size = sizeof(prec->s23);
    prt->papFldDes[scalerRecordS23]->offset = (unsigned short)((char *)&prec->s23 - (char *)prec);
    prt->papFldDes[scalerRecordS24]->size = sizeof(prec->s24);
    prt->papFldDes[scalerRecordS24]->offset = (unsigned short)((char *)&prec->s24 - (char *)prec);
    prt->papFldDes[scalerRecordS25]->size = sizeof(prec->s25);
    prt->papFldDes[scalerRecordS25]->offset = (unsigned short)((char *)&prec->s25 - (char *)prec);
    prt->papFldDes[scalerRecordS26]->size = sizeof(prec->s26);
    prt->papFldDes[scalerRecordS26]->offset = (unsigned short)((char *)&prec->s26 - (char *)prec);
    prt->papFldDes[scalerRecordS27]->size = sizeof(prec->s27);
    prt->papFldDes[scalerRecordS27]->offset = (unsigned short)((char *)&prec->s27 - (char *)prec);
    prt->papFldDes[scalerRecordS28]->size = sizeof(prec->s28);
    prt->papFldDes[scalerRecordS28]->offset = (unsigned short)((char *)&prec->s28 - (char *)prec);
    prt->papFldDes[scalerRecordS29]->size = sizeof(prec->s29);
    prt->papFldDes[scalerRecordS29]->offset = (unsigned short)((char *)&prec->s29 - (char *)prec);
    prt->papFldDes[scalerRecordS30]->size = sizeof(prec->s30);
    prt->papFldDes[scalerRecordS30]->offset = (unsigned short)((char *)&prec->s30 - (char *)prec);
    prt->papFldDes[scalerRecordS31]->size = sizeof(prec->s31);
    prt->papFldDes[scalerRecordS31]->offset = (unsigned short)((char *)&prec->s31 - (char *)prec);
    prt->papFldDes[scalerRecordS32]->size = sizeof(prec->s32);
    prt->papFldDes[scalerRecordS32]->offset = (unsigned short)((char *)&prec->s32 - (char *)prec);
    prt->papFldDes[scalerRecordS33]->size = sizeof(prec->s33);
    prt->papFldDes[scalerRecordS33]->offset = (unsigned short)((char *)&prec->s33 - (char *)prec);
    prt->papFldDes[scalerRecordS34]->size = sizeof(prec->s34);
    prt->papFldDes[scalerRecordS34]->offset = (unsigned short)((char *)&prec->s34 - (char *)prec);
    prt->papFldDes[scalerRecordS35]->size = sizeof(prec->s35);
    prt->papFldDes[scalerRecordS35]->offset = (unsigned short)((char *)&prec->s35 - (char *)prec);
    prt->papFldDes[scalerRecordS36]->size = sizeof(prec->s36);
    prt->papFldDes[scalerRecordS36]->offset = (unsigned short)((char *)&prec->s36 - (char *)prec);
    prt->papFldDes[scalerRecordS37]->size = sizeof(prec->s37);
    prt->papFldDes[scalerRecordS37]->offset = (unsigned short)((char *)&prec->s37 - (char *)prec);
    prt->papFldDes[scalerRecordS38]->size = sizeof(prec->s38);
    prt->papFldDes[scalerRecordS38]->offset = (unsigned short)((char *)&prec->s38 - (char *)prec);
    prt->papFldDes[scalerRecordS39]->size = sizeof(prec->s39);
    prt->papFldDes[scalerRecordS39]->offset = (unsigned short)((char *)&prec->s39 - (char *)prec);
    prt->papFldDes[scalerRecordS40]->size = sizeof(prec->s40);
    prt->papFldDes[scalerRecordS40]->offset = (unsigned short)((char *)&prec->s40 - (char *)prec);
    prt->papFldDes[scalerRecordS41]->size = sizeof(prec->s41);
    prt->papFldDes[scalerRecordS41]->offset = (unsigned short)((char *)&prec->s41 - (char *)prec);
    prt->papFldDes[scalerRecordS42]->size = sizeof(prec->s42);
    prt->papFldDes[scalerRecordS42]->offset = (unsigned short)((char *)&prec->s42 - (char *)prec);
    prt->papFldDes[scalerRecordS43]->size = sizeof(prec->s43);
    prt->papFldDes[scalerRecordS43]->offset = (unsigned short)((char *)&prec->s43 - (char *)prec);
    prt->papFldDes[scalerRecordS44]->size = sizeof(prec->s44);
    prt->papFldDes[scalerRecordS44]->offset = (unsigned short)((char *)&prec->s44 - (char *)prec);
    prt->papFldDes[scalerRecordS45]->size = sizeof(prec->s45);
    prt->papFldDes[scalerRecordS45]->offset = (unsigned short)((char *)&prec->s45 - (char *)prec);
    prt->papFldDes[scalerRecordS46]->size = sizeof(prec->s46);
    prt->papFldDes[scalerRecordS46]->offset = (unsigned short)((char *)&prec->s46 - (char *)prec);
    prt->papFldDes[scalerRecordS47]->size = sizeof(prec->s47);
    prt->papFldDes[scalerRecordS47]->offset = (unsigned short)((char *)&prec->s47 - (char *)prec);
    prt->papFldDes[scalerRecordS48]->size = sizeof(prec->s48);
    prt->papFldDes[scalerRecordS48]->offset = (unsigned short)((char *)&prec->s48 - (char *)prec);
    prt->papFldDes[scalerRecordS49]->size = sizeof(prec->s49);
    prt->papFldDes[scalerRecordS49]->offset = (unsigned short)((char *)&prec->s49 - (char *)prec);
    prt->papFldDes[scalerRecordS50]->size = sizeof(prec->s50);
    prt->papFldDes[scalerRecordS50]->offset = (unsigned short)((char *)&prec->s50 - (char *)prec);
    prt->papFldDes[scalerRecordS51]->size = sizeof(prec->s51);
    prt->papFldDes[scalerRecordS51]->offset = (unsigned short)((char *)&prec->s51 - (char *)prec);
    prt->papFldDes[scalerRecordS52]->size = sizeof(prec->s52);
    prt->papFldDes[scalerRecordS52]->offset = (unsigned short)((char *)&prec->s52 - (char *)prec);
    prt->papFldDes[scalerRecordS53]->size = sizeof(prec->s53);
    prt->papFldDes[scalerRecordS53]->offset = (unsigned short)((char *)&prec->s53 - (char *)prec);
    prt->papFldDes[scalerRecordS54]->size = sizeof(prec->s54);
    prt->papFldDes[scalerRecordS54]->offset = (unsigned short)((char *)&prec->s54 - (char *)prec);
    prt->papFldDes[scalerRecordS55]->size = sizeof(prec->s55);
    prt->papFldDes[scalerRecordS55]->offset = (unsigned short)((char *)&prec->s55 - (char *)prec);
    prt->papFldDes[scalerRecordS56]->size = sizeof(prec->s56);
    prt->papFldDes[scalerRecordS56]->offset = (unsigned short)((char *)&prec->s56 - (char *)prec);
    prt->papFldDes[scalerRecordS57]->size = sizeof(prec->s57);
    prt->papFldDes[scalerRecordS57]->offset = (unsigned short)((char *)&prec->s57 - (char *)prec);
    prt->papFldDes[scalerRecordS58]->size = sizeof(prec->s58);
    prt->papFldDes[scalerRecordS58]->offset = (unsigned short)((char *)&prec->s58 - (char *)prec);
    prt->papFldDes[scalerRecordS59]->size = sizeof(prec->s59);
    prt->papFldDes[scalerRecordS59]->offset = (unsigned short)((char *)&prec->s59 - (char *)prec);
    prt->papFldDes[scalerRecordS60]->size = sizeof(prec->s60);
    prt->papFldDes[scalerRecordS60]->offset = (unsigned short)((char *)&prec->s60 - (char *)prec);
    prt->papFldDes[scalerRecordS61]->size = sizeof(prec->s61);
    prt->papFldDes[scalerRecordS61]->offset = (unsigned short)((char *)&prec->s61 - (char *)prec);
    prt->papFldDes[scalerRecordS62]->size = sizeof(prec->s62);
    prt->papFldDes[scalerRecordS62]->offset = (unsigned short)((char *)&prec->s62 - (char *)prec);
    prt->papFldDes[scalerRecordS63]->size = sizeof(prec->s63);
    prt->papFldDes[scalerRecordS63]->offset = (unsigned short)((char *)&prec->s63 - (char *)prec);
    prt->papFldDes[scalerRecordS64]->size = sizeof(prec->s64);
    prt->papFldDes[scalerRecordS64]->offset = (unsigned short)((char *)&prec->s64 - (char *)prec);
    prt->papFldDes[scalerRecordNM1]->size = sizeof(prec->nm1);
    prt->papFldDes[scalerRecordNM1]->offset = (unsigned short)((char *)&prec->nm1 - (char *)prec);
    prt->papFldDes[scalerRecordNM2]->size = sizeof(prec->nm2);
    prt->papFldDes[scalerRecordNM2]->offset = (unsigned short)((char *)&prec->nm2 - (char *)prec);
    prt->papFldDes[scalerRecordNM3]->size = sizeof(prec->nm3);
    prt->papFldDes[scalerRecordNM3]->offset = (unsigned short)((char *)&prec->nm3 - (char *)prec);
    prt->papFldDes[scalerRecordNM4]->size = sizeof(prec->nm4);
    prt->papFldDes[scalerRecordNM4]->offset = (unsigned short)((char *)&prec->nm4 - (char *)prec);
    prt->papFldDes[scalerRecordNM5]->size = sizeof(prec->nm5);
    prt->papFldDes[scalerRecordNM5]->offset = (unsigned short)((char *)&prec->nm5 - (char *)prec);
    prt->papFldDes[scalerRecordNM6]->size = sizeof(prec->nm6);
    prt->papFldDes[scalerRecordNM6]->offset = (unsigned short)((char *)&prec->nm6 - (char *)prec);
    prt->papFldDes[scalerRecordNM7]->size = sizeof(prec->nm7);
    prt->papFldDes[scalerRecordNM7]->offset = (unsigned short)((char *)&prec->nm7 - (char *)prec);
    prt->papFldDes[scalerRecordNM8]->size = sizeof(prec->nm8);
    prt->papFldDes[scalerRecordNM8]->offset = (unsigned short)((char *)&prec->nm8 - (char *)prec);
    prt->papFldDes[scalerRecordNM9]->size = sizeof(prec->nm9);
    prt->papFldDes[scalerRecordNM9]->offset = (unsigned short)((char *)&prec->nm9 - (char *)prec);
    prt->papFldDes[scalerRecordNM10]->size = sizeof(prec->nm10);
    prt->papFldDes[scalerRecordNM10]->offset = (unsigned short)((char *)&prec->nm10 - (char *)prec);
    prt->papFldDes[scalerRecordNM11]->size = sizeof(prec->nm11);
    prt->papFldDes[scalerRecordNM11]->offset = (unsigned short)((char *)&prec->nm11 - (char *)prec);
    prt->papFldDes[scalerRecordNM12]->size = sizeof(prec->nm12);
    prt->papFldDes[scalerRecordNM12]->offset = (unsigned short)((char *)&prec->nm12 - (char *)prec);
    prt->papFldDes[scalerRecordNM13]->size = sizeof(prec->nm13);
    prt->papFldDes[scalerRecordNM13]->offset = (unsigned short)((char *)&prec->nm13 - (char *)prec);
    prt->papFldDes[scalerRecordNM14]->size = sizeof(prec->nm14);
    prt->papFldDes[scalerRecordNM14]->offset = (unsigned short)((char *)&prec->nm14 - (char *)prec);
    prt->papFldDes[scalerRecordNM15]->size = sizeof(prec->nm15);
    prt->papFldDes[scalerRecordNM15]->offset = (unsigned short)((char *)&prec->nm15 - (char *)prec);
    prt->papFldDes[scalerRecordNM16]->size = sizeof(prec->nm16);
    prt->papFldDes[scalerRecordNM16]->offset = (unsigned short)((char *)&prec->nm16 - (char *)prec);
    prt->papFldDes[scalerRecordNM17]->size = sizeof(prec->nm17);
    prt->papFldDes[scalerRecordNM17]->offset = (unsigned short)((char *)&prec->nm17 - (char *)prec);
    prt->papFldDes[scalerRecordNM18]->size = sizeof(prec->nm18);
    prt->papFldDes[scalerRecordNM18]->offset = (unsigned short)((char *)&prec->nm18 - (char *)prec);
    prt->papFldDes[scalerRecordNM19]->size = sizeof(prec->nm19);
    prt->papFldDes[scalerRecordNM19]->offset = (unsigned short)((char *)&prec->nm19 - (char *)prec);
    prt->papFldDes[scalerRecordNM20]->size = sizeof(prec->nm20);
    prt->papFldDes[scalerRecordNM20]->offset = (unsigned short)((char *)&prec->nm20 - (char *)prec);
    prt->papFldDes[scalerRecordNM21]->size = sizeof(prec->nm21);
    prt->papFldDes[scalerRecordNM21]->offset = (unsigned short)((char *)&prec->nm21 - (char *)prec);
    prt->papFldDes[scalerRecordNM22]->size = sizeof(prec->nm22);
    prt->papFldDes[scalerRecordNM22]->offset = (unsigned short)((char *)&prec->nm22 - (char *)prec);
    prt->papFldDes[scalerRecordNM23]->size = sizeof(prec->nm23);
    prt->papFldDes[scalerRecordNM23]->offset = (unsigned short)((char *)&prec->nm23 - (char *)prec);
    prt->papFldDes[scalerRecordNM24]->size = sizeof(prec->nm24);
    prt->papFldDes[scalerRecordNM24]->offset = (unsigned short)((char *)&prec->nm24 - (char *)prec);
    prt->papFldDes[scalerRecordNM25]->size = sizeof(prec->nm25);
    prt->papFldDes[scalerRecordNM25]->offset = (unsigned short)((char *)&prec->nm25 - (char *)prec);
    prt->papFldDes[scalerRecordNM26]->size = sizeof(prec->nm26);
    prt->papFldDes[scalerRecordNM26]->offset = (unsigned short)((char *)&prec->nm26 - (char *)prec);
    prt->papFldDes[scalerRecordNM27]->size = sizeof(prec->nm27);
    prt->papFldDes[scalerRecordNM27]->offset = (unsigned short)((char *)&prec->nm27 - (char *)prec);
    prt->papFldDes[scalerRecordNM28]->size = sizeof(prec->nm28);
    prt->papFldDes[scalerRecordNM28]->offset = (unsigned short)((char *)&prec->nm28 - (char *)prec);
    prt->papFldDes[scalerRecordNM29]->size = sizeof(prec->nm29);
    prt->papFldDes[scalerRecordNM29]->offset = (unsigned short)((char *)&prec->nm29 - (char *)prec);
    prt->papFldDes[scalerRecordNM30]->size = sizeof(prec->nm30);
    prt->papFldDes[scalerRecordNM30]->offset = (unsigned short)((char *)&prec->nm30 - (char *)prec);
    prt->papFldDes[scalerRecordNM31]->size = sizeof(prec->nm31);
    prt->papFldDes[scalerRecordNM31]->offset = (unsigned short)((char *)&prec->nm31 - (char *)prec);
    prt->papFldDes[scalerRecordNM32]->size = sizeof(prec->nm32);
    prt->papFldDes[scalerRecordNM32]->offset = (unsigned short)((char *)&prec->nm32 - (char *)prec);
    prt->papFldDes[scalerRecordNM33]->size = sizeof(prec->nm33);
    prt->papFldDes[scalerRecordNM33]->offset = (unsigned short)((char *)&prec->nm33 - (char *)prec);
    prt->papFldDes[scalerRecordNM34]->size = sizeof(prec->nm34);
    prt->papFldDes[scalerRecordNM34]->offset = (unsigned short)((char *)&prec->nm34 - (char *)prec);
    prt->papFldDes[scalerRecordNM35]->size = sizeof(prec->nm35);
    prt->papFldDes[scalerRecordNM35]->offset = (unsigned short)((char *)&prec->nm35 - (char *)prec);
    prt->papFldDes[scalerRecordNM36]->size = sizeof(prec->nm36);
    prt->papFldDes[scalerRecordNM36]->offset = (unsigned short)((char *)&prec->nm36 - (char *)prec);
    prt->papFldDes[scalerRecordNM37]->size = sizeof(prec->nm37);
    prt->papFldDes[scalerRecordNM37]->offset = (unsigned short)((char *)&prec->nm37 - (char *)prec);
    prt->papFldDes[scalerRecordNM38]->size = sizeof(prec->nm38);
    prt->papFldDes[scalerRecordNM38]->offset = (unsigned short)((char *)&prec->nm38 - (char *)prec);
    prt->papFldDes[scalerRecordNM39]->size = sizeof(prec->nm39);
    prt->papFldDes[scalerRecordNM39]->offset = (unsigned short)((char *)&prec->nm39 - (char *)prec);
    prt->papFldDes[scalerRecordNM40]->size = sizeof(prec->nm40);
    prt->papFldDes[scalerRecordNM40]->offset = (unsigned short)((char *)&prec->nm40 - (char *)prec);
    prt->papFldDes[scalerRecordNM41]->size = sizeof(prec->nm41);
    prt->papFldDes[scalerRecordNM41]->offset = (unsigned short)((char *)&prec->nm41 - (char *)prec);
    prt->papFldDes[scalerRecordNM42]->size = sizeof(prec->nm42);
    prt->papFldDes[scalerRecordNM42]->offset = (unsigned short)((char *)&prec->nm42 - (char *)prec);
    prt->papFldDes[scalerRecordNM43]->size = sizeof(prec->nm43);
    prt->papFldDes[scalerRecordNM43]->offset = (unsigned short)((char *)&prec->nm43 - (char *)prec);
    prt->papFldDes[scalerRecordNM44]->size = sizeof(prec->nm44);
    prt->papFldDes[scalerRecordNM44]->offset = (unsigned short)((char *)&prec->nm44 - (char *)prec);
    prt->papFldDes[scalerRecordNM45]->size = sizeof(prec->nm45);
    prt->papFldDes[scalerRecordNM45]->offset = (unsigned short)((char *)&prec->nm45 - (char *)prec);
    prt->papFldDes[scalerRecordNM46]->size = sizeof(prec->nm46);
    prt->papFldDes[scalerRecordNM46]->offset = (unsigned short)((char *)&prec->nm46 - (char *)prec);
    prt->papFldDes[scalerRecordNM47]->size = sizeof(prec->nm47);
    prt->papFldDes[scalerRecordNM47]->offset = (unsigned short)((char *)&prec->nm47 - (char *)prec);
    prt->papFldDes[scalerRecordNM48]->size = sizeof(prec->nm48);
    prt->papFldDes[scalerRecordNM48]->offset = (unsigned short)((char *)&prec->nm48 - (char *)prec);
    prt->papFldDes[scalerRecordNM49]->size = sizeof(prec->nm49);
    prt->papFldDes[scalerRecordNM49]->offset = (unsigned short)((char *)&prec->nm49 - (char *)prec);
    prt->papFldDes[scalerRecordNM50]->size = sizeof(prec->nm50);
    prt->papFldDes[scalerRecordNM50]->offset = (unsigned short)((char *)&prec->nm50 - (char *)prec);
    prt->papFldDes[scalerRecordNM51]->size = sizeof(prec->nm51);
    prt->papFldDes[scalerRecordNM51]->offset = (unsigned short)((char *)&prec->nm51 - (char *)prec);
    prt->papFldDes[scalerRecordNM52]->size = sizeof(prec->nm52);
    prt->papFldDes[scalerRecordNM52]->offset = (unsigned short)((char *)&prec->nm52 - (char *)prec);
    prt->papFldDes[scalerRecordNM53]->size = sizeof(prec->nm53);
    prt->papFldDes[scalerRecordNM53]->offset = (unsigned short)((char *)&prec->nm53 - (char *)prec);
    prt->papFldDes[scalerRecordNM54]->size = sizeof(prec->nm54);
    prt->papFldDes[scalerRecordNM54]->offset = (unsigned short)((char *)&prec->nm54 - (char *)prec);
    prt->papFldDes[scalerRecordNM55]->size = sizeof(prec->nm55);
    prt->papFldDes[scalerRecordNM55]->offset = (unsigned short)((char *)&prec->nm55 - (char *)prec);
    prt->papFldDes[scalerRecordNM56]->size = sizeof(prec->nm56);
    prt->papFldDes[scalerRecordNM56]->offset = (unsigned short)((char *)&prec->nm56 - (char *)prec);
    prt->papFldDes[scalerRecordNM57]->size = sizeof(prec->nm57);
    prt->papFldDes[scalerRecordNM57]->offset = (unsigned short)((char *)&prec->nm57 - (char *)prec);
    prt->papFldDes[scalerRecordNM58]->size = sizeof(prec->nm58);
    prt->papFldDes[scalerRecordNM58]->offset = (unsigned short)((char *)&prec->nm58 - (char *)prec);
    prt->papFldDes[scalerRecordNM59]->size = sizeof(prec->nm59);
    prt->papFldDes[scalerRecordNM59]->offset = (unsigned short)((char *)&prec->nm59 - (char *)prec);
    prt->papFldDes[scalerRecordNM60]->size = sizeof(prec->nm60);
    prt->papFldDes[scalerRecordNM60]->offset = (unsigned short)((char *)&prec->nm60 - (char *)prec);
    prt->papFldDes[scalerRecordNM61]->size = sizeof(prec->nm61);
    prt->papFldDes[scalerRecordNM61]->offset = (unsigned short)((char *)&prec->nm61 - (char *)prec);
    prt->papFldDes[scalerRecordNM62]->size = sizeof(prec->nm62);
    prt->papFldDes[scalerRecordNM62]->offset = (unsigned short)((char *)&prec->nm62 - (char *)prec);
    prt->papFldDes[scalerRecordNM63]->size = sizeof(prec->nm63);
    prt->papFldDes[scalerRecordNM63]->offset = (unsigned short)((char *)&prec->nm63 - (char *)prec);
    prt->papFldDes[scalerRecordNM64]->size = sizeof(prec->nm64);
    prt->papFldDes[scalerRecordNM64]->offset = (unsigned short)((char *)&prec->nm64 - (char *)prec);
    prt->papFldDes[scalerRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[scalerRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[scalerRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[scalerRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[scalerRecordCOUT]->size = sizeof(prec->cout);
    prt->papFldDes[scalerRecordCOUT]->offset = (unsigned short)((char *)&prec->cout - (char *)prec);
    prt->papFldDes[scalerRecordCOUTP]->size = sizeof(prec->coutp);
    prt->papFldDes[scalerRecordCOUTP]->offset = (unsigned short)((char *)&prec->coutp - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(scalerRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_scalerRecord_H */
