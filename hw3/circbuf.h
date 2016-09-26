#ifndef _HEAD_
#define _HEAD
#endif
#define MAX_LEN 3
typedef struct
{
    uint32_t length;
    uint8_t data[MAX_LEN];   // buffer structure; containing head tail and base address of the buffer
    uint8_t *buff;
    uint8_t *head;
    uint8_t *tail;

}cirbuf_t;

typedef enum {buf_full , buf_empty, buf_not_full, buf_not_empty, add_success, remove_success} state;
state buff_full(cirbuf_t *cb);
state buff_empty(cirbuf_t *cb);
state add_data(cirbuf_t *cb, uint8_t item);
state remove_data(cirbuf_t *cb);

