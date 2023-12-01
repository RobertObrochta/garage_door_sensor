#include "wifi.h"
//#include "config.h"
#include "main.h"

int indexdata=0;
int indexsensor=0;

uint8_t payloadsensors[1000];

void setSensor(uint8_t *name){
	uint8_t value[50];
	if(indexsensor!=0){
	strcat(payloadsensors,"} ] },{ \"sensor\":");
	strcat(payloadsensors,"\"");
	strcat(payloadsensors,name);
	strcat(payloadsensors,"\"");
	strcat(payloadsensors,", \"data\": [ {");
	}else{
	memset(payloadsensors,0,sizeof(payloadsensors));
	strcpy(payloadsensors,"\"");
	strcat(payloadsensors,name);
	strcat(payloadsensors,"\"");
	strcat(payloadsensors,", \"data\": [ {");
	}
	indexsensor++;
	indexdata=0;

}

void setDataInt(uint8_t *payload, int data){
	uint8_t value[10];
	if(indexdata!=0){
		sprintf(value,",");
		strcat(payloadsensors,value);
		strcat(payloadsensors,"\"");
		strcat(payloadsensors,payload);
		strcat(payloadsensors,"\"");
		strcat(payloadsensors,":");
		sprintf(value,"\"%d\"",data);
		strcat(payloadsensors,value);
	}else{
		strcat(payloadsensors,"\"");
		strcat(payloadsensors,payload);
		strcat(payloadsensors,"\"");
		strcat(payloadsensors,":");
		sprintf(value,"\"%d\"",data);
		strcat(payloadsensors,value);

	}
	indexdata++;


}
