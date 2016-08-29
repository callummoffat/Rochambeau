#pragma once
#include "MoveTypes.h"

class Move
{
public:
	Move(MoveTypes move);
	~Move();
	bool operator >(const Move& rhs);
	bool operator ==(const Move& rhs);
	bool operator !=(const Move& rhs);
	
private:
	MoveTypes _move;

	
};

