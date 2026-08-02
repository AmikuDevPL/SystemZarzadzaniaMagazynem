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
            Item(std::string sku,std::string name,std::string manufacturer,std::string part_number,std::string footprint,int min_stock_alert)
            :   sku(sku), name(name), manufacturer(manufacturer), part_number(part_number), footprint(footprint), min_stock_alert(min_stock_alert)
            {}
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
            itemsCatalogue.emplace_back(sku, name, manufacturer, part_number, footprint, min_stock_alert);
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
                Small_container(int row, int column) : row(row), column(column) {}
            };
            std::vector <Small_container> small_containers{};
            Drawer(int drawer_id, int row, int column) : drawer_id(drawer_id), row(row), column(column) {}
        };

        std::vector <Drawer> drawers {};

    public:
        Magazine(std::string magazine_name) {
            this->magazine_name = magazine_name;
        }

        void addDrawer(int row, int column) {
            int drawer_id = drawers.size() + 1;
            drawers.emplace_back(drawer_id, row, column);
        }

        void addDrawers(int rows, int columns) {
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < rows; j++) {
                    int drawer_id = drawers.size() + 1;
                    drawers.emplace_back(drawer_id, j, i);
                }
            }
        }

        std::optional<Drawer> getDrawerById(int drawer_id) {
            for (auto& i : drawers) {
                if (i.drawer_id == drawer_id) {
                    return i;
                }
            }
        }

        std::vector <Drawer> getDrawers() {
            return drawers;
        }

        void addContainers(int rows, int columns, int drawer_id) {
            for (auto& i : drawers) {
                if (i.drawer_id == drawer_id) {
                    i.small_containers_quantity = rows*columns;
                    for (int j = 0; j < columns; j++) {
                        for (int k = 0; k < rows; k++) {
                            int row = k;
                            int column = j;
                            i.small_containers.emplace_back(row, column);
                        }
                    }
                }
            }
        }


    };

    SystemManager MainSystemManager;
    MainSystemManager.addItem("sku", "nazwa przedmiotu", "marka", "part number", "obudowa", 10);
    std::cerr << MainSystemManager.getItemsInCatalogueQuantity() << '\n';
    std::cerr << MainSystemManager.getItemByName("nazwa przedmiotu")->sku << '\n';
    std::cerr << MainSystemManager.getItemBySku("sku")->name << '\n';

    Magazine M01("Magazyn1");
    M01.addDrawer(1, 1);
    M01.addContainers(12, 12, 1);
    std::cerr << M01.getDrawerById(1)->small_containers_quantity << '\n';


    return 0;
}