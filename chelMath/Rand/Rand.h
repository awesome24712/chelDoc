#ifndef CHEL_RANDOM
#define CHEL_RANDOM

void RandReport();

void RandSeed();

int RandInt();

int RandInt(int min, int max);

inline int RandInt(int max) { return RandInt(0, max); }

float RandFloat();

float RandFloat(float min, float max);

inline float RandFloat(float max) { return RandFloat(0, max); }

inline bool RandBool(float proportion) { return RandFloat() < proportion; }

#endif //CHEL_RANDOM