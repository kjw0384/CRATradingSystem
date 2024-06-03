#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

using namespace std;

class NemoDriver : public StockerBrockerDriverInterface {
public :
	virtual bool login(string ID, string password) {
		m_NemoAPI.certification(ID, password);
	}

	virtual void buy(string stockName, int budget) {
		int currentPrice = m_NemoAPI.getMarketPrice(stockName, 0);
		int buyCount = budget / currentPrice;
		m_NemoAPI.purchasingStock(stockName, currentPrice, buyCount);
	}

	virtual void sell(string stockName, int stockCnt) {
		int currentPrice = m_NemoAPI.getMarketPrice(stockName, 0);
		m_NemoAPI.sellingStock(stockName, stockCnt);
	}

	virtual int	 getPrice(string stockName) {
		return m_NemoAPI.getMarketPrice(stockName, 0);
	}

private: 
	NemoAPI m_NemoAPI;
};


class NemoAPI {
public:
	void certification(string ID, string pass) {
		cout << "[NEMO]" << ID << " login GOOD\n";
	}

	void purchasingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	void sellingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	int getMarketPrice(string stockCode, int minute) {
		//minute ms초 이후 구매가 되는 방식 (최소 1 ms)
		if (minute <= 0) minute = 1;
		Sleep(minute);
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};
