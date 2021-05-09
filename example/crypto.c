#include <openssl/crypto.h>
#include <stdio.h>
#include <openssl/des.h>
int main(int argc, char const *argv[]){
    unsigned char data[8]= "hello!!";
    unsigned char encdata[8] = {0};
    unsigned char decdata[8]  = {0};

    
    const_DES_cblock key = "hello!!";
    DES_key_schedule schedual;
    
    DES_set_key(&key,&schedual);
    
    //加密
    DES_ecb_encrypt((const_DES_cblock*)data,(DES_cblock *)encdata,&schedual,DES_ENCRYPT);

    //解密
    DES_ecb_encrypt((const_DES_cblock*)encdata,(DES_cblock *)decdata,&schedual,DES_DECRYPT);

    printf("%s",decdata);

    return 0;
}
