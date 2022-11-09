#include "source.h"
#include <conio.h>


int main() {

	std::cout << "Hi" << std::endl;
	double value;
	int nAp;
	double X, h;
	while (true) {
		system("cls");

		std::cout << "0. exit\n";
		std::cout << "1. Runge-Kutt (2, 3, 4)\n";

		//char com = _getch();

		enum TASKS { EXIT = 0, LAB_5 };

		int op;
		std::cin >> op;
		try {
			switch (op) {
			case EXIT: return 0; break;

			case LAB_5:
				double x0 = 0.0, y0 = 2.0;
				std::cout << "Solution dy/dx = y - x by the RK method" << std::endl;

				std::cout << "x0 = ";
				std::cin >> x0;
				std::cout << "y0 = ";
				std::cin >> y0;

				std::cout << "Precision = ";
				std::cin >> nAp;

				std::cout << "RK order = ";
				int order = 3;
				std::cin >> order;
				if (order == 1) {
					std::cout << "\n RK2" << std::endl;
					for (int i = 1; i <= nAp; i ++) {
						std::cout << "Iteration: " << i << 
							"\t solution:" << std::setprecision(nAp) << RK2(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK2(x0, y0, i) << std::endl;
					}

					std::cout << "\n RK3" << std::endl;
					for (int i = 1; i <= nAp; i++) {
						std::cout << "Iteration: " << i << 
							"\t solution:" << std::setprecision(nAp) << RK3(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK3(x0, y0, i) << std::endl;
					}

					std::cout << "\n RK4" << std::endl;
					for (int i = 1; i <= nAp; i ++) {
						std::cout << "Iteration: " << i <<
							"\t solution:" << std::setprecision(nAp) << RK4(x0, y0, i) <<
							"\t	\t eps = " << std::setprecision(2 * i) << epsRK4(x0, y0, i) << std::endl;
					}
					_getch();
				}
				if (order == 2) {
					for (int i = 1; i <= nAp; i++)
						std::cout << "Iterations: " << i <<
												std::setprecision(nAp) << "\t solution RK2:" << RK2(x0, y0, i) << 
													"\t	\t eps = " << std::setprecision(2*i)<< epsRK2(x0, y0, i) << std::endl;
					_getch();
				}
				else
					if (order == 3) {
						for (int i = 1; i < nAp; i ++)
							std::cout << "Iterations: " << i <<
														std::setprecision(nAp) << "\t solution RK3:" << RK3(x0, y0, i) <<
													"\t	\t eps = " << std::setprecision(2*i) << epsRK3(x0, y0, i) << std::endl;
						_getch();
					}
					else
						if (order == 4) {
							for (int i = 1; i < nAp; i ++)
								std::cout << "Iterations: " << i <<
													std::setprecision(nAp) << "\t solution RK4:" << RK4(x0, y0, i) <<
													"\t	\t eps = " << std::setprecision(2*i) << epsRK4(x0, y0, i) << std::endl;
							_getch();
						}
				break;
			}
		}
		catch (const char* er) {
			std::cout << er << std::endl;
			_getch();
			return 1;
		}

	}

	return 0;
}

