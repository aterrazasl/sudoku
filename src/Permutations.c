/*
 * Permutations.c
 *
 *  Created on: Oct 1, 2018
 *      Author: aterrazas
 */


#include <stdio.h>
#include <string.h>
#include "Permutations.h"

void swap(char *x, char *y)
{
	char temp;
	temp= *x;
	*x=*y;
	*y= temp;
}


void permute(char *a, int l, int r)
{
	int i;
	int j;
	if (l==r)
	{
//		for(j=0; j<r; j++)
//		{
//			printf("%d,",*(a+j));
//		}
//
//		printf("\n");

		totalPerm++;
	}
	else
	{
		for(i=l; i< r; i++)
		{
			swap((a+l), (a+i));
			permute(a,l+1,r);
			swap((a+l),(a+i));
		}
	}
}


int mainTest()
{
	char str[] = {1,2,1};
	int n = strlen(str);
	permute(str,0,3);//n-1);
	return 0;
}
