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


#include "PduR.h"

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#include "debug.h"

/* @req PDUR0764 */
#if (PDUR_ZERO_COST_OPERATION == STD_OFF) && (PDUR_J1939TP_SUPPORT == STD_ON)


// Autosar4 API

BufReq_ReturnType PduR_J1939TpCopyRxData(PduIdType id, PduInfoType* info, PduLengthType* bufferSizePtr) {
    return PduR_LoTpCopyRxData(id, info, bufferSizePtr, 0x14);
}

void PduR_J1939TpRxIndication(PduIdType id, NotifResultType result) {
    PduR_LoTpRxIndication(id, result, 0x15);
}

BufReq_ReturnType PduR_J1939TpStartOfReception(PduIdType id, PduInfoType*   info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr) {
    (void) *info; /* new in v4.1 of PduR*/
    return PduR_LoTpStartOfReception(id, TpSduLength, bufferSizePtr, 0x16);
/*lint -e818 used till v4.1 of PduR implemenation */
}

BufReq_ReturnType PduR_J1939TpCopyTxData(PduIdType id, PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr ) {
    return PduR_LoTpCopyTxData(id, info, retry, availableDataPtr, 0x17);
}

void PduR_J1939TpTxConfirmation(PduIdType id, NotifResultType result) {
    PduR_ARC_TpTxConfirmation(id, result, 0x18);
}

#endif
