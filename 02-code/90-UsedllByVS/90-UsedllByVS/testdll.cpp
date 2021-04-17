#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef void (*showWiget)(); //函数指针类型
typedef void (*DisplayInto)(); //函数指针类型
int main(){
    // HINSTANCE Hint = LoadLibrary("qtdialog.dll");//加载我们刚才生成的dll
    // HINSTANCE Hint = LoadLibrary(".\\Dll\\qtdialog.dll");//加载我们刚才生成的dll
    HINSTANCE Hint = LoadLibraryEx("F:\\GithubRepository\\WeiMuYang\\qtcreator-study\\03-qt-study-code\\90-UsedllByVS\\90-UsedllByVS\\qtdialog.dll",NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	DisplayInto PrintDll = (DisplayInto)GetProcAddress(Hint, "DisplayIntoDll");
    showWiget showWidget = (showWiget)GetProcAddress(Hint, "showWidget");
 
    PrintDll();
	getchar();
    showWidget();
    FreeLibrary(Hint);//卸载dll文件；
	return 0;
}
