#pragma once

#include "game_protocol.pb.h"

class Card
{
public:
	inline void setType(GameProtocol::CardType& t) { type = t; }
	const GameProtocol::CardType Type() { return type; }
private:
	GameProtocol::CardType type;
};