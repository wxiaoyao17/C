#include <stdio.h>

typedef struct
{
    char a;
    char b;
    short c;
    short d;
    int e;
} Struct_a; // 排列方式：a[0]、b[1]、c[2-3]、d[4-5]、空2字节[6-7]、e[8-11]
// } __attribute__ ((__packed__)) Struct_a; // 紧凑排列，没有空的2个字节

static int array[10] = {0x123, 0x456, 0x789, 0xabc, 0xdef, 0x111, 0x222, 0x333, 0x444, 0x555};
// static char array[12] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c};

int main()
{
    Struct_a *s = (Struct_a *)array;

    printf("sizeof Struct_a = %d\n", sizeof(Struct_a));
    printf("s->a = %02x\n", s->a);
    printf("s->b = %02x\n", s->b);
    printf("s->c = %04x\n", s->c);
    printf("s->d = %04x\n", s->d);
    printf("s->e = %08x\n", s->e);

    printf("address of s->a = %08x\n", &(s->a));
    printf("address of s->b = %08x\n", &(s->b));
    printf("address of s->c = %08x\n", &(s->c));
    printf("address of s->d = %08x\n", &(s->d));
    printf("address of s->e = %08x\n", &(s->e));
    // printf("address of s = %08x\n", s);
    // printf("address of array = %08x\n", array);

    /* 修改结构体指针s的成员时，array也跟着改变，因为s指向array */
    s->a = 0x11;
    s->b = 0x22;
    s->c = 0x33;
    s->d = 0x44;
    s->e = 0x55;

    printf("s->a = %02x\n", s->a);
    printf("s->b = %02x\n", s->b);
    printf("s->c = %04x\n", s->c);
    printf("s->d = %04x\n", s->d);
    printf("s->e = %08x\n", s->e);

    for (char i = 0; i < 12; i++)
    {
        printf("array[%d] = %02x\n" , i, array[i]);
    }
}