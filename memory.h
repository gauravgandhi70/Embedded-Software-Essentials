#ifndef _HW1_H
#define _HW1_H
#define copying_LOOP(start,endpoint,original_data,copy_dest)    \
while(start<endpoint)                                           \
{                                                               \
    *(copy_dest+start)=*(original_data+start);                  \
    start++;                                                    \
}
int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);

#endif
