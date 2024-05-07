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
//    // ����Ԫ��ѭ������
//    while (cin >> a)
//    {
//        // ...
//    }
//
//    // ���Ԫ��ѭ������
//    while (c >> a >> b >> c)
//    {
//        // ...
//    }
//
//    // ���н���
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
//        // ����������д�ģ���������_yearΪ0�������
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
//// C++ IO����ʹ���������+��������صķ�ʽ
//// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//    // �Զ�ʶ�����͵ı���--��������
//    // �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
//    int i = 1;
//    double j = 2.2;
//    cout << i << endl;
//    cout << j << endl;
//    // �Զ�����������Ҫ�����Լ�����<< �� >>
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
        // ����������д�ģ���������_yearΪ0�������
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
    // C++�ļ��������ƾ��ǿ��Զ��������ͺ��Զ������ͣ���ʹ��
    // һ���ķ�ʽ��ȥ�����������ȡ����
    // ��Ȼ�����Զ�������Date��Ҫ����>> �� <<
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
    string _filename; // �����ļ�
};

int main()
{
    ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };

    // �����ƶ�д
    ConfigManager cf_bin("test.bin");
    cf_bin.WriteBin(winfo);
    ServerInfo rbinfo;
    cf_bin.ReadBin(rbinfo);
    cout << rbinfo._address << " " << rbinfo._port << " "<< rbinfo._date << endl;

    // �ı���д
    ConfigManager cf_text("test.text");
    cf_text.WriteText(winfo);
    ServerInfo rtinfo;
    cf_text.ReadText(rtinfo);
    cout << rtinfo._address << " " << rtinfo._port << " " << rtinfo._date << endl;
    return 0;
}
