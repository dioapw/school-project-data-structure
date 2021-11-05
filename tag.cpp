#include "doc_tag.h"

void createListTag(list_tag &L)
{
    L.first = NULL;
    L.last = NULL;
}

addressTag allocate_tag(string tag)
{
    addressTag node_Tag = new nodeTag;
    node_Tag->dataTag = tag;
    node_Tag->nextTag = NULL;
    node_Tag->nextDoc = NULL;
    return node_Tag;
}

void addTag(list_tag &L, addressTag node_Tag)
{
    if (L.first == NULL)
    {
        L.first = node_Tag;
        L.last = node_Tag;
    }
    else {
            L.last->nextTag = node_Tag;
            L.last = node_Tag;
    }

}

void deleteTag(list_tag &L, addressTag &node_Tag)
{
    if (L.first == 0) {
		cout << "There's no Tag";
	}
	else if (L.first->nextTag == 0) {
		node_Tag = L.first;
		L.first = 0;
		L.last = 0;
	}
	else {
		node_Tag = L.first;
		L.first = node_Tag->nextTag;
		node_Tag->nextTag = NULL;
	}
}

void del_tag(list_doc &L1, list_tag &L2, addressTag node_Tag)
{
    if (L2.first != NULL)
    {
        addressDoc node_Doc = L1.first;
        while (node_Doc != NULL) {
            if (node_Doc->nextTag == L2.first || L2.first->nextDoc == node_Doc) {
                node_Doc->nextTag = NULL;
                L2.first->nextDoc = NULL;
            }
            node_Doc = node_Doc->nextDoc;
        }
        deleteTag(L2,node_Tag);
    } else {
        cout<<"There's no tag";
    }
}

addressTag findPopularTag(list_tag L1, list_doc L2)
{
    if ((L1.first != NULL) && (L2.first!= NULL))
    {
        addressTag popularTag = NULL;
        int modus = 0;
        int maximum = 0;
        addressTag node_Tag = L1.first;
        addressDoc node_Doc = L2.first;
        while (node_Tag != NULL){
            while (node_Doc != NULL){
                 if (node_Doc->nextTag == node_Tag || node_Tag->nextDoc == node_Doc ) {
                    modus++;
                }
                node_Doc = node_Doc->nextDoc;
            }
            if(maximum < modus){
                maximum = modus;
                popularTag = node_Tag;
            }
            node_Tag = node_Tag->nextTag;
            node_Doc = L2.first;
            modus = 0;
        }
         return popularTag;
    }
    else {
        cout<<"Not found";
    }
}

addressTag searchTag(list_tag L, string tag)
{
     if (L.first == NULL) {
		cout << "There's no Tag";
	}
	else {
            addressTag node_Tag= L.first;
            while ((node_Tag->dataTag != tag) && (node_Tag != 0)) {
                    node_Tag = node_Tag->nextTag;
            }
             if (node_Tag->dataTag == tag)
            {
                return node_Tag;
            }
	}
}

void connect(list_doc &L1, list_tag &L2, string tag, string title)
{
    addressDoc node_Doc = searchDoc(L1,title);
    addressTag node_Tag = searchTag(L2, tag);
    if ((node_Tag != NULL) && (node_Doc!= NULL))
    {
        if (node_Tag->nextDoc == NULL)
        {
             node_Tag->nextDoc = node_Doc;
        } else {
            node_Doc->nextTag = node_Tag;
        }
	} else {
        cout<<"Not found";
	}
}
