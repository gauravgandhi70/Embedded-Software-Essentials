#include<stdio.h>
#include<stdint.h>
#include "uart.h"
#include"circbuf.h"
#include"unittest.h"
#include"main.h"

state status;
cirbuf_t test_buffer;
int32_t count_pass=0;
int32_t count_fail=0;
teststate_t unittest_bufferfull() //unit test to test if the bufferfull
{
	int32_t count=0;
while(count==MAX_Length) // add data till the buffer is full
{
	status=add_data(&test_buffer,count);
	count++;
}
 if(status==buf_full) // check for buffer full
 return success;
 else 
 return failure;
}

teststate_t unittest_bufferempty() // unit test to test if bufferempty
{
	int32_t count=0;
while(count<MAX_Length) //remove data till buffer is empty
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
 status=buff_empty(&test_buffer); 
 if(status==buf_empty)//check for buffer empty
 return success;
 else
 return failure;
 
}

teststate_t unittest_additemwraparound() //unit test to check wrap around in add item
{
	state status;
	int32_t count=0;
 unittest_bufferfull();//get the buffer full
 count=read_data(&test_buffer);//read an item from the buffer
 status=add_data(&test_buffer,count);//add an item to the buffer
 if(status=add_success_with_wrap_around)//check if wraparound is a success
 return success;
 else
 return failure;
}

teststate_t unittest_additemandremoveitem() //unit test to add item and remove item at the same location
{
	uint8_t item=2,value=0;
	state test1, test2;
	test1=add_data(&test_buffer,item); //add data to the buffer
	value=read_data(&test_buffer);//remove data from the same location
	if(item==value)//check if read data and added data are same
	return success;
	else 
	return failure;
}

teststate_t unittest_currentitemsinadd() //unit test to check the current items in add
{
  int32_t count=0;
  while(count<MAX_Length)//add data till maximum length
{
	add_data(&test_buffer,count);
	count++;
}
     if(test_buffer.new_len==MAX_Length)//check if current items is max length
	return success;
	else
	return failure;	
}

teststate_t unittest_removeitemwraparound() //unit test to check wrap around in remove item
{
	int32_t count=0;
	int32_t value;
while(count<MAX_Length)//read data till its empty
{
	int8_t test_data[15];
	test_data[count]=read_data(&test_buffer);
	count++;
}
	add_data(&test_buffer,count);//add data to the buffer
	value=read_data(&test_buffer);//read data from the buffer
	if(count==value)//check if read value is same as added value
	return success;
	else
	return failure;
}

teststate_t unittest_currentitemsinremove()//unit test to check current items in remove
{
  int32_t count=0;
  while(count<MAX_Length)//read items till buffer empty
{
	read_data(&test_buffer);
	count++;
}
     if(test_buffer.new_len==0)//check if current items is zero
	return success;
	else
	return failure;	
}



void  unittest()
{ 
    
	teststate_t result1,result2,result3,result4,result5,result6;
	test_buffer.buff= initialize(&test_buffer);//initialisation of buffer memory
	test_buffer.head=test_buffer.data;
			 	test_buffer.tail=test_buffer.data;
			 	test_buffer.buff=test_buffer.data;
			 	test_buffer.new_len= 0;
result1=unittest_bufferfull();
if(result1==success)
{
	LOG0("CB UNIT TEST:1/7-<bufferfull> PASS\n\r"); //display pass if success else fail for test 1
	count_pass++;
}
else
{
	LOG0("CB UNIT TEST:1/7-<bufferfull> FAIL\n\r");
    count_fail++;
}
result2=unittest_bufferempty();
if(result2==success)
{
	LOG0("CB UNIT TEST:2/7-<bufferempty> PASS\n\r");//display pass if success else fail for test 2
	count_pass++;
	}
	else
	{
	LOG0("CB UNIT TEST:2/7-<bufferempty> FAIL\n\r");
	count_fail++;
}
result3=unittest_additemwraparound();
if(result3==success)
{	
    LOG0("CB UNIT TEST:3/7-<additemwraparound> PASS\n\r");//display pass if success else fail for test 3
	count_pass++;
	}
	else
	{
	LOG0("CB UNIT TEST:3/7-<additemwraparound> FAIL\n\r");
	count_fail++;
}
result4=unittest_currentitemsinadd();
if(result4==success)
	{
	LOG0("CB UNIT TEST:4/7-<currentitemsinadd> PASS\n\r");//display pass if success else fail for test 4
	count_pass++;
	}
	else
	{
	LOG0("CB UNIT TEST:4/7-<currentitemsinadd> FAIL\n\r");
	count_fail++;
}
result5=unittest_removeitemwraparound();
if(result5==success)
    {
	LOG0("CB UNIT TEST:5/7-<removeitemwraparound> PASS\n\r");//display pass if success else fail for test 5
	count_pass++;
	}
	else
	{
	LOG0("CB UNIT TEST:5/7-<removeitemwraparound> FAIL\n\r");
	count_fail++;
    }
result6=unittest_currentitemsinremove();
if(result6==success)
	{
	LOG0("CB UNIT TEST:6/7-<currentitemsinremove> PASS\n\r");//display pass if success else fail for test 6
	count_pass++;
    }
	else
    {
	LOG0("CB UNIT TEST:6/7-<currentitemsinremove> FAIL\n\r");
    count_fail++;	
	}
	initialize(&test_buffer);
	if(&test_buffer)
	{
	LOG0("CB UNIT TEST:7/7-<initialisation> PASS\n\r");//display pass if success else fail for test 7
	count_pass++;
	}
	else
	{
	LOG0("CB UNIT TEST:7/7-<initialisation> FAIL\n\r");
	count_fail++;
	}
	if(count_fail>0)
	{
		LOG0("CIRCBUFF UNIT TEST SUITE:FAIL\n\r");//display unit test suite of pass or fail
	}
	else
	LOG0("CIRCBUFF UNIT TEST SUITE:PASS\n\r");
	return 0;
		
}

