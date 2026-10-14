#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T>
class Array
{
private:
    T *_head;
    size_t _size;

public:
    Array() : _head(NULL), _size(0)
    {
    }
    Array(unsigned int n) : _head(new T[n]), _size(n)
    {
    }
    Array(const Array &ref) : _head(new T[ref._size]), _size(ref._size)
    {
        for (size_t i = 0; i < _size; i++)
        {
            this->_head[i] = ref._head[i];
        }
    }
    ~Array()
    {
        delete[] _head;
    }
    Array<T> &operator=(const Array &ref)
    {
        if (this != &ref)
        {
            T *temp = new T[ref._size];
            for (unsigned int i = 0; i < ref._size; i++)
                temp[i] = ref._head[i];
            delete[] _head;
            _head = temp;
            _size = ref._size;
        }
        return *this;
    }

    T &operator[](size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("OUT OF RANGE array index");
        }
        return _head[index];
    }

    const T &operator[](size_t index) const
    {
        return _head[index];
    }

    size_t size() const
    {
        return _size;
    }
};

#endif
