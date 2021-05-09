#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>
void md5hexToString(unsigned char *md,char *result){
    // char tmp[3];
    for (size_t i = 0; i <= 15; i++){
        sprintf(result+i*2,"%02x",md[i]);
    }

    return;

}
int main(int argc, char const *argv[])
{
    unsigned char md[16] = {0};
    char result[33] = {0};
    // 方式1
    MD5_CTX c;
    MD5_Init(&c);
    MD5_Update(&c,"helloworld",10);
    MD5_Update(&c,"helloworld",10);
    MD5_Update(&c,"helloworld",10);
    MD5_Final(md,&c);

    //方式2
    // MD5("helloworld",10,md);

    md5hexToString(md,result);

    printf("%s",result);
    
    
    return 0;
}
