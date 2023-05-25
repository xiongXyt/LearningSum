#include <iostream>
#include <string>

template<typename Type>
class List
{
public:
    typedef unsigned size_type;
public:
    List();
    void push_back(const Type& value);
    void push_front(const Type& value);
    Type& front() const;
    Type& back() const;
    size_type size() const;
    ~List();
private:
    struct DataType
    {
        Type Value;
        struct DataType* next;
    }head;
    struct DataType* end;
};

template<typename Type>
List<Type>::List()
{
    head.next = 0;
    end = &head;
    std::cout << "8888888888888888" << std::endl;
}

template<typename Type>
void List<Type>::push_back(const Type& value)
{
    DataType* tmp = new DataType;
    tmp->Value = value;
    tmp->next = 0;
    end->next = tmp;
    end = tmp;
}

template<typename Type>
void List<Type>::push_front(const Type& value)
{
    DataType* tmp = new DataType;
    tmp->Value = value;
    tmp->next = 0;
    tmp->next = head.next;
    head.next = tmp;
}

template<typename Type>
Type& List<Type>::front() const
{
    return head.next->Value;
}

template<typename Type>
Type& List<Type>::back() const
{
    return end->Value;
}

template<typename Type>
typename List<Type>::size_type List<Type>::size() const
{
    size_type iSize = 0;
    struct DataType* begin = &head;

    while (begin->next)
    {
        ++iSize;
    }

    return iSize;
}

template<typename Type>
List<Type>::~List()
{
    struct DataType* tmp = &head;

    while (tmp = tmp->next)
    {
        head.next = tmp->next;
        free(tmp);
        tmp = &head;
    }
}

int main()
{
    List<int> list;
    list.push_back(100);
    list.push_front(200);
    std::cout << list.front() << "/t" << list.back() << std::endl;

    system("pause");
    return 0;
}