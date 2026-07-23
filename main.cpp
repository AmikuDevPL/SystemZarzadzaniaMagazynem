#include <iostream>
#include <vector>
#include <string>

int main() {

    struct Item {
        std::string sku;
        std::string name;
        std::string manufacturer;
        std::string part_number;
        std::string footprint;
        int min_stock_alert{0};
    };

    class Magazine {
    private:
        std::string magazine_name;
        std::vector<Item> items;

    public:
        Magazine(std::string magazine_name) {
            this->magazine_name = magazine_name;
        }

        void addItem(Item item) {
            items.push_back(item);
        }

        void showItems() const {
            for (const auto& item : items) {
                std::cout << item.sku << " | "
                          << item.name << " | "
                          << item.manufacturer << " | "
                          << item.part_number << " | "
                          << item.footprint << " | "
                          << item.min_stock_alert << '\n';
            }
        }
    };

    Magazine M01("Magazyn1");

    M01.addItem({
        "CAP-100NF-0603",
    "Kondensator 100nF",
    "Murata",
    "GRM188R71E104KA01D",
    "0603",
    50
    });

    M01.showItems();

    return 0;
}