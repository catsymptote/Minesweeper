#pragma once

class Cell
{
public:
	Cell(bool bomb);
	~Cell();
	bool isTriggered();
	bool isBomb();
	bool trigger();
	void setBomb();

private:
	bool triggered;
	bool bomb;

};

