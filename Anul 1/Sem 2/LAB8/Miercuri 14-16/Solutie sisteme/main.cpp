#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double delta3(double v[][3]){
    return (v[0][0]*v[1][1]*v[2][2] + v[1][0]*v[2][1]*v[0][2] + v[2][0]*v[0][1]*v[1][2] - v[0][2]*v[1][1]*v[2][0] - v[1][0]*v[0][1]*v[2][2] - v[0][0]*v[1][2]*v[2][1]);
}

double delta2(double v[][2]){
    return (v[0][0]*v[1][1] - v[0][1]*v[1][0]);
}

void inlocuireColoana(double v[][3], double A[][3], double B[], int n){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (j != n) v[i][j] = A[i][j];
                else v[i][j] = B[i];
}

void Cramer(double A[][3], double B[]){
    double aux[3][3];
    for (int i = 0; i < 3; i++){
        inlocuireColoana(aux, A, B, i);
        cout << fixed << setprecision(3) << (double)(round(delta3(aux)/delta3(A)*1000)/1000) << " ";
    }
}

int rang(double A[][3]){
    if (delta3(A) != 0) return 3;
    else {
        bool gasit = false;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                double aux[2][2];

                int subx = 0;
                for (int x = 0; x < 3; x++){
                    if (x == i) continue;
                    int suby = 0;
                    for (int y = 0; y < 3; y++){
                        if (y == j) continue;
                        aux[subx][suby] = A[x][y];
                        suby++;
                    }
                    subx++;
                }

                if (delta2(aux) != 0) {
                    gasit = true;
                    break;
                }
            }
            if (gasit) break;
        }

        if (gasit) return 2;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (A[i][j] != 0) return 1;

        return 0;
    }
}

double rang(double A[][4]){
    for (int i = 0; i < 4; i++){
        double subA[3][3];
        for (int j = 0; j < 3; j++)
            for (int k = 0, col = 0; k < 4; k++){
                if (k == i) continue;
                subA[j][col] = A[j][k];
                col++;
            }
        if (delta3(subA) != 0) return 3;
    }

    for (int i = 0; i < 3; i++)
        for (int j = i+1; j < 4; j++){
            for (int k = 0; k < 3; k++)
                for (int l = k+1; l < 3; l++){
                    double subA[2][2] = { {A[k][i], A[k][j]}, {A[l][i], A[l][j]} };
                    if (delta2(subA) != 0) return 2;
                }
        }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (A[i][j] != 0) return 1;

    return 0;
}

int main()
{
    double n;
    cout << "n = "; cin >> n;
    double A[3][3] = {n, 2, -1, -2, -1, n, 3, 2*n, 0};
    double Ae[3][4] = {n, 2, -1, 4, -2, -1, n, 1, 3, 2*n, 0, n-8};
    double B[3] = {4, 1, n-8};

    if (delta3(A) != 0)
        Cramer(A, B);
    else if (delta3(A) == 0 && (rang(A) == rang(Ae)))
        cout << "Sistem Compatibil Nedeterminat.";
    else if (delta3(A) == 0 && (rang(A) != rang(Ae)))
        cout << "Sistem Incompatibil";
}
