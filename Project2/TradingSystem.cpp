#include <string>

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
		return;
	}
	void buy(string stockCode, int price, int count) {
		return;
	}
	void sell(string stockCode, int price, int count) {
		return;
	}
	int getPrice(string stockCode) {
		return 0;
	}

};

class NemoBroker : public IStockerBrocker {
	void login(string ID, string password) override {
		return;
	}
	void buy(string stockCode, int price, int count) {
		return;
	}
	void sell(string stockCode, int price, int count) {
		return;
	}
	int getPrice(string stockCode) {
		return 0;
	}

};

class TradingSystem {
public:
	TradingSystem() : stockBroker(nullptr) {}
	void selectStockBroker(IStockerBrocker* broker) {
		if (stockBroker != nullptr) {
			delete stockBroker; // 이전 증권사 객체 삭제
		}
		stockBroker = broker;
	}

	IStockerBrocker* stockBroker;

private:

};