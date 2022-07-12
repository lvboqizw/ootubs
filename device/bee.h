#ifndef __bee_include__
#define __bee_include__

#include "machine/speaker.h"

class Bee: public Speaker {
private:
	Bee(const Bee &copy);

    int fq = 1;                             // initialize the fq with 1

public:
    Bee():Speaker(1){
        stop();
    };

    /// return the current frequence
    inline int frequence(){
        return fq;
    };

    /// setup the frequence of the bee
    inline void frequence(int fq) {
        this->fq = fq;
    };

    /// make the bee speake with at the frequence
    void noise();

};

#endif