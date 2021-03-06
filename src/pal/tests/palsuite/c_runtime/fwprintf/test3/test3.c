//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*============================================================================
**
** Source:      test3.c
**
** Purpose:     Tests the wide string specifier (%S).
**              This test is modeled after the sprintf series.
**
**
**==========================================================================*/

#include <palsuite.h>
#include "../fwprintf.h"

/* 
 * Depends on memcmp, strlen, fopen, fseek and fgets.
 */

int __cdecl main(int argc, char *argv[])
{
    if (PAL_Initialize(argc, argv) != 0)
    {
        return(FAIL);
    }
    
    DoStrTest(convert("foo %S"), "bar", "foo bar");
    DoStrTest(convert("foo %hS"), "bar", "foo bar");
    DoWStrTest(convert("foo %lS"), convert("bar"), "foo bar");
    DoWStrTest(convert("foo %wS"), convert("bar"), "foo bar");
    DoStrTest(convert("foo %LS"), "bar", "foo bar");
    DoStrTest(convert("foo %I64S"), "bar", "foo bar");
    DoStrTest(convert("foo %5S"), "bar", "foo   bar");
    DoStrTest(convert("foo %.2S"), "bar", "foo ba");
    DoStrTest(convert("foo %5.2S"),"bar", "foo    ba");
    DoStrTest(convert("foo %-5S"), "bar", "foo bar  ");
    DoStrTest(convert("foo %05S"), "bar", "foo 00bar");

    PAL_Terminate();
    return PASS;
}


