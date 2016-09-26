#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"circbuf.h"



state buff_full(cirbuf_t *cb)  // Function checks if the buffer is full or not
{
    if ((cb->head==((cb->buff+cb->length)) & cb->buff==cb->tail )|| (cb->tail - cb->head)==1 )
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
    if(cb->head==cb->tail)
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
        if(cb->head==(cb->buff)+(cb->length))
        {// if head is at the last position of the buffer then add the item there
         //and then put head at the base address of the buffer
        cb->head=cb->buff;
        *(cb->head)=item;
        return add_success;
        }

        else
        {// otherwise add the item at the location of head and then head++
            *(cb->head)=item;
            cb->head++;
            return add_success;

        }


    }
    else if(error_code==buf_full)
    { // If buffer is full , do not add item and return error
      return buf_full;
    }
}

state remove_data(cirbuf_t *cb)
{
    state error_code;
    error_code=buff_empty(cb);  // check for buffer empty before removing item
    if(error_code==buf_not_empty)
    {

        if(cb->tail==((cb->buff)+(cb->length)))
        {  // if tail is at the last position of the buffer then remove the item there
         //and then put tail at the base address of the buffer
        *(cb->tail)=0;
        cb->tail=cb->buff;
        return remove_success;
        }

        else
        {  // otherwise remove the item at the location of tail and then do tail++
            *(cb->tail)=0;
            cb->tail++;
            return remove_success;

        }
    }
    else if(error_code==buf_empty)
    { // If buffer is empty , do not remove item and return error
      return buf_empty;
    }
}

