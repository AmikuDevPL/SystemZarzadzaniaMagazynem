#include <iostream>
#include <vector>
#include <string>

int main() {

    class SystemManager {
    private:
    struct Item {
        std::string sku;
        std::string name;
        std::string manufacturer;
        std::string part_number;
        std::string footprint;
        int min_stock_alert{0};
    };

    std::vector <Item> itemsCatalogue{};

    public:
    int getItemsInCatalogueQuantity() {
        return itemsCatalogue.size();
    };

    Item getItemBySku(sku) {

    }

    };


    class Magazine {
    private:
        std::string magazine_name;
        struct Drawer {
            int small_containers_quantity{0};
            int row{0};
            int column{0};
            struct Small_container {
                int row{0};
                int column{0};
                int item_quantity{0};
                std::string sku {};
            };
            std::vector <Small_container> small_containers{};

            Drawer(const int quantity)
                :   small_containers_quantity(quantity),
                    small_containers(quantity)
            {}
        };

    public:
        Magazine(std::string magazine_name) {
            this->magazine_name = magazine_name;
        }
    };

    Magazine M01("Magazyn1");

    return 0;
}