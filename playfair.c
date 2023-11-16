#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5


void initializeKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int k, i, j;
    char tempKey[26];
    int len = strlen(key);

    for (i = 0; i < len; i++) {
        tempKey[i] = toupper(key[i]);
    }


    int index = 0;
    for (i = 0; i < len; i++) {
        if (tempKey[i] == 'J') {
            continue; 
        }
        int found = 0;
        for (j = 0; j < index; j++) {
            if (tempKey[i] == tempKey[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            tempKey[index++] = tempKey[i];
        }
    }
    k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            keyTable[i][j] = tempKey[k++];
        }
    }
}

void findPosition(char ch, int *row, int *col, char keyTable[SIZE][SIZE]) {
    if (ch == 'J') {
        ch = 'I'; 
    }

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char ch1, char ch2, char keyTable[SIZE][SIZE]) {
    int row1, row2, col1, col2;
    findPosition(ch1, &row1, &col1, keyTable);
    findPosition(ch2, &row2, &col2, keyTable);

    if (row1 == row2) {
        col1 = (col1 + 1) % SIZE;
        col2 = (col2 + 1) % SIZE;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % SIZE;
        row2 = (row2 + 1) % SIZE;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c", keyTable[row1][col1], keyTable[row2][col2]);
}


void playfairCipher(char str[], char key[]) {
    char keyTable[SIZE][SIZE];

   
    initializeKeyTable(key, keyTable);

    int length = strlen(str);

    
    if (length % 2 != 0) {
        length++;
        str[length - 1] = 'X';
        str[length] = '\0';
    }

    for (int i = 0; i < length; i += 2) {
        encrypt(str[i], str[i + 1], keyTable);
    }
}

int main() {
    char key[SIZE * SIZE];
    char plaintext[100];

    printf("Enter the key for Playfair cipher: ");
    scanf("%s", key);

    printf("Enter the plaintext to be encrypted: ");
    scanf("%s", plaintext);

    printf("Encrypted Text: ");
    playfairCipher(plaintext, key);

    return 0;
}
