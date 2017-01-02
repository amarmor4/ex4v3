//
// Created by moran on 28/11/16.
//

#include "Driver.h"

/**
 * constractor of driver.
 * @param map1 map of the city.
 * @param driverId1 driver id.
 * @param age1 age of driver.
 * @param status1 current trip of driver.
 * @param expYears1 years of experience.
 * @param avgRate1 avrage rate of passengers.
 * @param taxiCab1 taxi cab.
 * @return nothing.
 */
Driver::Driver(int driverId1, int age1, Status status1, int expYears1, int cabId1) {
    driverId = driverId1;
    age = age1;
    status = status1;
    expYears = expYears1;
    avgRate = 0;
    cabId = cabId1;
    numOfDrives = 0;
    currentLocation = new Point(0, 0);
    available = true;
    cab = NULL;
}

Driver::Driver() {

}
/**
 * destructor.
 */
Driver::~Driver() {
    delete (currentLocation);
}


/**
 * get driver id.
 * @return driver id.
 */
int Driver::getDriverId() {
    return this->driverId;
}

/**
 * get driver age
 * @return driver age
 */
int Driver::getAge() {
    return this->age;
}

/**
 * get status.
 * @return status
 */
Status Driver::getStatus() {
    return this->status;
}

/**
 * get experience years of driver.
 * @return exprience of driver.
 */
int Driver::getExpYears() {
    return this->expYears;
}

/**
 * get average rate of passengers.
 * @return average rate of passengers.
 */
double Driver::getAvgRate() {
    return this->avgRate;
}

/**
 * get the current location of the driver
 * @return the location
 */
Point *Driver::getCurrentLocation() const{
    return this->currentLocation;
}

/**
 * access.
 * @return the cab 
 */
Cab *Driver::getCab() const {
    return cab;
}

/**
 * access.
 * @return the cabId
 */
int Driver::getCabId() const {
    return cabId;
}

/**
 * get true if the driver acailable to trip, false if has trip.
 * @return true if the driver acailable to trip, false if has trip.
 */
bool Driver::isAvailable() {
    return this->available;
}

/**
 * set the right cab to this driver
 * @param cab the rigt cab
 */
void Driver::setCab(Cab *cab) {
    this->cab = cab;
}

/**
 * set current location of driver.
 * @param location driver location
 */
void Driver::setCurrLocation(Point *location) {
    delete (currentLocation);
    this->currentLocation = new Point(location->getX(), location->getY());
}

/**
 * set availability of driver.
 * @param isAvailable true if available, false if not available.
 */
void Driver::setAvailable(bool isAvailable) {
    this->available = isAvailable;
}


/**
 * set driver id.
 * @param driverId1 driver id
 */
void Driver::setDriverId(int driverId1) {
    this->driverId = driverId1;
}

/**
 * set driver age.
 * @param age1 driver age
 */
void Driver::setAge(int age1) {
    this->age = age1;
}

/**
 * set status of driver.
 * @param status1 status of driver.
 */
void Driver::setStatus(Status status1) {
    this->status = status1;
}

/**
 * set driver's years of experienes.
 * @param expYears1 driver's years of experienes.
 */
void Driver::setExpYears(int expYears1) {
    this->expYears = expYears1;
}

/**
 * set average rate of passngers.
 * @param avgRate1
 */
void Driver::setAvgRate(double avgRate1) {
    this->avgRate = avgRate1;
}

/**
 * set pointer to taxi cab.
 * @param taxiCab1 pointer to taxi cab.
 */
void Driver::setNumOfDrives() {
    this->numOfDrives = numOfDrives + 1;

}

/**
 * operator == of driver
 * @param driver1 the first driver
 * @param driver2 the second driver
 * @return if driver1 == driver2
 */
bool operator==(Driver driver1, Driver driver2) {
    return (driver1.getAge() == driver2.getAge() &&
            driver1.getDriverId() == driver2.getDriverId() &&
            driver1.getAvgRate() == driver2.getAvgRate() &&
            driver1.getExpYears() == driver2.getExpYears() &&
            driver1.getStatus() == driver2.getStatus());
}

/**
 * operator != of driver
 * @param driver1 the first driver
 * @param driver2 the second driver
 * @return if driver1 != driver2
 */
bool operator!=(Driver driver1, Driver driver2) {
    return !(driver1 == driver2);
}

/**
 * operator overloading - print.
 * @param os ostream.
 * @param point point.
 * @return ostream.
// */
int Driver::getNumOfDrives() {
    return numOfDrives;
}

int Driver::setDataDriver(Socket* udp) {
    char buffer[1024];
    int b;
    udp->reciveData(buffer, sizeof(buffer));
    Point * p;
    boost::iostreams::basic_array_source<char> device1(buffer, sizeof(buffer));
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2
            (device1);
    boost::archive::binary_iarchive ia1(s2);
    ia1 >> p;
    if (p!=NULL){
        this->setCurrLocation(p);
        delete (p);
        return 1;
    }
    else{
        return 0;
    }
}