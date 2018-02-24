#include "../chelTypes/chelTypes.hpp"

#define NODE_SIZE 8


template<class T, int N> void printNode(SUrDblLkLstNode<T, N>* node) {
	for (int i = 0; i < node->m_iLength; i++) {
		Msg("%i,", node->m_pArray[i]);
	}
	Msg("\n");
}

template<class T, int N> void dumpNodeInfo(const SUrDblLkLstNode<T,N>& node) {
	printf("(%i)(%i,%i)\t\t", &node, node.m_pPrevious, node.m_pNext);
	for (uint8 i = 0; node.m_iLength <= N && i < node.m_iLength; i++)
		printf("%i ", node.m_pArray[i]);
}

template<class T, int N> void printInfo(const CUrDblLkLst<T,N>& lst) {
	printf("\n");
	printf("Length in bytes: %i\n", NList::lengthInBytes(lst));
	SUrDblLkLstNode<T,N>* node = lst.m_pFirst;
	while (node && node->m_pNext) {
		printNode(node);
		printf("\n");
		node = node->m_pNext;
	}
}

template<class T, int N> void dumpInfo(const CUrDblLkLst<T,N>& lst) {
	printf("\n");
	printf("Length in bytes: %i\n", NList::lengthInBytes(lst));
	SUrDblLkLstNode<T,N>* node = lst.m_pFirst;
	while (node && node->m_pNext) {
		dumpNodeInfo(*node);
		printf("\n");
		node = node->m_pNext;
	}
}

CON_COMMAND(testsplit) {
	if (args->argCount()) {
		CUrDblLkLst<int, NODE_SIZE> lst;
		
		for (int i = 0; i < NODE_SIZE; i++)
			lst.pushFront(i*i);
		
		lst.add(42, atoi(args->get(0)));
		
		dumpInfo(lst);
	}
}

CON_COMMAND(testmerge) {
	SUrDblLkLstNode<int, NODE_SIZE> node;
	node.m_iLength = 2;
	int i;
	for (i = 0; i < 3; i++)
		node.m_pArray[i] = i * i;
	
	SUrDblLkLstNode<int, NODE_SIZE> node2;
	node2.m_iLength = 2;
	for (; i < 6; i++)
		node2.m_pArray[i - 3] = i * i;
	
	printf("\n");
	
	node.m_pNext = &node2;
	node2.m_pPrevious = &node;
	SUrDblLkLstNode<int, NODE_SIZE> sentinal;
	node2.m_pNext = &sentinal;
	
	printNode<int, NODE_SIZE>(&node);
	printNode<int, NODE_SIZE>(&node2);
	
	printf("\n");
	
	node.merge();
	
	printNode<int, NODE_SIZE>(&node);
}

CON_COMMAND(copyto) {
	if (!args->argCount())
		return;
		
	CUrDblLkLst<int, NODE_SIZE> lst;
	
	SUrDblLkLstNode<int, NODE_SIZE>& node = *(lst.m_pFirst);
	
	int n = atoi(args->get(0));
	for (int i = 0; i < n; i++)
		lst.pushBack(i*i);
	
	dumpInfo(lst);
	Msg("\n");
}

CUrDblLkLst<int, NODE_SIZE> g_aLst;
int 						g_iCount = 0;

CON_COMMAND(ur_add) {
	if (args->argCount() != 1)
		return;
	
	g_aLst.add(sqr(g_iCount++), atoi(args->get(0)));
	
	printInfo(g_aLst);
}

CON_COMMAND(ur_remove) {
	if (args->argCount() != 1)
		return;
	
	g_aLst.remove(atoi(args->get(0)));
	printInfo(g_aLst);
}

CON_COMMAND(ur_print) {
	printInfo(g_aLst);
}

CON_COMMAND(ur_dump) {
	dumpInfo(g_aLst);
}

template<class R>
R callfunc( R(*pFunc)()) {
	pFunc();
}

CON_COMMAND(lambda) {
	int x = callfunc(+[]() -> int {
		return 100;
	});
	Msg("%i\n");
}

CON_COMMAND(ur_avg) {
	Msg("%i\n", NList::average(g_aLst, +[](const int& value) {
		return value;
	}));
}

int g_iIncrementMe = 0;
CON_COMMAND(increment) {
	Msg("%i\n", g_iIncrementMe);
}

