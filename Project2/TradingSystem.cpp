#include <string>
#include <stdexcept>
#include "NemoAPI.cpp"
#include "KiwerAPI.cpp"

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
		kiwer->login(ID, password);
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

	KiwerAPI* kiwer;
};

class NemoBroker : public IStockerBroker {
	void login(string ID, string password) override {
		nemo->certification(ID, password);
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

	NemoAPI* nemo;
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
};