#include <iostream>

int main() {

    struct Item {
        std::string sku{""};
        std::string name{""};
        std::string producent{""};
        std::string part_number{""};
        std::string footprint{""};
        int min_stock_alert{};
    };

    return 0;
}