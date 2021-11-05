#include "doc_tag.h"
#include "document.cpp"
#include "tag.cpp"


int main()
{
    list_doc L1;
	list_tag L2;
	createListDoc(L1);
	createListTag(L2);

	string i = "0";
	while (i != "10")
	{
		cout << "<-----------------------MENU----------------------->" << endl;
		cout << "1. Add new document" << endl;
		cout << "2. Add new tag" << endl;
		cout << "3. Find the most tags and least tags document" << endl;
		cout << "4. Show documents with its tags" << endl;
		cout << "5. Find document with only 2 tags" << endl;
		cout << "6. Find the most popular tag" << endl;
		cout << "7. Delete first document" << endl;
		cout << "8. Delete first tag" << endl;
		cout << "9. Add tag to document" << endl;
		cout << "10. Exit" << endl;
		cout << "<-------------------------------------------------->" << endl;
		cout << "choose between 1 - 10 : ";
		cin >> i;
		if (i == "1") {
			string title;
			cout << "Document Name: ";
			cin >> title;
			addressDoc node_Doc = allocate_Document(title);
			addDoc(L1, node_Doc);
			cout<<endl;
		}
		else if (i == "2") {
			string tag;
			cout << "Tag Name: ";
			cin >> tag;
			addressTag node_Tag = allocate_tag(tag);
			addTag(L2, node_Tag);
			cout<<endl;
		}
		else if (i == "3")
        {
            string most_tags_doc, least_tag_doc;
			findBiggestandSmallestDoc(L1, L2, most_tags_doc, least_tag_doc);
			if (L1.first != NULL)
            {
                cout << "The most tags document: "<<most_tags_doc<<endl;
                cout << "The least tags document: "<<least_tag_doc<<endl;
            }
            cout<<endl;
		}
		else if (i == "4") {
			printDocWithTag(L1, L2);
			cout<<endl;
		}
		else if (i == "5") {
            cout << "Document: ";
            findDocWith2Tag(L1, L2);
            cout<<endl;
		}
		else if (i == "6") {
            addressTag node_Tag = findPopularTag(L2, L1);
            if (node_Tag != NULL)
            {
                cout << "Most popular tag: "<<node_Tag->dataTag;
                cout<<endl;
                cout<<"List documents: ";
                addressDoc node_doc = L1.first;
                while (node_doc!= NULL)
                {
                    if (node_doc->nextTag == node_Tag || node_Tag->nextDoc == node_doc)
                    {
                        cout<<node_doc->dataDoc<<"  ";
                    }
                    node_doc = node_doc->nextDoc;
                }
            }
            cout<<endl;

        } else if (i == "7") {
            addressDoc node_Doc;
            del_doc(L1,L2,node_Doc);
			cout<<endl;
		}
		else if (i == "8") {
			addressTag node_Tag;
            deleteTag(L2,node_Tag);
			cout<<endl;
		}
		 else if (i == "9") {
            string title;
            string tag;
            cout << "Which tag you want to add to document?"<<endl;
            cout<<"Document: ";
            cin >> title;
            cout<<"Tag: ";
            cin>>tag;
            connect(L1,L2,tag,title);
            cout<<endl;
		}
	}
    return 0;
}
