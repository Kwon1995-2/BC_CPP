//7장-10.RECTCOL2.H의 일부
class ColorRect : public Rectangle{
    //전과 같음
    void IncreaseAll (){
        ++ color;
        ++ base;
        ++ height;
    }
};