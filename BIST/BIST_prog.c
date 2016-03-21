/*
 * BIST_prog.c
 *
 *  Created on: Mar 2, 2016
 *      Author: Home
 */
#include "types.h"
#include "DIO_interface.h"
#include "BIST_config.h"
#include "BIST_interface.h"
#include "BIST_private.h"


extern u8 BIST_CheckPattern(u8 pattern) {
	u8 local_u8CheckPort0;
	u8 local_u8CheckPort1;
	u8 local_u8CheckPort2;
	u8 local_u8CheckPort3;
	u8 local_u8returnStatus;

	DIO_u8ReadPortVal(DIO_u8PORT0, &local_u8CheckPort0);
	DIO_u8ReadPortVal(DIO_u8PORT1, &local_u8CheckPort1);
	DIO_u8ReadPortVal(DIO_u8PORT2, &local_u8CheckPort2);
	DIO_u8ReadPortVal(DIO_u8PORT3, &local_u8CheckPort3); // i will send on port 3, pins 30 and 31

	switch (pattern) {
	case 1:
		local_u8CheckPort3 = local_u8CheckPort3 & CHECKPORT3PATTERN1;
		switch (local_u8CheckPort3) {
		case CHECKPORT3PATTERN1:
			local_u8CheckPort0 = local_u8CheckPort0 && local_u8CheckPort1
					&& local_u8CheckPort2;
			switch (local_u8CheckPort0) {
			case PATTERN1:
				local_u8returnStatus = okay;
				break;
			default:
				local_u8returnStatus = error;
				break;
			}
			break;
		default:
			local_u8returnStatus = error;
			break;
		}
		break;
	case 2:
		local_u8CheckPort3 = local_u8CheckPort3 & CHECKPORT3PATTERN2;
		switch (local_u8CheckPort3) {
		case CHECKPORT3PATTERN2:
			local_u8CheckPort0 = local_u8CheckPort0 && local_u8CheckPort1
					&& local_u8CheckPort2;
			switch (local_u8CheckPort0) {
			case PATTERN2:
				local_u8returnStatus = okay;
				break;
			default:
				local_u8returnStatus = error;
				break;
			}
			break;
		default:
			local_u8returnStatus = error;
			break;
		}

	}

	return local_u8returnStatus;
}
extern void BIST_Init()
{
	DIO_u8WritePortDir(DIO_u8PORT0,DIO_u8INPUT);
	DIO_u8WritePortDir(DIO_u8PORT1,DIO_u8INPUT);
	DIO_u8WritePortDir(DIO_u8PORT2,DIO_u8INPUT);

	DIO_u8WritePinDir(DIO_u8PIN24,DIO_u8INPUT);
	DIO_u8WritePinDir(DIO_u8PIN25,DIO_u8INPUT);
	DIO_u8WritePinDir(DIO_u8PIN26,DIO_u8INPUT);
	DIO_u8WritePinDir(DIO_u8PIN27,DIO_u8INPUT);
	DIO_u8WritePinDir(DIO_u8PIN28,DIO_u8INPUT);
	DIO_u8WritePinDir(DIO_u8PIN29,DIO_u8INPUT);

	DIO_u8WritePinDir(DIO_u8PIN30,DIO_u8OUTPUT);
	DIO_u8WritePinDir(DIO_u8PIN31,DIO_u8OUTPUT);

}
