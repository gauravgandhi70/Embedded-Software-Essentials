/*
 * circbuf.h
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_CIRCBUF_H_
#define INCLUDES_CIRCBUF_H_

#define MAX_LEN 100
typedef struct
{
    uint32_t length;
    uint8_t data[MAX_LEN];   // buffer structure; containing head tail and base address of the buffer
    uint8_t *buff;
    uint8_t *head;
    uint8_t *tail;
    uint32_t new_len;

}cirbuf_t;

typedef enum {buf_full , buf_empty, buf_not_full, buf_not_empty, add_success, remove_success} state;
state buff_full(cirbuf_t *cb);
state buff_empty(cirbuf_t *cb);
state add_data(cirbuf_t *cb, uint8_t item);
uint8_t read_data(cirbuf_t *cb);
uint8_t* initialize(cirbuf_t *cb);
void destroy(cirbuf_t *cb);


#endif /* INCLUDES_CIRCBUF_H_ */
