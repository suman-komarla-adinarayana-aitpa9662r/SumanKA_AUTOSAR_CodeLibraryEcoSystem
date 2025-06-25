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

#include "Dma.h"

const Dma_MuxConfigType DmaMuxConfig [DMA_NUMBER_OF_CHANNELS] =
{
    [DMA_START_CHANNEL] = {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_0_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_0_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_1_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_1_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_2_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_2_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_3_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_3_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_4_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_4_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_5_TX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_DSPI_5_RX
    },
    {
        .DMA_CHANNEL_ENABLE = 1, .DMA_CHANNEL_TRIG_ENABLE = 0, .DMA_CHANNEL_SOURCE = DMA_ADC0
    }
};

const Dma_ChannelConfigType DmaChannelConfig [DMA_NUMBER_OF_CHANNELS] =
{
    [DMA_START_CHANNEL] = {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_A_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_A_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_B_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_B_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_C_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_C_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_D_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_D_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_E_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_E_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_F_COMMAND_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },
    {
        .DMA_CHANNEL_PRIORITY = DMA_DSPI_F_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    },

    {
    .DMA_CHANNEL_PRIORITY = DMA_ADC_GROUP0_RESULT_CHANNEL, .DMA_CHANNEL_PREEMTION_ENABLE = 1
    }
};


const Dma_ConfigType DmaConfig []=
{
  {
#if defined(CFG_DMA_MUX)
    DmaMuxConfig,
#endif
    .dmaChannelConfigPtr = DmaChannelConfig,
    .dmaChannelArbitration = DMA_FIXED_PRIORITY_ARBITRATION
  }
};


