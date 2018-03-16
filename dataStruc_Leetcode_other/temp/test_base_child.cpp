#include <iostream>
#include <string>

using namespace std;
#include <string>
class Staff  {
    private:
        string position;
        string name;
        string job_num;
        string id_num;
        string tel;
        double base_pay;
        double merit;
        double merit_pay;

    public:
        Staff() { }
        void message () const;
};

class DepartmentManager : public Staff {
    public:
        //DepartmentManager();
        DepartmentManager() {
        }
        void DM_pay (double merge_pay);
};

//DepartmentManager::DepartmenManager() {
//}

/*
Staff::Staff(const string & position, const string & name, const string & job_num, const string & id_num,
        const string & tel) : position(position), name(name), job_num(job_num), id_num(id_num), tel(tel) {
    cout << "name:" << name << endl;
    cout << "position:" << position << endl;
    cout << "Job Number:" << job_num << endl;
    cout << "ID Number:" << id_num << endl;
    cout << "Telephone Number:" << tel << endl;
}
*/

//DepartmentManager::DepartmenManager(double base_pay, double merit) :Staff(base_pay, merit) {
//}


int main() {
    Staff staff;
    //DepartmentManager mgr;
    return 0;
}
