// ==========================================================
// Random Walk with Descending Step Sizes
// ----------------------------------------------------------
// This program simulates many particles performing random walks.
// Each walk consists of "step_num" steps, where the step sizes
// are generated randomly in [0,1], sorted in descending order,
// and then assigned randomly as positive or negative.
//
// After many particles complete their walk, we record the final
// positions into a histogram. The distribution of final positions
// should approximate a Gaussian (normal distribution), due to the
// central limit theorem.
//
// Output: "walk5.dat" containing (position, normalized_count).


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <iomanip>
using namespace std;

// Output file
ofstream fout("walk5.dat");

const int particle_num = 100000;   // number of particles to simulate
const int step_num     = 100;      // number of steps per particle
const int range        = 200;      // histogram bins for integer part
// Each bin corresponds to one integer position. The histogram spans
// positions from -range/2 to +range/2.


int main() {
    // RNG: initialize random generator
    unsigned seed = (unsigned) chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 rng(seed);                       // Mersenne Twister generator
    uniform_real_distribution<double> uni01(0.0, 1.0);  // uniform [0,1)

    // Generating step sizes
    vector<double> randomNumbers(step_num);
    for (int i = 0; i < step_num; ++i)
        randomNumbers[i] = uni01(rng);

    // Sorting the step sizes in descending order
    sort(randomNumbers.begin(), randomNumbers.end(), greater<double>());

    //  Histogram vector
    vector<long long> counts(range, 0);

    //  Simulation of random walks
    for (int p = 0; p < particle_num; ++p) {
        double pos = 0.0;   // start at origin (0)

        // perform "step_num" steps
        for (int s = 0; s < step_num; ++s) {
            if (uni01(rng) < 0.5)
                pos -= randomNumbers[s];   // move left
            else
                pos += randomNumbers[s];   // move right
        }

        // Bin the final position
        // round to nearest integer and shift index into histogram
        int y_idx = static_cast<int>(round(pos)) + range/2;

        // record in histogram if within bounds
        if (y_idx >= 0 && y_idx < range)
            counts[y_idx]++;
    }

    // Output histogram 
    cout << fixed << setprecision(6);
    fout << fixed << setprecision(6);

    for (int j = 0; j < range; ++j) {
        double graph_x = j - range/2.0;   // convert bin index to actual position
        double normalized = static_cast<double>(counts[j]) / particle_num;

        cout << graph_x << " " << normalized << "\n";
        fout << graph_x << " " << normalized << "\n";
    }

    fout.close();
    return 0;
}

