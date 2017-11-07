#pragma once

#include "IMessage.h"
#include "IEMath.h"

class AddForceMessage : public IMessage
{
public:
	AddForceMessage(std::string name);
	~AddForceMessage();

	void SetForce(Vec2 force) { _force = force; }
	Vec2 GetForce() { return _force; }

private:
	std::string			_name;
	Vec2				_force;
};
