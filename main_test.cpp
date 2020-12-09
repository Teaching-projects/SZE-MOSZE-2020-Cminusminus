#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include "Map.h"
#include "Game.h"
#include "MarkedMap.h"
#include "PreparedGame.h"
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
		int lr;
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
	
	if (heroData.count("light_radius_bonus_per_level"))
	{
		lr = heroData.get<int>("light_radius_bonus_per_level");
	}
	else
	{
		lr = 1;
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
		heroData.get<int>("magical_bonus_per_level"),
		heroData.get<int>("light_radius"),
		lr,
		heroData.get<std::string>("texture"));
		
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
		dmg2, monsterData.get<double>("attack_cooldown"), monsterData.get<int>("defense"), monsterData.get<std::string>("texture"));
		
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
		int lr;
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
	if (heroData.count("light_radius_bonus_per_level"))
	{
		lr = heroData.get<int>("light_radius_bonus_per_level");
	}
	else
	{
		lr = 1;
	}
	
	Hero h = Hero (heroData.get<std::string>("name"),
		heroData.get<int>("base_health_points"),
		dmg,
		heroData.get<double>("base_attack_cooldown"),
		heroData.get<int>("defense"),
		heroData.get<int>("experience_per_level"),
		heroData.get<int>("health_point_bonus_per_level"),
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<double>("cooldown_multiplier_per_level"),
		heroData.get<int>("defense_bonus_per_level"),
		heroData.get<int>("magical_bonus_per_level"),
		heroData.get<int>("light_radius"),
		lr,
		heroData.get<std::string>("texture")
	);
		
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
		dmg2, monsterData.get<double>("attack_cooldown"), monsterData.get<int>("defense"), monsterData.get<std::string>("texture"));
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
	
	std::string m="maps/map2.txt";
	Map mapp(m);
	ASSERT_EQ(1,mapp.get(0,5));

}

TEST(checkFree, checkMap){
	
	std::string m="maps/map2.txt";
	Map mapp(m);
	ASSERT_EQ(0,mapp.get(3,1));

}

TEST(checkWrongIndex, checkMap){
	try{
		std::string m="maps/map2.txt";
	Map mapp(m);
	
	ASSERT_EQ(0,mapp.get(20,20));
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Wrong index!");
	}
}

TEST(checkWall, checkMarkedMap){
	try{
	std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	
	ASSERT_EQ(1,map.get(0,3));
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Wrong index!");
	}
}

TEST(checkFree, checkMarkedMap){
	try{
	std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	
	ASSERT_EQ(0,map.get(5,3));
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Wrong index!");
	}
}

TEST(checkWrongIndex, checkMarkedMap){
	try{
	std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	
	ASSERT_EQ(0,map.get(30,3));
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Wrong index!");
	}
}

TEST(checkHeroPosition, checkMarkedMap){
	try{
	std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	ASSERT_EQ(1,map.getHeroPosition().first);
	ASSERT_EQ(2,map.getHeroPosition().second);
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Map or parse error!");
	}
}

TEST(checkMonstersPosition, checkMarkedMap){
	try{
		std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	
	ASSERT_EQ(3,map.getMonsterPosition('3').begin()->first);
	ASSERT_EQ(6,map.getMonsterPosition('3').begin()->second);
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Map or parse error!");
	}
}

TEST(checkRowsAndCols, checkMarkedMap){
	
	try{
    std::string mm="maps/markedmap.txt";
	MarkedMap map(mm);
	
	ASSERT_EQ(14,map.getMaxCols());
	ASSERT_EQ(7,map.getRows());
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Map or parse error!");
	}
}

TEST(checkTextures, checkSVGRenderer){
	try{
	Hero hero{ Hero::parse("Dark_Wanderer.json") };
	Monster m1 = Monster::parse("Fallen.json");
	Monster m2 = Monster::parse("Zombie.json");
	Monster m3 = Monster::parse("Blood_Raven.json");
	
	ASSERT_EQ("svg/Dark_Wanderer.svg",hero.getTexture());
	ASSERT_EQ("svg/Fallen.svg",m1.getTexture());
	ASSERT_EQ("svg/Zombie.svg",m2.getTexture());
	ASSERT_EQ("svg/Blood_Raven.svg",m3.getTexture());
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "Map or parse error!");
	}
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
