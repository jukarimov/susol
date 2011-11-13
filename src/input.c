/*
   	Susol - sudoku solver
	Copyright (C) 2011 Jalil U. Karimov <jukarimov@gmail.com>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
*/

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
