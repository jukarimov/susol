#include "main.h"  

void input(char *fname) 
{
    fprintf(stderr, "Reading file: %s...\n", fname); 
    FILE *fp = fopen(fname, "r");
	if (!fp) {
    	fprintf(stderr, "Can not read file: %s\n", fname); 
		exit(-1);
	}
    int c, col = 0, row = 0; 
    while ((c = fgetc(fp)) != EOF) 
    { 
        //fprintf(stderr, "Reading cell: %d,%d\n", row, col); 
        if (row == SUDOKU_SIZE + 1) { 
            fprintf(stderr, "input.c: the rest of input ommited\n"); 
            break; 
        }  

        if (c == '\n') { 
            row++; 
            col = 0; 
            continue; 
        }  

        else if (c == '+') { 
			while (fgetc(fp) != '\n')
				;
            continue; 
        }

        else if (c == '|') { 
            continue; 
        }


        else if (c >= '0' && c <= '9') { 
            RAW[row][col] = c; 
            col++; 
        } 
 
        else if (c == '.') { 
            RAW[row][col] = c; 
            col++; 
        }  

        else if (c != ' ') { 
            puts("Bad input"); 
            exit(-1); 
    	} 
    } 
	fclose(fp);
} 
 
void getdat() 
{ 
    int i, j; 
    for (i=0; i < 9; i++) { 
        for (j=0; j < 9; j++) { 
            if (RAW[i][j] != '.') 
                DAT[i][j] = val(RAW[i][j]); 
            else 
                DAT[i][j] = 0; 
        } 
    } 
} 


void datcpy(int A[MAX][MAX])
{ 
    int i, j; 
    for (i=0; i < 9; i++) { 
        for (j=0; j < 9; j++) { 
                A[i][j] = DAT[i][j]; 
        } 
    } 
} 
