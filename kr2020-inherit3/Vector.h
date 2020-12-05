#ifndef _VECTOR_H
#define _VECTOR_H

#include <cassert>
#include <iostream>
using namespace std;


/*******************************************************************************
Шаблонный динамический массив.
    Требования к типу-параметру T:
    - default-конструктор (конструктор без параметров; желательно, максимально простой)
    - operator= (копирование присваиванием)
      (для объектов, состоящих только из базовых типов, он создается автоматически)

Это лишь "минимальный" функционал, достаточный для решения большинства стандартных задач.
    Возможно множество расширений:
    - Fill - заполнение "как в Array"
    - Reserve/ShrinkToFit - для оптимизации управления памятью
    - MoveTo - для переноса в другой массив (без переаллокации)
    - оптимизация вызовов конструкторов по умолчанию
    ... (и множество других развитий и модификаций)

*******************************************************************************/
template<typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


template<typename T>
class Vector {
public:
    ~Vector();
    Vector();
    Vector(const Vector&);
    const Vector& operator=(const Vector&);

    // методы доступа
    int Size() const;
    const T& operator[](int pos) const;
    T& operator[](int pos);

    // методы модификации
    void Add(const T&);
    void Insert(int pos, const T&);
    void Delete(int pos);
    void DeleteAll();
    void Sort(int l, int r);

protected:
    int count;      // количество элементов в массиве (явно добавленных)
    int bodySize;   // ёмкость буфера памяти (в штуках объектав T)
    T* body;        // указатель на буфер для хранения элементов
    int partition(int l, int r);
};

//******************************************************************************
//  Ниже - inline реализация методов шаблонного класса

template<typename T>
inline Vector<T>::~Vector()
{
    DeleteAll();
}

template<typename T>
inline Vector<T>::Vector() : count(0), bodySize(0), body(nullptr)
{
}

template<typename T>
inline Vector<T>::Vector(const Vector& src) : Vector()
{
    (*this) = src;
}

template<typename T>
inline const Vector<T>& Vector<T>::operator=(const Vector& src)
{
    DeleteAll(); // удаляем старое содержимое

    bodySize = src.bodySize;
    body = new T[bodySize]; // элементы в буфере создаются default-конструктором

    // count = 0  (уже) после вызова DeleteAll() выше
    for(;count < src.count; count++) {
        body[count] = src.body[count]; // здесь используется T::operator=(const T&)
    }
    return (*this);
}

template<typename T>
inline void Vector<T>::DeleteAll()
{
    delete[] body; // здесь будут вызваны деструкторы всех хранимых объектов
    body = nullptr;
    bodySize = count = 0;
}

template<typename T>
inline int Vector<T>::Size() const
{
    return count;
}

template<typename T>
inline T& Vector<T>::operator[](int i)
{
    assert( i >= 0 && i < count );
    return body[i];
}

template<typename T>
inline const T& Vector<T>::operator[](int i) const
{
    assert( i >= 0 && i < count );
    return body[i];
}

template<typename T>
inline void Vector<T>::Add(const T& val)
{
    // добавление элемента = вставка в конец массива
    Insert( count, val );
}

template<typename T>
inline void Vector<T>::Insert(int pos, const T& val)
{
    assert( pos >= 0 && pos <= count );
    assert( count <= bodySize );
    if(count == bodySize) {
        // стратегия роста : удвоение
        // +1 нужен для упрощения старта с нуля без лишних ветвлений
        int newSize = (1+bodySize) * 2;
        // элементы в буфере создаются с вызовом default-конструктора
        T* newBody = new T[newSize];
        // до pos копируем элементы на те же позиции
        for(int i = 0; i < pos; i++) {
            newBody[i] = body[i];
        }
        // начиная с pos копируем элементы на 1 место "вправо"
        for(int i = pos; i < count; i++) {
            newBody[i+1] = body[i];
        }
        // все данные скопированы, теперь нужно освободить старый буфер
        delete[] body;
        // переключаем параметры объекта только ПОСЛЕ всех манипуляций с данными
        body = newBody;
        bodySize = newSize;
    } else {
        // сдвигаем "хвост" массива "вправо" начиная с хвоста
        for(int i = count; i > pos; i--) {
            body[i] = body[i - 1];
        }
    }
    body[pos] = val;
    count++;
}

template<typename T>
inline void Vector<T>::Delete(int pos)
{
    assert( pos >= 0 && pos < count );
    for(int i = pos; i < count - 1; i++) {
        body[i] = body[i + 1];
    }
    count--;
    // теперь нужно "обнулить" последний (уже "отсутствующий" в массиве) элемент
    body[count] = T();
}

template<typename T>
inline int Vector<T>::partition(int l, int r) {
    T pivot = body[r];
    int i = l;
    for (int j = l; j < r; ++j) {
        if (body[j] < pivot) {
            Swap(body[i], body[j]);
            ++i;
        }
    }
    Swap(body[i], body[r]);
    return i;
}

template<typename T>
inline void Vector<T>::Sort(int l, int r) {
    if (l < r) {
        int p = partition(l, r);
        Sort(l, p-1);
        Sort(p+1, r);
    }
}

/*******************************************************************************
    operator вывода в стандартный поток
*******************************************************************************/

template<typename T>
inline ostream& operator<<(ostream& out, const Vector<T>& v)
{
    out << "{ ";
    for(int i = 0; i < v.Size(); i++) {
        out << v[i] << " ";
    }
    out << "}" << endl;
    return out;
}

#endif // _VECTOR_H
