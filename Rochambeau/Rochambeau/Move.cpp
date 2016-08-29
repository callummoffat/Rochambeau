#include "stdafx.h"
#include "Move.h"


Move::Move(MoveTypes move)
{
	_move = move;
}

Move::~Move()
{
}

bool Move::operator<(const Move & rhs)
{
	if (!((_move == MoveTypes::Paper && rhs._move == MoveTypes::Rock) ||
		(_move == MoveTypes::Scissors && rhs._move == MoveTypes::Paper) ||
		(_move == MoveTypes::Rock && rhs._move == MoveTypes::Scissors)))
		return true;
	return false;

		
}

bool Move::operator>(const Move & rhs)
{
	if ((_move == MoveTypes::Paper && rhs._move == MoveTypes::Rock) ||
		(_move == MoveTypes::Scissors && rhs._move == MoveTypes::Paper)
		|| (_move == MoveTypes::Rock && rhs._move == MoveTypes::Scissors))
	{
		return true;
	}
	else
	{
		return false;
	}



}

bool Move::operator==(const Move & rhs)
{
	return _move == rhs._move;
}

bool Move::operator!=(const Move & rhs)
{
	return _move != rhs._move;
}



