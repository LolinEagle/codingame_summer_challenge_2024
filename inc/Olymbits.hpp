#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Olymbits{
	private:
		int		_playerIdx, _nbGames;
		int		_reg0, _reg1, _reg2, _reg3, _reg4, _reg5, _reg6;
		int		_up, _down, _left, _right;
		string	_scoreInfo[3], _gpu;
	public:
		Olymbits(void);
		~Olymbits();

		void	setGlobal(void);
		void	setScoreInfo(void);
		void	printGlobal(void);
		
		void	setLocal(void);
		void	printLocal(void);
		void	reset(void);
		void	MiniGame1(void);
		void	MiniGame2(void);
		void	MiniGame3(void);
		void	MiniGame4(void);
		void	out(void);
};
