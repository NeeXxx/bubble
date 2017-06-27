enum SUBSTANCE{water,bridge,wood,tree,player1,player2,
               house,air,bomb,arrowUp,arrowDown,arrowLeft,arrowRight};

struct BLOCK
{
    bool canBeIn;
    bool canBeBroken;
    SUBSTANCE substance;
};

BLOCK map[10][10];
