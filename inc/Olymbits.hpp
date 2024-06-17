#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Olymbits{
	private:
		int		_playerIdx, _nbGames;
		int		_reg0[4], _reg1[4], _reg2[4], _reg3[4], _reg4[4], _reg5[4], _reg6[4];
		int		_up, _down, _left, _right;
		string	_scoreInfo[3], _gpu[4];
	public:
		Olymbits(void);
		~Olymbits();

		void	setGlobal(void);
		void	setScoreInfo(void);
		void	printGlobal(void);
		
		void	setLocal(const int &i);
		void	printLocal(const int &i);
		void	MiniGame1(void);
		void	MiniGame2(void);
		void	MiniGame3(void);
		void	MiniGame4(void);
};
