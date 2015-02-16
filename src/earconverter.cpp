/*
 * earconverter.cpp
 *
 *  Created on: Mar 26, 2011
 *      Author: joshua
 */

#include <EarthCoords/EarthCoords.h>
#include <stdio.h>
#include <stdlib.h>

using namespace RSN;

int main(int argc, char** argv){
	if (argc==1){
	}
	EarthCoords e;
	double x,y;
	for (int i=1;i<argc;i+=2){
		if (strcmp("-h",argv[i])==0){
			e.setHome(atof(argv[i+1]),atof(argv[i+2]));
			i=i+1;
		}
		e.getLocalCords(atof(argv[i]),atof(argv[i+1]),x,y);
		printf("%0.3f,%0.3f\n",x,y);
	}
//	e.getLocalCords(,,x,y);
//	printf("tag la: %f, tag lo: %f",x,y);
	//44.97426,-93.22765

	/*
	 * 44.974299, -93.227918
	 * 44.974279, -93.227968
	 * 44.974263, -93.227955
	 * 44.974266, -93.227974
	 * 44.974266, -93.227916
	 * 44.974266, -93.227920
	 *
	 */
/*
	e.setHome(44.974299, -93.227918);
	e.getLocalCords(44.974387,-93.2277421,x,y);
		printf("tag x: %f, tag y: %f\n",x,y);
	e.setHome(44.974279, -93.227968);
	e.getLocalCords(44.974387,-93.2277421,x,y);
		printf("tag x: %f, tag y: %f\n",x,y);
	e.setHome(44.974263, -93.227955);
	e.getLocalCords(44.974387,-93.2277421,x,y);
		printf("tag x: %f, tag y: %f\n",x,y);
	e.setHome(44.974266, -93.227974);
	e.getLocalCords(44.974387,-93.2277421,x,y);
		printf("tag x: %f, tag y: %f\n",x,y);
	e.setHome(44.974266, -93.227916);
	e.getLocalCords(44.974387,-93.2277421,x,y);
		printf("tag x: %f, tag y: %f\n",x,y);
	e.setHome(44.974266, -93.227920);
	e.getLocalCords(44.974387,-93.2277421,x,y);
	printf("tag x: %f, tag y: %f\n",x,y);
*/
//	//44.97403,-93.22778
//
//	e.setHome(44.974195511,-93.227734676);
//	e.getLocalCords(44.97403,-93.22778,x,y);
//	printf("before last tag x: %f, tag y: %f\n",x,y);
//
//	e.setHome(44.974011691,-93.227595842);
//	e.getLocalCords(44.97403,-93.22778,x,y);
//	printf("last tag x: %f, tag y: %f\n",x,y);
//
//	e.setHome(44.974019999,-93.227595842);
//	e.getLocalCords(44.97401,-93.22759,x,y);
//	printf("err x: %f, err y: %f\n",x,y);
}
