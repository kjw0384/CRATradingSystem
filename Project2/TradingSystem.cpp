#include <string>
#include "../Project2/KiwerAPI.cpp"
#include "../Project2/NemoAPI.cpp"

#define interface struct

using namespace std;

interface IStockerBroker {
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
};

class KiwerBroker : public IStockerBroker {
public:
	void login(string ID, string password) override {
		return;
	}
	void buy(string stockCode, int price, int count) override {
		m_API->buy(stockCode, price, count);

		return;
	}
	void sell(string stockCode, int price, int count) override {
		return;
	}
	int getPrice(string stockCode) override {
		return 0;
	}

private: 
	KiwerAPI* m_API;
};

class NemoBroker : public IStockerBroker {
public:
	void login(string ID, string password) override {
		return;
	}
	void buy(string stockCode, int price, int count) override {
		m_API->purchasingStock(stockCode, price, count);
		return;
	}
	void sell(string stockCode, int price, int count) override {
		return;
	}
	int getPrice(string stockCode) override {
		return 0;
	}

private:
	NemoAPI* m_API;
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

	void buy(string stockCode, int price, int count)
	{
		stockBroker->buy(stockCode, price, count);
	}

	IStockerBroker* stockBroker;
};