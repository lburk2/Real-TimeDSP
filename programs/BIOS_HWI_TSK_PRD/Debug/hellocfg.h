/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT hello.cdb */

/*  Include Header Files  */
#include <std.h>
#include <prd.h>
#include <hst.h>
#include <swi.h>
#include <tsk.h>
#include <log.h>
#include <sem.h>
#include <mbx.h>
#include <sts.h>

#ifdef __cplusplus
extern "C" {
#endif

extern PRD_Obj PRDHeartBeat;
extern HST_Obj RTA_fromHost;
extern HST_Obj RTA_toHost;
extern SWI_Obj PRD_swi;
extern SWI_Obj KNL_swi;
extern TSK_Obj TSK_idle;
extern TSK_Obj TaskAudioProcessing;
extern TSK_Obj TSKUserInterface;
extern LOG_Obj LOG_system;
extern LOG_Obj trace;
extern SEM_Obj SEMI2C;
extern SEM_Obj SEMFilter;
extern MBX_Obj MBXAudio;
extern MBX_Obj MBXOutput;
extern STS_Obj IDL_busyObj;


#ifdef __cplusplus
}
#endif /* extern "C" */
