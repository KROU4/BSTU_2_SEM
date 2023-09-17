#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 50
#include <stdio.h>
#include <string.h>
#include <iostream>
void zad9_1()
{
    FILE* fileA, * fileB;
    int num, prev_num = 0;
    fileA = fopen("fileA.txt", "r");
    fileB = fopen("fileB.txt", "w");
    if (fileA == NULL || fileB == NULL)
    {
        printf("Error opening files.");
        exit(1);
    }
    while (fscanf(fileA, "%d", &num) != EOF)
    {
        if (num != prev_num)
        {
            fprintf(fileB, "%d ", num);
            prev_num = num;
        }
    }
    fclose(fileA);
    fclose(fileB);
}

void zad9_2()
{
        FILE* f1, * f2;
        char str[MAX_LENGTH];
        int length;
        f1 = fopen("F1.txt", "w");
        if (f1 == NULL) {
            printf("Ошибка при создании файла F1\n");
        }
        fprintf(f1, "Первая строка\n");
        fprintf(f1, "Вторая строка, длиннее\n");
        fprintf(f1, "Третья строка, еще длиннее\n");
        fprintf(f1, "Четвертая строка, самая длинная\n");
        fclose(f1);
        length = 20;
        f1 = fopen("F1.txt", "r");
        f2 = fopen("F2.txt", "w");
        if (f1 == NULL || f2 == NULL) {
            printf("Ошибка при открытии файлов\n");
        }
        while (fgets(str, MAX_LENGTH, f1)) {
            if (strlen(str) > length) {
                fputs(str, f2);
            }
        }
        fclose(f1);
        fclose(f2);
        printf("Успешно скопировано в файл F2 строки длиннее %d символов\n", length);
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    zad9_2();
}