
#include "util.h"
#include "comdef.h"
//#include "stdio.h"
#include "encoding.h"

//unsigned int funcpll_432 = 0;
//unsigned int osc_clk = 0;

/*===========================================================================
FUNCTION:  sys_memcpy

DESCRIPTION:
	 copy one block memory to another position

INPUT PARAMETER:
	void *p_des:	destination address
	const void * p_src: source address
	unsigned long size: length of memory to copy (unit is byte)

OUTPUT PARAMETER:

RETURN VALUE:
===========================================================================*/
extern unsigned int test_flag;
void * sys_memcpy(void *p_des,const void * p_src,unsigned long size)
{
	char *tmp = p_des;
	const char *s = p_src;

	while (size--)
		*tmp++ = *s++;

	return p_des;
}
 int sys_memcmp(const void * cs,const void * ct,unsigned int count)
{
	const unsigned char *su1, *su2;
	int res = 0;

	for( su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}
void * _memcpy(void * dest,const void *src,unsigned int count)
{
	char *tmp = (char *) dest;
	const char *s = (char *) src;

	while (count--)
		*tmp++ = *s++;
	return dest;
}
/*===========================================================================
FUNCTION:  sys_memcpy_32

DESCRIPTION:
	 copy one block memory to another position
	 caller guarantee the src/des address are DWORD allign

INPUT PARAMETER:
	void *p_des:	destination address
	const void * p_src: source address
	unsigned long size: length of memory to copy (unit is DWORD)

OUTPUT PARAMETER:

RETURN VALUE:
===========================================================================*/
void sys_memcpy_32(void *p_des,const void * p_src,unsigned long size)
{
	unsigned long i;
	for (i=0;i<size;i++)
		*((unsigned long*)p_des+i) = *((unsigned long*)p_src+i);
}

/*===========================================================================
FUNCTION:  sys_memset

DESCRIPTION:
	 fill memory with specifed value

INPUT PARAMETER:
	void *p_des:	destination address
	int c:	value to set
	unsigned long size: length of memory

OUTPUT PARAMETER:

RETURN VALUE:
===========================================================================*/
void sys_memset(void *p_des,unsigned char c,unsigned long size)
{
	unsigned long i;
	for (i=0;i<size;i++)
		*((char*)p_des+i) = c;
}

/*===========================================================================
FUNCTION:  sys_memset32

DESCRIPTION:
	 fill memory with specifed value

INPUT PARAMETER:
	void *p_des:	destination address
	int c:	value to set
	unsigned long size: length of memory in word(32bit)

OUTPUT PARAMETER:

RETURN VALUE:
===========================================================================*/
void sys_memset32(void *p_des,int c,unsigned long size)
{
	unsigned long i;
	for(i=0; i< size; i++)
		((unsigned long*)p_des)[i] = c;
}

