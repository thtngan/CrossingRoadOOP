#include "CObject.h"

CObject::CObject() : _outMap(false){}
CObject::CObject(const CPos& start) : _pos(start), _outMap(false){}
int CObject::getX(){
	return _pos.getX();
}
int CObject::getY(){
	return _pos.getY();
}
CPos CObject::getPos(){
	return _pos;
}
bool CObject::isOutMap(){
	return _outMap;
}
void CObject::setOutMap(){
	_outMap = true;
}
void CObject::updatePos(const int x, const int y){
	_pos.setPos(_pos.getX() + x, _pos.getY() + y);
}

