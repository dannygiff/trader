#include "Handler.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Item.hpp"
#include "Inventory.hpp"
#include "User.hpp"



Handler::Handler()
{

}

void Handler::genUserFile(string filename)
{
    cout << "generating " << filename << endl;

    User admn("Admin", true, 99999);//generic administrator
    User test("test", false, 69);
    nUsers = 2;

    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);
    outfile.write( reinterpret_cast<const char *>(&nUsers), sizeof(nUsers));
    admn.save(outfile);
    test.save(outfile);
    outfile.close();
}

void Handler::printRecord()
{
    for(int i=0; i<userRecord.size(); i++)
    {
        cout << i << " ";
        userRecord.at(i).print();
    }
}

void Handler::loadRecord(string filename)
{
    fstream infile;
    
    int nameLen;
    infile.open(filename, ios::in | ios::binary);

    infile.read( reinterpret_cast<char *>( &nUsers ), sizeof( nUsers ) );

    for(int i=0; i<nUsers; i++)
    {
        User temp;
        userRecord.push_back(temp.loadFromFile(infile));
    }
    infile.close();
}

void Handler::saveRecord(string filename)
{
    fstream outfile;
    outfile.open(filename, ios::out | ios::binary);
    outfile.write( reinterpret_cast<const char *>(&nUsers), sizeof(nUsers));
    for (int i=0; i<nUsers; i++)
    {
        userRecord.at(i).save(outfile);
    }
    outfile.close();
    
}

void Handler::addtoRecord(User u)
{
    this->userRecord.push_back(u);
    this->nUsers = this->userRecord.size();
}

void Handler::genCartFile(string filename)
{
    cout << "generating " << filename << endl;

    string admn = "Admin";
    string test = "test";

    // Inventory a_inv();

    // fstream outfile;
    // outfile.open(filename, ios::out | ios::binary);
    // outfile.write( reinterpret_cast<const char *>(&nUsers), sizeof(nUsers));
    // admn.save(outfile);
    // test.save(outfile);
    // outfile.close();
}
