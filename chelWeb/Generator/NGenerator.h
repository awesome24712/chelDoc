#ifndef NGENERATOR
#define NGENERATOR

class HTMLOutput;
class TreeViewer;

class HTMLOutput{
	void createHeaders(const String& title);
	void createTable(const String& tableHeader);
	void createTableRows(const String& type, const String& value);
}

class TreeViewer{
	String getElement(const String& element);
	String getAttributeValue(const String& name);

}


#endif NGENERATOR