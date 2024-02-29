#pragma once

// 6.1.2 The Struct chainNode, page 196/826

template <typename T>
struct chainNode
{
    // data members
    T element;
    chainNode<T>* next;

    // methods
    chainNode() {}
    chainNode(const T& element)
    {
        this->element = element;
    }
    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};