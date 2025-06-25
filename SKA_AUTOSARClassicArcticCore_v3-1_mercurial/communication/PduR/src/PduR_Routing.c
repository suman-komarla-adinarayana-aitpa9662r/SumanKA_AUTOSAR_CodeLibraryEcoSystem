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

#if defined(USE_DEM)
#include "Dem.h"
#endif


#if PDUR_CANIF_SUPPORT == STD_ON
#include "CanIf.h"
#endif
#if PDUR_CANNM_SUPPORT == STD_ON
#include "CanNm.h"
#endif
#if PDUR_UDPNM_SUPPORT == STD_ON
#include "UdpNm.h"
#endif
#if PDUR_CANTP_SUPPORT == STD_ON
#include "CanTp.h"
#endif
#if PDUR_LINIF_SUPPORT == STD_ON
#include "LinIf.h"
#endif
#if PDUR_COM_SUPPORT == STD_ON
#include "Com.h"
#endif
#if PDUR_DCM_SUPPORT == STD_ON
#include "Dcm.h"
#endif
#if PDUR_SOAD_SUPPORT == STD_ON
#include "SoAd.h"
#endif
#if PDUR_DOIP_SUPPORT == STD_ON
#include "DoIP.h"
#endif
#if PDUR_J1939TP_SUPPORT == STD_ON
#include "J1939Tp.h"
#endif
#if PDUR_IPDUM_SUPPORT == STD_ON
#include "IpduM.h"
#include "IpduM_Cbk.h"
#endif
#if PDUR_FRIF_SUPPORT == STD_ON
#include "FrIf.h"
#endif
#if PDUR_FRNM_SUPPORT == STD_ON
#include "FrNm.h"
#endif
#if PDUR_FRTP_SUPPORT == STD_ON
#include "FrTp.h"
#endif
#if PDUR_SECOC_SUPPORT == STD_ON
#include "SecOC.h"
#endif
#if PDUR_CDDPDUR_SUPPORT == STD_ON
#include "CddPduR_Cbk.h"
#endif
#if PDUR_LDCOM_SUPPORT == STD_ON
#include "LdCom.h"
#endif

#if PDUR_ZERO_COST_OPERATION == STD_OFF

PduRRouteStatusType PduR_ARC_RouteTransmit(const PduRDestPdu_type * destination, const PduInfoType * pduInfo) {

    /* @req PDUR160 */
    /* @req PDUR629 */
    /* @req PDUR0745 */
    /* @req PDUR625 */
    /* @req PDUR423 *//* Dem_ReportError N/A since PduR has no production errors */

    PduRRouteStatusType ret = PDUR_E_DISABLED;
    Std_ReturnType retVal = E_NOT_OK;
    if( (TRUE==PduRRoutingPathEnabled(destination)) || (ARC_PDUR_COM == destination->DestModule) ) {
        ret = PDUR_E_REJECTED;
        switch (destination->DestModule) {
            case ARC_PDUR_CANIF:
#if PDUR_CANIF_SUPPORT == STD_ON
                retVal = CanIf_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_CANNM:
#if PDUR_CANNM_SUPPORT == STD_ON
                retVal = CanNm_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_UDPNM:
#if PDUR_UDPNM_SUPPORT == STD_ON
                retVal = UdpNm_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_LINIF:
#if PDUR_LINIF_SUPPORT == STD_ON
                retVal = LinIf_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_CANTP:
#if PDUR_CANTP_SUPPORT == STD_ON
                retVal = CanTp_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_SOADIF:
#if PDUR_SOAD_SUPPORT == STD_ON
                retVal = SoAd_IfTransmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_SOADTP:
#if PDUR_SOAD_SUPPORT == STD_ON
                retVal = SoAd_TpTransmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_DOIPIF:
#if PDUR_DOIP_SUPPORT == STD_ON
                retVal = DoIP_IfTransmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_DOIPTP:
#if PDUR_DOIP_SUPPORT == STD_ON
                retVal = DoIP_TpTransmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_J1939TP:
#if PDUR_J1939TP_SUPPORT == STD_ON
                retVal = J1939Tp_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_IPDUM:
#if PDUR_IPDUM_SUPPORT == STD_ON
                retVal = IpduM_Transmit(destination->DestPduId, pduInfo);
#endif
                break;
            case ARC_PDUR_FRIF:
#if PDUR_FRIF_SUPPORT == STD_ON
                retVal = FrIf_Transmit(destination->DestPduId, pduInfo);
#endif
            break;
        case ARC_PDUR_FRNM:
#if PDUR_FRNM_SUPPORT == STD_ON
            retVal = FrNm_Transmit(destination->DestPduId, pduInfo);
#endif
            break;
        case ARC_PDUR_FRTP:
#if PDUR_FRTP_SUPPORT == STD_ON
                retVal = FrTp_Transmit(destination->DestPduId, pduInfo);
#endif
            break;
        case ARC_PDUR_SECOC:
#if PDUR_SECOC_SUPPORT == STD_ON
            retVal = SecOC_Transmit(destination->DestPduId, pduInfo);
#endif
            break;
        default:
            retVal = E_NOT_OK;
            break;
        }
        if(E_OK == retVal) {
            ret = PDUR_E_OK;
        }
    }

    return ret;
}

void PduR_ARC_RouteRxIndication(const PduRDestPdu_type * destination, const PduInfoType *PduInfo) {

    switch (destination->DestModule) {
    case ARC_PDUR_COM:
#if PDUR_COM_SUPPORT == STD_ON
        /*lint -e{929} -e{9005} attempt to cast away const -Com_RxIndication() is ASR api and cast becomes necessary to match the prototype */
        Com_RxIndication(destination->DestPduId, (PduInfoType *)PduInfo);
#endif
        break;
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        Dcm_TpRxIndication(destination->DestPduId, *PduInfo->SduDataPtr);
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        /*lint -e{929} -e{9005} attempt to cast away const -Com_RxIndication() is ASR api and cast becomes necessary to match the prototype */
        LdCom_RxIndication(destination->DestPduId, (PduInfoType *)PduInfo);
#endif
        break;
    case ARC_PDUR_IPDUM:
#if PDUR_IPDUM_SUPPORT == STD_ON
        /*lint -e{929} -e{9005} attempt to cast away const -Com_RxIndication() is ASR api and cast becomes necessary to match the prototype */
        IpduM_RxIndication(destination->DestPduId, (PduInfoType *)PduInfo);
#endif
        break;
#if PDUR_CDDPDUR_SUPPORT == STD_ON
    case ARC_PDUR_CDDPDUR:
        /*lint -e{929} -e{9005} attempt to cast away const -Com_RxIndication() is ASR api and cast becomes necessary to match the prototype */
        CddPduR_RxIndication(destination->DestPduId, (PduInfoType *)PduInfo);
        break;
#endif
#if PDUR_SECOC_SUPPORT == STD_ON
    case ARC_PDUR_SECOC:
        SecOC_RxIndication(destination->DestPduId, PduInfo);
        break;
#endif
    default:
        break;
    }
}


void PduR_ARC_RouteTpRxIndication(const PduRDestPdu_type * destination, Std_ReturnType result ) {
    /* @req PDUR207 */
    /* @req PDUR429 */
    switch (destination->DestModule) {
    case ARC_PDUR_COM:
#if PDUR_COM_SUPPORT == STD_ON
        Com_TpRxIndication(destination->DestPduId, result);
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        LdCom_TpRxIndication(destination->DestPduId, result);
#endif
        break;
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        Dcm_TpRxIndication(destination->DestPduId, result );
#endif
        break;
#if PDUR_CDDPDUR_SUPPORT == STD_ON
    case ARC_PDUR_CDDPDUR:
        CddPduR_TpRxIndication(destination->DestPduId, result );
        break;
#endif
    default:
        break;
    }
}

void PduR_ARC_RouteTpTxConfirmation(const PduRRoutingPath_type *route, Std_ReturnType result) {
    /* @req PDUR301 */
    /* SrcModule is the initiator, ie calls PduR_<up>Transmit */
    switch (route->SrcModule) {
    case ARC_PDUR_COM:
#if PDUR_COM_SUPPORT == STD_ON
        Com_TpTxConfirmation(route->SrcPduId, result);
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        LdCom_TpTxConfirmation(route->SrcPduId, result);
#endif
        break;
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        Dcm_TpTxConfirmation(route->SrcPduId, result);
#else
        (void) result; /* Remove compiler warning */
#endif
        break;
#if PDUR_CDDPDUR_SUPPORT == STD_ON
        case ARC_PDUR_CDDPDUR:
        CddPduR_TpTxConfirmation(route->SrcPduId, result);
        break;
#endif
    default:
        break;
    }
}

void PduR_ARC_RouteTxConfirmation(const PduRRoutingPath_type *route, uint8 result) {
    /* @req PDUR627 */
    switch (route->SrcModule) {
        case ARC_PDUR_COM:
#if PDUR_COM_SUPPORT == STD_ON
            Com_TxConfirmation(route->SrcPduId);
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        LdCom_TxConfirmation(route->SrcPduId);
#endif
        break;
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
            Dcm_TpTxConfirmation(route->SrcPduId, result);
#else
        (void) result; /* Remove compiler warning */
#endif
            break;
        case ARC_PDUR_IPDUM:
#if PDUR_IPDUM_SUPPORT == STD_ON
            IpduM_TxConfirmation(route->SrcPduId);
#endif
            break;
#if PDUR_CDDPDUR_SUPPORT == STD_ON
        case ARC_PDUR_CDDPDUR:
            CddPduR_TxConfirmation(route->SrcPduId, result);
            break;
#endif
#if PDUR_SECOC_SUPPORT == STD_ON
        case ARC_PDUR_SECOC:
            SecOC_TxConfirmation(route->SrcPduId);
            break;
#endif
        default:
            break;
    }
}

Std_ReturnType PduR_ARC_RouteTriggerTransmit(const PduRRoutingPath_type *route, PduInfoType * pduInfo) {
    /* @req PDUR430 */
    Std_ReturnType retVal = E_NOT_OK;
    switch (route->SrcModule) {
    case ARC_PDUR_COM:
#if PDUR_COM_SUPPORT == STD_ON
        retVal = Com_TriggerTransmit(route->SrcPduId, pduInfo);
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        retVal = LdCom_TriggerTransmit(route->SrcPduId, pduInfo);
#endif
        break;
    case ARC_PDUR_IPDUM:
#if PDUR_IPDUM_SUPPORT == STD_ON
            retVal = IpduM_TriggerTransmit(route->SrcPduId, pduInfo);
#endif
            break;
        default:
            retVal = E_NOT_OK;
            break;
        }

    return retVal;
}

BufReq_ReturnType PduR_ARC_RouteCopyRxData(const PduRDestPdu_type * destination, PduInfoType* info, PduLengthType* bufferSizePtr) {
    /* @req PDUR428 */
    BufReq_ReturnType retVal = BUFREQ_NOT_OK;
    switch (destination->DestModule) {
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        retVal = Dcm_CopyRxData(destination->DestPduId, info, bufferSizePtr);
#else
        //lint -estring(920,pointer)  /* cast to void */
        (void)destination; /* Remove compiler warning */
        (void)info; /* Remove compiler warning */
        (void)bufferSizePtr; /* Remove compiler warning */
        //lint +estring(920,pointer)  /* cast to void */
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        retVal = LdCom_CopyRxData(destination->DestPduId, info, bufferSizePtr);
#endif
#if 0 // Not supported in current SecOC implementation
        case ARC_PDU_SECOC:
#if PDUR_SECOC_SUPPORT == STD_ON
            retVal = SecOC_CopyRxData(destination->DestPduId, info, bufferSizePtr);
#else
            //lint -estring(920,pointer)  /* cast to void */
            (void)destination; /* Remove compiler warning */
            (void)info; /* Remove compiler warning */
            (void)bufferSizePtr; /* Remove compiler warning */
            //lint +estring(920,pointer)  /* cast to void */
#endif
            break;
#endif
        break;
#if defined(USE_COM)
    case ARC_PDUR_COM:
        retVal = Com_CopyRxData(destination->DestPduId, info, bufferSizePtr);
        break;
#endif
#if PDUR_CDDPDUR_SUPPORT == STD_ON
    case ARC_PDUR_CDDPDUR:
        retVal = CddPduR_CopyRxData(destination->DestPduId, info, bufferSizePtr);
        break;
#endif
    default:
        break;
    }
    return retVal;
}
BufReq_ReturnType PduR_ARC_RouteCopyTxData(const PduRRoutingPath_type *route, PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr) {
    /* @req PDUR299 */
    BufReq_ReturnType retVal = BUFREQ_NOT_OK;
    switch (route->SrcModule) {
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        retVal = Dcm_CopyTxData(route->SrcPduId, info, retry, availableDataPtr);
#else
        //lint -estring(920,pointer)  /* cast to void */
        (void)info; /* Remove compiler warning*/
        (void)retry; /* Remove compiler warning  */
        (void)availableDataPtr; /* Remove compiler warning */
        //lint +estring(920,pointer)  /* cast to void */
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        retVal = LdCom_CopyTxData(route->SrcPduId, info, retry, availableDataPtr);
#endif
#if 0 // Not supported in current SecOC implementation
    case ARC_PDU_SECOC:
#if PDUR_SECOC_SUPPORT == STD_ON
        retVal = SecOC_CopyTxData(route->SrcPduId, info, retry, availableDataPtr);
#else
        //lint -estring(920,pointer)  /* cast to void */
        (void)info; /* Remove compiler warning*/
        (void)retry; /* Remove compiler warning  */
        (void)availableDataPtr; /* Remove compiler warning */
        //lint +estring(920,pointer)  /* cast to void */
#endif
        break;
#endif
        break;
#if defined(USE_COM)
    case ARC_PDUR_COM:
        retVal = Com_CopyTxData(route->SrcPduId, info, retry, availableDataPtr);
        break;
#endif
#if PDUR_CDDPDUR_SUPPORT == STD_ON
    case ARC_PDUR_CDDPDUR:
        retVal = CddPduR_CopyTxData(route->SrcPduId, info, retry, availableDataPtr);
        break;
#endif

        default:
            break;
    }
    return retVal;
}

BufReq_ReturnType PduR_ARC_RouteStartOfReception(const PduRDestPdu_type * destination, PduLengthType TpSduLength, PduLengthType* bufferSizePtr) {
    /* @req PDUR549 */
    BufReq_ReturnType retVal = BUFREQ_NOT_OK;
#if (PDUR_LDCOM_SUPPORT == STD_ON)
    uint8 temp; /* This is a temporary fix until we move all modules to 4.2.2 version. */
    /* Hope the upper layer does not require pduInfo, as it is not used in 4.0.3 */
    const PduInfoType pduInfo = { &temp, TpSduLength};
#endif
    switch (destination->DestModule) {
    case ARC_PDUR_DCM:
#if PDUR_DCM_SUPPORT == STD_ON
        retVal = Dcm_StartOfReception(destination->DestPduId, TpSduLength, bufferSizePtr);
#else
        //lint -estring(920,pointer)  /* cast to void */
        (void)TpSduLength; /* Remove compiler warning */
        (void)bufferSizePtr; /* Remove compiler warning */
        //lint +estring(920,pointer)  /* cast to void */
#endif
        break;
    case ARC_PDUR_LDCOM:
#if PDUR_LDCOM_SUPPORT == STD_ON
        retVal = LdCom_StartOfReception(destination->DestPduId, &pduInfo, TpSduLength, bufferSizePtr);
#endif
#if 0 // Not supported in current SecOC implementation
    case ARC_PDU_SECOC:
#if PDUR_SECOC_SUPPORT == STD_ON
        retVal = SecOC_StartOfReception(destination->DestPduId, NULL, TpSduLength, bufferSizePtr);
#else
        //lint -estring(920,pointer)  /* cast to void */
        (void)TpSduLength; /* Remove compiler warning */
        (void)bufferSizePtr; /* Remove compiler warning */
        //lint +estring(920,pointer)  /* cast to void */
#endif
            break;
#endif
        break;
#if defined(USE_COM)
    case ARC_PDUR_COM:
        retVal = Com_StartOfReception(destination->DestPduId, TpSduLength, bufferSizePtr);
        break;
#endif
#if PDUR_CDDPDUR_SUPPORT == STD_ON
    case ARC_PDUR_CDDPDUR:
        retVal = CddPduR_StartOfReception(destination->DestPduId, NULL, TpSduLength, bufferSizePtr);
        break;
#endif
    default:
        break;
    }
    return retVal;
}

#endif
