/*
 * circbuf.c

 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"circbuf.h"
uint8_t* initialize(cirbuf_t *cb)
{
	cb->data = (uint8_t *)malloc(MAX_LEN);
	cb=malloc(sizeof(cirbuf_t));
    return cb->buff;
}

void destroy(cirbuf_t *cb)
{
	free(cb);
}


state buff_full(cirbuf_t *cb)  // Function checks if the buffer is full or not
{
    if (cb->new_len == MAX_LEN)
    {   // If the head is at the end of the buffer and tail is at the start then buffer is full
        //or if head is one position behind the tail then also buffer is full
        return buf_full;
    }
    else
    {
        return buf_not_full;
    }

}

state buff_empty(cirbuf_t *cb)
{
    // if head and tail of the buffer are at the same position then that means buffer is empty.
    if(cb->new_len==0)
    {
        return buf_empty;
    }
    else
    {
        return buf_not_empty;
    }
}

state add_data(cirbuf_t *cb, uint8_t item)
{
    state error_code;
    error_code=buff_full(cb);  // before adding new item it checks if buffer is full or not
    if(error_code==buf_not_full)
    {
        if(cb->head==(cb->buff)+(MAX_LEN)-1)
        {// if head is at the last position of the buffer then add the item there
         //and then put head at the base address of the buffer
          cb->head=cb->buff;
        *(cb->head)=item;
        (cb->new_len)++;
        return add_success;
        }

        else
        {// otherwise add the item at the location of head and then head++
            cb->head++;
            *(cb->head)=item;
            (cb->new_len)++;
            return add_success;

        }


    }
    else if(error_code==buf_full)
    { // If buffer is full , do not add item and return error
      return buf_full;
    }
}

uint8_t read_data(cirbuf_t *cb)
{
    state error_code;
	uint8_t rd;
    error_code=buff_empty(cb);  // check for buffer empty before removing item
    if(error_code==buf_not_empty)
    {

        if(cb->tail==((cb->buff)+(MAX_LEN))-1)
        {  // if tail is at the last position of the buffer then remove the item there
         //and then put tail at the base address of the buffer

        cb->tail=cb->buff;
		rd=*(cb->tail);
        *(cb->tail)=0;
        (cb->new_len)--;
        return rd;
        }

        else
        {  // otherwise remove the item at the location of tail and then do tail++
            (cb->tail)++;
			rd=*(cb->tail);
            *(cb->tail)=0;
            (cb->new_len)--;
            return rd;

        }
    }
    else if(error_code==buf_empty)
    { // If buffer is empty , do not remove item and return error
      return buf_empty;
    }
}

