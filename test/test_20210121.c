#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// int bitcount(uint32_t x)
// {
//     int b;
//     for (b = 0; x != 0; x >>= 1)
//     {
//         if (x & 1)
//             ++b;
//     }

//     return b;
// }

uint32_t bitcount(uint32_t x)
{
    uint32_t count = 0;

    for (count = 0; x != 0; x >>= 1)
    {
        if (x & 1)
            count++;
    }

    return count;
}

static uint8_t count_next_bio_id(uint32_t id_flag)
{
    uint8_t count = 0;

    for (count = 0; id_flag != 0; id_flag >>= 1)
    {
        if (!(id_flag & 1))
        {
            break;
        }
        count++;
    }

    return count;
}

int main(void)
{
    uint32_t num = 0x00000000f;
    int result = 0;

    // result = bitcount(num);
    // printf("num = %d\n", num);
    // printf("result = %d\n", result);
    // num |= (0x01UL << 7);
    // result = bitcount(num);
    // printf("num = %d\n", num);
    // printf("result = %d\n", result);

    result = count_next_bio_id(num);
    printf("num = %d\n", num);
    printf("result = %d\n", result);

    return 0;
}