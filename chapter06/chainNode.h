#pragma once

// 6.1.2 The Chinese Edition, 131/561

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