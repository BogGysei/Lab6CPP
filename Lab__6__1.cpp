#include "resurses.h"
#include <iostream>

using namespace std;

void menu() {
    Point* p = nullptr;
    Rectangle* r = nullptr;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Create Point\n";
        cout << "2. Move Point\n";
        cout << "3. Set Point Color\n";
        cout << "4. Display Point\n";
        cout << "-------------------------------\n";
        cout << "5. Create Rectangle\n";
        cout << "6. Move Rectangle\n";
        cout << "7. Set Rectangle Color\n";
        cout << "8. Resize Rectangle\n";
        cout << "9. Rotate Rectangle\n";
        cout << "10. Display Rectangle\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int x, y;
            string color;
            cout << "Enter x, y and color: ";
            cin >> x >> y >> color;
            delete p;
            p = new Point(x, y, color);
            break;
        }
        case 2: {
            if (p) {
                int dx, dy;
                cout << "Enter dx and dy: ";
                cin >> dx >> dy;
                p->move(dx, dy);
            }
            else {
                cout << "Point not created yet.\n";
            }
            break;
        }
        case 3: {
            if (p) {
                string color;
                cout << "Enter new color: ";
                cin >> color;
                p->setColor(color);
            }
            else {
                cout << "Point not created yet.\n";
            }
            break;
        }
        case 4: {
            if (p) {
                p->display();
            }
            else {
                cout << "Point not created yet.\n";
            }
            break;
        }
        case 5: {
            int x, y, width, height;
            string color;
            cout << "Enter x, y, width, height and color: ";
            cin >> x >> y >> width >> height >> color;
            delete r;
            r = new Rectangle(x, y, width, height, color);
            break;
        }
        case 6: {
            if (r) {
                int dx, dy;
                cout << "Enter dx and dy: ";
                cin >> dx >> dy;
                r->move(dx, dy);
            }
            else {
                cout << "Rectangle not created yet.\n";
            }
            break;
        }
        case 7: {
            if (r) {
                string color;
                cout << "Enter new color: ";
                cin >> color;
                r->setColor(color);
            }
            else {
                cout << "Rectangle not created yet.\n";
            }
            break;
        }
        case 8: {
            if (r) {
                int width, height;
                cout << "Enter new width and height: ";
                cin >> width >> height;
                r->resize(width, height);
            }
            else {
                cout << "Rectangle not created yet.\n";
            }
            break;
        }
        case 9: {
            if (r) {
                double angle;
                cout << "Enter new angle: ";
                cin >> angle;
                r->rotate(angle);
            }
            else {
                cout << "Rectangle not created yet.\n";
            }
            break;
        }
        case 10: {
            if (r) {
                r->display();
            }
            else {
                cout << "Rectangle not created yet.\n";
            }
            break;
        }
        case 11:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    delete p;
    delete r;
}

int main() {
    menu();

}
