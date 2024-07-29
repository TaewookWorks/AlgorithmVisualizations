#include "CImg_Helpers.h"
#include "DefinedColors.h"
using namespace cimg_library;

#undef min
#undef max

//Main.
int main() 
{
	//3-Color Based Spectrum.
	unsigned int spectrum = 3;
	CImg<unsigned char> panel(400,400,1, spectrum,0);
	CImg<unsigned char> visu(800, 800, 1, spectrum, 0);

	unsigned char bg = 100U;

	CImgDisplay main_disp(panel, "Choose An Algorithm"), draw_disp(visu, "Results");

	while (!main_disp.is_closed() && !draw_disp.is_closed()) 
	{
		main_disp.wait();

		panel.fill(bg);

		if (twk::DrawButton(main_disp, panel, 100, 100, 120, 30, "A-Star", twk::MediumTurquoise))
		{
			bg = 200;
		}
		if (twk::DrawButton(main_disp, panel, 300, 100, 120, 30, "Djikstra", twk::MidnightBlue))
		{
			bg = 50;
		}

		panel.display(main_disp);
	}
	return 0;
}