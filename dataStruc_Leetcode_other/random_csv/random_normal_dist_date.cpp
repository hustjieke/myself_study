#include <cmath>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

static inline void ifLegalDate(unsigned int& _num, int& cnt) {
    int num = _num;
    num = num / 1000;
    if (0 == (num % 10) && (0 != ((num / 10) % 10))) {  // e.g. 1900 x0 
        ++cnt;
        _num += 1000;
    } else if (0 == (num % 10) && (0 == ((num / 10) % 10))) {  // e.g. 1900 00
        ++cnt;
        _num += 11000;
    } else if (0 != (num % 10) && (0 == ((num / 10) % 10))){  // e.g. 1900 0x
        ++cnt;
        _num += 10000;
    } else {
        // do nothing.
    }
}

static inline unsigned int getNumMod_10(unsigned int& num) {
    unsigned int temp = num % 10;
    num = num / 10;
    return temp;
}

static inline std::string getDateStrValue(const unsigned int num) {
    unsigned int tmp_num = num;
    unsigned int second = getNumMod_10(tmp_num);
    unsigned int minute = getNumMod_10(tmp_num);
    unsigned int hour   = getNumMod_10(tmp_num);
    unsigned int day    = getNumMod_10(tmp_num);
    unsigned int month  = getNumMod_10(tmp_num);
    unsigned int year   = tmp_num;

    ostringstream os;
    os << year << "/0"
        << month << "/0"
        << day   << " 0"
        << hour  << ":0"
        << minute<< ":0"
        <<second; //  << ":0";
    return os.str();
}

int main()
{
    int i;  // = 40;  // just for test
    cout << "请输入你想要生成的行数,并按enter结束：";
    cin >> i;
    cout << endl << "数据生成中...";
    normal_distribution<> num(595555499, 1.5);
    default_random_engine e;  // generate random value

    ofstream fIntOut;
    ofstream fDateOut;
    //fIntOut.open("int_groupby_norm.csv", ios_base::out);
    fDateOut.open("date_groupby_norm.csv", ios_base::out);  // 需要关闭吗?

    // int i = 200000000;
    int cnt = 0;
    while (i--) {
        //ostringstream os_int;
        ostringstream os_date;
        for (size_t j = 0; j < 3; j++) {
            unsigned int _num = lround(num(e));
            //if (ifLegalDate(_num)) {
            ifLegalDate(_num, cnt);
            std::string dateFormat = getDateStrValue(_num);
            //os_int << _num;
            os_date << dateFormat;
            if (2 == j) {  // 最后加 "\n"
                //os_int << "\n";
                os_date << "\n";
                break;
            } else {  // 否则加","
                //os_int << ",";
                os_date << ",";
            }
            //} else {
            //    // ++i;  // do it again
            //    break;
            //}
        }  // for end

        fDateOut << os_date.str();
        //fIntOut << os_int.str();
        // cout << os_date.str();
    } // while end

    cout << "cal nums: " << cnt << endl;

    return 0;
}
