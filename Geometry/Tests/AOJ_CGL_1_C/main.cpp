#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    Point P0, P1, P2;
    cin >> P0 >> P1;
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        cin >> P2;
        switch (Point::CCW(P0, P1, P2)) {
            case 1: 
                cout << "COUNTER_CLOCKWISE" << endl;
                break;
            case -1:
                cout << "CLOCKWISE" << endl;
                break;
            case 2:
                cout << "ONLINE_BACK" << endl;
                break;
            case -2:
                cout << "ONLINE_FRONT" << endl;
                break;
            case 0:
                cout << "ON_SEGMENT" << endl;
                break;
            default:
                assert(0);
        }
    }
    return 0;
}
