#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>

TEST(ParseFromStringTest, checkIfEquals){
	std::string text = 
	"{\"name\": \"Bela\",\"hp\": 500,\"dmg\": 20, \"atc\": 1.4}";
	JSON json = JSON::parseFromString(text);
	
  ASSERT_FLOAT_EQ(json.get<float>("atc"), 1.4);
}

TEST(ParseTest, badInputTest) {
    std::string testfile = "bad_units/test_unit_badDMG.json";

    try{
        JSON::parseFromFile(testfile);
        ASSERT_TRUE(true);
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(LVLupTest, checkHero){
	
	Hero testhero ("Hero", 500, 10, 50, 20, 20, 0.9, 1.1);
	Monster testmonster("Monster", 500, 20, 2.5);
	testhero.fightTilDeath(testmonster);
	ASSERT_EQ(5,testhero.getLevel());

}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
