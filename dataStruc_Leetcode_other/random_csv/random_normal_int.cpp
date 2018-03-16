#include <cmath>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>

/*
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
*/

class intCsv {
    public:
        intCsv(std::string file, int64_t rows, int64_t cols, bool hasDelimiter = false) : m_file(file),
        m_rows(rows), m_cols(cols), m_hasDelimiter(hasDelimiter) { }

        ~intCsv() { }
    public:
        void generateNorm() {
            std::normal_distribution<> num(595555499, 1.5);
            std::default_random_engine e;  // generate random value

            std::ofstream fIntOut;
            fIntOut.open(m_file, std::ios_base::out);
            
            while (m_rows--) {
                std::ostringstream os_int;
                std::string Delimiter = "|";

                for (size_t col = 0; col < m_cols; col++) {
                    unsigned int _num = lround(num(e));
                    if (m_hasDelimiter) {
                        os_int << Delimiter << _num << Delimiter;
                        if ((m_cols-1) == col) {
                            os_int << "\n";
                            break;
                        } else {  // add ","
                            os_int << ",";
                        }
                    } else {
                        os_int << _num;
                        if ((m_cols-1) == col) {
                            os_int << "\n";
                            break;
                        } else {  // add ","
                            os_int << ",";
                        }
                    }  // if end
                }  // for end

                //  write into file
                fIntOut << os_int.str();
            }  // while end
        }
        
    private:
        intCsv() { }

    private:
        std::string m_file;
        int64_t m_rows;
        int64_t m_cols;
        bool m_hasDelimiter;
};

class stdCsv {
    public:
        stdCsv(std::string file, int64_t rows, bool hasDelimiter = false) : m_file(file),
        m_rows(rows), m_hasDelimiter(hasDelimiter) { }

        ~stdCsv() { }
    public:
        void generateNorm() {
            std::normal_distribution<> num(595555499, 1.5);
            std::default_random_engine e;  // generate random value

            std::ofstream fIntOut;
            fIntOut.open(m_file, std::ios_base::out);
            
            while (m_rows--) {
                std::ostringstream ostring;
                std::string Delimiter = "|";

                double d_num = num(e);
                unsigned int _num = lround(d_num);
                if (m_hasDelimiter) {
                    ostring << Delimiter << _num << Delimiter << ",";  // int
                    ostring << Delimiter << _num << Delimiter << ",";  // long
                    ostring << Delimiter << d_num << Delimiter << ",";  // double
                    ostring << Delimiter << "abcdefdjfj" << Delimiter << ",";  // char
                    ostring << Delimiter << "abcdefdjfj" << Delimiter << ","; // varchar
                    ostring << Delimiter << "2017/11/06 11:12:10" << Delimiter << ",";  // date
                    ostring << Delimiter << "2017/11/06 11:12:10.123456789" << Delimiter << ",";  // tms
                    ostring << Delimiter << "2017-11" << Delimiter << ",";  // ymitv
                    ostring << Delimiter << "11 15:02:23.123456789" << Delimiter << ",";  // dsitv
                    ostring << Delimiter << _num << Delimiter << ",";  // int
                    ostring << Delimiter << _num << Delimiter << ",";  // long
                    ostring << Delimiter << d_num << Delimiter << ",";  // double
                    ostring << Delimiter << "abcdefdjfj" << Delimiter << ",";  // char
                    ostring << Delimiter << "abcdefdjfj" << Delimiter << ","; // varchar
                    ostring << Delimiter << "2017/11/06 11:12:10" << Delimiter << ",";  // date
                    ostring << Delimiter << "2017/11/06 11:12:10.123456789" << Delimiter << ",";  // tms
                    ostring << Delimiter << "2017-11" << Delimiter << ",";  // ymitv
                    ostring << Delimiter << "11 15:02:23.123456789" << Delimiter << "\n";  // dsitv
                } else {
                    ostring << _num << ",";  // int
                    ostring << _num << ",";  // long
                    ostring << d_num << ","; // double
                    ostring << "abcdefdjfj" << ",";  // char
                    ostring << "abcdefdjfj" << ",";  // varchar
                    ostring << "2017/11/06 11:12:10" << ",";  // date
                    ostring << "2017/11/06 11:12:10.123456789" << ",";  // tms
                    ostring << "2017-11" << ",";  // ymitv
                    ostring << "11 15:02:23.123456789" << ",";  // dsitv
                    ostring << _num << ",";  // int
                    ostring << _num << ",";  // long
                    ostring << d_num << ","; // double
                    ostring << "abcdefdjfj" << ",";  // char
                    ostring << "abcdefdjfj" << ",";  // varchar
                    ostring << "2017/11/06 11:12:10" << ",";  // date
                    ostring << "2017/11/06 11:12:10.123456789" << ",";  // tms
                    ostring << "2017-11" << ",";  // ymitv
                    ostring << "11 15:02:23.123456789" << "\n";  // dsitv
                }  // if end

                //  write into file
                fIntOut << ostring.str();
            }  // while end
        }
        
    private:
        stdCsv() { }

    private:
        std::string m_file;
        int64_t m_rows;
        bool m_hasDelimiter;
};

int main()
{
    int rows, cols;
    std::cout << "enter a num for rows:";
    std::cin >> rows;
    std::cout << "enter a num for cols:";
    std::cin >> cols;

    std::cout << "file data generating:" << std::endl;

    std::string fileNum = std::to_string(rows/10000);
    /*
    std::string file1("int_long_norm_has_deli");
    std::string file2("int_long_norm_no_deli");
    */
    std::string file1("std_norm_has_deli_mult");
    std::string file2("std_norm_no_deli_mult");
    file1 = file1 + "_" + fileNum + "W" + ".csv";
    file2 = file2 + "_" + fileNum + "W" + ".csv";
    /*
    intCsv  intObjWithDeli(file1, rows, cols, true);
    intCsv  intObjWithNoDeli(file2, rows, cols, false);
    */

    stdCsv stdObjWithDeli(file1, rows, true);
    stdCsv stdObjWithNoDeli(file2, rows, false);


    stdObjWithDeli.generateNorm();
    stdObjWithNoDeli.generateNorm();

    return 0;
}
