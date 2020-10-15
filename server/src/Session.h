#pragma once

#include "asio.hpp"
#include "game_protocol.pb.h"

using asio::ip::tcp;

class Session
	: public std::enable_shared_from_this<Session>
{
public:
	Session();
	Session(tcp::socket &socket);
	~Session();

	void start();
	void send(const GameProtocol::Packet& msg);
private:
	void receive();
	void end();
	void joinRoom();

	tcp::socket socket_;
};