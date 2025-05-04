#include <iostream>
#include <chrono>    
#include <utility>   
#include "MyVector.cpp"

// Для целей этого примера, мы будем считать, что MyVector и createMyVector
// определены где-то, где компилятор их найдет.
// В реальной лабораторной работе класс MyVector должен быть в .h файле,
// а его реализация (если не inline) в .cpp файле, и main.cpp должен включать .h файл.


int main() {
    const size_t vector_size = 1000000; // Размер вектора для теста

    // --- Тест производительности копирования ---
    std::cout << "Testing Copy Semantics...\n";
    MyVector original_copy_vector(vector_size);
    // Заполняем данными для более реалистичного сценария, хотя для теста копирования/перемещения важен только размер
    for (size_t i = 0; i < vector_size; ++i) {
        original_copy_vector[i] = i;
    }


    auto start_copy = std::chrono::high_resolution_clock::now();

    // Тест конструктора копирования
    MyVector copied_vector = original_copy_vector;

    // Тест оператора присваивания копированием
    MyVector another_copied_vector(1); // Создаем объект для присваивания
    another_copied_vector = original_copy_vector;


    auto end_copy = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_copy = end_copy - start_copy;
    std::cout << "Copy operations took: " << elapsed_copy.count() << " seconds.\n";

    // Проверка (опционально): убедимся, что копии имеют правильный размер
    std::cout << "Copied vector size: " << copied_vector.getSize() << "\n";
    std::cout << "Another copied vector size: " << another_copied_vector.getSize() << "\n";
    std::cout << "Original copy vector size after copy: " << original_copy_vector.getSize() << " (should be " << vector_size << ")\n"; // Исходный объект не должен измениться

    std::cout << "\n"; // Пустая строка для разделения

    // --- Тест производительности перемещения ---
    std::cout << "Testing Move Semantics...\n";

    // Тест move конструктора с использованием временного объекта
    // Предполагается, что функция createMyVector доступна
    auto start_move_ctor = std::chrono::high_resolution_clock::now();
    MyVector moved_vector1 = createMyVector(vector_size); // Здесь вызывается move конструктор
    auto end_move_ctor = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_move_ctor = end_move_ctor - start_move_ctor;
    std::cout << "Move constructor took: " << elapsed_move_ctor.count() << " seconds.\n";

    // Тест move оператора присваивания с использованием std::move
    MyVector original_move_vector(vector_size);
    // Заполняем данными для более реалистичного сценария
    for (size_t i = 0; i < vector_size; ++i) {
        original_move_vector[i] = i;
    }

    MyVector moved_vector2(1); // Создаем объект для присваивания

    auto start_move_assign = std::chrono::high_resolution_clock::now();
    moved_vector2 = std::move(original_move_vector); // Здесь вызывается move оператор присваивания
    auto end_move_assign = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_move_assign = end_move_assign - start_move_assign;
    std::cout << "Move assignment took: " << elapsed_move_assign.count() << " seconds.\n";


    // Проверка (опционально): убедимся, что перемещенные векторы имеют правильный размер, а исходные - пустой
    std::cout << "Moved vector 1 size: " << moved_vector1.getSize() << "\n"; // Должен быть vector_size
    std::cout << "Moved vector 2 size: " << moved_vector2.getSize() << "\n"; // Должен быть vector_size
    std::cout << "Original move vector size after move: " << original_move_vector.getSize() << " (should be 0)\n"; // Исходный объект должен быть в "перемещенном" состоянии

    return 0;
}

// Если определение класса MyVector и функции createMyVector не включены выше,
// они должны быть определены здесь или в другом включенном файле.
// Пример:
// class MyVector { /* ... */ };
// MyVector createMyVector(size_t s) { /* ... */ }

