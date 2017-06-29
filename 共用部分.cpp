enum underSubstance{water,ground,bridge,house,tree};
enum aboveSubstance{bomb,arrowUp,arrowDown,arrowLeft,arrowRight,
                    player1,player2,
                    wood,air};

class substance
{
public:
    underSubstance us;
    aboveSubstance as;
    substance(underSubstance tus,aboveSubstance tas):us(tus),as(tas) {}
}; //substance 规定的是一个方块，在每一个方块里面，先看 aboveSubstance ，如果有就直接绘制，
  //如果没有（即aboveSubstance为air），就绘制underSubstance
//在这里的时候金鹏翔已经处理过了，如果是树的话，aboveSubstance一定是air

substance temp[10][10];
