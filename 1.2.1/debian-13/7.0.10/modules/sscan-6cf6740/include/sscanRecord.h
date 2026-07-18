/** @file sscanRecord.h
 * @brief Declarations for the @ref sscanRecord "sscan" record type.
 *
 * This header was generated from sscanRecord.dbd
 */

#ifndef INC_sscanRecord_H
#define INC_sscanRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

/** @brief Declaration of sscan record type. */
typedef struct sscanRecord {
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
    epicsFloat64        val;        /**< @brief Value Field */
    char                smsg[40];   /**< @brief Record State Msg */
    epicsEnum16         cmnd;       /**< @brief Command Field */
    epicsUInt8          alrt;       /**< @brief Operator Alert */
    void *           rpvt;          /**< @brief Ptr to Pvt Struct */
    epicsInt32          mpts;       /**< @brief Max # of Points */
    epicsInt16          exsc;       /**< @brief Execute Scan */
    epicsInt16          xsc;        /**< @brief Internal execScan */
    epicsUInt8          pxsc;       /**< @brief Previous XScan */
    epicsUInt8          busy;       /**< @brief Scan in progress */
    epicsUInt8          kill;       /**< @brief Abort right now */
    epicsInt16          wait;       /**< @brief Wait for client(s) */
    epicsInt16          wcnt;       /**< @brief Wait count) */
    epicsInt16          awct;       /**< @brief Auto WCNT */
    epicsInt16          wtng;       /**< @brief Waiting for client(s) */
    epicsInt16          await;      /**< @brief Waiting for data-storage client */
    epicsEnum16         aawait;     /**< @brief AutoWait for data-storage client */
    epicsInt16          data;       /**< @brief Scan data ready */
    epicsInt16          refd;       /**< @brief Reference detector */
    epicsInt32          npts;       /**< @brief Number of Points */
    epicsEnum16         fpts;       /**< @brief Freeze Num of Points */
    epicsEnum16         ffo;        /**< @brief Freeze Flag Override */
    epicsInt32          cpt;        /**< @brief Current Point */
    epicsInt32          bcpt;       /**< @brief Bufferred Current Point */
    epicsInt32          dpt;        /**< @brief Desired Point */
    epicsInt32          pcpt;       /**< @brief Point ofLast Posting */
    epicsEnum16         pasm;       /**< @brief After Scan Mode */
    epicsTimeStamp	tolp;            /**< @brief Time of Last Posting */
    epicsTimeStamp	tlap;            /**< @brief Time of Last Array Posting */
    epicsFloat32        atime;      /**< @brief Array post time period */
    char                p1pv[40];   /**< @brief Positioner 1 PV Name */
    char                p2pv[40];   /**< @brief Positioner 2 PV Name */
    char                p3pv[40];   /**< @brief Positioner 3 PV Name */
    char                p4pv[40];   /**< @brief Positioner 4 PV Name */
    char                r1pv[40];   /**< @brief P1 Readback  PV Name */
    char                r2pv[40];   /**< @brief P2 Readback  PV Name */
    char                r3pv[40];   /**< @brief P3 Readback  PV Name */
    char                r4pv[40];   /**< @brief P4 Readback  PV Name */
    char                d01pv[40];  /**< @brief Detector PV Name */
    char                d02pv[40];  /**< @brief Detector PV Name */
    char                d03pv[40];  /**< @brief Detector PV Name */
    char                d04pv[40];  /**< @brief Detector PV Name */
    char                d05pv[40];  /**< @brief Detector PV Name */
    char                d06pv[40];  /**< @brief Detector PV Name */
    char                d07pv[40];  /**< @brief Detector PV Name */
    char                d08pv[40];  /**< @brief Detector PV Name */
    char                d09pv[40];  /**< @brief Detector PV Name */
    char                d10pv[40];  /**< @brief Detector PV Name */
    char                d11pv[40];  /**< @brief Detector PV Name */
    char                d12pv[40];  /**< @brief Detector PV Name */
    char                d13pv[40];  /**< @brief Detector PV Name */
    char                d14pv[40];  /**< @brief Detector PV Name */
    char                d15pv[40];  /**< @brief Detector PV Name */
    char                d16pv[40];  /**< @brief Detector PV Name */
    char                d17pv[40];  /**< @brief Detector PV Name */
    char                d18pv[40];  /**< @brief Detector PV Name */
    char                d19pv[40];  /**< @brief Detector PV Name */
    char                d20pv[40];  /**< @brief Detector PV Name */
    char                d21pv[40];  /**< @brief Detector PV Name */
    char                d22pv[40];  /**< @brief Detector PV Name */
    char                d23pv[40];  /**< @brief Detector PV Name */
    char                d24pv[40];  /**< @brief Detector PV Name */
    char                d25pv[40];  /**< @brief Detector PV Name */
    char                d26pv[40];  /**< @brief Detector PV Name */
    char                d27pv[40];  /**< @brief Detector PV Name */
    char                d28pv[40];  /**< @brief Detector PV Name */
    char                d29pv[40];  /**< @brief Detector PV Name */
    char                d30pv[40];  /**< @brief Detector PV Name */
    char                d31pv[40];  /**< @brief Detector PV Name */
    char                d32pv[40];  /**< @brief Detector PV Name */
    char                d33pv[40];  /**< @brief Detector PV Name */
    char                d34pv[40];  /**< @brief Detector PV Name */
    char                d35pv[40];  /**< @brief Detector PV Name */
    char                d36pv[40];  /**< @brief Detector PV Name */
    char                d37pv[40];  /**< @brief Detector PV Name */
    char                d38pv[40];  /**< @brief Detector PV Name */
    char                d39pv[40];  /**< @brief Detector PV Name */
    char                d40pv[40];  /**< @brief Detector PV Name */
    char                d41pv[40];  /**< @brief Detector PV Name */
    char                d42pv[40];  /**< @brief Detector PV Name */
    char                d43pv[40];  /**< @brief Detector PV Name */
    char                d44pv[40];  /**< @brief Detector PV Name */
    char                d45pv[40];  /**< @brief Detector PV Name */
    char                d46pv[40];  /**< @brief Detector PV Name */
    char                d47pv[40];  /**< @brief Detector PV Name */
    char                d48pv[40];  /**< @brief Detector PV Name */
    char                d49pv[40];  /**< @brief Detector PV Name */
    char                d50pv[40];  /**< @brief Detector PV Name */
    char                d51pv[40];  /**< @brief Detector PV Name */
    char                d52pv[40];  /**< @brief Detector PV Name */
    char                d53pv[40];  /**< @brief Detector PV Name */
    char                d54pv[40];  /**< @brief Detector PV Name */
    char                d55pv[40];  /**< @brief Detector PV Name */
    char                d56pv[40];  /**< @brief Detector PV Name */
    char                d57pv[40];  /**< @brief Detector PV Name */
    char                d58pv[40];  /**< @brief Detector PV Name */
    char                d59pv[40];  /**< @brief Detector PV Name */
    char                d60pv[40];  /**< @brief Detector PV Name */
    char                d61pv[40];  /**< @brief Detector PV Name */
    char                d62pv[40];  /**< @brief Detector PV Name */
    char                d63pv[40];  /**< @brief Detector PV Name */
    char                d64pv[40];  /**< @brief Detector PV Name */
    char                d65pv[40];  /**< @brief Detector PV Name */
    char                d66pv[40];  /**< @brief Detector PV Name */
    char                d67pv[40];  /**< @brief Detector PV Name */
    char                d68pv[40];  /**< @brief Detector PV Name */
    char                d69pv[40];  /**< @brief Detector PV Name */
    char                d70pv[40];  /**< @brief Detector PV Name */
    char                t1pv[40];   /**< @brief Trigger 1    PV Name */
    char                t2pv[40];   /**< @brief Trigger 2    PV Name */
    char                t3pv[40];   /**< @brief Trigger 3    PV Name */
    char                t4pv[40];   /**< @brief Trigger 4    PV Name */
    char                a1pv[40];   /**< @brief Array-read trigger 1 PV Name */
    char                bspv[40];   /**< @brief Before Scan  PV Name */
    char                aspv[40];   /**< @brief After Scan   PV Name */
    epicsEnum16         bswait;     /**< @brief Wait for completion? */
    epicsEnum16         aswait;     /**< @brief Wait for completion? */
    epicsEnum16         p1nv;       /**< @brief P1  PV Status */
    epicsEnum16         p2nv;       /**< @brief P2  PV Status */
    epicsEnum16         p3nv;       /**< @brief P3  PV Status */
    epicsEnum16         p4nv;       /**< @brief P4  PV Status */
    epicsEnum16         r1nv;       /**< @brief R1  PV Status */
    epicsEnum16         r2nv;       /**< @brief R2  PV Status */
    epicsEnum16         r3nv;       /**< @brief R3  PV Status */
    epicsEnum16         r4nv;       /**< @brief R4  PV Status */
    epicsEnum16         d01nv;      /**< @brief PV Status */
    epicsEnum16         d02nv;      /**< @brief PV Status */
    epicsEnum16         d03nv;      /**< @brief PV Status */
    epicsEnum16         d04nv;      /**< @brief PV Status */
    epicsEnum16         d05nv;      /**< @brief PV Status */
    epicsEnum16         d06nv;      /**< @brief PV Status */
    epicsEnum16         d07nv;      /**< @brief PV Status */
    epicsEnum16         d08nv;      /**< @brief PV Status */
    epicsEnum16         d09nv;      /**< @brief PV Status */
    epicsEnum16         d10nv;      /**< @brief PV Status */
    epicsEnum16         d11nv;      /**< @brief PV Status */
    epicsEnum16         d12nv;      /**< @brief PV Status */
    epicsEnum16         d13nv;      /**< @brief PV Status */
    epicsEnum16         d14nv;      /**< @brief PV Status */
    epicsEnum16         d15nv;      /**< @brief PV Status */
    epicsEnum16         d16nv;      /**< @brief PV Status */
    epicsEnum16         d17nv;      /**< @brief PV Status */
    epicsEnum16         d18nv;      /**< @brief PV Status */
    epicsEnum16         d19nv;      /**< @brief PV Status */
    epicsEnum16         d20nv;      /**< @brief PV Status */
    epicsEnum16         d21nv;      /**< @brief PV Status */
    epicsEnum16         d22nv;      /**< @brief PV Status */
    epicsEnum16         d23nv;      /**< @brief PV Status */
    epicsEnum16         d24nv;      /**< @brief PV Status */
    epicsEnum16         d25nv;      /**< @brief PV Status */
    epicsEnum16         d26nv;      /**< @brief PV Status */
    epicsEnum16         d27nv;      /**< @brief PV Status */
    epicsEnum16         d28nv;      /**< @brief PV Status */
    epicsEnum16         d29nv;      /**< @brief PV Status */
    epicsEnum16         d30nv;      /**< @brief PV Status */
    epicsEnum16         d31nv;      /**< @brief PV Status */
    epicsEnum16         d32nv;      /**< @brief PV Status */
    epicsEnum16         d33nv;      /**< @brief PV Status */
    epicsEnum16         d34nv;      /**< @brief PV Status */
    epicsEnum16         d35nv;      /**< @brief PV Status */
    epicsEnum16         d36nv;      /**< @brief PV Status */
    epicsEnum16         d37nv;      /**< @brief PV Status */
    epicsEnum16         d38nv;      /**< @brief PV Status */
    epicsEnum16         d39nv;      /**< @brief PV Status */
    epicsEnum16         d40nv;      /**< @brief PV Status */
    epicsEnum16         d41nv;      /**< @brief PV Status */
    epicsEnum16         d42nv;      /**< @brief PV Status */
    epicsEnum16         d43nv;      /**< @brief PV Status */
    epicsEnum16         d44nv;      /**< @brief PV Status */
    epicsEnum16         d45nv;      /**< @brief PV Status */
    epicsEnum16         d46nv;      /**< @brief PV Status */
    epicsEnum16         d47nv;      /**< @brief PV Status */
    epicsEnum16         d48nv;      /**< @brief PV Status */
    epicsEnum16         d49nv;      /**< @brief PV Status */
    epicsEnum16         d50nv;      /**< @brief PV Status */
    epicsEnum16         d51nv;      /**< @brief PV Status */
    epicsEnum16         d52nv;      /**< @brief PV Status */
    epicsEnum16         d53nv;      /**< @brief PV Status */
    epicsEnum16         d54nv;      /**< @brief PV Status */
    epicsEnum16         d55nv;      /**< @brief PV Status */
    epicsEnum16         d56nv;      /**< @brief PV Status */
    epicsEnum16         d57nv;      /**< @brief PV Status */
    epicsEnum16         d58nv;      /**< @brief PV Status */
    epicsEnum16         d59nv;      /**< @brief PV Status */
    epicsEnum16         d60nv;      /**< @brief PV Status */
    epicsEnum16         d61nv;      /**< @brief PV Status */
    epicsEnum16         d62nv;      /**< @brief PV Status */
    epicsEnum16         d63nv;      /**< @brief PV Status */
    epicsEnum16         d64nv;      /**< @brief PV Status */
    epicsEnum16         d65nv;      /**< @brief PV Status */
    epicsEnum16         d66nv;      /**< @brief PV Status */
    epicsEnum16         d67nv;      /**< @brief PV Status */
    epicsEnum16         d68nv;      /**< @brief PV Status */
    epicsEnum16         d69nv;      /**< @brief PV Status */
    epicsEnum16         d70nv;      /**< @brief PV Status */
    epicsEnum16         t1nv;       /**< @brief T1  PV Status */
    epicsEnum16         t2nv;       /**< @brief T2  PV Status */
    epicsEnum16         t3nv;       /**< @brief T3  PV Status */
    epicsEnum16         t4nv;       /**< @brief T4  PV Status */
    epicsEnum16         a1nv;       /**< @brief A1  PV Status */
    epicsEnum16         bsnv;       /**< @brief BeforeScan PV Status */
    epicsEnum16         asnv;       /**< @brief After Scan PV Status */
    epicsFloat64        p1pp;       /**< @brief P1 Previous Position */
    epicsFloat64        p1cv;       /**< @brief P1 Current Value */
    epicsFloat64        p1dv;       /**< @brief P1 Desired Value */
    epicsFloat64        p1lv;       /**< @brief P1 Last Value Posted */
    epicsFloat64        p1sp;       /**< @brief P1 Start Position */
    epicsFloat64        p1si;       /**< @brief P1 Step Increment */
    epicsFloat64        p1ep;       /**< @brief P1 End Position */
    epicsFloat64        p1cp;       /**< @brief P1 Center Position */
    epicsFloat64        p1wd;       /**< @brief P1 Scan Width */
    epicsFloat64        r1cv;       /**< @brief P1 Readback Value */
    epicsFloat64        r1lv;       /**< @brief P1 Rdbk Last Val Pst */
    epicsFloat64        r1dl;       /**< @brief P1 Readback Delta */
    epicsFloat64        p1hr;       /**< @brief P1 High Oper Range */
    epicsFloat64        p1lr;       /**< @brief P1 Low  Oper Range */
    double *         p1pa;          /**< @brief P1 Step Array */
    double *         p1ra;          /**< @brief P1 Readback Array */
    double *         p1ca;          /**< @brief P1 Current Readback Array */
    epicsEnum16         p1fs;       /**< @brief P1 Freeze Start Pos */
    epicsEnum16         p1fi;       /**< @brief P1 Freeze Step Inc */
    epicsEnum16         p1fe;       /**< @brief P1 Freeze End Pos */
    epicsEnum16         p1fc;       /**< @brief P1 Freeze Center Pos */
    epicsEnum16         p1fw;       /**< @brief P1 Freeze Width */
    epicsEnum16         p1sm;       /**< @brief P1 Step Mode */
    epicsEnum16         p1ar;       /**< @brief P1 Absolute/Relative */
    char                p1eu[16];   /**< @brief P1 Engineering Units */
    epicsInt16          p1pr;       /**< @brief P1 Display Precision */
    epicsFloat64        p2pp;       /**< @brief P2 Previous Position */
    epicsFloat64        p2cv;       /**< @brief P2 Current Value */
    epicsFloat64        p2dv;       /**< @brief P2 Desired Value */
    epicsFloat64        p2lv;       /**< @brief P2 Last Value Posted */
    epicsFloat64        p2sp;       /**< @brief P2 Start Position */
    epicsFloat64        p2si;       /**< @brief P2 Step Increment */
    epicsFloat64        p2ep;       /**< @brief P2 End Position */
    epicsFloat64        p2cp;       /**< @brief P2 Center Position */
    epicsFloat64        p2wd;       /**< @brief P2 Scan Width */
    epicsFloat64        r2cv;       /**< @brief P2 Readback Value */
    epicsFloat64        r2lv;       /**< @brief P2 Rdbk Last Val Pst */
    epicsFloat64        r2dl;       /**< @brief P2 Readback Delta */
    epicsFloat64        p2hr;       /**< @brief P2 High Oper Range */
    epicsFloat64        p2lr;       /**< @brief P2 Low  Oper Range */
    double *         p2pa;          /**< @brief P2 Step Array */
    double *         p2ra;          /**< @brief P2 Readback Array */
    double *         p2ca;          /**< @brief P2 Current Readback Array */
    epicsEnum16         p2fs;       /**< @brief P2 Freeze Start Pos */
    epicsEnum16         p2fi;       /**< @brief P2 Freeze Step Inc */
    epicsEnum16         p2fe;       /**< @brief P2 Freeze End Pos */
    epicsEnum16         p2fc;       /**< @brief P2 Freeze Center Pos */
    epicsEnum16         p2fw;       /**< @brief P2 Freeze Width */
    epicsEnum16         p2sm;       /**< @brief P2 Step Mode */
    epicsEnum16         p2ar;       /**< @brief P2 Absolute/Relative */
    char                p2eu[16];   /**< @brief P2 Engineering Units */
    epicsInt16          p2pr;       /**< @brief P2 Display Precision */
    epicsFloat64        p3pp;       /**< @brief P3 Previous Position */
    epicsFloat64        p3cv;       /**< @brief P3 Current Value */
    epicsFloat64        p3dv;       /**< @brief P3 Desired Value */
    epicsFloat64        p3lv;       /**< @brief P3 Last Value Posted */
    epicsFloat64        p3sp;       /**< @brief P3 Start Position */
    epicsFloat64        p3si;       /**< @brief P3 Step Increment */
    epicsFloat64        p3ep;       /**< @brief P3 End Position */
    epicsFloat64        p3cp;       /**< @brief P3 Center Position */
    epicsFloat64        p3wd;       /**< @brief P3 Scan Width */
    epicsFloat64        r3cv;       /**< @brief P3 Readback Value */
    epicsFloat64        r3lv;       /**< @brief P3 Rdbk Last Val Pst */
    epicsFloat64        r3dl;       /**< @brief P3 Readback Delta */
    epicsFloat64        p3hr;       /**< @brief P3 High Oper Range */
    epicsFloat64        p3lr;       /**< @brief P3 Low  Oper Range */
    double *         p3pa;          /**< @brief P3 Step Array */
    double *         p3ra;          /**< @brief P3 Readback Array */
    double *         p3ca;          /**< @brief P3 Current Readback Array */
    epicsEnum16         p3fs;       /**< @brief P3 Freeze Start Pos */
    epicsEnum16         p3fi;       /**< @brief P3 Freeze Step Inc */
    epicsEnum16         p3fe;       /**< @brief P3 Freeze End Pos */
    epicsEnum16         p3fc;       /**< @brief P3 Freeze Center Pos */
    epicsEnum16         p3fw;       /**< @brief P3 Freeze Width */
    epicsEnum16         p3sm;       /**< @brief P3 Step Mode */
    epicsEnum16         p3ar;       /**< @brief P3 Absolute/Relative */
    char                p3eu[16];   /**< @brief P3 Engineering Units */
    epicsInt16          p3pr;       /**< @brief P3 Display Precision */
    epicsFloat64        p4pp;       /**< @brief P4 Previous Position */
    epicsFloat64        p4cv;       /**< @brief P4 Current Value */
    epicsFloat64        p4dv;       /**< @brief P4 Desired Value */
    epicsFloat64        p4lv;       /**< @brief P4 Last Value Posted */
    epicsFloat64        p4sp;       /**< @brief P4 Start Position */
    epicsFloat64        p4si;       /**< @brief P4 Step Increment */
    epicsFloat64        p4ep;       /**< @brief P4 End Position */
    epicsFloat64        p4cp;       /**< @brief P4 Center Position */
    epicsFloat64        p4wd;       /**< @brief P4 Scan Width */
    epicsFloat64        r4cv;       /**< @brief P4 Readback Value */
    epicsFloat64        r4lv;       /**< @brief P4 Rdbk Last Val Pst */
    epicsFloat64        r4dl;       /**< @brief P4 Readback Delta */
    epicsFloat64        p4hr;       /**< @brief P4 High Oper Range */
    epicsFloat64        p4lr;       /**< @brief P4 Low  Oper Range */
    double *         p4pa;          /**< @brief P4 Step Array */
    double *         p4ra;          /**< @brief P4 Readback Array */
    double *         p4ca;          /**< @brief P4 Current Readback Array */
    epicsEnum16         p4fs;       /**< @brief P4 Freeze Start Pos */
    epicsEnum16         p4fi;       /**< @brief P4 Freeze Step Inc */
    epicsEnum16         p4fe;       /**< @brief P4 Freeze End Pos */
    epicsEnum16         p4fc;       /**< @brief P4 Freeze Center Pos */
    epicsEnum16         p4fw;       /**< @brief P4 Freeze Width */
    epicsEnum16         p4sm;       /**< @brief P4 Step Mode */
    epicsEnum16         p4ar;       /**< @brief P4 Absolute/Relative */
    char                p4eu[16];   /**< @brief P4 Engineering Units */
    epicsInt16          p4pr;       /**< @brief P4 Display Precision */
    epicsFloat64        d01hr;      /**< @brief High Oper Range */
    epicsFloat64        d01lr;      /**< @brief Low  Oper Range */
    float *          d01da;         /**< @brief Data Array */
    float *          d01ca;         /**< @brief Current Data Array */
    epicsFloat32        d01cv;      /**< @brief Current Value */
    epicsFloat32        d01lv;      /**< @brief Last Value Posted */
    epicsUInt32         d01ne;      /**< @brief # of Elements/Pt */
    char                d01eu[16];  /**< @brief Engineering Units */
    epicsInt16          d01pr;      /**< @brief Display Precision */
    epicsFloat64        d02hr;      /**< @brief High Oper Range */
    epicsFloat64        d02lr;      /**< @brief Low  Oper Range */
    float *          d02da;         /**< @brief Data Array */
    float *          d02ca;         /**< @brief Current Data Array */
    epicsFloat32        d02cv;      /**< @brief Current Value */
    epicsFloat32        d02lv;      /**< @brief Last Value Posted */
    epicsUInt32         d02ne;      /**< @brief # of Elements/Pt */
    char                d02eu[16];  /**< @brief Engineering Units */
    epicsInt16          d02pr;      /**< @brief Display Precision */
    epicsFloat64        d03hr;      /**< @brief High Oper Range */
    epicsFloat64        d03lr;      /**< @brief Low  Oper Range */
    float *          d03da;         /**< @brief Data Array */
    float *          d03ca;         /**< @brief Current Data Array */
    epicsFloat32        d03cv;      /**< @brief Current Value */
    epicsFloat32        d03lv;      /**< @brief Last Value Posted */
    epicsUInt32         d03ne;      /**< @brief # of Elements/Pt */
    char                d03eu[16];  /**< @brief Engineering Units */
    epicsInt16          d03pr;      /**< @brief Display Precision */
    epicsFloat64        d04hr;      /**< @brief High Oper Range */
    epicsFloat64        d04lr;      /**< @brief Low  Oper Range */
    float *          d04da;         /**< @brief Data Array */
    float *          d04ca;         /**< @brief Current Data Array */
    epicsFloat32        d04cv;      /**< @brief Current Value */
    epicsFloat32        d04lv;      /**< @brief Last Value Posted */
    epicsUInt32         d04ne;      /**< @brief # of Elements/Pt */
    char                d04eu[16];  /**< @brief Engineering Units */
    epicsInt16          d04pr;      /**< @brief Display Precision */
    epicsFloat64        d05hr;      /**< @brief High Oper Range */
    epicsFloat64        d05lr;      /**< @brief Low  Oper Range */
    float *          d05da;         /**< @brief Data Array */
    float *          d05ca;         /**< @brief Current Data Array */
    epicsFloat32        d05cv;      /**< @brief Current Value */
    epicsFloat32        d05lv;      /**< @brief Last Value Posted */
    epicsUInt32         d05ne;      /**< @brief # of Elements/Pt */
    char                d05eu[16];  /**< @brief Engineering Units */
    epicsInt16          d05pr;      /**< @brief Display Precision */
    epicsFloat64        d06hr;      /**< @brief High Oper Range */
    epicsFloat64        d06lr;      /**< @brief Low  Oper Range */
    float *          d06da;         /**< @brief Data Array */
    float *          d06ca;         /**< @brief Current Data Array */
    epicsFloat32        d06cv;      /**< @brief Current Value */
    epicsFloat32        d06lv;      /**< @brief Last Value Posted */
    epicsUInt32         d06ne;      /**< @brief # of Elements/Pt */
    char                d06eu[16];  /**< @brief Engineering Units */
    epicsInt16          d06pr;      /**< @brief Display Precision */
    epicsFloat64        d07hr;      /**< @brief High Oper Range */
    epicsFloat64        d07lr;      /**< @brief Low  Oper Range */
    float *          d07da;         /**< @brief Data Array */
    float *          d07ca;         /**< @brief Current Data Array */
    epicsFloat32        d07cv;      /**< @brief Current Value */
    epicsFloat32        d07lv;      /**< @brief Last Value Posted */
    epicsUInt32         d07ne;      /**< @brief # of Elements/Pt */
    char                d07eu[16];  /**< @brief Engineering Units */
    epicsInt16          d07pr;      /**< @brief Display Precision */
    epicsFloat64        d08hr;      /**< @brief High Oper Range */
    epicsFloat64        d08lr;      /**< @brief Low  Oper Range */
    float *          d08da;         /**< @brief Data Array */
    float *          d08ca;         /**< @brief Current Data Array */
    epicsFloat32        d08cv;      /**< @brief Current Value */
    epicsFloat32        d08lv;      /**< @brief Last Value Posted */
    epicsUInt32         d08ne;      /**< @brief # of Elements/Pt */
    char                d08eu[16];  /**< @brief Engineering Units */
    epicsInt16          d08pr;      /**< @brief Display Precision */
    epicsFloat64        d09hr;      /**< @brief High Oper Range */
    epicsFloat64        d09lr;      /**< @brief Low  Oper Range */
    float *          d09da;         /**< @brief Data Array */
    float *          d09ca;         /**< @brief Current Data Array */
    epicsFloat32        d09cv;      /**< @brief Current Value */
    epicsFloat32        d09lv;      /**< @brief Last Value Posted */
    epicsUInt32         d09ne;      /**< @brief # of Elements/Pt */
    char                d09eu[16];  /**< @brief Engineering Units */
    epicsInt16          d09pr;      /**< @brief Display Precision */
    epicsFloat64        d10hr;      /**< @brief High Oper Range */
    epicsFloat64        d10lr;      /**< @brief Low  Oper Range */
    float *          d10da;         /**< @brief Data Array */
    float *          d10ca;         /**< @brief Current Data Array */
    epicsFloat32        d10cv;      /**< @brief Current Value */
    epicsFloat32        d10lv;      /**< @brief Last Value Posted */
    epicsUInt32         d10ne;      /**< @brief # of Elements/Pt */
    char                d10eu[16];  /**< @brief Engineering Units */
    epicsInt16          d10pr;      /**< @brief Display Precision */
    epicsFloat64        d11hr;      /**< @brief High Oper Range */
    epicsFloat64        d11lr;      /**< @brief Low  Oper Range */
    float *          d11da;         /**< @brief Data Array */
    float *          d11ca;         /**< @brief Current Data Array */
    epicsFloat32        d11cv;      /**< @brief Current Value */
    epicsFloat32        d11lv;      /**< @brief Last Value Posted */
    epicsUInt32         d11ne;      /**< @brief # of Elements/Pt */
    char                d11eu[16];  /**< @brief Engineering Units */
    epicsInt16          d11pr;      /**< @brief Display Precision */
    epicsFloat64        d12hr;      /**< @brief High Oper Range */
    epicsFloat64        d12lr;      /**< @brief Low  Oper Range */
    float *          d12da;         /**< @brief Data Array */
    float *          d12ca;         /**< @brief Current Data Array */
    epicsFloat32        d12cv;      /**< @brief Current Value */
    epicsFloat32        d12lv;      /**< @brief Last Value Posted */
    epicsUInt32         d12ne;      /**< @brief # of Elements/Pt */
    char                d12eu[16];  /**< @brief Engineering Units */
    epicsInt16          d12pr;      /**< @brief Display Precision */
    epicsFloat64        d13hr;      /**< @brief High Oper Range */
    epicsFloat64        d13lr;      /**< @brief Low  Oper Range */
    float *          d13da;         /**< @brief Data Array */
    float *          d13ca;         /**< @brief Current Data Array */
    epicsFloat32        d13cv;      /**< @brief Current Value */
    epicsFloat32        d13lv;      /**< @brief Last Value Posted */
    epicsUInt32         d13ne;      /**< @brief # of Elements/Pt */
    char                d13eu[16];  /**< @brief Engineering Units */
    epicsInt16          d13pr;      /**< @brief Display Precision */
    epicsFloat64        d14hr;      /**< @brief High Oper Range */
    epicsFloat64        d14lr;      /**< @brief Low  Oper Range */
    float *          d14da;         /**< @brief Data Array */
    float *          d14ca;         /**< @brief Current Data Array */
    epicsFloat32        d14cv;      /**< @brief Current Value */
    epicsFloat32        d14lv;      /**< @brief Last Value Posted */
    epicsUInt32         d14ne;      /**< @brief # of Elements/Pt */
    char                d14eu[16];  /**< @brief Engineering Units */
    epicsInt16          d14pr;      /**< @brief Display Precision */
    epicsFloat64        d15hr;      /**< @brief High Oper Range */
    epicsFloat64        d15lr;      /**< @brief Low  Oper Range */
    float *          d15da;         /**< @brief Data Array */
    float *          d15ca;         /**< @brief Current Data Array */
    epicsFloat32        d15cv;      /**< @brief Current Value */
    epicsFloat32        d15lv;      /**< @brief Last Value Posted */
    epicsUInt32         d15ne;      /**< @brief # of Elements/Pt */
    char                d15eu[16];  /**< @brief Engineering Units */
    epicsInt16          d15pr;      /**< @brief Display Precision */
    epicsFloat64        d16hr;      /**< @brief High Oper Range */
    epicsFloat64        d16lr;      /**< @brief Low  Oper Range */
    float *          d16da;         /**< @brief Data Array */
    float *          d16ca;         /**< @brief Current Data Array */
    epicsFloat32        d16cv;      /**< @brief Current Value */
    epicsFloat32        d16lv;      /**< @brief Last Value Posted */
    epicsUInt32         d16ne;      /**< @brief # of Elements/Pt */
    char                d16eu[16];  /**< @brief Engineering Units */
    epicsInt16          d16pr;      /**< @brief Display Precision */
    epicsFloat64        d17hr;      /**< @brief High Oper Range */
    epicsFloat64        d17lr;      /**< @brief Low  Oper Range */
    float *          d17da;         /**< @brief Data Array */
    float *          d17ca;         /**< @brief Current Data Array */
    epicsFloat32        d17cv;      /**< @brief Current Value */
    epicsFloat32        d17lv;      /**< @brief Last Value Posted */
    epicsUInt32         d17ne;      /**< @brief # of Elements/Pt */
    char                d17eu[16];  /**< @brief Engineering Units */
    epicsInt16          d17pr;      /**< @brief Display Precision */
    epicsFloat64        d18hr;      /**< @brief High Oper Range */
    epicsFloat64        d18lr;      /**< @brief Low  Oper Range */
    float *          d18da;         /**< @brief Data Array */
    float *          d18ca;         /**< @brief Current Data Array */
    epicsFloat32        d18cv;      /**< @brief Current Value */
    epicsFloat32        d18lv;      /**< @brief Last Value Posted */
    epicsUInt32         d18ne;      /**< @brief # of Elements/Pt */
    char                d18eu[16];  /**< @brief Engineering Units */
    epicsInt16          d18pr;      /**< @brief Display Precision */
    epicsFloat64        d19hr;      /**< @brief High Oper Range */
    epicsFloat64        d19lr;      /**< @brief Low  Oper Range */
    float *          d19da;         /**< @brief Data Array */
    float *          d19ca;         /**< @brief Current Data Array */
    epicsFloat32        d19cv;      /**< @brief Current Value */
    epicsFloat32        d19lv;      /**< @brief Last Value Posted */
    epicsUInt32         d19ne;      /**< @brief # of Elements/Pt */
    char                d19eu[16];  /**< @brief Engineering Units */
    epicsInt16          d19pr;      /**< @brief Display Precision */
    epicsFloat64        d20hr;      /**< @brief High Oper Range */
    epicsFloat64        d20lr;      /**< @brief Low  Oper Range */
    float *          d20da;         /**< @brief Data Array */
    float *          d20ca;         /**< @brief Current Data Array */
    epicsFloat32        d20cv;      /**< @brief Current Value */
    epicsFloat32        d20lv;      /**< @brief Last Value Posted */
    epicsUInt32         d20ne;      /**< @brief # of Elements/Pt */
    char                d20eu[16];  /**< @brief Engineering Units */
    epicsInt16          d20pr;      /**< @brief Display Precision */
    epicsFloat64        d21hr;      /**< @brief High Oper Range */
    epicsFloat64        d21lr;      /**< @brief Low  Oper Range */
    float *          d21da;         /**< @brief Data Array */
    float *          d21ca;         /**< @brief Current Data Array */
    epicsFloat32        d21cv;      /**< @brief Current Value */
    epicsFloat32        d21lv;      /**< @brief Last Value Posted */
    epicsUInt32         d21ne;      /**< @brief # of Elements/Pt */
    char                d21eu[16];  /**< @brief Engineering Units */
    epicsInt16          d21pr;      /**< @brief Display Precision */
    epicsFloat64        d22hr;      /**< @brief High Oper Range */
    epicsFloat64        d22lr;      /**< @brief Low  Oper Range */
    float *          d22da;         /**< @brief Data Array */
    float *          d22ca;         /**< @brief Current Data Array */
    epicsFloat32        d22cv;      /**< @brief Current Value */
    epicsFloat32        d22lv;      /**< @brief Last Value Posted */
    epicsUInt32         d22ne;      /**< @brief # of Elements/Pt */
    char                d22eu[16];  /**< @brief Engineering Units */
    epicsInt16          d22pr;      /**< @brief Display Precision */
    epicsFloat64        d23hr;      /**< @brief High Oper Range */
    epicsFloat64        d23lr;      /**< @brief Low  Oper Range */
    float *          d23da;         /**< @brief Data Array */
    float *          d23ca;         /**< @brief Current Data Array */
    epicsFloat32        d23cv;      /**< @brief Current Value */
    epicsFloat32        d23lv;      /**< @brief Last Value Posted */
    epicsUInt32         d23ne;      /**< @brief # of Elements/Pt */
    char                d23eu[16];  /**< @brief Engineering Units */
    epicsInt16          d23pr;      /**< @brief Display Precision */
    epicsFloat64        d24hr;      /**< @brief High Oper Range */
    epicsFloat64        d24lr;      /**< @brief Low  Oper Range */
    float *          d24da;         /**< @brief Data Array */
    float *          d24ca;         /**< @brief Current Data Array */
    epicsFloat32        d24cv;      /**< @brief Current Value */
    epicsFloat32        d24lv;      /**< @brief Last Value Posted */
    epicsUInt32         d24ne;      /**< @brief # of Elements/Pt */
    char                d24eu[16];  /**< @brief Engineering Units */
    epicsInt16          d24pr;      /**< @brief Display Precision */
    epicsFloat64        d25hr;      /**< @brief High Oper Range */
    epicsFloat64        d25lr;      /**< @brief Low  Oper Range */
    float *          d25da;         /**< @brief Data Array */
    float *          d25ca;         /**< @brief Current Data Array */
    epicsFloat32        d25cv;      /**< @brief Current Value */
    epicsFloat32        d25lv;      /**< @brief Last Value Posted */
    epicsUInt32         d25ne;      /**< @brief # of Elements/Pt */
    char                d25eu[16];  /**< @brief Engineering Units */
    epicsInt16          d25pr;      /**< @brief Display Precision */
    epicsFloat64        d26hr;      /**< @brief High Oper Range */
    epicsFloat64        d26lr;      /**< @brief Low  Oper Range */
    float *          d26da;         /**< @brief Data Array */
    float *          d26ca;         /**< @brief Current Data Array */
    epicsFloat32        d26cv;      /**< @brief Current Value */
    epicsFloat32        d26lv;      /**< @brief Last Value Posted */
    epicsUInt32         d26ne;      /**< @brief # of Elements/Pt */
    char                d26eu[16];  /**< @brief Engineering Units */
    epicsInt16          d26pr;      /**< @brief Display Precision */
    epicsFloat64        d27hr;      /**< @brief High Oper Range */
    epicsFloat64        d27lr;      /**< @brief Low  Oper Range */
    float *          d27da;         /**< @brief Data Array */
    float *          d27ca;         /**< @brief Current Data Array */
    epicsFloat32        d27cv;      /**< @brief Current Value */
    epicsFloat32        d27lv;      /**< @brief Last Value Posted */
    epicsUInt32         d27ne;      /**< @brief # of Elements/Pt */
    char                d27eu[16];  /**< @brief Engineering Units */
    epicsInt16          d27pr;      /**< @brief Display Precision */
    epicsFloat64        d28hr;      /**< @brief High Oper Range */
    epicsFloat64        d28lr;      /**< @brief Low  Oper Range */
    float *          d28da;         /**< @brief Data Array */
    float *          d28ca;         /**< @brief Current Data Array */
    epicsFloat32        d28cv;      /**< @brief Current Value */
    epicsFloat32        d28lv;      /**< @brief Last Value Posted */
    epicsUInt32         d28ne;      /**< @brief # of Elements/Pt */
    char                d28eu[16];  /**< @brief Engineering Units */
    epicsInt16          d28pr;      /**< @brief Display Precision */
    epicsFloat64        d29hr;      /**< @brief High Oper Range */
    epicsFloat64        d29lr;      /**< @brief Low  Oper Range */
    float *          d29da;         /**< @brief Data Array */
    float *          d29ca;         /**< @brief Current Data Array */
    epicsFloat32        d29cv;      /**< @brief Current Value */
    epicsFloat32        d29lv;      /**< @brief Last Value Posted */
    epicsUInt32         d29ne;      /**< @brief # of Elements/Pt */
    char                d29eu[16];  /**< @brief Engineering Units */
    epicsInt16          d29pr;      /**< @brief Display Precision */
    epicsFloat64        d30hr;      /**< @brief High Oper Range */
    epicsFloat64        d30lr;      /**< @brief Low  Oper Range */
    float *          d30da;         /**< @brief Data Array */
    float *          d30ca;         /**< @brief Current Data Array */
    epicsFloat32        d30cv;      /**< @brief Current Value */
    epicsFloat32        d30lv;      /**< @brief Last Value Posted */
    epicsUInt32         d30ne;      /**< @brief # of Elements/Pt */
    char                d30eu[16];  /**< @brief Engineering Units */
    epicsInt16          d30pr;      /**< @brief Display Precision */
    epicsFloat64        d31hr;      /**< @brief High Oper Range */
    epicsFloat64        d31lr;      /**< @brief Low  Oper Range */
    float *          d31da;         /**< @brief Data Array */
    float *          d31ca;         /**< @brief Current Data Array */
    epicsFloat32        d31cv;      /**< @brief Current Value */
    epicsFloat32        d31lv;      /**< @brief Last Value Posted */
    epicsUInt32         d31ne;      /**< @brief # of Elements/Pt */
    char                d31eu[16];  /**< @brief Engineering Units */
    epicsInt16          d31pr;      /**< @brief Display Precision */
    epicsFloat64        d32hr;      /**< @brief High Oper Range */
    epicsFloat64        d32lr;      /**< @brief Low  Oper Range */
    float *          d32da;         /**< @brief Data Array */
    float *          d32ca;         /**< @brief Current Data Array */
    epicsFloat32        d32cv;      /**< @brief Current Value */
    epicsFloat32        d32lv;      /**< @brief Last Value Posted */
    epicsUInt32         d32ne;      /**< @brief # of Elements/Pt */
    char                d32eu[16];  /**< @brief Engineering Units */
    epicsInt16          d32pr;      /**< @brief Display Precision */
    epicsFloat64        d33hr;      /**< @brief High Oper Range */
    epicsFloat64        d33lr;      /**< @brief Low  Oper Range */
    float *          d33da;         /**< @brief Data Array */
    float *          d33ca;         /**< @brief Current Data Array */
    epicsFloat32        d33cv;      /**< @brief Current Value */
    epicsFloat32        d33lv;      /**< @brief Last Value Posted */
    epicsUInt32         d33ne;      /**< @brief # of Elements/Pt */
    char                d33eu[16];  /**< @brief Engineering Units */
    epicsInt16          d33pr;      /**< @brief Display Precision */
    epicsFloat64        d34hr;      /**< @brief High Oper Range */
    epicsFloat64        d34lr;      /**< @brief Low  Oper Range */
    float *          d34da;         /**< @brief Data Array */
    float *          d34ca;         /**< @brief Current Data Array */
    epicsFloat32        d34cv;      /**< @brief Current Value */
    epicsFloat32        d34lv;      /**< @brief Last Value Posted */
    epicsUInt32         d34ne;      /**< @brief # of Elements/Pt */
    char                d34eu[16];  /**< @brief Engineering Units */
    epicsInt16          d34pr;      /**< @brief Display Precision */
    epicsFloat64        d35hr;      /**< @brief High Oper Range */
    epicsFloat64        d35lr;      /**< @brief Low  Oper Range */
    float *          d35da;         /**< @brief Data Array */
    float *          d35ca;         /**< @brief Current Data Array */
    epicsFloat32        d35cv;      /**< @brief Current Value */
    epicsFloat32        d35lv;      /**< @brief Last Value Posted */
    epicsUInt32         d35ne;      /**< @brief # of Elements/Pt */
    char                d35eu[16];  /**< @brief Engineering Units */
    epicsInt16          d35pr;      /**< @brief Display Precision */
    epicsFloat64        d36hr;      /**< @brief High Oper Range */
    epicsFloat64        d36lr;      /**< @brief Low  Oper Range */
    float *          d36da;         /**< @brief Data Array */
    float *          d36ca;         /**< @brief Current Data Array */
    epicsFloat32        d36cv;      /**< @brief Current Value */
    epicsFloat32        d36lv;      /**< @brief Last Value Posted */
    epicsUInt32         d36ne;      /**< @brief # of Elements/Pt */
    char                d36eu[16];  /**< @brief Engineering Units */
    epicsInt16          d36pr;      /**< @brief Display Precision */
    epicsFloat64        d37hr;      /**< @brief High Oper Range */
    epicsFloat64        d37lr;      /**< @brief Low  Oper Range */
    float *          d37da;         /**< @brief Data Array */
    float *          d37ca;         /**< @brief Current Data Array */
    epicsFloat32        d37cv;      /**< @brief Current Value */
    epicsFloat32        d37lv;      /**< @brief Last Value Posted */
    epicsUInt32         d37ne;      /**< @brief # of Elements/Pt */
    char                d37eu[16];  /**< @brief Engineering Units */
    epicsInt16          d37pr;      /**< @brief Display Precision */
    epicsFloat64        d38hr;      /**< @brief High Oper Range */
    epicsFloat64        d38lr;      /**< @brief Low  Oper Range */
    float *          d38da;         /**< @brief Data Array */
    float *          d38ca;         /**< @brief Current Data Array */
    epicsFloat32        d38cv;      /**< @brief Current Value */
    epicsFloat32        d38lv;      /**< @brief Last Value Posted */
    epicsUInt32         d38ne;      /**< @brief # of Elements/Pt */
    char                d38eu[16];  /**< @brief Engineering Units */
    epicsInt16          d38pr;      /**< @brief Display Precision */
    epicsFloat64        d39hr;      /**< @brief High Oper Range */
    epicsFloat64        d39lr;      /**< @brief Low  Oper Range */
    float *          d39da;         /**< @brief Data Array */
    float *          d39ca;         /**< @brief Current Data Array */
    epicsFloat32        d39cv;      /**< @brief Current Value */
    epicsFloat32        d39lv;      /**< @brief Last Value Posted */
    epicsUInt32         d39ne;      /**< @brief # of Elements/Pt */
    char                d39eu[16];  /**< @brief Engineering Units */
    epicsInt16          d39pr;      /**< @brief Display Precision */
    epicsFloat64        d40hr;      /**< @brief High Oper Range */
    epicsFloat64        d40lr;      /**< @brief Low  Oper Range */
    float *          d40da;         /**< @brief Data Array */
    float *          d40ca;         /**< @brief Current Data Array */
    epicsFloat32        d40cv;      /**< @brief Current Value */
    epicsFloat32        d40lv;      /**< @brief Last Value Posted */
    epicsUInt32         d40ne;      /**< @brief # of Elements/Pt */
    char                d40eu[16];  /**< @brief Engineering Units */
    epicsInt16          d40pr;      /**< @brief Display Precision */
    epicsFloat64        d41hr;      /**< @brief High Oper Range */
    epicsFloat64        d41lr;      /**< @brief Low  Oper Range */
    float *          d41da;         /**< @brief Data Array */
    float *          d41ca;         /**< @brief Current Data Array */
    epicsFloat32        d41cv;      /**< @brief Current Value */
    epicsFloat32        d41lv;      /**< @brief Last Value Posted */
    epicsUInt32         d41ne;      /**< @brief # of Elements/Pt */
    char                d41eu[16];  /**< @brief Engineering Units */
    epicsInt16          d41pr;      /**< @brief Display Precision */
    epicsFloat64        d42hr;      /**< @brief High Oper Range */
    epicsFloat64        d42lr;      /**< @brief Low  Oper Range */
    float *          d42da;         /**< @brief Data Array */
    float *          d42ca;         /**< @brief Current Data Array */
    epicsFloat32        d42cv;      /**< @brief Current Value */
    epicsFloat32        d42lv;      /**< @brief Last Value Posted */
    epicsUInt32         d42ne;      /**< @brief # of Elements/Pt */
    char                d42eu[16];  /**< @brief Engineering Units */
    epicsInt16          d42pr;      /**< @brief Display Precision */
    epicsFloat64        d43hr;      /**< @brief High Oper Range */
    epicsFloat64        d43lr;      /**< @brief Low  Oper Range */
    float *          d43da;         /**< @brief Data Array */
    float *          d43ca;         /**< @brief Current Data Array */
    epicsFloat32        d43cv;      /**< @brief Current Value */
    epicsFloat32        d43lv;      /**< @brief Last Value Posted */
    epicsUInt32         d43ne;      /**< @brief # of Elements/Pt */
    char                d43eu[16];  /**< @brief Engineering Units */
    epicsInt16          d43pr;      /**< @brief Display Precision */
    epicsFloat64        d44hr;      /**< @brief High Oper Range */
    epicsFloat64        d44lr;      /**< @brief Low  Oper Range */
    float *          d44da;         /**< @brief Data Array */
    float *          d44ca;         /**< @brief Current Data Array */
    epicsFloat32        d44cv;      /**< @brief Current Value */
    epicsFloat32        d44lv;      /**< @brief Last Value Posted */
    epicsUInt32         d44ne;      /**< @brief # of Elements/Pt */
    char                d44eu[16];  /**< @brief Engineering Units */
    epicsInt16          d44pr;      /**< @brief Display Precision */
    epicsFloat64        d45hr;      /**< @brief High Oper Range */
    epicsFloat64        d45lr;      /**< @brief Low  Oper Range */
    float *          d45da;         /**< @brief Data Array */
    float *          d45ca;         /**< @brief Current Data Array */
    epicsFloat32        d45cv;      /**< @brief Current Value */
    epicsFloat32        d45lv;      /**< @brief Last Value Posted */
    epicsUInt32         d45ne;      /**< @brief # of Elements/Pt */
    char                d45eu[16];  /**< @brief Engineering Units */
    epicsInt16          d45pr;      /**< @brief Display Precision */
    epicsFloat64        d46hr;      /**< @brief High Oper Range */
    epicsFloat64        d46lr;      /**< @brief Low  Oper Range */
    float *          d46da;         /**< @brief Data Array */
    float *          d46ca;         /**< @brief Current Data Array */
    epicsFloat32        d46cv;      /**< @brief Current Value */
    epicsFloat32        d46lv;      /**< @brief Last Value Posted */
    epicsUInt32         d46ne;      /**< @brief # of Elements/Pt */
    char                d46eu[16];  /**< @brief Engineering Units */
    epicsInt16          d46pr;      /**< @brief Display Precision */
    epicsFloat64        d47hr;      /**< @brief High Oper Range */
    epicsFloat64        d47lr;      /**< @brief Low  Oper Range */
    float *          d47da;         /**< @brief Data Array */
    float *          d47ca;         /**< @brief Current Data Array */
    epicsFloat32        d47cv;      /**< @brief Current Value */
    epicsFloat32        d47lv;      /**< @brief Last Value Posted */
    epicsUInt32         d47ne;      /**< @brief # of Elements/Pt */
    char                d47eu[16];  /**< @brief Engineering Units */
    epicsInt16          d47pr;      /**< @brief Display Precision */
    epicsFloat64        d48hr;      /**< @brief High Oper Range */
    epicsFloat64        d48lr;      /**< @brief Low  Oper Range */
    float *          d48da;         /**< @brief Data Array */
    float *          d48ca;         /**< @brief Current Data Array */
    epicsFloat32        d48cv;      /**< @brief Current Value */
    epicsFloat32        d48lv;      /**< @brief Last Value Posted */
    epicsUInt32         d48ne;      /**< @brief # of Elements/Pt */
    char                d48eu[16];  /**< @brief Engineering Units */
    epicsInt16          d48pr;      /**< @brief Display Precision */
    epicsFloat64        d49hr;      /**< @brief High Oper Range */
    epicsFloat64        d49lr;      /**< @brief Low  Oper Range */
    float *          d49da;         /**< @brief Data Array */
    float *          d49ca;         /**< @brief Current Data Array */
    epicsFloat32        d49cv;      /**< @brief Current Value */
    epicsFloat32        d49lv;      /**< @brief Last Value Posted */
    epicsUInt32         d49ne;      /**< @brief # of Elements/Pt */
    char                d49eu[16];  /**< @brief Engineering Units */
    epicsInt16          d49pr;      /**< @brief Display Precision */
    epicsFloat64        d50hr;      /**< @brief High Oper Range */
    epicsFloat64        d50lr;      /**< @brief Low  Oper Range */
    float *          d50da;         /**< @brief Data Array */
    float *          d50ca;         /**< @brief Current Data Array */
    epicsFloat32        d50cv;      /**< @brief Current Value */
    epicsFloat32        d50lv;      /**< @brief Last Value Posted */
    epicsUInt32         d50ne;      /**< @brief # of Elements/Pt */
    char                d50eu[16];  /**< @brief Engineering Units */
    epicsInt16          d50pr;      /**< @brief Display Precision */
    epicsFloat64        d51hr;      /**< @brief High Oper Range */
    epicsFloat64        d51lr;      /**< @brief Low  Oper Range */
    float *          d51da;         /**< @brief Data Array */
    float *          d51ca;         /**< @brief Current Data Array */
    epicsFloat32        d51cv;      /**< @brief Current Value */
    epicsFloat32        d51lv;      /**< @brief Last Value Posted */
    epicsUInt32         d51ne;      /**< @brief # of Elements/Pt */
    char                d51eu[16];  /**< @brief Engineering Units */
    epicsInt16          d51pr;      /**< @brief Display Precision */
    epicsFloat64        d52hr;      /**< @brief High Oper Range */
    epicsFloat64        d52lr;      /**< @brief Low  Oper Range */
    float *          d52da;         /**< @brief Data Array */
    float *          d52ca;         /**< @brief Current Data Array */
    epicsFloat32        d52cv;      /**< @brief Current Value */
    epicsFloat32        d52lv;      /**< @brief Last Value Posted */
    epicsUInt32         d52ne;      /**< @brief # of Elements/Pt */
    char                d52eu[16];  /**< @brief Engineering Units */
    epicsInt16          d52pr;      /**< @brief Display Precision */
    epicsFloat64        d53hr;      /**< @brief High Oper Range */
    epicsFloat64        d53lr;      /**< @brief Low  Oper Range */
    float *          d53da;         /**< @brief Data Array */
    float *          d53ca;         /**< @brief Current Data Array */
    epicsFloat32        d53cv;      /**< @brief Current Value */
    epicsFloat32        d53lv;      /**< @brief Last Value Posted */
    epicsUInt32         d53ne;      /**< @brief # of Elements/Pt */
    char                d53eu[16];  /**< @brief Engineering Units */
    epicsInt16          d53pr;      /**< @brief Display Precision */
    epicsFloat64        d54hr;      /**< @brief High Oper Range */
    epicsFloat64        d54lr;      /**< @brief Low  Oper Range */
    float *          d54da;         /**< @brief Data Array */
    float *          d54ca;         /**< @brief Current Data Array */
    epicsFloat32        d54cv;      /**< @brief Current Value */
    epicsFloat32        d54lv;      /**< @brief Last Value Posted */
    epicsUInt32         d54ne;      /**< @brief # of Elements/Pt */
    char                d54eu[16];  /**< @brief Engineering Units */
    epicsInt16          d54pr;      /**< @brief Display Precision */
    epicsFloat64        d55hr;      /**< @brief High Oper Range */
    epicsFloat64        d55lr;      /**< @brief Low  Oper Range */
    float *          d55da;         /**< @brief Data Array */
    float *          d55ca;         /**< @brief Current Data Array */
    epicsFloat32        d55cv;      /**< @brief Current Value */
    epicsFloat32        d55lv;      /**< @brief Last Value Posted */
    epicsUInt32         d55ne;      /**< @brief # of Elements/Pt */
    char                d55eu[16];  /**< @brief Engineering Units */
    epicsInt16          d55pr;      /**< @brief Display Precision */
    epicsFloat64        d56hr;      /**< @brief High Oper Range */
    epicsFloat64        d56lr;      /**< @brief Low  Oper Range */
    float *          d56da;         /**< @brief Data Array */
    float *          d56ca;         /**< @brief Current Data Array */
    epicsFloat32        d56cv;      /**< @brief Current Value */
    epicsFloat32        d56lv;      /**< @brief Last Value Posted */
    epicsUInt32         d56ne;      /**< @brief # of Elements/Pt */
    char                d56eu[16];  /**< @brief Engineering Units */
    epicsInt16          d56pr;      /**< @brief Display Precision */
    epicsFloat64        d57hr;      /**< @brief High Oper Range */
    epicsFloat64        d57lr;      /**< @brief Low  Oper Range */
    float *          d57da;         /**< @brief Data Array */
    float *          d57ca;         /**< @brief Current Data Array */
    epicsFloat32        d57cv;      /**< @brief Current Value */
    epicsFloat32        d57lv;      /**< @brief Last Value Posted */
    epicsUInt32         d57ne;      /**< @brief # of Elements/Pt */
    char                d57eu[16];  /**< @brief Engineering Units */
    epicsInt16          d57pr;      /**< @brief Display Precision */
    epicsFloat64        d58hr;      /**< @brief High Oper Range */
    epicsFloat64        d58lr;      /**< @brief Low  Oper Range */
    float *          d58da;         /**< @brief Data Array */
    float *          d58ca;         /**< @brief Current Data Array */
    epicsFloat32        d58cv;      /**< @brief Current Value */
    epicsFloat32        d58lv;      /**< @brief Last Value Posted */
    epicsUInt32         d58ne;      /**< @brief # of Elements/Pt */
    char                d58eu[16];  /**< @brief Engineering Units */
    epicsInt16          d58pr;      /**< @brief Display Precision */
    epicsFloat64        d59hr;      /**< @brief High Oper Range */
    epicsFloat64        d59lr;      /**< @brief Low  Oper Range */
    float *          d59da;         /**< @brief Data Array */
    float *          d59ca;         /**< @brief Current Data Array */
    epicsFloat32        d59cv;      /**< @brief Current Value */
    epicsFloat32        d59lv;      /**< @brief Last Value Posted */
    epicsUInt32         d59ne;      /**< @brief # of Elements/Pt */
    char                d59eu[16];  /**< @brief Engineering Units */
    epicsInt16          d59pr;      /**< @brief Display Precision */
    epicsFloat64        d60hr;      /**< @brief High Oper Range */
    epicsFloat64        d60lr;      /**< @brief Low  Oper Range */
    float *          d60da;         /**< @brief Data Array */
    float *          d60ca;         /**< @brief Current Data Array */
    epicsFloat32        d60cv;      /**< @brief Current Value */
    epicsFloat32        d60lv;      /**< @brief Last Value Posted */
    epicsUInt32         d60ne;      /**< @brief # of Elements/Pt */
    char                d60eu[16];  /**< @brief Engineering Units */
    epicsInt16          d60pr;      /**< @brief Display Precision */
    epicsFloat64        d61hr;      /**< @brief High Oper Range */
    epicsFloat64        d61lr;      /**< @brief Low  Oper Range */
    float *          d61da;         /**< @brief Data Array */
    float *          d61ca;         /**< @brief Current Data Array */
    epicsFloat32        d61cv;      /**< @brief Current Value */
    epicsFloat32        d61lv;      /**< @brief Last Value Posted */
    epicsUInt32         d61ne;      /**< @brief # of Elements/Pt */
    char                d61eu[16];  /**< @brief Engineering Units */
    epicsInt16          d61pr;      /**< @brief Display Precision */
    epicsFloat64        d62hr;      /**< @brief High Oper Range */
    epicsFloat64        d62lr;      /**< @brief Low  Oper Range */
    float *          d62da;         /**< @brief Data Array */
    float *          d62ca;         /**< @brief Current Data Array */
    epicsFloat32        d62cv;      /**< @brief Current Value */
    epicsFloat32        d62lv;      /**< @brief Last Value Posted */
    epicsUInt32         d62ne;      /**< @brief # of Elements/Pt */
    char                d62eu[16];  /**< @brief Engineering Units */
    epicsInt16          d62pr;      /**< @brief Display Precision */
    epicsFloat64        d63hr;      /**< @brief High Oper Range */
    epicsFloat64        d63lr;      /**< @brief Low  Oper Range */
    float *          d63da;         /**< @brief Data Array */
    float *          d63ca;         /**< @brief Current Data Array */
    epicsFloat32        d63cv;      /**< @brief Current Value */
    epicsFloat32        d63lv;      /**< @brief Last Value Posted */
    epicsUInt32         d63ne;      /**< @brief # of Elements/Pt */
    char                d63eu[16];  /**< @brief Engineering Units */
    epicsInt16          d63pr;      /**< @brief Display Precision */
    epicsFloat64        d64hr;      /**< @brief High Oper Range */
    epicsFloat64        d64lr;      /**< @brief Low  Oper Range */
    float *          d64da;         /**< @brief Data Array */
    float *          d64ca;         /**< @brief Current Data Array */
    epicsFloat32        d64cv;      /**< @brief Current Value */
    epicsFloat32        d64lv;      /**< @brief Last Value Posted */
    epicsUInt32         d64ne;      /**< @brief # of Elements/Pt */
    char                d64eu[16];  /**< @brief Engineering Units */
    epicsInt16          d64pr;      /**< @brief Display Precision */
    epicsFloat64        d65hr;      /**< @brief High Oper Range */
    epicsFloat64        d65lr;      /**< @brief Low  Oper Range */
    float *          d65da;         /**< @brief Data Array */
    float *          d65ca;         /**< @brief Current Data Array */
    epicsFloat32        d65cv;      /**< @brief Current Value */
    epicsFloat32        d65lv;      /**< @brief Last Value Posted */
    epicsUInt32         d65ne;      /**< @brief # of Elements/Pt */
    char                d65eu[16];  /**< @brief Engineering Units */
    epicsInt16          d65pr;      /**< @brief Display Precision */
    epicsFloat64        d66hr;      /**< @brief High Oper Range */
    epicsFloat64        d66lr;      /**< @brief Low  Oper Range */
    float *          d66da;         /**< @brief Data Array */
    float *          d66ca;         /**< @brief Current Data Array */
    epicsFloat32        d66cv;      /**< @brief Current Value */
    epicsFloat32        d66lv;      /**< @brief Last Value Posted */
    epicsUInt32         d66ne;      /**< @brief # of Elements/Pt */
    char                d66eu[16];  /**< @brief Engineering Units */
    epicsInt16          d66pr;      /**< @brief Display Precision */
    epicsFloat64        d67hr;      /**< @brief High Oper Range */
    epicsFloat64        d67lr;      /**< @brief Low  Oper Range */
    float *          d67da;         /**< @brief Data Array */
    float *          d67ca;         /**< @brief Current Data Array */
    epicsFloat32        d67cv;      /**< @brief Current Value */
    epicsFloat32        d67lv;      /**< @brief Last Value Posted */
    epicsUInt32         d67ne;      /**< @brief # of Elements/Pt */
    char                d67eu[16];  /**< @brief Engineering Units */
    epicsInt16          d67pr;      /**< @brief Display Precision */
    epicsFloat64        d68hr;      /**< @brief High Oper Range */
    epicsFloat64        d68lr;      /**< @brief Low  Oper Range */
    float *          d68da;         /**< @brief Data Array */
    float *          d68ca;         /**< @brief Current Data Array */
    epicsFloat32        d68cv;      /**< @brief Current Value */
    epicsFloat32        d68lv;      /**< @brief Last Value Posted */
    epicsUInt32         d68ne;      /**< @brief # of Elements/Pt */
    char                d68eu[16];  /**< @brief Engineering Units */
    epicsInt16          d68pr;      /**< @brief Display Precision */
    epicsFloat64        d69hr;      /**< @brief High Oper Range */
    epicsFloat64        d69lr;      /**< @brief Low  Oper Range */
    float *          d69da;         /**< @brief Data Array */
    float *          d69ca;         /**< @brief Current Data Array */
    epicsFloat32        d69cv;      /**< @brief Current Value */
    epicsFloat32        d69lv;      /**< @brief Last Value Posted */
    epicsUInt32         d69ne;      /**< @brief # of Elements/Pt */
    char                d69eu[16];  /**< @brief Engineering Units */
    epicsInt16          d69pr;      /**< @brief Display Precision */
    epicsFloat64        d70hr;      /**< @brief High Oper Range */
    epicsFloat64        d70lr;      /**< @brief Low  Oper Range */
    float *          d70da;         /**< @brief Data Array */
    float *          d70ca;         /**< @brief Current Data Array */
    epicsFloat32        d70cv;      /**< @brief Current Value */
    epicsFloat32        d70lv;      /**< @brief Last Value Posted */
    epicsUInt32         d70ne;      /**< @brief # of Elements/Pt */
    char                d70eu[16];  /**< @brief Engineering Units */
    epicsInt16          d70pr;      /**< @brief Display Precision */
    epicsFloat32        t1cd;       /**< @brief T1 Cmnd */
    epicsFloat32        t2cd;       /**< @brief T2 Cmnd */
    epicsFloat32        t3cd;       /**< @brief T3 Cmnd */
    epicsFloat32        t4cd;       /**< @brief T4 Cmnd */
    epicsFloat32        a1cd;       /**< @brief A1 Cmnd */
    epicsFloat32        bscd;       /**< @brief Before Scan Cmnd */
    epicsFloat32        ascd;       /**< @brief After Scan Cmnd */
    epicsEnum16         paus;       /**< @brief Go/Pause control */
    epicsEnum16         lpau;       /**< @brief Last value of Go/Pause */
    epicsFloat32        pdly;       /**< @brief Positioner-settling delay */
    epicsFloat32        ddly;       /**< @brief Detector-settling delay */
    epicsFloat32        rdly;       /**< @brief Pause resume delay */
    epicsEnum16         faze;       /**< @brief Scan phase */
    epicsEnum16         acqm;       /**< @brief Acquisition mode */
    epicsEnum16         acqt;       /**< @brief Acquisition type */
    epicsEnum16         dstate;     /**< @brief Data state */
    epicsInt32          copyto;     /**< @brief Copy Last Pt Thru */
} sscanRecord;

typedef enum {
	sscanRecordNAME = 0,
	sscanRecordDESC = 1,
	sscanRecordASG = 2,
	sscanRecordSCAN = 3,
	sscanRecordPINI = 4,
	sscanRecordPHAS = 5,
	sscanRecordEVNT = 6,
	sscanRecordTSE = 7,
	sscanRecordTSEL = 8,
	sscanRecordDTYP = 9,
	sscanRecordDISV = 10,
	sscanRecordDISA = 11,
	sscanRecordSDIS = 12,
	sscanRecordMLOK = 13,
	sscanRecordMLIS = 14,
	sscanRecordBKLNK = 15,
	sscanRecordDISP = 16,
	sscanRecordPROC = 17,
	sscanRecordSTAT = 18,
	sscanRecordSEVR = 19,
	sscanRecordAMSG = 20,
	sscanRecordNSTA = 21,
	sscanRecordNSEV = 22,
	sscanRecordNAMSG = 23,
	sscanRecordACKS = 24,
	sscanRecordACKT = 25,
	sscanRecordDISS = 26,
	sscanRecordLCNT = 27,
	sscanRecordPACT = 28,
	sscanRecordPUTF = 29,
	sscanRecordRPRO = 30,
	sscanRecordASP = 31,
	sscanRecordPPN = 32,
	sscanRecordPPNR = 33,
	sscanRecordSPVT = 34,
	sscanRecordRSET = 35,
	sscanRecordDSET = 36,
	sscanRecordDPVT = 37,
	sscanRecordRDES = 38,
	sscanRecordLSET = 39,
	sscanRecordPRIO = 40,
	sscanRecordTPRO = 41,
	sscanRecordBKPT = 42,
	sscanRecordUDF = 43,
	sscanRecordUDFS = 44,
	sscanRecordTIME = 45,
	sscanRecordUTAG = 46,
	sscanRecordFLNK = 47,
	sscanRecordVERS = 48,
	sscanRecordVAL = 49,
	sscanRecordSMSG = 50,
	sscanRecordCMND = 51,
	sscanRecordALRT = 52,
	sscanRecordRPVT = 53,
	sscanRecordMPTS = 54,
	sscanRecordEXSC = 55,
	sscanRecordXSC = 56,
	sscanRecordPXSC = 57,
	sscanRecordBUSY = 58,
	sscanRecordKILL = 59,
	sscanRecordWAIT = 60,
	sscanRecordWCNT = 61,
	sscanRecordAWCT = 62,
	sscanRecordWTNG = 63,
	sscanRecordAWAIT = 64,
	sscanRecordAAWAIT = 65,
	sscanRecordDATA = 66,
	sscanRecordREFD = 67,
	sscanRecordNPTS = 68,
	sscanRecordFPTS = 69,
	sscanRecordFFO = 70,
	sscanRecordCPT = 71,
	sscanRecordBCPT = 72,
	sscanRecordDPT = 73,
	sscanRecordPCPT = 74,
	sscanRecordPASM = 75,
	sscanRecordTOLP = 76,
	sscanRecordTLAP = 77,
	sscanRecordATIME = 78,
	sscanRecordP1PV = 79,
	sscanRecordP2PV = 80,
	sscanRecordP3PV = 81,
	sscanRecordP4PV = 82,
	sscanRecordR1PV = 83,
	sscanRecordR2PV = 84,
	sscanRecordR3PV = 85,
	sscanRecordR4PV = 86,
	sscanRecordD01PV = 87,
	sscanRecordD02PV = 88,
	sscanRecordD03PV = 89,
	sscanRecordD04PV = 90,
	sscanRecordD05PV = 91,
	sscanRecordD06PV = 92,
	sscanRecordD07PV = 93,
	sscanRecordD08PV = 94,
	sscanRecordD09PV = 95,
	sscanRecordD10PV = 96,
	sscanRecordD11PV = 97,
	sscanRecordD12PV = 98,
	sscanRecordD13PV = 99,
	sscanRecordD14PV = 100,
	sscanRecordD15PV = 101,
	sscanRecordD16PV = 102,
	sscanRecordD17PV = 103,
	sscanRecordD18PV = 104,
	sscanRecordD19PV = 105,
	sscanRecordD20PV = 106,
	sscanRecordD21PV = 107,
	sscanRecordD22PV = 108,
	sscanRecordD23PV = 109,
	sscanRecordD24PV = 110,
	sscanRecordD25PV = 111,
	sscanRecordD26PV = 112,
	sscanRecordD27PV = 113,
	sscanRecordD28PV = 114,
	sscanRecordD29PV = 115,
	sscanRecordD30PV = 116,
	sscanRecordD31PV = 117,
	sscanRecordD32PV = 118,
	sscanRecordD33PV = 119,
	sscanRecordD34PV = 120,
	sscanRecordD35PV = 121,
	sscanRecordD36PV = 122,
	sscanRecordD37PV = 123,
	sscanRecordD38PV = 124,
	sscanRecordD39PV = 125,
	sscanRecordD40PV = 126,
	sscanRecordD41PV = 127,
	sscanRecordD42PV = 128,
	sscanRecordD43PV = 129,
	sscanRecordD44PV = 130,
	sscanRecordD45PV = 131,
	sscanRecordD46PV = 132,
	sscanRecordD47PV = 133,
	sscanRecordD48PV = 134,
	sscanRecordD49PV = 135,
	sscanRecordD50PV = 136,
	sscanRecordD51PV = 137,
	sscanRecordD52PV = 138,
	sscanRecordD53PV = 139,
	sscanRecordD54PV = 140,
	sscanRecordD55PV = 141,
	sscanRecordD56PV = 142,
	sscanRecordD57PV = 143,
	sscanRecordD58PV = 144,
	sscanRecordD59PV = 145,
	sscanRecordD60PV = 146,
	sscanRecordD61PV = 147,
	sscanRecordD62PV = 148,
	sscanRecordD63PV = 149,
	sscanRecordD64PV = 150,
	sscanRecordD65PV = 151,
	sscanRecordD66PV = 152,
	sscanRecordD67PV = 153,
	sscanRecordD68PV = 154,
	sscanRecordD69PV = 155,
	sscanRecordD70PV = 156,
	sscanRecordT1PV = 157,
	sscanRecordT2PV = 158,
	sscanRecordT3PV = 159,
	sscanRecordT4PV = 160,
	sscanRecordA1PV = 161,
	sscanRecordBSPV = 162,
	sscanRecordASPV = 163,
	sscanRecordBSWAIT = 164,
	sscanRecordASWAIT = 165,
	sscanRecordP1NV = 166,
	sscanRecordP2NV = 167,
	sscanRecordP3NV = 168,
	sscanRecordP4NV = 169,
	sscanRecordR1NV = 170,
	sscanRecordR2NV = 171,
	sscanRecordR3NV = 172,
	sscanRecordR4NV = 173,
	sscanRecordD01NV = 174,
	sscanRecordD02NV = 175,
	sscanRecordD03NV = 176,
	sscanRecordD04NV = 177,
	sscanRecordD05NV = 178,
	sscanRecordD06NV = 179,
	sscanRecordD07NV = 180,
	sscanRecordD08NV = 181,
	sscanRecordD09NV = 182,
	sscanRecordD10NV = 183,
	sscanRecordD11NV = 184,
	sscanRecordD12NV = 185,
	sscanRecordD13NV = 186,
	sscanRecordD14NV = 187,
	sscanRecordD15NV = 188,
	sscanRecordD16NV = 189,
	sscanRecordD17NV = 190,
	sscanRecordD18NV = 191,
	sscanRecordD19NV = 192,
	sscanRecordD20NV = 193,
	sscanRecordD21NV = 194,
	sscanRecordD22NV = 195,
	sscanRecordD23NV = 196,
	sscanRecordD24NV = 197,
	sscanRecordD25NV = 198,
	sscanRecordD26NV = 199,
	sscanRecordD27NV = 200,
	sscanRecordD28NV = 201,
	sscanRecordD29NV = 202,
	sscanRecordD30NV = 203,
	sscanRecordD31NV = 204,
	sscanRecordD32NV = 205,
	sscanRecordD33NV = 206,
	sscanRecordD34NV = 207,
	sscanRecordD35NV = 208,
	sscanRecordD36NV = 209,
	sscanRecordD37NV = 210,
	sscanRecordD38NV = 211,
	sscanRecordD39NV = 212,
	sscanRecordD40NV = 213,
	sscanRecordD41NV = 214,
	sscanRecordD42NV = 215,
	sscanRecordD43NV = 216,
	sscanRecordD44NV = 217,
	sscanRecordD45NV = 218,
	sscanRecordD46NV = 219,
	sscanRecordD47NV = 220,
	sscanRecordD48NV = 221,
	sscanRecordD49NV = 222,
	sscanRecordD50NV = 223,
	sscanRecordD51NV = 224,
	sscanRecordD52NV = 225,
	sscanRecordD53NV = 226,
	sscanRecordD54NV = 227,
	sscanRecordD55NV = 228,
	sscanRecordD56NV = 229,
	sscanRecordD57NV = 230,
	sscanRecordD58NV = 231,
	sscanRecordD59NV = 232,
	sscanRecordD60NV = 233,
	sscanRecordD61NV = 234,
	sscanRecordD62NV = 235,
	sscanRecordD63NV = 236,
	sscanRecordD64NV = 237,
	sscanRecordD65NV = 238,
	sscanRecordD66NV = 239,
	sscanRecordD67NV = 240,
	sscanRecordD68NV = 241,
	sscanRecordD69NV = 242,
	sscanRecordD70NV = 243,
	sscanRecordT1NV = 244,
	sscanRecordT2NV = 245,
	sscanRecordT3NV = 246,
	sscanRecordT4NV = 247,
	sscanRecordA1NV = 248,
	sscanRecordBSNV = 249,
	sscanRecordASNV = 250,
	sscanRecordP1PP = 251,
	sscanRecordP1CV = 252,
	sscanRecordP1DV = 253,
	sscanRecordP1LV = 254,
	sscanRecordP1SP = 255,
	sscanRecordP1SI = 256,
	sscanRecordP1EP = 257,
	sscanRecordP1CP = 258,
	sscanRecordP1WD = 259,
	sscanRecordR1CV = 260,
	sscanRecordR1LV = 261,
	sscanRecordR1DL = 262,
	sscanRecordP1HR = 263,
	sscanRecordP1LR = 264,
	sscanRecordP1PA = 265,
	sscanRecordP1RA = 266,
	sscanRecordP1CA = 267,
	sscanRecordP1FS = 268,
	sscanRecordP1FI = 269,
	sscanRecordP1FE = 270,
	sscanRecordP1FC = 271,
	sscanRecordP1FW = 272,
	sscanRecordP1SM = 273,
	sscanRecordP1AR = 274,
	sscanRecordP1EU = 275,
	sscanRecordP1PR = 276,
	sscanRecordP2PP = 277,
	sscanRecordP2CV = 278,
	sscanRecordP2DV = 279,
	sscanRecordP2LV = 280,
	sscanRecordP2SP = 281,
	sscanRecordP2SI = 282,
	sscanRecordP2EP = 283,
	sscanRecordP2CP = 284,
	sscanRecordP2WD = 285,
	sscanRecordR2CV = 286,
	sscanRecordR2LV = 287,
	sscanRecordR2DL = 288,
	sscanRecordP2HR = 289,
	sscanRecordP2LR = 290,
	sscanRecordP2PA = 291,
	sscanRecordP2RA = 292,
	sscanRecordP2CA = 293,
	sscanRecordP2FS = 294,
	sscanRecordP2FI = 295,
	sscanRecordP2FE = 296,
	sscanRecordP2FC = 297,
	sscanRecordP2FW = 298,
	sscanRecordP2SM = 299,
	sscanRecordP2AR = 300,
	sscanRecordP2EU = 301,
	sscanRecordP2PR = 302,
	sscanRecordP3PP = 303,
	sscanRecordP3CV = 304,
	sscanRecordP3DV = 305,
	sscanRecordP3LV = 306,
	sscanRecordP3SP = 307,
	sscanRecordP3SI = 308,
	sscanRecordP3EP = 309,
	sscanRecordP3CP = 310,
	sscanRecordP3WD = 311,
	sscanRecordR3CV = 312,
	sscanRecordR3LV = 313,
	sscanRecordR3DL = 314,
	sscanRecordP3HR = 315,
	sscanRecordP3LR = 316,
	sscanRecordP3PA = 317,
	sscanRecordP3RA = 318,
	sscanRecordP3CA = 319,
	sscanRecordP3FS = 320,
	sscanRecordP3FI = 321,
	sscanRecordP3FE = 322,
	sscanRecordP3FC = 323,
	sscanRecordP3FW = 324,
	sscanRecordP3SM = 325,
	sscanRecordP3AR = 326,
	sscanRecordP3EU = 327,
	sscanRecordP3PR = 328,
	sscanRecordP4PP = 329,
	sscanRecordP4CV = 330,
	sscanRecordP4DV = 331,
	sscanRecordP4LV = 332,
	sscanRecordP4SP = 333,
	sscanRecordP4SI = 334,
	sscanRecordP4EP = 335,
	sscanRecordP4CP = 336,
	sscanRecordP4WD = 337,
	sscanRecordR4CV = 338,
	sscanRecordR4LV = 339,
	sscanRecordR4DL = 340,
	sscanRecordP4HR = 341,
	sscanRecordP4LR = 342,
	sscanRecordP4PA = 343,
	sscanRecordP4RA = 344,
	sscanRecordP4CA = 345,
	sscanRecordP4FS = 346,
	sscanRecordP4FI = 347,
	sscanRecordP4FE = 348,
	sscanRecordP4FC = 349,
	sscanRecordP4FW = 350,
	sscanRecordP4SM = 351,
	sscanRecordP4AR = 352,
	sscanRecordP4EU = 353,
	sscanRecordP4PR = 354,
	sscanRecordD01HR = 355,
	sscanRecordD01LR = 356,
	sscanRecordD01DA = 357,
	sscanRecordD01CA = 358,
	sscanRecordD01CV = 359,
	sscanRecordD01LV = 360,
	sscanRecordD01NE = 361,
	sscanRecordD01EU = 362,
	sscanRecordD01PR = 363,
	sscanRecordD02HR = 364,
	sscanRecordD02LR = 365,
	sscanRecordD02DA = 366,
	sscanRecordD02CA = 367,
	sscanRecordD02CV = 368,
	sscanRecordD02LV = 369,
	sscanRecordD02NE = 370,
	sscanRecordD02EU = 371,
	sscanRecordD02PR = 372,
	sscanRecordD03HR = 373,
	sscanRecordD03LR = 374,
	sscanRecordD03DA = 375,
	sscanRecordD03CA = 376,
	sscanRecordD03CV = 377,
	sscanRecordD03LV = 378,
	sscanRecordD03NE = 379,
	sscanRecordD03EU = 380,
	sscanRecordD03PR = 381,
	sscanRecordD04HR = 382,
	sscanRecordD04LR = 383,
	sscanRecordD04DA = 384,
	sscanRecordD04CA = 385,
	sscanRecordD04CV = 386,
	sscanRecordD04LV = 387,
	sscanRecordD04NE = 388,
	sscanRecordD04EU = 389,
	sscanRecordD04PR = 390,
	sscanRecordD05HR = 391,
	sscanRecordD05LR = 392,
	sscanRecordD05DA = 393,
	sscanRecordD05CA = 394,
	sscanRecordD05CV = 395,
	sscanRecordD05LV = 396,
	sscanRecordD05NE = 397,
	sscanRecordD05EU = 398,
	sscanRecordD05PR = 399,
	sscanRecordD06HR = 400,
	sscanRecordD06LR = 401,
	sscanRecordD06DA = 402,
	sscanRecordD06CA = 403,
	sscanRecordD06CV = 404,
	sscanRecordD06LV = 405,
	sscanRecordD06NE = 406,
	sscanRecordD06EU = 407,
	sscanRecordD06PR = 408,
	sscanRecordD07HR = 409,
	sscanRecordD07LR = 410,
	sscanRecordD07DA = 411,
	sscanRecordD07CA = 412,
	sscanRecordD07CV = 413,
	sscanRecordD07LV = 414,
	sscanRecordD07NE = 415,
	sscanRecordD07EU = 416,
	sscanRecordD07PR = 417,
	sscanRecordD08HR = 418,
	sscanRecordD08LR = 419,
	sscanRecordD08DA = 420,
	sscanRecordD08CA = 421,
	sscanRecordD08CV = 422,
	sscanRecordD08LV = 423,
	sscanRecordD08NE = 424,
	sscanRecordD08EU = 425,
	sscanRecordD08PR = 426,
	sscanRecordD09HR = 427,
	sscanRecordD09LR = 428,
	sscanRecordD09DA = 429,
	sscanRecordD09CA = 430,
	sscanRecordD09CV = 431,
	sscanRecordD09LV = 432,
	sscanRecordD09NE = 433,
	sscanRecordD09EU = 434,
	sscanRecordD09PR = 435,
	sscanRecordD10HR = 436,
	sscanRecordD10LR = 437,
	sscanRecordD10DA = 438,
	sscanRecordD10CA = 439,
	sscanRecordD10CV = 440,
	sscanRecordD10LV = 441,
	sscanRecordD10NE = 442,
	sscanRecordD10EU = 443,
	sscanRecordD10PR = 444,
	sscanRecordD11HR = 445,
	sscanRecordD11LR = 446,
	sscanRecordD11DA = 447,
	sscanRecordD11CA = 448,
	sscanRecordD11CV = 449,
	sscanRecordD11LV = 450,
	sscanRecordD11NE = 451,
	sscanRecordD11EU = 452,
	sscanRecordD11PR = 453,
	sscanRecordD12HR = 454,
	sscanRecordD12LR = 455,
	sscanRecordD12DA = 456,
	sscanRecordD12CA = 457,
	sscanRecordD12CV = 458,
	sscanRecordD12LV = 459,
	sscanRecordD12NE = 460,
	sscanRecordD12EU = 461,
	sscanRecordD12PR = 462,
	sscanRecordD13HR = 463,
	sscanRecordD13LR = 464,
	sscanRecordD13DA = 465,
	sscanRecordD13CA = 466,
	sscanRecordD13CV = 467,
	sscanRecordD13LV = 468,
	sscanRecordD13NE = 469,
	sscanRecordD13EU = 470,
	sscanRecordD13PR = 471,
	sscanRecordD14HR = 472,
	sscanRecordD14LR = 473,
	sscanRecordD14DA = 474,
	sscanRecordD14CA = 475,
	sscanRecordD14CV = 476,
	sscanRecordD14LV = 477,
	sscanRecordD14NE = 478,
	sscanRecordD14EU = 479,
	sscanRecordD14PR = 480,
	sscanRecordD15HR = 481,
	sscanRecordD15LR = 482,
	sscanRecordD15DA = 483,
	sscanRecordD15CA = 484,
	sscanRecordD15CV = 485,
	sscanRecordD15LV = 486,
	sscanRecordD15NE = 487,
	sscanRecordD15EU = 488,
	sscanRecordD15PR = 489,
	sscanRecordD16HR = 490,
	sscanRecordD16LR = 491,
	sscanRecordD16DA = 492,
	sscanRecordD16CA = 493,
	sscanRecordD16CV = 494,
	sscanRecordD16LV = 495,
	sscanRecordD16NE = 496,
	sscanRecordD16EU = 497,
	sscanRecordD16PR = 498,
	sscanRecordD17HR = 499,
	sscanRecordD17LR = 500,
	sscanRecordD17DA = 501,
	sscanRecordD17CA = 502,
	sscanRecordD17CV = 503,
	sscanRecordD17LV = 504,
	sscanRecordD17NE = 505,
	sscanRecordD17EU = 506,
	sscanRecordD17PR = 507,
	sscanRecordD18HR = 508,
	sscanRecordD18LR = 509,
	sscanRecordD18DA = 510,
	sscanRecordD18CA = 511,
	sscanRecordD18CV = 512,
	sscanRecordD18LV = 513,
	sscanRecordD18NE = 514,
	sscanRecordD18EU = 515,
	sscanRecordD18PR = 516,
	sscanRecordD19HR = 517,
	sscanRecordD19LR = 518,
	sscanRecordD19DA = 519,
	sscanRecordD19CA = 520,
	sscanRecordD19CV = 521,
	sscanRecordD19LV = 522,
	sscanRecordD19NE = 523,
	sscanRecordD19EU = 524,
	sscanRecordD19PR = 525,
	sscanRecordD20HR = 526,
	sscanRecordD20LR = 527,
	sscanRecordD20DA = 528,
	sscanRecordD20CA = 529,
	sscanRecordD20CV = 530,
	sscanRecordD20LV = 531,
	sscanRecordD20NE = 532,
	sscanRecordD20EU = 533,
	sscanRecordD20PR = 534,
	sscanRecordD21HR = 535,
	sscanRecordD21LR = 536,
	sscanRecordD21DA = 537,
	sscanRecordD21CA = 538,
	sscanRecordD21CV = 539,
	sscanRecordD21LV = 540,
	sscanRecordD21NE = 541,
	sscanRecordD21EU = 542,
	sscanRecordD21PR = 543,
	sscanRecordD22HR = 544,
	sscanRecordD22LR = 545,
	sscanRecordD22DA = 546,
	sscanRecordD22CA = 547,
	sscanRecordD22CV = 548,
	sscanRecordD22LV = 549,
	sscanRecordD22NE = 550,
	sscanRecordD22EU = 551,
	sscanRecordD22PR = 552,
	sscanRecordD23HR = 553,
	sscanRecordD23LR = 554,
	sscanRecordD23DA = 555,
	sscanRecordD23CA = 556,
	sscanRecordD23CV = 557,
	sscanRecordD23LV = 558,
	sscanRecordD23NE = 559,
	sscanRecordD23EU = 560,
	sscanRecordD23PR = 561,
	sscanRecordD24HR = 562,
	sscanRecordD24LR = 563,
	sscanRecordD24DA = 564,
	sscanRecordD24CA = 565,
	sscanRecordD24CV = 566,
	sscanRecordD24LV = 567,
	sscanRecordD24NE = 568,
	sscanRecordD24EU = 569,
	sscanRecordD24PR = 570,
	sscanRecordD25HR = 571,
	sscanRecordD25LR = 572,
	sscanRecordD25DA = 573,
	sscanRecordD25CA = 574,
	sscanRecordD25CV = 575,
	sscanRecordD25LV = 576,
	sscanRecordD25NE = 577,
	sscanRecordD25EU = 578,
	sscanRecordD25PR = 579,
	sscanRecordD26HR = 580,
	sscanRecordD26LR = 581,
	sscanRecordD26DA = 582,
	sscanRecordD26CA = 583,
	sscanRecordD26CV = 584,
	sscanRecordD26LV = 585,
	sscanRecordD26NE = 586,
	sscanRecordD26EU = 587,
	sscanRecordD26PR = 588,
	sscanRecordD27HR = 589,
	sscanRecordD27LR = 590,
	sscanRecordD27DA = 591,
	sscanRecordD27CA = 592,
	sscanRecordD27CV = 593,
	sscanRecordD27LV = 594,
	sscanRecordD27NE = 595,
	sscanRecordD27EU = 596,
	sscanRecordD27PR = 597,
	sscanRecordD28HR = 598,
	sscanRecordD28LR = 599,
	sscanRecordD28DA = 600,
	sscanRecordD28CA = 601,
	sscanRecordD28CV = 602,
	sscanRecordD28LV = 603,
	sscanRecordD28NE = 604,
	sscanRecordD28EU = 605,
	sscanRecordD28PR = 606,
	sscanRecordD29HR = 607,
	sscanRecordD29LR = 608,
	sscanRecordD29DA = 609,
	sscanRecordD29CA = 610,
	sscanRecordD29CV = 611,
	sscanRecordD29LV = 612,
	sscanRecordD29NE = 613,
	sscanRecordD29EU = 614,
	sscanRecordD29PR = 615,
	sscanRecordD30HR = 616,
	sscanRecordD30LR = 617,
	sscanRecordD30DA = 618,
	sscanRecordD30CA = 619,
	sscanRecordD30CV = 620,
	sscanRecordD30LV = 621,
	sscanRecordD30NE = 622,
	sscanRecordD30EU = 623,
	sscanRecordD30PR = 624,
	sscanRecordD31HR = 625,
	sscanRecordD31LR = 626,
	sscanRecordD31DA = 627,
	sscanRecordD31CA = 628,
	sscanRecordD31CV = 629,
	sscanRecordD31LV = 630,
	sscanRecordD31NE = 631,
	sscanRecordD31EU = 632,
	sscanRecordD31PR = 633,
	sscanRecordD32HR = 634,
	sscanRecordD32LR = 635,
	sscanRecordD32DA = 636,
	sscanRecordD32CA = 637,
	sscanRecordD32CV = 638,
	sscanRecordD32LV = 639,
	sscanRecordD32NE = 640,
	sscanRecordD32EU = 641,
	sscanRecordD32PR = 642,
	sscanRecordD33HR = 643,
	sscanRecordD33LR = 644,
	sscanRecordD33DA = 645,
	sscanRecordD33CA = 646,
	sscanRecordD33CV = 647,
	sscanRecordD33LV = 648,
	sscanRecordD33NE = 649,
	sscanRecordD33EU = 650,
	sscanRecordD33PR = 651,
	sscanRecordD34HR = 652,
	sscanRecordD34LR = 653,
	sscanRecordD34DA = 654,
	sscanRecordD34CA = 655,
	sscanRecordD34CV = 656,
	sscanRecordD34LV = 657,
	sscanRecordD34NE = 658,
	sscanRecordD34EU = 659,
	sscanRecordD34PR = 660,
	sscanRecordD35HR = 661,
	sscanRecordD35LR = 662,
	sscanRecordD35DA = 663,
	sscanRecordD35CA = 664,
	sscanRecordD35CV = 665,
	sscanRecordD35LV = 666,
	sscanRecordD35NE = 667,
	sscanRecordD35EU = 668,
	sscanRecordD35PR = 669,
	sscanRecordD36HR = 670,
	sscanRecordD36LR = 671,
	sscanRecordD36DA = 672,
	sscanRecordD36CA = 673,
	sscanRecordD36CV = 674,
	sscanRecordD36LV = 675,
	sscanRecordD36NE = 676,
	sscanRecordD36EU = 677,
	sscanRecordD36PR = 678,
	sscanRecordD37HR = 679,
	sscanRecordD37LR = 680,
	sscanRecordD37DA = 681,
	sscanRecordD37CA = 682,
	sscanRecordD37CV = 683,
	sscanRecordD37LV = 684,
	sscanRecordD37NE = 685,
	sscanRecordD37EU = 686,
	sscanRecordD37PR = 687,
	sscanRecordD38HR = 688,
	sscanRecordD38LR = 689,
	sscanRecordD38DA = 690,
	sscanRecordD38CA = 691,
	sscanRecordD38CV = 692,
	sscanRecordD38LV = 693,
	sscanRecordD38NE = 694,
	sscanRecordD38EU = 695,
	sscanRecordD38PR = 696,
	sscanRecordD39HR = 697,
	sscanRecordD39LR = 698,
	sscanRecordD39DA = 699,
	sscanRecordD39CA = 700,
	sscanRecordD39CV = 701,
	sscanRecordD39LV = 702,
	sscanRecordD39NE = 703,
	sscanRecordD39EU = 704,
	sscanRecordD39PR = 705,
	sscanRecordD40HR = 706,
	sscanRecordD40LR = 707,
	sscanRecordD40DA = 708,
	sscanRecordD40CA = 709,
	sscanRecordD40CV = 710,
	sscanRecordD40LV = 711,
	sscanRecordD40NE = 712,
	sscanRecordD40EU = 713,
	sscanRecordD40PR = 714,
	sscanRecordD41HR = 715,
	sscanRecordD41LR = 716,
	sscanRecordD41DA = 717,
	sscanRecordD41CA = 718,
	sscanRecordD41CV = 719,
	sscanRecordD41LV = 720,
	sscanRecordD41NE = 721,
	sscanRecordD41EU = 722,
	sscanRecordD41PR = 723,
	sscanRecordD42HR = 724,
	sscanRecordD42LR = 725,
	sscanRecordD42DA = 726,
	sscanRecordD42CA = 727,
	sscanRecordD42CV = 728,
	sscanRecordD42LV = 729,
	sscanRecordD42NE = 730,
	sscanRecordD42EU = 731,
	sscanRecordD42PR = 732,
	sscanRecordD43HR = 733,
	sscanRecordD43LR = 734,
	sscanRecordD43DA = 735,
	sscanRecordD43CA = 736,
	sscanRecordD43CV = 737,
	sscanRecordD43LV = 738,
	sscanRecordD43NE = 739,
	sscanRecordD43EU = 740,
	sscanRecordD43PR = 741,
	sscanRecordD44HR = 742,
	sscanRecordD44LR = 743,
	sscanRecordD44DA = 744,
	sscanRecordD44CA = 745,
	sscanRecordD44CV = 746,
	sscanRecordD44LV = 747,
	sscanRecordD44NE = 748,
	sscanRecordD44EU = 749,
	sscanRecordD44PR = 750,
	sscanRecordD45HR = 751,
	sscanRecordD45LR = 752,
	sscanRecordD45DA = 753,
	sscanRecordD45CA = 754,
	sscanRecordD45CV = 755,
	sscanRecordD45LV = 756,
	sscanRecordD45NE = 757,
	sscanRecordD45EU = 758,
	sscanRecordD45PR = 759,
	sscanRecordD46HR = 760,
	sscanRecordD46LR = 761,
	sscanRecordD46DA = 762,
	sscanRecordD46CA = 763,
	sscanRecordD46CV = 764,
	sscanRecordD46LV = 765,
	sscanRecordD46NE = 766,
	sscanRecordD46EU = 767,
	sscanRecordD46PR = 768,
	sscanRecordD47HR = 769,
	sscanRecordD47LR = 770,
	sscanRecordD47DA = 771,
	sscanRecordD47CA = 772,
	sscanRecordD47CV = 773,
	sscanRecordD47LV = 774,
	sscanRecordD47NE = 775,
	sscanRecordD47EU = 776,
	sscanRecordD47PR = 777,
	sscanRecordD48HR = 778,
	sscanRecordD48LR = 779,
	sscanRecordD48DA = 780,
	sscanRecordD48CA = 781,
	sscanRecordD48CV = 782,
	sscanRecordD48LV = 783,
	sscanRecordD48NE = 784,
	sscanRecordD48EU = 785,
	sscanRecordD48PR = 786,
	sscanRecordD49HR = 787,
	sscanRecordD49LR = 788,
	sscanRecordD49DA = 789,
	sscanRecordD49CA = 790,
	sscanRecordD49CV = 791,
	sscanRecordD49LV = 792,
	sscanRecordD49NE = 793,
	sscanRecordD49EU = 794,
	sscanRecordD49PR = 795,
	sscanRecordD50HR = 796,
	sscanRecordD50LR = 797,
	sscanRecordD50DA = 798,
	sscanRecordD50CA = 799,
	sscanRecordD50CV = 800,
	sscanRecordD50LV = 801,
	sscanRecordD50NE = 802,
	sscanRecordD50EU = 803,
	sscanRecordD50PR = 804,
	sscanRecordD51HR = 805,
	sscanRecordD51LR = 806,
	sscanRecordD51DA = 807,
	sscanRecordD51CA = 808,
	sscanRecordD51CV = 809,
	sscanRecordD51LV = 810,
	sscanRecordD51NE = 811,
	sscanRecordD51EU = 812,
	sscanRecordD51PR = 813,
	sscanRecordD52HR = 814,
	sscanRecordD52LR = 815,
	sscanRecordD52DA = 816,
	sscanRecordD52CA = 817,
	sscanRecordD52CV = 818,
	sscanRecordD52LV = 819,
	sscanRecordD52NE = 820,
	sscanRecordD52EU = 821,
	sscanRecordD52PR = 822,
	sscanRecordD53HR = 823,
	sscanRecordD53LR = 824,
	sscanRecordD53DA = 825,
	sscanRecordD53CA = 826,
	sscanRecordD53CV = 827,
	sscanRecordD53LV = 828,
	sscanRecordD53NE = 829,
	sscanRecordD53EU = 830,
	sscanRecordD53PR = 831,
	sscanRecordD54HR = 832,
	sscanRecordD54LR = 833,
	sscanRecordD54DA = 834,
	sscanRecordD54CA = 835,
	sscanRecordD54CV = 836,
	sscanRecordD54LV = 837,
	sscanRecordD54NE = 838,
	sscanRecordD54EU = 839,
	sscanRecordD54PR = 840,
	sscanRecordD55HR = 841,
	sscanRecordD55LR = 842,
	sscanRecordD55DA = 843,
	sscanRecordD55CA = 844,
	sscanRecordD55CV = 845,
	sscanRecordD55LV = 846,
	sscanRecordD55NE = 847,
	sscanRecordD55EU = 848,
	sscanRecordD55PR = 849,
	sscanRecordD56HR = 850,
	sscanRecordD56LR = 851,
	sscanRecordD56DA = 852,
	sscanRecordD56CA = 853,
	sscanRecordD56CV = 854,
	sscanRecordD56LV = 855,
	sscanRecordD56NE = 856,
	sscanRecordD56EU = 857,
	sscanRecordD56PR = 858,
	sscanRecordD57HR = 859,
	sscanRecordD57LR = 860,
	sscanRecordD57DA = 861,
	sscanRecordD57CA = 862,
	sscanRecordD57CV = 863,
	sscanRecordD57LV = 864,
	sscanRecordD57NE = 865,
	sscanRecordD57EU = 866,
	sscanRecordD57PR = 867,
	sscanRecordD58HR = 868,
	sscanRecordD58LR = 869,
	sscanRecordD58DA = 870,
	sscanRecordD58CA = 871,
	sscanRecordD58CV = 872,
	sscanRecordD58LV = 873,
	sscanRecordD58NE = 874,
	sscanRecordD58EU = 875,
	sscanRecordD58PR = 876,
	sscanRecordD59HR = 877,
	sscanRecordD59LR = 878,
	sscanRecordD59DA = 879,
	sscanRecordD59CA = 880,
	sscanRecordD59CV = 881,
	sscanRecordD59LV = 882,
	sscanRecordD59NE = 883,
	sscanRecordD59EU = 884,
	sscanRecordD59PR = 885,
	sscanRecordD60HR = 886,
	sscanRecordD60LR = 887,
	sscanRecordD60DA = 888,
	sscanRecordD60CA = 889,
	sscanRecordD60CV = 890,
	sscanRecordD60LV = 891,
	sscanRecordD60NE = 892,
	sscanRecordD60EU = 893,
	sscanRecordD60PR = 894,
	sscanRecordD61HR = 895,
	sscanRecordD61LR = 896,
	sscanRecordD61DA = 897,
	sscanRecordD61CA = 898,
	sscanRecordD61CV = 899,
	sscanRecordD61LV = 900,
	sscanRecordD61NE = 901,
	sscanRecordD61EU = 902,
	sscanRecordD61PR = 903,
	sscanRecordD62HR = 904,
	sscanRecordD62LR = 905,
	sscanRecordD62DA = 906,
	sscanRecordD62CA = 907,
	sscanRecordD62CV = 908,
	sscanRecordD62LV = 909,
	sscanRecordD62NE = 910,
	sscanRecordD62EU = 911,
	sscanRecordD62PR = 912,
	sscanRecordD63HR = 913,
	sscanRecordD63LR = 914,
	sscanRecordD63DA = 915,
	sscanRecordD63CA = 916,
	sscanRecordD63CV = 917,
	sscanRecordD63LV = 918,
	sscanRecordD63NE = 919,
	sscanRecordD63EU = 920,
	sscanRecordD63PR = 921,
	sscanRecordD64HR = 922,
	sscanRecordD64LR = 923,
	sscanRecordD64DA = 924,
	sscanRecordD64CA = 925,
	sscanRecordD64CV = 926,
	sscanRecordD64LV = 927,
	sscanRecordD64NE = 928,
	sscanRecordD64EU = 929,
	sscanRecordD64PR = 930,
	sscanRecordD65HR = 931,
	sscanRecordD65LR = 932,
	sscanRecordD65DA = 933,
	sscanRecordD65CA = 934,
	sscanRecordD65CV = 935,
	sscanRecordD65LV = 936,
	sscanRecordD65NE = 937,
	sscanRecordD65EU = 938,
	sscanRecordD65PR = 939,
	sscanRecordD66HR = 940,
	sscanRecordD66LR = 941,
	sscanRecordD66DA = 942,
	sscanRecordD66CA = 943,
	sscanRecordD66CV = 944,
	sscanRecordD66LV = 945,
	sscanRecordD66NE = 946,
	sscanRecordD66EU = 947,
	sscanRecordD66PR = 948,
	sscanRecordD67HR = 949,
	sscanRecordD67LR = 950,
	sscanRecordD67DA = 951,
	sscanRecordD67CA = 952,
	sscanRecordD67CV = 953,
	sscanRecordD67LV = 954,
	sscanRecordD67NE = 955,
	sscanRecordD67EU = 956,
	sscanRecordD67PR = 957,
	sscanRecordD68HR = 958,
	sscanRecordD68LR = 959,
	sscanRecordD68DA = 960,
	sscanRecordD68CA = 961,
	sscanRecordD68CV = 962,
	sscanRecordD68LV = 963,
	sscanRecordD68NE = 964,
	sscanRecordD68EU = 965,
	sscanRecordD68PR = 966,
	sscanRecordD69HR = 967,
	sscanRecordD69LR = 968,
	sscanRecordD69DA = 969,
	sscanRecordD69CA = 970,
	sscanRecordD69CV = 971,
	sscanRecordD69LV = 972,
	sscanRecordD69NE = 973,
	sscanRecordD69EU = 974,
	sscanRecordD69PR = 975,
	sscanRecordD70HR = 976,
	sscanRecordD70LR = 977,
	sscanRecordD70DA = 978,
	sscanRecordD70CA = 979,
	sscanRecordD70CV = 980,
	sscanRecordD70LV = 981,
	sscanRecordD70NE = 982,
	sscanRecordD70EU = 983,
	sscanRecordD70PR = 984,
	sscanRecordT1CD = 985,
	sscanRecordT2CD = 986,
	sscanRecordT3CD = 987,
	sscanRecordT4CD = 988,
	sscanRecordA1CD = 989,
	sscanRecordBSCD = 990,
	sscanRecordASCD = 991,
	sscanRecordPAUS = 992,
	sscanRecordLPAU = 993,
	sscanRecordPDLY = 994,
	sscanRecordDDLY = 995,
	sscanRecordRDLY = 996,
	sscanRecordFAZE = 997,
	sscanRecordACQM = 998,
	sscanRecordACQT = 999,
	sscanRecordDSTATE = 1000,
	sscanRecordCOPYTO = 1001
} sscanFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int sscanRecordSizeOffset(dbRecordType *prt)
{
    sscanRecord *prec = 0;

    if (prt->no_fields != 1002) {
        cantProceed("IOC build or installation error:\n"
            "    The sscanRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 1002.\n",
            prt->no_fields);
    }
    prt->papFldDes[sscanRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[sscanRecordNAME]->offset = (unsigned short)offsetof(sscanRecord, name);
    prt->papFldDes[sscanRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[sscanRecordDESC]->offset = (unsigned short)offsetof(sscanRecord, desc);
    prt->papFldDes[sscanRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[sscanRecordASG]->offset = (unsigned short)offsetof(sscanRecord, asg);
    prt->papFldDes[sscanRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[sscanRecordSCAN]->offset = (unsigned short)offsetof(sscanRecord, scan);
    prt->papFldDes[sscanRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[sscanRecordPINI]->offset = (unsigned short)offsetof(sscanRecord, pini);
    prt->papFldDes[sscanRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[sscanRecordPHAS]->offset = (unsigned short)offsetof(sscanRecord, phas);
    prt->papFldDes[sscanRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[sscanRecordEVNT]->offset = (unsigned short)offsetof(sscanRecord, evnt);
    prt->papFldDes[sscanRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[sscanRecordTSE]->offset = (unsigned short)offsetof(sscanRecord, tse);
    prt->papFldDes[sscanRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[sscanRecordTSEL]->offset = (unsigned short)offsetof(sscanRecord, tsel);
    prt->papFldDes[sscanRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[sscanRecordDTYP]->offset = (unsigned short)offsetof(sscanRecord, dtyp);
    prt->papFldDes[sscanRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[sscanRecordDISV]->offset = (unsigned short)offsetof(sscanRecord, disv);
    prt->papFldDes[sscanRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[sscanRecordDISA]->offset = (unsigned short)offsetof(sscanRecord, disa);
    prt->papFldDes[sscanRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[sscanRecordSDIS]->offset = (unsigned short)offsetof(sscanRecord, sdis);
    prt->papFldDes[sscanRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[sscanRecordMLOK]->offset = (unsigned short)offsetof(sscanRecord, mlok);
    prt->papFldDes[sscanRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[sscanRecordMLIS]->offset = (unsigned short)offsetof(sscanRecord, mlis);
    prt->papFldDes[sscanRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[sscanRecordBKLNK]->offset = (unsigned short)offsetof(sscanRecord, bklnk);
    prt->papFldDes[sscanRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[sscanRecordDISP]->offset = (unsigned short)offsetof(sscanRecord, disp);
    prt->papFldDes[sscanRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[sscanRecordPROC]->offset = (unsigned short)offsetof(sscanRecord, proc);
    prt->papFldDes[sscanRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[sscanRecordSTAT]->offset = (unsigned short)offsetof(sscanRecord, stat);
    prt->papFldDes[sscanRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[sscanRecordSEVR]->offset = (unsigned short)offsetof(sscanRecord, sevr);
    prt->papFldDes[sscanRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[sscanRecordAMSG]->offset = (unsigned short)offsetof(sscanRecord, amsg);
    prt->papFldDes[sscanRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[sscanRecordNSTA]->offset = (unsigned short)offsetof(sscanRecord, nsta);
    prt->papFldDes[sscanRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[sscanRecordNSEV]->offset = (unsigned short)offsetof(sscanRecord, nsev);
    prt->papFldDes[sscanRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[sscanRecordNAMSG]->offset = (unsigned short)offsetof(sscanRecord, namsg);
    prt->papFldDes[sscanRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[sscanRecordACKS]->offset = (unsigned short)offsetof(sscanRecord, acks);
    prt->papFldDes[sscanRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[sscanRecordACKT]->offset = (unsigned short)offsetof(sscanRecord, ackt);
    prt->papFldDes[sscanRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[sscanRecordDISS]->offset = (unsigned short)offsetof(sscanRecord, diss);
    prt->papFldDes[sscanRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[sscanRecordLCNT]->offset = (unsigned short)offsetof(sscanRecord, lcnt);
    prt->papFldDes[sscanRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[sscanRecordPACT]->offset = (unsigned short)offsetof(sscanRecord, pact);
    prt->papFldDes[sscanRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[sscanRecordPUTF]->offset = (unsigned short)offsetof(sscanRecord, putf);
    prt->papFldDes[sscanRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[sscanRecordRPRO]->offset = (unsigned short)offsetof(sscanRecord, rpro);
    prt->papFldDes[sscanRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[sscanRecordASP]->offset = (unsigned short)offsetof(sscanRecord, asp);
    prt->papFldDes[sscanRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[sscanRecordPPN]->offset = (unsigned short)offsetof(sscanRecord, ppn);
    prt->papFldDes[sscanRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[sscanRecordPPNR]->offset = (unsigned short)offsetof(sscanRecord, ppnr);
    prt->papFldDes[sscanRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[sscanRecordSPVT]->offset = (unsigned short)offsetof(sscanRecord, spvt);
    prt->papFldDes[sscanRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[sscanRecordRSET]->offset = (unsigned short)offsetof(sscanRecord, rset);
    prt->papFldDes[sscanRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[sscanRecordDSET]->offset = (unsigned short)offsetof(sscanRecord, dset);
    prt->papFldDes[sscanRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[sscanRecordDPVT]->offset = (unsigned short)offsetof(sscanRecord, dpvt);
    prt->papFldDes[sscanRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[sscanRecordRDES]->offset = (unsigned short)offsetof(sscanRecord, rdes);
    prt->papFldDes[sscanRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[sscanRecordLSET]->offset = (unsigned short)offsetof(sscanRecord, lset);
    prt->papFldDes[sscanRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[sscanRecordPRIO]->offset = (unsigned short)offsetof(sscanRecord, prio);
    prt->papFldDes[sscanRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[sscanRecordTPRO]->offset = (unsigned short)offsetof(sscanRecord, tpro);
    prt->papFldDes[sscanRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[sscanRecordBKPT]->offset = (unsigned short)offsetof(sscanRecord, bkpt);
    prt->papFldDes[sscanRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[sscanRecordUDF]->offset = (unsigned short)offsetof(sscanRecord, udf);
    prt->papFldDes[sscanRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[sscanRecordUDFS]->offset = (unsigned short)offsetof(sscanRecord, udfs);
    prt->papFldDes[sscanRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[sscanRecordTIME]->offset = (unsigned short)offsetof(sscanRecord, time);
    prt->papFldDes[sscanRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[sscanRecordUTAG]->offset = (unsigned short)offsetof(sscanRecord, utag);
    prt->papFldDes[sscanRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[sscanRecordFLNK]->offset = (unsigned short)offsetof(sscanRecord, flnk);
    prt->papFldDes[sscanRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[sscanRecordVERS]->offset = (unsigned short)offsetof(sscanRecord, vers);
    prt->papFldDes[sscanRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[sscanRecordVAL]->offset = (unsigned short)offsetof(sscanRecord, val);
    prt->papFldDes[sscanRecordSMSG]->size = sizeof(prec->smsg);
    prt->papFldDes[sscanRecordSMSG]->offset = (unsigned short)offsetof(sscanRecord, smsg);
    prt->papFldDes[sscanRecordCMND]->size = sizeof(prec->cmnd);
    prt->papFldDes[sscanRecordCMND]->offset = (unsigned short)offsetof(sscanRecord, cmnd);
    prt->papFldDes[sscanRecordALRT]->size = sizeof(prec->alrt);
    prt->papFldDes[sscanRecordALRT]->offset = (unsigned short)offsetof(sscanRecord, alrt);
    prt->papFldDes[sscanRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[sscanRecordRPVT]->offset = (unsigned short)offsetof(sscanRecord, rpvt);
    prt->papFldDes[sscanRecordMPTS]->size = sizeof(prec->mpts);
    prt->papFldDes[sscanRecordMPTS]->offset = (unsigned short)offsetof(sscanRecord, mpts);
    prt->papFldDes[sscanRecordEXSC]->size = sizeof(prec->exsc);
    prt->papFldDes[sscanRecordEXSC]->offset = (unsigned short)offsetof(sscanRecord, exsc);
    prt->papFldDes[sscanRecordXSC]->size = sizeof(prec->xsc);
    prt->papFldDes[sscanRecordXSC]->offset = (unsigned short)offsetof(sscanRecord, xsc);
    prt->papFldDes[sscanRecordPXSC]->size = sizeof(prec->pxsc);
    prt->papFldDes[sscanRecordPXSC]->offset = (unsigned short)offsetof(sscanRecord, pxsc);
    prt->papFldDes[sscanRecordBUSY]->size = sizeof(prec->busy);
    prt->papFldDes[sscanRecordBUSY]->offset = (unsigned short)offsetof(sscanRecord, busy);
    prt->papFldDes[sscanRecordKILL]->size = sizeof(prec->kill);
    prt->papFldDes[sscanRecordKILL]->offset = (unsigned short)offsetof(sscanRecord, kill);
    prt->papFldDes[sscanRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[sscanRecordWAIT]->offset = (unsigned short)offsetof(sscanRecord, wait);
    prt->papFldDes[sscanRecordWCNT]->size = sizeof(prec->wcnt);
    prt->papFldDes[sscanRecordWCNT]->offset = (unsigned short)offsetof(sscanRecord, wcnt);
    prt->papFldDes[sscanRecordAWCT]->size = sizeof(prec->awct);
    prt->papFldDes[sscanRecordAWCT]->offset = (unsigned short)offsetof(sscanRecord, awct);
    prt->papFldDes[sscanRecordWTNG]->size = sizeof(prec->wtng);
    prt->papFldDes[sscanRecordWTNG]->offset = (unsigned short)offsetof(sscanRecord, wtng);
    prt->papFldDes[sscanRecordAWAIT]->size = sizeof(prec->await);
    prt->papFldDes[sscanRecordAWAIT]->offset = (unsigned short)offsetof(sscanRecord, await);
    prt->papFldDes[sscanRecordAAWAIT]->size = sizeof(prec->aawait);
    prt->papFldDes[sscanRecordAAWAIT]->offset = (unsigned short)offsetof(sscanRecord, aawait);
    prt->papFldDes[sscanRecordDATA]->size = sizeof(prec->data);
    prt->papFldDes[sscanRecordDATA]->offset = (unsigned short)offsetof(sscanRecord, data);
    prt->papFldDes[sscanRecordREFD]->size = sizeof(prec->refd);
    prt->papFldDes[sscanRecordREFD]->offset = (unsigned short)offsetof(sscanRecord, refd);
    prt->papFldDes[sscanRecordNPTS]->size = sizeof(prec->npts);
    prt->papFldDes[sscanRecordNPTS]->offset = (unsigned short)offsetof(sscanRecord, npts);
    prt->papFldDes[sscanRecordFPTS]->size = sizeof(prec->fpts);
    prt->papFldDes[sscanRecordFPTS]->offset = (unsigned short)offsetof(sscanRecord, fpts);
    prt->papFldDes[sscanRecordFFO]->size = sizeof(prec->ffo);
    prt->papFldDes[sscanRecordFFO]->offset = (unsigned short)offsetof(sscanRecord, ffo);
    prt->papFldDes[sscanRecordCPT]->size = sizeof(prec->cpt);
    prt->papFldDes[sscanRecordCPT]->offset = (unsigned short)offsetof(sscanRecord, cpt);
    prt->papFldDes[sscanRecordBCPT]->size = sizeof(prec->bcpt);
    prt->papFldDes[sscanRecordBCPT]->offset = (unsigned short)offsetof(sscanRecord, bcpt);
    prt->papFldDes[sscanRecordDPT]->size = sizeof(prec->dpt);
    prt->papFldDes[sscanRecordDPT]->offset = (unsigned short)offsetof(sscanRecord, dpt);
    prt->papFldDes[sscanRecordPCPT]->size = sizeof(prec->pcpt);
    prt->papFldDes[sscanRecordPCPT]->offset = (unsigned short)offsetof(sscanRecord, pcpt);
    prt->papFldDes[sscanRecordPASM]->size = sizeof(prec->pasm);
    prt->papFldDes[sscanRecordPASM]->offset = (unsigned short)offsetof(sscanRecord, pasm);
    prt->papFldDes[sscanRecordTOLP]->size = sizeof(prec->tolp);
    prt->papFldDes[sscanRecordTOLP]->offset = (unsigned short)offsetof(sscanRecord, tolp);
    prt->papFldDes[sscanRecordTLAP]->size = sizeof(prec->tlap);
    prt->papFldDes[sscanRecordTLAP]->offset = (unsigned short)offsetof(sscanRecord, tlap);
    prt->papFldDes[sscanRecordATIME]->size = sizeof(prec->atime);
    prt->papFldDes[sscanRecordATIME]->offset = (unsigned short)offsetof(sscanRecord, atime);
    prt->papFldDes[sscanRecordP1PV]->size = sizeof(prec->p1pv);
    prt->papFldDes[sscanRecordP1PV]->offset = (unsigned short)offsetof(sscanRecord, p1pv);
    prt->papFldDes[sscanRecordP2PV]->size = sizeof(prec->p2pv);
    prt->papFldDes[sscanRecordP2PV]->offset = (unsigned short)offsetof(sscanRecord, p2pv);
    prt->papFldDes[sscanRecordP3PV]->size = sizeof(prec->p3pv);
    prt->papFldDes[sscanRecordP3PV]->offset = (unsigned short)offsetof(sscanRecord, p3pv);
    prt->papFldDes[sscanRecordP4PV]->size = sizeof(prec->p4pv);
    prt->papFldDes[sscanRecordP4PV]->offset = (unsigned short)offsetof(sscanRecord, p4pv);
    prt->papFldDes[sscanRecordR1PV]->size = sizeof(prec->r1pv);
    prt->papFldDes[sscanRecordR1PV]->offset = (unsigned short)offsetof(sscanRecord, r1pv);
    prt->papFldDes[sscanRecordR2PV]->size = sizeof(prec->r2pv);
    prt->papFldDes[sscanRecordR2PV]->offset = (unsigned short)offsetof(sscanRecord, r2pv);
    prt->papFldDes[sscanRecordR3PV]->size = sizeof(prec->r3pv);
    prt->papFldDes[sscanRecordR3PV]->offset = (unsigned short)offsetof(sscanRecord, r3pv);
    prt->papFldDes[sscanRecordR4PV]->size = sizeof(prec->r4pv);
    prt->papFldDes[sscanRecordR4PV]->offset = (unsigned short)offsetof(sscanRecord, r4pv);
    prt->papFldDes[sscanRecordD01PV]->size = sizeof(prec->d01pv);
    prt->papFldDes[sscanRecordD01PV]->offset = (unsigned short)offsetof(sscanRecord, d01pv);
    prt->papFldDes[sscanRecordD02PV]->size = sizeof(prec->d02pv);
    prt->papFldDes[sscanRecordD02PV]->offset = (unsigned short)offsetof(sscanRecord, d02pv);
    prt->papFldDes[sscanRecordD03PV]->size = sizeof(prec->d03pv);
    prt->papFldDes[sscanRecordD03PV]->offset = (unsigned short)offsetof(sscanRecord, d03pv);
    prt->papFldDes[sscanRecordD04PV]->size = sizeof(prec->d04pv);
    prt->papFldDes[sscanRecordD04PV]->offset = (unsigned short)offsetof(sscanRecord, d04pv);
    prt->papFldDes[sscanRecordD05PV]->size = sizeof(prec->d05pv);
    prt->papFldDes[sscanRecordD05PV]->offset = (unsigned short)offsetof(sscanRecord, d05pv);
    prt->papFldDes[sscanRecordD06PV]->size = sizeof(prec->d06pv);
    prt->papFldDes[sscanRecordD06PV]->offset = (unsigned short)offsetof(sscanRecord, d06pv);
    prt->papFldDes[sscanRecordD07PV]->size = sizeof(prec->d07pv);
    prt->papFldDes[sscanRecordD07PV]->offset = (unsigned short)offsetof(sscanRecord, d07pv);
    prt->papFldDes[sscanRecordD08PV]->size = sizeof(prec->d08pv);
    prt->papFldDes[sscanRecordD08PV]->offset = (unsigned short)offsetof(sscanRecord, d08pv);
    prt->papFldDes[sscanRecordD09PV]->size = sizeof(prec->d09pv);
    prt->papFldDes[sscanRecordD09PV]->offset = (unsigned short)offsetof(sscanRecord, d09pv);
    prt->papFldDes[sscanRecordD10PV]->size = sizeof(prec->d10pv);
    prt->papFldDes[sscanRecordD10PV]->offset = (unsigned short)offsetof(sscanRecord, d10pv);
    prt->papFldDes[sscanRecordD11PV]->size = sizeof(prec->d11pv);
    prt->papFldDes[sscanRecordD11PV]->offset = (unsigned short)offsetof(sscanRecord, d11pv);
    prt->papFldDes[sscanRecordD12PV]->size = sizeof(prec->d12pv);
    prt->papFldDes[sscanRecordD12PV]->offset = (unsigned short)offsetof(sscanRecord, d12pv);
    prt->papFldDes[sscanRecordD13PV]->size = sizeof(prec->d13pv);
    prt->papFldDes[sscanRecordD13PV]->offset = (unsigned short)offsetof(sscanRecord, d13pv);
    prt->papFldDes[sscanRecordD14PV]->size = sizeof(prec->d14pv);
    prt->papFldDes[sscanRecordD14PV]->offset = (unsigned short)offsetof(sscanRecord, d14pv);
    prt->papFldDes[sscanRecordD15PV]->size = sizeof(prec->d15pv);
    prt->papFldDes[sscanRecordD15PV]->offset = (unsigned short)offsetof(sscanRecord, d15pv);
    prt->papFldDes[sscanRecordD16PV]->size = sizeof(prec->d16pv);
    prt->papFldDes[sscanRecordD16PV]->offset = (unsigned short)offsetof(sscanRecord, d16pv);
    prt->papFldDes[sscanRecordD17PV]->size = sizeof(prec->d17pv);
    prt->papFldDes[sscanRecordD17PV]->offset = (unsigned short)offsetof(sscanRecord, d17pv);
    prt->papFldDes[sscanRecordD18PV]->size = sizeof(prec->d18pv);
    prt->papFldDes[sscanRecordD18PV]->offset = (unsigned short)offsetof(sscanRecord, d18pv);
    prt->papFldDes[sscanRecordD19PV]->size = sizeof(prec->d19pv);
    prt->papFldDes[sscanRecordD19PV]->offset = (unsigned short)offsetof(sscanRecord, d19pv);
    prt->papFldDes[sscanRecordD20PV]->size = sizeof(prec->d20pv);
    prt->papFldDes[sscanRecordD20PV]->offset = (unsigned short)offsetof(sscanRecord, d20pv);
    prt->papFldDes[sscanRecordD21PV]->size = sizeof(prec->d21pv);
    prt->papFldDes[sscanRecordD21PV]->offset = (unsigned short)offsetof(sscanRecord, d21pv);
    prt->papFldDes[sscanRecordD22PV]->size = sizeof(prec->d22pv);
    prt->papFldDes[sscanRecordD22PV]->offset = (unsigned short)offsetof(sscanRecord, d22pv);
    prt->papFldDes[sscanRecordD23PV]->size = sizeof(prec->d23pv);
    prt->papFldDes[sscanRecordD23PV]->offset = (unsigned short)offsetof(sscanRecord, d23pv);
    prt->papFldDes[sscanRecordD24PV]->size = sizeof(prec->d24pv);
    prt->papFldDes[sscanRecordD24PV]->offset = (unsigned short)offsetof(sscanRecord, d24pv);
    prt->papFldDes[sscanRecordD25PV]->size = sizeof(prec->d25pv);
    prt->papFldDes[sscanRecordD25PV]->offset = (unsigned short)offsetof(sscanRecord, d25pv);
    prt->papFldDes[sscanRecordD26PV]->size = sizeof(prec->d26pv);
    prt->papFldDes[sscanRecordD26PV]->offset = (unsigned short)offsetof(sscanRecord, d26pv);
    prt->papFldDes[sscanRecordD27PV]->size = sizeof(prec->d27pv);
    prt->papFldDes[sscanRecordD27PV]->offset = (unsigned short)offsetof(sscanRecord, d27pv);
    prt->papFldDes[sscanRecordD28PV]->size = sizeof(prec->d28pv);
    prt->papFldDes[sscanRecordD28PV]->offset = (unsigned short)offsetof(sscanRecord, d28pv);
    prt->papFldDes[sscanRecordD29PV]->size = sizeof(prec->d29pv);
    prt->papFldDes[sscanRecordD29PV]->offset = (unsigned short)offsetof(sscanRecord, d29pv);
    prt->papFldDes[sscanRecordD30PV]->size = sizeof(prec->d30pv);
    prt->papFldDes[sscanRecordD30PV]->offset = (unsigned short)offsetof(sscanRecord, d30pv);
    prt->papFldDes[sscanRecordD31PV]->size = sizeof(prec->d31pv);
    prt->papFldDes[sscanRecordD31PV]->offset = (unsigned short)offsetof(sscanRecord, d31pv);
    prt->papFldDes[sscanRecordD32PV]->size = sizeof(prec->d32pv);
    prt->papFldDes[sscanRecordD32PV]->offset = (unsigned short)offsetof(sscanRecord, d32pv);
    prt->papFldDes[sscanRecordD33PV]->size = sizeof(prec->d33pv);
    prt->papFldDes[sscanRecordD33PV]->offset = (unsigned short)offsetof(sscanRecord, d33pv);
    prt->papFldDes[sscanRecordD34PV]->size = sizeof(prec->d34pv);
    prt->papFldDes[sscanRecordD34PV]->offset = (unsigned short)offsetof(sscanRecord, d34pv);
    prt->papFldDes[sscanRecordD35PV]->size = sizeof(prec->d35pv);
    prt->papFldDes[sscanRecordD35PV]->offset = (unsigned short)offsetof(sscanRecord, d35pv);
    prt->papFldDes[sscanRecordD36PV]->size = sizeof(prec->d36pv);
    prt->papFldDes[sscanRecordD36PV]->offset = (unsigned short)offsetof(sscanRecord, d36pv);
    prt->papFldDes[sscanRecordD37PV]->size = sizeof(prec->d37pv);
    prt->papFldDes[sscanRecordD37PV]->offset = (unsigned short)offsetof(sscanRecord, d37pv);
    prt->papFldDes[sscanRecordD38PV]->size = sizeof(prec->d38pv);
    prt->papFldDes[sscanRecordD38PV]->offset = (unsigned short)offsetof(sscanRecord, d38pv);
    prt->papFldDes[sscanRecordD39PV]->size = sizeof(prec->d39pv);
    prt->papFldDes[sscanRecordD39PV]->offset = (unsigned short)offsetof(sscanRecord, d39pv);
    prt->papFldDes[sscanRecordD40PV]->size = sizeof(prec->d40pv);
    prt->papFldDes[sscanRecordD40PV]->offset = (unsigned short)offsetof(sscanRecord, d40pv);
    prt->papFldDes[sscanRecordD41PV]->size = sizeof(prec->d41pv);
    prt->papFldDes[sscanRecordD41PV]->offset = (unsigned short)offsetof(sscanRecord, d41pv);
    prt->papFldDes[sscanRecordD42PV]->size = sizeof(prec->d42pv);
    prt->papFldDes[sscanRecordD42PV]->offset = (unsigned short)offsetof(sscanRecord, d42pv);
    prt->papFldDes[sscanRecordD43PV]->size = sizeof(prec->d43pv);
    prt->papFldDes[sscanRecordD43PV]->offset = (unsigned short)offsetof(sscanRecord, d43pv);
    prt->papFldDes[sscanRecordD44PV]->size = sizeof(prec->d44pv);
    prt->papFldDes[sscanRecordD44PV]->offset = (unsigned short)offsetof(sscanRecord, d44pv);
    prt->papFldDes[sscanRecordD45PV]->size = sizeof(prec->d45pv);
    prt->papFldDes[sscanRecordD45PV]->offset = (unsigned short)offsetof(sscanRecord, d45pv);
    prt->papFldDes[sscanRecordD46PV]->size = sizeof(prec->d46pv);
    prt->papFldDes[sscanRecordD46PV]->offset = (unsigned short)offsetof(sscanRecord, d46pv);
    prt->papFldDes[sscanRecordD47PV]->size = sizeof(prec->d47pv);
    prt->papFldDes[sscanRecordD47PV]->offset = (unsigned short)offsetof(sscanRecord, d47pv);
    prt->papFldDes[sscanRecordD48PV]->size = sizeof(prec->d48pv);
    prt->papFldDes[sscanRecordD48PV]->offset = (unsigned short)offsetof(sscanRecord, d48pv);
    prt->papFldDes[sscanRecordD49PV]->size = sizeof(prec->d49pv);
    prt->papFldDes[sscanRecordD49PV]->offset = (unsigned short)offsetof(sscanRecord, d49pv);
    prt->papFldDes[sscanRecordD50PV]->size = sizeof(prec->d50pv);
    prt->papFldDes[sscanRecordD50PV]->offset = (unsigned short)offsetof(sscanRecord, d50pv);
    prt->papFldDes[sscanRecordD51PV]->size = sizeof(prec->d51pv);
    prt->papFldDes[sscanRecordD51PV]->offset = (unsigned short)offsetof(sscanRecord, d51pv);
    prt->papFldDes[sscanRecordD52PV]->size = sizeof(prec->d52pv);
    prt->papFldDes[sscanRecordD52PV]->offset = (unsigned short)offsetof(sscanRecord, d52pv);
    prt->papFldDes[sscanRecordD53PV]->size = sizeof(prec->d53pv);
    prt->papFldDes[sscanRecordD53PV]->offset = (unsigned short)offsetof(sscanRecord, d53pv);
    prt->papFldDes[sscanRecordD54PV]->size = sizeof(prec->d54pv);
    prt->papFldDes[sscanRecordD54PV]->offset = (unsigned short)offsetof(sscanRecord, d54pv);
    prt->papFldDes[sscanRecordD55PV]->size = sizeof(prec->d55pv);
    prt->papFldDes[sscanRecordD55PV]->offset = (unsigned short)offsetof(sscanRecord, d55pv);
    prt->papFldDes[sscanRecordD56PV]->size = sizeof(prec->d56pv);
    prt->papFldDes[sscanRecordD56PV]->offset = (unsigned short)offsetof(sscanRecord, d56pv);
    prt->papFldDes[sscanRecordD57PV]->size = sizeof(prec->d57pv);
    prt->papFldDes[sscanRecordD57PV]->offset = (unsigned short)offsetof(sscanRecord, d57pv);
    prt->papFldDes[sscanRecordD58PV]->size = sizeof(prec->d58pv);
    prt->papFldDes[sscanRecordD58PV]->offset = (unsigned short)offsetof(sscanRecord, d58pv);
    prt->papFldDes[sscanRecordD59PV]->size = sizeof(prec->d59pv);
    prt->papFldDes[sscanRecordD59PV]->offset = (unsigned short)offsetof(sscanRecord, d59pv);
    prt->papFldDes[sscanRecordD60PV]->size = sizeof(prec->d60pv);
    prt->papFldDes[sscanRecordD60PV]->offset = (unsigned short)offsetof(sscanRecord, d60pv);
    prt->papFldDes[sscanRecordD61PV]->size = sizeof(prec->d61pv);
    prt->papFldDes[sscanRecordD61PV]->offset = (unsigned short)offsetof(sscanRecord, d61pv);
    prt->papFldDes[sscanRecordD62PV]->size = sizeof(prec->d62pv);
    prt->papFldDes[sscanRecordD62PV]->offset = (unsigned short)offsetof(sscanRecord, d62pv);
    prt->papFldDes[sscanRecordD63PV]->size = sizeof(prec->d63pv);
    prt->papFldDes[sscanRecordD63PV]->offset = (unsigned short)offsetof(sscanRecord, d63pv);
    prt->papFldDes[sscanRecordD64PV]->size = sizeof(prec->d64pv);
    prt->papFldDes[sscanRecordD64PV]->offset = (unsigned short)offsetof(sscanRecord, d64pv);
    prt->papFldDes[sscanRecordD65PV]->size = sizeof(prec->d65pv);
    prt->papFldDes[sscanRecordD65PV]->offset = (unsigned short)offsetof(sscanRecord, d65pv);
    prt->papFldDes[sscanRecordD66PV]->size = sizeof(prec->d66pv);
    prt->papFldDes[sscanRecordD66PV]->offset = (unsigned short)offsetof(sscanRecord, d66pv);
    prt->papFldDes[sscanRecordD67PV]->size = sizeof(prec->d67pv);
    prt->papFldDes[sscanRecordD67PV]->offset = (unsigned short)offsetof(sscanRecord, d67pv);
    prt->papFldDes[sscanRecordD68PV]->size = sizeof(prec->d68pv);
    prt->papFldDes[sscanRecordD68PV]->offset = (unsigned short)offsetof(sscanRecord, d68pv);
    prt->papFldDes[sscanRecordD69PV]->size = sizeof(prec->d69pv);
    prt->papFldDes[sscanRecordD69PV]->offset = (unsigned short)offsetof(sscanRecord, d69pv);
    prt->papFldDes[sscanRecordD70PV]->size = sizeof(prec->d70pv);
    prt->papFldDes[sscanRecordD70PV]->offset = (unsigned short)offsetof(sscanRecord, d70pv);
    prt->papFldDes[sscanRecordT1PV]->size = sizeof(prec->t1pv);
    prt->papFldDes[sscanRecordT1PV]->offset = (unsigned short)offsetof(sscanRecord, t1pv);
    prt->papFldDes[sscanRecordT2PV]->size = sizeof(prec->t2pv);
    prt->papFldDes[sscanRecordT2PV]->offset = (unsigned short)offsetof(sscanRecord, t2pv);
    prt->papFldDes[sscanRecordT3PV]->size = sizeof(prec->t3pv);
    prt->papFldDes[sscanRecordT3PV]->offset = (unsigned short)offsetof(sscanRecord, t3pv);
    prt->papFldDes[sscanRecordT4PV]->size = sizeof(prec->t4pv);
    prt->papFldDes[sscanRecordT4PV]->offset = (unsigned short)offsetof(sscanRecord, t4pv);
    prt->papFldDes[sscanRecordA1PV]->size = sizeof(prec->a1pv);
    prt->papFldDes[sscanRecordA1PV]->offset = (unsigned short)offsetof(sscanRecord, a1pv);
    prt->papFldDes[sscanRecordBSPV]->size = sizeof(prec->bspv);
    prt->papFldDes[sscanRecordBSPV]->offset = (unsigned short)offsetof(sscanRecord, bspv);
    prt->papFldDes[sscanRecordASPV]->size = sizeof(prec->aspv);
    prt->papFldDes[sscanRecordASPV]->offset = (unsigned short)offsetof(sscanRecord, aspv);
    prt->papFldDes[sscanRecordBSWAIT]->size = sizeof(prec->bswait);
    prt->papFldDes[sscanRecordBSWAIT]->offset = (unsigned short)offsetof(sscanRecord, bswait);
    prt->papFldDes[sscanRecordASWAIT]->size = sizeof(prec->aswait);
    prt->papFldDes[sscanRecordASWAIT]->offset = (unsigned short)offsetof(sscanRecord, aswait);
    prt->papFldDes[sscanRecordP1NV]->size = sizeof(prec->p1nv);
    prt->papFldDes[sscanRecordP1NV]->offset = (unsigned short)offsetof(sscanRecord, p1nv);
    prt->papFldDes[sscanRecordP2NV]->size = sizeof(prec->p2nv);
    prt->papFldDes[sscanRecordP2NV]->offset = (unsigned short)offsetof(sscanRecord, p2nv);
    prt->papFldDes[sscanRecordP3NV]->size = sizeof(prec->p3nv);
    prt->papFldDes[sscanRecordP3NV]->offset = (unsigned short)offsetof(sscanRecord, p3nv);
    prt->papFldDes[sscanRecordP4NV]->size = sizeof(prec->p4nv);
    prt->papFldDes[sscanRecordP4NV]->offset = (unsigned short)offsetof(sscanRecord, p4nv);
    prt->papFldDes[sscanRecordR1NV]->size = sizeof(prec->r1nv);
    prt->papFldDes[sscanRecordR1NV]->offset = (unsigned short)offsetof(sscanRecord, r1nv);
    prt->papFldDes[sscanRecordR2NV]->size = sizeof(prec->r2nv);
    prt->papFldDes[sscanRecordR2NV]->offset = (unsigned short)offsetof(sscanRecord, r2nv);
    prt->papFldDes[sscanRecordR3NV]->size = sizeof(prec->r3nv);
    prt->papFldDes[sscanRecordR3NV]->offset = (unsigned short)offsetof(sscanRecord, r3nv);
    prt->papFldDes[sscanRecordR4NV]->size = sizeof(prec->r4nv);
    prt->papFldDes[sscanRecordR4NV]->offset = (unsigned short)offsetof(sscanRecord, r4nv);
    prt->papFldDes[sscanRecordD01NV]->size = sizeof(prec->d01nv);
    prt->papFldDes[sscanRecordD01NV]->offset = (unsigned short)offsetof(sscanRecord, d01nv);
    prt->papFldDes[sscanRecordD02NV]->size = sizeof(prec->d02nv);
    prt->papFldDes[sscanRecordD02NV]->offset = (unsigned short)offsetof(sscanRecord, d02nv);
    prt->papFldDes[sscanRecordD03NV]->size = sizeof(prec->d03nv);
    prt->papFldDes[sscanRecordD03NV]->offset = (unsigned short)offsetof(sscanRecord, d03nv);
    prt->papFldDes[sscanRecordD04NV]->size = sizeof(prec->d04nv);
    prt->papFldDes[sscanRecordD04NV]->offset = (unsigned short)offsetof(sscanRecord, d04nv);
    prt->papFldDes[sscanRecordD05NV]->size = sizeof(prec->d05nv);
    prt->papFldDes[sscanRecordD05NV]->offset = (unsigned short)offsetof(sscanRecord, d05nv);
    prt->papFldDes[sscanRecordD06NV]->size = sizeof(prec->d06nv);
    prt->papFldDes[sscanRecordD06NV]->offset = (unsigned short)offsetof(sscanRecord, d06nv);
    prt->papFldDes[sscanRecordD07NV]->size = sizeof(prec->d07nv);
    prt->papFldDes[sscanRecordD07NV]->offset = (unsigned short)offsetof(sscanRecord, d07nv);
    prt->papFldDes[sscanRecordD08NV]->size = sizeof(prec->d08nv);
    prt->papFldDes[sscanRecordD08NV]->offset = (unsigned short)offsetof(sscanRecord, d08nv);
    prt->papFldDes[sscanRecordD09NV]->size = sizeof(prec->d09nv);
    prt->papFldDes[sscanRecordD09NV]->offset = (unsigned short)offsetof(sscanRecord, d09nv);
    prt->papFldDes[sscanRecordD10NV]->size = sizeof(prec->d10nv);
    prt->papFldDes[sscanRecordD10NV]->offset = (unsigned short)offsetof(sscanRecord, d10nv);
    prt->papFldDes[sscanRecordD11NV]->size = sizeof(prec->d11nv);
    prt->papFldDes[sscanRecordD11NV]->offset = (unsigned short)offsetof(sscanRecord, d11nv);
    prt->papFldDes[sscanRecordD12NV]->size = sizeof(prec->d12nv);
    prt->papFldDes[sscanRecordD12NV]->offset = (unsigned short)offsetof(sscanRecord, d12nv);
    prt->papFldDes[sscanRecordD13NV]->size = sizeof(prec->d13nv);
    prt->papFldDes[sscanRecordD13NV]->offset = (unsigned short)offsetof(sscanRecord, d13nv);
    prt->papFldDes[sscanRecordD14NV]->size = sizeof(prec->d14nv);
    prt->papFldDes[sscanRecordD14NV]->offset = (unsigned short)offsetof(sscanRecord, d14nv);
    prt->papFldDes[sscanRecordD15NV]->size = sizeof(prec->d15nv);
    prt->papFldDes[sscanRecordD15NV]->offset = (unsigned short)offsetof(sscanRecord, d15nv);
    prt->papFldDes[sscanRecordD16NV]->size = sizeof(prec->d16nv);
    prt->papFldDes[sscanRecordD16NV]->offset = (unsigned short)offsetof(sscanRecord, d16nv);
    prt->papFldDes[sscanRecordD17NV]->size = sizeof(prec->d17nv);
    prt->papFldDes[sscanRecordD17NV]->offset = (unsigned short)offsetof(sscanRecord, d17nv);
    prt->papFldDes[sscanRecordD18NV]->size = sizeof(prec->d18nv);
    prt->papFldDes[sscanRecordD18NV]->offset = (unsigned short)offsetof(sscanRecord, d18nv);
    prt->papFldDes[sscanRecordD19NV]->size = sizeof(prec->d19nv);
    prt->papFldDes[sscanRecordD19NV]->offset = (unsigned short)offsetof(sscanRecord, d19nv);
    prt->papFldDes[sscanRecordD20NV]->size = sizeof(prec->d20nv);
    prt->papFldDes[sscanRecordD20NV]->offset = (unsigned short)offsetof(sscanRecord, d20nv);
    prt->papFldDes[sscanRecordD21NV]->size = sizeof(prec->d21nv);
    prt->papFldDes[sscanRecordD21NV]->offset = (unsigned short)offsetof(sscanRecord, d21nv);
    prt->papFldDes[sscanRecordD22NV]->size = sizeof(prec->d22nv);
    prt->papFldDes[sscanRecordD22NV]->offset = (unsigned short)offsetof(sscanRecord, d22nv);
    prt->papFldDes[sscanRecordD23NV]->size = sizeof(prec->d23nv);
    prt->papFldDes[sscanRecordD23NV]->offset = (unsigned short)offsetof(sscanRecord, d23nv);
    prt->papFldDes[sscanRecordD24NV]->size = sizeof(prec->d24nv);
    prt->papFldDes[sscanRecordD24NV]->offset = (unsigned short)offsetof(sscanRecord, d24nv);
    prt->papFldDes[sscanRecordD25NV]->size = sizeof(prec->d25nv);
    prt->papFldDes[sscanRecordD25NV]->offset = (unsigned short)offsetof(sscanRecord, d25nv);
    prt->papFldDes[sscanRecordD26NV]->size = sizeof(prec->d26nv);
    prt->papFldDes[sscanRecordD26NV]->offset = (unsigned short)offsetof(sscanRecord, d26nv);
    prt->papFldDes[sscanRecordD27NV]->size = sizeof(prec->d27nv);
    prt->papFldDes[sscanRecordD27NV]->offset = (unsigned short)offsetof(sscanRecord, d27nv);
    prt->papFldDes[sscanRecordD28NV]->size = sizeof(prec->d28nv);
    prt->papFldDes[sscanRecordD28NV]->offset = (unsigned short)offsetof(sscanRecord, d28nv);
    prt->papFldDes[sscanRecordD29NV]->size = sizeof(prec->d29nv);
    prt->papFldDes[sscanRecordD29NV]->offset = (unsigned short)offsetof(sscanRecord, d29nv);
    prt->papFldDes[sscanRecordD30NV]->size = sizeof(prec->d30nv);
    prt->papFldDes[sscanRecordD30NV]->offset = (unsigned short)offsetof(sscanRecord, d30nv);
    prt->papFldDes[sscanRecordD31NV]->size = sizeof(prec->d31nv);
    prt->papFldDes[sscanRecordD31NV]->offset = (unsigned short)offsetof(sscanRecord, d31nv);
    prt->papFldDes[sscanRecordD32NV]->size = sizeof(prec->d32nv);
    prt->papFldDes[sscanRecordD32NV]->offset = (unsigned short)offsetof(sscanRecord, d32nv);
    prt->papFldDes[sscanRecordD33NV]->size = sizeof(prec->d33nv);
    prt->papFldDes[sscanRecordD33NV]->offset = (unsigned short)offsetof(sscanRecord, d33nv);
    prt->papFldDes[sscanRecordD34NV]->size = sizeof(prec->d34nv);
    prt->papFldDes[sscanRecordD34NV]->offset = (unsigned short)offsetof(sscanRecord, d34nv);
    prt->papFldDes[sscanRecordD35NV]->size = sizeof(prec->d35nv);
    prt->papFldDes[sscanRecordD35NV]->offset = (unsigned short)offsetof(sscanRecord, d35nv);
    prt->papFldDes[sscanRecordD36NV]->size = sizeof(prec->d36nv);
    prt->papFldDes[sscanRecordD36NV]->offset = (unsigned short)offsetof(sscanRecord, d36nv);
    prt->papFldDes[sscanRecordD37NV]->size = sizeof(prec->d37nv);
    prt->papFldDes[sscanRecordD37NV]->offset = (unsigned short)offsetof(sscanRecord, d37nv);
    prt->papFldDes[sscanRecordD38NV]->size = sizeof(prec->d38nv);
    prt->papFldDes[sscanRecordD38NV]->offset = (unsigned short)offsetof(sscanRecord, d38nv);
    prt->papFldDes[sscanRecordD39NV]->size = sizeof(prec->d39nv);
    prt->papFldDes[sscanRecordD39NV]->offset = (unsigned short)offsetof(sscanRecord, d39nv);
    prt->papFldDes[sscanRecordD40NV]->size = sizeof(prec->d40nv);
    prt->papFldDes[sscanRecordD40NV]->offset = (unsigned short)offsetof(sscanRecord, d40nv);
    prt->papFldDes[sscanRecordD41NV]->size = sizeof(prec->d41nv);
    prt->papFldDes[sscanRecordD41NV]->offset = (unsigned short)offsetof(sscanRecord, d41nv);
    prt->papFldDes[sscanRecordD42NV]->size = sizeof(prec->d42nv);
    prt->papFldDes[sscanRecordD42NV]->offset = (unsigned short)offsetof(sscanRecord, d42nv);
    prt->papFldDes[sscanRecordD43NV]->size = sizeof(prec->d43nv);
    prt->papFldDes[sscanRecordD43NV]->offset = (unsigned short)offsetof(sscanRecord, d43nv);
    prt->papFldDes[sscanRecordD44NV]->size = sizeof(prec->d44nv);
    prt->papFldDes[sscanRecordD44NV]->offset = (unsigned short)offsetof(sscanRecord, d44nv);
    prt->papFldDes[sscanRecordD45NV]->size = sizeof(prec->d45nv);
    prt->papFldDes[sscanRecordD45NV]->offset = (unsigned short)offsetof(sscanRecord, d45nv);
    prt->papFldDes[sscanRecordD46NV]->size = sizeof(prec->d46nv);
    prt->papFldDes[sscanRecordD46NV]->offset = (unsigned short)offsetof(sscanRecord, d46nv);
    prt->papFldDes[sscanRecordD47NV]->size = sizeof(prec->d47nv);
    prt->papFldDes[sscanRecordD47NV]->offset = (unsigned short)offsetof(sscanRecord, d47nv);
    prt->papFldDes[sscanRecordD48NV]->size = sizeof(prec->d48nv);
    prt->papFldDes[sscanRecordD48NV]->offset = (unsigned short)offsetof(sscanRecord, d48nv);
    prt->papFldDes[sscanRecordD49NV]->size = sizeof(prec->d49nv);
    prt->papFldDes[sscanRecordD49NV]->offset = (unsigned short)offsetof(sscanRecord, d49nv);
    prt->papFldDes[sscanRecordD50NV]->size = sizeof(prec->d50nv);
    prt->papFldDes[sscanRecordD50NV]->offset = (unsigned short)offsetof(sscanRecord, d50nv);
    prt->papFldDes[sscanRecordD51NV]->size = sizeof(prec->d51nv);
    prt->papFldDes[sscanRecordD51NV]->offset = (unsigned short)offsetof(sscanRecord, d51nv);
    prt->papFldDes[sscanRecordD52NV]->size = sizeof(prec->d52nv);
    prt->papFldDes[sscanRecordD52NV]->offset = (unsigned short)offsetof(sscanRecord, d52nv);
    prt->papFldDes[sscanRecordD53NV]->size = sizeof(prec->d53nv);
    prt->papFldDes[sscanRecordD53NV]->offset = (unsigned short)offsetof(sscanRecord, d53nv);
    prt->papFldDes[sscanRecordD54NV]->size = sizeof(prec->d54nv);
    prt->papFldDes[sscanRecordD54NV]->offset = (unsigned short)offsetof(sscanRecord, d54nv);
    prt->papFldDes[sscanRecordD55NV]->size = sizeof(prec->d55nv);
    prt->papFldDes[sscanRecordD55NV]->offset = (unsigned short)offsetof(sscanRecord, d55nv);
    prt->papFldDes[sscanRecordD56NV]->size = sizeof(prec->d56nv);
    prt->papFldDes[sscanRecordD56NV]->offset = (unsigned short)offsetof(sscanRecord, d56nv);
    prt->papFldDes[sscanRecordD57NV]->size = sizeof(prec->d57nv);
    prt->papFldDes[sscanRecordD57NV]->offset = (unsigned short)offsetof(sscanRecord, d57nv);
    prt->papFldDes[sscanRecordD58NV]->size = sizeof(prec->d58nv);
    prt->papFldDes[sscanRecordD58NV]->offset = (unsigned short)offsetof(sscanRecord, d58nv);
    prt->papFldDes[sscanRecordD59NV]->size = sizeof(prec->d59nv);
    prt->papFldDes[sscanRecordD59NV]->offset = (unsigned short)offsetof(sscanRecord, d59nv);
    prt->papFldDes[sscanRecordD60NV]->size = sizeof(prec->d60nv);
    prt->papFldDes[sscanRecordD60NV]->offset = (unsigned short)offsetof(sscanRecord, d60nv);
    prt->papFldDes[sscanRecordD61NV]->size = sizeof(prec->d61nv);
    prt->papFldDes[sscanRecordD61NV]->offset = (unsigned short)offsetof(sscanRecord, d61nv);
    prt->papFldDes[sscanRecordD62NV]->size = sizeof(prec->d62nv);
    prt->papFldDes[sscanRecordD62NV]->offset = (unsigned short)offsetof(sscanRecord, d62nv);
    prt->papFldDes[sscanRecordD63NV]->size = sizeof(prec->d63nv);
    prt->papFldDes[sscanRecordD63NV]->offset = (unsigned short)offsetof(sscanRecord, d63nv);
    prt->papFldDes[sscanRecordD64NV]->size = sizeof(prec->d64nv);
    prt->papFldDes[sscanRecordD64NV]->offset = (unsigned short)offsetof(sscanRecord, d64nv);
    prt->papFldDes[sscanRecordD65NV]->size = sizeof(prec->d65nv);
    prt->papFldDes[sscanRecordD65NV]->offset = (unsigned short)offsetof(sscanRecord, d65nv);
    prt->papFldDes[sscanRecordD66NV]->size = sizeof(prec->d66nv);
    prt->papFldDes[sscanRecordD66NV]->offset = (unsigned short)offsetof(sscanRecord, d66nv);
    prt->papFldDes[sscanRecordD67NV]->size = sizeof(prec->d67nv);
    prt->papFldDes[sscanRecordD67NV]->offset = (unsigned short)offsetof(sscanRecord, d67nv);
    prt->papFldDes[sscanRecordD68NV]->size = sizeof(prec->d68nv);
    prt->papFldDes[sscanRecordD68NV]->offset = (unsigned short)offsetof(sscanRecord, d68nv);
    prt->papFldDes[sscanRecordD69NV]->size = sizeof(prec->d69nv);
    prt->papFldDes[sscanRecordD69NV]->offset = (unsigned short)offsetof(sscanRecord, d69nv);
    prt->papFldDes[sscanRecordD70NV]->size = sizeof(prec->d70nv);
    prt->papFldDes[sscanRecordD70NV]->offset = (unsigned short)offsetof(sscanRecord, d70nv);
    prt->papFldDes[sscanRecordT1NV]->size = sizeof(prec->t1nv);
    prt->papFldDes[sscanRecordT1NV]->offset = (unsigned short)offsetof(sscanRecord, t1nv);
    prt->papFldDes[sscanRecordT2NV]->size = sizeof(prec->t2nv);
    prt->papFldDes[sscanRecordT2NV]->offset = (unsigned short)offsetof(sscanRecord, t2nv);
    prt->papFldDes[sscanRecordT3NV]->size = sizeof(prec->t3nv);
    prt->papFldDes[sscanRecordT3NV]->offset = (unsigned short)offsetof(sscanRecord, t3nv);
    prt->papFldDes[sscanRecordT4NV]->size = sizeof(prec->t4nv);
    prt->papFldDes[sscanRecordT4NV]->offset = (unsigned short)offsetof(sscanRecord, t4nv);
    prt->papFldDes[sscanRecordA1NV]->size = sizeof(prec->a1nv);
    prt->papFldDes[sscanRecordA1NV]->offset = (unsigned short)offsetof(sscanRecord, a1nv);
    prt->papFldDes[sscanRecordBSNV]->size = sizeof(prec->bsnv);
    prt->papFldDes[sscanRecordBSNV]->offset = (unsigned short)offsetof(sscanRecord, bsnv);
    prt->papFldDes[sscanRecordASNV]->size = sizeof(prec->asnv);
    prt->papFldDes[sscanRecordASNV]->offset = (unsigned short)offsetof(sscanRecord, asnv);
    prt->papFldDes[sscanRecordP1PP]->size = sizeof(prec->p1pp);
    prt->papFldDes[sscanRecordP1PP]->offset = (unsigned short)offsetof(sscanRecord, p1pp);
    prt->papFldDes[sscanRecordP1CV]->size = sizeof(prec->p1cv);
    prt->papFldDes[sscanRecordP1CV]->offset = (unsigned short)offsetof(sscanRecord, p1cv);
    prt->papFldDes[sscanRecordP1DV]->size = sizeof(prec->p1dv);
    prt->papFldDes[sscanRecordP1DV]->offset = (unsigned short)offsetof(sscanRecord, p1dv);
    prt->papFldDes[sscanRecordP1LV]->size = sizeof(prec->p1lv);
    prt->papFldDes[sscanRecordP1LV]->offset = (unsigned short)offsetof(sscanRecord, p1lv);
    prt->papFldDes[sscanRecordP1SP]->size = sizeof(prec->p1sp);
    prt->papFldDes[sscanRecordP1SP]->offset = (unsigned short)offsetof(sscanRecord, p1sp);
    prt->papFldDes[sscanRecordP1SI]->size = sizeof(prec->p1si);
    prt->papFldDes[sscanRecordP1SI]->offset = (unsigned short)offsetof(sscanRecord, p1si);
    prt->papFldDes[sscanRecordP1EP]->size = sizeof(prec->p1ep);
    prt->papFldDes[sscanRecordP1EP]->offset = (unsigned short)offsetof(sscanRecord, p1ep);
    prt->papFldDes[sscanRecordP1CP]->size = sizeof(prec->p1cp);
    prt->papFldDes[sscanRecordP1CP]->offset = (unsigned short)offsetof(sscanRecord, p1cp);
    prt->papFldDes[sscanRecordP1WD]->size = sizeof(prec->p1wd);
    prt->papFldDes[sscanRecordP1WD]->offset = (unsigned short)offsetof(sscanRecord, p1wd);
    prt->papFldDes[sscanRecordR1CV]->size = sizeof(prec->r1cv);
    prt->papFldDes[sscanRecordR1CV]->offset = (unsigned short)offsetof(sscanRecord, r1cv);
    prt->papFldDes[sscanRecordR1LV]->size = sizeof(prec->r1lv);
    prt->papFldDes[sscanRecordR1LV]->offset = (unsigned short)offsetof(sscanRecord, r1lv);
    prt->papFldDes[sscanRecordR1DL]->size = sizeof(prec->r1dl);
    prt->papFldDes[sscanRecordR1DL]->offset = (unsigned short)offsetof(sscanRecord, r1dl);
    prt->papFldDes[sscanRecordP1HR]->size = sizeof(prec->p1hr);
    prt->papFldDes[sscanRecordP1HR]->offset = (unsigned short)offsetof(sscanRecord, p1hr);
    prt->papFldDes[sscanRecordP1LR]->size = sizeof(prec->p1lr);
    prt->papFldDes[sscanRecordP1LR]->offset = (unsigned short)offsetof(sscanRecord, p1lr);
    prt->papFldDes[sscanRecordP1PA]->size = sizeof(prec->p1pa);
    prt->papFldDes[sscanRecordP1PA]->offset = (unsigned short)offsetof(sscanRecord, p1pa);
    prt->papFldDes[sscanRecordP1RA]->size = sizeof(prec->p1ra);
    prt->papFldDes[sscanRecordP1RA]->offset = (unsigned short)offsetof(sscanRecord, p1ra);
    prt->papFldDes[sscanRecordP1CA]->size = sizeof(prec->p1ca);
    prt->papFldDes[sscanRecordP1CA]->offset = (unsigned short)offsetof(sscanRecord, p1ca);
    prt->papFldDes[sscanRecordP1FS]->size = sizeof(prec->p1fs);
    prt->papFldDes[sscanRecordP1FS]->offset = (unsigned short)offsetof(sscanRecord, p1fs);
    prt->papFldDes[sscanRecordP1FI]->size = sizeof(prec->p1fi);
    prt->papFldDes[sscanRecordP1FI]->offset = (unsigned short)offsetof(sscanRecord, p1fi);
    prt->papFldDes[sscanRecordP1FE]->size = sizeof(prec->p1fe);
    prt->papFldDes[sscanRecordP1FE]->offset = (unsigned short)offsetof(sscanRecord, p1fe);
    prt->papFldDes[sscanRecordP1FC]->size = sizeof(prec->p1fc);
    prt->papFldDes[sscanRecordP1FC]->offset = (unsigned short)offsetof(sscanRecord, p1fc);
    prt->papFldDes[sscanRecordP1FW]->size = sizeof(prec->p1fw);
    prt->papFldDes[sscanRecordP1FW]->offset = (unsigned short)offsetof(sscanRecord, p1fw);
    prt->papFldDes[sscanRecordP1SM]->size = sizeof(prec->p1sm);
    prt->papFldDes[sscanRecordP1SM]->offset = (unsigned short)offsetof(sscanRecord, p1sm);
    prt->papFldDes[sscanRecordP1AR]->size = sizeof(prec->p1ar);
    prt->papFldDes[sscanRecordP1AR]->offset = (unsigned short)offsetof(sscanRecord, p1ar);
    prt->papFldDes[sscanRecordP1EU]->size = sizeof(prec->p1eu);
    prt->papFldDes[sscanRecordP1EU]->offset = (unsigned short)offsetof(sscanRecord, p1eu);
    prt->papFldDes[sscanRecordP1PR]->size = sizeof(prec->p1pr);
    prt->papFldDes[sscanRecordP1PR]->offset = (unsigned short)offsetof(sscanRecord, p1pr);
    prt->papFldDes[sscanRecordP2PP]->size = sizeof(prec->p2pp);
    prt->papFldDes[sscanRecordP2PP]->offset = (unsigned short)offsetof(sscanRecord, p2pp);
    prt->papFldDes[sscanRecordP2CV]->size = sizeof(prec->p2cv);
    prt->papFldDes[sscanRecordP2CV]->offset = (unsigned short)offsetof(sscanRecord, p2cv);
    prt->papFldDes[sscanRecordP2DV]->size = sizeof(prec->p2dv);
    prt->papFldDes[sscanRecordP2DV]->offset = (unsigned short)offsetof(sscanRecord, p2dv);
    prt->papFldDes[sscanRecordP2LV]->size = sizeof(prec->p2lv);
    prt->papFldDes[sscanRecordP2LV]->offset = (unsigned short)offsetof(sscanRecord, p2lv);
    prt->papFldDes[sscanRecordP2SP]->size = sizeof(prec->p2sp);
    prt->papFldDes[sscanRecordP2SP]->offset = (unsigned short)offsetof(sscanRecord, p2sp);
    prt->papFldDes[sscanRecordP2SI]->size = sizeof(prec->p2si);
    prt->papFldDes[sscanRecordP2SI]->offset = (unsigned short)offsetof(sscanRecord, p2si);
    prt->papFldDes[sscanRecordP2EP]->size = sizeof(prec->p2ep);
    prt->papFldDes[sscanRecordP2EP]->offset = (unsigned short)offsetof(sscanRecord, p2ep);
    prt->papFldDes[sscanRecordP2CP]->size = sizeof(prec->p2cp);
    prt->papFldDes[sscanRecordP2CP]->offset = (unsigned short)offsetof(sscanRecord, p2cp);
    prt->papFldDes[sscanRecordP2WD]->size = sizeof(prec->p2wd);
    prt->papFldDes[sscanRecordP2WD]->offset = (unsigned short)offsetof(sscanRecord, p2wd);
    prt->papFldDes[sscanRecordR2CV]->size = sizeof(prec->r2cv);
    prt->papFldDes[sscanRecordR2CV]->offset = (unsigned short)offsetof(sscanRecord, r2cv);
    prt->papFldDes[sscanRecordR2LV]->size = sizeof(prec->r2lv);
    prt->papFldDes[sscanRecordR2LV]->offset = (unsigned short)offsetof(sscanRecord, r2lv);
    prt->papFldDes[sscanRecordR2DL]->size = sizeof(prec->r2dl);
    prt->papFldDes[sscanRecordR2DL]->offset = (unsigned short)offsetof(sscanRecord, r2dl);
    prt->papFldDes[sscanRecordP2HR]->size = sizeof(prec->p2hr);
    prt->papFldDes[sscanRecordP2HR]->offset = (unsigned short)offsetof(sscanRecord, p2hr);
    prt->papFldDes[sscanRecordP2LR]->size = sizeof(prec->p2lr);
    prt->papFldDes[sscanRecordP2LR]->offset = (unsigned short)offsetof(sscanRecord, p2lr);
    prt->papFldDes[sscanRecordP2PA]->size = sizeof(prec->p2pa);
    prt->papFldDes[sscanRecordP2PA]->offset = (unsigned short)offsetof(sscanRecord, p2pa);
    prt->papFldDes[sscanRecordP2RA]->size = sizeof(prec->p2ra);
    prt->papFldDes[sscanRecordP2RA]->offset = (unsigned short)offsetof(sscanRecord, p2ra);
    prt->papFldDes[sscanRecordP2CA]->size = sizeof(prec->p2ca);
    prt->papFldDes[sscanRecordP2CA]->offset = (unsigned short)offsetof(sscanRecord, p2ca);
    prt->papFldDes[sscanRecordP2FS]->size = sizeof(prec->p2fs);
    prt->papFldDes[sscanRecordP2FS]->offset = (unsigned short)offsetof(sscanRecord, p2fs);
    prt->papFldDes[sscanRecordP2FI]->size = sizeof(prec->p2fi);
    prt->papFldDes[sscanRecordP2FI]->offset = (unsigned short)offsetof(sscanRecord, p2fi);
    prt->papFldDes[sscanRecordP2FE]->size = sizeof(prec->p2fe);
    prt->papFldDes[sscanRecordP2FE]->offset = (unsigned short)offsetof(sscanRecord, p2fe);
    prt->papFldDes[sscanRecordP2FC]->size = sizeof(prec->p2fc);
    prt->papFldDes[sscanRecordP2FC]->offset = (unsigned short)offsetof(sscanRecord, p2fc);
    prt->papFldDes[sscanRecordP2FW]->size = sizeof(prec->p2fw);
    prt->papFldDes[sscanRecordP2FW]->offset = (unsigned short)offsetof(sscanRecord, p2fw);
    prt->papFldDes[sscanRecordP2SM]->size = sizeof(prec->p2sm);
    prt->papFldDes[sscanRecordP2SM]->offset = (unsigned short)offsetof(sscanRecord, p2sm);
    prt->papFldDes[sscanRecordP2AR]->size = sizeof(prec->p2ar);
    prt->papFldDes[sscanRecordP2AR]->offset = (unsigned short)offsetof(sscanRecord, p2ar);
    prt->papFldDes[sscanRecordP2EU]->size = sizeof(prec->p2eu);
    prt->papFldDes[sscanRecordP2EU]->offset = (unsigned short)offsetof(sscanRecord, p2eu);
    prt->papFldDes[sscanRecordP2PR]->size = sizeof(prec->p2pr);
    prt->papFldDes[sscanRecordP2PR]->offset = (unsigned short)offsetof(sscanRecord, p2pr);
    prt->papFldDes[sscanRecordP3PP]->size = sizeof(prec->p3pp);
    prt->papFldDes[sscanRecordP3PP]->offset = (unsigned short)offsetof(sscanRecord, p3pp);
    prt->papFldDes[sscanRecordP3CV]->size = sizeof(prec->p3cv);
    prt->papFldDes[sscanRecordP3CV]->offset = (unsigned short)offsetof(sscanRecord, p3cv);
    prt->papFldDes[sscanRecordP3DV]->size = sizeof(prec->p3dv);
    prt->papFldDes[sscanRecordP3DV]->offset = (unsigned short)offsetof(sscanRecord, p3dv);
    prt->papFldDes[sscanRecordP3LV]->size = sizeof(prec->p3lv);
    prt->papFldDes[sscanRecordP3LV]->offset = (unsigned short)offsetof(sscanRecord, p3lv);
    prt->papFldDes[sscanRecordP3SP]->size = sizeof(prec->p3sp);
    prt->papFldDes[sscanRecordP3SP]->offset = (unsigned short)offsetof(sscanRecord, p3sp);
    prt->papFldDes[sscanRecordP3SI]->size = sizeof(prec->p3si);
    prt->papFldDes[sscanRecordP3SI]->offset = (unsigned short)offsetof(sscanRecord, p3si);
    prt->papFldDes[sscanRecordP3EP]->size = sizeof(prec->p3ep);
    prt->papFldDes[sscanRecordP3EP]->offset = (unsigned short)offsetof(sscanRecord, p3ep);
    prt->papFldDes[sscanRecordP3CP]->size = sizeof(prec->p3cp);
    prt->papFldDes[sscanRecordP3CP]->offset = (unsigned short)offsetof(sscanRecord, p3cp);
    prt->papFldDes[sscanRecordP3WD]->size = sizeof(prec->p3wd);
    prt->papFldDes[sscanRecordP3WD]->offset = (unsigned short)offsetof(sscanRecord, p3wd);
    prt->papFldDes[sscanRecordR3CV]->size = sizeof(prec->r3cv);
    prt->papFldDes[sscanRecordR3CV]->offset = (unsigned short)offsetof(sscanRecord, r3cv);
    prt->papFldDes[sscanRecordR3LV]->size = sizeof(prec->r3lv);
    prt->papFldDes[sscanRecordR3LV]->offset = (unsigned short)offsetof(sscanRecord, r3lv);
    prt->papFldDes[sscanRecordR3DL]->size = sizeof(prec->r3dl);
    prt->papFldDes[sscanRecordR3DL]->offset = (unsigned short)offsetof(sscanRecord, r3dl);
    prt->papFldDes[sscanRecordP3HR]->size = sizeof(prec->p3hr);
    prt->papFldDes[sscanRecordP3HR]->offset = (unsigned short)offsetof(sscanRecord, p3hr);
    prt->papFldDes[sscanRecordP3LR]->size = sizeof(prec->p3lr);
    prt->papFldDes[sscanRecordP3LR]->offset = (unsigned short)offsetof(sscanRecord, p3lr);
    prt->papFldDes[sscanRecordP3PA]->size = sizeof(prec->p3pa);
    prt->papFldDes[sscanRecordP3PA]->offset = (unsigned short)offsetof(sscanRecord, p3pa);
    prt->papFldDes[sscanRecordP3RA]->size = sizeof(prec->p3ra);
    prt->papFldDes[sscanRecordP3RA]->offset = (unsigned short)offsetof(sscanRecord, p3ra);
    prt->papFldDes[sscanRecordP3CA]->size = sizeof(prec->p3ca);
    prt->papFldDes[sscanRecordP3CA]->offset = (unsigned short)offsetof(sscanRecord, p3ca);
    prt->papFldDes[sscanRecordP3FS]->size = sizeof(prec->p3fs);
    prt->papFldDes[sscanRecordP3FS]->offset = (unsigned short)offsetof(sscanRecord, p3fs);
    prt->papFldDes[sscanRecordP3FI]->size = sizeof(prec->p3fi);
    prt->papFldDes[sscanRecordP3FI]->offset = (unsigned short)offsetof(sscanRecord, p3fi);
    prt->papFldDes[sscanRecordP3FE]->size = sizeof(prec->p3fe);
    prt->papFldDes[sscanRecordP3FE]->offset = (unsigned short)offsetof(sscanRecord, p3fe);
    prt->papFldDes[sscanRecordP3FC]->size = sizeof(prec->p3fc);
    prt->papFldDes[sscanRecordP3FC]->offset = (unsigned short)offsetof(sscanRecord, p3fc);
    prt->papFldDes[sscanRecordP3FW]->size = sizeof(prec->p3fw);
    prt->papFldDes[sscanRecordP3FW]->offset = (unsigned short)offsetof(sscanRecord, p3fw);
    prt->papFldDes[sscanRecordP3SM]->size = sizeof(prec->p3sm);
    prt->papFldDes[sscanRecordP3SM]->offset = (unsigned short)offsetof(sscanRecord, p3sm);
    prt->papFldDes[sscanRecordP3AR]->size = sizeof(prec->p3ar);
    prt->papFldDes[sscanRecordP3AR]->offset = (unsigned short)offsetof(sscanRecord, p3ar);
    prt->papFldDes[sscanRecordP3EU]->size = sizeof(prec->p3eu);
    prt->papFldDes[sscanRecordP3EU]->offset = (unsigned short)offsetof(sscanRecord, p3eu);
    prt->papFldDes[sscanRecordP3PR]->size = sizeof(prec->p3pr);
    prt->papFldDes[sscanRecordP3PR]->offset = (unsigned short)offsetof(sscanRecord, p3pr);
    prt->papFldDes[sscanRecordP4PP]->size = sizeof(prec->p4pp);
    prt->papFldDes[sscanRecordP4PP]->offset = (unsigned short)offsetof(sscanRecord, p4pp);
    prt->papFldDes[sscanRecordP4CV]->size = sizeof(prec->p4cv);
    prt->papFldDes[sscanRecordP4CV]->offset = (unsigned short)offsetof(sscanRecord, p4cv);
    prt->papFldDes[sscanRecordP4DV]->size = sizeof(prec->p4dv);
    prt->papFldDes[sscanRecordP4DV]->offset = (unsigned short)offsetof(sscanRecord, p4dv);
    prt->papFldDes[sscanRecordP4LV]->size = sizeof(prec->p4lv);
    prt->papFldDes[sscanRecordP4LV]->offset = (unsigned short)offsetof(sscanRecord, p4lv);
    prt->papFldDes[sscanRecordP4SP]->size = sizeof(prec->p4sp);
    prt->papFldDes[sscanRecordP4SP]->offset = (unsigned short)offsetof(sscanRecord, p4sp);
    prt->papFldDes[sscanRecordP4SI]->size = sizeof(prec->p4si);
    prt->papFldDes[sscanRecordP4SI]->offset = (unsigned short)offsetof(sscanRecord, p4si);
    prt->papFldDes[sscanRecordP4EP]->size = sizeof(prec->p4ep);
    prt->papFldDes[sscanRecordP4EP]->offset = (unsigned short)offsetof(sscanRecord, p4ep);
    prt->papFldDes[sscanRecordP4CP]->size = sizeof(prec->p4cp);
    prt->papFldDes[sscanRecordP4CP]->offset = (unsigned short)offsetof(sscanRecord, p4cp);
    prt->papFldDes[sscanRecordP4WD]->size = sizeof(prec->p4wd);
    prt->papFldDes[sscanRecordP4WD]->offset = (unsigned short)offsetof(sscanRecord, p4wd);
    prt->papFldDes[sscanRecordR4CV]->size = sizeof(prec->r4cv);
    prt->papFldDes[sscanRecordR4CV]->offset = (unsigned short)offsetof(sscanRecord, r4cv);
    prt->papFldDes[sscanRecordR4LV]->size = sizeof(prec->r4lv);
    prt->papFldDes[sscanRecordR4LV]->offset = (unsigned short)offsetof(sscanRecord, r4lv);
    prt->papFldDes[sscanRecordR4DL]->size = sizeof(prec->r4dl);
    prt->papFldDes[sscanRecordR4DL]->offset = (unsigned short)offsetof(sscanRecord, r4dl);
    prt->papFldDes[sscanRecordP4HR]->size = sizeof(prec->p4hr);
    prt->papFldDes[sscanRecordP4HR]->offset = (unsigned short)offsetof(sscanRecord, p4hr);
    prt->papFldDes[sscanRecordP4LR]->size = sizeof(prec->p4lr);
    prt->papFldDes[sscanRecordP4LR]->offset = (unsigned short)offsetof(sscanRecord, p4lr);
    prt->papFldDes[sscanRecordP4PA]->size = sizeof(prec->p4pa);
    prt->papFldDes[sscanRecordP4PA]->offset = (unsigned short)offsetof(sscanRecord, p4pa);
    prt->papFldDes[sscanRecordP4RA]->size = sizeof(prec->p4ra);
    prt->papFldDes[sscanRecordP4RA]->offset = (unsigned short)offsetof(sscanRecord, p4ra);
    prt->papFldDes[sscanRecordP4CA]->size = sizeof(prec->p4ca);
    prt->papFldDes[sscanRecordP4CA]->offset = (unsigned short)offsetof(sscanRecord, p4ca);
    prt->papFldDes[sscanRecordP4FS]->size = sizeof(prec->p4fs);
    prt->papFldDes[sscanRecordP4FS]->offset = (unsigned short)offsetof(sscanRecord, p4fs);
    prt->papFldDes[sscanRecordP4FI]->size = sizeof(prec->p4fi);
    prt->papFldDes[sscanRecordP4FI]->offset = (unsigned short)offsetof(sscanRecord, p4fi);
    prt->papFldDes[sscanRecordP4FE]->size = sizeof(prec->p4fe);
    prt->papFldDes[sscanRecordP4FE]->offset = (unsigned short)offsetof(sscanRecord, p4fe);
    prt->papFldDes[sscanRecordP4FC]->size = sizeof(prec->p4fc);
    prt->papFldDes[sscanRecordP4FC]->offset = (unsigned short)offsetof(sscanRecord, p4fc);
    prt->papFldDes[sscanRecordP4FW]->size = sizeof(prec->p4fw);
    prt->papFldDes[sscanRecordP4FW]->offset = (unsigned short)offsetof(sscanRecord, p4fw);
    prt->papFldDes[sscanRecordP4SM]->size = sizeof(prec->p4sm);
    prt->papFldDes[sscanRecordP4SM]->offset = (unsigned short)offsetof(sscanRecord, p4sm);
    prt->papFldDes[sscanRecordP4AR]->size = sizeof(prec->p4ar);
    prt->papFldDes[sscanRecordP4AR]->offset = (unsigned short)offsetof(sscanRecord, p4ar);
    prt->papFldDes[sscanRecordP4EU]->size = sizeof(prec->p4eu);
    prt->papFldDes[sscanRecordP4EU]->offset = (unsigned short)offsetof(sscanRecord, p4eu);
    prt->papFldDes[sscanRecordP4PR]->size = sizeof(prec->p4pr);
    prt->papFldDes[sscanRecordP4PR]->offset = (unsigned short)offsetof(sscanRecord, p4pr);
    prt->papFldDes[sscanRecordD01HR]->size = sizeof(prec->d01hr);
    prt->papFldDes[sscanRecordD01HR]->offset = (unsigned short)offsetof(sscanRecord, d01hr);
    prt->papFldDes[sscanRecordD01LR]->size = sizeof(prec->d01lr);
    prt->papFldDes[sscanRecordD01LR]->offset = (unsigned short)offsetof(sscanRecord, d01lr);
    prt->papFldDes[sscanRecordD01DA]->size = sizeof(prec->d01da);
    prt->papFldDes[sscanRecordD01DA]->offset = (unsigned short)offsetof(sscanRecord, d01da);
    prt->papFldDes[sscanRecordD01CA]->size = sizeof(prec->d01ca);
    prt->papFldDes[sscanRecordD01CA]->offset = (unsigned short)offsetof(sscanRecord, d01ca);
    prt->papFldDes[sscanRecordD01CV]->size = sizeof(prec->d01cv);
    prt->papFldDes[sscanRecordD01CV]->offset = (unsigned short)offsetof(sscanRecord, d01cv);
    prt->papFldDes[sscanRecordD01LV]->size = sizeof(prec->d01lv);
    prt->papFldDes[sscanRecordD01LV]->offset = (unsigned short)offsetof(sscanRecord, d01lv);
    prt->papFldDes[sscanRecordD01NE]->size = sizeof(prec->d01ne);
    prt->papFldDes[sscanRecordD01NE]->offset = (unsigned short)offsetof(sscanRecord, d01ne);
    prt->papFldDes[sscanRecordD01EU]->size = sizeof(prec->d01eu);
    prt->papFldDes[sscanRecordD01EU]->offset = (unsigned short)offsetof(sscanRecord, d01eu);
    prt->papFldDes[sscanRecordD01PR]->size = sizeof(prec->d01pr);
    prt->papFldDes[sscanRecordD01PR]->offset = (unsigned short)offsetof(sscanRecord, d01pr);
    prt->papFldDes[sscanRecordD02HR]->size = sizeof(prec->d02hr);
    prt->papFldDes[sscanRecordD02HR]->offset = (unsigned short)offsetof(sscanRecord, d02hr);
    prt->papFldDes[sscanRecordD02LR]->size = sizeof(prec->d02lr);
    prt->papFldDes[sscanRecordD02LR]->offset = (unsigned short)offsetof(sscanRecord, d02lr);
    prt->papFldDes[sscanRecordD02DA]->size = sizeof(prec->d02da);
    prt->papFldDes[sscanRecordD02DA]->offset = (unsigned short)offsetof(sscanRecord, d02da);
    prt->papFldDes[sscanRecordD02CA]->size = sizeof(prec->d02ca);
    prt->papFldDes[sscanRecordD02CA]->offset = (unsigned short)offsetof(sscanRecord, d02ca);
    prt->papFldDes[sscanRecordD02CV]->size = sizeof(prec->d02cv);
    prt->papFldDes[sscanRecordD02CV]->offset = (unsigned short)offsetof(sscanRecord, d02cv);
    prt->papFldDes[sscanRecordD02LV]->size = sizeof(prec->d02lv);
    prt->papFldDes[sscanRecordD02LV]->offset = (unsigned short)offsetof(sscanRecord, d02lv);
    prt->papFldDes[sscanRecordD02NE]->size = sizeof(prec->d02ne);
    prt->papFldDes[sscanRecordD02NE]->offset = (unsigned short)offsetof(sscanRecord, d02ne);
    prt->papFldDes[sscanRecordD02EU]->size = sizeof(prec->d02eu);
    prt->papFldDes[sscanRecordD02EU]->offset = (unsigned short)offsetof(sscanRecord, d02eu);
    prt->papFldDes[sscanRecordD02PR]->size = sizeof(prec->d02pr);
    prt->papFldDes[sscanRecordD02PR]->offset = (unsigned short)offsetof(sscanRecord, d02pr);
    prt->papFldDes[sscanRecordD03HR]->size = sizeof(prec->d03hr);
    prt->papFldDes[sscanRecordD03HR]->offset = (unsigned short)offsetof(sscanRecord, d03hr);
    prt->papFldDes[sscanRecordD03LR]->size = sizeof(prec->d03lr);
    prt->papFldDes[sscanRecordD03LR]->offset = (unsigned short)offsetof(sscanRecord, d03lr);
    prt->papFldDes[sscanRecordD03DA]->size = sizeof(prec->d03da);
    prt->papFldDes[sscanRecordD03DA]->offset = (unsigned short)offsetof(sscanRecord, d03da);
    prt->papFldDes[sscanRecordD03CA]->size = sizeof(prec->d03ca);
    prt->papFldDes[sscanRecordD03CA]->offset = (unsigned short)offsetof(sscanRecord, d03ca);
    prt->papFldDes[sscanRecordD03CV]->size = sizeof(prec->d03cv);
    prt->papFldDes[sscanRecordD03CV]->offset = (unsigned short)offsetof(sscanRecord, d03cv);
    prt->papFldDes[sscanRecordD03LV]->size = sizeof(prec->d03lv);
    prt->papFldDes[sscanRecordD03LV]->offset = (unsigned short)offsetof(sscanRecord, d03lv);
    prt->papFldDes[sscanRecordD03NE]->size = sizeof(prec->d03ne);
    prt->papFldDes[sscanRecordD03NE]->offset = (unsigned short)offsetof(sscanRecord, d03ne);
    prt->papFldDes[sscanRecordD03EU]->size = sizeof(prec->d03eu);
    prt->papFldDes[sscanRecordD03EU]->offset = (unsigned short)offsetof(sscanRecord, d03eu);
    prt->papFldDes[sscanRecordD03PR]->size = sizeof(prec->d03pr);
    prt->papFldDes[sscanRecordD03PR]->offset = (unsigned short)offsetof(sscanRecord, d03pr);
    prt->papFldDes[sscanRecordD04HR]->size = sizeof(prec->d04hr);
    prt->papFldDes[sscanRecordD04HR]->offset = (unsigned short)offsetof(sscanRecord, d04hr);
    prt->papFldDes[sscanRecordD04LR]->size = sizeof(prec->d04lr);
    prt->papFldDes[sscanRecordD04LR]->offset = (unsigned short)offsetof(sscanRecord, d04lr);
    prt->papFldDes[sscanRecordD04DA]->size = sizeof(prec->d04da);
    prt->papFldDes[sscanRecordD04DA]->offset = (unsigned short)offsetof(sscanRecord, d04da);
    prt->papFldDes[sscanRecordD04CA]->size = sizeof(prec->d04ca);
    prt->papFldDes[sscanRecordD04CA]->offset = (unsigned short)offsetof(sscanRecord, d04ca);
    prt->papFldDes[sscanRecordD04CV]->size = sizeof(prec->d04cv);
    prt->papFldDes[sscanRecordD04CV]->offset = (unsigned short)offsetof(sscanRecord, d04cv);
    prt->papFldDes[sscanRecordD04LV]->size = sizeof(prec->d04lv);
    prt->papFldDes[sscanRecordD04LV]->offset = (unsigned short)offsetof(sscanRecord, d04lv);
    prt->papFldDes[sscanRecordD04NE]->size = sizeof(prec->d04ne);
    prt->papFldDes[sscanRecordD04NE]->offset = (unsigned short)offsetof(sscanRecord, d04ne);
    prt->papFldDes[sscanRecordD04EU]->size = sizeof(prec->d04eu);
    prt->papFldDes[sscanRecordD04EU]->offset = (unsigned short)offsetof(sscanRecord, d04eu);
    prt->papFldDes[sscanRecordD04PR]->size = sizeof(prec->d04pr);
    prt->papFldDes[sscanRecordD04PR]->offset = (unsigned short)offsetof(sscanRecord, d04pr);
    prt->papFldDes[sscanRecordD05HR]->size = sizeof(prec->d05hr);
    prt->papFldDes[sscanRecordD05HR]->offset = (unsigned short)offsetof(sscanRecord, d05hr);
    prt->papFldDes[sscanRecordD05LR]->size = sizeof(prec->d05lr);
    prt->papFldDes[sscanRecordD05LR]->offset = (unsigned short)offsetof(sscanRecord, d05lr);
    prt->papFldDes[sscanRecordD05DA]->size = sizeof(prec->d05da);
    prt->papFldDes[sscanRecordD05DA]->offset = (unsigned short)offsetof(sscanRecord, d05da);
    prt->papFldDes[sscanRecordD05CA]->size = sizeof(prec->d05ca);
    prt->papFldDes[sscanRecordD05CA]->offset = (unsigned short)offsetof(sscanRecord, d05ca);
    prt->papFldDes[sscanRecordD05CV]->size = sizeof(prec->d05cv);
    prt->papFldDes[sscanRecordD05CV]->offset = (unsigned short)offsetof(sscanRecord, d05cv);
    prt->papFldDes[sscanRecordD05LV]->size = sizeof(prec->d05lv);
    prt->papFldDes[sscanRecordD05LV]->offset = (unsigned short)offsetof(sscanRecord, d05lv);
    prt->papFldDes[sscanRecordD05NE]->size = sizeof(prec->d05ne);
    prt->papFldDes[sscanRecordD05NE]->offset = (unsigned short)offsetof(sscanRecord, d05ne);
    prt->papFldDes[sscanRecordD05EU]->size = sizeof(prec->d05eu);
    prt->papFldDes[sscanRecordD05EU]->offset = (unsigned short)offsetof(sscanRecord, d05eu);
    prt->papFldDes[sscanRecordD05PR]->size = sizeof(prec->d05pr);
    prt->papFldDes[sscanRecordD05PR]->offset = (unsigned short)offsetof(sscanRecord, d05pr);
    prt->papFldDes[sscanRecordD06HR]->size = sizeof(prec->d06hr);
    prt->papFldDes[sscanRecordD06HR]->offset = (unsigned short)offsetof(sscanRecord, d06hr);
    prt->papFldDes[sscanRecordD06LR]->size = sizeof(prec->d06lr);
    prt->papFldDes[sscanRecordD06LR]->offset = (unsigned short)offsetof(sscanRecord, d06lr);
    prt->papFldDes[sscanRecordD06DA]->size = sizeof(prec->d06da);
    prt->papFldDes[sscanRecordD06DA]->offset = (unsigned short)offsetof(sscanRecord, d06da);
    prt->papFldDes[sscanRecordD06CA]->size = sizeof(prec->d06ca);
    prt->papFldDes[sscanRecordD06CA]->offset = (unsigned short)offsetof(sscanRecord, d06ca);
    prt->papFldDes[sscanRecordD06CV]->size = sizeof(prec->d06cv);
    prt->papFldDes[sscanRecordD06CV]->offset = (unsigned short)offsetof(sscanRecord, d06cv);
    prt->papFldDes[sscanRecordD06LV]->size = sizeof(prec->d06lv);
    prt->papFldDes[sscanRecordD06LV]->offset = (unsigned short)offsetof(sscanRecord, d06lv);
    prt->papFldDes[sscanRecordD06NE]->size = sizeof(prec->d06ne);
    prt->papFldDes[sscanRecordD06NE]->offset = (unsigned short)offsetof(sscanRecord, d06ne);
    prt->papFldDes[sscanRecordD06EU]->size = sizeof(prec->d06eu);
    prt->papFldDes[sscanRecordD06EU]->offset = (unsigned short)offsetof(sscanRecord, d06eu);
    prt->papFldDes[sscanRecordD06PR]->size = sizeof(prec->d06pr);
    prt->papFldDes[sscanRecordD06PR]->offset = (unsigned short)offsetof(sscanRecord, d06pr);
    prt->papFldDes[sscanRecordD07HR]->size = sizeof(prec->d07hr);
    prt->papFldDes[sscanRecordD07HR]->offset = (unsigned short)offsetof(sscanRecord, d07hr);
    prt->papFldDes[sscanRecordD07LR]->size = sizeof(prec->d07lr);
    prt->papFldDes[sscanRecordD07LR]->offset = (unsigned short)offsetof(sscanRecord, d07lr);
    prt->papFldDes[sscanRecordD07DA]->size = sizeof(prec->d07da);
    prt->papFldDes[sscanRecordD07DA]->offset = (unsigned short)offsetof(sscanRecord, d07da);
    prt->papFldDes[sscanRecordD07CA]->size = sizeof(prec->d07ca);
    prt->papFldDes[sscanRecordD07CA]->offset = (unsigned short)offsetof(sscanRecord, d07ca);
    prt->papFldDes[sscanRecordD07CV]->size = sizeof(prec->d07cv);
    prt->papFldDes[sscanRecordD07CV]->offset = (unsigned short)offsetof(sscanRecord, d07cv);
    prt->papFldDes[sscanRecordD07LV]->size = sizeof(prec->d07lv);
    prt->papFldDes[sscanRecordD07LV]->offset = (unsigned short)offsetof(sscanRecord, d07lv);
    prt->papFldDes[sscanRecordD07NE]->size = sizeof(prec->d07ne);
    prt->papFldDes[sscanRecordD07NE]->offset = (unsigned short)offsetof(sscanRecord, d07ne);
    prt->papFldDes[sscanRecordD07EU]->size = sizeof(prec->d07eu);
    prt->papFldDes[sscanRecordD07EU]->offset = (unsigned short)offsetof(sscanRecord, d07eu);
    prt->papFldDes[sscanRecordD07PR]->size = sizeof(prec->d07pr);
    prt->papFldDes[sscanRecordD07PR]->offset = (unsigned short)offsetof(sscanRecord, d07pr);
    prt->papFldDes[sscanRecordD08HR]->size = sizeof(prec->d08hr);
    prt->papFldDes[sscanRecordD08HR]->offset = (unsigned short)offsetof(sscanRecord, d08hr);
    prt->papFldDes[sscanRecordD08LR]->size = sizeof(prec->d08lr);
    prt->papFldDes[sscanRecordD08LR]->offset = (unsigned short)offsetof(sscanRecord, d08lr);
    prt->papFldDes[sscanRecordD08DA]->size = sizeof(prec->d08da);
    prt->papFldDes[sscanRecordD08DA]->offset = (unsigned short)offsetof(sscanRecord, d08da);
    prt->papFldDes[sscanRecordD08CA]->size = sizeof(prec->d08ca);
    prt->papFldDes[sscanRecordD08CA]->offset = (unsigned short)offsetof(sscanRecord, d08ca);
    prt->papFldDes[sscanRecordD08CV]->size = sizeof(prec->d08cv);
    prt->papFldDes[sscanRecordD08CV]->offset = (unsigned short)offsetof(sscanRecord, d08cv);
    prt->papFldDes[sscanRecordD08LV]->size = sizeof(prec->d08lv);
    prt->papFldDes[sscanRecordD08LV]->offset = (unsigned short)offsetof(sscanRecord, d08lv);
    prt->papFldDes[sscanRecordD08NE]->size = sizeof(prec->d08ne);
    prt->papFldDes[sscanRecordD08NE]->offset = (unsigned short)offsetof(sscanRecord, d08ne);
    prt->papFldDes[sscanRecordD08EU]->size = sizeof(prec->d08eu);
    prt->papFldDes[sscanRecordD08EU]->offset = (unsigned short)offsetof(sscanRecord, d08eu);
    prt->papFldDes[sscanRecordD08PR]->size = sizeof(prec->d08pr);
    prt->papFldDes[sscanRecordD08PR]->offset = (unsigned short)offsetof(sscanRecord, d08pr);
    prt->papFldDes[sscanRecordD09HR]->size = sizeof(prec->d09hr);
    prt->papFldDes[sscanRecordD09HR]->offset = (unsigned short)offsetof(sscanRecord, d09hr);
    prt->papFldDes[sscanRecordD09LR]->size = sizeof(prec->d09lr);
    prt->papFldDes[sscanRecordD09LR]->offset = (unsigned short)offsetof(sscanRecord, d09lr);
    prt->papFldDes[sscanRecordD09DA]->size = sizeof(prec->d09da);
    prt->papFldDes[sscanRecordD09DA]->offset = (unsigned short)offsetof(sscanRecord, d09da);
    prt->papFldDes[sscanRecordD09CA]->size = sizeof(prec->d09ca);
    prt->papFldDes[sscanRecordD09CA]->offset = (unsigned short)offsetof(sscanRecord, d09ca);
    prt->papFldDes[sscanRecordD09CV]->size = sizeof(prec->d09cv);
    prt->papFldDes[sscanRecordD09CV]->offset = (unsigned short)offsetof(sscanRecord, d09cv);
    prt->papFldDes[sscanRecordD09LV]->size = sizeof(prec->d09lv);
    prt->papFldDes[sscanRecordD09LV]->offset = (unsigned short)offsetof(sscanRecord, d09lv);
    prt->papFldDes[sscanRecordD09NE]->size = sizeof(prec->d09ne);
    prt->papFldDes[sscanRecordD09NE]->offset = (unsigned short)offsetof(sscanRecord, d09ne);
    prt->papFldDes[sscanRecordD09EU]->size = sizeof(prec->d09eu);
    prt->papFldDes[sscanRecordD09EU]->offset = (unsigned short)offsetof(sscanRecord, d09eu);
    prt->papFldDes[sscanRecordD09PR]->size = sizeof(prec->d09pr);
    prt->papFldDes[sscanRecordD09PR]->offset = (unsigned short)offsetof(sscanRecord, d09pr);
    prt->papFldDes[sscanRecordD10HR]->size = sizeof(prec->d10hr);
    prt->papFldDes[sscanRecordD10HR]->offset = (unsigned short)offsetof(sscanRecord, d10hr);
    prt->papFldDes[sscanRecordD10LR]->size = sizeof(prec->d10lr);
    prt->papFldDes[sscanRecordD10LR]->offset = (unsigned short)offsetof(sscanRecord, d10lr);
    prt->papFldDes[sscanRecordD10DA]->size = sizeof(prec->d10da);
    prt->papFldDes[sscanRecordD10DA]->offset = (unsigned short)offsetof(sscanRecord, d10da);
    prt->papFldDes[sscanRecordD10CA]->size = sizeof(prec->d10ca);
    prt->papFldDes[sscanRecordD10CA]->offset = (unsigned short)offsetof(sscanRecord, d10ca);
    prt->papFldDes[sscanRecordD10CV]->size = sizeof(prec->d10cv);
    prt->papFldDes[sscanRecordD10CV]->offset = (unsigned short)offsetof(sscanRecord, d10cv);
    prt->papFldDes[sscanRecordD10LV]->size = sizeof(prec->d10lv);
    prt->papFldDes[sscanRecordD10LV]->offset = (unsigned short)offsetof(sscanRecord, d10lv);
    prt->papFldDes[sscanRecordD10NE]->size = sizeof(prec->d10ne);
    prt->papFldDes[sscanRecordD10NE]->offset = (unsigned short)offsetof(sscanRecord, d10ne);
    prt->papFldDes[sscanRecordD10EU]->size = sizeof(prec->d10eu);
    prt->papFldDes[sscanRecordD10EU]->offset = (unsigned short)offsetof(sscanRecord, d10eu);
    prt->papFldDes[sscanRecordD10PR]->size = sizeof(prec->d10pr);
    prt->papFldDes[sscanRecordD10PR]->offset = (unsigned short)offsetof(sscanRecord, d10pr);
    prt->papFldDes[sscanRecordD11HR]->size = sizeof(prec->d11hr);
    prt->papFldDes[sscanRecordD11HR]->offset = (unsigned short)offsetof(sscanRecord, d11hr);
    prt->papFldDes[sscanRecordD11LR]->size = sizeof(prec->d11lr);
    prt->papFldDes[sscanRecordD11LR]->offset = (unsigned short)offsetof(sscanRecord, d11lr);
    prt->papFldDes[sscanRecordD11DA]->size = sizeof(prec->d11da);
    prt->papFldDes[sscanRecordD11DA]->offset = (unsigned short)offsetof(sscanRecord, d11da);
    prt->papFldDes[sscanRecordD11CA]->size = sizeof(prec->d11ca);
    prt->papFldDes[sscanRecordD11CA]->offset = (unsigned short)offsetof(sscanRecord, d11ca);
    prt->papFldDes[sscanRecordD11CV]->size = sizeof(prec->d11cv);
    prt->papFldDes[sscanRecordD11CV]->offset = (unsigned short)offsetof(sscanRecord, d11cv);
    prt->papFldDes[sscanRecordD11LV]->size = sizeof(prec->d11lv);
    prt->papFldDes[sscanRecordD11LV]->offset = (unsigned short)offsetof(sscanRecord, d11lv);
    prt->papFldDes[sscanRecordD11NE]->size = sizeof(prec->d11ne);
    prt->papFldDes[sscanRecordD11NE]->offset = (unsigned short)offsetof(sscanRecord, d11ne);
    prt->papFldDes[sscanRecordD11EU]->size = sizeof(prec->d11eu);
    prt->papFldDes[sscanRecordD11EU]->offset = (unsigned short)offsetof(sscanRecord, d11eu);
    prt->papFldDes[sscanRecordD11PR]->size = sizeof(prec->d11pr);
    prt->papFldDes[sscanRecordD11PR]->offset = (unsigned short)offsetof(sscanRecord, d11pr);
    prt->papFldDes[sscanRecordD12HR]->size = sizeof(prec->d12hr);
    prt->papFldDes[sscanRecordD12HR]->offset = (unsigned short)offsetof(sscanRecord, d12hr);
    prt->papFldDes[sscanRecordD12LR]->size = sizeof(prec->d12lr);
    prt->papFldDes[sscanRecordD12LR]->offset = (unsigned short)offsetof(sscanRecord, d12lr);
    prt->papFldDes[sscanRecordD12DA]->size = sizeof(prec->d12da);
    prt->papFldDes[sscanRecordD12DA]->offset = (unsigned short)offsetof(sscanRecord, d12da);
    prt->papFldDes[sscanRecordD12CA]->size = sizeof(prec->d12ca);
    prt->papFldDes[sscanRecordD12CA]->offset = (unsigned short)offsetof(sscanRecord, d12ca);
    prt->papFldDes[sscanRecordD12CV]->size = sizeof(prec->d12cv);
    prt->papFldDes[sscanRecordD12CV]->offset = (unsigned short)offsetof(sscanRecord, d12cv);
    prt->papFldDes[sscanRecordD12LV]->size = sizeof(prec->d12lv);
    prt->papFldDes[sscanRecordD12LV]->offset = (unsigned short)offsetof(sscanRecord, d12lv);
    prt->papFldDes[sscanRecordD12NE]->size = sizeof(prec->d12ne);
    prt->papFldDes[sscanRecordD12NE]->offset = (unsigned short)offsetof(sscanRecord, d12ne);
    prt->papFldDes[sscanRecordD12EU]->size = sizeof(prec->d12eu);
    prt->papFldDes[sscanRecordD12EU]->offset = (unsigned short)offsetof(sscanRecord, d12eu);
    prt->papFldDes[sscanRecordD12PR]->size = sizeof(prec->d12pr);
    prt->papFldDes[sscanRecordD12PR]->offset = (unsigned short)offsetof(sscanRecord, d12pr);
    prt->papFldDes[sscanRecordD13HR]->size = sizeof(prec->d13hr);
    prt->papFldDes[sscanRecordD13HR]->offset = (unsigned short)offsetof(sscanRecord, d13hr);
    prt->papFldDes[sscanRecordD13LR]->size = sizeof(prec->d13lr);
    prt->papFldDes[sscanRecordD13LR]->offset = (unsigned short)offsetof(sscanRecord, d13lr);
    prt->papFldDes[sscanRecordD13DA]->size = sizeof(prec->d13da);
    prt->papFldDes[sscanRecordD13DA]->offset = (unsigned short)offsetof(sscanRecord, d13da);
    prt->papFldDes[sscanRecordD13CA]->size = sizeof(prec->d13ca);
    prt->papFldDes[sscanRecordD13CA]->offset = (unsigned short)offsetof(sscanRecord, d13ca);
    prt->papFldDes[sscanRecordD13CV]->size = sizeof(prec->d13cv);
    prt->papFldDes[sscanRecordD13CV]->offset = (unsigned short)offsetof(sscanRecord, d13cv);
    prt->papFldDes[sscanRecordD13LV]->size = sizeof(prec->d13lv);
    prt->papFldDes[sscanRecordD13LV]->offset = (unsigned short)offsetof(sscanRecord, d13lv);
    prt->papFldDes[sscanRecordD13NE]->size = sizeof(prec->d13ne);
    prt->papFldDes[sscanRecordD13NE]->offset = (unsigned short)offsetof(sscanRecord, d13ne);
    prt->papFldDes[sscanRecordD13EU]->size = sizeof(prec->d13eu);
    prt->papFldDes[sscanRecordD13EU]->offset = (unsigned short)offsetof(sscanRecord, d13eu);
    prt->papFldDes[sscanRecordD13PR]->size = sizeof(prec->d13pr);
    prt->papFldDes[sscanRecordD13PR]->offset = (unsigned short)offsetof(sscanRecord, d13pr);
    prt->papFldDes[sscanRecordD14HR]->size = sizeof(prec->d14hr);
    prt->papFldDes[sscanRecordD14HR]->offset = (unsigned short)offsetof(sscanRecord, d14hr);
    prt->papFldDes[sscanRecordD14LR]->size = sizeof(prec->d14lr);
    prt->papFldDes[sscanRecordD14LR]->offset = (unsigned short)offsetof(sscanRecord, d14lr);
    prt->papFldDes[sscanRecordD14DA]->size = sizeof(prec->d14da);
    prt->papFldDes[sscanRecordD14DA]->offset = (unsigned short)offsetof(sscanRecord, d14da);
    prt->papFldDes[sscanRecordD14CA]->size = sizeof(prec->d14ca);
    prt->papFldDes[sscanRecordD14CA]->offset = (unsigned short)offsetof(sscanRecord, d14ca);
    prt->papFldDes[sscanRecordD14CV]->size = sizeof(prec->d14cv);
    prt->papFldDes[sscanRecordD14CV]->offset = (unsigned short)offsetof(sscanRecord, d14cv);
    prt->papFldDes[sscanRecordD14LV]->size = sizeof(prec->d14lv);
    prt->papFldDes[sscanRecordD14LV]->offset = (unsigned short)offsetof(sscanRecord, d14lv);
    prt->papFldDes[sscanRecordD14NE]->size = sizeof(prec->d14ne);
    prt->papFldDes[sscanRecordD14NE]->offset = (unsigned short)offsetof(sscanRecord, d14ne);
    prt->papFldDes[sscanRecordD14EU]->size = sizeof(prec->d14eu);
    prt->papFldDes[sscanRecordD14EU]->offset = (unsigned short)offsetof(sscanRecord, d14eu);
    prt->papFldDes[sscanRecordD14PR]->size = sizeof(prec->d14pr);
    prt->papFldDes[sscanRecordD14PR]->offset = (unsigned short)offsetof(sscanRecord, d14pr);
    prt->papFldDes[sscanRecordD15HR]->size = sizeof(prec->d15hr);
    prt->papFldDes[sscanRecordD15HR]->offset = (unsigned short)offsetof(sscanRecord, d15hr);
    prt->papFldDes[sscanRecordD15LR]->size = sizeof(prec->d15lr);
    prt->papFldDes[sscanRecordD15LR]->offset = (unsigned short)offsetof(sscanRecord, d15lr);
    prt->papFldDes[sscanRecordD15DA]->size = sizeof(prec->d15da);
    prt->papFldDes[sscanRecordD15DA]->offset = (unsigned short)offsetof(sscanRecord, d15da);
    prt->papFldDes[sscanRecordD15CA]->size = sizeof(prec->d15ca);
    prt->papFldDes[sscanRecordD15CA]->offset = (unsigned short)offsetof(sscanRecord, d15ca);
    prt->papFldDes[sscanRecordD15CV]->size = sizeof(prec->d15cv);
    prt->papFldDes[sscanRecordD15CV]->offset = (unsigned short)offsetof(sscanRecord, d15cv);
    prt->papFldDes[sscanRecordD15LV]->size = sizeof(prec->d15lv);
    prt->papFldDes[sscanRecordD15LV]->offset = (unsigned short)offsetof(sscanRecord, d15lv);
    prt->papFldDes[sscanRecordD15NE]->size = sizeof(prec->d15ne);
    prt->papFldDes[sscanRecordD15NE]->offset = (unsigned short)offsetof(sscanRecord, d15ne);
    prt->papFldDes[sscanRecordD15EU]->size = sizeof(prec->d15eu);
    prt->papFldDes[sscanRecordD15EU]->offset = (unsigned short)offsetof(sscanRecord, d15eu);
    prt->papFldDes[sscanRecordD15PR]->size = sizeof(prec->d15pr);
    prt->papFldDes[sscanRecordD15PR]->offset = (unsigned short)offsetof(sscanRecord, d15pr);
    prt->papFldDes[sscanRecordD16HR]->size = sizeof(prec->d16hr);
    prt->papFldDes[sscanRecordD16HR]->offset = (unsigned short)offsetof(sscanRecord, d16hr);
    prt->papFldDes[sscanRecordD16LR]->size = sizeof(prec->d16lr);
    prt->papFldDes[sscanRecordD16LR]->offset = (unsigned short)offsetof(sscanRecord, d16lr);
    prt->papFldDes[sscanRecordD16DA]->size = sizeof(prec->d16da);
    prt->papFldDes[sscanRecordD16DA]->offset = (unsigned short)offsetof(sscanRecord, d16da);
    prt->papFldDes[sscanRecordD16CA]->size = sizeof(prec->d16ca);
    prt->papFldDes[sscanRecordD16CA]->offset = (unsigned short)offsetof(sscanRecord, d16ca);
    prt->papFldDes[sscanRecordD16CV]->size = sizeof(prec->d16cv);
    prt->papFldDes[sscanRecordD16CV]->offset = (unsigned short)offsetof(sscanRecord, d16cv);
    prt->papFldDes[sscanRecordD16LV]->size = sizeof(prec->d16lv);
    prt->papFldDes[sscanRecordD16LV]->offset = (unsigned short)offsetof(sscanRecord, d16lv);
    prt->papFldDes[sscanRecordD16NE]->size = sizeof(prec->d16ne);
    prt->papFldDes[sscanRecordD16NE]->offset = (unsigned short)offsetof(sscanRecord, d16ne);
    prt->papFldDes[sscanRecordD16EU]->size = sizeof(prec->d16eu);
    prt->papFldDes[sscanRecordD16EU]->offset = (unsigned short)offsetof(sscanRecord, d16eu);
    prt->papFldDes[sscanRecordD16PR]->size = sizeof(prec->d16pr);
    prt->papFldDes[sscanRecordD16PR]->offset = (unsigned short)offsetof(sscanRecord, d16pr);
    prt->papFldDes[sscanRecordD17HR]->size = sizeof(prec->d17hr);
    prt->papFldDes[sscanRecordD17HR]->offset = (unsigned short)offsetof(sscanRecord, d17hr);
    prt->papFldDes[sscanRecordD17LR]->size = sizeof(prec->d17lr);
    prt->papFldDes[sscanRecordD17LR]->offset = (unsigned short)offsetof(sscanRecord, d17lr);
    prt->papFldDes[sscanRecordD17DA]->size = sizeof(prec->d17da);
    prt->papFldDes[sscanRecordD17DA]->offset = (unsigned short)offsetof(sscanRecord, d17da);
    prt->papFldDes[sscanRecordD17CA]->size = sizeof(prec->d17ca);
    prt->papFldDes[sscanRecordD17CA]->offset = (unsigned short)offsetof(sscanRecord, d17ca);
    prt->papFldDes[sscanRecordD17CV]->size = sizeof(prec->d17cv);
    prt->papFldDes[sscanRecordD17CV]->offset = (unsigned short)offsetof(sscanRecord, d17cv);
    prt->papFldDes[sscanRecordD17LV]->size = sizeof(prec->d17lv);
    prt->papFldDes[sscanRecordD17LV]->offset = (unsigned short)offsetof(sscanRecord, d17lv);
    prt->papFldDes[sscanRecordD17NE]->size = sizeof(prec->d17ne);
    prt->papFldDes[sscanRecordD17NE]->offset = (unsigned short)offsetof(sscanRecord, d17ne);
    prt->papFldDes[sscanRecordD17EU]->size = sizeof(prec->d17eu);
    prt->papFldDes[sscanRecordD17EU]->offset = (unsigned short)offsetof(sscanRecord, d17eu);
    prt->papFldDes[sscanRecordD17PR]->size = sizeof(prec->d17pr);
    prt->papFldDes[sscanRecordD17PR]->offset = (unsigned short)offsetof(sscanRecord, d17pr);
    prt->papFldDes[sscanRecordD18HR]->size = sizeof(prec->d18hr);
    prt->papFldDes[sscanRecordD18HR]->offset = (unsigned short)offsetof(sscanRecord, d18hr);
    prt->papFldDes[sscanRecordD18LR]->size = sizeof(prec->d18lr);
    prt->papFldDes[sscanRecordD18LR]->offset = (unsigned short)offsetof(sscanRecord, d18lr);
    prt->papFldDes[sscanRecordD18DA]->size = sizeof(prec->d18da);
    prt->papFldDes[sscanRecordD18DA]->offset = (unsigned short)offsetof(sscanRecord, d18da);
    prt->papFldDes[sscanRecordD18CA]->size = sizeof(prec->d18ca);
    prt->papFldDes[sscanRecordD18CA]->offset = (unsigned short)offsetof(sscanRecord, d18ca);
    prt->papFldDes[sscanRecordD18CV]->size = sizeof(prec->d18cv);
    prt->papFldDes[sscanRecordD18CV]->offset = (unsigned short)offsetof(sscanRecord, d18cv);
    prt->papFldDes[sscanRecordD18LV]->size = sizeof(prec->d18lv);
    prt->papFldDes[sscanRecordD18LV]->offset = (unsigned short)offsetof(sscanRecord, d18lv);
    prt->papFldDes[sscanRecordD18NE]->size = sizeof(prec->d18ne);
    prt->papFldDes[sscanRecordD18NE]->offset = (unsigned short)offsetof(sscanRecord, d18ne);
    prt->papFldDes[sscanRecordD18EU]->size = sizeof(prec->d18eu);
    prt->papFldDes[sscanRecordD18EU]->offset = (unsigned short)offsetof(sscanRecord, d18eu);
    prt->papFldDes[sscanRecordD18PR]->size = sizeof(prec->d18pr);
    prt->papFldDes[sscanRecordD18PR]->offset = (unsigned short)offsetof(sscanRecord, d18pr);
    prt->papFldDes[sscanRecordD19HR]->size = sizeof(prec->d19hr);
    prt->papFldDes[sscanRecordD19HR]->offset = (unsigned short)offsetof(sscanRecord, d19hr);
    prt->papFldDes[sscanRecordD19LR]->size = sizeof(prec->d19lr);
    prt->papFldDes[sscanRecordD19LR]->offset = (unsigned short)offsetof(sscanRecord, d19lr);
    prt->papFldDes[sscanRecordD19DA]->size = sizeof(prec->d19da);
    prt->papFldDes[sscanRecordD19DA]->offset = (unsigned short)offsetof(sscanRecord, d19da);
    prt->papFldDes[sscanRecordD19CA]->size = sizeof(prec->d19ca);
    prt->papFldDes[sscanRecordD19CA]->offset = (unsigned short)offsetof(sscanRecord, d19ca);
    prt->papFldDes[sscanRecordD19CV]->size = sizeof(prec->d19cv);
    prt->papFldDes[sscanRecordD19CV]->offset = (unsigned short)offsetof(sscanRecord, d19cv);
    prt->papFldDes[sscanRecordD19LV]->size = sizeof(prec->d19lv);
    prt->papFldDes[sscanRecordD19LV]->offset = (unsigned short)offsetof(sscanRecord, d19lv);
    prt->papFldDes[sscanRecordD19NE]->size = sizeof(prec->d19ne);
    prt->papFldDes[sscanRecordD19NE]->offset = (unsigned short)offsetof(sscanRecord, d19ne);
    prt->papFldDes[sscanRecordD19EU]->size = sizeof(prec->d19eu);
    prt->papFldDes[sscanRecordD19EU]->offset = (unsigned short)offsetof(sscanRecord, d19eu);
    prt->papFldDes[sscanRecordD19PR]->size = sizeof(prec->d19pr);
    prt->papFldDes[sscanRecordD19PR]->offset = (unsigned short)offsetof(sscanRecord, d19pr);
    prt->papFldDes[sscanRecordD20HR]->size = sizeof(prec->d20hr);
    prt->papFldDes[sscanRecordD20HR]->offset = (unsigned short)offsetof(sscanRecord, d20hr);
    prt->papFldDes[sscanRecordD20LR]->size = sizeof(prec->d20lr);
    prt->papFldDes[sscanRecordD20LR]->offset = (unsigned short)offsetof(sscanRecord, d20lr);
    prt->papFldDes[sscanRecordD20DA]->size = sizeof(prec->d20da);
    prt->papFldDes[sscanRecordD20DA]->offset = (unsigned short)offsetof(sscanRecord, d20da);
    prt->papFldDes[sscanRecordD20CA]->size = sizeof(prec->d20ca);
    prt->papFldDes[sscanRecordD20CA]->offset = (unsigned short)offsetof(sscanRecord, d20ca);
    prt->papFldDes[sscanRecordD20CV]->size = sizeof(prec->d20cv);
    prt->papFldDes[sscanRecordD20CV]->offset = (unsigned short)offsetof(sscanRecord, d20cv);
    prt->papFldDes[sscanRecordD20LV]->size = sizeof(prec->d20lv);
    prt->papFldDes[sscanRecordD20LV]->offset = (unsigned short)offsetof(sscanRecord, d20lv);
    prt->papFldDes[sscanRecordD20NE]->size = sizeof(prec->d20ne);
    prt->papFldDes[sscanRecordD20NE]->offset = (unsigned short)offsetof(sscanRecord, d20ne);
    prt->papFldDes[sscanRecordD20EU]->size = sizeof(prec->d20eu);
    prt->papFldDes[sscanRecordD20EU]->offset = (unsigned short)offsetof(sscanRecord, d20eu);
    prt->papFldDes[sscanRecordD20PR]->size = sizeof(prec->d20pr);
    prt->papFldDes[sscanRecordD20PR]->offset = (unsigned short)offsetof(sscanRecord, d20pr);
    prt->papFldDes[sscanRecordD21HR]->size = sizeof(prec->d21hr);
    prt->papFldDes[sscanRecordD21HR]->offset = (unsigned short)offsetof(sscanRecord, d21hr);
    prt->papFldDes[sscanRecordD21LR]->size = sizeof(prec->d21lr);
    prt->papFldDes[sscanRecordD21LR]->offset = (unsigned short)offsetof(sscanRecord, d21lr);
    prt->papFldDes[sscanRecordD21DA]->size = sizeof(prec->d21da);
    prt->papFldDes[sscanRecordD21DA]->offset = (unsigned short)offsetof(sscanRecord, d21da);
    prt->papFldDes[sscanRecordD21CA]->size = sizeof(prec->d21ca);
    prt->papFldDes[sscanRecordD21CA]->offset = (unsigned short)offsetof(sscanRecord, d21ca);
    prt->papFldDes[sscanRecordD21CV]->size = sizeof(prec->d21cv);
    prt->papFldDes[sscanRecordD21CV]->offset = (unsigned short)offsetof(sscanRecord, d21cv);
    prt->papFldDes[sscanRecordD21LV]->size = sizeof(prec->d21lv);
    prt->papFldDes[sscanRecordD21LV]->offset = (unsigned short)offsetof(sscanRecord, d21lv);
    prt->papFldDes[sscanRecordD21NE]->size = sizeof(prec->d21ne);
    prt->papFldDes[sscanRecordD21NE]->offset = (unsigned short)offsetof(sscanRecord, d21ne);
    prt->papFldDes[sscanRecordD21EU]->size = sizeof(prec->d21eu);
    prt->papFldDes[sscanRecordD21EU]->offset = (unsigned short)offsetof(sscanRecord, d21eu);
    prt->papFldDes[sscanRecordD21PR]->size = sizeof(prec->d21pr);
    prt->papFldDes[sscanRecordD21PR]->offset = (unsigned short)offsetof(sscanRecord, d21pr);
    prt->papFldDes[sscanRecordD22HR]->size = sizeof(prec->d22hr);
    prt->papFldDes[sscanRecordD22HR]->offset = (unsigned short)offsetof(sscanRecord, d22hr);
    prt->papFldDes[sscanRecordD22LR]->size = sizeof(prec->d22lr);
    prt->papFldDes[sscanRecordD22LR]->offset = (unsigned short)offsetof(sscanRecord, d22lr);
    prt->papFldDes[sscanRecordD22DA]->size = sizeof(prec->d22da);
    prt->papFldDes[sscanRecordD22DA]->offset = (unsigned short)offsetof(sscanRecord, d22da);
    prt->papFldDes[sscanRecordD22CA]->size = sizeof(prec->d22ca);
    prt->papFldDes[sscanRecordD22CA]->offset = (unsigned short)offsetof(sscanRecord, d22ca);
    prt->papFldDes[sscanRecordD22CV]->size = sizeof(prec->d22cv);
    prt->papFldDes[sscanRecordD22CV]->offset = (unsigned short)offsetof(sscanRecord, d22cv);
    prt->papFldDes[sscanRecordD22LV]->size = sizeof(prec->d22lv);
    prt->papFldDes[sscanRecordD22LV]->offset = (unsigned short)offsetof(sscanRecord, d22lv);
    prt->papFldDes[sscanRecordD22NE]->size = sizeof(prec->d22ne);
    prt->papFldDes[sscanRecordD22NE]->offset = (unsigned short)offsetof(sscanRecord, d22ne);
    prt->papFldDes[sscanRecordD22EU]->size = sizeof(prec->d22eu);
    prt->papFldDes[sscanRecordD22EU]->offset = (unsigned short)offsetof(sscanRecord, d22eu);
    prt->papFldDes[sscanRecordD22PR]->size = sizeof(prec->d22pr);
    prt->papFldDes[sscanRecordD22PR]->offset = (unsigned short)offsetof(sscanRecord, d22pr);
    prt->papFldDes[sscanRecordD23HR]->size = sizeof(prec->d23hr);
    prt->papFldDes[sscanRecordD23HR]->offset = (unsigned short)offsetof(sscanRecord, d23hr);
    prt->papFldDes[sscanRecordD23LR]->size = sizeof(prec->d23lr);
    prt->papFldDes[sscanRecordD23LR]->offset = (unsigned short)offsetof(sscanRecord, d23lr);
    prt->papFldDes[sscanRecordD23DA]->size = sizeof(prec->d23da);
    prt->papFldDes[sscanRecordD23DA]->offset = (unsigned short)offsetof(sscanRecord, d23da);
    prt->papFldDes[sscanRecordD23CA]->size = sizeof(prec->d23ca);
    prt->papFldDes[sscanRecordD23CA]->offset = (unsigned short)offsetof(sscanRecord, d23ca);
    prt->papFldDes[sscanRecordD23CV]->size = sizeof(prec->d23cv);
    prt->papFldDes[sscanRecordD23CV]->offset = (unsigned short)offsetof(sscanRecord, d23cv);
    prt->papFldDes[sscanRecordD23LV]->size = sizeof(prec->d23lv);
    prt->papFldDes[sscanRecordD23LV]->offset = (unsigned short)offsetof(sscanRecord, d23lv);
    prt->papFldDes[sscanRecordD23NE]->size = sizeof(prec->d23ne);
    prt->papFldDes[sscanRecordD23NE]->offset = (unsigned short)offsetof(sscanRecord, d23ne);
    prt->papFldDes[sscanRecordD23EU]->size = sizeof(prec->d23eu);
    prt->papFldDes[sscanRecordD23EU]->offset = (unsigned short)offsetof(sscanRecord, d23eu);
    prt->papFldDes[sscanRecordD23PR]->size = sizeof(prec->d23pr);
    prt->papFldDes[sscanRecordD23PR]->offset = (unsigned short)offsetof(sscanRecord, d23pr);
    prt->papFldDes[sscanRecordD24HR]->size = sizeof(prec->d24hr);
    prt->papFldDes[sscanRecordD24HR]->offset = (unsigned short)offsetof(sscanRecord, d24hr);
    prt->papFldDes[sscanRecordD24LR]->size = sizeof(prec->d24lr);
    prt->papFldDes[sscanRecordD24LR]->offset = (unsigned short)offsetof(sscanRecord, d24lr);
    prt->papFldDes[sscanRecordD24DA]->size = sizeof(prec->d24da);
    prt->papFldDes[sscanRecordD24DA]->offset = (unsigned short)offsetof(sscanRecord, d24da);
    prt->papFldDes[sscanRecordD24CA]->size = sizeof(prec->d24ca);
    prt->papFldDes[sscanRecordD24CA]->offset = (unsigned short)offsetof(sscanRecord, d24ca);
    prt->papFldDes[sscanRecordD24CV]->size = sizeof(prec->d24cv);
    prt->papFldDes[sscanRecordD24CV]->offset = (unsigned short)offsetof(sscanRecord, d24cv);
    prt->papFldDes[sscanRecordD24LV]->size = sizeof(prec->d24lv);
    prt->papFldDes[sscanRecordD24LV]->offset = (unsigned short)offsetof(sscanRecord, d24lv);
    prt->papFldDes[sscanRecordD24NE]->size = sizeof(prec->d24ne);
    prt->papFldDes[sscanRecordD24NE]->offset = (unsigned short)offsetof(sscanRecord, d24ne);
    prt->papFldDes[sscanRecordD24EU]->size = sizeof(prec->d24eu);
    prt->papFldDes[sscanRecordD24EU]->offset = (unsigned short)offsetof(sscanRecord, d24eu);
    prt->papFldDes[sscanRecordD24PR]->size = sizeof(prec->d24pr);
    prt->papFldDes[sscanRecordD24PR]->offset = (unsigned short)offsetof(sscanRecord, d24pr);
    prt->papFldDes[sscanRecordD25HR]->size = sizeof(prec->d25hr);
    prt->papFldDes[sscanRecordD25HR]->offset = (unsigned short)offsetof(sscanRecord, d25hr);
    prt->papFldDes[sscanRecordD25LR]->size = sizeof(prec->d25lr);
    prt->papFldDes[sscanRecordD25LR]->offset = (unsigned short)offsetof(sscanRecord, d25lr);
    prt->papFldDes[sscanRecordD25DA]->size = sizeof(prec->d25da);
    prt->papFldDes[sscanRecordD25DA]->offset = (unsigned short)offsetof(sscanRecord, d25da);
    prt->papFldDes[sscanRecordD25CA]->size = sizeof(prec->d25ca);
    prt->papFldDes[sscanRecordD25CA]->offset = (unsigned short)offsetof(sscanRecord, d25ca);
    prt->papFldDes[sscanRecordD25CV]->size = sizeof(prec->d25cv);
    prt->papFldDes[sscanRecordD25CV]->offset = (unsigned short)offsetof(sscanRecord, d25cv);
    prt->papFldDes[sscanRecordD25LV]->size = sizeof(prec->d25lv);
    prt->papFldDes[sscanRecordD25LV]->offset = (unsigned short)offsetof(sscanRecord, d25lv);
    prt->papFldDes[sscanRecordD25NE]->size = sizeof(prec->d25ne);
    prt->papFldDes[sscanRecordD25NE]->offset = (unsigned short)offsetof(sscanRecord, d25ne);
    prt->papFldDes[sscanRecordD25EU]->size = sizeof(prec->d25eu);
    prt->papFldDes[sscanRecordD25EU]->offset = (unsigned short)offsetof(sscanRecord, d25eu);
    prt->papFldDes[sscanRecordD25PR]->size = sizeof(prec->d25pr);
    prt->papFldDes[sscanRecordD25PR]->offset = (unsigned short)offsetof(sscanRecord, d25pr);
    prt->papFldDes[sscanRecordD26HR]->size = sizeof(prec->d26hr);
    prt->papFldDes[sscanRecordD26HR]->offset = (unsigned short)offsetof(sscanRecord, d26hr);
    prt->papFldDes[sscanRecordD26LR]->size = sizeof(prec->d26lr);
    prt->papFldDes[sscanRecordD26LR]->offset = (unsigned short)offsetof(sscanRecord, d26lr);
    prt->papFldDes[sscanRecordD26DA]->size = sizeof(prec->d26da);
    prt->papFldDes[sscanRecordD26DA]->offset = (unsigned short)offsetof(sscanRecord, d26da);
    prt->papFldDes[sscanRecordD26CA]->size = sizeof(prec->d26ca);
    prt->papFldDes[sscanRecordD26CA]->offset = (unsigned short)offsetof(sscanRecord, d26ca);
    prt->papFldDes[sscanRecordD26CV]->size = sizeof(prec->d26cv);
    prt->papFldDes[sscanRecordD26CV]->offset = (unsigned short)offsetof(sscanRecord, d26cv);
    prt->papFldDes[sscanRecordD26LV]->size = sizeof(prec->d26lv);
    prt->papFldDes[sscanRecordD26LV]->offset = (unsigned short)offsetof(sscanRecord, d26lv);
    prt->papFldDes[sscanRecordD26NE]->size = sizeof(prec->d26ne);
    prt->papFldDes[sscanRecordD26NE]->offset = (unsigned short)offsetof(sscanRecord, d26ne);
    prt->papFldDes[sscanRecordD26EU]->size = sizeof(prec->d26eu);
    prt->papFldDes[sscanRecordD26EU]->offset = (unsigned short)offsetof(sscanRecord, d26eu);
    prt->papFldDes[sscanRecordD26PR]->size = sizeof(prec->d26pr);
    prt->papFldDes[sscanRecordD26PR]->offset = (unsigned short)offsetof(sscanRecord, d26pr);
    prt->papFldDes[sscanRecordD27HR]->size = sizeof(prec->d27hr);
    prt->papFldDes[sscanRecordD27HR]->offset = (unsigned short)offsetof(sscanRecord, d27hr);
    prt->papFldDes[sscanRecordD27LR]->size = sizeof(prec->d27lr);
    prt->papFldDes[sscanRecordD27LR]->offset = (unsigned short)offsetof(sscanRecord, d27lr);
    prt->papFldDes[sscanRecordD27DA]->size = sizeof(prec->d27da);
    prt->papFldDes[sscanRecordD27DA]->offset = (unsigned short)offsetof(sscanRecord, d27da);
    prt->papFldDes[sscanRecordD27CA]->size = sizeof(prec->d27ca);
    prt->papFldDes[sscanRecordD27CA]->offset = (unsigned short)offsetof(sscanRecord, d27ca);
    prt->papFldDes[sscanRecordD27CV]->size = sizeof(prec->d27cv);
    prt->papFldDes[sscanRecordD27CV]->offset = (unsigned short)offsetof(sscanRecord, d27cv);
    prt->papFldDes[sscanRecordD27LV]->size = sizeof(prec->d27lv);
    prt->papFldDes[sscanRecordD27LV]->offset = (unsigned short)offsetof(sscanRecord, d27lv);
    prt->papFldDes[sscanRecordD27NE]->size = sizeof(prec->d27ne);
    prt->papFldDes[sscanRecordD27NE]->offset = (unsigned short)offsetof(sscanRecord, d27ne);
    prt->papFldDes[sscanRecordD27EU]->size = sizeof(prec->d27eu);
    prt->papFldDes[sscanRecordD27EU]->offset = (unsigned short)offsetof(sscanRecord, d27eu);
    prt->papFldDes[sscanRecordD27PR]->size = sizeof(prec->d27pr);
    prt->papFldDes[sscanRecordD27PR]->offset = (unsigned short)offsetof(sscanRecord, d27pr);
    prt->papFldDes[sscanRecordD28HR]->size = sizeof(prec->d28hr);
    prt->papFldDes[sscanRecordD28HR]->offset = (unsigned short)offsetof(sscanRecord, d28hr);
    prt->papFldDes[sscanRecordD28LR]->size = sizeof(prec->d28lr);
    prt->papFldDes[sscanRecordD28LR]->offset = (unsigned short)offsetof(sscanRecord, d28lr);
    prt->papFldDes[sscanRecordD28DA]->size = sizeof(prec->d28da);
    prt->papFldDes[sscanRecordD28DA]->offset = (unsigned short)offsetof(sscanRecord, d28da);
    prt->papFldDes[sscanRecordD28CA]->size = sizeof(prec->d28ca);
    prt->papFldDes[sscanRecordD28CA]->offset = (unsigned short)offsetof(sscanRecord, d28ca);
    prt->papFldDes[sscanRecordD28CV]->size = sizeof(prec->d28cv);
    prt->papFldDes[sscanRecordD28CV]->offset = (unsigned short)offsetof(sscanRecord, d28cv);
    prt->papFldDes[sscanRecordD28LV]->size = sizeof(prec->d28lv);
    prt->papFldDes[sscanRecordD28LV]->offset = (unsigned short)offsetof(sscanRecord, d28lv);
    prt->papFldDes[sscanRecordD28NE]->size = sizeof(prec->d28ne);
    prt->papFldDes[sscanRecordD28NE]->offset = (unsigned short)offsetof(sscanRecord, d28ne);
    prt->papFldDes[sscanRecordD28EU]->size = sizeof(prec->d28eu);
    prt->papFldDes[sscanRecordD28EU]->offset = (unsigned short)offsetof(sscanRecord, d28eu);
    prt->papFldDes[sscanRecordD28PR]->size = sizeof(prec->d28pr);
    prt->papFldDes[sscanRecordD28PR]->offset = (unsigned short)offsetof(sscanRecord, d28pr);
    prt->papFldDes[sscanRecordD29HR]->size = sizeof(prec->d29hr);
    prt->papFldDes[sscanRecordD29HR]->offset = (unsigned short)offsetof(sscanRecord, d29hr);
    prt->papFldDes[sscanRecordD29LR]->size = sizeof(prec->d29lr);
    prt->papFldDes[sscanRecordD29LR]->offset = (unsigned short)offsetof(sscanRecord, d29lr);
    prt->papFldDes[sscanRecordD29DA]->size = sizeof(prec->d29da);
    prt->papFldDes[sscanRecordD29DA]->offset = (unsigned short)offsetof(sscanRecord, d29da);
    prt->papFldDes[sscanRecordD29CA]->size = sizeof(prec->d29ca);
    prt->papFldDes[sscanRecordD29CA]->offset = (unsigned short)offsetof(sscanRecord, d29ca);
    prt->papFldDes[sscanRecordD29CV]->size = sizeof(prec->d29cv);
    prt->papFldDes[sscanRecordD29CV]->offset = (unsigned short)offsetof(sscanRecord, d29cv);
    prt->papFldDes[sscanRecordD29LV]->size = sizeof(prec->d29lv);
    prt->papFldDes[sscanRecordD29LV]->offset = (unsigned short)offsetof(sscanRecord, d29lv);
    prt->papFldDes[sscanRecordD29NE]->size = sizeof(prec->d29ne);
    prt->papFldDes[sscanRecordD29NE]->offset = (unsigned short)offsetof(sscanRecord, d29ne);
    prt->papFldDes[sscanRecordD29EU]->size = sizeof(prec->d29eu);
    prt->papFldDes[sscanRecordD29EU]->offset = (unsigned short)offsetof(sscanRecord, d29eu);
    prt->papFldDes[sscanRecordD29PR]->size = sizeof(prec->d29pr);
    prt->papFldDes[sscanRecordD29PR]->offset = (unsigned short)offsetof(sscanRecord, d29pr);
    prt->papFldDes[sscanRecordD30HR]->size = sizeof(prec->d30hr);
    prt->papFldDes[sscanRecordD30HR]->offset = (unsigned short)offsetof(sscanRecord, d30hr);
    prt->papFldDes[sscanRecordD30LR]->size = sizeof(prec->d30lr);
    prt->papFldDes[sscanRecordD30LR]->offset = (unsigned short)offsetof(sscanRecord, d30lr);
    prt->papFldDes[sscanRecordD30DA]->size = sizeof(prec->d30da);
    prt->papFldDes[sscanRecordD30DA]->offset = (unsigned short)offsetof(sscanRecord, d30da);
    prt->papFldDes[sscanRecordD30CA]->size = sizeof(prec->d30ca);
    prt->papFldDes[sscanRecordD30CA]->offset = (unsigned short)offsetof(sscanRecord, d30ca);
    prt->papFldDes[sscanRecordD30CV]->size = sizeof(prec->d30cv);
    prt->papFldDes[sscanRecordD30CV]->offset = (unsigned short)offsetof(sscanRecord, d30cv);
    prt->papFldDes[sscanRecordD30LV]->size = sizeof(prec->d30lv);
    prt->papFldDes[sscanRecordD30LV]->offset = (unsigned short)offsetof(sscanRecord, d30lv);
    prt->papFldDes[sscanRecordD30NE]->size = sizeof(prec->d30ne);
    prt->papFldDes[sscanRecordD30NE]->offset = (unsigned short)offsetof(sscanRecord, d30ne);
    prt->papFldDes[sscanRecordD30EU]->size = sizeof(prec->d30eu);
    prt->papFldDes[sscanRecordD30EU]->offset = (unsigned short)offsetof(sscanRecord, d30eu);
    prt->papFldDes[sscanRecordD30PR]->size = sizeof(prec->d30pr);
    prt->papFldDes[sscanRecordD30PR]->offset = (unsigned short)offsetof(sscanRecord, d30pr);
    prt->papFldDes[sscanRecordD31HR]->size = sizeof(prec->d31hr);
    prt->papFldDes[sscanRecordD31HR]->offset = (unsigned short)offsetof(sscanRecord, d31hr);
    prt->papFldDes[sscanRecordD31LR]->size = sizeof(prec->d31lr);
    prt->papFldDes[sscanRecordD31LR]->offset = (unsigned short)offsetof(sscanRecord, d31lr);
    prt->papFldDes[sscanRecordD31DA]->size = sizeof(prec->d31da);
    prt->papFldDes[sscanRecordD31DA]->offset = (unsigned short)offsetof(sscanRecord, d31da);
    prt->papFldDes[sscanRecordD31CA]->size = sizeof(prec->d31ca);
    prt->papFldDes[sscanRecordD31CA]->offset = (unsigned short)offsetof(sscanRecord, d31ca);
    prt->papFldDes[sscanRecordD31CV]->size = sizeof(prec->d31cv);
    prt->papFldDes[sscanRecordD31CV]->offset = (unsigned short)offsetof(sscanRecord, d31cv);
    prt->papFldDes[sscanRecordD31LV]->size = sizeof(prec->d31lv);
    prt->papFldDes[sscanRecordD31LV]->offset = (unsigned short)offsetof(sscanRecord, d31lv);
    prt->papFldDes[sscanRecordD31NE]->size = sizeof(prec->d31ne);
    prt->papFldDes[sscanRecordD31NE]->offset = (unsigned short)offsetof(sscanRecord, d31ne);
    prt->papFldDes[sscanRecordD31EU]->size = sizeof(prec->d31eu);
    prt->papFldDes[sscanRecordD31EU]->offset = (unsigned short)offsetof(sscanRecord, d31eu);
    prt->papFldDes[sscanRecordD31PR]->size = sizeof(prec->d31pr);
    prt->papFldDes[sscanRecordD31PR]->offset = (unsigned short)offsetof(sscanRecord, d31pr);
    prt->papFldDes[sscanRecordD32HR]->size = sizeof(prec->d32hr);
    prt->papFldDes[sscanRecordD32HR]->offset = (unsigned short)offsetof(sscanRecord, d32hr);
    prt->papFldDes[sscanRecordD32LR]->size = sizeof(prec->d32lr);
    prt->papFldDes[sscanRecordD32LR]->offset = (unsigned short)offsetof(sscanRecord, d32lr);
    prt->papFldDes[sscanRecordD32DA]->size = sizeof(prec->d32da);
    prt->papFldDes[sscanRecordD32DA]->offset = (unsigned short)offsetof(sscanRecord, d32da);
    prt->papFldDes[sscanRecordD32CA]->size = sizeof(prec->d32ca);
    prt->papFldDes[sscanRecordD32CA]->offset = (unsigned short)offsetof(sscanRecord, d32ca);
    prt->papFldDes[sscanRecordD32CV]->size = sizeof(prec->d32cv);
    prt->papFldDes[sscanRecordD32CV]->offset = (unsigned short)offsetof(sscanRecord, d32cv);
    prt->papFldDes[sscanRecordD32LV]->size = sizeof(prec->d32lv);
    prt->papFldDes[sscanRecordD32LV]->offset = (unsigned short)offsetof(sscanRecord, d32lv);
    prt->papFldDes[sscanRecordD32NE]->size = sizeof(prec->d32ne);
    prt->papFldDes[sscanRecordD32NE]->offset = (unsigned short)offsetof(sscanRecord, d32ne);
    prt->papFldDes[sscanRecordD32EU]->size = sizeof(prec->d32eu);
    prt->papFldDes[sscanRecordD32EU]->offset = (unsigned short)offsetof(sscanRecord, d32eu);
    prt->papFldDes[sscanRecordD32PR]->size = sizeof(prec->d32pr);
    prt->papFldDes[sscanRecordD32PR]->offset = (unsigned short)offsetof(sscanRecord, d32pr);
    prt->papFldDes[sscanRecordD33HR]->size = sizeof(prec->d33hr);
    prt->papFldDes[sscanRecordD33HR]->offset = (unsigned short)offsetof(sscanRecord, d33hr);
    prt->papFldDes[sscanRecordD33LR]->size = sizeof(prec->d33lr);
    prt->papFldDes[sscanRecordD33LR]->offset = (unsigned short)offsetof(sscanRecord, d33lr);
    prt->papFldDes[sscanRecordD33DA]->size = sizeof(prec->d33da);
    prt->papFldDes[sscanRecordD33DA]->offset = (unsigned short)offsetof(sscanRecord, d33da);
    prt->papFldDes[sscanRecordD33CA]->size = sizeof(prec->d33ca);
    prt->papFldDes[sscanRecordD33CA]->offset = (unsigned short)offsetof(sscanRecord, d33ca);
    prt->papFldDes[sscanRecordD33CV]->size = sizeof(prec->d33cv);
    prt->papFldDes[sscanRecordD33CV]->offset = (unsigned short)offsetof(sscanRecord, d33cv);
    prt->papFldDes[sscanRecordD33LV]->size = sizeof(prec->d33lv);
    prt->papFldDes[sscanRecordD33LV]->offset = (unsigned short)offsetof(sscanRecord, d33lv);
    prt->papFldDes[sscanRecordD33NE]->size = sizeof(prec->d33ne);
    prt->papFldDes[sscanRecordD33NE]->offset = (unsigned short)offsetof(sscanRecord, d33ne);
    prt->papFldDes[sscanRecordD33EU]->size = sizeof(prec->d33eu);
    prt->papFldDes[sscanRecordD33EU]->offset = (unsigned short)offsetof(sscanRecord, d33eu);
    prt->papFldDes[sscanRecordD33PR]->size = sizeof(prec->d33pr);
    prt->papFldDes[sscanRecordD33PR]->offset = (unsigned short)offsetof(sscanRecord, d33pr);
    prt->papFldDes[sscanRecordD34HR]->size = sizeof(prec->d34hr);
    prt->papFldDes[sscanRecordD34HR]->offset = (unsigned short)offsetof(sscanRecord, d34hr);
    prt->papFldDes[sscanRecordD34LR]->size = sizeof(prec->d34lr);
    prt->papFldDes[sscanRecordD34LR]->offset = (unsigned short)offsetof(sscanRecord, d34lr);
    prt->papFldDes[sscanRecordD34DA]->size = sizeof(prec->d34da);
    prt->papFldDes[sscanRecordD34DA]->offset = (unsigned short)offsetof(sscanRecord, d34da);
    prt->papFldDes[sscanRecordD34CA]->size = sizeof(prec->d34ca);
    prt->papFldDes[sscanRecordD34CA]->offset = (unsigned short)offsetof(sscanRecord, d34ca);
    prt->papFldDes[sscanRecordD34CV]->size = sizeof(prec->d34cv);
    prt->papFldDes[sscanRecordD34CV]->offset = (unsigned short)offsetof(sscanRecord, d34cv);
    prt->papFldDes[sscanRecordD34LV]->size = sizeof(prec->d34lv);
    prt->papFldDes[sscanRecordD34LV]->offset = (unsigned short)offsetof(sscanRecord, d34lv);
    prt->papFldDes[sscanRecordD34NE]->size = sizeof(prec->d34ne);
    prt->papFldDes[sscanRecordD34NE]->offset = (unsigned short)offsetof(sscanRecord, d34ne);
    prt->papFldDes[sscanRecordD34EU]->size = sizeof(prec->d34eu);
    prt->papFldDes[sscanRecordD34EU]->offset = (unsigned short)offsetof(sscanRecord, d34eu);
    prt->papFldDes[sscanRecordD34PR]->size = sizeof(prec->d34pr);
    prt->papFldDes[sscanRecordD34PR]->offset = (unsigned short)offsetof(sscanRecord, d34pr);
    prt->papFldDes[sscanRecordD35HR]->size = sizeof(prec->d35hr);
    prt->papFldDes[sscanRecordD35HR]->offset = (unsigned short)offsetof(sscanRecord, d35hr);
    prt->papFldDes[sscanRecordD35LR]->size = sizeof(prec->d35lr);
    prt->papFldDes[sscanRecordD35LR]->offset = (unsigned short)offsetof(sscanRecord, d35lr);
    prt->papFldDes[sscanRecordD35DA]->size = sizeof(prec->d35da);
    prt->papFldDes[sscanRecordD35DA]->offset = (unsigned short)offsetof(sscanRecord, d35da);
    prt->papFldDes[sscanRecordD35CA]->size = sizeof(prec->d35ca);
    prt->papFldDes[sscanRecordD35CA]->offset = (unsigned short)offsetof(sscanRecord, d35ca);
    prt->papFldDes[sscanRecordD35CV]->size = sizeof(prec->d35cv);
    prt->papFldDes[sscanRecordD35CV]->offset = (unsigned short)offsetof(sscanRecord, d35cv);
    prt->papFldDes[sscanRecordD35LV]->size = sizeof(prec->d35lv);
    prt->papFldDes[sscanRecordD35LV]->offset = (unsigned short)offsetof(sscanRecord, d35lv);
    prt->papFldDes[sscanRecordD35NE]->size = sizeof(prec->d35ne);
    prt->papFldDes[sscanRecordD35NE]->offset = (unsigned short)offsetof(sscanRecord, d35ne);
    prt->papFldDes[sscanRecordD35EU]->size = sizeof(prec->d35eu);
    prt->papFldDes[sscanRecordD35EU]->offset = (unsigned short)offsetof(sscanRecord, d35eu);
    prt->papFldDes[sscanRecordD35PR]->size = sizeof(prec->d35pr);
    prt->papFldDes[sscanRecordD35PR]->offset = (unsigned short)offsetof(sscanRecord, d35pr);
    prt->papFldDes[sscanRecordD36HR]->size = sizeof(prec->d36hr);
    prt->papFldDes[sscanRecordD36HR]->offset = (unsigned short)offsetof(sscanRecord, d36hr);
    prt->papFldDes[sscanRecordD36LR]->size = sizeof(prec->d36lr);
    prt->papFldDes[sscanRecordD36LR]->offset = (unsigned short)offsetof(sscanRecord, d36lr);
    prt->papFldDes[sscanRecordD36DA]->size = sizeof(prec->d36da);
    prt->papFldDes[sscanRecordD36DA]->offset = (unsigned short)offsetof(sscanRecord, d36da);
    prt->papFldDes[sscanRecordD36CA]->size = sizeof(prec->d36ca);
    prt->papFldDes[sscanRecordD36CA]->offset = (unsigned short)offsetof(sscanRecord, d36ca);
    prt->papFldDes[sscanRecordD36CV]->size = sizeof(prec->d36cv);
    prt->papFldDes[sscanRecordD36CV]->offset = (unsigned short)offsetof(sscanRecord, d36cv);
    prt->papFldDes[sscanRecordD36LV]->size = sizeof(prec->d36lv);
    prt->papFldDes[sscanRecordD36LV]->offset = (unsigned short)offsetof(sscanRecord, d36lv);
    prt->papFldDes[sscanRecordD36NE]->size = sizeof(prec->d36ne);
    prt->papFldDes[sscanRecordD36NE]->offset = (unsigned short)offsetof(sscanRecord, d36ne);
    prt->papFldDes[sscanRecordD36EU]->size = sizeof(prec->d36eu);
    prt->papFldDes[sscanRecordD36EU]->offset = (unsigned short)offsetof(sscanRecord, d36eu);
    prt->papFldDes[sscanRecordD36PR]->size = sizeof(prec->d36pr);
    prt->papFldDes[sscanRecordD36PR]->offset = (unsigned short)offsetof(sscanRecord, d36pr);
    prt->papFldDes[sscanRecordD37HR]->size = sizeof(prec->d37hr);
    prt->papFldDes[sscanRecordD37HR]->offset = (unsigned short)offsetof(sscanRecord, d37hr);
    prt->papFldDes[sscanRecordD37LR]->size = sizeof(prec->d37lr);
    prt->papFldDes[sscanRecordD37LR]->offset = (unsigned short)offsetof(sscanRecord, d37lr);
    prt->papFldDes[sscanRecordD37DA]->size = sizeof(prec->d37da);
    prt->papFldDes[sscanRecordD37DA]->offset = (unsigned short)offsetof(sscanRecord, d37da);
    prt->papFldDes[sscanRecordD37CA]->size = sizeof(prec->d37ca);
    prt->papFldDes[sscanRecordD37CA]->offset = (unsigned short)offsetof(sscanRecord, d37ca);
    prt->papFldDes[sscanRecordD37CV]->size = sizeof(prec->d37cv);
    prt->papFldDes[sscanRecordD37CV]->offset = (unsigned short)offsetof(sscanRecord, d37cv);
    prt->papFldDes[sscanRecordD37LV]->size = sizeof(prec->d37lv);
    prt->papFldDes[sscanRecordD37LV]->offset = (unsigned short)offsetof(sscanRecord, d37lv);
    prt->papFldDes[sscanRecordD37NE]->size = sizeof(prec->d37ne);
    prt->papFldDes[sscanRecordD37NE]->offset = (unsigned short)offsetof(sscanRecord, d37ne);
    prt->papFldDes[sscanRecordD37EU]->size = sizeof(prec->d37eu);
    prt->papFldDes[sscanRecordD37EU]->offset = (unsigned short)offsetof(sscanRecord, d37eu);
    prt->papFldDes[sscanRecordD37PR]->size = sizeof(prec->d37pr);
    prt->papFldDes[sscanRecordD37PR]->offset = (unsigned short)offsetof(sscanRecord, d37pr);
    prt->papFldDes[sscanRecordD38HR]->size = sizeof(prec->d38hr);
    prt->papFldDes[sscanRecordD38HR]->offset = (unsigned short)offsetof(sscanRecord, d38hr);
    prt->papFldDes[sscanRecordD38LR]->size = sizeof(prec->d38lr);
    prt->papFldDes[sscanRecordD38LR]->offset = (unsigned short)offsetof(sscanRecord, d38lr);
    prt->papFldDes[sscanRecordD38DA]->size = sizeof(prec->d38da);
    prt->papFldDes[sscanRecordD38DA]->offset = (unsigned short)offsetof(sscanRecord, d38da);
    prt->papFldDes[sscanRecordD38CA]->size = sizeof(prec->d38ca);
    prt->papFldDes[sscanRecordD38CA]->offset = (unsigned short)offsetof(sscanRecord, d38ca);
    prt->papFldDes[sscanRecordD38CV]->size = sizeof(prec->d38cv);
    prt->papFldDes[sscanRecordD38CV]->offset = (unsigned short)offsetof(sscanRecord, d38cv);
    prt->papFldDes[sscanRecordD38LV]->size = sizeof(prec->d38lv);
    prt->papFldDes[sscanRecordD38LV]->offset = (unsigned short)offsetof(sscanRecord, d38lv);
    prt->papFldDes[sscanRecordD38NE]->size = sizeof(prec->d38ne);
    prt->papFldDes[sscanRecordD38NE]->offset = (unsigned short)offsetof(sscanRecord, d38ne);
    prt->papFldDes[sscanRecordD38EU]->size = sizeof(prec->d38eu);
    prt->papFldDes[sscanRecordD38EU]->offset = (unsigned short)offsetof(sscanRecord, d38eu);
    prt->papFldDes[sscanRecordD38PR]->size = sizeof(prec->d38pr);
    prt->papFldDes[sscanRecordD38PR]->offset = (unsigned short)offsetof(sscanRecord, d38pr);
    prt->papFldDes[sscanRecordD39HR]->size = sizeof(prec->d39hr);
    prt->papFldDes[sscanRecordD39HR]->offset = (unsigned short)offsetof(sscanRecord, d39hr);
    prt->papFldDes[sscanRecordD39LR]->size = sizeof(prec->d39lr);
    prt->papFldDes[sscanRecordD39LR]->offset = (unsigned short)offsetof(sscanRecord, d39lr);
    prt->papFldDes[sscanRecordD39DA]->size = sizeof(prec->d39da);
    prt->papFldDes[sscanRecordD39DA]->offset = (unsigned short)offsetof(sscanRecord, d39da);
    prt->papFldDes[sscanRecordD39CA]->size = sizeof(prec->d39ca);
    prt->papFldDes[sscanRecordD39CA]->offset = (unsigned short)offsetof(sscanRecord, d39ca);
    prt->papFldDes[sscanRecordD39CV]->size = sizeof(prec->d39cv);
    prt->papFldDes[sscanRecordD39CV]->offset = (unsigned short)offsetof(sscanRecord, d39cv);
    prt->papFldDes[sscanRecordD39LV]->size = sizeof(prec->d39lv);
    prt->papFldDes[sscanRecordD39LV]->offset = (unsigned short)offsetof(sscanRecord, d39lv);
    prt->papFldDes[sscanRecordD39NE]->size = sizeof(prec->d39ne);
    prt->papFldDes[sscanRecordD39NE]->offset = (unsigned short)offsetof(sscanRecord, d39ne);
    prt->papFldDes[sscanRecordD39EU]->size = sizeof(prec->d39eu);
    prt->papFldDes[sscanRecordD39EU]->offset = (unsigned short)offsetof(sscanRecord, d39eu);
    prt->papFldDes[sscanRecordD39PR]->size = sizeof(prec->d39pr);
    prt->papFldDes[sscanRecordD39PR]->offset = (unsigned short)offsetof(sscanRecord, d39pr);
    prt->papFldDes[sscanRecordD40HR]->size = sizeof(prec->d40hr);
    prt->papFldDes[sscanRecordD40HR]->offset = (unsigned short)offsetof(sscanRecord, d40hr);
    prt->papFldDes[sscanRecordD40LR]->size = sizeof(prec->d40lr);
    prt->papFldDes[sscanRecordD40LR]->offset = (unsigned short)offsetof(sscanRecord, d40lr);
    prt->papFldDes[sscanRecordD40DA]->size = sizeof(prec->d40da);
    prt->papFldDes[sscanRecordD40DA]->offset = (unsigned short)offsetof(sscanRecord, d40da);
    prt->papFldDes[sscanRecordD40CA]->size = sizeof(prec->d40ca);
    prt->papFldDes[sscanRecordD40CA]->offset = (unsigned short)offsetof(sscanRecord, d40ca);
    prt->papFldDes[sscanRecordD40CV]->size = sizeof(prec->d40cv);
    prt->papFldDes[sscanRecordD40CV]->offset = (unsigned short)offsetof(sscanRecord, d40cv);
    prt->papFldDes[sscanRecordD40LV]->size = sizeof(prec->d40lv);
    prt->papFldDes[sscanRecordD40LV]->offset = (unsigned short)offsetof(sscanRecord, d40lv);
    prt->papFldDes[sscanRecordD40NE]->size = sizeof(prec->d40ne);
    prt->papFldDes[sscanRecordD40NE]->offset = (unsigned short)offsetof(sscanRecord, d40ne);
    prt->papFldDes[sscanRecordD40EU]->size = sizeof(prec->d40eu);
    prt->papFldDes[sscanRecordD40EU]->offset = (unsigned short)offsetof(sscanRecord, d40eu);
    prt->papFldDes[sscanRecordD40PR]->size = sizeof(prec->d40pr);
    prt->papFldDes[sscanRecordD40PR]->offset = (unsigned short)offsetof(sscanRecord, d40pr);
    prt->papFldDes[sscanRecordD41HR]->size = sizeof(prec->d41hr);
    prt->papFldDes[sscanRecordD41HR]->offset = (unsigned short)offsetof(sscanRecord, d41hr);
    prt->papFldDes[sscanRecordD41LR]->size = sizeof(prec->d41lr);
    prt->papFldDes[sscanRecordD41LR]->offset = (unsigned short)offsetof(sscanRecord, d41lr);
    prt->papFldDes[sscanRecordD41DA]->size = sizeof(prec->d41da);
    prt->papFldDes[sscanRecordD41DA]->offset = (unsigned short)offsetof(sscanRecord, d41da);
    prt->papFldDes[sscanRecordD41CA]->size = sizeof(prec->d41ca);
    prt->papFldDes[sscanRecordD41CA]->offset = (unsigned short)offsetof(sscanRecord, d41ca);
    prt->papFldDes[sscanRecordD41CV]->size = sizeof(prec->d41cv);
    prt->papFldDes[sscanRecordD41CV]->offset = (unsigned short)offsetof(sscanRecord, d41cv);
    prt->papFldDes[sscanRecordD41LV]->size = sizeof(prec->d41lv);
    prt->papFldDes[sscanRecordD41LV]->offset = (unsigned short)offsetof(sscanRecord, d41lv);
    prt->papFldDes[sscanRecordD41NE]->size = sizeof(prec->d41ne);
    prt->papFldDes[sscanRecordD41NE]->offset = (unsigned short)offsetof(sscanRecord, d41ne);
    prt->papFldDes[sscanRecordD41EU]->size = sizeof(prec->d41eu);
    prt->papFldDes[sscanRecordD41EU]->offset = (unsigned short)offsetof(sscanRecord, d41eu);
    prt->papFldDes[sscanRecordD41PR]->size = sizeof(prec->d41pr);
    prt->papFldDes[sscanRecordD41PR]->offset = (unsigned short)offsetof(sscanRecord, d41pr);
    prt->papFldDes[sscanRecordD42HR]->size = sizeof(prec->d42hr);
    prt->papFldDes[sscanRecordD42HR]->offset = (unsigned short)offsetof(sscanRecord, d42hr);
    prt->papFldDes[sscanRecordD42LR]->size = sizeof(prec->d42lr);
    prt->papFldDes[sscanRecordD42LR]->offset = (unsigned short)offsetof(sscanRecord, d42lr);
    prt->papFldDes[sscanRecordD42DA]->size = sizeof(prec->d42da);
    prt->papFldDes[sscanRecordD42DA]->offset = (unsigned short)offsetof(sscanRecord, d42da);
    prt->papFldDes[sscanRecordD42CA]->size = sizeof(prec->d42ca);
    prt->papFldDes[sscanRecordD42CA]->offset = (unsigned short)offsetof(sscanRecord, d42ca);
    prt->papFldDes[sscanRecordD42CV]->size = sizeof(prec->d42cv);
    prt->papFldDes[sscanRecordD42CV]->offset = (unsigned short)offsetof(sscanRecord, d42cv);
    prt->papFldDes[sscanRecordD42LV]->size = sizeof(prec->d42lv);
    prt->papFldDes[sscanRecordD42LV]->offset = (unsigned short)offsetof(sscanRecord, d42lv);
    prt->papFldDes[sscanRecordD42NE]->size = sizeof(prec->d42ne);
    prt->papFldDes[sscanRecordD42NE]->offset = (unsigned short)offsetof(sscanRecord, d42ne);
    prt->papFldDes[sscanRecordD42EU]->size = sizeof(prec->d42eu);
    prt->papFldDes[sscanRecordD42EU]->offset = (unsigned short)offsetof(sscanRecord, d42eu);
    prt->papFldDes[sscanRecordD42PR]->size = sizeof(prec->d42pr);
    prt->papFldDes[sscanRecordD42PR]->offset = (unsigned short)offsetof(sscanRecord, d42pr);
    prt->papFldDes[sscanRecordD43HR]->size = sizeof(prec->d43hr);
    prt->papFldDes[sscanRecordD43HR]->offset = (unsigned short)offsetof(sscanRecord, d43hr);
    prt->papFldDes[sscanRecordD43LR]->size = sizeof(prec->d43lr);
    prt->papFldDes[sscanRecordD43LR]->offset = (unsigned short)offsetof(sscanRecord, d43lr);
    prt->papFldDes[sscanRecordD43DA]->size = sizeof(prec->d43da);
    prt->papFldDes[sscanRecordD43DA]->offset = (unsigned short)offsetof(sscanRecord, d43da);
    prt->papFldDes[sscanRecordD43CA]->size = sizeof(prec->d43ca);
    prt->papFldDes[sscanRecordD43CA]->offset = (unsigned short)offsetof(sscanRecord, d43ca);
    prt->papFldDes[sscanRecordD43CV]->size = sizeof(prec->d43cv);
    prt->papFldDes[sscanRecordD43CV]->offset = (unsigned short)offsetof(sscanRecord, d43cv);
    prt->papFldDes[sscanRecordD43LV]->size = sizeof(prec->d43lv);
    prt->papFldDes[sscanRecordD43LV]->offset = (unsigned short)offsetof(sscanRecord, d43lv);
    prt->papFldDes[sscanRecordD43NE]->size = sizeof(prec->d43ne);
    prt->papFldDes[sscanRecordD43NE]->offset = (unsigned short)offsetof(sscanRecord, d43ne);
    prt->papFldDes[sscanRecordD43EU]->size = sizeof(prec->d43eu);
    prt->papFldDes[sscanRecordD43EU]->offset = (unsigned short)offsetof(sscanRecord, d43eu);
    prt->papFldDes[sscanRecordD43PR]->size = sizeof(prec->d43pr);
    prt->papFldDes[sscanRecordD43PR]->offset = (unsigned short)offsetof(sscanRecord, d43pr);
    prt->papFldDes[sscanRecordD44HR]->size = sizeof(prec->d44hr);
    prt->papFldDes[sscanRecordD44HR]->offset = (unsigned short)offsetof(sscanRecord, d44hr);
    prt->papFldDes[sscanRecordD44LR]->size = sizeof(prec->d44lr);
    prt->papFldDes[sscanRecordD44LR]->offset = (unsigned short)offsetof(sscanRecord, d44lr);
    prt->papFldDes[sscanRecordD44DA]->size = sizeof(prec->d44da);
    prt->papFldDes[sscanRecordD44DA]->offset = (unsigned short)offsetof(sscanRecord, d44da);
    prt->papFldDes[sscanRecordD44CA]->size = sizeof(prec->d44ca);
    prt->papFldDes[sscanRecordD44CA]->offset = (unsigned short)offsetof(sscanRecord, d44ca);
    prt->papFldDes[sscanRecordD44CV]->size = sizeof(prec->d44cv);
    prt->papFldDes[sscanRecordD44CV]->offset = (unsigned short)offsetof(sscanRecord, d44cv);
    prt->papFldDes[sscanRecordD44LV]->size = sizeof(prec->d44lv);
    prt->papFldDes[sscanRecordD44LV]->offset = (unsigned short)offsetof(sscanRecord, d44lv);
    prt->papFldDes[sscanRecordD44NE]->size = sizeof(prec->d44ne);
    prt->papFldDes[sscanRecordD44NE]->offset = (unsigned short)offsetof(sscanRecord, d44ne);
    prt->papFldDes[sscanRecordD44EU]->size = sizeof(prec->d44eu);
    prt->papFldDes[sscanRecordD44EU]->offset = (unsigned short)offsetof(sscanRecord, d44eu);
    prt->papFldDes[sscanRecordD44PR]->size = sizeof(prec->d44pr);
    prt->papFldDes[sscanRecordD44PR]->offset = (unsigned short)offsetof(sscanRecord, d44pr);
    prt->papFldDes[sscanRecordD45HR]->size = sizeof(prec->d45hr);
    prt->papFldDes[sscanRecordD45HR]->offset = (unsigned short)offsetof(sscanRecord, d45hr);
    prt->papFldDes[sscanRecordD45LR]->size = sizeof(prec->d45lr);
    prt->papFldDes[sscanRecordD45LR]->offset = (unsigned short)offsetof(sscanRecord, d45lr);
    prt->papFldDes[sscanRecordD45DA]->size = sizeof(prec->d45da);
    prt->papFldDes[sscanRecordD45DA]->offset = (unsigned short)offsetof(sscanRecord, d45da);
    prt->papFldDes[sscanRecordD45CA]->size = sizeof(prec->d45ca);
    prt->papFldDes[sscanRecordD45CA]->offset = (unsigned short)offsetof(sscanRecord, d45ca);
    prt->papFldDes[sscanRecordD45CV]->size = sizeof(prec->d45cv);
    prt->papFldDes[sscanRecordD45CV]->offset = (unsigned short)offsetof(sscanRecord, d45cv);
    prt->papFldDes[sscanRecordD45LV]->size = sizeof(prec->d45lv);
    prt->papFldDes[sscanRecordD45LV]->offset = (unsigned short)offsetof(sscanRecord, d45lv);
    prt->papFldDes[sscanRecordD45NE]->size = sizeof(prec->d45ne);
    prt->papFldDes[sscanRecordD45NE]->offset = (unsigned short)offsetof(sscanRecord, d45ne);
    prt->papFldDes[sscanRecordD45EU]->size = sizeof(prec->d45eu);
    prt->papFldDes[sscanRecordD45EU]->offset = (unsigned short)offsetof(sscanRecord, d45eu);
    prt->papFldDes[sscanRecordD45PR]->size = sizeof(prec->d45pr);
    prt->papFldDes[sscanRecordD45PR]->offset = (unsigned short)offsetof(sscanRecord, d45pr);
    prt->papFldDes[sscanRecordD46HR]->size = sizeof(prec->d46hr);
    prt->papFldDes[sscanRecordD46HR]->offset = (unsigned short)offsetof(sscanRecord, d46hr);
    prt->papFldDes[sscanRecordD46LR]->size = sizeof(prec->d46lr);
    prt->papFldDes[sscanRecordD46LR]->offset = (unsigned short)offsetof(sscanRecord, d46lr);
    prt->papFldDes[sscanRecordD46DA]->size = sizeof(prec->d46da);
    prt->papFldDes[sscanRecordD46DA]->offset = (unsigned short)offsetof(sscanRecord, d46da);
    prt->papFldDes[sscanRecordD46CA]->size = sizeof(prec->d46ca);
    prt->papFldDes[sscanRecordD46CA]->offset = (unsigned short)offsetof(sscanRecord, d46ca);
    prt->papFldDes[sscanRecordD46CV]->size = sizeof(prec->d46cv);
    prt->papFldDes[sscanRecordD46CV]->offset = (unsigned short)offsetof(sscanRecord, d46cv);
    prt->papFldDes[sscanRecordD46LV]->size = sizeof(prec->d46lv);
    prt->papFldDes[sscanRecordD46LV]->offset = (unsigned short)offsetof(sscanRecord, d46lv);
    prt->papFldDes[sscanRecordD46NE]->size = sizeof(prec->d46ne);
    prt->papFldDes[sscanRecordD46NE]->offset = (unsigned short)offsetof(sscanRecord, d46ne);
    prt->papFldDes[sscanRecordD46EU]->size = sizeof(prec->d46eu);
    prt->papFldDes[sscanRecordD46EU]->offset = (unsigned short)offsetof(sscanRecord, d46eu);
    prt->papFldDes[sscanRecordD46PR]->size = sizeof(prec->d46pr);
    prt->papFldDes[sscanRecordD46PR]->offset = (unsigned short)offsetof(sscanRecord, d46pr);
    prt->papFldDes[sscanRecordD47HR]->size = sizeof(prec->d47hr);
    prt->papFldDes[sscanRecordD47HR]->offset = (unsigned short)offsetof(sscanRecord, d47hr);
    prt->papFldDes[sscanRecordD47LR]->size = sizeof(prec->d47lr);
    prt->papFldDes[sscanRecordD47LR]->offset = (unsigned short)offsetof(sscanRecord, d47lr);
    prt->papFldDes[sscanRecordD47DA]->size = sizeof(prec->d47da);
    prt->papFldDes[sscanRecordD47DA]->offset = (unsigned short)offsetof(sscanRecord, d47da);
    prt->papFldDes[sscanRecordD47CA]->size = sizeof(prec->d47ca);
    prt->papFldDes[sscanRecordD47CA]->offset = (unsigned short)offsetof(sscanRecord, d47ca);
    prt->papFldDes[sscanRecordD47CV]->size = sizeof(prec->d47cv);
    prt->papFldDes[sscanRecordD47CV]->offset = (unsigned short)offsetof(sscanRecord, d47cv);
    prt->papFldDes[sscanRecordD47LV]->size = sizeof(prec->d47lv);
    prt->papFldDes[sscanRecordD47LV]->offset = (unsigned short)offsetof(sscanRecord, d47lv);
    prt->papFldDes[sscanRecordD47NE]->size = sizeof(prec->d47ne);
    prt->papFldDes[sscanRecordD47NE]->offset = (unsigned short)offsetof(sscanRecord, d47ne);
    prt->papFldDes[sscanRecordD47EU]->size = sizeof(prec->d47eu);
    prt->papFldDes[sscanRecordD47EU]->offset = (unsigned short)offsetof(sscanRecord, d47eu);
    prt->papFldDes[sscanRecordD47PR]->size = sizeof(prec->d47pr);
    prt->papFldDes[sscanRecordD47PR]->offset = (unsigned short)offsetof(sscanRecord, d47pr);
    prt->papFldDes[sscanRecordD48HR]->size = sizeof(prec->d48hr);
    prt->papFldDes[sscanRecordD48HR]->offset = (unsigned short)offsetof(sscanRecord, d48hr);
    prt->papFldDes[sscanRecordD48LR]->size = sizeof(prec->d48lr);
    prt->papFldDes[sscanRecordD48LR]->offset = (unsigned short)offsetof(sscanRecord, d48lr);
    prt->papFldDes[sscanRecordD48DA]->size = sizeof(prec->d48da);
    prt->papFldDes[sscanRecordD48DA]->offset = (unsigned short)offsetof(sscanRecord, d48da);
    prt->papFldDes[sscanRecordD48CA]->size = sizeof(prec->d48ca);
    prt->papFldDes[sscanRecordD48CA]->offset = (unsigned short)offsetof(sscanRecord, d48ca);
    prt->papFldDes[sscanRecordD48CV]->size = sizeof(prec->d48cv);
    prt->papFldDes[sscanRecordD48CV]->offset = (unsigned short)offsetof(sscanRecord, d48cv);
    prt->papFldDes[sscanRecordD48LV]->size = sizeof(prec->d48lv);
    prt->papFldDes[sscanRecordD48LV]->offset = (unsigned short)offsetof(sscanRecord, d48lv);
    prt->papFldDes[sscanRecordD48NE]->size = sizeof(prec->d48ne);
    prt->papFldDes[sscanRecordD48NE]->offset = (unsigned short)offsetof(sscanRecord, d48ne);
    prt->papFldDes[sscanRecordD48EU]->size = sizeof(prec->d48eu);
    prt->papFldDes[sscanRecordD48EU]->offset = (unsigned short)offsetof(sscanRecord, d48eu);
    prt->papFldDes[sscanRecordD48PR]->size = sizeof(prec->d48pr);
    prt->papFldDes[sscanRecordD48PR]->offset = (unsigned short)offsetof(sscanRecord, d48pr);
    prt->papFldDes[sscanRecordD49HR]->size = sizeof(prec->d49hr);
    prt->papFldDes[sscanRecordD49HR]->offset = (unsigned short)offsetof(sscanRecord, d49hr);
    prt->papFldDes[sscanRecordD49LR]->size = sizeof(prec->d49lr);
    prt->papFldDes[sscanRecordD49LR]->offset = (unsigned short)offsetof(sscanRecord, d49lr);
    prt->papFldDes[sscanRecordD49DA]->size = sizeof(prec->d49da);
    prt->papFldDes[sscanRecordD49DA]->offset = (unsigned short)offsetof(sscanRecord, d49da);
    prt->papFldDes[sscanRecordD49CA]->size = sizeof(prec->d49ca);
    prt->papFldDes[sscanRecordD49CA]->offset = (unsigned short)offsetof(sscanRecord, d49ca);
    prt->papFldDes[sscanRecordD49CV]->size = sizeof(prec->d49cv);
    prt->papFldDes[sscanRecordD49CV]->offset = (unsigned short)offsetof(sscanRecord, d49cv);
    prt->papFldDes[sscanRecordD49LV]->size = sizeof(prec->d49lv);
    prt->papFldDes[sscanRecordD49LV]->offset = (unsigned short)offsetof(sscanRecord, d49lv);
    prt->papFldDes[sscanRecordD49NE]->size = sizeof(prec->d49ne);
    prt->papFldDes[sscanRecordD49NE]->offset = (unsigned short)offsetof(sscanRecord, d49ne);
    prt->papFldDes[sscanRecordD49EU]->size = sizeof(prec->d49eu);
    prt->papFldDes[sscanRecordD49EU]->offset = (unsigned short)offsetof(sscanRecord, d49eu);
    prt->papFldDes[sscanRecordD49PR]->size = sizeof(prec->d49pr);
    prt->papFldDes[sscanRecordD49PR]->offset = (unsigned short)offsetof(sscanRecord, d49pr);
    prt->papFldDes[sscanRecordD50HR]->size = sizeof(prec->d50hr);
    prt->papFldDes[sscanRecordD50HR]->offset = (unsigned short)offsetof(sscanRecord, d50hr);
    prt->papFldDes[sscanRecordD50LR]->size = sizeof(prec->d50lr);
    prt->papFldDes[sscanRecordD50LR]->offset = (unsigned short)offsetof(sscanRecord, d50lr);
    prt->papFldDes[sscanRecordD50DA]->size = sizeof(prec->d50da);
    prt->papFldDes[sscanRecordD50DA]->offset = (unsigned short)offsetof(sscanRecord, d50da);
    prt->papFldDes[sscanRecordD50CA]->size = sizeof(prec->d50ca);
    prt->papFldDes[sscanRecordD50CA]->offset = (unsigned short)offsetof(sscanRecord, d50ca);
    prt->papFldDes[sscanRecordD50CV]->size = sizeof(prec->d50cv);
    prt->papFldDes[sscanRecordD50CV]->offset = (unsigned short)offsetof(sscanRecord, d50cv);
    prt->papFldDes[sscanRecordD50LV]->size = sizeof(prec->d50lv);
    prt->papFldDes[sscanRecordD50LV]->offset = (unsigned short)offsetof(sscanRecord, d50lv);
    prt->papFldDes[sscanRecordD50NE]->size = sizeof(prec->d50ne);
    prt->papFldDes[sscanRecordD50NE]->offset = (unsigned short)offsetof(sscanRecord, d50ne);
    prt->papFldDes[sscanRecordD50EU]->size = sizeof(prec->d50eu);
    prt->papFldDes[sscanRecordD50EU]->offset = (unsigned short)offsetof(sscanRecord, d50eu);
    prt->papFldDes[sscanRecordD50PR]->size = sizeof(prec->d50pr);
    prt->papFldDes[sscanRecordD50PR]->offset = (unsigned short)offsetof(sscanRecord, d50pr);
    prt->papFldDes[sscanRecordD51HR]->size = sizeof(prec->d51hr);
    prt->papFldDes[sscanRecordD51HR]->offset = (unsigned short)offsetof(sscanRecord, d51hr);
    prt->papFldDes[sscanRecordD51LR]->size = sizeof(prec->d51lr);
    prt->papFldDes[sscanRecordD51LR]->offset = (unsigned short)offsetof(sscanRecord, d51lr);
    prt->papFldDes[sscanRecordD51DA]->size = sizeof(prec->d51da);
    prt->papFldDes[sscanRecordD51DA]->offset = (unsigned short)offsetof(sscanRecord, d51da);
    prt->papFldDes[sscanRecordD51CA]->size = sizeof(prec->d51ca);
    prt->papFldDes[sscanRecordD51CA]->offset = (unsigned short)offsetof(sscanRecord, d51ca);
    prt->papFldDes[sscanRecordD51CV]->size = sizeof(prec->d51cv);
    prt->papFldDes[sscanRecordD51CV]->offset = (unsigned short)offsetof(sscanRecord, d51cv);
    prt->papFldDes[sscanRecordD51LV]->size = sizeof(prec->d51lv);
    prt->papFldDes[sscanRecordD51LV]->offset = (unsigned short)offsetof(sscanRecord, d51lv);
    prt->papFldDes[sscanRecordD51NE]->size = sizeof(prec->d51ne);
    prt->papFldDes[sscanRecordD51NE]->offset = (unsigned short)offsetof(sscanRecord, d51ne);
    prt->papFldDes[sscanRecordD51EU]->size = sizeof(prec->d51eu);
    prt->papFldDes[sscanRecordD51EU]->offset = (unsigned short)offsetof(sscanRecord, d51eu);
    prt->papFldDes[sscanRecordD51PR]->size = sizeof(prec->d51pr);
    prt->papFldDes[sscanRecordD51PR]->offset = (unsigned short)offsetof(sscanRecord, d51pr);
    prt->papFldDes[sscanRecordD52HR]->size = sizeof(prec->d52hr);
    prt->papFldDes[sscanRecordD52HR]->offset = (unsigned short)offsetof(sscanRecord, d52hr);
    prt->papFldDes[sscanRecordD52LR]->size = sizeof(prec->d52lr);
    prt->papFldDes[sscanRecordD52LR]->offset = (unsigned short)offsetof(sscanRecord, d52lr);
    prt->papFldDes[sscanRecordD52DA]->size = sizeof(prec->d52da);
    prt->papFldDes[sscanRecordD52DA]->offset = (unsigned short)offsetof(sscanRecord, d52da);
    prt->papFldDes[sscanRecordD52CA]->size = sizeof(prec->d52ca);
    prt->papFldDes[sscanRecordD52CA]->offset = (unsigned short)offsetof(sscanRecord, d52ca);
    prt->papFldDes[sscanRecordD52CV]->size = sizeof(prec->d52cv);
    prt->papFldDes[sscanRecordD52CV]->offset = (unsigned short)offsetof(sscanRecord, d52cv);
    prt->papFldDes[sscanRecordD52LV]->size = sizeof(prec->d52lv);
    prt->papFldDes[sscanRecordD52LV]->offset = (unsigned short)offsetof(sscanRecord, d52lv);
    prt->papFldDes[sscanRecordD52NE]->size = sizeof(prec->d52ne);
    prt->papFldDes[sscanRecordD52NE]->offset = (unsigned short)offsetof(sscanRecord, d52ne);
    prt->papFldDes[sscanRecordD52EU]->size = sizeof(prec->d52eu);
    prt->papFldDes[sscanRecordD52EU]->offset = (unsigned short)offsetof(sscanRecord, d52eu);
    prt->papFldDes[sscanRecordD52PR]->size = sizeof(prec->d52pr);
    prt->papFldDes[sscanRecordD52PR]->offset = (unsigned short)offsetof(sscanRecord, d52pr);
    prt->papFldDes[sscanRecordD53HR]->size = sizeof(prec->d53hr);
    prt->papFldDes[sscanRecordD53HR]->offset = (unsigned short)offsetof(sscanRecord, d53hr);
    prt->papFldDes[sscanRecordD53LR]->size = sizeof(prec->d53lr);
    prt->papFldDes[sscanRecordD53LR]->offset = (unsigned short)offsetof(sscanRecord, d53lr);
    prt->papFldDes[sscanRecordD53DA]->size = sizeof(prec->d53da);
    prt->papFldDes[sscanRecordD53DA]->offset = (unsigned short)offsetof(sscanRecord, d53da);
    prt->papFldDes[sscanRecordD53CA]->size = sizeof(prec->d53ca);
    prt->papFldDes[sscanRecordD53CA]->offset = (unsigned short)offsetof(sscanRecord, d53ca);
    prt->papFldDes[sscanRecordD53CV]->size = sizeof(prec->d53cv);
    prt->papFldDes[sscanRecordD53CV]->offset = (unsigned short)offsetof(sscanRecord, d53cv);
    prt->papFldDes[sscanRecordD53LV]->size = sizeof(prec->d53lv);
    prt->papFldDes[sscanRecordD53LV]->offset = (unsigned short)offsetof(sscanRecord, d53lv);
    prt->papFldDes[sscanRecordD53NE]->size = sizeof(prec->d53ne);
    prt->papFldDes[sscanRecordD53NE]->offset = (unsigned short)offsetof(sscanRecord, d53ne);
    prt->papFldDes[sscanRecordD53EU]->size = sizeof(prec->d53eu);
    prt->papFldDes[sscanRecordD53EU]->offset = (unsigned short)offsetof(sscanRecord, d53eu);
    prt->papFldDes[sscanRecordD53PR]->size = sizeof(prec->d53pr);
    prt->papFldDes[sscanRecordD53PR]->offset = (unsigned short)offsetof(sscanRecord, d53pr);
    prt->papFldDes[sscanRecordD54HR]->size = sizeof(prec->d54hr);
    prt->papFldDes[sscanRecordD54HR]->offset = (unsigned short)offsetof(sscanRecord, d54hr);
    prt->papFldDes[sscanRecordD54LR]->size = sizeof(prec->d54lr);
    prt->papFldDes[sscanRecordD54LR]->offset = (unsigned short)offsetof(sscanRecord, d54lr);
    prt->papFldDes[sscanRecordD54DA]->size = sizeof(prec->d54da);
    prt->papFldDes[sscanRecordD54DA]->offset = (unsigned short)offsetof(sscanRecord, d54da);
    prt->papFldDes[sscanRecordD54CA]->size = sizeof(prec->d54ca);
    prt->papFldDes[sscanRecordD54CA]->offset = (unsigned short)offsetof(sscanRecord, d54ca);
    prt->papFldDes[sscanRecordD54CV]->size = sizeof(prec->d54cv);
    prt->papFldDes[sscanRecordD54CV]->offset = (unsigned short)offsetof(sscanRecord, d54cv);
    prt->papFldDes[sscanRecordD54LV]->size = sizeof(prec->d54lv);
    prt->papFldDes[sscanRecordD54LV]->offset = (unsigned short)offsetof(sscanRecord, d54lv);
    prt->papFldDes[sscanRecordD54NE]->size = sizeof(prec->d54ne);
    prt->papFldDes[sscanRecordD54NE]->offset = (unsigned short)offsetof(sscanRecord, d54ne);
    prt->papFldDes[sscanRecordD54EU]->size = sizeof(prec->d54eu);
    prt->papFldDes[sscanRecordD54EU]->offset = (unsigned short)offsetof(sscanRecord, d54eu);
    prt->papFldDes[sscanRecordD54PR]->size = sizeof(prec->d54pr);
    prt->papFldDes[sscanRecordD54PR]->offset = (unsigned short)offsetof(sscanRecord, d54pr);
    prt->papFldDes[sscanRecordD55HR]->size = sizeof(prec->d55hr);
    prt->papFldDes[sscanRecordD55HR]->offset = (unsigned short)offsetof(sscanRecord, d55hr);
    prt->papFldDes[sscanRecordD55LR]->size = sizeof(prec->d55lr);
    prt->papFldDes[sscanRecordD55LR]->offset = (unsigned short)offsetof(sscanRecord, d55lr);
    prt->papFldDes[sscanRecordD55DA]->size = sizeof(prec->d55da);
    prt->papFldDes[sscanRecordD55DA]->offset = (unsigned short)offsetof(sscanRecord, d55da);
    prt->papFldDes[sscanRecordD55CA]->size = sizeof(prec->d55ca);
    prt->papFldDes[sscanRecordD55CA]->offset = (unsigned short)offsetof(sscanRecord, d55ca);
    prt->papFldDes[sscanRecordD55CV]->size = sizeof(prec->d55cv);
    prt->papFldDes[sscanRecordD55CV]->offset = (unsigned short)offsetof(sscanRecord, d55cv);
    prt->papFldDes[sscanRecordD55LV]->size = sizeof(prec->d55lv);
    prt->papFldDes[sscanRecordD55LV]->offset = (unsigned short)offsetof(sscanRecord, d55lv);
    prt->papFldDes[sscanRecordD55NE]->size = sizeof(prec->d55ne);
    prt->papFldDes[sscanRecordD55NE]->offset = (unsigned short)offsetof(sscanRecord, d55ne);
    prt->papFldDes[sscanRecordD55EU]->size = sizeof(prec->d55eu);
    prt->papFldDes[sscanRecordD55EU]->offset = (unsigned short)offsetof(sscanRecord, d55eu);
    prt->papFldDes[sscanRecordD55PR]->size = sizeof(prec->d55pr);
    prt->papFldDes[sscanRecordD55PR]->offset = (unsigned short)offsetof(sscanRecord, d55pr);
    prt->papFldDes[sscanRecordD56HR]->size = sizeof(prec->d56hr);
    prt->papFldDes[sscanRecordD56HR]->offset = (unsigned short)offsetof(sscanRecord, d56hr);
    prt->papFldDes[sscanRecordD56LR]->size = sizeof(prec->d56lr);
    prt->papFldDes[sscanRecordD56LR]->offset = (unsigned short)offsetof(sscanRecord, d56lr);
    prt->papFldDes[sscanRecordD56DA]->size = sizeof(prec->d56da);
    prt->papFldDes[sscanRecordD56DA]->offset = (unsigned short)offsetof(sscanRecord, d56da);
    prt->papFldDes[sscanRecordD56CA]->size = sizeof(prec->d56ca);
    prt->papFldDes[sscanRecordD56CA]->offset = (unsigned short)offsetof(sscanRecord, d56ca);
    prt->papFldDes[sscanRecordD56CV]->size = sizeof(prec->d56cv);
    prt->papFldDes[sscanRecordD56CV]->offset = (unsigned short)offsetof(sscanRecord, d56cv);
    prt->papFldDes[sscanRecordD56LV]->size = sizeof(prec->d56lv);
    prt->papFldDes[sscanRecordD56LV]->offset = (unsigned short)offsetof(sscanRecord, d56lv);
    prt->papFldDes[sscanRecordD56NE]->size = sizeof(prec->d56ne);
    prt->papFldDes[sscanRecordD56NE]->offset = (unsigned short)offsetof(sscanRecord, d56ne);
    prt->papFldDes[sscanRecordD56EU]->size = sizeof(prec->d56eu);
    prt->papFldDes[sscanRecordD56EU]->offset = (unsigned short)offsetof(sscanRecord, d56eu);
    prt->papFldDes[sscanRecordD56PR]->size = sizeof(prec->d56pr);
    prt->papFldDes[sscanRecordD56PR]->offset = (unsigned short)offsetof(sscanRecord, d56pr);
    prt->papFldDes[sscanRecordD57HR]->size = sizeof(prec->d57hr);
    prt->papFldDes[sscanRecordD57HR]->offset = (unsigned short)offsetof(sscanRecord, d57hr);
    prt->papFldDes[sscanRecordD57LR]->size = sizeof(prec->d57lr);
    prt->papFldDes[sscanRecordD57LR]->offset = (unsigned short)offsetof(sscanRecord, d57lr);
    prt->papFldDes[sscanRecordD57DA]->size = sizeof(prec->d57da);
    prt->papFldDes[sscanRecordD57DA]->offset = (unsigned short)offsetof(sscanRecord, d57da);
    prt->papFldDes[sscanRecordD57CA]->size = sizeof(prec->d57ca);
    prt->papFldDes[sscanRecordD57CA]->offset = (unsigned short)offsetof(sscanRecord, d57ca);
    prt->papFldDes[sscanRecordD57CV]->size = sizeof(prec->d57cv);
    prt->papFldDes[sscanRecordD57CV]->offset = (unsigned short)offsetof(sscanRecord, d57cv);
    prt->papFldDes[sscanRecordD57LV]->size = sizeof(prec->d57lv);
    prt->papFldDes[sscanRecordD57LV]->offset = (unsigned short)offsetof(sscanRecord, d57lv);
    prt->papFldDes[sscanRecordD57NE]->size = sizeof(prec->d57ne);
    prt->papFldDes[sscanRecordD57NE]->offset = (unsigned short)offsetof(sscanRecord, d57ne);
    prt->papFldDes[sscanRecordD57EU]->size = sizeof(prec->d57eu);
    prt->papFldDes[sscanRecordD57EU]->offset = (unsigned short)offsetof(sscanRecord, d57eu);
    prt->papFldDes[sscanRecordD57PR]->size = sizeof(prec->d57pr);
    prt->papFldDes[sscanRecordD57PR]->offset = (unsigned short)offsetof(sscanRecord, d57pr);
    prt->papFldDes[sscanRecordD58HR]->size = sizeof(prec->d58hr);
    prt->papFldDes[sscanRecordD58HR]->offset = (unsigned short)offsetof(sscanRecord, d58hr);
    prt->papFldDes[sscanRecordD58LR]->size = sizeof(prec->d58lr);
    prt->papFldDes[sscanRecordD58LR]->offset = (unsigned short)offsetof(sscanRecord, d58lr);
    prt->papFldDes[sscanRecordD58DA]->size = sizeof(prec->d58da);
    prt->papFldDes[sscanRecordD58DA]->offset = (unsigned short)offsetof(sscanRecord, d58da);
    prt->papFldDes[sscanRecordD58CA]->size = sizeof(prec->d58ca);
    prt->papFldDes[sscanRecordD58CA]->offset = (unsigned short)offsetof(sscanRecord, d58ca);
    prt->papFldDes[sscanRecordD58CV]->size = sizeof(prec->d58cv);
    prt->papFldDes[sscanRecordD58CV]->offset = (unsigned short)offsetof(sscanRecord, d58cv);
    prt->papFldDes[sscanRecordD58LV]->size = sizeof(prec->d58lv);
    prt->papFldDes[sscanRecordD58LV]->offset = (unsigned short)offsetof(sscanRecord, d58lv);
    prt->papFldDes[sscanRecordD58NE]->size = sizeof(prec->d58ne);
    prt->papFldDes[sscanRecordD58NE]->offset = (unsigned short)offsetof(sscanRecord, d58ne);
    prt->papFldDes[sscanRecordD58EU]->size = sizeof(prec->d58eu);
    prt->papFldDes[sscanRecordD58EU]->offset = (unsigned short)offsetof(sscanRecord, d58eu);
    prt->papFldDes[sscanRecordD58PR]->size = sizeof(prec->d58pr);
    prt->papFldDes[sscanRecordD58PR]->offset = (unsigned short)offsetof(sscanRecord, d58pr);
    prt->papFldDes[sscanRecordD59HR]->size = sizeof(prec->d59hr);
    prt->papFldDes[sscanRecordD59HR]->offset = (unsigned short)offsetof(sscanRecord, d59hr);
    prt->papFldDes[sscanRecordD59LR]->size = sizeof(prec->d59lr);
    prt->papFldDes[sscanRecordD59LR]->offset = (unsigned short)offsetof(sscanRecord, d59lr);
    prt->papFldDes[sscanRecordD59DA]->size = sizeof(prec->d59da);
    prt->papFldDes[sscanRecordD59DA]->offset = (unsigned short)offsetof(sscanRecord, d59da);
    prt->papFldDes[sscanRecordD59CA]->size = sizeof(prec->d59ca);
    prt->papFldDes[sscanRecordD59CA]->offset = (unsigned short)offsetof(sscanRecord, d59ca);
    prt->papFldDes[sscanRecordD59CV]->size = sizeof(prec->d59cv);
    prt->papFldDes[sscanRecordD59CV]->offset = (unsigned short)offsetof(sscanRecord, d59cv);
    prt->papFldDes[sscanRecordD59LV]->size = sizeof(prec->d59lv);
    prt->papFldDes[sscanRecordD59LV]->offset = (unsigned short)offsetof(sscanRecord, d59lv);
    prt->papFldDes[sscanRecordD59NE]->size = sizeof(prec->d59ne);
    prt->papFldDes[sscanRecordD59NE]->offset = (unsigned short)offsetof(sscanRecord, d59ne);
    prt->papFldDes[sscanRecordD59EU]->size = sizeof(prec->d59eu);
    prt->papFldDes[sscanRecordD59EU]->offset = (unsigned short)offsetof(sscanRecord, d59eu);
    prt->papFldDes[sscanRecordD59PR]->size = sizeof(prec->d59pr);
    prt->papFldDes[sscanRecordD59PR]->offset = (unsigned short)offsetof(sscanRecord, d59pr);
    prt->papFldDes[sscanRecordD60HR]->size = sizeof(prec->d60hr);
    prt->papFldDes[sscanRecordD60HR]->offset = (unsigned short)offsetof(sscanRecord, d60hr);
    prt->papFldDes[sscanRecordD60LR]->size = sizeof(prec->d60lr);
    prt->papFldDes[sscanRecordD60LR]->offset = (unsigned short)offsetof(sscanRecord, d60lr);
    prt->papFldDes[sscanRecordD60DA]->size = sizeof(prec->d60da);
    prt->papFldDes[sscanRecordD60DA]->offset = (unsigned short)offsetof(sscanRecord, d60da);
    prt->papFldDes[sscanRecordD60CA]->size = sizeof(prec->d60ca);
    prt->papFldDes[sscanRecordD60CA]->offset = (unsigned short)offsetof(sscanRecord, d60ca);
    prt->papFldDes[sscanRecordD60CV]->size = sizeof(prec->d60cv);
    prt->papFldDes[sscanRecordD60CV]->offset = (unsigned short)offsetof(sscanRecord, d60cv);
    prt->papFldDes[sscanRecordD60LV]->size = sizeof(prec->d60lv);
    prt->papFldDes[sscanRecordD60LV]->offset = (unsigned short)offsetof(sscanRecord, d60lv);
    prt->papFldDes[sscanRecordD60NE]->size = sizeof(prec->d60ne);
    prt->papFldDes[sscanRecordD60NE]->offset = (unsigned short)offsetof(sscanRecord, d60ne);
    prt->papFldDes[sscanRecordD60EU]->size = sizeof(prec->d60eu);
    prt->papFldDes[sscanRecordD60EU]->offset = (unsigned short)offsetof(sscanRecord, d60eu);
    prt->papFldDes[sscanRecordD60PR]->size = sizeof(prec->d60pr);
    prt->papFldDes[sscanRecordD60PR]->offset = (unsigned short)offsetof(sscanRecord, d60pr);
    prt->papFldDes[sscanRecordD61HR]->size = sizeof(prec->d61hr);
    prt->papFldDes[sscanRecordD61HR]->offset = (unsigned short)offsetof(sscanRecord, d61hr);
    prt->papFldDes[sscanRecordD61LR]->size = sizeof(prec->d61lr);
    prt->papFldDes[sscanRecordD61LR]->offset = (unsigned short)offsetof(sscanRecord, d61lr);
    prt->papFldDes[sscanRecordD61DA]->size = sizeof(prec->d61da);
    prt->papFldDes[sscanRecordD61DA]->offset = (unsigned short)offsetof(sscanRecord, d61da);
    prt->papFldDes[sscanRecordD61CA]->size = sizeof(prec->d61ca);
    prt->papFldDes[sscanRecordD61CA]->offset = (unsigned short)offsetof(sscanRecord, d61ca);
    prt->papFldDes[sscanRecordD61CV]->size = sizeof(prec->d61cv);
    prt->papFldDes[sscanRecordD61CV]->offset = (unsigned short)offsetof(sscanRecord, d61cv);
    prt->papFldDes[sscanRecordD61LV]->size = sizeof(prec->d61lv);
    prt->papFldDes[sscanRecordD61LV]->offset = (unsigned short)offsetof(sscanRecord, d61lv);
    prt->papFldDes[sscanRecordD61NE]->size = sizeof(prec->d61ne);
    prt->papFldDes[sscanRecordD61NE]->offset = (unsigned short)offsetof(sscanRecord, d61ne);
    prt->papFldDes[sscanRecordD61EU]->size = sizeof(prec->d61eu);
    prt->papFldDes[sscanRecordD61EU]->offset = (unsigned short)offsetof(sscanRecord, d61eu);
    prt->papFldDes[sscanRecordD61PR]->size = sizeof(prec->d61pr);
    prt->papFldDes[sscanRecordD61PR]->offset = (unsigned short)offsetof(sscanRecord, d61pr);
    prt->papFldDes[sscanRecordD62HR]->size = sizeof(prec->d62hr);
    prt->papFldDes[sscanRecordD62HR]->offset = (unsigned short)offsetof(sscanRecord, d62hr);
    prt->papFldDes[sscanRecordD62LR]->size = sizeof(prec->d62lr);
    prt->papFldDes[sscanRecordD62LR]->offset = (unsigned short)offsetof(sscanRecord, d62lr);
    prt->papFldDes[sscanRecordD62DA]->size = sizeof(prec->d62da);
    prt->papFldDes[sscanRecordD62DA]->offset = (unsigned short)offsetof(sscanRecord, d62da);
    prt->papFldDes[sscanRecordD62CA]->size = sizeof(prec->d62ca);
    prt->papFldDes[sscanRecordD62CA]->offset = (unsigned short)offsetof(sscanRecord, d62ca);
    prt->papFldDes[sscanRecordD62CV]->size = sizeof(prec->d62cv);
    prt->papFldDes[sscanRecordD62CV]->offset = (unsigned short)offsetof(sscanRecord, d62cv);
    prt->papFldDes[sscanRecordD62LV]->size = sizeof(prec->d62lv);
    prt->papFldDes[sscanRecordD62LV]->offset = (unsigned short)offsetof(sscanRecord, d62lv);
    prt->papFldDes[sscanRecordD62NE]->size = sizeof(prec->d62ne);
    prt->papFldDes[sscanRecordD62NE]->offset = (unsigned short)offsetof(sscanRecord, d62ne);
    prt->papFldDes[sscanRecordD62EU]->size = sizeof(prec->d62eu);
    prt->papFldDes[sscanRecordD62EU]->offset = (unsigned short)offsetof(sscanRecord, d62eu);
    prt->papFldDes[sscanRecordD62PR]->size = sizeof(prec->d62pr);
    prt->papFldDes[sscanRecordD62PR]->offset = (unsigned short)offsetof(sscanRecord, d62pr);
    prt->papFldDes[sscanRecordD63HR]->size = sizeof(prec->d63hr);
    prt->papFldDes[sscanRecordD63HR]->offset = (unsigned short)offsetof(sscanRecord, d63hr);
    prt->papFldDes[sscanRecordD63LR]->size = sizeof(prec->d63lr);
    prt->papFldDes[sscanRecordD63LR]->offset = (unsigned short)offsetof(sscanRecord, d63lr);
    prt->papFldDes[sscanRecordD63DA]->size = sizeof(prec->d63da);
    prt->papFldDes[sscanRecordD63DA]->offset = (unsigned short)offsetof(sscanRecord, d63da);
    prt->papFldDes[sscanRecordD63CA]->size = sizeof(prec->d63ca);
    prt->papFldDes[sscanRecordD63CA]->offset = (unsigned short)offsetof(sscanRecord, d63ca);
    prt->papFldDes[sscanRecordD63CV]->size = sizeof(prec->d63cv);
    prt->papFldDes[sscanRecordD63CV]->offset = (unsigned short)offsetof(sscanRecord, d63cv);
    prt->papFldDes[sscanRecordD63LV]->size = sizeof(prec->d63lv);
    prt->papFldDes[sscanRecordD63LV]->offset = (unsigned short)offsetof(sscanRecord, d63lv);
    prt->papFldDes[sscanRecordD63NE]->size = sizeof(prec->d63ne);
    prt->papFldDes[sscanRecordD63NE]->offset = (unsigned short)offsetof(sscanRecord, d63ne);
    prt->papFldDes[sscanRecordD63EU]->size = sizeof(prec->d63eu);
    prt->papFldDes[sscanRecordD63EU]->offset = (unsigned short)offsetof(sscanRecord, d63eu);
    prt->papFldDes[sscanRecordD63PR]->size = sizeof(prec->d63pr);
    prt->papFldDes[sscanRecordD63PR]->offset = (unsigned short)offsetof(sscanRecord, d63pr);
    prt->papFldDes[sscanRecordD64HR]->size = sizeof(prec->d64hr);
    prt->papFldDes[sscanRecordD64HR]->offset = (unsigned short)offsetof(sscanRecord, d64hr);
    prt->papFldDes[sscanRecordD64LR]->size = sizeof(prec->d64lr);
    prt->papFldDes[sscanRecordD64LR]->offset = (unsigned short)offsetof(sscanRecord, d64lr);
    prt->papFldDes[sscanRecordD64DA]->size = sizeof(prec->d64da);
    prt->papFldDes[sscanRecordD64DA]->offset = (unsigned short)offsetof(sscanRecord, d64da);
    prt->papFldDes[sscanRecordD64CA]->size = sizeof(prec->d64ca);
    prt->papFldDes[sscanRecordD64CA]->offset = (unsigned short)offsetof(sscanRecord, d64ca);
    prt->papFldDes[sscanRecordD64CV]->size = sizeof(prec->d64cv);
    prt->papFldDes[sscanRecordD64CV]->offset = (unsigned short)offsetof(sscanRecord, d64cv);
    prt->papFldDes[sscanRecordD64LV]->size = sizeof(prec->d64lv);
    prt->papFldDes[sscanRecordD64LV]->offset = (unsigned short)offsetof(sscanRecord, d64lv);
    prt->papFldDes[sscanRecordD64NE]->size = sizeof(prec->d64ne);
    prt->papFldDes[sscanRecordD64NE]->offset = (unsigned short)offsetof(sscanRecord, d64ne);
    prt->papFldDes[sscanRecordD64EU]->size = sizeof(prec->d64eu);
    prt->papFldDes[sscanRecordD64EU]->offset = (unsigned short)offsetof(sscanRecord, d64eu);
    prt->papFldDes[sscanRecordD64PR]->size = sizeof(prec->d64pr);
    prt->papFldDes[sscanRecordD64PR]->offset = (unsigned short)offsetof(sscanRecord, d64pr);
    prt->papFldDes[sscanRecordD65HR]->size = sizeof(prec->d65hr);
    prt->papFldDes[sscanRecordD65HR]->offset = (unsigned short)offsetof(sscanRecord, d65hr);
    prt->papFldDes[sscanRecordD65LR]->size = sizeof(prec->d65lr);
    prt->papFldDes[sscanRecordD65LR]->offset = (unsigned short)offsetof(sscanRecord, d65lr);
    prt->papFldDes[sscanRecordD65DA]->size = sizeof(prec->d65da);
    prt->papFldDes[sscanRecordD65DA]->offset = (unsigned short)offsetof(sscanRecord, d65da);
    prt->papFldDes[sscanRecordD65CA]->size = sizeof(prec->d65ca);
    prt->papFldDes[sscanRecordD65CA]->offset = (unsigned short)offsetof(sscanRecord, d65ca);
    prt->papFldDes[sscanRecordD65CV]->size = sizeof(prec->d65cv);
    prt->papFldDes[sscanRecordD65CV]->offset = (unsigned short)offsetof(sscanRecord, d65cv);
    prt->papFldDes[sscanRecordD65LV]->size = sizeof(prec->d65lv);
    prt->papFldDes[sscanRecordD65LV]->offset = (unsigned short)offsetof(sscanRecord, d65lv);
    prt->papFldDes[sscanRecordD65NE]->size = sizeof(prec->d65ne);
    prt->papFldDes[sscanRecordD65NE]->offset = (unsigned short)offsetof(sscanRecord, d65ne);
    prt->papFldDes[sscanRecordD65EU]->size = sizeof(prec->d65eu);
    prt->papFldDes[sscanRecordD65EU]->offset = (unsigned short)offsetof(sscanRecord, d65eu);
    prt->papFldDes[sscanRecordD65PR]->size = sizeof(prec->d65pr);
    prt->papFldDes[sscanRecordD65PR]->offset = (unsigned short)offsetof(sscanRecord, d65pr);
    prt->papFldDes[sscanRecordD66HR]->size = sizeof(prec->d66hr);
    prt->papFldDes[sscanRecordD66HR]->offset = (unsigned short)offsetof(sscanRecord, d66hr);
    prt->papFldDes[sscanRecordD66LR]->size = sizeof(prec->d66lr);
    prt->papFldDes[sscanRecordD66LR]->offset = (unsigned short)offsetof(sscanRecord, d66lr);
    prt->papFldDes[sscanRecordD66DA]->size = sizeof(prec->d66da);
    prt->papFldDes[sscanRecordD66DA]->offset = (unsigned short)offsetof(sscanRecord, d66da);
    prt->papFldDes[sscanRecordD66CA]->size = sizeof(prec->d66ca);
    prt->papFldDes[sscanRecordD66CA]->offset = (unsigned short)offsetof(sscanRecord, d66ca);
    prt->papFldDes[sscanRecordD66CV]->size = sizeof(prec->d66cv);
    prt->papFldDes[sscanRecordD66CV]->offset = (unsigned short)offsetof(sscanRecord, d66cv);
    prt->papFldDes[sscanRecordD66LV]->size = sizeof(prec->d66lv);
    prt->papFldDes[sscanRecordD66LV]->offset = (unsigned short)offsetof(sscanRecord, d66lv);
    prt->papFldDes[sscanRecordD66NE]->size = sizeof(prec->d66ne);
    prt->papFldDes[sscanRecordD66NE]->offset = (unsigned short)offsetof(sscanRecord, d66ne);
    prt->papFldDes[sscanRecordD66EU]->size = sizeof(prec->d66eu);
    prt->papFldDes[sscanRecordD66EU]->offset = (unsigned short)offsetof(sscanRecord, d66eu);
    prt->papFldDes[sscanRecordD66PR]->size = sizeof(prec->d66pr);
    prt->papFldDes[sscanRecordD66PR]->offset = (unsigned short)offsetof(sscanRecord, d66pr);
    prt->papFldDes[sscanRecordD67HR]->size = sizeof(prec->d67hr);
    prt->papFldDes[sscanRecordD67HR]->offset = (unsigned short)offsetof(sscanRecord, d67hr);
    prt->papFldDes[sscanRecordD67LR]->size = sizeof(prec->d67lr);
    prt->papFldDes[sscanRecordD67LR]->offset = (unsigned short)offsetof(sscanRecord, d67lr);
    prt->papFldDes[sscanRecordD67DA]->size = sizeof(prec->d67da);
    prt->papFldDes[sscanRecordD67DA]->offset = (unsigned short)offsetof(sscanRecord, d67da);
    prt->papFldDes[sscanRecordD67CA]->size = sizeof(prec->d67ca);
    prt->papFldDes[sscanRecordD67CA]->offset = (unsigned short)offsetof(sscanRecord, d67ca);
    prt->papFldDes[sscanRecordD67CV]->size = sizeof(prec->d67cv);
    prt->papFldDes[sscanRecordD67CV]->offset = (unsigned short)offsetof(sscanRecord, d67cv);
    prt->papFldDes[sscanRecordD67LV]->size = sizeof(prec->d67lv);
    prt->papFldDes[sscanRecordD67LV]->offset = (unsigned short)offsetof(sscanRecord, d67lv);
    prt->papFldDes[sscanRecordD67NE]->size = sizeof(prec->d67ne);
    prt->papFldDes[sscanRecordD67NE]->offset = (unsigned short)offsetof(sscanRecord, d67ne);
    prt->papFldDes[sscanRecordD67EU]->size = sizeof(prec->d67eu);
    prt->papFldDes[sscanRecordD67EU]->offset = (unsigned short)offsetof(sscanRecord, d67eu);
    prt->papFldDes[sscanRecordD67PR]->size = sizeof(prec->d67pr);
    prt->papFldDes[sscanRecordD67PR]->offset = (unsigned short)offsetof(sscanRecord, d67pr);
    prt->papFldDes[sscanRecordD68HR]->size = sizeof(prec->d68hr);
    prt->papFldDes[sscanRecordD68HR]->offset = (unsigned short)offsetof(sscanRecord, d68hr);
    prt->papFldDes[sscanRecordD68LR]->size = sizeof(prec->d68lr);
    prt->papFldDes[sscanRecordD68LR]->offset = (unsigned short)offsetof(sscanRecord, d68lr);
    prt->papFldDes[sscanRecordD68DA]->size = sizeof(prec->d68da);
    prt->papFldDes[sscanRecordD68DA]->offset = (unsigned short)offsetof(sscanRecord, d68da);
    prt->papFldDes[sscanRecordD68CA]->size = sizeof(prec->d68ca);
    prt->papFldDes[sscanRecordD68CA]->offset = (unsigned short)offsetof(sscanRecord, d68ca);
    prt->papFldDes[sscanRecordD68CV]->size = sizeof(prec->d68cv);
    prt->papFldDes[sscanRecordD68CV]->offset = (unsigned short)offsetof(sscanRecord, d68cv);
    prt->papFldDes[sscanRecordD68LV]->size = sizeof(prec->d68lv);
    prt->papFldDes[sscanRecordD68LV]->offset = (unsigned short)offsetof(sscanRecord, d68lv);
    prt->papFldDes[sscanRecordD68NE]->size = sizeof(prec->d68ne);
    prt->papFldDes[sscanRecordD68NE]->offset = (unsigned short)offsetof(sscanRecord, d68ne);
    prt->papFldDes[sscanRecordD68EU]->size = sizeof(prec->d68eu);
    prt->papFldDes[sscanRecordD68EU]->offset = (unsigned short)offsetof(sscanRecord, d68eu);
    prt->papFldDes[sscanRecordD68PR]->size = sizeof(prec->d68pr);
    prt->papFldDes[sscanRecordD68PR]->offset = (unsigned short)offsetof(sscanRecord, d68pr);
    prt->papFldDes[sscanRecordD69HR]->size = sizeof(prec->d69hr);
    prt->papFldDes[sscanRecordD69HR]->offset = (unsigned short)offsetof(sscanRecord, d69hr);
    prt->papFldDes[sscanRecordD69LR]->size = sizeof(prec->d69lr);
    prt->papFldDes[sscanRecordD69LR]->offset = (unsigned short)offsetof(sscanRecord, d69lr);
    prt->papFldDes[sscanRecordD69DA]->size = sizeof(prec->d69da);
    prt->papFldDes[sscanRecordD69DA]->offset = (unsigned short)offsetof(sscanRecord, d69da);
    prt->papFldDes[sscanRecordD69CA]->size = sizeof(prec->d69ca);
    prt->papFldDes[sscanRecordD69CA]->offset = (unsigned short)offsetof(sscanRecord, d69ca);
    prt->papFldDes[sscanRecordD69CV]->size = sizeof(prec->d69cv);
    prt->papFldDes[sscanRecordD69CV]->offset = (unsigned short)offsetof(sscanRecord, d69cv);
    prt->papFldDes[sscanRecordD69LV]->size = sizeof(prec->d69lv);
    prt->papFldDes[sscanRecordD69LV]->offset = (unsigned short)offsetof(sscanRecord, d69lv);
    prt->papFldDes[sscanRecordD69NE]->size = sizeof(prec->d69ne);
    prt->papFldDes[sscanRecordD69NE]->offset = (unsigned short)offsetof(sscanRecord, d69ne);
    prt->papFldDes[sscanRecordD69EU]->size = sizeof(prec->d69eu);
    prt->papFldDes[sscanRecordD69EU]->offset = (unsigned short)offsetof(sscanRecord, d69eu);
    prt->papFldDes[sscanRecordD69PR]->size = sizeof(prec->d69pr);
    prt->papFldDes[sscanRecordD69PR]->offset = (unsigned short)offsetof(sscanRecord, d69pr);
    prt->papFldDes[sscanRecordD70HR]->size = sizeof(prec->d70hr);
    prt->papFldDes[sscanRecordD70HR]->offset = (unsigned short)offsetof(sscanRecord, d70hr);
    prt->papFldDes[sscanRecordD70LR]->size = sizeof(prec->d70lr);
    prt->papFldDes[sscanRecordD70LR]->offset = (unsigned short)offsetof(sscanRecord, d70lr);
    prt->papFldDes[sscanRecordD70DA]->size = sizeof(prec->d70da);
    prt->papFldDes[sscanRecordD70DA]->offset = (unsigned short)offsetof(sscanRecord, d70da);
    prt->papFldDes[sscanRecordD70CA]->size = sizeof(prec->d70ca);
    prt->papFldDes[sscanRecordD70CA]->offset = (unsigned short)offsetof(sscanRecord, d70ca);
    prt->papFldDes[sscanRecordD70CV]->size = sizeof(prec->d70cv);
    prt->papFldDes[sscanRecordD70CV]->offset = (unsigned short)offsetof(sscanRecord, d70cv);
    prt->papFldDes[sscanRecordD70LV]->size = sizeof(prec->d70lv);
    prt->papFldDes[sscanRecordD70LV]->offset = (unsigned short)offsetof(sscanRecord, d70lv);
    prt->papFldDes[sscanRecordD70NE]->size = sizeof(prec->d70ne);
    prt->papFldDes[sscanRecordD70NE]->offset = (unsigned short)offsetof(sscanRecord, d70ne);
    prt->papFldDes[sscanRecordD70EU]->size = sizeof(prec->d70eu);
    prt->papFldDes[sscanRecordD70EU]->offset = (unsigned short)offsetof(sscanRecord, d70eu);
    prt->papFldDes[sscanRecordD70PR]->size = sizeof(prec->d70pr);
    prt->papFldDes[sscanRecordD70PR]->offset = (unsigned short)offsetof(sscanRecord, d70pr);
    prt->papFldDes[sscanRecordT1CD]->size = sizeof(prec->t1cd);
    prt->papFldDes[sscanRecordT1CD]->offset = (unsigned short)offsetof(sscanRecord, t1cd);
    prt->papFldDes[sscanRecordT2CD]->size = sizeof(prec->t2cd);
    prt->papFldDes[sscanRecordT2CD]->offset = (unsigned short)offsetof(sscanRecord, t2cd);
    prt->papFldDes[sscanRecordT3CD]->size = sizeof(prec->t3cd);
    prt->papFldDes[sscanRecordT3CD]->offset = (unsigned short)offsetof(sscanRecord, t3cd);
    prt->papFldDes[sscanRecordT4CD]->size = sizeof(prec->t4cd);
    prt->papFldDes[sscanRecordT4CD]->offset = (unsigned short)offsetof(sscanRecord, t4cd);
    prt->papFldDes[sscanRecordA1CD]->size = sizeof(prec->a1cd);
    prt->papFldDes[sscanRecordA1CD]->offset = (unsigned short)offsetof(sscanRecord, a1cd);
    prt->papFldDes[sscanRecordBSCD]->size = sizeof(prec->bscd);
    prt->papFldDes[sscanRecordBSCD]->offset = (unsigned short)offsetof(sscanRecord, bscd);
    prt->papFldDes[sscanRecordASCD]->size = sizeof(prec->ascd);
    prt->papFldDes[sscanRecordASCD]->offset = (unsigned short)offsetof(sscanRecord, ascd);
    prt->papFldDes[sscanRecordPAUS]->size = sizeof(prec->paus);
    prt->papFldDes[sscanRecordPAUS]->offset = (unsigned short)offsetof(sscanRecord, paus);
    prt->papFldDes[sscanRecordLPAU]->size = sizeof(prec->lpau);
    prt->papFldDes[sscanRecordLPAU]->offset = (unsigned short)offsetof(sscanRecord, lpau);
    prt->papFldDes[sscanRecordPDLY]->size = sizeof(prec->pdly);
    prt->papFldDes[sscanRecordPDLY]->offset = (unsigned short)offsetof(sscanRecord, pdly);
    prt->papFldDes[sscanRecordDDLY]->size = sizeof(prec->ddly);
    prt->papFldDes[sscanRecordDDLY]->offset = (unsigned short)offsetof(sscanRecord, ddly);
    prt->papFldDes[sscanRecordRDLY]->size = sizeof(prec->rdly);
    prt->papFldDes[sscanRecordRDLY]->offset = (unsigned short)offsetof(sscanRecord, rdly);
    prt->papFldDes[sscanRecordFAZE]->size = sizeof(prec->faze);
    prt->papFldDes[sscanRecordFAZE]->offset = (unsigned short)offsetof(sscanRecord, faze);
    prt->papFldDes[sscanRecordACQM]->size = sizeof(prec->acqm);
    prt->papFldDes[sscanRecordACQM]->offset = (unsigned short)offsetof(sscanRecord, acqm);
    prt->papFldDes[sscanRecordACQT]->size = sizeof(prec->acqt);
    prt->papFldDes[sscanRecordACQT]->offset = (unsigned short)offsetof(sscanRecord, acqt);
    prt->papFldDes[sscanRecordDSTATE]->size = sizeof(prec->dstate);
    prt->papFldDes[sscanRecordDSTATE]->offset = (unsigned short)offsetof(sscanRecord, dstate);
    prt->papFldDes[sscanRecordCOPYTO]->size = sizeof(prec->copyto);
    prt->papFldDes[sscanRecordCOPYTO]->offset = (unsigned short)offsetof(sscanRecord, copyto);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(sscanRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_sscanRecord_H */
