/*
 * main.c
 *
 *  Created on: 25-May-2018
 *      Author: Nachiket
 */

#include "stdio.h"
#include "xparameters.h"
#include "PmodGPS.h"

#ifdef XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ
#define PERIPHERAL_CLK 100000000 // FCLK0 frequency is not in xparameters.h for some reason
#else
#define PERIPHERAL_CLK XPAR_CPU_M_AXI_DP_FREQ_HZ
#endif

int main(){
	PmodGPS gps;

	while(1){
		GPS_begin(&gps, XPAR_PMODGPS_0_AXI_LITE_GPIO_BASEADDR, XPAR_PMODGPS_0_AXI_LITE_UART_BASEADDR, PERIPHERAL_CLK);


		printf("Ping: %d\n", gps.ping);
		//GPS_formatSentence(&gps);
		printf("Latitude: %s\n", GPS_getLatitude(&gps));
	}

	return 0;
}
