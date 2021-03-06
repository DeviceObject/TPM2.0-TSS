#include <stdio.h>
#define LOGMODULE test
#include "log/log.h"
#include "test.h"
#include "sapi/tpm20.h"

/*
 * This program contains integration test for SAPI Tss2_Sys_SelfTest
 * that perform test of its capabilities. This program is calling  
 * SelfTest SAPI and make sure the response code are success
 * when fullTest set as YES and when it is set as NO.  
 */
int
test_invoke (TSS2_SYS_CONTEXT *sapi_context)
{
    TSS2_RC rc;
    LOG_INFO( "SelfTest tests started." );
    rc = Tss2_Sys_SelfTest( sapi_context, 0, YES, 0);
    if (rc != TSS2_RC_SUCCESS) {
        LOG_ERROR("SelfTest FAILED! Response Code : 0x%x", rc);
        exit(1);
    }
    rc = Tss2_Sys_SelfTest( sapi_context, 0, NO, 0);
    if (rc != TSS2_RC_SUCCESS) {
        LOG_ERROR("SelfTest FAILED! Response Code : 0x%x", rc);
        exit(1);
    }
    rc = Tss2_Sys_SelfTest(sapi_context, 0, YES, 0);
    if (rc != TSS2_RC_SUCCESS) {
        LOG_ERROR("SelfTest FAILED! Response Code : 0x%x", rc);
        exit(1);
    }
    LOG_INFO("SelfTest tests passed.");
    return 0;
}
