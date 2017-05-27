#define BITFIELD_BEGIN()

	#define BF(FLAG_NAME, BIT_NUM) \
		const unsigned long long FLAG_NAME = 1ULL << BIT_NUM;

#define BITFIELD_END()