#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class KiwerAPI {
public:
	void login(string ID, string password) {
		cout << ID << " login success\n";
	}

	void buy(string stockCode, int count, int price) {
		cout << stockCode << " : Buy stock ( " << price << " * " << count << ")\n";
	}

	void sell(string stockCode, int count, int price) {
		cout << stockCode << " : Sell stock ( " << price << " * " << count << ")\n";
	}

	int currentPrice(string stockCode) {
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};

class KiwerDriver {
public:
	virtual void login(string ID, string password) {
		m_KiwerAPI.login(ID, password);
	}

	virtual int	 getPrice(string stockName) {
		return m_KiwerAPI.currentPrice(stockName);
	}

	virtual void buy(string stockName, int budget) {
		int price = getPrice(stockName);
		return m_KiwerAPI.buy(stockName, budget / price, price);
	}

	virtual void sell(string stockName, int stockCnt) {
		m_KiwerAPI.sell(stockName, stockCnt, getPrice(stockName));
	}

private:
	KiwerAPI m_KiwerAPI; 
};