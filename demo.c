#include <stdio.h>
#include<stdint.h>
#include <inttypes.h> // Required for PRIu32
int main(void)
{

	int x = 32;
	int *p = &x;

	printf("The value of p is: %p \n", p);
	
}