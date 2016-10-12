/*
 * prof_test.c
 *
 *  Created on: 12-Oct-2016
 *      Author: Admin
 */

#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"led.h"
#include"data.h"
#include"log.h"
#include"memory.h"
#include"main.h"
#include"profile.h"
#include<stdlib.h>


void timetest()
{
	uint8_t src[100]="ABCDEFGHIJKLMNOPQRSNFDLKNBFNBSDJBND",dst[100];

	LOG0("RESOLUTION IS OF 1 microseconds ");
	LOG0("\n\n\r");

	//Test case for profiling the memmove with variable byte length

	LOG0("MEMMOVE 100  bytes : ");
		pit_enable();
		memmove(dst,src,100);
		pit_disable();
		get_time();



		//Test case profiling for the my_memmove with variable byte length
		LOG0("\n\n\r");

		LOG0("MY_MEMMOVE 100  bytes : ");
		pit_enable();
		my_memmove(src,dst,100);
		pit_disable();
		get_time();

		LOG0("\n\n\r");

		//Test case profiling for the memset with variable byte length
	LOG0("MEMSET 100  bytes : ");
			pit_enable();
			memset(src,0,100);
			pit_disable();
			get_time();




			//Test case for profiling the my_memzero with variable byte length
			LOG0("\n\n\r");

			LOG0("MY_MEMZERO 100  bytes : ");
			pit_enable();
			my_memzero(src,100);
			pit_disable();
			get_time();

			LOG0("\n\n\r");

			//Test case for profiling the reverse function with variable byte length
	LOG0("reverse 100  bytes : ");
				pit_enable();
				my_reverse(src,100);
				pit_disable();
				get_time();


				LOG0("\n\n\r");

	uint8_t str[10]="123456" ;

	//Test case for profiling the my_atoi function with variable byte length
	LOG0("my_atoi for uint32_t 123456 : ");
					pit_enable();
					my_atoi(str);
					pit_disable();
					get_time();


					LOG0("\n\n\r");

	//Test case for profiling the my_atoi function with variable byte length
	LOG0("my_ftoa for 1543.456 : ");
						pit_enable();
						ftoa(1543.456, dst, 3);
						pit_disable();
						get_time();


						LOG0("\n\n\r");

	//Test case for profiling the itoa function with variable byte length

	LOG0("my_itoa for   uint32_t 321435: ");
						pit_enable();
						itoa(321435, dst, 10)  ;
						pit_disable();
						get_time();


						LOG0("\n\n\r");

	//Test case for profiling the malloc function with variable byte length
			uint8_t *a;
	LOG0("malloc 10 bytes ");
							pit_enable();
							a=(uint8_t *)malloc(10);
							pit_disable();
							get_time();


							LOG0("\n\n\r");
							free(a);

		LOG0("malloc 100 bytes ");
							pit_enable();
							a=(uint8_t *)malloc(100);
							pit_disable();
							get_time();

							LOG0("\n\n\r");
							free(a);


		LOG0("malloc 500 bytes ");
							pit_enable();
							a=(uint8_t *)malloc(500);
							pit_disable();
							get_time();

							LOG0("\n\n\r");
							free(a);

		LOG0("malloc 1000 bytes ");
							pit_enable();
							a=(uint8_t *)malloc(1000);
							pit_disable();
							get_time();

							LOG0("\n\n\r");

		LOG0("free command \t");
							pit_enable();
							free(a);
							pit_disable();
							get_time();
							LOG0("\n\n\r");

		// Circular buffer functions profiling
		cirbuf_t b;
		b.buff = initialize(&b);
		b.head=b.data;
				 	b.tail=b.data;
				 	b.buff=b.data;
				 	b.new_len= 0;

		LOG0("Circbuf Add Item : \t");
					pit_enable();
					add_data(&b,'a');
					pit_disable();
					get_time();
					LOG0("\n\n\r");

	     LOG0("Circbuf remove Item : \t");
					pit_enable();
					read_data(&b);
					pit_disable();
					get_time();
					LOG0("\n\n\r");

		// LOG functions profiling

	LOG0("LOG0 Function : \t");
						pit_enable();
						LOG0(" ");
						pit_disable();
						get_time();
						LOG0("\n\n\r");

	LOG0("LOG1 Function : \t");
						pit_enable();
						uint32_t para = 123456;
						LOG1("ABC ",&para);
						pit_disable();
						LOG0(": \t");
						get_time();
						LOG0("\n\n\r");









}

