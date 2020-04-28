#ifndef _SEPC_H_
#define _SEPC_H_

#define MESH_DATA_EVENT_TYPE_PWM       		0xA2
#define MESH_DATA_EVENT_TYPE_PING      		0xFE
#define MESH_DATA_EVENT_TYPE_PING_RESPONSE 	0xFF
#define MESH_DATA_EVENT_TYPE_REMOTE_CMD    	0x11

#define UART_PACKET_HEAD					0x77

/*
typedef enum{
	UART_PACKET_TYPE_CMD = 1,
	UART_PACKET_TYPE_RESERVED,
	UART_PACKET_TYPE_RESPONSE,
	UART_PACKET_TYPE_EVENT,
}UartPacket_t;



typedef enum{
	ERR_NONE = 0,
	ERR_LENGTH_FAIL,
	ERR_INVALID_FAIL,
	ERR_FIFO_FULL
}ResponseError_t;

typedef enum {
	UART_CMD_OPCODE_SET_MESH_INFO = 1,
	UART_CMD_OPCODE_ENTER_ADDING_MODE,
	UART_CMD_OPCODE_ENTER_DELETING_MODE,
	UART_CMD_OPCODE_EXIT_CONFIG_MODE,
	UART_CMD_OPCODE_BRAODCAST_PWM_DATA,
	UART_CMD_OPCODE_ENTER_DEEP_SLEEP,
	UART_CMD_OPCODE_ENTER_OTA_MODE,
	UART_CMD_OPCODE_DELETE_ALL_IN_NET,
	UART_CMD_OPCODE_SEND_MESSAGE,
	UART_CMD_OPCODE_SHARE_SEND,
	UART_CMD_OPCODE_SHARE_RECEIVE,
	UART_CMD_OPCODE_LDS_TABLE,
	UART_CMD_OPCODE_NICERA_SQUARE,
	UART_CMD_OPCODE_SENSOR_COMMAND,
	UART_CMD_OPCODE_NICERA_HUMAN,
	UART_CMD_OPCODE_NICERA_LUMINANCE,
	UART_CMD_OPCODE_CHECK_ERROR
}UartOpcode_t;
*/

typedef enum{
	UARTIN_STATE_NONE = 0,
	UARTIN_STATE_READING,
	//UARTIN_STATE_CMD,
	UARTIN_STATE_MAX
}UartState_t;

typedef enum{
	Buffalo_Message_Type_Command,
	Buffalo_Message_Type_DongleStatus,
	Buffalo_Message_Type_Response,
	Buffalo_Message_Type_Event,
	Buffalo_Message_Type
}MessageType_t;

typedef enum{
	Buffalo_Command_Opcode_Set_Mesh_Info,
	Buffalo_Command_Opcode_Enter_Adding_Mode,
	Buffalo_Command_Opcode_Enter_Deleting_Mode,
	Buffalo_Command_Opcode_Exit_Config_Mode,
	Buffalo_Command_Opcode_Broadcast_PWM_Data,
	Buffalo_Command_Opcode_Enter_Deep_Sleep,
	Buffalo_Command_Opcode_Enter_OTA_Mode,
	Buffalo_Command_Opcode_Delete_All_In_Mode,
	Buffalo_Command_Opcode_Send_Message,
	Buffalo_Command_Opcode_Share_Send,
	Buffalo_Command_Opcode_Share_Received,
	Buffalo_Dongle_Status_Opcode_Check_Error,
}MessageOpcode_t;

typedef enum{
	Buffalo_Error_None,
	Buffalo_Error_Length,
	Buffalo_Error_Invalid,
	Buffalo_Error_FIFO_Full,
}BuffaloErrorCode_t;


typedef struct {
	UINT8 type;
	UINT8 len;
	UINT8 opcode;
	UINT8 parameter[64];
} tcmdBuffer;
typedef struct {
	UINT8 head;
	tcmdBuffer cmd;
	UINT8 checksum;
} tcmdPacket;
typedef struct {
	UINT8 state;
	tcmdPacket rx_buffer;
	UINT8 rx_len;
} tUartinState;
typedef struct {
	BD_ADDR addr;
	UINT32 virtual_addr;
} tPingResponse;


#endif

