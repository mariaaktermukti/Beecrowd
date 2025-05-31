#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int city_count = 0;

    while ( (cin >> N) ) {
        if (N == 0) break;
        city_count++;

        static long long countResidents[201];
        memset(countResidents, 0, sizeof(countResidents));

        long long totalResidents = 0;
        long long totalConsumption = 0;

        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            int c = Y / X;  
            countResidents[c] += X;
            totalResidents += X;
            totalConsumption += Y;
        }

        if (city_count > 1) {
            cout << "\n";
        }
        cout << "Cidade# " << city_count << ":\n";

        bool first = true;
        for (int c = 0; c <= 200; c++) {
            if (countResidents[c] > 0) {
                if (!first) {
                    cout << " ";
                }
                first = false;
                cout << countResidents[c] << "-" << c;
            }
        }
        cout << "\n";

        long long truncated = (totalConsumption * 100) / totalResidents;
        long long integerPart = truncated / 100;
        long long decimalPart = truncated % 100;

        cout << "Consumo medio: "
             << integerPart << "."
             << (decimalPart < 10 ? "0" : "") << decimalPart
             << " m3.\n";
    }

    return 0;
}
