#pragma 

#include <ostream>

#include "chainNode.h"
#include "linearList.h"
#include "illegalIndex.h"

template <typename T>
class chain : public linearList<T>
{
public:
    // Constructor, Copy Constructor
    chain(int initialCapacity = 10);
    chain(const chain<T>&);

    // Destructor
    ~chain();

    bool empty() const
    {
        return listSize == 0;
    }

    int size() const
    {
        return listSize;
    }

    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    // template <typename T>
    class iterator 
    {
    public:
        iterator(chainNode<T>* theNode = nullptr)
        {
            node = theNode;
        }

        T& operator*() const
        {
            return node->element;
        }

        T* operator->() const
        {
            return &node->element;
        }

        iterator& operator++()
        {
            node = node->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            node = node->next;
            return old;
        }

        bool operator!=(const iterator right) const
        {
            return node != right.node;
        }

        bool operator==(const iterator right) const
        {
            return node == right.node;
        }

    protected:
        chainNode<T>* node;


    private:
    };

    iterator begin()
    {
        return iterator(firstNode);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    int listSize;

private:

};