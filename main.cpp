#include "perceptron.h"

using namespace std;

int main(int argc, char const *argv[])
{
    double **x = new double *[MAX_TAB];        // learning data
    double *w = new double[MAX_COL - 1];       // weight vector
    double **baseTest = new double *[MAX_TAB]; // test data
    int n;
    int m;
    char fic[] = "baseApprentissage.csv";
    char ficTest[] = "baseTest.csv";

    chargerBaseExcel(x, fic, n);            // load the learning data
    chargerBaseExcel(baseTest, ficTest, m); // load the test data
    perceptron(w, x, n);                    // train the perceptron

    // print the weight vector
    cout << endl
         << "Resulting perceptron : ";
    for (int i = 0; i < MAX_COL - 1; i++)
    {
        cout << w[i] << "\t";
    }
    cout << endl;
    cout << "Test data : " << endl;

    testBase(w, baseTest, m);

    free(baseTest);
    free(x);
    free(w);
    return 0;
}
