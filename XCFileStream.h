#if _MSC_VER > 1000
#pragma once
#endif


#ifndef __XCFILESTREAM_H__
#define __XCFILESTREAM_H__


/// 隐藏依赖文件
/// C系统文件
/// C++系统文件
#include <string>
#include <list>
#include <vector>
using namespace std;

/// 其它库头文件
/// 本项目头文件


/// 无错
#define XC_ERR_NONE 0
/// 无效文件名或非指定文件格式
#define XC_ERR_INVALID_FILE_NAME (-1)


/// xun-test文件的读与写
class CXCFileStream
{
    
    
public:
    
    
    CXCFileStream(void);
    ~CXCFileStream(void);
    
    
    /*
     * 函数功能：读取CSV文件，分析其中的内容，然后存储在容器中。
     * 参数描述：
     *     [in] lpszFilename - 待读取的CSV文件；
     *     [in, out] vlStr - 存储分析后的CSV内容
     * 返回值：
     *     错误代码
     * 注意：这里因为特殊愿意（目前还不清楚），不是vector<list<string>>，而是vector<list<string> >。
     */
    const int ReadCsvData(LPCTSTR lpszFilename, vector<list<string> > &vlStr);
    /*
     * 函数功能：将容器中的内容经过排版、布局、添加分隔符后写入到CSV文件。
     * 参数描述：
     *     [in] lpszFilename - 待读取的CSV文件；
     *     [in] vlStr - 存储分析后的CSV内容
     * 返回值：
     *     错误代码
     * 注意：这里因为特殊愿意（目前还不清楚），不是vector<list<string>>，而是vector<list<string> >。
     */
    const int WriteCsvData(LPCTSTR lpszFilename, const vector<list<string> > &vlStr);
    
    
private:
    
    
    /// 判断是否是CSV文件
    const bool IsCsvFile(LPCTSTR lpszFilename);
    
    
};


#endif
