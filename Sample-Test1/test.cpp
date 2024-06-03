#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project2/KiwerAPI.cpp"
#include "../Project2/NemoAPI.cpp"
#include "../Project2/TradingSystem.cpp"

//1. selectStockBrocker
TEST(TradingSystemTest, selectStockBroker) {
	TradingSystem t;
	t.selectStockBroker();
	EXPECT_THAT(t.stockBroker != nullptr);
}

