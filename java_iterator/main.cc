
#include "java_iterator.h"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    {
        cout << "int test:\n";
        const std::vector<int> vi {1, 2, 3, 4};
        auto i = make_java_iter(vi);
        while (i.hasNext()) {
            auto& i1 = i.next();
            cout << i1 << " ";
        }
        cout << endl;
    }

    {
        cout << "float test:\n";
        std::vector<float> vi {1.5, 2, 3.6, 4};
        auto i = make_java_citer(vi);
        while (i.hasNext()) {
            auto& i1 = i.next();
            cout << i1 << " ";
        }
        cout << endl;
    }

    {
        cout << "string test:\n";
        std::vector<string> vs {"one", "two", "3"};
        auto i2 = make_java_iter(vs);
        while (i2.hasNext()) {
            auto& i3 = i2.next();
            cout << i3 << " ";
        }
        cout << endl;
    }
}
