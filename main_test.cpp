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

TEST(ParseTest, ParseExceptionTest) {
    std::string testfile = "notexists.json";

    try{
        JSON::parseFromFile(testfile);
		
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Can't open the json file.");
    }
}

TEST(HeroTests, checkHero){
	try{
		Hero h{ Hero::parse("Dark_Wanderer.json") };
		
        ASSERT_EQ(5,h.getPhysicalDmg());
		ASSERT_EQ(1.2,h.getAttackCoolDown());
		ASSERT_EQ(1,h.getDefense());
		ASSERT_EQ(85,h.getHealthPoints());
		ASSERT_EQ(1,h.getLevel());
		ASSERT_EQ(1,h.getMagicalDmg());
		ASSERT_EQ(85,h.getMaxHealthPoints());
		ASSERT_EQ("Prince Aidan of Khanduras",h.getName());
		ASSERT_EQ(2,h.getRadius());
		ASSERT_EQ("svg/Dark_Wanderer.svg",h.getTexture());
		
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
}
}

TEST(checkIsAlive, checkHeroAndMonster){
	try{
		Hero hero{Hero::parse("Dark_Wanderer.json")};
		Monster monster = Monster::parse("Fallen.json");
		
		hero.fightTilDeath(monster);
		
        ASSERT_EQ(true,hero.isAlive());
		ASSERT_EQ(false,monster.isAlive());
		
    } catch(std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Wrong JSON syntax!");
    }
}

TEST(LVLupAndXPTest, checkHero){
	
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

TEST(checkHeroPut, checkGame){
	try{
		
	Game game("maps/map.txt");
	Hero hero{ Hero::parse("Dark_Wanderer.json") };
	game.putHero(hero, 1, 1);
	game.putHero(hero, 1, 2);
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "A hero has already been set!");
	}
}

TEST(checkSetMapException, checkGame){
	try{
	Hero hero{ Hero::parse("Dark_Wanderer.json") };
	Monster m1 = Monster::parse("Fallen.json");
	
	Game game("maps/map.txt");
	game.putHero(hero, 1, 1);
	game.putMonster(m1, 1, 2);
	Map map("maps/map.txt");
	game.setMap(map);
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "The units are already set up. Map cannot be changed.");
	}
}

TEST(checkNotInitializedException, checkGame){
	try{
	Monster m1 = Monster::parse("Fallen.json");
	
	Game game("maps/map.txt");
	game.putMonster(m1, 1, 2);
	game.run();
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "The game is not initialized!");
	}
}

TEST(checkOccupiedException, checkGame){
	try{
	Hero hero{ Hero::parse("Dark_Wanderer.json") };
	
	Game game("maps/map.txt");
	game.putHero(hero, 0, 0);
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "There's a wall in this position!\n");
	}
}

TEST(checkMonsterCount, checkGame){
	try{
	Hero hero{ Hero::parse("Dark_Wanderer.json") };
	Monster m1 = Monster::parse("Fallen.json");
	
	Game game("maps/map.txt");
	game.putHero(hero, 1, 2);
	game.putMonster(m1, 1, 1);
	game.putMonster(m1, 1, 1);
	game.putMonster(m1, 1, 1);
	game.putMonster(m1, 1, 1);
	game.putMonster(m1, 1, 1);
	
	ASSERT_EQ(5,game.monsterCount(1,1));
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "");
	}
}

TEST(checkGetHeroPos, checkGame){
	try{
	Hero hero{ Hero::parse("Dark_Wanderer.json") };

	
	Game game("maps/map.txt");
	game.putHero(hero, 1, 2);
	
	ASSERT_EQ(1,game.getHeroPos().first);
	ASSERT_EQ(2,game.getHeroPos().second);
	
	}catch(std::runtime_error& e)
	{
		ASSERT_STREQ(e.what(), "");
	}
}



int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
