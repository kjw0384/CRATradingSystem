#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project2/KiwerAPI.cpp"
#include "../Project2/NemoAPI.cpp"
#include "../Project2/TradingSystem.cpp"

//1. selectStockBrocker
TEST(TradingSystemTest, selectStockBroker) {
	TradingSystem t;
	t.selectStockBroker("Kiwer");
	EXPECT_THAT(t.stockBroker, Ne(nullptr));
}

//2-1. login success
TEST(TradingSystemTest, loginSuccess) {
	TradingSystem t;
	t.selectStockBroker("Kiwer");
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
	t.selectStockBroker(new KiwiDriver());
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
	t.selectStockBroker(new KiwiDriver());
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
	t.selectStockBroker(new KiwiDriver());
	t.login("user", "1234");
	EXPECT_THAT(t.getPrice("Amazon"), Gt(0));
}

//5-2. getPrice Fail if stockCode is null
TEST(TradingSystemTest, getPriceFailIfStockCodeIsNull) {
	TradingSystem t;
	t.selectStockBroker(new KiwiDriver());
	t.login("user", "1234");
	EXPECT_THROW(t.getPrice(""), exception);
}

