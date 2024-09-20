#ifndef ANSI_LIB
#define ANSI_LIB

//字体版式类型
#define TEXT_DEFAULT    0   //重置所有效果(默认)
#define TEXT_HEAVY      1   //字体加粗
#define TEXT_OBSCURE    2   //字体模糊
#define TEXT_ITALIC     3   //斜体
#define TEXT_UNDERLIE   4   //下划线
#define TEXT_GLINT      5   //闪烁
#define TEXT_REVCOLOR   7   //反色
#define TEXT_HIDE       8   //隐藏
#define TEXT_DELLINE    9   //删除线

//文本前景色
#define TEXT_FRONTCOLOR_BLACK   30  //黑色
#define TEXT_FRONTCOLOR_RED     31  //红色
#define TEXT_FRONTCOLOR_GREEN   32  //绿色
#define TEXT_FRONTCOLOR_YELLO   33  //黄色
#define TEXT_FRONTCOLOR_BLUE    34  //蓝色
#define TEXT_FRONTCOLOR_PRED    35  //洋红色
#define TEXT_FRONTCOLOR_CYAN    36  //青色
#define TEXT_FRONTCOLOR_WHITE   37  //白色

//文本背景色
#define TEXT_BACKCOLOR_BLACK    40  //黑色
#define TEXT_BACKCOLOR_RED      41  //红色
#define TEXT_BACKCOLOR_GREEN    42  //绿色
#define TEXT_BACKCOLOR_YELLO    43  //黄色
#define TEXT_BACKCOLOR_BLUE     44  //蓝色
#define TEXT_BACKCOLOR_PRED     45  //洋红色
#define TEXT_BACKCOLOR_CYAN     46  //青色
#define TEXT_BACKCOLOR_WHITE    47  //白色


#if defined(__cplusplus)
#include <iostream>

/* 终端字体修改 */
#define __ANSI_TEXT_TYPE_HEAVY()     std::cout<<"\033["<<TEXT_HEAVY<<"m";   //字体加粗
#define __ANSI_TEXT_TYPE_ITALIC()    std::cout<<"\033["<<TEXT_ITALIC<<"m";  //斜体字
#define __ANSI_TEXT_TYPE_UNDERLINE()    std::cout<<"\033["<<TEXT_UNDERLIE<<"m"; //下划线
#define __ANSI_TEXT_TYPE_GLINT()     std::cout<<"\033["<<TEXT_GLINT<<"m";   //字体闪烁
#define __ANSI_TEXT_TYPE_REVCOLOR()  std::cout<<"\033["<<TEXT_REVCOLOR<<"m";    //字体反色
#define __ANSI_TEXT_TYPE_HIDE()      std::cout<<"\033["<<TEXT_HIDE<<"m";    //隐藏
#define __ANSI_TEXT_TYPE_DELLINE()   std::cout<<"\033["<<TEXT_UNDERLIE<<"m";    //字体删除线

void __ANSI_FRONTCOLOR_SET_NOR(size_t parameter);   //传统文本前景色设置

void __ANSI_FRONTCOLOR_SET_ADV(size_t color_code);   //256色文本前景色设置



#endif  //__cplusplus

#if defined(_STDC_)
#include <stdio.h>



#endif  //_STDC_

#endif //ANSI_LIB