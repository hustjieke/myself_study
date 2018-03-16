#include <cmath>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>

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
        // void generateOthers();
        
    private:
        intCsv() { }

    private:
        std::string m_file;
        int64_t m_rows;
        int64_t m_cols;
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
    std::string file1("int_long_norm_has_deli");
    std::string file2("int_long_norm_no_deli");
    file1 = file1 + "_" + fileNum + "W" + ".csv";
    file2 = file2 + "_" + fileNum + "W" + ".csv";
    intCsv  intObjWithDeli(file1, rows, cols, true);
    intCsv  intObjWithNoDeli(file2, rows, cols, false);

    // for test
    //intCsv  intObjWithDeli("int_long_norm_has_deli.csv", 3, 3, true);
    //intCsv  intObjWithNoDeli("int_long_norm_no_deli.csv", 3, 3, false);

    intObjWithDeli.generateNorm();
    intObjWithNoDeli.generateNorm();

    return 0;
}
