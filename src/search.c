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

void dec(int *row, int *col)
{
     int a = *row, b = *col;

     if (!a && !b) {
		*row = -1;
		return;
     }

     if (a != 0 && b == 0) {
        *col = 8;
        *row = a - 1;
     }
     else 
        *col = b - 1;
}

void inc(int *row, int *col)
{
	int a = *row, b = *col;

	if (a == 8 && b == 8) {
		*row = -1;
		return;
     }

     if (a != 8 && b == 8) {
        *col = 0;
        *row = a + 1;
     }
     else 
        *col = b + 1;
}

int in_row(int row, int n)
{
	int i;
	for (i=0; i < SUDOKU_SIZE; i++) {
		if (DAT[row][i] == n)
			return 1;
	}
	return 0;
}

int in_col(int col, int n)
{
	int i;
	for (i=0; i < SUDOKU_SIZE; i++) {
		if (DAT[i][col] == n)
			return 1;
	}
	return 0;
}

int in_zon(int row, int col, int n)
{
	if (in_row(row, n) == 0 && in_col(col, n) == 0)
		return 0;
	else
		return 1;
}

int in_blk(int row, int col, int n)
{
	int a = (row / 3) * 3;
	int b = (col / 3) * 3;
	int i, j;
	for (i = a; i < a + 3; i++) {
		for (j = b; j < b + 3; j++) {
			if (DAT[i][j] == n)
				return 1;
		}
	}

	return 0;
}

int possible(int row, int col, int n)
{
	if (in_zon(row, col, n) == 0 && in_blk(row, col, n) == 0)
		return 1;
	else
		return 0;  
}

int search(int row, int col, int start)
{
	int i;
	for (i = start; i < SUDOKU_SIZE + 1; i++) {
		if (possible(row, col, i))
			return i;
		/*else
			printf("[search:%d is not possible]\n", i);*/
	}
	return -1;
}

int searchbak(int row, int col, int start)
{
	int i;
	for (i = start; i != 0 ; i--) {
		if (possible(row, col, i))
			return i;
	}
	return -1;
}

