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

int val(int c)
{
	return c - '0';
}

int chr(int d)
{
	return d + '0';
}

void print_row(int row)
{
	int col;
	for (col=0 ; col < SUDOKU_SIZE; col++)
		printf("%c%s", DAT[row][col] ? chr(DAT[row][col]) : '.',
			col == 8 ? "" : " ");
	puts("");
}

void print_col(int col)
{
	int row;
	for (row = 0; row < SUDOKU_SIZE; row++)
		printf("%c ", DAT[row][col] ? chr(DAT[row][col]) : '.');
	puts("");
}

void print_zon(int col, int row)
{
	print_col(col);
	print_row(row);
}

void print_blk(int brow, int bcol)
{
	int row, col;
	int n = SUDOKU_SIZE / 3;
	int x = brow * n, y = bcol * n;

	for (row = x; row < x + n; row++)
	{
		for (col = y; col < y + n; col++)
			printf("%c ", DAT[row][col] ? chr(DAT[row][col]) : '.');
		puts("");
	}
}

void printsu(int A[MAX][MAX])
{
	int i, j;
	for (i=0; i < 9; i++) {
		for (j=0; j < 9; j++)
			printf("%c%c", A[i][j] ? chr(A[i][j]) : '.',
			j == 8 ? '\n' : ' '); 
	}
}

void printsu_rotated(int A[MAX][MAX])
{
	int i, j;
	for (i=8; i != -1; i--) {
		for (j=8; j != -1; j--)
			printf("%c ", A[i][j] ? chr(A[i][j]) : '.'); 
		puts("");
	}
}

void output(int A[MAX][MAX], char *fname)
{
	fprintf(stderr, "Dumping to file: %s...\n", fname); 

	FILE *fp = fopen(fname, "w");

	if (!fp) {
		fprintf(stderr, "Can not write file: %s\n", fname); 
		exit(-1);
	}

	int i, j, k, p, q;
/*
	for (i=0; i < 9; i++) {
		for (j=0; j < 9; j++)
			fprintf(fp, "%c%c", A[i][j] ? chr(A[i][j]) : '.', j == 8 ? '\n' : ' ');
	}
*/
	for (q=0; q < 3; q++)
	 	fprintf(fp, "+-------");
	putc('+', fp);
	putc('\n', fp);

	for (i=0, p=0; i < 9; i++, p++) {

		if (p == 3) {
			p = 0;
			for (q=0; q < 3; q++)
				fprintf(fp, "+-------");
				putc('+', fp);
				putc('\n', fp);
		}

		for (j=0, k=0; j < 9; j++, k++) {
			if (k == 3) k = 0;
			fprintf(fp, "%s%c%s", 
				k == 0 ? "| ": "",
				A[i][j] ? chr(A[i][j]) : '.',
				j == 8 ? " |\n" : " "
			);
		}
	}

	for (q=0; q < 3; q++)
	 	fprintf(fp, "+-------");
	putc('+', fp);
	putc('\n', fp);

	fclose(fp);
}

void logdat(int A[MAX][MAX], char *fname)
{
	fprintf(stderr, "Dumping to file: %s...\n", fname); 

	FILE *fp = fopen(fname, "a+");

	if (!fp) {
		fprintf(stderr, "Can not write file: %s\n", fname); 
		exit(-1);
	}

	int i, j, k, p, q;
/*
	for (i=0; i < 9; i++) {
		for (j=0; j < 9; j++)
			fprintf(fp, "%c%c", A[i][j] ? chr(A[i][j]) : '.', j == 8 ? '\n' : ' ');
	}
*/
	for (q=0; q < 3; q++)
	 	fprintf(fp, "+-------");
	putc('+', fp);
	putc('\n', fp);

	for (i=0, p=0; i < 9; i++, p++) {
		if (p == 3) {
			p = 0;
			for (q=0; q < 3; q++)
				fprintf(fp, "+-------");
			putc('+', fp);
			putc('\n', fp);
		}

		for (j=0, k=0; j < 9; j++, k++) {
			if (k == 3)
				k = 0;
			fprintf(fp, "%s%c%s", 
				k == 0 ? "| ": "",
				A[i][j] ? chr(A[i][j]) : '.',
				j == 8 ? " |\n" : " "
			);
		}
	}

	for (q=0; q < 3; q++)
		fprintf(fp, "+-------");
	putc('+', fp);
	putc('\n', fp);

	fclose(fp);
}
