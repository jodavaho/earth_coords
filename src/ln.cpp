/*
 * earconverter.cpp
 *
 *  Created on: Mar 26, 2011
 *      Author: joshua
 */

#include "EarthCoords/EarthCoords.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	if (argc<8){
		printf("use as:\n\tlineup <home-lat> <home-lon> <pt1 lat> <pt1 lon> <pt2 lat> <pt2 lon> [more pairs] N\n" );
		return -1;
	}
	RSN::EarthCoords e;
	e.setHome(atof(argv[1]),atof(argv[2]));
	int npts = (argc - 4)/2;
	int nlegs = npts - 1;
	int N = atoi(argc[argv-1]);
	
	double * d = new double[nlegs];
	double * dx = new double[nlegs];
	double * dy = new double[nlegs];

	double * ptx = new double[npts];
	double * pty = new double[npts];

	double sum=0;
	for (int i=1;i<=npts;i++){
		ptx[i-1] = atof(argv[1+2*i]);
		pty[i-1] = atof(argv[2+2*i]);
	}
	for (int i=0;i<nlegs;i++){
		double cdx = ptx[i+1] - ptx[i];
		double cdy = pty[i+1] - pty[i];

		d[i] = pow(ptx[i+1]-ptx[i],2) + pow(pty[i+1]-pty[i],2);
		d[i] = sqrt(d[i]);
		dx[i] = cdx;
		dy[i] = cdy;
		sum+=d[i];
		//printf("%f, %f -> %f, %f dl= %f,%f d=%f \n",ptx[i],pty[i],ptx[i+1],pty[i+1],dx[i],dy[i],d[i]);
	}
	double inc = sum/N;

	//printf("%d\n",nlegs);
	for (int seg=0;seg<nlegs;seg++){
		int n = floor(d[seg]/inc);
		double offset = d[seg] - n*inc;
		double xo,yo;
		if (dy[seg]==0){yo = 0;xo = offset/2;}
		else if (dx[seg]==0){xo = 0;yo = offset/2;}
		else {
			xo = offset/2 * dy[seg]/dx[seg];
			yo = offset/2 * dx[seg]/dy[seg];
		}
		for (int i=0;i<n;i++){
			double z,a;
			e.getLocalCords(xo+ptx[seg]+i*dx[seg]/n,yo+pty[seg]+i*dy[seg]/n,z,a);
			printf("%f %f\n",z,a);
		}
	}
	printf("\n");
	return 0;
}
