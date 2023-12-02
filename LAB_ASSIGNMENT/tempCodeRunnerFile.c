#include <openssl/sha.h>

void sha256Hash(const char* input, unsigned char* output) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(output, &sha256);
}
