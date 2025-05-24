#include <iostream>   
#include <cstring>     

// Загальний шаблон функції пошуку останнього індексу елемента, рівного ключу
template <typename T>
int findLastIndex(const T arr[], int size, const T& key) {
    int lastIndex = -1;           // Ініціалізуємо індекс останнього знайденого елемента -1 (означає "не знайдено")
    for (int i = 0; i < size; ++i) {  // Перебираємо всі елементи масиву від 0 до size-1
        if (arr[i] == key) {          // Якщо поточний елемент дорівнює ключу (порівняння оператором ==)
            lastIndex = i;            // Запам'ятовуємо індекс останнього знайденого елемента
        }
    }
    return lastIndex;             // Повертаємо індекс останнього знайденого елемента або -1, якщо не знайдено
}

// Спеціалізація функції для масиву рядків (тип const char*)
template <>
int findLastIndex<const char*>(const char* const arr[], int size, const char* const& key) {
    int lastIndex = -1;           // Ініціалізуємо індекс останнього знайденого елемента -1
    for (int i = 0; i < size; ++i) {  // Перебираємо всі рядки в масиві
        if (std::strcmp(arr[i], key) == 0) {  // Порівнюємо рядки за допомогою strcmp (повертає 0, якщо рівні)
            lastIndex = i;         // Запам'ятовуємо індекс останнього знайденого рядка
        }
    }
    return lastIndex;             // Повертаємо індекс або -1, якщо не знайдено
}

int main() {
    int arrInt[] = { 1, 3, 5, 3, 7, 3 };  // Масив цілих чисел
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);  // Обчислюємо розмір масиву (кількість елементів)
    int keyInt = 3;                     // Ключ для пошуку
    // Виводимо індекс останнього входження ключа у масиві цілих чисел
    std::cout << "Last index of " << keyInt << " in arrInt: "
        << findLastIndex(arrInt, sizeInt, keyInt) << std::endl;

    const char* arrStr[] = { "apple", "banana", "orange", "banana", "kiwi" };  // Масив C-рядків (масив вказівників)
    int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);  // Обчислюємо розмір масиву рядків
    const char* keyStr = "banana";           // Ключ (рядок) для пошуку
    // Виводимо індекс останнього входження ключа у масиві рядків
    std::cout << "Last index of \"" << keyStr << "\" in arrStr: "
        << findLastIndex(arrStr, sizeStr, keyStr) << std::endl;

    return 0;
}
