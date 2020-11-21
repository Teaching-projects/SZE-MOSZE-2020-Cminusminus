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

TEST(ParseTest, goodInputTest) {
    std::string testfile = "units/test_unit_1.json";

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
		
        ASSERT_EQ(3,h.getDamage());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(dmgAfterFightTest, checkHero){
	
	 std::string herofile = "Dark_Wanderer.json";
	 std::string monsterfile = "Blood_Raven.json";
	 
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
		h.fightTilDeath(m);
		
        ASSERT_EQ(3,h.getDamage());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(LVLupTest, checkHero){
	
	 std::string file = "scenario1.json";
	 
	try{
     std::string hero_file;
    std::list<std::string> monster_files;
    try {
        JSON scenario = JSON::parseFromFile(file); 
        if (!(scenario.count("hero")&&scenario.count("monsters"))) std::cout << "error";
        else {
            hero_file=scenario.get<std::string>("hero");
            std::istringstream monsters(scenario.get<std::string>("monsters"));
            std::copy(std::istream_iterator<std::string>(monsters),
                std::istream_iterator<std::string>(),
                std::back_inserter(monster_files));
        }
    } catch (const JSON::ParseException& e) {std::cout << "error";}
 
    try { 
        Hero hero{Hero::parse(hero_file)};
        std::list<Monster> monsters;
        for (const auto& monster_file : monster_files)
            monsters.push_back(Monster::parse(monster_file));        
 
        while (hero.isAlive() && !monsters.empty()) {
            std::cout 
                << hero.getName() << "(" << hero.getLevel()<<")"
                << " vs "
                << monsters.front().getName()
                <<std::endl;
            hero.fightTilDeath(monsters.front());
            if (!monsters.front().isAlive()) monsters.pop_front();
        }
    } catch (const JSON::ParseException& e) { std::cout << "JSON parsing error.";}
		
        ASSERT_EQ(8,hero.getLevel());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
