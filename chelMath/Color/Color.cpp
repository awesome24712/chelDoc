#include "Color.h"
#include "../math.hpp"

ColorRGB::ColorRGB(uint8_t red, uint8_t green, uint8_t blue) {
	R = red;
	G = green;
	B = blue;
}

void ColorRGB::toGrayScale() {
	R = G = B = (R + G + B) / 3;
}

void ColorRGB::lerpWith(ColorRGB other, float _lerp) {
	R = lerp(_lerp, R, other.R);
	G = lerp(_lerp, G, other.G);
	B = lerp(_lerp, B, other.B);
}