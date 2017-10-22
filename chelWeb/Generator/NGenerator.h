#ifndef NGENERATOR
#define NGENERATOR
#include <fstream>

class CHTMLWriter;
class TreeViewer;

class CHTMLWriter{
	
private:
	CHTMLWriter(); //constructor declaration
	~CHTMLWriter(); //destructor declaration
	
	ofstream outfile;
	
	CHTMLWriter(outputFileName){
		outfile.open(outputFileName);
	}
	
	~CHTMLWriter(){
		outfile.close();
	}

	void createHeaders(const String& title);
	void createTable(const String& tableHeader);
	void createTableRows(const String& type, const String& value);
	void closeTable(const String& tableFooter);
	void createFooter();
	void createLink(const String& link, const String& linkName);
	void printParagraph(const String& paragraph);
	void printPreParagraph(const String& PreParagraph);
}

class TreeViewer{
	String getElement(const String& element);
	String getAttributeValue(const String& name);

}


#endif NGENERATOR