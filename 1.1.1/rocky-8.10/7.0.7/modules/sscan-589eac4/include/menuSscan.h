/** @file menuSscan.h
 * @brief Declarations generated from menuSscan.dbd
 */

#ifndef INC_menuSscan_H
#define INC_menuSscan_H

#ifndef sscanP1SM_NUM_CHOICES
/** @brief Enumerated type from menu sscanP1SM */
typedef enum {
    sscanP1SM_Linear                /**< @brief State string "LINEAR" */,
    sscanP1SM_Table                 /**< @brief State string "TABLE" */,
    sscanP1SM_On_The_Fly            /**< @brief State string "FLY" */
} sscanP1SM;
/** @brief Number of states defined for menu sscanP1SM */
#define sscanP1SM_NUM_CHOICES 3
#endif

#ifndef sscanNOYES_NUM_CHOICES
/** @brief Enumerated type from menu sscanNOYES */
typedef enum {
    sscanNOYES_NO                   /**< @brief State string "NO" */,
    sscanNOYES_YES                  /**< @brief State string "YES" */
} sscanNOYES;
/** @brief Number of states defined for menu sscanNOYES */
#define sscanNOYES_NUM_CHOICES 2
#endif

#ifndef sscanDSTATE_NUM_CHOICES
/** @brief Enumerated type from menu sscanDSTATE */
typedef enum {
    sscanDSTATE_UNPACKED            /**< @brief State string "UNPACKED" */,
    sscanDSTATE_TRIG_ARRAY_READ     /**< @brief State string "TRIG_ARRAY_READ" */,
    sscanDSTATE_ARRAY_READ_WAIT     /**< @brief State string "ARRAY_READ_WAIT" */,
    sscanDSTATE_ARRAY_GET_CALLBACK_WAIT /**< @brief State string "ARRAY_GET_CALLBACK_WAIT" */,
    sscanDSTATE_RECORD_ARRAY_DATA   /**< @brief State string "RECORD_ARRAY_DATA" */,
    sscanDSTATE_SAVE_DATA_WAIT      /**< @brief State string "SAVE_DATA_WAIT" */,
    sscanDSTATE_PACKED              /**< @brief State string "PACKED" */,
    sscanDSTATE_POSTED              /**< @brief State string "POSTED" */
} sscanDSTATE;
/** @brief Number of states defined for menu sscanDSTATE */
#define sscanDSTATE_NUM_CHOICES 8
#endif

#ifndef sscanPASM_NUM_CHOICES
/** @brief Enumerated type from menu sscanPASM */
typedef enum {
    sscanPASM_Stay                  /**< @brief State string "STAY" */,
    sscanPASM_Start_Pos             /**< @brief State string "START POS" */,
    sscanPASM_Prior_Pos             /**< @brief State string "PRIOR POS" */,
    sscanPASM_Peak_Pos              /**< @brief State string "PEAK POS" */,
    sscanPASM_Valley_Pos            /**< @brief State string "VALLEY POS" */,
    sscanPASM_RisingEdge_Pos        /**< @brief State string "+EDGE POS" */,
    sscanPASM_FallingEdge_Pos       /**< @brief State string "-EDGE POS" */,
    sscanPASM_COM                   /**< @brief State string "CNTR OF MASS" */
} sscanPASM;
/** @brief Number of states defined for menu sscanPASM */
#define sscanPASM_NUM_CHOICES 8
#endif

#ifndef sscanPAUS_NUM_CHOICES
/** @brief Enumerated type from menu sscanPAUS */
typedef enum {
    sscanPAUS_Go                    /**< @brief State string "GO" */,
    sscanPAUS_Pause                 /**< @brief State string "PAUSE" */
} sscanPAUS;
/** @brief Number of states defined for menu sscanPAUS */
#define sscanPAUS_NUM_CHOICES 2
#endif

#ifndef sscanFPTS_NUM_CHOICES
/** @brief Enumerated type from menu sscanFPTS */
typedef enum {
    sscanFPTS_No                    /**< @brief State string "NO" */,
    sscanFPTS_Freeze                /**< @brief State string "FREEZE" */
} sscanFPTS;
/** @brief Number of states defined for menu sscanFPTS */
#define sscanFPTS_NUM_CHOICES 2
#endif

#ifndef sscanFFO_NUM_CHOICES
/** @brief Enumerated type from menu sscanFFO */
typedef enum {
    sscanFFO_Use_F_Flags            /**< @brief State string "USE F-FLAGS" */,
    sscanFFO_Override               /**< @brief State string "OVERRIDE" */
} sscanFFO;
/** @brief Number of states defined for menu sscanFFO */
#define sscanFFO_NUM_CHOICES 2
#endif

#ifndef sscanFAZE_NUM_CHOICES
/** @brief Enumerated type from menu sscanFAZE */
typedef enum {
    sscanFAZE_IDLE                  /**< @brief State string "IDLE" */,
    sscanFAZE_INIT_SCAN             /**< @brief State string "INIT_SCAN" */,
    sscanFAZE_BEFORE_SCAN           /**< @brief State string "DO:BEFORE_SCAN" */,
    sscanFAZE_BEFORE_SCAN_WAIT      /**< @brief State string "WAIT:BEFORE_SCAN" */,
    sscanFAZE_MOVE_MOTORS           /**< @brief State string "MOVE_MOTORS" */,
    sscanFAZE_CHECK_MOTORS          /**< @brief State string "WAIT:MOTORS" */,
    sscanFAZE_TRIG_DETCTRS          /**< @brief State string "TRIG_DETCTRS" */,
    sscanFAZE_READ_DETCTRS          /**< @brief State string "WAIT:DETCTRS" */,
    sscanFAZE_RETRACE_MOVE          /**< @brief State string "RETRACE_MOVE" */,
    sscanFAZE_RETRACE_WAIT          /**< @brief State string "WAIT:RETRACE" */,
    sscanFAZE_AFTER_SCAN_DO         /**< @brief State string "DO:AFTER_SCAN" */,
    sscanFAZE_AFTER_SCAN_WAIT       /**< @brief State string "WAIT:AFTER_SCAN" */,
    sscanFAZE_SCAN_DONE             /**< @brief State string "SCAN_DONE" */,
    sscanFAZE_SCAN_PENDING          /**< @brief State string "SCAN_PENDING" */,
    sscanFAZE_PREVIEW               /**< @brief State string "PREVIEW" */,
    sscanFAZE_RECORD_SCALAR_DATA    /**< @brief State string "RECORD SCALAR DATA" */
} sscanFAZE;
/** @brief Number of states defined for menu sscanFAZE */
#define sscanFAZE_NUM_CHOICES 16
#endif

#ifndef sscanACQM_NUM_CHOICES
/** @brief Enumerated type from menu sscanACQM */
typedef enum {
    sscanACQM_NORMAL                /**< @brief State string "NORMAL" */,
    sscanACQM_ACC                   /**< @brief State string "ACCUMULATE" */,
    sscanACQM_ADD                   /**< @brief State string "ADD TO PREV" */
} sscanACQM;
/** @brief Number of states defined for menu sscanACQM */
#define sscanACQM_NUM_CHOICES 3
#endif

#ifndef sscanLINKWAIT_NUM_CHOICES
/** @brief Enumerated type from menu sscanLINKWAIT */
typedef enum {
    sscanLINKWAIT_YES               /**< @brief State string "Wait" */,
    sscanLINKWAIT_NO                /**< @brief State string "NoWait" */
} sscanLINKWAIT;
/** @brief Number of states defined for menu sscanLINKWAIT */
#define sscanLINKWAIT_NUM_CHOICES 2
#endif

#ifndef sscanCMND_NUM_CHOICES
/** @brief Enumerated type from menu sscanCMND */
typedef enum {
    sscanCMND_CLEAR_MSG             /**< @brief State string "Clear msg" */,
    sscanCMND_CHECK_LIMITS          /**< @brief State string "Check limits" */,
    sscanCMND_PREVIEW_SCAN          /**< @brief State string "Preview scan" */,
    sscanCMND_CLEAR_ALL_PVS         /**< @brief State string "Clear all PV's" */,
    sscanCMND_CLEAR_POS_PVS_ETC     /**< @brief State string "Clear pos PV's, etc" */,
    sscanCMND_CLEAR_POS_PVS         /**< @brief State string "Clear pos PV's" */,
    sscanCMND_CLEAR_POS_RDBK_PVS_ETC /**< @brief State string "Clear pos&rdbk PV's, etc" */,
    sscanCMND_CLEAR_POS_RDBK_PVS    /**< @brief State string "Clear pos&rdbk PV's" */
} sscanCMND;
/** @brief Number of states defined for menu sscanCMND */
#define sscanCMND_NUM_CHOICES 8
#endif

#ifndef sscanP1NV_NUM_CHOICES
/** @brief Enumerated type from menu sscanP1NV */
typedef enum {
    sscanP1NV_PV_OK                 /**< @brief State string "PV OK" */,
    sscanP1NV_No_PV                 /**< @brief State string "No PV" */,
    sscanP1NV_PV_NoRead             /**< @brief State string "PV NoRead" */,
    sscanP1NV_PV_xxx                /**< @brief State string "PV illegal1" */,
    sscanP1NV_PV_NoWrite            /**< @brief State string "PV NoWrite" */,
    sscanP1NV_PV_yyy                /**< @brief State string "PV illegal2" */,
    sscanP1NV_PV_NC                 /**< @brief State string "PV BAD" */
} sscanP1NV;
/** @brief Number of states defined for menu sscanP1NV */
#define sscanP1NV_NUM_CHOICES 7
#endif

#ifndef sscanP1AR_NUM_CHOICES
/** @brief Enumerated type from menu sscanP1AR */
typedef enum {
    sscanP1AR_Absolute              /**< @brief State string "ABSOLUTE" */,
    sscanP1AR_Relative              /**< @brief State string "RELATIVE" */
} sscanP1AR;
/** @brief Number of states defined for menu sscanP1AR */
#define sscanP1AR_NUM_CHOICES 2
#endif

#ifndef sscanACQT_NUM_CHOICES
/** @brief Enumerated type from menu sscanACQT */
typedef enum {
    sscanACQT_SCALAR                /**< @brief State string "SCALAR" */,
    sscanACQT_1D_ARRAY              /**< @brief State string "1D ARRAY" */
} sscanACQT;
/** @brief Number of states defined for menu sscanACQT */
#define sscanACQT_NUM_CHOICES 2
#endif


#endif /* INC_menuSscan_H */
