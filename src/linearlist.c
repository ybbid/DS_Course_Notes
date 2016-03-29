#include "linearlist.h"

// Static Sequenced List --SSList

int initSSList(SSList* list) {
    if (!list)
        return -1;
    list->length = 0;
    return 0;
}

int destroySSList(SSList* list) {
    if (!list)
        return -1;
    list->length = 0;
    return 0;
}

int clearSSList(SSList* list) {
    if (!list)
        return -1;
    list->length = 0;
    return 0;
}

int ifSSListIsEmpty(SSList list) {
    return !list.length;
}

int16_t getLengthOfSSList(SSList list) {
    return list.length;
}

listData getSSListElemAtIndex(SSList list, int16_t index) {
    if (index >= 1 && index <= list.length)
        return list.data[index - 1];
    else
        return -1;
}

SSLMultiReVal locateSSListElem(SSList list, listData elem) {
    SSLMultiReVal retVal;
    int16_t temp[SSLSize] = {0};
    memcpy(retVal.returnValue, temp, sizeof(retVal.returnValue));
    int16_t counter = 0;
    for (int i = 0; i < SSLSize; ++i) {
        if (list.data[i] == elem) {
            retVal.returnValue[counter] = (int16_t) (i + 1);
            ++counter;
        }
    }
    return retVal;
}

int ifElemIsInSSList(SSList list, listData elem) {
    int16_t i = 0;
    int found = 0;
    while (i < list.length && !found) {
        if (list.data[i] != elem)
            ++i;
        else
            found = 1;
    }
    return found;
}

int16_t getSSListNextElemIndex(SSList list, listData elem) {
    int16_t i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i < list.length - 1)
        return (int16_t) (i + 1);
    else
        return -1;
}

int16_t getSSListPrevElemIndex(SSList list, listData elem) {
    int16_t i = 0;
    while (i < list.length && list.data[i] != elem)
        ++i;
    if (i > 0 && i < list.length)
        return (int16_t) (i - 1);
    else
        return -1;
}

int insertSSListElemAfterIndex(SSList* list, int16_t index, listData elem) {
    if (!list || index < 1 || index > list->length + 1 ||
        list->length == SSLSize)
        return 0;
    else {
        for (int16_t i = list->length; i > index; --i)
            list->data[i] = list->data[i - 1];
        list->data[index + 1] = elem;
        ++list->length;
        return -1;
    }
}

int deleteSSListElemAtIndex(SSList* list, int16_t index) {
    if (!list || index < 1 || index > list->length + 1)
        return 0;
    else {
        for (int16_t i = (int16_t) (index - 1); i < list->length; ++i)
            list->data[i] = list->data[i + 1];
        --list->length;
        return -1;
    }
}

// Dynamic Sequenced List --DSList

int initDSList(DSList* list) {
    if (!list)
        return -1;
    list->data = (listData*) malloc(DSLInitSize * sizeof(listData));
    if (!list->data)
        return -1;
    list->length = 0;
    list->size = DSLInitSize;
    return 0;
}

int destroyDSList(DSList* list) {
    if (!list)
        return -1;
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->size = 0;
    return 0;
}

int clearDSList(DSList* list) {
    if (!list)
        return -1;
    list->length = 0;
    return 0;
}

int ifDSListIsEmpty(DSList list) {
    return (int) !list.length;
}


int16_t getLengthOfDSList(DSList list) {
    return list.length;
}

listData getDSListElemAtIndex(DSList list, int16_t index) {
    if (index >= 1 && index <= list.length)
        return list.data[index-1];
    else
        return -1;
}

/*
SLLSpace initSLLSpace() {
    SLLSpace temp;
    temp.availHead = 0;
    for (int16_t i = 0; i < SLLSize - 1; ++i)
        temp.nodes[i].next = (int16_t) (i + 1);
    temp.nodes[SLLSize - 1].next = -1;
    return temp;
}

int initSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    if (space->availHead != -1) {
        *head = space->availHead;
        space->availHead = space->nodes[space->availHead].next;
    }
    else
        return -1;
    space->nodes[(size_t) head].next = -1;
    return 0;
}

int destroySLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
    space->nodes[cursor].next = space->availHead;
    space->availHead = *head;
    *head = -1;
    return 0;
}

int clearSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
    space->nodes[cursor].next = space->availHead;
    space->availHead = space->nodes[*head].next;
    space->nodes[*head].next = -1;
    return 0;
}

int ifSLListHIsEmpty(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    return (space->nodes[*head].next == -1);
}

int16_t getLengthOfSLListH(SLLSpace* space, int16_t* head) {
    if (!space || !head)
        return -1;
    int16_t cursor = *head, counter = 0;
    while (space->nodes[cursor].next != -1)
        cursor = space->nodes[cursor].next;
}

listData getElementAtIndex(SLLSpace* space, int16_t head, int16_t index) {
    if (!space || head == -1 || index < 1)
        return 0;

}
*/
