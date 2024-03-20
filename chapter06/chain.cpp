
#include <sstream>

#include "chain.h"
#include "chainNode.h"
#include "illegalIndex.h"
#include "illegalParameterValue.h"

template <typename T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }

    firstNode = nullptr;
    listSize = 0;
}

template <typename T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;

    if(listSize == 0) {
        firstNode = nullptr;
        return;
    }

    chain<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);

    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;

    while(sourceNode != nullptr) {
        targetNode-> next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
}

template <typename T>
chain<T>::~chain()
{
    while(firstNode != nullptr) {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <typename T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);

    chainNode<T>* currentNode = firstNode;

    for(auto i = 0; i < theIndex; i++) {
        currentNode = currentNode->next;
    }

    return currentNode->element;
}

template <typename T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;

    int index = 0;

    while(currentNode != nullptr && currentNode->element != theElement) {
        currentNode = currentNode->next;
        index++;
    }

    if(currentNode == nullptr) {
        return -1;
    } else {
        return index;
    }
}

template <typename T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);

    chainNode<T>* deleteNode;
    if(theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T>* p = firstNode;
        for(auto i = 0; i < theIndex; i++) {
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;
    }

    listSize--;
    delete deleteNode;
}

template <typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if(theIndex == 0) {
        firstNode = new chainNode<T> (theElement, firstNode);
    } else {
        chainNode<T>* p = firstNode;
        for(auto i = 0; i < theIndex; i++) {
            p = p->next;
        }
        p->next = new chainNode<T>(theElement, p->next);
    }

    listSize++;
}

template <typename T>
void chain<T>::output(std::ostream& out) const
{
    for(auto currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next) {
        out << currentNode->element << "  ";
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}

