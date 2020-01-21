#include <stdio.h>

#include "io.h"

#include<stdlib.h>

#include "memory.h"

#include "buffer.h"



#define _CRT_SECURE_NO_WARNINGS



#define BUFFER_SIZE 64



#define MIN     0

#define MAX     1

#define ODD     2

#define EVEN    3

#define MINMAX  4

#define ODDEVEN 5







void processing(int[]);





void transferringToLocal(int[]);



void transferringFromLocal(int[]);

void submitting();





int main(void)

{

	int i=0,j=0;

   

    int dataSize;

    int *localBuffer = NULL;



	dataSize=reading();

      while (dataSize !=-1) {



        localBuffer = (int *)my_malloc((dataSize + 2) * sizeof(int));

		if(localBuffer==NULL)

		{

			printf("\nMemory has not been allocated!!");

			exit(0);

		}

        transferringToLocal(localBuffer);

        processing(localBuffer);

        transferringFromLocal(localBuffer);

        my_free(localBuffer);

        submitting();

        dataSize = reading();

    }

	printf("\n");

    return 0;

}







void processing(int localBuffer[]){



    int Number_of_data_points=0;

    int value_minimum=0;

    int value_maximum=0;

    int value_odd=0;

    int value_even=0;

	int i=0;



    Number_of_data_points=localBuffer[1];

    printf("\nOriginal Local Buffer is: \n");

    for(i=0;i<Number_of_data_points+2;i++)

    {

    		printf("  %d  ",localBuffer[i]);

    }

    if ((localBuffer[0])==0)

    {

            value_minimum=localBuffer[2];

            for(i=2;i<Number_of_data_points+2;i++)

            {

                if(localBuffer[i]<value_minimum)

                    value_minimum=localBuffer[i];

            }

            localBuffer[1]=1;

            localBuffer[2]=value_minimum;

            for( i=3;i<Number_of_data_points+2;i++)

               {

                localBuffer[i]=0;

               }

    }

    else if (( localBuffer[0])==1)  

    {

            value_maximum=localBuffer[2];

            for(i=2; i<Number_of_data_points+2;i++)

            {

                if(localBuffer[i]>value_maximum)

                    value_maximum=localBuffer[i];

            }

            localBuffer[1]=1;

            localBuffer[2]=value_maximum;

            for( i=3;i<Number_of_data_points+2;i++)

             {

               localBuffer[i]=0;

             }

    }

    else if ((localBuffer[0])==2)  

    {

    			for(i=2;i<Number_of_data_points+2;i++)

            {

                if((localBuffer[i])%2!=0)

                {

                    value_odd++;

                }

            }

            localBuffer[1]=1;

            localBuffer[2]=value_odd;

            for( i=3;i<Number_of_data_points+2;i++)

              {

                localBuffer[i]=0;

               }

    }

    else if ((localBuffer[0])==3) 

    {

            for(i=2;i<Number_of_data_points+2;i++)

            {

                if((localBuffer[i])%2==0)

                {

                    value_even++;

                }

            }

            localBuffer[1]=1;

            localBuffer[2]=value_even;

            for( i=3;i<Number_of_data_points+2;i++)

            {

            		localBuffer[i]=0;

            }

    }

    else if ((localBuffer[0])==4)

    {

            value_minimum = localBuffer[2];

            value_maximum = localBuffer[2];

            for(i=2;i<Number_of_data_points+2;i++)

            {

                if(localBuffer[i]<value_minimum)

                    value_minimum=localBuffer[i];

                if(localBuffer[i]>value_maximum)

                    value_maximum=localBuffer[i];

            }

            localBuffer[1]=2;

            localBuffer[2]=value_minimum;

            localBuffer[3]=value_maximum;

            for( i=4;i<Number_of_data_points+2;i++)

              {

                	localBuffer[i]=0;

              }

    }

    else if ((localBuffer[0])==5)  

    {

            for(i=2;i<Number_of_data_points+2;i++)

            {

                if((localBuffer[i])%2!=0)

                {

                    value_odd++;

                }

                else if(localBuffer[i]%2==0)

                {

                    value_even++;

                }

            }

            localBuffer[1]=2;

            localBuffer[2]=value_odd;

            localBuffer[3]=value_even;

            for( i=4;i<Number_of_data_points+2;i++)

            {

            	localBuffer[i]=0;

            }

    }

       printf("\nModified Local Buffer is: \n");

               for( i=0;i<Number_of_data_points+2;i++)

               {

               		printf("  %d  ",localBuffer[i]);

               }

    }



