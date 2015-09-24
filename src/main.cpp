#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <ctime>

#include <boost/locale.hpp>

#include "libs/TimeInit.hpp"    // include header of Time class

using namespace std;
using namespace boost::locale;

void *task(void *argument){
      char* msg;
      msg = (char*)argument;
      std::cout<<msg<<std::endl;
}

int main(int argc, char ** argv) {

	generator gen;
    locale loc=gen("");
    // Create system default locale

    locale::global(loc);
    // Make it system global

    cout.imbue(loc);
    // Set as default locale for output

    cout <<format("Today {1,date} at {1,time} we had run our first localization example") % time(0)
          <<endl;

    cout<<"This is how we show numbers in this locale "<<as::number << 103.34 <<endl;
    cout<<"This is how we show currency in this locale "<<as::currency << 103.34 <<endl;
    cout<<"This is typical date in the locale "<<as::date << std::time(0) <<endl;
    cout<<"This is typical time in the locale "<<as::time << std::time(0) <<endl;
    cout<<"This is upper case "<<to_upper("Hello World!")<<endl;
    cout<<"This is lower case "<<to_lower("Hello World!")<<endl;
    cout<<"This is title case "<<to_title("Hello World!")<<endl;
    cout<<"This is fold case "<<fold_case("Hello World!")<<endl;



    pthread_t thread1, thread2;
    int i1,i2;

    i1 = pthread_create( &thread1, NULL, task, (void*) "thread 1");
    i2 = pthread_create( &thread1, NULL, task, (void*) "thread 2");

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);


    TimeInit t1(23, 59, 59);   // Test constructor

    // Test all public member functions
    t1.print();       // 23:59:59
    t1.setHour(12);
    t1.setMinute(30);
    t1.setSecond(15);
    t1.print();       // 12:30:15
    cout << "Hour is "   << t1.getHour()   << endl;
    cout << "Minute is " << t1.getMinute() << endl;
    cout << "Second is " << t1.getSecond() << endl;

    TimeInit t2;     // Test constructor with default values for hour, minute and second
    t2.print();  // 00:00:00
    t2.setTime(1, 2, 3);
    t2.print();  // 01:02:03

    TimeInit t3(12); // Use default values for minute and second
    t3.print();  // 12:00:00

    // Test nextSecond()
    TimeInit t4(23, 59, 58);
    t4.print();
    t4.nextSecond();
    t4.print();
    t4.nextSecond();
    t4.print();

    // No input validation
    TimeInit t5(25, 61, 99); // values out of range
    t5.print();  // 25:61:99

	return 0;
}
