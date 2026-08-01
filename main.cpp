#include <iostream>
#include <vector>
#include <string>
#include <optional>

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

        std::optional<Item> getItemBySku(std::string sku) {
            for (auto& i : itemsCatalogue) {
                if (i.sku == sku) {
                    return i;
                    break;
                } else {
                    continue;
                }
            }
        }

        std::optional<Item> getItemByName(std::string name) {
            for (auto& i : itemsCatalogue) {
                if (i.name == name) {
                    return i;
                    break;
                } else {
                    continue;
                }
            }
        }

        void addItem(std::string sku, std::string name, std::string manufacturer, std::string part_number, std::string footprint, int min_stock_alert) {
            itemsCatalogue.push_back(Item(sku, name, manufacturer, part_number, footprint, min_stock_alert));
        }

    };


    class Magazine {
    private:
        std::string magazine_name;

        struct Drawer {
            int drawer_id{0};
            int small_containers_quantity{0};
            int row{0};
            int column{0};
            struct Small_container {
                int row{0};
                int column{0};
                int item_quantity{0};
                std::string itemSku {};
            };
            std::vector <Small_container> small_containers{};

        };

        std::vector <Drawer> drawers {};

    public:
        Magazine(std::string magazine_name) {
            this->magazine_name = magazine_name;
        }

        void addDrawer(int drawer_id, int small_containers_quantity, int row, int column) {
            drawers.push_back(Drawer(drawer_id, small_containers_quantity, row, column));
        }

        void addContainers(int rows, int columns, int drawer_id) {
            for (auto& i : drawers) {
                if (i.drawer_id == drawer_id) {
                    for (size_t j = 0; j < columns; j++) {
                        for (size_t k = 0; k < rows; k++) {
                            i.small_containers.push_back();
                        }
                    }
                }
            }
        }
    };

    Magazine M01("Magazyn1");
    std::cerr << "cerr" << '\n';

    return 0;
}