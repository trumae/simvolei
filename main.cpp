#include <iostream>
#include <tuple>
#include <unistd.h>
#include <chrono>
#include <random>
#include <limits>
#include <cstdlib>

#include "progressbar.hpp"

int gogame(double pt1, std::mt19937 &g) {
    int sc1 =0 , sc2 = 0;

    while(true) {
        double v = 1.0 * g() / std::numeric_limits<uint>::max() ;

        if (v < pt1) {
            sc1 ++;
        } else {
            sc2 ++;
        }

        if (sc1 - sc2 >1 && sc1 > 24) return 1;
        if (sc2 - sc1 >1 && sc2 > 24) return 2;
    }

    return 0;
}

void verbose(char **argv) {
    std::cout << argv[0] << " <point prob team1> <rounds>" << std::endl;
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) verbose(argv);

    double pt1 = std::atof(argv[1]);
    int total = std::atoi(argv[2]);
    uint team1=0, team2 = 0;

    // obtain a seed from the system clock:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine


    /*
     * Define a progress bar that has a total of 100,
     * a width of 70, shows `=` to indicate completion
     * and a blank space for incomplete
     */
    ProgressBar progressBar(total, 70, '#', '-');

    for (int i = 0; i < total; i++) {
        ++progressBar; // record the tick

        int res=gogame(pt1, generator);
        if (res == 1) team1 ++;
        if (res == 2) team2 ++;

        // display the bar only at certain steps
        if (i % 10 == 0)
            progressBar.display();
    }

    // tell the bar to finish
    progressBar.done();

    std::cout << "Done! " << team1 << "  " << team2 << std::endl;
}
