//
// Created by yejung on 7/23/21.
//

#include <Base64/Base64.h>

int main() {
    char source_string[64] = "encrypt_demo";
    char encrypt_string[64] = {0};
    char decrypt_string[64] = {0};
    Base64::Base64_Encrypt(encrypt_string, source_string, strlen(source_string));
    printf("encrypt_string:%s\n", encrypt_string);


    Base64::Base64_Decrypt(decrypt_string, encrypt_string);
    printf("decrypt_string:%s\n", decrypt_string);

}