/*
 * user_code.c
 *
 *  Created on: Aug 12, 2020
 *      Author: king_pc1
 */
#include "main.h"
#include "sys.h"

/*' '转0
 *
 */
void String_Handle(char* p){
	while(*p!='\0'){
		if(*p==' '){
			*p='0';
		}
		p++;
	}
}
