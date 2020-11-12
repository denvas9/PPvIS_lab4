// ppvis4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/////////////////////////////////////////////////////////////////////////////////////// BOZO Sort + Merge Sort /////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
#include <time.h>
#include "Car.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////// Пользовательские функции для сравнения /////////////////////////////////////////////////////////////////////
template < class Iter >
bool ot_mensh_k_bolsh_it(Iter cmp1, Iter cmp2)
{
    return *cmp1 <= *cmp2;
}
template < class Iter >
bool ot_bolsh_k_mensh_it(Iter cmp1, Iter cmp2)
{
    return *cmp1 >= *cmp2;
}

template < class type >
bool ot_mensh_k_bolsh(type cmp1, type cmp2)
{
    return cmp1 <= cmp2;
}
template < class type >
bool ot_bolsh_k_mensh(type cmp1, type cmp2)
{
    return cmp1 >= cmp2;
}

///////////////////////////////////////////////////////////////////////////////////////// MergeSort ///////////////////////////////////////////////////////////////////////////////////////

template < class type >
void merging(type *array_input, int left, int middle, int right, bool(*comp) (type, type))
{
    int left_part_size = middle - left + 1;
    int right_part_size = right - middle;

    vector<type> Left_part(left_part_size), Right_part(right_part_size);

    for (int left_ind = 0; left_ind < left_part_size; left_ind++)
        Left_part[left_ind] = array_input[left + left_ind];
    for (int right_ind = 0; right_ind < right_part_size; right_ind++)
        Right_part[right_ind] = array_input[middle + 1 + right_ind];

    int left_ind = 0;
    int right_ind = 0;
    int ind_merged = left;

    while (left_ind < left_part_size && right_ind < right_part_size)
    {
        if (comp(Left_part[left_ind],Right_part[right_ind]))
        {
            array_input[ind_merged] = Left_part[left_ind];
            left_ind++;
        }
        else
        {
            array_input[ind_merged] = Right_part[right_ind];
            right_ind++;
        }
        ind_merged++;
    }

    while (left_ind < left_part_size)
    {
        array_input[ind_merged] = Left_part[left_ind];
        left_ind++;
        ind_merged++;
    }
    while (right_ind < right_part_size)
    {
        array_input[ind_merged] = Right_part[right_ind];
        right_ind++;
        ind_merged++;
    }
}
template < class type >
void mergeSort(type *array_input, int left, int right, bool (*comp) (type, type))
{
    if (left < right)
    {

        int middle = left + (right - left) / 2;

        mergeSort(array_input, left, middle, comp);
        mergeSort(array_input, middle + 1, right, comp);

        merging(array_input, left, middle, right, comp);
    }
}

template < class type >
void merging(vector<type>& input_vector, int left, int middle, int right, bool(*comp) (type, type))
{
    int left_part_size = middle - left + 1;
    int right_part_size = right - middle;

    vector<type> Left_part(left_part_size), Right_part(right_part_size);

    for (int left_ind = 0; left_ind < left_part_size; left_ind++)
        Left_part[left_ind] = input_vector[left + left_ind];
    for (int right_ind = 0; right_ind < right_part_size; right_ind++)
        Right_part[right_ind] = input_vector[middle + 1 + right_ind];

    int left_ind = 0;
    int right_ind = 0;
    int ind_merged = left;

    while (left_ind < left_part_size && right_ind < right_part_size)
    {
        if (comp(Left_part[left_ind], Right_part[right_ind]))
        {
            input_vector[ind_merged] = Left_part[left_ind];
            left_ind++;
        }
        else
        {
            input_vector[ind_merged] = Right_part[right_ind];
            right_ind++;
        }
        ind_merged++;
    }

    while (left_ind < left_part_size)
    {
        input_vector[ind_merged] = Left_part[left_ind];
        left_ind++;
        ind_merged++;
    }

    while (right_ind < right_part_size)
    {
        input_vector[ind_merged] = Right_part[right_ind];
        right_ind++;
        ind_merged++;
    }
}
template < class type >
void mergeSort(vector<type>& input_vector, int left, int right, bool (*comp) (type, type))
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(input_vector, left, middle, comp);
        mergeSort(input_vector, middle + 1, right, comp);

        merging(input_vector, left, middle, right, comp);
    }
}

/////////////////////////////////////////////////////////////////////////////////////// BozoSort ///////////////////////////////////////////////////////////////////////////////////////
template < class Iter >
bool isSorted(Iter first, Iter last, bool (*comp) (Iter, Iter)) 
{
        for (auto iterat = first; iterat !=last-1; ++iterat) 
        {
                if ( !( comp(iterat,iterat+1) ) )
                {
                        return false;
                }
        }
        return true;
}
template < class Iter >
void BozoSort(Iter first, Iter last, int size, bool (*comp) (Iter, Iter)) {

    if (distance(first,last)<=1)
    {
        cout << "error" << endl;
        return;
    }
        srand(time(NULL));
        
        while (!isSorted(first, last, comp)) 
        {
            auto iter1 = first+(rand() % size);
            auto iter2 = first+(rand() % size);

            swap(*iter1, *iter2);
        }
    
}

/////////////////////////////////////////////////////////////////////////////////////// Тестовая часть ///////////////////////////////////////////////////////////////////////////////////////

int main() {
    int merge_int_array[]{ 4, 6, 5, 12, 5, 12, 7, 9, 11 };
    double merge_double_array[]{ 1.31, 11.0, 12.2999, 32.1, 2.0501, 33.17, 33.5, 12.63, 7.42 };
    Car merge_car_array[]{
        Car(1000, "UAZ"),
        Car(5000, "Volga"),
        Car(1500, "Buhanka"),
        Car(3000, "Lada Kalina"),
        Car(45000, "Ford"),
        Car(16000, "Toyota"),
        Car(20000, "GAZ Tigr"),
        Car(120000, "Falcatus"),
        Car(10000, "Humvee")
    };


    cout << "MergeSort for arrays: " << endl;
    mergeSort(merge_int_array, 0, 8, ot_bolsh_k_mensh);
    mergeSort(merge_double_array, 0, 8, ot_bolsh_k_mensh);
    mergeSort(merge_car_array, 0, 8, ot_bolsh_k_mensh);

    for (int i = 0; i < 9; i++)
        cout << merge_int_array[i] << ' ';
    cout << endl;
    for (int i = 0; i < 9; i++)
        cout << merge_double_array[i] << ' ';
    cout << endl;
    for (int i = 0; i < 9; i++)
        cout << "Object N"<< i+1 << " Name: " << merge_car_array[i].get_Name() << "; Cost: " << merge_car_array[i].get_cost() << ";\n";
    cout << endl;


    int  bozo_int_array[]{ 1, 3, 4, 3, 8 };
    double bozo_double_array[]{ 1.3, 1.0, 3.5, 12.3, 7.2 };
    Car bozo_car_array[]{
        Car(1000, "UAZ"),
        Car(1500, "Buhanka"),
        Car(3000, "Lada Kalina"),
        Car(120000, "Falcatus"),
        Car(10000, "Humvee")
    };

    cout << "BozoSort for arrays: " << endl;
    BozoSort(bozo_car_array, bozo_car_array + 5, 5, ot_bolsh_k_mensh_it);
    BozoSort(bozo_int_array, bozo_int_array + 5, 5, ot_bolsh_k_mensh_it);
    BozoSort(bozo_double_array, bozo_double_array + 5, 5, ot_bolsh_k_mensh_it);


    for (int i = 0; i < 5; i++)
        cout << bozo_int_array[i] << ' ';
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << bozo_double_array[i] << ' ';
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << "Object N" << i + 1 << " Name: " << bozo_car_array[i].get_Name() << "; Cost: " << bozo_car_array[i].get_cost() << ";\n";
    cout << endl;

    vector<int> merge_int_vector{ 1, 3, 2, 9, 4, 3 };
    vector<double> merge_double_vector{ 1.3, 1.0, 2.001, 3.17, 3.5, 12.3 };
    vector<Car> merge_car_vector
    {
        Car(1000, "UAZ"),
        Car(5000, "Volga"),
        Car(1500, "Buhanka"),
        Car(3000, "Lada Kalina"),
        Car(20000, "GAZ Tigr"),
        Car(10000, "Humvee")
    };

    cout << "MergeSort for vectors: " << endl;
    mergeSort(merge_car_vector, 0, merge_car_vector.size() - 1, ot_mensh_k_bolsh);
    mergeSort(merge_int_vector, 0, merge_int_vector.size() -1, ot_mensh_k_bolsh);
    mergeSort(merge_double_vector, 0, merge_double_vector.size() - 1, ot_mensh_k_bolsh);

    for (int i = 0; i < merge_int_vector.size(); i++)
        cout << merge_int_vector[i] << ' ';
    cout << endl;
    for (int i = 0; i < merge_double_vector.size(); i++)
        cout << merge_double_vector[i] << ' ';
    cout << endl;
    for (int i = 0; i < merge_car_vector.size(); i++)
        cout << "Object N" << i + 1 << " Name: " << merge_car_vector[i].get_Name() << "; Cost: " << merge_car_vector[i].get_cost() << ";\n";
    cout << endl;

    vector<int> bozo_int_vector{ 1, 3, 2, 9, 4, 3 };
    vector<double> bozo_double_vector{ 1.3, 1.0, 2.001, 3.17, 3.5, 12.3 };
    vector<Car> bozo_car_vector
    {
        Car(1000, "UAZ"),
        Car(5000, "Volga"),
        Car(1500, "Buhanka"),
        Car(3000, "Lada Kalina"),
        Car(20000, "GAZ Tigr"),
        Car(10000, "Humvee")
    };
    cout << "BozoSort for vectors: " << endl;
    BozoSort(bozo_car_vector.begin(), bozo_car_vector.end(), bozo_car_vector.size(), ot_bolsh_k_mensh_it);
    BozoSort(bozo_int_vector.begin(), bozo_int_vector.end(), bozo_int_vector.size(), ot_bolsh_k_mensh_it);
    BozoSort(bozo_double_vector.begin(), bozo_double_vector.end(), bozo_double_vector.size(), ot_bolsh_k_mensh_it);

    for (int i = 0; i < bozo_int_vector.size(); i++)
        cout << bozo_int_vector[i] << ' ';
    cout << endl;
    for (int i = 0; i < bozo_double_vector.size(); i++)
        cout << bozo_double_vector[i] << ' ';
    cout << endl;
    for (int i = 0; i < bozo_car_vector.size(); i++)
        cout << "Object N" << i + 1 << " Name: " << bozo_car_vector[i].get_Name() << "; Cost: " << bozo_car_vector[i].get_cost() << ";\n";
    cout << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
