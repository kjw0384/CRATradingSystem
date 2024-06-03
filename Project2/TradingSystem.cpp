#include <string>
#include <map>
#include <stdexcept>
#include "NemoAPI.cpp"
#include "KiwerAPI.cpp"

#include "NemoAPI.cpp"
#include "KiwerAPI.cpp"

#define interface struct

using namespace std;

interface IStockerBrocker {
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
};

class KiwerBroker : public IStockerBrocker {

	void login(string ID, string password) override {
		m_KiwerAPI.login(ID, password);
	}

	void buy(string stockCode, int price, int count) {
		return m_KiwerAPI.buy(stockCode, count, price);
	}

	void sell(string stockCode, int price, int count) {
		m_KiwerAPI.sell(stockCode, count, price);
	}

	int getPrice(string stockCode) {
		return m_KiwerAPI.currentPrice(stockCode);
	}

private:
	KiwerAPI m_KiwerAPI;
};

class NemoBroker : public IStockerBrocker {
	void login(string ID, string password) override {
		m_NemoAPI.certification(ID, password);
	}

	void buy(string stockCode, int price, int count) {
		m_NemoAPI.purchasingStock(stockCode, price, count);
	}

	void sell(string stockCode, int price, int count) {
		m_NemoAPI.sellingStock(stockCode, price, count);
	}

	int getPrice(string stockCode) {
		return m_NemoAPI.getMarketPrice(stockCode, 0);
	}

private:
	NemoAPI m_NemoAPI;
};

class TradingSystem {
public:
	void selectStockBroker(string broker) {
		if (broker == "Kiwer") {
			stockBroker = new KiwerBroker();
		}
		else if (broker == "Nemo") {
			stockBroker = new NemoBroker();
		}
	}
  
	void login(string ID, string password) {
		if (ID.empty() || password.empty()) {
			throw std::invalid_argument("invalid argument");
		}

		if (stockBroker == nullptr) {
			throw std::bad_alloc();
		}

		stockBroker->login(ID, password);
	}

	IStockerBroker* stockBroker{};
	user user;
};

class user {
public:

	int getStockCount(string stockCode) {
		if (stockCountPerStockCode.find(stockCode) != stockCountPerStockCode.end())
			return stockCountPerStockCode[stockCode];
		else
			return 0;
	}

	void setStockCount(string stockCode, int value) {
		stockCountPerStockCode[stockCode] = value;
	}

	int balance = 0;
	map<string, int> stockCountPerStockCode;

};
