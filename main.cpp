#include <iostream>
#include <chrono>    
#include <utility>   
#include "MyVector.cpp"

// ��� ����� ����� �������, �� ����� �������, ��� MyVector � createMyVector
// ���������� ���-��, ��� ���������� �� ������.
// � �������� ������������ ������ ����� MyVector ������ ���� � .h �����,
// � ��� ���������� (���� �� inline) � .cpp �����, � main.cpp ������ �������� .h ����.


int main() {
    const size_t vector_size = 1000000; // ������ ������� ��� �����

    // --- ���� ������������������ ����������� ---
    std::cout << "Testing Copy Semantics...\n";
    MyVector original_copy_vector(vector_size);
    // ��������� ������� ��� ����� ������������� ��������, ���� ��� ����� �����������/����������� ����� ������ ������
    for (size_t i = 0; i < vector_size; ++i) {
        original_copy_vector[i] = i;
    }


    auto start_copy = std::chrono::high_resolution_clock::now();

    // ���� ������������ �����������
    MyVector copied_vector = original_copy_vector;

    // ���� ��������� ������������ ������������
    MyVector another_copied_vector(1); // ������� ������ ��� ������������
    another_copied_vector = original_copy_vector;


    auto end_copy = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_copy = end_copy - start_copy;
    std::cout << "Copy operations took: " << elapsed_copy.count() << " seconds.\n";

    // �������� (�����������): ��������, ��� ����� ����� ���������� ������
    std::cout << "Copied vector size: " << copied_vector.getSize() << "\n";
    std::cout << "Another copied vector size: " << another_copied_vector.getSize() << "\n";
    std::cout << "Original copy vector size after copy: " << original_copy_vector.getSize() << " (should be " << vector_size << ")\n"; // �������� ������ �� ������ ����������

    std::cout << "\n"; // ������ ������ ��� ����������

    // --- ���� ������������������ ����������� ---
    std::cout << "Testing Move Semantics...\n";

    // ���� move ������������ � �������������� ���������� �������
    // ��������������, ��� ������� createMyVector ��������
    auto start_move_ctor = std::chrono::high_resolution_clock::now();
    MyVector moved_vector1 = createMyVector(vector_size); // ����� ���������� move �����������
    auto end_move_ctor = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_move_ctor = end_move_ctor - start_move_ctor;
    std::cout << "Move constructor took: " << elapsed_move_ctor.count() << " seconds.\n";

    // ���� move ��������� ������������ � �������������� std::move
    MyVector original_move_vector(vector_size);
    // ��������� ������� ��� ����� ������������� ��������
    for (size_t i = 0; i < vector_size; ++i) {
        original_move_vector[i] = i;
    }

    MyVector moved_vector2(1); // ������� ������ ��� ������������

    auto start_move_assign = std::chrono::high_resolution_clock::now();
    moved_vector2 = std::move(original_move_vector); // ����� ���������� move �������� ������������
    auto end_move_assign = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_move_assign = end_move_assign - start_move_assign;
    std::cout << "Move assignment took: " << elapsed_move_assign.count() << " seconds.\n";


    // �������� (�����������): ��������, ��� ������������ ������� ����� ���������� ������, � �������� - ������
    std::cout << "Moved vector 1 size: " << moved_vector1.getSize() << "\n"; // ������ ���� vector_size
    std::cout << "Moved vector 2 size: " << moved_vector2.getSize() << "\n"; // ������ ���� vector_size
    std::cout << "Original move vector size after move: " << original_move_vector.getSize() << " (should be 0)\n"; // �������� ������ ������ ���� � "������������" ���������

    return 0;
}

// ���� ����������� ������ MyVector � ������� createMyVector �� �������� ����,
// ��� ������ ���� ���������� ����� ��� � ������ ���������� �����.
// ������:
// class MyVector { /* ... */ };
// MyVector createMyVector(size_t s) { /* ... */ }

