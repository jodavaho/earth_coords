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
	if (argc==1 || (argc<5 && argc%2!=1)){
		printf("use as:\n\tconverter <home-lat,home-lon> <target-lat> <target-lon> [<target-lat> <target-lon>]\n ie..\n\t converter 44.974299 -93.227918 44.97 -93.22 44.88 -92.18\n ... which would set home to the first pair and convert all remaining pairs\n");
		return -1;
	}
	RSN::EarthCoords e;
	e.setHome(atof(argv[1]),atof(argv[2]));
	double d1 = atof(argv[1]);
	double d2 = atof(argv[2]);
	//printf("Home set to %0.6f, %0.6f\n",d1,d2);
	int i=3;
	double x,y,x2,y2;
	while(i<argc){
		y = atof(argv[i]);
		x = atof(argv[i+1]);
		e.getLocalCords(y,x,x2,y2);
		printf("%f, %f, %f, %f\n",x,y,x2,y2);
		i++;
		i++;
	}
	printf("\n");
	return 0;
}
