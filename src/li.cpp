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
	if (argc!=8){
		printf("use as:\n\tlineup <home-lat> <home-lon> <pt1 lat> <pt1 lon> <pt2 lat> <pt2 lon> Interval\n" );
		return -1;
	}
	RSN::EarthCoords e;
	e.setHome(atof(argv[1]),atof(argv[2]));
	double pt[4];
	for (int i=0;i<4;i++){
		pt[i] = atof(argv[i+3]);
	}
	double dlat = pt[2]-pt[0];
	double dlon = pt[3]-pt[1];
	int N = atoi(argv[7]);
	for (int i=0;i<N+1;i++){
		double x,y;
		e.getLocalCords(pt[0]+dlat/(N)*i,pt[1]+dlon/N*i,x,y);
		printf("%0.3f,%0.3f\n",x,y);
	}
	printf("\n");
	return 0;
}
