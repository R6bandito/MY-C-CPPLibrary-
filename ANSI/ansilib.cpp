#include "ansilib.h"

#if defined(__cplusplus)
/*文本字体的格式设置
_text_type-----传入字体设置参数
*/
void __ANSI_TEXT_TYPE(size_t _text_type)
{
    std::cout << "\033[" << _text_type << "m";
}

/*文本前景色的设置（传统模式）
front_parameter-----字体的颜色代码
*/
void __ANSI_FRONTCOLOR_SET_NOR(size_t front_parameter)
{
    std::cout << "\033[" << front_parameter << "m";
}

/*文本的前景色设置（256色高精度设置）
color_code-----颜色代码，范围为0-255
*/
void __ANSI_FRONTCOLOR_SET_ADV(size_t color_code)
{
    std::cout << "\033[38;5;" << color_code << "m";
}

/*文本背景色设置（传统模式）
back_parameter-----背景色颜色代码
*/
void __ANSI_BACKCOLOR_SET_NOR(size_t back_parameter)
{
    std::cout << "\033[" << back_parameter << "m";
}

void __ANSI_BACKCOLOR_SET_ADV(size_t color_code)
{
    std::cout << "\033[48;5;" << color_code << "m";
}

/*光标上移设置
lines-----移动行数，默认为1
*/
void __ANSI_CURSOR_UP(size_t lines)
{
    std::cout << "\033[" << lines << "A";
}

/*光标下移设置
lines-----移动行数，默认为1
*/
void __ANSI_CURSOR_DOWN(size_t lines)
{
    std::cout << "\033[" << lines << "B";
}

/*光标右移设置
columns-----列数,默认为1
*/
void __ANSI_CURSOR_RIGHT(size_t columns)
{
    std::cout << "\033[" << columns << "C";
}

/*光标左移设置
columns-----列数，默认为1
*/
void __ANSI_CURSOR_LEFT(size_t columns)
{
    std::cout << "\033[" << columns << "D";
}

/*光标移动到指定位置
lines_x-----行数参数
columns_y-----列数参数
*/
void __ANSI_CURSOR_MOVE(size_t lines_x, size_t columns_y)
{
    std::cout << "\033[" << lines_x << ";" << columns_y << "H";
}

/*保存当前的光标位置
 */
void __ANSI_CURSOR_SAVE()
{
    std::cout << "\033[s";
}

/*读取保存的光标位置
 */
void __ANSI_CURSOR_READ()
{
    std::cout << "\033[u";
}

/*清屏
 */
void __ANSI_CLR_TERM()
{
    std::cout << "\033[2J\033[H";
}

/*清空光标所在行内容
 */
void __ANSI_LINECLR()
{
    std::cout << "\033[2K";
}

/*清除从光标位置到行尾的内容
 */
void __ANSI_LINECLR_CUR()
{
    std::cout << "\033[K";
}

/*隐藏光标
 */
void __ANSI_DISABLE_CURSOR()
{
    std::cout << "\033[?25l";
}

/*启用光标
 */
void __ANSI_ENABLE_CURSOR()
{
    std::cout << "\033[?25h";
}

/*禁用终端自动换行
 */
void __ANSI_DISABLE_AUTO_NEWLINE()
{
    std::cout << "\033[?7l";
}

/*启用自动换行
 */
void __ANSI_ENABLE_AUTO_NEWLINE()
{
    std::cout << "\033[?7h";
}

/*复原终端
 */
void resetTextAttributes();
void __ANSI_TERM_RESET(size_t mode)
{
    if (mode == 1){
        resetTextAttributes();
        __ANSI_CLR_TERM();
        __ANSI_ENABLE_AUTO_NEWLINE();
    }
    else if(mode == 0){
        resetTextAttributes();
    }
}
void resetTextAttributes()
{
    __ANSI_TEXT_TYPE(TEXT_TYPE_DEFAULT);
    __ANSI_FRONTCOLOR_SET_NOR(TEXT_FRONTCOLOR_DEFAULT);
    __ANSI_BACKCOLOR_SET_NOR(TEXT_BACKCOLOR_DEFAULT);
    __ANSI_ENABLE_CURSOR();
}

/*该函数用于当用户进行错误输入且换行输出错误提示信息后的返回
会清空该行的错误提示信息，并且回到光标保存位置并清空后续信息
该函数需配合光标保存进行使用*/
void __ANSI_INPUT_RESET()
{
    __ANSI_LINECLR();
    __ANSI_CURSOR_READ();
    __ANSI_LINECLR_CUR();
}

#endif //_cplusplus