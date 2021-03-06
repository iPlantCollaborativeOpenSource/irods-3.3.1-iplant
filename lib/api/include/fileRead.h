/**
 * @file  fileRead.h
 *
 */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* fileRead.h - This file may be generated by a program or script
 */

#ifndef FILE_READ_H
#define FILE_READ_H

/* This is a low level file type API call */

#include "rods.h"
#include "rcMisc.h"
#include "procApiRequest.h"
#include "apiNumber.h"
#include "initServer.h"
#include "fileRead.h"

#include "fileDriver.h"

/**
 * \var fileReadInp_t
 * \brief Input struct for lower level read from the iRODS server
 * \since 1.0
 *
 * \remark none
 *
 * \note
 * Elements of fileReadInp_t:
 * \li int fileInx - The descriptor index for the read. 
 * \li int len - the length to read.
 * \sa none
 * \bug  no known bugs
 */

typedef struct FileReadInp {
    int fileInx;
    int len;
} fileReadInp_t;
    
#define fileReadInp_PI "int fileInx; int len;"

#if defined(RODS_SERVER)
#define RS_FILE_READ rsFileRead
/* prototype for the server handler */
int
rsFileRead (rsComm_t *rsComm, fileReadInp_t *fileReadInp, 
bytesBuf_t *fileReadOutBBuf);
int
_rsFileRead (rsComm_t *rsComm, fileReadInp_t *fileReadInp, 
bytesBuf_t *fileReadOutBBuf);
int
remoteFileRead (rsComm_t *rsComm, fileReadInp_t *fileReadInp,
bytesBuf_t *fileReadOutBBuf, rodsServerHost_t *rodsServerHost);
#else
#define RS_FILE_READ NULL
#endif

/* prototype for the client call */
int
rcFileRead (rcComm_t *conn, fileReadInp_t *fileReadInp,
bytesBuf_t *fileReadOutBBuf);

#endif	/* FILE_READ_H */
