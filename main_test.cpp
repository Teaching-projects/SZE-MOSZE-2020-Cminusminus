#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include "Map.h"
#include "Game.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>

TEST(ParseFromStringTest, checkIfEquals){
	std::string text = 
	"{\"name\": \"Bela\",\"hp\": 500,\"dmg\": 20, \"atc\": 1.4}";
	JSON json = JSON::parseFromString(text);
	
  ASSERT_DOUBLE_EQ(json.get<double>("atc"), 1.4);
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

TEST(phDMGTest, checkHero){
	
	 std::string herofile = "Dark_Wanderer.json";
	 std::string monsterfile = "Fallen.json";
	 
	try{
        JSON heroData = JSON::parseFromFile(herofile);
		JSON monsterData = JSON::parseFromFile(monsterfile);
		Damage dmg;
	if (heroData.count("base_damage"))
	{
		dmg.physical = heroData.get<int>("base_damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (heroData.count("magical-damage"))
	{
		dmg.magical = heroData.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}
		Hero h = Hero(heroData.get<std::string>("name"),
		heroData.get<int>("base_health_points"),
		dmg,
		heroData.get<double>("base_attack_cooldown"),
		heroData.get<int>("defense"),
		heroData.get<int>("experience_per_level"),
		heroData.get<int>("health_point_bonus_per_level"),
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<double>("cooldown_multiplier_per_level"),
		heroData.get<int>("defense_bonus_per_level"),
		heroData.get<int>("magical_bonus_per_level"));
		
		Damage dmg2;
	if (monsterData.count("damage"))
	{
		dmg2.physical = monsterData.get<int>("damage");
	}
	else
	{
		dmg2.physical = 0;
	}

	if (monsterData.count("magical-damage"))
	{
		dmg2.magical = monsterData.get<int>("magical-damage");
	}
	else
	{
		dmg2.magical = 0;
	}
		Monster m = Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
		dmg2, monsterData.get<double>("attack_cooldown"), monsterData.get<int>("defense"));
		
        ASSERT_EQ(5,h.getPhysicalDmg());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(mgicalDMGAfterFightTest, checkHero){
	
	 std::string herofile = "Dark_Wanderer.json";
	 std::string monsterfile = "Blood_Raven.json";
	 
	try{
        JSON heroData = JSON::parseFromFile(herofile);
		JSON monsterData = JSON::parseFromFile(monsterfile);
		Damage dmg;
	if (heroData.count("base_damage"))
	{
		dmg.physical = heroData.get<int>("base_damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (heroData.count("magical-damage"))
	{
		dmg.magical = heroData.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}
		Hero h = Hero(heroData.get<std::string>("name"),
		heroData.get<int>("base_health_points"),
		dmg,
		heroData.get<double>("base_attack_cooldown"),
		heroData.get<int>("defense"),
		heroData.get<int>("experience_per_level"),
		heroData.get<int>("health_point_bonus_per_level"),
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<double>("cooldown_multiplier_per_level"),
		heroData.get<int>("defense_bonus_per_level"),
		heroData.get<int>("magical_bonus_per_level"));
		
		Damage dmg2;
	if (monsterData.count("damage"))
	{
		dmg2.physical = monsterData.get<int>("damage");
	}
	else
	{
		dmg2.physical = 0;
	}

	if (monsterData.count("magical-damage"))
	{
		dmg2.magical = monsterData.get<int>("magical-damage");
	}
	else
	{
		dmg2.magical = 0;
	}
		Monster m = Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
		dmg2, monsterData.get<double>("attack_cooldown"), monsterData.get<int>("defense"));
		h.fightTilDeath(m);
		
        ASSERT_EQ(6,h.getMagicalDmg());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(LVLupTest, checkHero){
	
	try{
        Hero hero{Hero::parse("Dark_Wanderer.json")};
		Monster m1 = Monster::parse("Fallen.json");
		Monster m2 = Monster::parse("Zombie.json");
		Monster m3 = Monster::parse("Blood_Raven.json");
		
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m3);
		
        ASSERT_EQ(7,hero.getLevel());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(HPTest, checkHero){
	
	try{
        Hero hero{Hero::parse("Dark_Wanderer.json")};
		Monster m1 = Monster::parse("Fallen.json");
		Monster m2 = Monster::parse("Zombie.json");
		Monster m3 = Monster::parse("Blood_Raven.json");
		
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m3);
		
        ASSERT_EQ(113,hero.getHealthPoints());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(XPTest, checkHero){
	
	try{
        Hero hero{Hero::parse("Dark_Wanderer.json")};
		Monster m1 = Monster::parse("Fallen.json");
		Monster m2 = Monster::parse("Zombie.json");
		Monster m3 = Monster::parse("Blood_Raven.json");
		
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m2);
		hero.fightTilDeath(m1);
		hero.fightTilDeath(m3);
		
        ASSERT_EQ(131,hero.GetXP());
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }

}

TEST(checkWrongMapName, checkGame){
	
	try{
       Game game("mapx.txt");
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "WrongIndexException!");
    }

}

TEST(checkWall, checkMap){
	
	Map mapp("map2.txt");
	ASSERT_EQ(1,mapp.get(0,5));

}

TEST(checkMultipleHeros, checkGame){
	
	try{
       Game game("map2.txt");
	   Hero hero{Hero::parse("Dark_Wanderer.json")};
	   
		game.putHero(hero, 0, 5);	  
	   
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "OccupiedException");
    }

}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
