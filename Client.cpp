#include <iostream>
#include "Driver.h"
#include "Udp.h"

using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

int main(int argc, char *argv[]) {
    int id, age, experience, cabId;
    Status status;
    char c, statusLetter;
    Driver *driver;

    //get an input from the user and set a new driver
    cin >> id >> c >> age >> c >> statusLetter >> c >>
        experience >> c >> cabId;
    status = Status(statusLetter);
    driver = new Driver(id, age, status, experience, cabId);

    // create new socket
    Socket *udp = new Udp(0, atoi(argv[1]));
    udp->initialize();
    char buffer[1024];

    // serial driver object to string
    string serial_str;
    back_insert_device<std::string> inserter(serial_str);
    stream<boost::iostreams::back_insert_device<std::string>> s(inserter);
    binary_oarchive oa(s);
    oa << driver;
    s.flush();

    // send driver object to server
    udp->sendData(serial_str);
    // get a cab

    // get a cab serial string from server and add it to driver.
    udp->reciveData(buffer, sizeof(buffer));
    Cab* cab;
    boost::iostreams::basic_array_source<char> device(buffer, sizeof(buffer));
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > stream1
            (device);
    boost::archive::binary_iarchive ia(stream1);
    ia >> cab;
    driver->setCab(cab);


    //get from server point of the next step at path
    int b=1;
    while(b!=0){
        b=driver->setDataDriver(udp);
    }

    delete(driver);
    delete(cab);
    delete (udp);
    return 0;
}