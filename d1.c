#include <stdio.h>
#include <stdlib.h>//підключення бібліотек
int main() {
    // Відкриття перших двох файлів для читання
    FILE* file1 = fopen("file1.txt", "r");
    FILE* file2 = fopen("file2.txt", "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }
    // Відкриття третього файлу для запису
    FILE* file3 = fopen("file3.txt", "w");
    if (file3 == NULL) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }
    int number1, number2;
    // Читання та запис значень по черзі до третього файлу
    while (fscanf(file1, "%d", &number1) == 1 && fscanf(file2, "%d", &number2) == 1) {
        fprintf(file3, "%d\n", number1);
        fprintf(file3, "%d\n", number2);
    }
    // Якщо один файл закінчився раніше, записуємо решту значень з іншого файлу
    while (fscanf(file1, "%d", &number1) == 1) {
        fprintf(file3, "%d\n", number1);
    }
    while (fscanf(file2, "%d", &number2) == 1) {
        fprintf(file3, "%d\n", number2);
    }
    // Закриття файлів
    fclose(file1);
    fclose(file2);
    fclose(file3);
    printf("Значення файлів записані до file3.txt.\n");
    return 0;//кінець програми
}

