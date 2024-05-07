using namespace std;
#include<iostream>

//int main()
//{
//    string str;
//    int a, b, c;
//    //while (cin >> str)
//    while (operator>>(cin, str))
//    {
//        cout << str << endl;
//    }
//
//
//    // 单个元素循环输入
//    while (cin >> a)
//    {
//        // ...
//    }
//
//    // 多个元素循环输入
//    while (c >> a >> b >> c)
//    {
//        // ...
//    }
//
//    // 整行接收
//    while (cin >> str)
//    {
//        // ...
//    }
//}



//class Date
//{
//    friend ostream& operator << (ostream& out, const Date& d);
//    friend istream& operator >> (istream& in, Date& d);
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    operator bool()
//    {
//        // 这里是随意写的，假设输入_year为0，则结束
//        if (_year == 0)
//            return false;
//        else
//            return true;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//istream& operator >> (istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//ostream& operator << (ostream& out, const Date& d)
//{
//    out << d._year << " " << d._month << " " << d._day;
//    return out;
//}
//// C++ IO流，使用面向对象+运算符重载的方式
//// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//    // 自动识别类型的本质--函数重载
//    // 内置类型可以直接使用--因为库里面ostream类型已经实现了
//    int i = 1;
//    double j = 2.2;
//    cout << i << endl;
//    cout << j << endl;
//    // 自定义类型则需要我们自己重载<< 和 >>
//    Date d(2022, 4, 10);
//    cout << d;
//
//    while (d)
//    {
//       cin >> d;
//       cout << d;
//    }
//    return 0;
//}


#include<fstream>

class Date
{
    friend ostream& operator << (ostream& out, const Date& d);
    friend istream& operator >> (istream& in, Date& d);
public:
    Date(int year = 1, int month = 1, int day = 1)
        :_year(year)
        , _month(month)
        , _day(day)
    {}
    operator bool()
    {
        // 这里是随意写的，假设输入_year为0，则结束
        if (_year == 0)
            return false;
        else
            return true;
    }
private:
    int _year;
    int _month;
    int _day;
};
istream& operator >> (istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
ostream& operator << (ostream& out, const Date& d)
{
    out << d._year << " " << d._month << " " << d._day;
    return out;
}

struct ServerInfo
{
    char _address[32];
    int _port;
    Date _date;
};

struct ConfigManager
{
public:
    ConfigManager(const char* filename)
        :_filename(filename)
    {}
    void WriteBin(const ServerInfo& info)
    {
        ofstream ofs(_filename, ios_base::out | ios_base::binary);
        ofs.write((const char*)&info, sizeof(info));
    }
    void ReadBin(ServerInfo& info)
    {
        ifstream ifs(_filename, ios_base::in | ios_base::binary);
        ifs.read((char*)&info, sizeof(info));
    }
    // C++文件流的优势就是可以对内置类型和自定义类型，都使用
    // 一样的方式，去流插入和流提取数据
    // 当然这里自定义类型Date需要重载>> 和 <<
    // istream& operator >> (istream& in, Date& d)
    // ostream& operator << (ostream& out, const Date& d)

    void WriteText(const ServerInfo& info)
    {
        ofstream ofs(_filename);
        ofs << info._address << " " << info._port << " " << info._date;
    }
    void ReadText(ServerInfo& info)
    {
        ifstream ifs(_filename);
        ifs >> info._address >> info._port >> info._date;
    }
private:
    string _filename; // 配置文件
};

int main()
{
    ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };

    // 二进制读写
    ConfigManager cf_bin("test.bin");
    cf_bin.WriteBin(winfo);
    ServerInfo rbinfo;
    cf_bin.ReadBin(rbinfo);
    cout << rbinfo._address << " " << rbinfo._port << " "<< rbinfo._date << endl;

    // 文本读写
    ConfigManager cf_text("test.text");
    cf_text.WriteText(winfo);
    ServerInfo rtinfo;
    cf_text.ReadText(rtinfo);
    cout << rtinfo._address << " " << rtinfo._port << " " << rtinfo._date << endl;
    return 0;
}
