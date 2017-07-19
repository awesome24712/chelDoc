#include "Character.h"

#define CHARACTER_CASE_OFFSET 32

void Character::toLowerCase(char& ldChar) {
	if (ldChar >= 'A' && ldChar <= 'Z')
		ldChar += CHARACTER_CASE_OFFSET;
}

void Character::toUpperCase(char& ldChar) {
	if (ldChar >= 'a' && ldChar <= 'z')
		ldChar -= CHARACTER_CASE_OFFSET;
}