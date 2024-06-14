#include "Olymbits.hpp"

int	main(void){
	Olymbits	o;

	o.setGlobal();
	while (1){
		o.reset();
		o.setScoreInfo();
		o.printGlobal();
		for (int i = 0; i < 4; i++){
			o.setLocal();
			o.printLocal();
			if (i == 0) o.MiniGame1();
			else if (i == 1) o.MiniGame2();
			else if (i == 2) o.MiniGame3();
			else o.MiniGame4();
		}
		o.out();
	}
}
