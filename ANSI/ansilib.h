#ifndef ANSI_LIB
#define ANSI_LIB

//字体版式类型
#define TEXT_TYPE_DEFAULT    0   //重置所有效果(默认)
#define TEXT_TYPE_HEAVY      1   //字体加粗
#define TEXT_TYPE_OBSCURE    2   //字体模糊
#define TEXT_TYPE_ITALIC     3   //斜体
#define TEXT_TYPE_UNDERLIE   4   //下划线
#define TEXT_TYPE_GLINT      5   //闪烁
#define TEXT_TYPE_REVCOLOR   7   //反色
#define TEXT_TYPE_HIDE       8   //隐藏
#define TEXT_TYPE_DELLINE    9   //删除线

//文本前景色
#define TEXT_FRONTCOLOR_BLACK   30  //黑色
#define TEXT_FRONTCOLOR_RED     31  //红色
#define TEXT_FRONTCOLOR_GREEN   32  //绿色
#define TEXT_FRONTCOLOR_YELLO   33  //黄色
#define TEXT_FRONTCOLOR_BLUE    34  //蓝色
#define TEXT_FRONTCOLOR_PRED    35  //洋红色
#define TEXT_FRONTCOLOR_CYAN    36  //青色
#define TEXT_FRONTCOLOR_WHITE   37  //白色
#define TEXT_FRONTCOLOR_DEFAULT 39  //默认

//文本背景色
#define TEXT_BACKCOLOR_BLACK    40  //黑色
#define TEXT_BACKCOLOR_RED      41  //红色
#define TEXT_BACKCOLOR_GREEN    42  //绿色
#define TEXT_BACKCOLOR_YELLO    43  //黄色
#define TEXT_BACKCOLOR_BLUE     44  //蓝色
#define TEXT_BACKCOLOR_PRED     45  //洋红色
#define TEXT_BACKCOLOR_CYAN     46  //青色
#define TEXT_BACKCOLOR_WHITE    47  //白色
#define TEXT_BACKCOLOR_DEFAULT  49  //默认

#define RESET_MODE_ALL  1   //清屏并复原整个终端设置
#define RESET_MODE_HALF 0   //仅恢复字体设置


#if defined(__cplusplus)
#include <iostream>
#include <string>
#include <conio.h>


void __ANSI_TEXT_TYPE(size_t _text_type);   //文本格式设置

void __ANSI_FRONTCOLOR_SET_NOR(size_t front_parameter);   //传统文本前景色设置

void __ANSI_BACKCOLOR_SET_NOR(size_t back_parameter);  //传统文本背景色设置

void __ANSI_FRONTCOLOR_SET_ADV(size_t color_code);   //256色文本前景色设置

void __ANSI_BACKCOLOR_SET_ADV(size_t color_code);   //256色文本背景色设置


/*ANSI光标控制*/

void __ANSI_CURSOR_UP(size_t lines = 1);    //光标上移 

void __ANSI_CURSOR_DOWN(size_t lines = 1);  //光标下移

void __ANSI_CURSOR_RIGHT(size_t columns = 1);   //光标右移

void __ANSI_CURSOR_LEFT(size_t columns = 1);    //光标左移

void __ANSI_CURSOR_MOVE(size_t lines_x,size_t columns_y);   //光标移动到指定位置

void __ANSI_CURSOR_SAVE();  //光标位置保存

void __ANSI_CURSOR_READ();  //读取保存的光标位置


void __ANSI_CLR_TERM();     //ANSI清屏

void __ANSI_LINECLR();      //清空光标所在行

void __ANSI_LINECLR_CUR();  //清除光标位置到行尾内容

void __ANSI_DISABLE_AUTO_NEWLINE(); //禁用终端自动换行

void __ANSI_ENABLE_AUTO_NEWLINE();  //启用自动换行



void __ANSI_DISABLE_CURSOR();   //禁用光标

void __ANSI_ENABLE_CURSOR();    //启用光标

void __ANSI_GOTO_INITIAL(size_t lines = 1);     //将光标移至某行行首


    #endif  //__cplusplus

#if defined(__STDC__)
#include <stdio.h>



    #endif  //__STDC__

#endif //ANSI_LIB



#ifndef ANSI_ADVFUNC
#define ANSI_ADVFUNC
#if defined(__cplusplus)

void __ANSI_TERM_RESET(size_t mode);   //复原终端

void __ANSI_INPUT_RESET();  //输入重置

template<typename _Type>
void __ANSI_LOCK_CURSOR(_Type &Type,size_t length);  //输入后锁定光标
void __ANSI_LOCK_CURSOR(std::string &str,size_t length);

    #endif //_cplusplus


#endif //ANSI_ADVFUNC