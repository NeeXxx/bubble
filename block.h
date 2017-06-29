#ifndef BLOCK_H
#define BLOCK_H

enum underSubstance{water,ground,bridge,house,tree};
enum aboveSubstance{bomb,arrowUp,arrowDown,arrowLeft,arrowRight,
                    player1,player2,
                    wood,air};
enum texture{t_nothing,t_tree,t_house,t_player1,t_player2,t_wood,t_bomb,t_flame};

//希望底部的东西是不可改变的
class under
{
    underSubstance s;
    bool canBeIn;
public:
    under(underSubstance us,bool cbi):s(us),canBeIn(cbi) {}
    bool inable() { return canBeIn; }
    underSubstance substance() { return s; }
};

const under uWater(water,false),
            uHouse(house,false),//不可进入
            uGround(ground,true),
            uTree(tree,true),
            uBridge(bridge,true);//可进入

class above
{
    aboveSubstance s;
    bool canBeIn;
    bool canBePush;
public:
    above(aboveSubstance as,bool cbi,bool cbp):s(as),canBeIn(cbi),canBePush(cbp) {}
    bool pushable() { return canBePush; }
    bool inable() { return canBeIn; }
    aboveSubstance substance() { return s; }
};

const above aBomb(bomb,false,false),//不可推
            aWood(wood,false,true),//可推        //不可进入
            aArrowUp(arrowUp,true,false),
            aArrowDown(arrowDown,true,false),
            aArrowLeft(arrowLeft,true,false),
            aArrowRight(arrowRight,true,false),
            aPlayer1(player1,true,false),
            aPlayer2(player1,true,false),
            aAir(air,true,false);               //可进入

class substance
{
public:
    underSubstance us;
    aboveSubstance as;
    substance(underSubstance tus,aboveSubstance tas):us(tus),as(tas) {}
};

substance temp[10][10];

class block
{
    under u;
    above a;
public:
    block(under tu,above ta):u(tu),a(ta) {}
    void destroyAbove();
    void addAbove(above ta);
    above getAbove() { return a; }
    bool inable();
    bool pushable();
    bool hidable();
    bool haveAbove();
    substance appearance(); //画图必须调用appearance
};

#endif // BLOCK_H
