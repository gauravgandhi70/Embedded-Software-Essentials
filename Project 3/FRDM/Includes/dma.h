/*
 * dma.h
 *
 *  Created on: 26-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_

typedef enum{dma_success, config_error}dma_st;
dma_st memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length);
void memzero_dma(uint8_t *src, uint32_t length);
void DMA0_IRQHandler();



#endif /* INCLUDES_DMA_H_ */
