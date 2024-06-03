#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project2/KiwerAPI.cpp"
#include "../Project2/NemoAPI.cpp"
#include "../Project2/TradingSystem.cpp"

using namespace testing;
using namespace std;

//1. selectStockBrocker
TEST(TradingSystemTest, selectStockBroker) {
	TradingSystem t;
	t.selectStockBroker(new KiwiDriver());
	EXPECT_THAT(t.stockBroker != nullptr);
}

//2-1. login success
TEST(TradingSystemTest, loginSuccess) {
	TradingSystem t;
	t.selectStockBroker(new KiwiDriver());
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

