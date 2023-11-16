#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char message[], char key[]) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    for (int i = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            char encryptedChar = ((message[i] - base + key[i % keyLength] - 'A') % 26) + base;
            printf("%c", encryptedChar);
        } else {
            
            printf("%c", message[i]);
        }
    }
}

int main() {
    char message[1000];
    char key[100];

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Encrypted Message: ");
    vigenereEncrypt(message, key);

    return 0;
}
