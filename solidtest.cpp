#include <iostream>
#include <vector>
#include <memory>
#include "solids.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of solids:\n";
    cin >> n;
    vector<unique_ptr<Solid>> v(n);
    for (int i = 0; i < n; ++i) {
        int type;
        cout << "Enter type of solid #" << i+1 << ":\n";
        cin >> type;
        switch (type) {
            case 0:
                v[i] = Sphere::input(cin, cout);
                break;
            case 1:
                v[i] = Parallelepiped::input(cin, cout);
                break;
            case 2:
                v[i] = RectParallelepiped::input(cin, cout);
                break;
            case 3:
                v[i] = Cube::input(cin, cout);
                break;
            case 4:
                v[i] = Cylinder::input(cin, cout);
                break;
            default:
                cout << "ERROR: Unknown solid type\n";
                return 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Solid #" << i+1 << "\n";
        cout << "diameter: " << v[i]->diameter() << "\n";
        cout << "surface area: " << v[i]->surfaceArea() << "\n";
        cout << "volume: " << v[i]->volume() << "\n";
    }

    return 0;
}
