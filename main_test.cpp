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

TEST(dmgTest, checkHero){
	
	 std::string herofile = "Dark_Wanderer.json";
	 std::string monsterfile = "Fallen.json";
	 
	try{
        JSON heroData = JSON::parseFromFile(herofile);
		JSON monsterData = JSON::parseFromFile(monsterfile);
		
		Hero h = Hero(heroData.get<std::string>("name"),
		heroData.get<int>("base_health_points"),
		heroData.get<int>("base_damage"),
		heroData.get<float>("base_attack_cooldown"),
		heroData.get<int>("experience_per_level"),
		heroData.get<int>("health_point_bonus_per_level"),
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<float>("cooldown_multiplier_per_level"));
		
		Monster m = Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
		monsterData.get<int>("damage"), monsterData.get<float>("attack_cooldown"));
		
        ASSERT_EQ(5,h.getDamage());;
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
