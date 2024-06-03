#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project2/KiwerAPI.cpp"
#include "../Project2/NemoAPI.cpp"
#include "../Project2/TradingSystem.cpp"

using namespace testing;
using namespace std;

class MockStockBroker : public IStockerBrocker {
public:
	MOCK_METHOD(void, login, (std::string ID, std::string password), (override));
	MOCK_METHOD(void, buy, (std::string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (std::string stockCode, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (std::string stockCode), (override));
};

/*
//1. selectStockBrocker
TEST(TradingSystemTest, selectStockBroker) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	EXPECT_THAT(t.stockBroker, Ne(nullptr));
}

//2-1. login success
TEST(TradingSystemTest, loginSuccess) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	try {
		t.login("user", "1234");
	}
	catch(exception e){
		FAIL();
	}
}

//2-2. login fail when Broker not selected
TEST(TradingSystemTest, loginFailWhenBrockerNotSelected) {
	TradingSystem t;
	
	EXPECT_THROW(t.login("user", "1234"), exception);
}

//3-1. buy Success
TEST(TradingSystemTest, buySuccess) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	t.setBalance(10000);
	t.buy("samsung", 1, 300);
	EXPECT_EQ(t.balance, 9700);
}

//3-2. buy Fail if no balance
TEST(TradingSystemTest, buyFailIfNoBalance) {
	TradingSystem t;
	t.selectStockBroker(new KiwiDriver());
	t.setBalance(100);
	EXPECT_THROW(t.buy("nVIdia", 100, 300), exception);
}

//4-1. sell Success
TEST(TradingSystemTest, sellSuccess) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	t.setBalance(100);
	try {
		t.sell("Hynix", 5)
	}
	catch (exception e) {
		FAIL();
	}
}

//5-1. getPrice Success
TEST(TradingSystemTest, getPriceSuccess) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	t.stockBroker->login("user", "1234");
	EXPECT_THAT(t.stockBroker->getPrice("Amazon"), Gt(0));
}

//5-2. getPrice Fail if stockCode is null
TEST(TradingSystemTest, getPriceFailIfStockCodeIsNull) {
	TradingSystem t;
	t.selectStockBroker(new KiwerBroker());
	t.stockBroker->login("user", "1234");
	EXPECT_THROW(t.stockBroker->getPrice(""), exception);
}
*/
// 5-1. getPrice Success
TEST(TradingSystemTest, getPriceSuccess) {
	TradingSystem t;
	MockStockBroker* mockBroker = new MockStockBroker();
	t.selectStockBroker(mockBroker);

	EXPECT_CALL(*mockBroker, login("user", "1234")).Times(1);
	EXPECT_CALL(*mockBroker, getPrice("Amazon")).WillOnce(Return(5000));

	t.stockBroker->login("user", "1234");
	EXPECT_THAT(t.stockBroker->getPrice("Amazon"), Gt(0));
}

// 5-2. getPrice Fail if stockCode is null
TEST(TradingSystemTest, getPriceFailIfStockCodeIsNull) {
	TradingSystem t;
	MockStockBroker* mockBroker = new MockStockBroker();
	t.selectStockBroker(mockBroker);

	EXPECT_CALL(*mockBroker, login("user", "1234")).Times(1);
	EXPECT_CALL(*mockBroker, getPrice("")).WillOnce(Throw(std::invalid_argument("Invalid stock code")));

	t.stockBroker->login("user", "1234");
	EXPECT_THROW(t.stockBroker->getPrice(""), std::invalid_argument);
}