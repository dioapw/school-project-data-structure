#include "doc_tag.h"

void createListDoc(list_doc &L)
{
   L.first = NULL;
   L.last = NULL;
}

addressDoc allocate_Document(string title)
{
    addressDoc node_Doc = new nodeDoc;
    node_Doc->dataDoc = title;
    node_Doc->nextDoc = NULL;
    node_Doc->nextTag =NULL;
    return node_Doc;
}

void addDoc(list_doc &L, addressDoc node_Doc)
{
     if (L.first == NULL)
    {
        L.first = node_Doc;
        L.last = node_Doc;
    }
    else {
            L.last->nextDoc = node_Doc;
            L.last = node_Doc;
    }
}

void del_doc(list_doc &L1, list_tag &L2, addressDoc node_Doc)
{
    if (L1.first != NULL)
    {
        addressTag node_Tag = L2.first;
        while (node_Tag != NULL) {
            if (node_Tag->nextDoc == L1.first || L1.first->nextTag == node_Tag) {
                node_Tag->nextDoc = NULL;
                L1.first->nextTag = NULL;
            }
            node_Tag = node_Tag->nextTag;
        }
        deleteDoc(L1,node_Doc);
    } else {
        cout<<"There's no document";
    }
}

void findBiggestandSmallestDoc(list_doc L1, list_tag L2, string &max_doc, string &min_doc)
{
    if (L1.first == NULL)
    {
        cout<<"There's no document";
    } else if (L1.first->nextDoc == NULL) {
        max_doc = L1.first->dataDoc;
        min_doc = L1.first->dataDoc;
    } else {
        int modus = 0;
        int maximum = 0;
        addressTag node_Tag = L2.first;
        addressDoc node_Doc = L1.first;
        while (node_Doc != NULL){
            while (node_Tag != NULL){
                 if (node_Tag->nextDoc == node_Doc || node_Doc->nextTag == node_Tag){
                    modus++;
                }
                node_Tag = node_Tag->nextTag;
            }
            if(maximum < modus){
                maximum = modus;
                max_doc = node_Doc->dataDoc;
            }else {
                min_doc = node_Doc->dataDoc;
            }
            node_Doc = node_Doc->nextDoc;
            node_Tag = L2.first;
            modus = 0;
        }
    }
}

void printDocWithTag(list_doc L1, list_tag L2)
{
     if (L1.first == NULL)
    {
        cout<<"There's no document";
    } else {
        addressDoc node_Doc = L1.first;
        addressTag node_Tag = L2.first;
        bool mark = false;
        while(node_Doc != NULL){
            cout<<"Document: "<<node_Doc->dataDoc<<" Tag: ";
            while (node_Tag != NULL){
                if (node_Tag->nextDoc == node_Doc || node_Doc->nextTag == node_Tag)
                {
                     mark = true;
                     cout<< node_Tag->dataTag<<" ";
                }
                node_Tag = node_Tag->nextTag;
            }
            if (mark == false)
            {
                cout<<"NULL";
            }
            cout<<endl;
            node_Doc = node_Doc->nextDoc;
            node_Tag = L2.first;
            mark = false;
        }
    }
}

void deleteDoc(list_doc &L, addressDoc &node_Doc)
{
    if (L.first == NULL)
    {
        cout<<"There's no document";
    } else if (L.first->nextDoc == NULL) {
		node_Doc = L.first;
		L.first = NULL;
		L.last = NULL;
	}
	else {
		node_Doc = L.first;
		L.first = node_Doc->nextDoc;
		node_Doc->nextDoc = NULL;
	}
}

addressDoc searchDoc(list_doc L, string title)
{
    if (L.first == NULL)
    {
        cout<<"There's no document";
    }
    else {
            addressDoc node_Doc = L.first;
            while ((node_Doc->dataDoc != title) && (node_Doc != NULL)) {
                    node_Doc = node_Doc->nextDoc;
            }
             if (node_Doc->dataDoc == title)
            {
                return node_Doc;
            }
    }
}

void findDocWith2Tag(list_doc L1, list_tag L2)
{
     if (L1.first != NULL)
    {
        bool mark = false;
        int modus = 0;
        addressDoc node_Doc = L1.first;
        addressTag node_Tag = L2.first;
        while ( node_Doc != NULL){
            while (node_Tag != NULL){
                 if (node_Tag->nextDoc == node_Doc || node_Doc->nextTag == node_Tag){
                    modus++;
                }
                node_Tag = node_Tag->nextTag;
            }
            if(modus == 2){
                cout<<node_Doc->dataDoc<<" ";
                mark = true;
            }
            node_Doc = node_Doc->nextDoc;
            node_Tag = L2.first;
            modus = 0;
        }
        if (mark == false) {
             cout<<"NULL";
        }
    }
}
