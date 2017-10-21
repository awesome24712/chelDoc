//#include "../chelTypes/chelTypes.hpp"
/*#include "../chelMath/chelMath.hpp"
#include "../chelTypes/chelTypes.hpp"
#include "stdio.h"
//#include "stdlib.h"
//#include "memory.h"
//#include "typeinfo"

<<<<<<< .mine
#include "Array/CArray.hpp"
#include "Array/CArray.hpp"*/
=======
//#include "Array/CArray.hpp"
//#include "Array/CArray.hpp"
>>>>>>> .r11

<<<<<<< .mine
//includes - we're only printing here
#include "stdio.h"

/**
 * Plays a game of "FizzBuzz" but with the words "OnBase" instead,
 * 		and with different numbers.
 * The relationships are customizable. See below.
 */

//namespace NFizzBuzzGame {
	/**
	* Map pairs are defined separately, to allow easy adding of new relationships.
	* Change the value of FIZZBUZZ_MAX_PAIRS to allow for more pairs to be added.
	* Priority of pairs is based on definition order.
	*/
	/*#define FIZZBUZZ_MAX_PAIRS 2
	struct 				SMapPair;
	const SMapPair* 	g_ppPairs[FIZZBUZZ_MAX_PAIRS];
	int					g_iPairCount = 0;
	
	struct SMapPair {
	public:
		int 		m_iDivisor;
		const char* m_pszMessage;
		SMapPair(int iDivisor, const char* pszMessage) {
			m_iDivisor = iDivisor; m_pszMessage = pszMessage;
			g_ppPairs[g_iPairCount++] = this;
		}
	};
	
	//From here you can add new relationships without having to
	//modify rest of program. Don't forget about MAX_PAIRS though.
	SMapPair on		(3, "On");
	SMapPair base	(7, "Base");
	
	//This function actually plays the game - you shouldn't
	//ever need to modify anything here except for FIZZBUZZ_MAX_INT
	#define FIZZBUZZ_MAX_INT 100
	void play() {
		for (int i = 1; i <= FIZZBUZZ_MAX_INT; i++) {
			bool bDidPrintMessage = false;
			//go through each relationship and check
			for (int j = 0; j < g_iPairCount; j++) {
				const SMapPair* pPair = g_ppPairs[j];
				if (i % pPair->m_iDivisor == 0) {
					printf(pPair->m_pszMessage);
					bDidPrintMessage = true;
				}
			}
			
			//only print the actual number if we didn't print another message
			if (!bDidPrintMessage) {
				printf("%i", i);
			}
			
			//go to next line
			printf("\n");
		}
	}
}

=======


void treeTest() {
	printf("Begin tree test\n");
	{
		CTreeHandle<int> t = 3;
		printf("Built tree handle\n");
		//int var = t->child(-1)->value();
		t->addChild(2)->addChild(67);
		printf("Added two children\n");
		
		t->addChild(5);
		t->addChild(42)->addChild(101)->addChild(32);
		
		CTree<int>* ch = t->child(1);
		ch->addChild(1);
		ch->addChild(2);
		ch->addChild(2);
		
		printf("Finished adding children\n");
		
		String treeAsString;
		
		//void (*pProcedure)(const CTree<int>*, String&, int) = &treeToString;
		
		printf("Converting tree to string\n");
		treeToString(t.getPtr(), treeAsString, 0);
		
		printf("Printing tree as string\n");
		printf(treeAsString);
		printf("Finished tree test\n");
	}
	printf("End tree test\n");
}




>>>>>>> .r11
int main() {
<<<<<<< .mine
	NFizzBuzzGame::play();
}*/

#include "math.h"
bool isPrime(int n) {
	//assume true, then test otherwise
	bool bIsPrime = n > 1;
	
	if (bIsPrime) {
		//we'll do a simple trial by exhaustion
		int root = ((int) (sqrtf(n))) + 1;
		for (int i = 2; i <= root && bIsPrime; i++) {
			bIsPrime = n % i != 0;
		}
	}
	
	return bIsPrime;
}

#define PRINT_PRIMES_MAX 99
int main() {
	for (int i = 2; i <= PRINT_PRIMES_MAX; i++) {
		if (isPrime(i)) {
			printf("%i\n", i);
		}
	}
}


=======
	try {
		
	} catch (CChelException* e) {
		printf("Begin exception handling\n");
		e->handle();
	}
}>>>>>>> .r11
