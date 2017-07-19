#define BITFIELD_BEGIN()

	#define BF64(FLAG_NAME, BIT_NUM) \
		const unsigned long long FLAG_NAME = 1ULL << BIT_NUM;
	#define BF(FLAG_NAME, BIT_NUM) \
		const unsigned int FLAG_NAME = 1U << BIT_NUM;

#define BITFIELD_END()