/*
 ============================================================================
 Name        : Sudoku.c
 Author      : Antonio
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//#define PRINTDEBUG

char constantSudoku[81] =		   {0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0,
									0,0,0,0,0,0,0,0,0 };


//char constantSudoku[81] = 	   {0,0,0,0,0,0,0,0,1,
//								0,0,0,0,0,3,0,2,0,
//								0,0,0,0,8,5,0,0,0,
//								0,0,0,0,0,4,0,9,0,
//								5,0,7,0,0,0,0,0,0,
//								0,0,0,1,0,0,0,0,0,
//								5,0,0,0,0,2,0,0,0,
//								0,0,0,0,1,0,0,4,0,
//								0,7,3,0,0,0,0,0,9};

//char constantSudoku[81] = 	   {0,0,0,0,0,7,0,5,8,
//								2,1,0,3,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								4,3,0,2,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,8,0,7,6,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,7,0,9,8,
//								2,5,0,3,0,0,0,0,0};

//char constantSudoku[81] = 	   {0,5,0,0,0,0,0,0,0,
//								0,9,0,0,0,0,0,5,0,
//								0,1,0,7,0,0,4,0,6,
//								9,0,8,0,7,0,6,0,0,
//								0,0,2,8,0,0,5,4,0,
//								0,0,0,0,0,0,0,2,0,
//								0,0,0,0,0,0,5,0,6,
//								0,0,0,7,0,3,0,0,0,
//								0,6,2,1,0,0,0,0,0};

//char constantSudoku[81] = 	   {0,0,0,4,0,0,8,0,1,
//								0,7,0,0,0,0,0,0,0,
//								0,4,5,8,0,0,0,0,0,
//								0,8,0,0,0,0,2,1,0,
//								0,0,2,5,9,0,0,0,4,
//								0,0,0,0,6,0,0,0,0,
//								5,0,0,0,0,2,0,0,0,
//								4,0,0,0,0,0,6,0,0,
//								0,0,3,0,0,7,0,5,4};

//char constantSudoku[81] = 	   {0,5,0,4,6,9,0,0,0,
//								0,0,0,0,0,0,0,0,9,
//								0,0,0,0,0,5,3,0,0,
//								0,0,0,1,0,0,0,0,0,
//								5,0,7,0,3,0,0,0,0,
//								2,0,0,0,0,0,0,1,0,
//								6,0,0,7,0,4,8,0,0,
//								0,0,0,2,0,0,6,0,0,
//								0,0,7,1,0,0,0,4,2};

//char constantSudoku[81] = 	   {0,0,0,0,0,0,0,0,6,
//								0,4,6,0,0,0,0,0,3,
//								5,0,0,9,0,0,0,2,0,
//								0,0,3,0,0,0,0,9,0,
//								0,8,0,4,0,9,0,0,0,
//								0,0,0,0,8,0,0,6,0,
//								7,0,0,2,4,0,0,5,0,
//								0,9,0,8,1,0,0,3,0,
//								0,0,5,0,0,0,0,0,0};

//char constantSudoku[81] = 	   {1,0,0,0,0,6,0,3,8,
//								0,0,8,0,0,0,4,0,0,
//								6,0,4,0,8,0,0,0,0,
//								0,0,0,9,0,0,0,4,5,
//								0,4,1,6,0,7,3,9,0,
//								2,5,0,0,0,8,0,0,0,
//								0,0,0,0,8,0,5,0,1,
//								0,0,9,0,0,0,7,0,0,
//								7,4,0,5,0,0,0,0,3};

//char constantSudoku[81] = 	   {1,0,0,0,0,5,0,4,8,
//								0,0,8,0,0,0,2,0,0,
//								5,0,2,0,8,0,0,0,0,
//								0,0,0,9,0,0,0,2,6,
//								0,2,1,5,0,3,4,9,0,
//								7,6,0,0,0,8,0,0,0,
//								0,0,0,0,8,0,6,0,1,
//								0,0,9,0,0,0,3,0,0,
//								3,2,0,6,0,0,0,0,4};

//char constantSudoku[81] = 	   {1,0,3,0,0,0,0,0,0,
//								4,5,6,0,0,0,0,0,0,
//								7,8,9,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0};

//char constantSudoku[81] = 	   {0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								0,0,0,0,0,0,0,0,0,
//								1,2,3,4,0,6,7,8,9};

//Returns the index of the first number of a box
int getIndexBox(char box)
{
	return ( ( box % 9 ) * 9 );
}

//Get value from board at row and col
char getValueBoard(char * res, char row, char col)
{
	return 	*(res + (row % 3)*3  + ( (row / 3) * 27 ) + (col % 3) + ( (col / 3) * 9 ) );
}

//Initialize the pointer with the sudoku sequence
int initializeSudokuBoard(char * res)
{
	memcpy(res, constantSudoku, sizeof(char) * 9 * 9); //9x9
	printf("%s","Initial Sudoku\n");
	printBoard(res);
	return 0;
}

//Print Sudoku board
int printBoard(char * array)
{
	int element,box;
	printf("-----------------------------------------\n");

	for(box = 0; box < 9; box = box + 3)
	{
		for(element = 0; element < 3; element ++)
		{
			printf(" %d | %d | %d  +  ", *(array + getIndexBox(box+0) + (element * 3) + 0), *(array + getIndexBox(box+0) + (element * 3) + 1), *(array + getIndexBox(box+0) + (element * 3) + 2));
			printf(" %d | %d | %d  +  ", *(array + getIndexBox(box+1) + (element * 3) + 0), *(array + getIndexBox(box+1) + (element * 3) + 1), *(array + getIndexBox(box+1) + (element * 3) + 2));
			printf(" %d | %d | %d \n"  , *(array + getIndexBox(box+2) + (element * 3) + 0), *(array + getIndexBox(box+2) + (element * 3) + 1), *(array + getIndexBox(box+2) + (element * 3) + 2));
		}
		printf("-----------------------------------------\n");
	}
	printf("\n");
	return 0;
}

//Validate that a box as only a sequence of number from 1 to 9
//Return 1 if valid 0 otherwise
int validateBox( char *res, char box )
{
	int element;
	int scdElement;

	for(element = 0; element < 9; element ++)
	{
//		if(*( res + getIndexBox(box) + element ) == 0)
//		{
//			return 0;
//		}


#define FIRSTELEMENT *( res + getIndexBox(box) + element )
#define SECONDELEMENT *( res + getIndexBox(box) + scdElement )

		for(scdElement = element+1; scdElement < 9; scdElement ++)
		{
			if((*( res + getIndexBox(box) + element ) != 0) & ( (FIRSTELEMENT) == (SECONDELEMENT)) )
			{
#ifdef PRINTDEBUG
				printf("Value %d in Box %d is not valid\n",FIRSTELEMENT, box);
#endif
				return 0;
			}
		}

	}
#ifdef PRINTDEBUG

	printf("Box %d is valid\n",box);
#endif
#undef FIRSTELEMENT
#undef SECONDELEMENT
	return 	1;
}

//Validate that a Row as only a sequence of number from 1 to 9
//Return 1 if valid 0 otherwise
int validateRow(char *res, char row )
{
	int element;
	int scdElement;

	for(element = 0; element < 9; element ++)
	{

		for(scdElement = element+1; scdElement < 9; scdElement ++)
		{

			if( (getValueBoard(res, row, element) > 9))
			{
#ifdef PRINTDEBUG
				printf("Value %d in Row %d is not valid\n",getValueBoard(res, row, element), row);
#endif
				return 0;
			}

			if( (getValueBoard(res, row, element) != 0) & ( (getValueBoard(res, row, element)) == (getValueBoard(res, row, scdElement)) ))
			{
#ifdef PRINTDEBUG

				printf("Value %d in Row %d is not valid\n",getValueBoard(res, row, element), row);
#endif
				return 0;
			}
		}

	}
#ifdef PRINTDEBUG

	printf("Row %d is valid\n",row);
#endif

#undef FIRSTELEMENT
#undef SECONDELEMENT
	return 	1;
}

//Validate that a Col as only a sequence of number from 1 to 9
//Return 1 if valid 0 otherwise
int validateCol(char *res, char col )
{
	int element;
	int scdElement;

	for(element = 0; element < 9; element ++)
	{

		for(scdElement = element+1; scdElement < 9; scdElement ++)
		{

			if( (getValueBoard(res,element,col) != 0) &  ( (getValueBoard(res,element,col)) == (getValueBoard(res,scdElement,col)) ))
			{
#ifdef PRINTDEBUG
				printf("Value %d in Col %d is not valid\n",getValueBoard(res,col,element), col);
#endif
				return 0;
			}
		}

	}
#ifdef PRINTDEBUG

	printf("Col %d is valid\n",col);
#endif

#undef FIRSTELEMENT
#undef SECONDELEMENT
	return 	1;
}

//Update value of board at row and col
int updateValueBoard(char * res, char row, char col, char data)
{
	*(res + (row % 3)*3  + ( (row / 3) * 27 ) + (col % 3) + ( (col / 3) * 9 ) ) = data;
	return 0;
}

//Validate if cell is ok
//return 1 if row, col and box are valid
int validateCell(char * res, char row, char col)
{
	int box =  (col / 3)  + (3 * (row / 3) );

	if(!validateRow(res,row))
		return 0;

	if(!validateCol(res,col))
		return 0;

	if(!validateBox(res,box))
		return 0;

	return 1;
}

//Validate board use it for initial board check
//Return 1 if ok
int validateBoard(char * res)
{
	int count=0;
	int row=0;
	int col = 0;

	while(row < 9)
	{
		col = 0;
		while( col < 9 )
		{
			count++;
			if(validateCell(res, row, col))
			{
				col++;
			}
			else
			{
				printf("%s","Sudoku Board Invalid!\n");
				return 0;
			}
		}
		row ++;
	}
	//printf("%s\n\n","Sudoku Board Valid!");
	return 1;
}

//Solves sudokuBoard
int solveSudoku(char* sudokuBoard)
{
	int col=0;
	int row=0;
	int count=0;

	if(!validateBoard(sudokuBoard))
		return  EXIT_SUCCESS;

	while(row < 9)
	{
		col = 0;
		while( col < 9 )
		{
			count++;

			//evaluate if the original sudoku at row,col can be modified (diff than 0)
			char val = getValueBoard(constantSudoku,row,col);
			if( val != 0 )
			{
				col++;	//Can't be modified, change column
			}
			else
			{
				do{	//Get the valude at row,col and increment, do it until is valid
					val = getValueBoard(sudokuBoard,row,col);
					val ++;
					updateValueBoard(sudokuBoard, row, col, val);
				}while (!validateCell(sudokuBoard, row, col) & (val <= 9));

				if(val <= 9)	///if number is ok change next col
					col++;
				else
				{
					//value is not valid at row and col, change it to 0
					updateValueBoard(sudokuBoard, row, col, 0);

					do{
						if(col == 0)	//reach the begin of the row go to prev row
						{
							row --;
							col = 8;
						}
						else
						{
							col--;	//go back to prev col
						}
						val = getValueBoard(constantSudoku,row,col); //get the current value at original board
					}while ((val != 0)); // go back to prev col or row if value is 0
				}
			}

#ifdef PRINTDEBUG
			printBoard(sudokuBoard);
#endif
		}

		row ++;

	}

	//printBoard(constantSudoku);
	printf("%s","Sudoku Solved\n");
	printBoard(sudokuBoard);
	printf("Number of Iterations = %d\n\n", count);

	return count;
}

//decrement value if 0 returns 9
int dec(int value)
{
	if(value == 0)
		return 9;

	return value-1;
}

//Solves sudokuBoard reversed
int solveSudokuRev(char* sudokuBoard)
{
	int col=0;
	int row=0;
	int count=0;

	if(!validateBoard(sudokuBoard))
		return  EXIT_SUCCESS;

	while(row < 9)
	{
		col = 0;
		while( col < 9 )
		{
			count++;

			//evaluate if the original sudoku at row,col can be modified (diff than 0)
			char val = getValueBoard(constantSudoku,row,col);
			if( val != 0 )
			{
				col++;	//Can't be modified, change column
			}
			else
			{
				do{	//Get the valude at row,col and increment, do it until is valid
					val = getValueBoard(sudokuBoard,row,col);
					val = dec(val);
					updateValueBoard(sudokuBoard, row, col, val);
				}while (!validateCell(sudokuBoard, row, col) & (val >= 1));

				if(val >= 1)	///if number is ok change next col
					col++;
				else
				{
					//value is not valid at row and col, change it to 0
					updateValueBoard(sudokuBoard, row, col, 0);

					do{
						if(col == 0)	//reach the begin of the row go to prev row
						{
							row --;
							col = 8;
						}
						else
						{
							col--;	//go back to prev col
						}
						val = getValueBoard(constantSudoku,row,col); //get the current value at original board
					}while ((val != 0)); // go back to prev col or row if value is 0
				}
			}

#ifdef PRINTDEBUG
			printBoard(sudokuBoard);
#endif
		}

		row ++;

	}
	//printBoard(constantSudoku);
	printf("%s","Sudoku Solved\n");
	printBoard(sudokuBoard);
	printf("Number of Iterations = %d\n\n", count);

	return count;
}

int findBoxMissingSpaces(char * res, char box, int *sum, char *foundCol, char *foundRow)
{
	int row, irow;
	int col, icol;
	int count = 0;
	*(sum) = 0;

	irow = (box / 3) * 3;
	icol = (box % 3) * 3;

//	printf("row = %d",row);
//	printf(" col = %d\n",col);


	for(row  = irow; row < irow + 3; row++)
	{
		for(col = icol; col < icol + 3; col++)
		{
			if(!getValueBoard(res,row,col))
			{
				count++;
				*(foundRow) = row;
				*(foundCol) = col;
			}
			*(sum) = *(sum) + getValueBoard(res,row,col);
		}
	}

	return count;
}

int findColMissingSpaces(char * res, char col,int *sum, char *foundCol, char *foundRow)
{
	int row;
	int count = 0;

	*(sum) = 0;
	for(row  = 0; row < 9; row++)
	{
		if(!getValueBoard(res,row,col))
		{
			count++;
			*(foundRow) = row;
			*(foundCol) = col;
		}
		*(sum) = *(sum) + getValueBoard(res,row,col);
	}

	return count;
}

int findRowMissingSpaces(char * res, char row,int *sum, char *foundCol, char *foundRow)
{
	int col;
	int count = 0;
	*(sum) =0;

	for(col = 0; col < 9; col++)
	{
		if(!getValueBoard(res,row,col))
		{
			count++;
			*(foundRow) = row;
			*(foundCol) = col;
		}
		*(sum) = *(sum) + getValueBoard(res,row,col);
	}

	return count;
}

int firstPass(char * res)
{
	int box,icol,irow;
	char repeat=0;
	int sum;
	char col,row;
	char update =0;

	if(!validateBoard(res))
		return  EXIT_SUCCESS;

	do
	{
		repeat = 0;

		for(box = 0; box < 9; box ++)
		{
			if(findBoxMissingSpaces(res, box, &sum, &col,&row) == 1)
			{
				updateValueBoard(res, row, col, (45 - sum) );
				repeat ++;
				update ++;
			}
		}

		for(icol = 0; icol < 9; icol ++)
		{
			if(findColMissingSpaces(res, icol, &sum, &col,&row) == 1)
			{
				updateValueBoard(res, row, col, (45 - sum) );
				repeat ++;
				update++;
			}

			for(irow = 0; irow < 9; irow ++)
			{

				if(findRowMissingSpaces(res, irow, &sum, &col, &row) == 1)
				{
					updateValueBoard(res, row, col, (45 - sum) );
					repeat ++;
					update++;
				}

			}

		}


	}while(repeat != 0);

	if(update)
	{
		printf("%s","First pass result\n");
		printBoard(constantSudoku);

	}

	return 0;
}

int inputSudokuBoard(char * res)
{
	int row[9];
	int i,j;
	int scanned =0;

	printBoard(res);
	for(i=0; i<9; i++)
	{
		printf("type row %d data (type 0 to skip)\n",i);
		scanned = scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",&row[0],&row[1],&row[2],&row[3],&row[4],&row[5],&row[6],&row[7],&row[8]);
		if(scanned == 9)
		{
			for (j = 0; j < 9; j++)
			{
				updateValueBoard(res,i,j,row[j]);

			}
		}
	}

	printBoard(res);
	return 0;
}

int main(void)
{

	char * sudokuBoard = calloc( 9*9, sizeof( char ) ); //81 bytes of data

	inputSudokuBoard(constantSudoku);

	initializeSudokuBoard(sudokuBoard);
//	firstPass(constantSudoku);
	solveSudoku(sudokuBoard);


//	initializeSudokuBoard(sudokuBoard);
//	solveSudokuRev(sudokuBoard);

	return EXIT_SUCCESS;
}
