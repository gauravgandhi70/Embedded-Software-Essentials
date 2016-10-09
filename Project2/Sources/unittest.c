#include<stdio.h>
#include<stdint.h>
#include "uart.h"
#include"circbuf.h"
#include"unittest.h"



teststate_t unittest_bufferfull()
{
	int32_t count=0;
while(count==MAX_Length)
{
	status=add_data(&test_buffer,count);
	count++;
}
 if(status==buf_full)
 return success;
 else 
 return failure;
}

teststate_t unittest_bufferempty()
{
	int32_t count=0;
while(count<MAX_Length)
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
 status=buff_empty(&test_buffer);
 if(status==buf_empty)
 return success;
 else
 return failure;
 
}

teststate_t unittest_additemwraparound()
{
	state status;
	int32_t count=0;
 unittest_bufferfull();
 count=read_data(&test_buffer);
 status=add_data(&test_buffer,count);
 if(status=add_success_with_wrap_around)
 return success;
 else
 return failure;
}

teststate_t unittest_additemandremoveitem()
{
	uint8_t item=2,value=0;
	state test1, test2;
	test1=add_data(&test_buffer,item);
	value=read_data(&test_buffer);
	if(item==value)
	return success;
	else 
	return failure;
}

teststate_t unittest_currentitemsinadd()
{
  int32_t count=0;
  while(count<MAX_Length)
{
	add_data(&test_buffer,count);
	count++;
}
     if(test_buffer.new_len==MAX_Length)
	return success;
	else
	return failure;	
}

teststate_t unittest_removeitemwraparound()
{
	int32_t count=0;
	int32_t value;
while(count<MAX_Length)
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
	add_data(&test_buffer,count);
	value=read_data(&test_buffer);
	if(count==value)
	return success;
	else
	return failure;
}

teststate_t unittest_currentitemsinremove()
{
  int32_t count=0;
  while(count<MAX_Length)
{
	read_data(&test_buffer);
	count++;
}
     if(test_buffer.new_len==0)
	return success;
	else
	return failure;	
}



void unittest_init()
{ 
    state status;
    cirbuf_t test_buffer;
	teststate_t result1,result2,result3,result4,result5,result6;
	test_buffer.buff= initialize(&test_buffer);
	test_buffer.head=test_buffer.data;
			 	test_buffer.tail=test_buffer.data;
			 	test_buffer.buff=test_buffer.data;
			 	test_buffer.length=MAX_Length;
			 	test_buffer.new_len= 0;
result1=unittest_bufferfull();
if(result1==success)
	 printf("CB UNIT TEST:1/7-<bufferfull> PASS\n");
else
printf("CB UNIT TEST:1/7-<bufferfull> FAIL\n"); 
result2=unittest_bufferempty();
if(result2==success)
	printf("CB UNIT TEST:2/7-<bufferempty> PASS\n");
	else
	printf("CB UNIT TEST:2/7-<bufferfull> FAIL\n");
result3=unittest_additemwraparound();
if(result3==success)
	printf("CB UNIT TEST:3/7-<additemwraparound> PASS\n");
	else
	printf("CB UNIT TEST:3/7-<bufferfull> FAIL\n");
result4=unittest_currentitemsinadd();
if(result4==success)
	printf("CB UNIT TEST:4/7-<currentitemsinadd> PASS\n");
	else
	printf("CB UNIT TEST:4/7-<bufferfull> FAIL\n");
result5=unittest_removeitemwraparound();
if(result5==success)
	printf("CB UNIT TEST:5/7-<removeitemwraparound> PASS\n");
	else
	printf("CB UNIT TEST:5/7-<bufferfull> FAIL\n");
result6=unittest_currentitemsinremove();
if(result6==success)
	printf("CB UNIT TEST:6/7-<currentitemsinremove> PASS\n");
	else
	printf("CB UNIT TEST:6/7-<bufferfull> FAIL\n");
	initialize(&test_buffer);
	if(&test_buffer)
	printf("CB UNIT TEST:7/7-<initialisation> PASS\n");
	else
	printf("CB UNIT TEST:7/7-<initialisation> FAIL\n");
	return 0;
		
}

