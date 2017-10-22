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

void CHTMLWriter::createTable((const String& tableHeader, outfile){
	outfile << "<table border='1' \n";
	outfile << "<tbody> \n";
	outfile << "<tr> \n";
	outfile << "<th>" << tableHeader << "</th> \n";
	outfile << "<th> Value </th> \n"; //might want to change table headers
	outfile << "</tr>";
	
}

void CHTMLWriter::createTableRows(const String& type, const String& value){
	outfile <<"<td>" << type << "</td> \n";
	outfile <<"<td>" << value << "</td> \n";

}

void CHTMLWriter::closeTable(const String& tableFooter){
	outfile << "</table> \n";
}

void CHTMLWriter::createFooter(){
	outfile << "</body> \n";
	outfile << "</html> \n";
}

void CHTMLWriter::createLink(const String& link,const String& linkName){
	outfile << "<a href" << link << ">";
	outfile << linkName << "</a> \n";
}

void CHTMLWriter::printParagraph(const String& paragraph){
	outfile << "<p>" << paragraph << "</p> \n"
}

void CHTMLWriter::printPreParagraph(const String& PreParagraph){
	outfile << "<pre>" << PreParagraph << "</pre>";
}

