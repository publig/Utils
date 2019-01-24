//
// Created by yejung on 19-1-24.
//

#ifndef BASE64_BASE64_H
#define BASE64_BASE64_H
#include <cstring>
#include <iostream>
using namespace std;
#define INDEX_MAX_LEN 64
#define INDEX_ERROR 255
class Base64 {
 public:
  static char base64_index_[64];
  static int Base64_Encrypt(char* encrypt_str, const char* source_str, int len);
  static int Base64_Decrypt(char* decrypt_str, const char* source_str);

 private:
 static char FindIndex(char value);
};

#endif //BASE64_BASE64_H
