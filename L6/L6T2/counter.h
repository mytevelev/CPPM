#pragma once

class Counter
{
private:
	int count;      // недоступно всем
public:
	void increment();
	void decrement();
	int get_value();
	Counter();
	Counter(int initial);
};