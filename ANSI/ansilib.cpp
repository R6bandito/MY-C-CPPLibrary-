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
    if (mode == 1)
    {
        resetTextAttributes();
        __ANSI_CLR_TERM();
        __ANSI_ENABLE_AUTO_NEWLINE();
    }
    else if (mode == 0)
    {
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

/*移到行首
lines-----行数参数,默认为1
*/
void __ANSI_GOTO_INITIAL(size_t lines)
{
    std::cout << "\033[" << lines << "H";
}

/*该函数已包含了输入函数，其功能是限定输入宽度。通过传入参数来
进行限定*/
template <typename _Type>
void __ANSI_LOCK_CURSOR(_Type &Type, size_t length)
{
}
void __ANSI_LOCK_CURSOR(std::string &str,const size_t length)
{
    size_t cont = 0;
    str.resize(length); // 空间设置
    while (true){
        str[cont] = _getch();
        if((str[cont] > 32 && str[cont] < 127) && cont<length)
            std::cout<<str[cont];

        if(cont == length-1){
            __ANSI_DISABLE_CURSOR();
            str[cont-1] = '\0';
        }

        if(str[cont] == '\b'){
            std::cout<<"\b \b";     //从终端上删除该字符
            str[--cont] = '\0';     //从容器中删除该字符
        }

        if(str[cont++] == '\r')   break;
    }
    __ANSI_ENABLE_CURSOR();
}

#endif //_cplusplus