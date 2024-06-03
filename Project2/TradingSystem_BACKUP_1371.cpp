#include <string>

<<<<<<< .merge_file_vF3x5w
#include "NemoAPI.cpp"
#include "KiwerAPI.cpp"

=======
>>>>>>> .merge_file_V4XAac
#define interface struct

using namespace std;

<<<<<<< .merge_file_vF3x5w
interface IStockerBrocker {
=======
interface IStockerBroker {
>>>>>>> .merge_file_V4XAac
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
};

<<<<<<< .merge_file_vF3x5w
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
=======
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

>>>>>>> .merge_file_V4XAac
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

<<<<<<< .merge_file_vF3x5w
	IStockerBrocker* stockBroker;
=======
	IStockerBroker* stockBroker;
>>>>>>> .merge_file_V4XAac
};