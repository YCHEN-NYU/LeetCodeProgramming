/*
 Press any key to change color, do you want to try it. Please hurry up!
 */


#include <conio.h>
void main(void)
{
    int color;
    for (color = 0; color < 8; color++)
        　{
            　textbackground(color); /*设置文本的背景颜色*/
            　cprintf("This is color %d\r\n", color);
            　cprintf("ress any key to continue\r\n");
            　getch(); /*输入字符看不见*/
            　}
}
