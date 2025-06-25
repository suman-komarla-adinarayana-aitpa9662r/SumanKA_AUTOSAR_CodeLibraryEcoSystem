/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

/* A steal in an idea from
 * http://blogs.sun.com/nickstephen/entry/some_assembly_required_-_down
 * According to blog original BSD license..
 *
 * Generate assembler from this file( -S option for GNU ).
 * extract the "#defines" with some tool e.g. "sed -n '/#define/p' <asm_file>"
 */

#define restrict

#include "os_i.h"

#if defined(__GNUC__) || defined(__ghs__)

/* For ARM this will generate to #define APA #12 */
#define DECLARE(sym,val) \
    __asm("#define\t" #sym "\t%0" : : "n" ((val)))
void  asm_foo(void) {
#elif defined(__CWCC__)
#define DECLARE(_var,_offset) \
    __declspec(section ".apa") char_t _var[100+ (_offset)]
#pragma section ".apa" ".apa"
#elif (defined(__DCC__)) || defined(__ARMCC_VERSION)
#define DECLARE(_sym,_val) \
    const sint32 arc_dummy_ ## _sym = _val
#else
#define DECLARE(_sym,_val) const sint32 arc_dummy_ ## _sym = _val
#endif

    DECLARE(PCB_STACK_CURR_P,	offsetof(OsTaskVarType, stack));
    DECLARE(PCB_CONST_P,		offsetof(OsTaskVarType, constPtr));
    DECLARE(PCB_REGS,			offsetof(OsTaskVarType, regs));
    DECLARE(SYS_CURR_PCB_P,		offsetof(Os_SysType, currTaskPtr));
    DECLARE(SYS_INT_NEST_CNT, offsetof(Os_SysType, intNestCnt));
    DECLARE(SYS_INT_STACK, offsetof(Os_SysType, intStack));
    DECLARE(SYS_SIZE, sizeof(Os_SysType));
#if (OS_SC3 == STD_ON ) || (OS_SC4 == STD_ON )
    DECLARE(APP_INT_NEST_CNT,       offsetof(OsAppVarType, nestCnt));
    DECLARE(APP_INT_STACK,          offsetof(OsAppVarType, intStack));
    DECLARE(APP_SAVED_INT_STACK,    offsetof(OsAppVarType, savedIntStack));
#endif
#if defined(__GNUC__) || defined(__ghs__)
}
#endif


