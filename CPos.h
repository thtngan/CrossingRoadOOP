#pragma once
class CPos {
	int _x, _y;

public:
	CPos(){
		_x = 0;
		_y = 0;
	}
	CPos(const int x, const int y) {
		_x = x; 
		_y = y;
	}

	void setPos(const int x, const int y) {
		this->_x = x;
		this->_y = y;
	}

	int getX() {
		return _x;
	}

	int getY() {
		return _y;
	}
	~CPos(){}
	
};
