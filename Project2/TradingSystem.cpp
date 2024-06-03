#include <string>

#define interface struct

using namespace std;

interface IStockerBroker {
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
};

class KiwerBroker : public IStockerBroker {
	void login(string ID, string password) override {
		return;
	}
	void buy(string stockCode, int price, int count) override {
		return;
	}
	void sell(string stockCode, int price, int count) override {
		return;
	}
	int getPrice(string stockCode) override {
		return 0;
	}

};

class NemoBroker : public IStockerBroker {
	void login(string ID, string password) override {
		return;
	}
	void buy(string stockCode, int price, int count) override {
		return;
	}
	void sell(string stockCode, int price, int count) override {
		return;
	}
	int getPrice(string stockCode) override {
		return 0;
	}

};

class TradingSystem {
public:
	TradingSystem() : stockBroker(nullptr) {}
	void selectStockBroker(IStockerBroker* broker) {
		if (stockBroker != nullptr) {
			delete stockBroker; // 이전 증권사 객체 삭제
		}
		stockBroker = broker;
	}

	IStockerBroker* stockBroker;

private:

};