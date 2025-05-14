/*recDynLink.c*/
/*****************************************************************
                          COPYRIGHT NOTIFICATION
*****************************************************************

(C)  COPYRIGHT 1993 UNIVERSITY OF CHICAGO
 
This software was developed under a United States Government license
described on the COPYRIGHT_UniversityOfChicago file included as part
of this distribution.
*******************************************************************/
#ifndef INCrecDynLinkh
#define INCrecDynLinkh

/* tmm not in 3.15.0.1 #include <tsDefs.h> */
typedef struct recDynLink{
	void	*puserPvt;
	void	*pdynLinkPvt;
	short	status;
	short	onQueue;
	short	getCallbackInProgress;
} recDynLink;
typedef void (*recDynCallback)(recDynLink *);

#define NOTIFY_IN_PROGRESS 1
#define RINGBUFF_PUT_ERROR 2
#define FATAL_ERROR 3

#define rdlDBONLY	0x1
#define rdlSCALAR	0x2

epicsShareFunc long epicsShareAPI recDynLinkAddInput(recDynLink *precDynLink,char *pvname,
	short dbrType,int options,
	recDynCallback searchCallback,recDynCallback monitorCallback);
epicsShareFunc long epicsShareAPI recDynLinkAddOutput(recDynLink *precDynLink,char *pvname,
	short dbrType,int options, recDynCallback searchCallback);
epicsShareFunc long epicsShareAPI recDynLinkClear(recDynLink *precDynLink);
/*The following routine returns (0,-1) for (connected,not connected)*/
epicsShareFunc long epicsShareAPI recDynLinkConnectionStatus(recDynLink *precDynLink);
/*thye following routine returns (0,-1) if (connected,not connected)*/
epicsShareFunc long epicsShareAPI recDynLinkGetNelem(recDynLink *precDynLink,size_t *nelem);
/*The following 4 routines return (0,-1) if data (is, is not) yet available*/
/*searchCallback is not called until this info is available*/
epicsShareFunc long epicsShareAPI recDynLinkGetControlLimits(recDynLink *precDynLink,
	double *low,double *high);
epicsShareFunc long epicsShareAPI recDynLinkGetGraphicLimits(recDynLink *precDynLink,
	double *low,double *high);
epicsShareFunc long epicsShareAPI recDynLinkGetPrecision(recDynLink *precDynLink,int *prec);
epicsShareFunc long epicsShareAPI recDynLinkGetUnits(recDynLink *precDynLink,char *units,int maxlen);

/*get only valid mfor rdlINPUT. put only valid for rdlOUTPUT*/
epicsShareFunc long epicsShareAPI recDynLinkGet(recDynLink *precDynLink, void *pbuffer, size_t *nRequest,
	TS_STAMP *timestamp,short *status,short *severity);
long epicsShareAPI recDynLinkGetCallback(recDynLink *precDynLink, size_t *nRequest, recDynCallback userGetCallback);
epicsShareFunc long epicsShareAPI recDynLinkPut(recDynLink *precDynLink,void *pbuffer,size_t nRequest);
epicsShareFunc long epicsShareAPI recDynLinkPutCallback(recDynLink *precDynLink,void *pbuffer,size_t nRequest, recDynCallback notifyCallback);

/* bitmask */
#define ACCESS_NONE 0
#define ACCESS_READ 1
#define ACCESS_WRITE 2
int epicsShareAPI recDynLinkCheckReadWriteAccess(recDynLink *precDynLink);

#endif /*INCrecDynLinkh*/
