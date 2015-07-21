/*
5.18 ¡ô
Write a version of the inner product procedure described in Problem 5.15 that uses
four-way loop unrolling along with reassociation to enable greater parallelism.
Our measurements for this function give a CPE of 2.00 with x86-64 and 2.25 with
IA32 for all types of data.
*/

#include<stdio.h>


typedef int data_t;

typedef struct
{
	long int len;
	data_t *data;
}vec_rec, *vec_ptr;

#define IDENT 0
#define OP +

vec_ptr new_vec(long int len)
{
	vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
	if (!result)
	{
		return NULL;
	}
	result->len = len;

	if (len > 0)
	{
		data_t *data = (data_t *)calloc(len, sizeof(data_t));
		if (!data)
		{
			free((void*)result);
			return NULL;
		}
		result->data = data;

	}
	else
	{
		result->data = NULL;
	}
	return result;
}

int get_vec_element(vec_ptr v, long int index, data_t *dest)
{
	if (index<0 || index>v->len)
	{
		return 0;
	}
	else
	{
		*dest = v->data[index];
		return 1;
	}
}

long int vec_length(vec_ptr v)
{
	return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
	return v->data;
}

void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
	long int i;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t)0;
	int limit = length - 3;
	for (i = 0; i < limit; i += 4)
	{
		sum += (udata[i] * vdata[i] + udata[i + 1] * vdata[i + 1] + udata[i + 2] * vdata[i + 2] + udata[i + 3] * vdata[i + 3]);
	}
	for (; i < length; i++)
	{
		sum += udata[i] * vdata[i];
	}



	*dest = sum;
}


int main()
{

}