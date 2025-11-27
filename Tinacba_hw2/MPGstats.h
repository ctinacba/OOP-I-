// Name: Your Full Name
// Student ID: YourID
// Assignment: CS2313 Homework 2


using namespace std;

class MPGStats {
    private:
        int trips;              // Total Count of Valid Trips Recorded
        int lowMPGCount;        // Number of trips with MPG below 15.0

        double totalMiles;      // Total of all miles driven
        double totalGallons;    // Total Gallons used

        double bestMPG;         // Highest Single-trip MPG recorded
        double worstMPG;        // Lowest Single-trip MPG Recorded
    public:

    //Default constructor
    MPGStats(){
        trips = 0;
        bestMPG = 0;
        worstMPG = 1e9;
        lowMPGCount = 0;
        totalMiles = 0;
        totalGallons = 0;
    }

    double addTrip(double miles, double gallons) {
        double mpg; // To be calculated

        if (gallons > 0 && miles >=0) {
            mpg = miles/gallons;
            trips++;
            totalMiles += miles;
            totalGallons += gallons;

            if (gallons >= totalGallons)
                totalGallons = gallons;
            if (mpg < 15)
                lowMPGCount = mpg;
            if (worstMPG > mpg)
                worstMPG = mpg;
            else if (bestMPG < mpg)
                bestMPG = mpg;
            return mpg;
        }
        else {
            return -1.0;
        }

    }

    int getTrips() {
        return trips-1; // Because trips goes 1 more than the actual
    }

    double getTotalMiles() {
        return totalMiles;
    }

    double getTotalGallons() {
        return totalGallons;
    }

    double getLowMPGCount() {
        return lowMPGCount;
    }

    double getBestMPG() {
        return bestMPG;
    }

    double getWorseMPG() {
        return worstMPG;
    }

    double overAllMPG() const {
        if (totalGallons == 0)
            return 0.0;
        else
            return totalMiles/totalGallons;
    }






};