//
// Created by yejung on 19-1-24.
//

#include "Base64.h"
char Base64::base64_index_[INDEX_MAX_LEN] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

char Base64::FindIndex(char value) {
  for (int i = 0; i < INDEX_MAX_LEN; i++) {
    if (value == base64_index_[i]) {
      return i;
    }
  }
  return INDEX_ERROR;
}

int Base64::Base64_Encrypt(char* encrypt_str, const char* source_str, int len) {
  int idx = 0;
  int jdx = 0;
  while (idx < len) {
    encrypt_str[jdx++] = base64_index_[(source_str[idx] & 0xfc) >> 2];
    if (idx + 1 < len) {
      encrypt_str[jdx++] = base64_index_[(source_str[idx] & 0x03) << 4 | (source_str[idx + 1] & 0xf0) >> 4];
    } else {
      encrypt_str[jdx++] = base64_index_[(source_str[idx] & 0x03) << 4];
      encrypt_str[jdx++] = '=';
      encrypt_str[jdx++] = '=';
      break;
    }
    if (idx + 2 < len) {
      encrypt_str[jdx++] = base64_index_[(source_str[idx + 1] & 0x0f) << 2 | (source_str[idx + 2] & 0xc0) >> 6];
    } else {
      encrypt_str[jdx++] = base64_index_[(source_str[idx + 1] & 0x0f) << 2];
      encrypt_str[jdx++] = '=';
      break;
    }
    encrypt_str[jdx++] = base64_index_[source_str[idx + 2] & 0x3f];
    idx += 3;
  }
  encrypt_str[jdx++] = '\0';
  return 0;
}

int Base64::Base64_Decrypt(char* decrypt_str, const char* source_str) {
  size_t len = strlen(source_str);
  size_t idx = 0;
  size_t jdx = 0;
  while (idx < len) {
    decrypt_str[jdx++] = (char)(FindIndex(source_str[idx]) << 2 | (FindIndex(source_str[idx + 1]) & 0x30) >> 4);
    if (source_str[idx + 2] != '=') {
      decrypt_str[jdx++] = (char)((FindIndex(source_str[idx + 1]) & 0x0f) << 4 | (FindIndex(source_str[idx + 2]) & 0xfc) >> 2);
    } else {
      decrypt_str[jdx++] = (char)((FindIndex(source_str[idx + 1]) & 0x0f) << 4);
      break;
    }
    if (source_str[idx + 3] != '=') {
      decrypt_str[jdx++] = (char)((FindIndex(source_str[idx + 2]) & 0x03) << 6 | (FindIndex(source_str[idx + 3]) & 0xcf));
     } else {
      decrypt_str[jdx++] = (char)((FindIndex(source_str[idx + 2]) & 0x03) << 6);
      break;
    }
    idx += 4;
  }
  decrypt_str[jdx++] = '\0';
  return 0;
}