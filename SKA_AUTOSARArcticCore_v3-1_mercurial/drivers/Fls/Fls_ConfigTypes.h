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

#ifndef FLS_CONFIGTYPES_H_
#define FLS_CONFIGTYPES_H_


#if (USE_FLS_INFO==STD_ON)

typedef struct Flash {
    uint32 size;
    uint32 sectCnt;
    uint32 bankSize;
    uint32 regBase;
    uint32 sectAddr[FLASH_MAX_SECTORS+1];
    uint16 addrSpace[FLASH_MAX_SECTORS+1];
} FlashType;


#else
typedef struct {
  Fls_LengthType FlsNumberOfSectors;
  Fls_LengthType FlsPageSize;
  Fls_LengthType FlsSectorSize;
  Fls_AddressType FlsSectorStartaddress;
} Fls_SectorType;
#endif


struct Flash;

typedef struct {
    void (*FlsAcErase)(void);					/* NO SUPPORT */
    void (*FlsAcWrite)(void);					/* NO SUPPORT */
    // FlsCallCycle N/A in core.
    void (*FlsJobEndNotification)(void);
    void (*FlsJobErrorNotification)(void);
    uint32 FlsMaxReadFastMode;
    uint32 FlsMaxReadNormalMode;
    uint32 FlsMaxWriteFastMode;
    uint32 FlsMaxWriteNormalMode;
    uint32 FlsProtection;					/* NO SUPPORT */
#if (USE_FLS_INFO==STD_ON)
    const struct Flash *FlsInfo;
#else
    const Fls_SectorType *FlsSectorList;
    const uint32 FlsSectorListSize;			/* NO SUPPORT */
#endif
} Fls_ConfigSetType;

typedef Fls_ConfigSetType Fls_ConfigType;

extern const Fls_ConfigSetType FlsConfigSet[];


#endif /* FLS_CONFIGTYPES_H_ */
