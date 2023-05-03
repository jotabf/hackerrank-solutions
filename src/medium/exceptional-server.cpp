// SUBDOMAINS: Classes

#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Server {
 private:
  static int load;

 public:
  static int compute(long long A, long long B) {
    load += 1;
    if (A < 0) {
      throw std::invalid_argument("A is negative");
    }
    vector<int> v(A, 0);
    int real = -1, cmplx = sqrt(-1);
    if (B == 0) throw 0;
    real = (A / B) * real;
    int ans = v.at(B);
    return real + A - B * ans;
  }
  static int getLoad() { return load; }
};
int Server::load = 0;

int main() {
  int T;
  cin >> T;
  while (T--) {
    long long A, B;
    cin >> A >> B;
    try {
      cout << Server::compute(A, B) << endl;
    } catch (std::bad_alloc& e) {
      cout << "Not enough memory" << endl;
    } catch (std::exception& e) {
      cout << "Exception: " << e.what() << endl;
    } catch (...) {
      cout << "Other Exception" << endl;
    }
  }
}