#include "visitedlist.h"

VisitedNode::VisitedNode(){
    this->id = 0;
    this->visited = false;
    this->nxt = nullptr;
}

VisitedNode::VisitedNode(int id){
    this->id = id;
    this->visited = false;
    this->nxt = nullptr;
}

VisitedList::VisitedList() { first = nullptr; }

void VisitedList::add(int id){
    VisitedNode* ptr = this->first;
    if (first == nullptr)
        first = new VisitedNode(id);
    else {
        while(ptr->nxt != nullptr)
            ptr = ptr->nxt;
        ptr->nxt = new VisitedNode(id);
    }
}

VisitedNode* VisitedList::getFirst(){
    VisitedNode* ptr = first;
    while (ptr != nullptr){
        if (ptr->visited == false)
            return ptr;
        ptr = ptr->nxt;
    }
    return nullptr;
}

bool VisitedList::isComplete(){
    VisitedNode* ptr = this->first;
    while (ptr != nullptr){
        if (ptr->visited == false)
            return false;
        ptr = ptr->nxt;
    }
    return true;
}

bool VisitedList::isHere(int id){
    VisitedNode* ptr = this->first;
    while (ptr != nullptr){
        if (ptr->id == id)
            return true;
        ptr = ptr->nxt;
    }
    return false;
}

void VisitedList::setVisited(int id){
    VisitedNode* ptr = this->first;
    while (ptr != nullptr){
        if (ptr->id == id){
            ptr->visited = true;
            break;
        }
        ptr = ptr->nxt;
    }
}
