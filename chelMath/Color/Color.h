#ifndef CHEL_COLOR
#define CHEL_COLOR

#include "../CBase/CBase.h"

class ColorRGB {
	uint8_t R;
	uint8_t G;
	uint8_t B;
	
	ColorRGB(uint8_t red, uint8_t green, uint8_t blue);
	
	void toGrayScale();
	void lerpWith(ColorRGB other, float _lerp);
};

#endif //CHEL_COLOR