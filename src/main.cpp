#include "Olymbits.hpp"

int	main(void){
	Olymbits	o;

	o.setGlobal();
	while (1){
		o.setScoreInfo();
		o.printGlobal();
		for (int i = 0; i < 4; i++){
			o.setLocal(i);
			o.printLocal(i);
		}
		o.MiniGame1();
	}
}
