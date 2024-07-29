#pragma once

//Helper Functions.

#include "CImg.h"
#include <string>
#include <cassert>

using namespace cimg_library;

namespace twk
{
	// CeCILL, From CImg Examples.
	float dist_segment(const float x, const float y, const float x1, const float y1, const float x2, const float y2) {
		const float
			dx = x2 - x1,
			dy = y2 - y1,
			long_segment = (float)std::sqrt(dx * dx + dy * dy);
		if (long_segment == 0) { const float ddx = x - x1, ddy = y - y1; return (float)std::sqrt(ddx * ddx + ddy * ddy); }
		const float
			unitx = dx / long_segment,
			unity = dy / long_segment,
			vx = x - x1,
			vy = y - y1,
			long_proy = vx * unitx + vy * unity,
			proyx = x1 + long_proy * unitx,
			proyy = y1 + long_proy * unity;
		if (long_proy > long_segment) { const float ddx = x - x2, ddy = y - y2; return std::sqrt(ddx * ddx + ddy * ddy); }
		else if (long_proy < 0) { const float ddx = x - x1, ddy = y - y1; return std::sqrt(ddx * ddx + ddy * ddy); }
		const float ddx = x - proyx, ddy = y - proyy;
		return std::sqrt(ddx * ddx + ddy * ddy);
	}

	//Custom.
	template <typename tc>
	bool DrawButton(CImgDisplay& imgDisplay, CImg<tc>& cimg, const int x, const int y, const int width, const int height, const std::string& innerText, const tc* const color, unsigned char fontSize = 20U)
	{
		int TL_X = x - width / 2;
		int TL_Y = y - height / 2;
		int BR_X = x + width / 2;
		int BR_Y = y + height / 2;

		bool isHovered = (imgDisplay.mouse_x() >= TL_X) &&
			(imgDisplay.mouse_x() <= BR_X) &&
			(imgDisplay.mouse_y() >= TL_Y) &&
			(imgDisplay.mouse_y() <= BR_Y);

		float opacity = isHovered ? 0.7f : 1.0f;

		//Button Background.
		cimg.draw_rectangle(TL_X, TL_Y, BR_X, BR_Y, color, opacity);

		//Button Border
		tc borderColor[3] = { 0, 0, 0 }; 
		cimg.draw_rectangle(TL_X, TL_Y, BR_X, BR_Y, borderColor, 1.0f, ~0U);

		//Text
		const unsigned char white[] = { 255,255,255 };
		cimg.draw_text((TL_X + x) / 2, (TL_Y + y) / 2, innerText.c_str(), white, 0, 1, fontSize);

		//Check Click
		bool isClicked = isHovered && imgDisplay.button() & 1;

		return isClicked;
	}
	
}




