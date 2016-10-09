
#ifndef INCLUDES_UNITTEST_H_
#define INCLUDES_UNITTEST_H_
#define MAX_Length 10

typedef enum
{
success,
failure}teststate_t;

teststate_t unittest_bufferfull();
teststate_t unittest_bufferempty();
teststate_t unittest_additemwraparound();
teststate_t unittest_additemandremoveitem();
teststate_t unittest_currentitemsinadd();
teststate_t unittest_removeitemwraparound();
teststate_t unittest_currentitemsinremove();
