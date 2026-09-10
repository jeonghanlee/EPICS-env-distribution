/*************************************************************************\
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Default main program */
#include "epicsThread.h"
#include "iocsh.h"

int main(int argc,char *argv[]) {
    char * macro_def;
    int callIocsh = TRUE;

    if(argc>1 && strcmp(argv[1],"-s")==0) {
        callIocsh = TRUE;
        --argc; ++argv;
    }
    if(argc>1 && strcmp(argv[1],"-S")==0) {
        --argc; ++argv;
        callIocsh = FALSE;
    }
    macro_def = (argc>1)?argv[1]:NULL;
    seqRegisterSequencerProgram(&PROG_NAME);
    seq(&PROG_NAME, macro_def, 0);
    if(callIocsh) {
        seqRegisterSequencerCommands();
        iocsh(0);
    } else {
        epicsThreadExitMain();
    }
    return(0);
}
