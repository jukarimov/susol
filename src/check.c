/*
   	Susol - sudoku solver
    Copyright (C) 2011 Jalil U. Karimov <jukarimov@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHCHK ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
*/
#include "main.h"


int chkrow(int row, int n)
{
	int i;
	for (i=0; i < SUDOKU_SIZE; i++) {
		if (CHK[row][i] == n)
			return 1;
	}
	return 0;
}

int chkcol(int col, int n)
{
	int i;
	for (i=0; i < SUDOKU_SIZE; i++) {
		if (CHK[i][col] == n)
			return 1;
	}
	return 0;
}

int chkzon(int row, int col, int n)
{
	if (chkrow(row, n) == 0 && chkcol(col, n) == 0)
		return 0;
	else
		return 1;
}

int chkblk(int row, int col, int n)
{
	int a = (row / 3) * 3;
	int b = (col / 3) * 3;
	int i, j;
	for (i = a; i < a + 3; i++) {
		for (j = b; j < b + 3; j++) {
			if (CHK[i][j] == n)
				return 1;
		}
	}

	return 0;
}

int test(int row, int col, int n)
{
	if (chkzon(row, col, n) == 0 && chkblk(row, col, n) == 0)
		return 1;
	else
		return 0;  
}

int chkdat()
{	
	datcpy(CHK);
	int i, j;
	for (i = 0; i < SUDOKU_SIZE; i++) {
		for (j = 0; j < SUDOKU_SIZE; j++) {
			if (!CHK[i][j]) {
				fprintf(stderr, "Not solved yet\n");
				return 1;
			}
			CHK[i][j] = 0;
			if (!test(i, j, DAT[i][j])) {
				fprintf(stderr, "%d isn't possible at %d,%d\n",
						DAT[i][j], i, j);
				return -1;
			}
		}
	}
	return 0;
}

