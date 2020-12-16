#include <stdio.h>

unsigned short checksum()
{
    unsigned short data[10];
    printf("Enter the IP header in 16 bit word format\n");
    for(int i=0;i<10;i++)
    scanf("%x",&data[i]);
    unsigned short sum=0;
    for(int i=0;i<10;i++)
    {
        if (i==5) continue;
        sum+= data[i];
        while(sum>>16)
        {
            sum= (sum & 0xFFFF) + sum>>16;
        }
    }
    return ~sum;
}

int main()
{
    unsigned short result1, result2;
    printf("Sender\n");
    result1= checksum();
    printf("Computed checksum at sender %x\n",result1);
    printf("Reciever\n");
    result2=checksum();
    printf("Computed checksum at reciever %x\n",result2);
    if(result1==result2)
        printf("No error\n");
    else
        printf("Error detected!!!!\n");
    return 0;
}