#ifndef __speaker_include__
#define __speaker_include__

#include "machine/io_port.h"

class Speaker {
private:
    Speaker(const Speaker &copy);
    IO_Port crtl_register;
    IO_Port counter;
    IO_Port speaker;


    int fq;
public:
    Speaker(int fq) : crtl_register(0x43), counter(0x42), speaker(0x61) { // counter2, 1.PIT
		interval (fq);
	}

	// Indicates which interrupt interval was set
	int interval() {
	return this->fq;
	}

	// Set a new interupt interval
	void interval(int fq);

    /// let speaker make sound
    void speak();

    /// shut speaker down
    void stop();
};

#endif