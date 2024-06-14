#include "Olymbits.hpp"

Olymbits::Olymbits(void){
}

Olymbits::~Olymbits(){
}

void	Olymbits::setGlobal(void){
	cin >> _playerIdx >> _nbGames;
	cin.ignore();
}

void	Olymbits::setScoreInfo(void){
	for (int i = 0; i < 3; i++)
		getline(cin, _scoreInfo[i]);
}

void	Olymbits::printGlobal(void){
	cerr << "player_idx:" << _playerIdx << " nb_games:" << _nbGames << endl;
}

void	Olymbits::setLocal(void){
	cin >> _gpu >> _reg0 >> _reg1 >> _reg2 >> _reg3 >> _reg4 >> _reg5 >> _reg6;
	cin.ignore();
}

void	Olymbits::printLocal(void){
	cerr << "\ngpu:" << _gpu << "\nreg0:" << _reg0 << " reg1:" << _reg1 <<
			" reg2:" << _reg2 << " reg3:" << _reg3 << " reg4:" << _reg4 <<
			" reg5:" << _reg5 << " reg6:" << _reg6 << endl;
}

void	Olymbits::reset(void){
	_up = 0;
	_left = 0;
	_down = 0;
	_right = 0;
}

void	Olymbits::MiniGame1(void){
	int	stun = _playerIdx == 0 ? _reg3 : _playerIdx == 1 ? _reg4 : _reg5;

	if (_gpu == "GAME_OVER" || stun)
		return ;
	_gpu += "..";

	int		pos = _playerIdx == 0 ? _reg0 : _playerIdx == 1 ? _reg1 : _reg2;
	string	sub = _gpu.substr(pos + 1, 3);

	if (sub[0] == '.' && sub[1] == '.' && sub[2] == '.'){
		_right++;
	} else if (sub[1] == '.'){
		_up++;
		if (sub[0] == '.')
			_down++;
	} else if (sub[0] == '.'){
		_left++;
	}
}

int		sqr(int x){
	return (x * x);
}

double	find_dist(int x1, int y1, int x2, int y2){
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}

void	Olymbits::MiniGame2(void){
	if (_gpu == "GAME_OVER")
		return ;

	int		x = _playerIdx == 0 ? _reg0 : _playerIdx == 1 ? _reg2 : _reg4;
	int		y = _playerIdx == 0 ? _reg1 : _playerIdx == 1 ? _reg3 : _reg5;
	double	pos[4] = {
		find_dist(0, 0, x, y - _gpu[0]),// Up
		find_dist(0, 0, x, y + _gpu[0]),// Down
		find_dist(0, 0, x - _gpu[0], y),// Left
		find_dist(0, 0, x + _gpu[0], y)	// Right
	};

	if (pos[0] < pos[1] && pos[0] < pos[2] && pos[0] < pos[3])
		_up++;
	else if (pos[1] < pos[2] && pos[1] < pos[3])
		_down++;
	else if (pos[2] < pos[3])
		_left++;
	else
		_right++;
}

void	Olymbits::MiniGame3(void){
	int	risk = _playerIdx == 0 ? _reg3 : _playerIdx == 1 ? _reg4 : _reg5;

	if (_gpu == "GAME_OVER" || risk < 0)
		return ;
	if (_gpu[0] == 'U') _up++;
	else if (_gpu[0] == 'D') _down++;
	else if (_gpu[0] == 'L') _left++;
	else _right++;
	if (_gpu[1] == 'U') _up++;
	else if (_gpu[1] == 'D') _down++;
	else if (_gpu[1] == 'L') _left++;
	else _right++;
}

void	Olymbits::MiniGame4(void){
	int	combo = _playerIdx == 0 ? _reg3 : _playerIdx == 1 ? _reg4 : _reg5;

	if (_gpu == "GAME_OVER" || combo == 0)
		return ;
	if (_gpu[0] == 'U')
		_up++;
	else if (_gpu[0] == 'D')
		_down++;
	else if (_gpu[0] == 'L')
		_left++;
	else
		_right++;
}

void	Olymbits::out(void){
	cerr << "\nup:" << _up << " down:" << _down << " left:" << _left <<
			" right:" << _right << endl;
	if (_up > _down && _up > _left && _up > _right)
		cout << "UP" << endl;
	else if (_down > _left && _down > _right)
		cout << "DOWN" << endl;
	else if (_left > _right)
		cout << "LEFT" << endl;
	else
		cout << "RIGHT" << endl;
}
