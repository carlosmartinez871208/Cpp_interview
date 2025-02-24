#include <iostream>
#include <cstring>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class String
{
    private:
        char* s;
        int size;
    public:
        String(const char* str = nullptr);
        ~String(){delete[] s;}
        String (const String&); /* Copy constructor */
        void print(){std::cout << s << std::endl;}
        void change (const char*);
};

String::String (const char* str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s,str);
}

String::String (const String& old_str)
{
    size = old_str.size;
    s = new char[size+1];
    strcpy(s,old_str.s);
}

void String::change(const char* str)
{
    delete[] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s,str);
}

int main (int argc, char** argv)
{
    String str1{"HelloImCarlos"};
    String str2 = str1;
    str1.print();
    str2.print();
    str2.change("HiImNinmah");
    str1.print();
    str2.print();
    return EXIT_SUCCESS;
}