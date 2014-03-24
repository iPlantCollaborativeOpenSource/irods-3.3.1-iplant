/**
 * @file  dataObjCopy.h
 *
 */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* dataObjCopy.h - This dataObj may be generated by a program or script
 */

#ifndef DATA_OBJ_COPY_H
#define DATA_OBJ_COPY_H

/* This is a high level type API call */

#include "rods.h"
#include "procApiRequest.h"
#include "apiNumber.h"

/**
 * \var dataObjCopyInp_t
 * \brief Input struct for Copy Data object operation
 * \since 1.0
 *
 * \remark none
 *
 * \note
 * Elements of dataObjCopyInp_t:
 * \li dataObjInp_t srcDataObjInp - dataObjInp_t for the source data object.
 * \li dataObjInp_t destDataObjInp - dataObjInp_t for the target data object.
 *
 * \sa none
 * \bug  no known bugs
 */

typedef struct DataObjCopyInp {
    dataObjInp_t srcDataObjInp;
    dataObjInp_t destDataObjInp;
} dataObjCopyInp_t;

#define DataObjCopyInp_PI "struct DataObjInp_PI; struct DataObjInp_PI;"

#if defined(RODS_SERVER)
#define RS_DATA_OBJ_COPY250 rsDataObjCopy250
#define RS_DATA_OBJ_COPY rsDataObjCopy
/* prototype for the server handler */
int
rsDataObjCopy250 (rsComm_t *rsComm, dataObjCopyInp_t *dataObjCopyInp,
transStat_t **transStat);
int
rsDataObjCopy (rsComm_t *rsComm, dataObjCopyInp_t *dataObjCopyInp,
transferStat_t **transferStat);
int
_rsDataObjCopy (rsComm_t *rsComm, int destL1descInx, int existFlag,
transferStat_t **transStat);
int
getAndConnRemoteZoneForCopy (rsComm_t *rsComm, dataObjCopyInp_t *dataObjCopyInp,
rodsServerHost_t **rodsServerHost);
#else
#define RS_DATA_OBJ_COPY NULL
#define RS_DATA_OBJ_COPY250 NULL
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/* prototype for the client call */
/* rcDataObjCopy - Copy a iRODS data object.
 * Input -
 *   rcComm_t *conn - The client connection handle.
 *   dataObjCopyInp_t *dataObjCopyInp - Relevant items are:
 *	dataObjInp_t srcDataObjInp - The source dataObj. Relevant items are:
 *	    objPath - the source object path.
 *	destDataObjInp - The destination dataObj. Relevant items are:
 *          objPath - the destination object path.
 *	    condInput - DATA_TYPE_KW - "value" = the data type of the object
 *	                FORCE_FLAG_KW - overwrite an existing data object
 *			REG_CHKSUM_KW - compute the checksum value
 *		 	VERIFY_CHKSUM_KW - compute and verify the checksum on 
 *			  the data.
 *			FILE_PATH_KW - "value" = the physical path of the 
 *			  destination file.
 *			DEST_RESC_NAME_KW - "value" = The destination Resource.
 *	    numThreads - number of threads to use. NO_THREADING = no threading.	
 *	    openFlags - Open flag for the copy operation. Should be O_WRONLY. 
 *	    createMode - the file mode (optional).
 *
 * OutPut -
 *    int status of the operation - >= 0 ==> success, < 0 ==> failure.
 */

int
rcDataObjCopy (rcComm_t *conn, dataObjCopyInp_t *dataObjCopyInp);
int
_rcDataObjCopy (rcComm_t *conn, dataObjCopyInp_t *dataObjCopyInp,
transferStat_t **transferStat);
int
_rcDataObjCopy250 (rcComm_t *conn, dataObjCopyInp_t *dataObjCopyInp,
transStat_t **transStat);
int
clearDataObjCopyInp (dataObjCopyInp_t *dataObjCopyInp);
#ifdef  __cplusplus
}
#endif

#endif	/* DATA_OBJ_COPY_H */
