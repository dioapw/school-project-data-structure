# The Final Project of The Data Structure Course

## Problem
Manage a multi-linked list that models documents, tags, and relationships between them. A document may have more than one tag and some documents may have some similar tags.
Your program must implement the list and all features listed below.
- Add a new document
- Add a new tag
- Add a relationship between a document and a tag
- Delete a certain document
- Delete a certain tag
- Show all documents; each with its tags
- Find the most popular tags and list all documents tagged with the most popular tag
- Find a document with the largest and smallest number of tags
- Given two tags, find documents having both tags or one of them

## Abstract Data Structure
```
Type addressTag : pointer to nodeTag
Type addressDoc: pointer to nodeDoc
 
Type nodeTag <
            dataTag : string
            nextTag : addressTag
            nextDoc : addressDoc
            >
Type nodeDoc<
            dataTag : string
            nextDoc : addressDoc
            nextTag : addressTag
            >
Type list_tag<
            AddressTag : first, last
            >
Type list_doc<
            addressDoc : first, last
            >
```

## List of Procedures and Functions

```
Procedure createListDoc(in/out L : list_doc)
Procedure addDoc(in/out L : list_doc, in node_doc : addressDoc)
Procedure deleteDoc(in/out L : list_doc, out node_doc : addressDoc) 
Function allocate_Document(in title : string) -> addressDoc
Function searchDoc(L : list_doc, title : string) -> addressDoc
Procedure createListTag(in/out L : list_tag)
Function allocate_tag(in tag : string) -> addressTag
Procedure addTag(in/out L : list_tag, in node_Tag :addressTag)
Procedure deleteTag(in/out L : list_tag, out node_Tag : addressTag)
Function searchTag(in L : list_tag, in tag : string) -> addressTag
Function findPopularTag(in L1: list_tag, in L2 : list_doc) -> addressTag
Procedure connect(in/out L1 : list_doc , in/out L2 : list_tag, tag : string, title :string)
Procedure del_doc(in/out L1 : list_doc , in/out L2 : list_tag, node_Doc : addressDoc)
Procedure findBiggestandSmallestDoc(in L1 : list_doc, in L2 : list_tag, out max_doc : string, out min_doc : string)
Procedure printDocWithTag(in L1 : list_doc, in L2 : list_tag)
Procedure findDocWith2Tag(in L1 : list_doc, in L2 : list_tag)
Procedure del_tag(in/out L1: list_doc, in/out L2 : list_tag, in node_Tag  : addressTag);
```

This project was built by Dio Aditya and Muhammad Ali Fikri.
