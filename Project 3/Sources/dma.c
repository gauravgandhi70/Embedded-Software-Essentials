/*
 * dma.c
 *
 *  Created on: 26-Oct-2016
 *      Author: Admin
 */
#include"MKL25Z4.h"
#include"main.h"
#include"dma.h"
#include"profile.h"

dma_st memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length)
{
	// Clock Gate enabled fpr DMA and DMAMUX
	SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
	SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

	// Disable channel 0 before initializing
	DMAMUX0_CHCFG0 &= ~DMAMUX_CHCFG_ENBL_MASK;
	DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;

	// Give Source address

	DMA_SAR0 =  src;
	DMA_DAR0 =  dst;

	DMA_DSR_BCR0 |= length;
	DMA_DCR0 |= DMA_DCR_SINC_MASK;
	DMA_DCR0 |= DMA_DCR_SSIZE(1);
	DMA_DCR0 |= DMA_DCR_DINC_MASK;
	DMA_DCR0 |= DMA_DCR_DSIZE(1);

	DMA_DCR0 |= DMA_DCR_EINT_MASK;
	NVIC_EnableIRQ(DMA0_IRQn);
	__enable_irq;


	DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;

	DMA_DCR0 |= DMA_DCR_START_MASK;



}



void DMA0_IRQHandler()
{ 	uint32_t i= DMA_DSR_BCR0;
	if(DMA_DSR_BCR0 == DMA_DSR_BCR_DONE_MASK)
	{
				DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;
				LOG0("\n\rSUCCESSFUL");
	}
	else
	{
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;
			LOG0("\n\rFAILURE");
	}

	 pit_disable();
	 get_time();

}

