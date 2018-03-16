#include <time.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

std::string getRandom6X() {
    time_t t = time( 0 );
    char tmpBuf[14];
    char tmpBuf_2[16];
    strftime(tmpBuf, 12, "/tmp/XXXXXX", localtime(&t)); //format date and time.
    strftime(tmpBuf_2, 15, "DP_%m%d%H%M%S.", localtime(&t));
    char* tmp_file_name = tmpBuf;
    cout << "gry tmpBuf: " << tmpBuf << endl;
    cout << "gry tmp_file_name: " << tmp_file_name << endl;
    cout << "sizeof: " << sizeof(&tmp_file_name[0]) << endl;
    cout << "gry tmpBuf_2: " << tmpBuf_2 << endl;

    int fd;
    fd = mkstemp(tmp_file_name);
    unlink (tmp_file_name);
    close(fd);
    string xstr(tmp_file_name, 5, 7);
    cout << "gry tmp_file_name: " << tmp_file_name << endl;
    return xstr;
}

int main()
{
    string ret = getRandom6X();
    cout << "gry ret: " << ret << endl;

    return 0;
}
