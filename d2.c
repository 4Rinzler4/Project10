#include <stdio.h>//підключення бібліотек
void removeIntegersFromBinaryFile(const char* filename, int count) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Помилка відкриття файлу.");
        return;
    }
    // Отримуємо розмір файлу
    fseek(file, 1000, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    // Перевірка, чи кількість даних для видалення не перевищує розмір файлу
    if (count * sizeof(int) > fileSize) {
        printf("Кількість даних для видалення перевищує розмір файлу.");
        fclose(file);
        return;
    }
    // Створення тимчасового файлу
    FILE* tempFile = fopen("temp.bin", "wb");
    if (tempFile == NULL) {
        printf("Помилка створення тимчасового файлу.");
        fclose(file);
        return;
    }
    // Копіювання даних з початку файлу до тимчасового файлу без видаляємих елементів
    int buffer;
    for (int i = 0; i < count; i++) {
        fread(&buffer, sizeof(int), 1, file);
    }
    while (fread(&buffer, sizeof(int), 1, file)) {
        fwrite(&buffer, sizeof(int), 1, tempFile);
    }
    // Закриття файлів
    fclose(file);
    fclose(tempFile);
    // Видалення початкового файлу
    remove(filename);
    // Перейменування тимчасового файлу на початкове ім'я
    rename("temp.bin", filename);
    printf("Дані успішно видалені з файлу.");
}
int main() {
    const char* filename = "data.bin";
    int count = 100;  // Кількість цілих даних для видалення

    removeIntegersFromBinaryFile(filename, count);

    return 0;//кінець програми 
}
