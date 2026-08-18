#include <iostream>
#include <string>
#include <vector>

void cls() { std::cout << "\033[2J\033[1;1H"; }

int main() {
  int bal{};
  int x{};
  int plus{};
  int minus{};

  std::vector<std::string> history;

  const std::string bold_red = "\033[1;31m";
  const std::string bold_green = "\033[1;32m";
  const std::string reset = "\033[0m";

  cls();

  std::cout << "Enter your balance: ";
  std::cin >> bal;

  while (true) {
    cls();

    if (bal >= 0) {
      std::cout << bold_green << "$" << bal << reset << "\n";
    } else {
      std::cout << bold_red << "$ " << bal << reset << "\n";
    }

    std::cout << R"(
1. Put on balance
2. Subtract from balance
3. Action History

4. Exit
)";
    std::cin >> x;

    switch (x) {
    case 1:
      cls();

      std::cout << "Enter the amount: ";
      std::cin >> plus;

      if (plus > 0) {
        bal += plus;
        history.push_back(bold_green + "+ $" + std::to_string(plus) + reset);
      }

      break;

    case 2:
      cls();

      std::cout << "Enter amount to subtract: ";
      std::cin >> minus;

      if (minus > 0) {
        bal -= minus;
        history.push_back(bold_red + "- $" + std::to_string(minus) + reset);
      }

      break;

    case 3: {
      cls();

      std::cout << "History: " << "\n";

      if (history.empty()) {
        std::cout << "History is empty.\n";
      } else {
        for (const std::string &item : history) {
          std::cout << item << "\n";
        }
      }

      std::cout << "\nEnter 0 to return: ";
      int back{};
      std::cin >> back;
      break;
    }

    case 4:
      return 0;

    default:
      break;
    }
  }
}