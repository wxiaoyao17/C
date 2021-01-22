#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// uint8_t g_value_1 = 0x12;
// uint8_t g_value_2 = 0x56;

// void set_buff(uint8_t *buff)
// {
//     buff[0] = 0x01;
//     buff[1] = 0x02;
//     buff[2] = 0x03;
// }

// void set_ptr(uint8_t **ptr)
// {
//     uint8_t *ptr_temp = malloc(sizeof(uint8_t) * 1);

//     ptr_temp = &g_value_2;

//     *ptr = ptr_temp;
// }

// 此程序很简单，仅仅打印一个Hello World的字符串。
int main(void)
{
    short id = 0x1234;
    int check = 0;
    // char string_id[5] = {0};
    char string_id[] = "ffff";
    uint8_t buff[3] = {0};
    int i = 0;
    uint8_t *ptr = malloc(sizeof(uint8_t) * 1);

    // itoa(id, string_id, 10);
    sprintf(string_id, "%x", id);
    printf("id:%x\n", id);
    printf("string_id:%s\n", string_id);
    // check = atoi(string_id);
    // printf("check:%x\n", check);

    printf("Hello World! \n");

    // set_buff(buff);
    // printf("buff:\n");
    // for (i = 0; i < sizeof(buff); i++)
    // {
    //     printf("0x%02x ", buff[i]);
    // }
    // printf("\n");

    // ptr = &g_value_1;
    // printf("&ptr: %x, ptr: %x, *ptr: %x\n", &ptr, ptr, *ptr);
    // set_ptr(&ptr);
    // printf("&ptr: %x, ptr: %x, *ptr: %x\n", &ptr, ptr, *ptr);

    return 0;
}