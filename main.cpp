#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
    int64_t relation_power, set_power, t;
    cin >> set_power;
    int32_t** matrix = new int32_t*[set_power];
    for (int32_t i = 0; i < set_power; ++i) {
        matrix[i] = new int32_t[set_power]();
    }

    for (int32_t i = 0; i < set_power; ++i) {
        for (int32_t j = 0; j < set_power; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int32_t i = 0; i < set_power; ++i) {
        matrix[i][i] = 1;
    }

    for (int32_t i = 0; i < set_power; ++i) {
        for (int32_t j = 0; j < set_power; ++j) {
            if (matrix[i][j] == 1) {
                matrix[j][i] = 1;
            }
        }
    }

    bool is_transitive;
    do {
        is_transitive = true;
        for (int32_t i = 0; i < set_power; ++i) {
            for (int32_t j = 0; j < set_power; ++j) {
                if (matrix[i][j] == 1) {
                    for (int32_t k = 0; k < set_power; k++) {
                        if (matrix[j][k] == 1 && matrix[i][k] == 0) {
                            is_transitive = false;
                            matrix[i][k] = 1;
                        }
                    }
                }
            }
        }
    } while (is_transitive == false);

    cout << endl;
    for (int32_t i = 0; i < set_power; ++i) {
        for (int32_t j = 0; j < set_power; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    for (int32_t i = 0; i < set_power; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
