#include <NGenerator.h>
#include <fstream>



void CHTMLWriter::createHeaders(const String& title){
	outfile << "<head> \n";
	outfile << "<title> \n";
	outfile << //output title of page somehow
	outfile << "</title> \n";
	outfile << "</head> \n";
	
	//output page header
	outfile << "<h1> \n";
	outfile << "<body> \n";
	outfile //output title (probably same as before)
	outfile << "</h1> \n";
	
}

void CHTMLWriter::createTable(CDynList<String>& headers){
	outfile << "<table border='1' \n";
	outfile << "<tbody> \n";
	outfile << "<tr> \n";
	for(int i=0; i< header.length(); i++){
	outfile << "<th>" << *(cells.getPtr(i)) << "</th> \n";
	}
	outfile << "</tr>";
	
}

void CHTMLWriter::createTableRow(CDynList<String>& cells){
	
	outfile << "<tr> \n";
	for(int i=0; i< cells.length(); i++){
		outfile <<"<td>" << *(cells.getPtr(i)) << "</td> \n";
	}
	outfile << "</tr> \n";

}

void CHTMLWriter::closeTable(const String& tableFooter){
	outfile << "</table> \n";
}

void CHTMLWriter::createFooter(){
	outfile << "</body> \n";
	outfile << "</html> \n";
}

void CHTMLWriter::createLink(const String& link,const String& linkName){
	outfile << "<a href \"" << link << " \" >";
	outfile << linkName << "</a> \n";
}

void CHTMLWriter::encloseLink(const String& link, String& str){
	str.add(0,"\">");
	
	str.add(0 , link);
	str.add(0, "<a href=\"");
	str.add(str.length(), "</a>");
	
}

void CHTMLWriter::printParagraph(const String& paragraph){
	outfile << "<p>" << paragraph << "</p> \n"
}

void CHTMLWriter::printPreParagraph(const String& PreParagraph){
	outfile << "<pre>" << PreParagraph << "</pre>";
}

