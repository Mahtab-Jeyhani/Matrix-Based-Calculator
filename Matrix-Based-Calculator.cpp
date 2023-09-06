#include <iostream>
#include <math.h>

int determinant(int A[100][100], int n);
bool inverse(int A[100][100], float inverse[100][100], int K);
void adjoint(int A[100][100], int adj[100][100], int K);
void getCofactor(int A[100][100], int temp[100][100], int p, int q, int n);
using namespace std;

const int arraycolsize = 100;
const int arrayrowsize = 100;
int a[arrayrowsize][arraycolsize];
int  b[arrayrowsize][arraycolsize];
int c[arrayrowsize][arraycolsize];
int d[arrayrowsize][arraycolsize];
int f[arrayrowsize][arraycolsize];
int n, m, k, s, q;

void CheckCommands() {
    cout << "please enter a number" << endl;

    cin >> q;

    if (q == 1) {
        cout << "Enter m and n" << endl;
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "a[" << i << "," << j << "]=";
                cin >> a[i][j];
            }
        }
        CheckCommands();
    }


    if (q == 2) {
        cout << "Enter k and s" << endl;
        cin >> k >> s;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < s; j++) {
                cout << "b[" << i << "," << j << "]=";
                cin >> b[i][j];
            }
        }
        CheckCommands();
    }


    if (q == 3) {
        if (m == k && n == s) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = a[i][j];
                }
            }

        }
        else {
            cout << "Eror" << endl;
        }
        CheckCommands();

    }


    if (q == 4) {
        if (m == k && n == s) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = b[i][j];
                }
            }

        }
        else {
            cout << "Eror" << endl;
        }
        CheckCommands();
    }





    if (q == 6) {




        if (m == k && n == s) {
            for (int i = 0; i < m; i++) {
                cout << endl;
                for (int j = 0; j < s; j++) {
                    c[i][j] = b[i][j] + a[i][j];

                    cout << c[i][j] << "\t";
                }
            }
        }
        else cout << "Error" << endl;

        CheckCommands();
    }
    if (q == 8) {

        if (m == k && n == s) {
            for (int i = 0; i < m; i++) {
                cout << endl;
                for (int j = 0; j < s; j++) {
                    d[i][j] = a[i][j] - b[i][j];
                    cout << d[i][j] << "\t";
                }
            }
        }
        else cout << "Error" << endl;

        CheckCommands();
    }

    if (q == 5) {
        if (n == k) {

            for (int t = 0; t < m; t++) {
                cout << endl;
                for (int i = 0; i < s; i++) {
                    for (int j = 0; j < n; j++) {
                        f[t][i] += a[t][j] * b[j][i];
                    }
                }
            }
        
        for (int t = 0; t < m; t++) {
            for (int i = 0; i < s; i++) {
                a[t][i] = f[t][i];
                n = s;
            }
        }
    }
        else { cout << "Error" << endl;
       
    }
        CheckCommands();
}

    if (q == 7) {
        if (k == s && n == k) {

            float inv[100][100];
            float Result[100][100];
            bool ret = inverse(b, inv, s);

            if (ret == true) {


                for (int t = 0; t < m; t++) {
                    cout << endl;
                    for (int i = 0; i < s; i++) {
                        float sum = 0;

                        for (int j = 0; j < n; j++) {
                            sum += a[t][j] * inv[j][i];

                        }
                        Result[t][i] = sum;
                        a[t][i] = Result[t][i];
                        cout << Result[t][i] << "\t";
                    }
                }

                cout << endl;
            }
            else {
                cout << "Error" << endl;
                CheckCommands();
            }



        }
        else cout << "Error" << endl;
        CheckCommands();
    }

    if (q == 9) {
        int z;
        cout << "please Enter a number to multiply in matrix:" << endl;
        cin >> z;
        for (int i = 0; i < m; i++) {
            cout << endl;
            for (int j = 0; j < n; j++) {
                a[i][j] = z * a[i][j];
                cout << a[i][j] << "\t";
            }
        }
        CheckCommands();
    }







    if (q == 10) {
        if (m == n) {
            cout << "The determinate of A matrix is:";

            cout << determinant(a, n) << endl;
            //cout << det(a, n) << endl;
            CheckCommands();
        }
        else {
            cout << "Error" << endl;
            CheckCommands();
        }


    }

    if (q == 11) {
        if (k != s) {
            cout << "Error" << endl;
            CheckCommands();
        }
        else {
            cout << "The determinate of B matrix is:";
            cout << determinant(b, k) << endl;
            CheckCommands();
        }

    }
    if (q == 12) {


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "a[" << i << "," << j << "]=" << a[i][j];

            }
        }
        CheckCommands();

    }



    if (q == 13) {


        for (int i = 0; i < k; i++) {
            for (int j = 0; j < s; j++) {
                cout << "b[" << i << "," << j << "]=" << b[i][j];

            }
        }
        CheckCommands();

    }


}



void build(int b[100][100], int a[100][100], int i, int n)
{
    int j, l;
    int h = 0, k = 0;
    for (l = 1; l < n; l++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            b[h][k] = a[l][j];
            k++;
            if (k == n - 1)
            {
                h++;
                k = 0;
            }

        }
    }
}



void getCofactor(int A[100][100], int temp[100][100], int p, int q, int n)
{

    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }

    }
}


int determinant(int A[100][100], int n)
{
    int D = 0;
    if (n == 1)
        return A[0][0];
    int temp[100][100];
    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;

    }

    return D;
}


void adjoint(int A[100][100], int adj[100][100], int K)
{
    if (K == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[100][100];
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            getCofactor(A, temp, i, j, K);

            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, K - 1));

        }

    }
}


bool inverse(int A[100][100], float inverse[100][100], int K)
{


    int det = determinant(A, K);

    if (det == 0)

    {
        cout << "can't find its inverse";
        return false;

    }

    int adj[100][100];

    adjoint(A, adj, K);


    for (int i = 0; i < K; i++)

        for (int j = 0; j < K; j++)

            inverse[i][j] = adj[i][j] / float(det);
    return true;
}
int main() {
    CheckCommands();
}
