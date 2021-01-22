#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 14
#define uint16_t unsigned short int
#define uint8_t unsigned char

typedef struct
{
    uint16_t Head;
    uint8_t SourceID;
    uint8_t DestinationID;
    uint8_t Command;
    uint8_t Data[7];
    uint16_t Tail;
} FrameInfo_TypeDef;

unsigned char gFrameInfo[LEN];
unsigned char buffer[LEN];

int main(int argc, char *argv[])
{
    FrameInfo_TypeDef *sFrameInfo = (FrameInfo_TypeDef *)gFrameInfo;
    unsigned int i = 0;
    for (; i < LEN; i++)
    {
        buffer[i] = i;
    }
    memset(gFrameInfo, 0, LEN);
    memcpy(gFrameInfo, buffer, LEN);
    //	sFrmameInfo = (FrameInfo_TypeDef*)&gFrameInfo;
    for (i = 0; i < LEN; i++)
    {
        printf("gFrame[%d] = %d \r\n.", i, gFrameInfo[i]);
    }
    printf("sFrameInfo.Head = %d\r\n", sFrameInfo->Head);
    printf("sFrameInfo.SourceID = %d\r\n", sFrameInfo->SourceID);
    printf("sFrameInfo.DestinationID = %d\r\n", sFrameInfo->DestinationID);
    printf("sFrameInfo.Command = %d\r\n", sFrameInfo->Command);
    for (i = 0; i < 7; i++)
    {
        printf("sFrameInfo.Data[%d] = %d \r\n.", i, sFrameInfo->Data[i]);
    }
    printf("sFrameInfo.Tail = %d\r\n", sFrameInfo->Tail);
    printf("Hello C-Free!\n");
    return 0;
}