#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

template <typename T> class Array
{
    private:
        T* ptr;
        int size;

    public:
        Array(T arr[], int s);
        void print();
};

template <typename T> Array<T> :: Array(T arr[], int s)
{
    ptr = new T(s);
    size = s;
    for(int i=0; i<size; i++)
    {
        ptr[i] = arr[i];
    }
}

template <typename T> void Array<T> :: print()
{
    for(int i=0; i<size; i++)
    {
        std::cout << *(ptr+i) << std::endl; 
    }
}

int main (int argc, char** argv)
{
    int arr[5] = {1,2,3,4,5};
    Array<int> a(arr,5);
    a.print();
    return EXIT_SUCCESS;
}
