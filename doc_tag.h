#ifndef DOC_TAG_H_INCLUDED
#define DOC_TAG_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct nodeTag *addressTag;
typedef struct nodeDoc *addressDoc;

struct nodeTag
{
	string dataTag;
	addressTag nextTag;
	addressDoc nextDoc;

};

struct nodeDoc
{
	string dataDoc;
	addressDoc nextDoc;
	addressTag nextTag;
};

struct list_tag
{
	addressTag first,last;
};

struct list_doc
{
	addressDoc first,last;
};

void createListDoc(list_doc &L);
void addDoc(list_doc &L, addressDoc node_Doc);
void deleteDoc(list_doc &L, addressDoc &node_Doc);
addressDoc allocate_Document(string title);
addressDoc searchDoc(list_doc L, string title);
void createListTag(list_tag &L);
addressTag allocate_tag(string tag);
void addTag(list_tag &L, addressTag node_Tag);
void deleteTag(list_tag &L, addressTag &node_Tag);
addressTag searchTag(list_tag L, string tag);
addressTag findPopularTag(list_tag L1, list_doc L2);
void connect(list_doc &L1, list_tag &L2, string tag, string title);
void del_doc(list_doc &L1, list_tag &L2, addressDoc node_Doc);
void findBiggestandSmallestDoc(list_doc L1, list_tag L2, string &max_doc, string &min_doc);
void printDocWithTag(list_doc L1, list_tag L2);
void findDocWith2Tag(list_doc L1, list_tag L2);
void del_tag(list_doc &L1, list_tag &L2, addressTag node_Tag);

#endif // DOC_TAG_H_INCLUDED
