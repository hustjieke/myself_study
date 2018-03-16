#include <iostream>
#include <string>
#include <assert.h>    
#include "leveldb/db.h"    

using namespace std;

int main(void) 
{       

    leveldb::DB      *db;    
    leveldb::Options  options;    
    options.create_if_missing = true;    

    // open
    const char tempDB[] = "/home/gaoriyao/local/github/leveldb-1.18/gry_testdb";
    leveldb::Status status = leveldb::DB::Open(options, tempDB, &db);    
    assert(status.ok());

    string key = "name";
    string value = "gaoriyao";

    // write
    status = db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());

    // read
    status = db->Get(leveldb::ReadOptions(), key, &value);
    assert(status.ok());

    cout << value << endl;

    // delete
    status = db->Delete(leveldb::WriteOptions(), key);
    assert(status.ok());

    status = db->Get(leveldb::ReadOptions(), key, &value);
    if(!status.ok()) {
        cerr << key << "    " << status.ToString() << endl;
    } else {
        cout << key << "===" << value << endl;
    }

    // close 
    delete db;

    return 0;
}
