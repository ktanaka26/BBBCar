﻿#include <BBB.h>
#include <BBB_GPIO.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i, ctrNum;
	char pin_name[4][8] = {"P9_11", "P9_12", "P9_13", "P9_14"};

	BBB_gpio *gpio[4];
	for(i = 0; i < 4; i++){
		gpio[i] = BBB_open_gpio(pin_name[i]);
		if( gpio[i] == NULL ) {
			printf("Can not open %s\n", pin_name[i] );
			return;
		}
		gpio[i]->set_direction(gpio[i], OUT);
		gpio[i]->put(gpio[i], 0);
	}
		

	while(i){
		printf("------------------------------\n"
			"Type number of control:");
		scanf("%d", &ctrNum);
		switch(ctrNum){
			case 0:
			gpio[2]->put(gpio[2], 0);
			gpio[3]->put(gpio[3], 0);
			break;

			case 1:
			gpio[2]->put(gpio[2], 0);
			gpio[3]->put(gpio[3], 1);
			break;

			case 10:
			gpio[2]->put(gpio[2], 1);
			gpio[3]->put(gpio[3], 0);
			break;

			case 11:
			gpio[2]->put(gpio[2], 1);
			gpio[3]->put(gpio[3], 1);
			break;
	
			case 99:
			i = 0;
			printf("Exit commmand was typed.\n");
			break;

			default:
			printf("Illegal number was typed!!\n");
			ctrNum = 0;
			break;
		}
		printf("Now Status: gpio0:%d gpio1:%d\n"
			"------------------------------\n\n\n", gpio[2]->get(gpio[2]), gpio[3]->get(gpio[3]));
	}

	for(i = 0; i < 4; i++){
		BBB_close_gpio(gpio[i]);
	}
}	
