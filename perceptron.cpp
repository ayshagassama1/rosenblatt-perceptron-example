#include "perceptron.h"

using namespace std;

/*
 *@param x: the matrix to store the data
 *@param ch: the file name
 *@param n: the number of lines of data (initially unknown)
 */
// read the csv file and load the data into the matrix x
void chargerBaseExcel(double **x, char *ch, int &n)
{
    FILE *fic = fopen(ch, "r");
    if (fic == NULL)
    {
        cout << "ouverture impossible";
    }
    else
    {
        char *cstr = new char[100];
        char **token = new char *[MAX_COL];
        int i = 0;
        n = 0;

        fgets(cstr, 100, fic); // read the 1st line and ignore it
        // read a line from the file and store it in cstr
        while (fgets(cstr, 100, fic))
        {
            // split the line
            token[0] = strtok(cstr, ";");
            for (int k = 1; k < MAX_COL; k++)
            {
                token[k] = strtok(NULL, ";");
            }

            x[i] = new double[MAX_COL];

            for (int k = 0; k < MAX_COL; k++)
                x[i][k] = atof(token[k]);
            i++;
        }
        n = i;

        fclose(fic);
    }
}

/*
 *@param w : vector of weights
 *@param x : data matrix
 *@param n : the number of lines
 */
// train the perceptron
void perceptron(double *w, double **x, int n)
{
    for (int i = 0; i < MAX_COL; i++) // weight vectors initialisation
    {
        w[i] = 1.0;
    }
    int k = 0; // epochs
    int o;     // predicted class
    double s;
    int l = 0; // current line
    int c;     // class
    do
    {
        s = 0.0;
        for (int i = 0; i < MAX_COL - 1; i++)
        {
            s += w[i] * x[l][i];
        }
        if (s > 0)
        {
            o = 1;
        }
        else
        {
            o = 0;
        }

        l++;

        c = (int)x[l - 1][MAX_COL - 1];
        for (int i = 0; i < MAX_COL; i++)
        {
            w[i] = w[i] + (c - o) * x[l - 1][i];
        }

        if (c == o) // if the class is the same as the predicted class
            k++;
        else
            k = 0;

        if (l == n) // if the end of the matrix is reached start again
            l = 0;
    } while (k < 25);
}

/*
 *@param w : Rosenblatt perceptron
 *@param x : input to predict
 */
// prediction of the class
int natureFleur(double *w, double *x)
{
    double s = w[0];
    for (int k = 1; k < MAX_COL - 1; k++)
    {
        s += w[k] * x[k];
    }

    return (s > 0);
}

void testBase(double *w, double **baseTest, int n)
{
    cout << "Num\tSepal\tPetal\tOutput" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_COL - 1; j++)
        {
            cout << baseTest[i][j] << "\t";
        }

        if (!natureFleur(w, baseTest[i]))
        {
            cout << "Iris-Setosa";
        }
        else
        {
            cout << "Iris-Versicolor";
        }
        cout << endl;
    }
}
