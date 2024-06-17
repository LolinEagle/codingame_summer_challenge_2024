#include "Olymbits.hpp"

Olymbits::Olymbits(void){
}

Olymbits::~Olymbits(){
}

void	Olymbits::setGlobal(void){
	cin >> _playerIdx >> _nbGames; cin.ignore();
}

void	Olymbits::setScoreInfo(void){
	for (int i = 0; i < 3; i++)
		getline(cin, _scoreInfo[i]);
}

void	Olymbits::printGlobal(void){
	cerr << "player_idx:" << _playerIdx << " nb_games:" << _nbGames << endl;
}

void	Olymbits::setLocal(const int &i){
	cin >> _gpu[i] >> _reg0[i] >> _reg1[i] >> _reg2[i] >> _reg3[i] >> _reg4[i]
		>> _reg5[i] >> _reg6[i]; cin.ignore();
}

void	Olymbits::printLocal(const int &i){
	cerr << "\ngpu:" << _gpu[i] << "\nreg0:" << _reg0[i] <<
			" reg1:" << _reg1[i] << " reg2:" << _reg2[i] <<
			" reg3:" << _reg3[i] << " reg4:" << _reg4[i] <<
			" reg5:" << _reg5[i] << " reg6:" << _reg6[i] << endl;
}

void	MiniGame1Default(const string &sub){
	if (sub == "...")
		cout << "RIGHT" << endl;
	else if (sub[1] == '.')
		cout << "UP" << endl;
	else
		cout << "LEFT" << endl;
}

bool	MiniGame1Directions(string &sub, int dir){
	int	i = 0;

	for (string::iterator it = sub.begin(); it != sub.end(); it++){
		if (*it == '.'){
			i++;
		} else if (*it == '#' || it + 1 == sub.end()){
			if (dir < 3){
				if (i % 3 != dir)
					return (false);
				return (true);
			} else if (dir == 3){
				if (i / 3 == 0)
					return (false);
				return (true);
			}
		}
	}
	return (false);
}

void	Olymbits::MiniGame1(void){
	// Exception
	if (_gpu[0] == "GAME_OVER"){
		if (_gpu[3] != "GAME_OVER" && _gpu[3].size() > 1){
			if (_gpu[3][1] == 'U') cout << "UP" << endl;
			else if (_gpu[3][1] == 'D') cout << "DOWN" << endl;
			else if (_gpu[3][1] == 'L') cout << "LEFT" << endl;
			else cout << "RIGHT" << endl;
		} else {
			cout << "UP" << endl;
		}
		return ;
	}

	// Next move
	int		pos = _playerIdx == 0 ? _reg0[0] : _playerIdx == 1 ? _reg1[0] : _reg2[0];
	string	sub = _gpu[0].substr(pos + 1, 3);

	if (sub[0] == '#'){
		cout << "UP" << endl;
		return ;
	}
	while (sub.size() < 3)
		sub.push_back('.');
	
	string	subAll = _gpu[0].substr(pos + 1);
	bool	up = MiniGame1Directions(subAll, 2);
	bool	down = MiniGame1Directions(subAll, 2);
	bool	left = MiniGame1Directions(subAll, 1);
	bool	right = MiniGame1Directions(subAll, 3);

	if (_gpu[3] != "GAME_OVER" && _gpu[3].size() > 1){
		if (up && _gpu[3][1] == 'U' && sub[1] == '.'){
			cout << "UP" << endl;
		} else if (down && _gpu[3][1] == 'D' && sub[0] == '.' && sub[1] == '.'){
			cout << "DOWN" << endl;
		} else if (left && _gpu[3][1] == 'L' && sub[0] == '.'){
			cout << "LEFT" << endl;
		} else if (right && _gpu[3][1] == 'R' && sub == "..."){
			cout << "RIGHT" << endl;
		} else {
			MiniGame1Default(sub);
		}
	} else {
		MiniGame1Default(sub);
	}
}

int		sqr(int x){
	return (x * x);
}

double	find_dist(int x1, int y1, int x2, int y2){
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}

void	Olymbits::MiniGame2(void){
	/* if (_gpu == "GAME_OVER")
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
		_right++;*/
}

void	Olymbits::MiniGame3(void){
	/* int	risk = _playerIdx == 0 ? _reg3 : _playerIdx == 1 ? _reg4 : _reg5;

	if (_gpu == "GAME_OVER" || risk < 0)
		return ;
	if (_gpu[0] == 'U') _up++;
	else if (_gpu[0] == 'D') _down++;
	else if (_gpu[0] == 'L') _left++;
	else _right++;
	if (_gpu[1] == 'U') _up++;
	else if (_gpu[1] == 'D') _down++;
	else if (_gpu[1] == 'L') _left++;
	else _right++;*/
}

void	Olymbits::MiniGame4(void){
	/* int	combo = _playerIdx == 0 ? _reg3 : _playerIdx == 1 ? _reg4 : _reg5;

	if (_gpu == "GAME_OVER" || combo == 0)
		return ;
	if (_gpu[0] == 'U')
		_up++;
	else if (_gpu[0] == 'D')
		_down++;
	else if (_gpu[0] == 'L')
		_left++;
	else
		_right++;*/
}
