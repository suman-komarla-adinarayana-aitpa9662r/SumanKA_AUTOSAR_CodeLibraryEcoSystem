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

#include "Fls.h"
#include "flash.h"
#include <stdlib.h>


#if defined(CFG_SPC56XL70)
#define FLASH_REGS_BASE 0xC3F88000UL
    /* RWW between partitions*
     *
     * LOW   8*16KB + 2*64KB = 256KB
     * MID   2*128KB                    = 256KB
     * HIGH  6*256KB                   = 1536KB
     */

const FlashType flashInfo[] = {
    [0].sectCnt = 18,
    [0].bankSize = 0x200000,
    [0].regBase = FLASH_REGS_BASE,

    /* LOW */
    [0].sectAddr[0]     = 0,
    [0].addrSpace[0]    = ADDR_SPACE(0, ADDR_SPACE_LOW, 1 ),
    [0].sectAddr[1]     = 0x00004000,
    [0].addrSpace[1]    = ADDR_SPACE(1, ADDR_SPACE_LOW, 1 ),
    [0].sectAddr[2]     = 0x00008000,
    [0].addrSpace[2]    = ADDR_SPACE(2, ADDR_SPACE_LOW, 1 ),
    [0].sectAddr[3]     = 0x0000C000,
    [0].addrSpace[3]    = ADDR_SPACE(3, ADDR_SPACE_LOW, 1 ),
    [0].sectAddr[4]     = 0x00010000,
    [0].addrSpace[4]    = ADDR_SPACE(4, ADDR_SPACE_LOW, 2 ),
    [0].sectAddr[5]     = 0x00014000,
    [0].addrSpace[5]    = ADDR_SPACE(5, ADDR_SPACE_LOW, 2 ),
    [0].sectAddr[6]     = 0x00018000,
    [0].addrSpace[6]    = ADDR_SPACE(6, ADDR_SPACE_LOW, 2 ),
    [0].sectAddr[7]     = 0x0001C000,
    [0].addrSpace[7]    = ADDR_SPACE(7, ADDR_SPACE_LOW, 2 ),
    [0].sectAddr[8]     = 0x00020000,
    [0].addrSpace[8]    = ADDR_SPACE(8, ADDR_SPACE_LOW, 3 ),
    [0].sectAddr[9]     = 0x00030000,
    [0].addrSpace[9]    = ADDR_SPACE(9, ADDR_SPACE_LOW, 3 ),

    /* MID */
    [0].sectAddr[10]     = 0x00040000,
    [0].addrSpace[10]    = ADDR_SPACE(0, ADDR_SPACE_MID, 4 ),
    [0].sectAddr[11]     = 0x00060000,
    [0].addrSpace[11]    = ADDR_SPACE(1, ADDR_SPACE_MID, 4 ),

    /* HIGH */
    [0].sectAddr[12]     = 0x00080000,
    [0].addrSpace[12]    = ADDR_SPACE(0, ADDR_SPACE_HIGH, 5 ),
    [0].sectAddr[13]     = 0x000C0000,
    [0].addrSpace[13]    = ADDR_SPACE(1, ADDR_SPACE_HIGH, 5 ),
    [0].sectAddr[14]     = 0x00100000,
    [0].addrSpace[14]    = ADDR_SPACE(2, ADDR_SPACE_HIGH, 6 ),
    [0].sectAddr[15]     = 0x00140000,
    [0].addrSpace[15]    = ADDR_SPACE(3, ADDR_SPACE_HIGH, 6 ),
    [0].sectAddr[16]     = 0x00180000,
    [0].addrSpace[16]    = ADDR_SPACE(4, ADDR_SPACE_HIGH, 7 ),
    [0].sectAddr[17]     = 0x001C0000,
    [0].addrSpace[17]    = ADDR_SPACE(5, ADDR_SPACE_HIGH, 7 ),
    [0].sectAddr[18]     = 0x200000,  /* End, NOT a sector */
};
#else
#error CPU NOT supported
#endif


const Fls_ConfigType FlsConfigSet[]=
{
  {
#if ( FLS_AC_LOAD_ON_JOB_START == STD_ON)
    .FlsAcWrite = __FLS_ERASE_RAM__,
    .FlsAcErase = __FLS_WRITE_RAM__,
#else
    .FlsAcWrite = NULL,
    .FlsAcErase = NULL,
#endif
    .FlsJobEndNotification = NULL,
    .FlsJobErrorNotification = NULL,
    .FlsInfo = flashInfo,

    .FlsMaxReadFastMode = 16,
    .FlsMaxReadNormalMode = 16,
    .FlsMaxWriteFastMode = 32,
    .FlsMaxWriteNormalMode = 32,

//    .FlsSectorList = &fls_evbSectorList[0],
//    .FlsSectorListSize = sizeof(fls_evbSectorList)/sizeof(Fls_SectorType),
//    .FlsBlockToPartitionMap = Fls_BlockToPartitionMap,
  }
};
