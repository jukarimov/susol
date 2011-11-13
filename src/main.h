#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100
#define SUDOKU_SIZE 9

#define putd(d) (printf("[%d]\n", d))
 
#define TRUE 1 
#define FALSE 0 

int DAT[100][100];
int RAW[100][100]; 
int CHK[100][100];

void input(char *fname); 
void getdat(void);
void datcpy(int [MAX][MAX]);
void printsu(int [MAX][MAX]);
void output(int [MAX][MAX], char *); 
void output_raw(int [MAX][MAX], char *); 

int val(int c);
int chr(int d);

void print_row(int row); 
void xprint_row(int row, int [MAX][MAX]);
void print_col(int col);
void print_zon(int col, int row);
void print_blk(int brow, int bcol);

void dec(int *x, int *y);
void inc(int *x, int *y);

int in_row(int row, int n);
int in_col(int col, int n);
int in_zon(int row, int col, int n);
int in_blk(int row, int col, int n);

int chkdat();
int chkrow(int row, int n);
int chkcol(int col, int n);
int chkzon(int row, int col, int n);
int chkblk(int row, int col, int n);
int test(int row, int col, int n);

int possible(int row, int col, int n);
int search(int row, int col, int start); 
int searchbak(int row, int col, int start);

int fill_min(void);
int fill_next(char *, char *);
int fill_max(void); 
