#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30
#define LINE 1000

int haveDoubles(const char *word);

int main() {
    printf("Words with double consonants:\n\n");

    FILE *file;
    char word[MAX_WORD_LENGTH];
    char line[LINE];
    char uniqueWords[LINE][MAX_WORD_LENGTH];
    int count = 0;

    file = fopen("C:\\Users\\HP\\CLionProjects\\3rdcourse\\SP_lab1\\check.txt", "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        int i = 0;

        while (i < len) {
            int j = 0;

            while (i < len && isalpha(line[i])) {
                word[j] = tolower(line[i]);
                j++;
                i++;
            }

            word[j] = '\0';

            if (j > 0 && j <= MAX_WORD_LENGTH && haveDoubles(word)) {
                int isDuplicate = 0;
                for (int k = 0; k < count; k++) {
                    if (strcmp(uniqueWords[k], word) == 0) {
                        isDuplicate = 1;
                        break;
                    }
                }

                if (!isDuplicate) {
                    strcpy(uniqueWords[count], word);
                    printf("%s\n", word);
                    count++;
                }
            }

            while (i < len && !isalpha(line[i])) {
                i++;
            }
        }
    }

    fclose(file);

    return 0;
}

int haveDoubles(const char *word) {
    int l = strlen(word);
    for (int i = 0; i < l - 1; ++i) {
        char achar = tolower(word[i]);
        char bchar = tolower(word[i + 1]);

        if (isalpha(achar) && isalpha(bchar) &&
            strchr("aeiou", achar) == NULL &&
            strchr("aeiou", bchar) == NULL &&
            achar == bchar) {
            return 1;
        }
    }
    return 0;
}

