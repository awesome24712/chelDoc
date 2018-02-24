#ifndef CHEL_CURDBLLKLST_HPP
#define CHEL_CURDBLLKLST_HPP

#include "../../String/Character.h"
#include "CUrDblLkLst.h"
#include "Windows.h"



template<class T, int N> void SUrDblLkLstNode<T,N>::insertNoSplit(const T& incomingValue, uint8 index) {
	AssertTrue(index >= 0 && index <= m_iLength, "Valid array index for SUrDblLkLstNode insertion");
	
	//fixup length
	m_iLength++;
	
	//displace values to the right by one
	//TODO clean this up!
	uint8 i = m_iLength - 1;
	while(true) {
		m_pArray[i] = m_pArray[i-1];
		if ( i == index)
			break;
		i--;
	}
		
	//copy in the incoming value
	m_pArray[index] = incomingValue;
}

template<class T, int N> void SUrDblLkLstNode<T,N>::split(const T& incomingValue, uint8 index) {
	//build the next node
	SUrDblLkLstNode<T,N>* newNode = new SUrDblLkLstNode<T,N>();
	
	//fixup references
	newNode->m_pNext = m_pNext;
	newNode->m_pPrevious = this;
	m_pNext->m_pPrevious = newNode;
	m_pNext = newNode;
	
	//determine which node will have the value added to it
	if (index < HALF_FULL_UP)
	//we'll add it to the first node
	{
		//copy values into the next node
		for (int i = 0; i <= HALF_FULL + 1; i++)
			m_pNext->m_pArray[i] = m_pArray[HALF_FULL_UP - 1 + i];
		
		//displace values at and to the right of the index by 1
		for (int i = HALF_FULL; i > index; i--)
			m_pArray[i] = m_pArray[i-1];
			
		//set the value at the given index to the given value
		m_pArray[index] = incomingValue;
		
		//fixup lengths
		m_iLength = HALF_FULL_UP;
		m_pNext->m_iLength = HALF_FULL + 1;
	}
	else
	//we' add it to the second node
	{
		//copy values before the index in
		int j = 0;
		int i;
		for (i = HALF_FULL_UP; i < index; i++)
			m_pNext->m_pArray[j++] = m_pArray[i];
			
		//put in the incoming value
		m_pNext->m_pArray[index - HALF_FULL_UP] = incomingValue;
		
		//copy in the rest of the values
		j = index - HALF_FULL_UP + 1;
		for (i; i < N; i++) {
			m_pNext->m_pArray[j++] = m_pArray[i];
		}
		
		//fixup the lengths
		m_iLength = HALF_FULL_UP;
		m_pNext->m_iLength = HALF_FULL + 1;
	}
}

template<class T, int N> void SUrDblLkLstNode<T,N>::erase(uint8 index) {
	//copy value before removal
	//dest = m_pArray[index];
	
	//copy value from the right
	//printf("Shifting values in range (%i, %i)\n", index, m_iLength - 1);
	while (index < m_iLength - 1) {
		m_pArray[index] = m_pArray[index + 1];
		index++;
	}
	
	//fixup length
	m_iLength--;
	
	//balance or merge if necessary
	if (m_iLength + m_pNext->m_iLength == N) 	
		merge();													
	else if (m_iLength < HALF_FULL_UP) {
		balance();
	}
}

template<class T, int N> void SUrDblLkLstNode<T,N>::merge() {
	
	//copy values into this
	for (int i = 0 ; i < m_pNext->m_iLength; i++)
		m_pArray[m_iLength + i] = m_pNext->m_pArray[i];
	
	//fixup length
	m_iLength += m_pNext->m_iLength;
	
	//fixup references and delete
	SUrDblLkLstNode* deleteMe = m_pNext;
	m_pNext = deleteMe->m_pNext;
	m_pNext->m_pPrevious = this;
	delete deleteMe;
}

template<class T, int N> void SUrDblLkLstNode<T,N>::balance() {
	//don't do anything if the next node is the terminal node
	if (m_pNext->m_iLength > N)
		return;
	
	uint8 origLength = m_iLength;
	uint8 i = 0;
	
	//copy values from the next node into ours
	while (m_iLength < HALF_FULL_UP && i < m_pNext->m_iLength) {
		m_pArray[m_iLength++] = m_pNext->m_pArray[i++];
	}
	
	uint8 numValuesCopied = m_iLength - origLength;
	
	//displace values in the next node too
	for (i = 0; i < numValuesCopied; i++) {
		m_pArray[i] = m_pArray[i + numValuesCopied];
	}
	
	//fixup length
	m_pNext->m_iLength -= numValuesCopied;
}

/*********************************************************************
 * Unrolled Linked List
 ********************************************************************/ 
template<class T, int N> CUrDblLkLst<T,N>::CUrDblLkLst() {
	m_iLength = 0;
	m_pFirst = new SUrDblLkLstNode<T,N>();
	m_pTerminal = new SUrDblLkLstNode<T,N>();
	
	m_pTerminal->m_iLength = INT8_MIN; //huge negative value prevents merging with terminal node
	
	m_iLastReferencedIndex = 0;
	m_pLastReferenced = m_pFirst;
	
	//assign null values to prevent wierd access
	m_pFirst->m_pPrevious = m_pTerminal->m_pNext = nullptr;
	
	//link first and sentinal nodes
	m_pFirst->m_pNext = m_pTerminal;
	m_pTerminal->m_pPrevious = m_pFirst;
}

template<class T, int N> SUrDblLkLstNode<T,N>* CUrDblLkLst<T,N>::nodeForPos(int& pos) const {
	SUrDblLkLstNode<T,N>* curNode = m_pFirst;
	while (pos > curNode->m_iLength) {
		pos -= curNode->m_iLength;
		curNode = curNode->m_pNext;
	}
	return curNode;
}

template<class T, int N> T& CUrDblLkLst<T,N>::getRef(int pos) const {
	//first navigate to correct node
	return nodeForPos(pos)->m_pArray[pos];
}

template<class T, int N> void CUrDblLkLst<T,N>::add(const T& value, int pos) {
	nodeForPos(pos)->insert(value, pos);
	m_iLength++;
}

template<class T, int N> void CUrDblLkLst<T,N>::erase(int pos) {
	//get node
	SUrDblLkLstNode<T,N>* pNode = nodeForPos(pos);
	
	//decrement length
	m_iLength--;
	
	pNode->erase(pos);
}

template<class T, int N> void CUrDblLkLst<T,N>::copyTo(T* dest, int numElements) {
	for (int i = 0; i < numElements && i < m_iLength; i++) {
		dest[i] = getRef(i);
	}
}

#endif //CHEL_CURDBLLKLST_HPP