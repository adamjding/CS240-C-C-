
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot(char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS];
  double xx[MAXCOLS];	//not used for plotting
  clearPlot();

  // Evaluate function and store in vector yy

  //Compute maximum and minimum y in vector yy
  
  //Plot x axis

  //Plot y axis

  // Plot function. Use scaling.
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1

	for(int i = 0; i < MAXCOLS; i++){
		double x = minX + (maxX - minX) * i / MAXCOLS; //formula was given, X value
		double y = rpn_eval(funcFile, x);	//Y value
		xx[i] = x;	//assigns x value
		yy[i] = y;	//assigns y value	
	}

	double minY = yy[0];
	double maxY = yy[0];
	for(int i = 0; i < MAXCOLS; i++){	//loops get minY and maxY
		if(minY >  yy[i]){
			minY = yy[i];
		}
		if(maxY < yy[i]){
			maxY = yy[i];
		}
	}
	
	for(int i = 0; i < MAXCOLS-1; i++){	//prints y axis
		double rowNum = MAXCOLS/2;
		plotXY(rowNum, i, '|');
	}

	for(int i = 0; i <  MAXCOLS; i++){
		 int yPlot = (int)((0 - minY) * MAXROWS / (maxY - minY)); //plots X axis
                 yPlot = MAXROWS - yPlot - 1;
                 plotXY(i, yPlot, '_');
        }  
	
	for(int i = 0; i <  MAXCOLS; i++){
		int yPlot = (int)((yy[i] - minY) * MAXROWS / (maxY - minY)); //formula give
		yPlot = MAXROWS - yPlot - 1;
      	        plotXY(i, yPlot, '*');
	}
  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
	
	/*char* funcFile = argv[1];
	double maxX = atof(argv[2]);
	double minX = atof(argv[3]);
	createPlot(funcFile, maxX, minX);*/
  }

  // Get arguments
  
  //createPlot(funcName, xmin, xmax);
	 char* funcFile = argv[1];
         double maxX = atof(argv[3]);
         double minX = atof(argv[2]);
         createPlot(funcFile, minX, maxX);
}
