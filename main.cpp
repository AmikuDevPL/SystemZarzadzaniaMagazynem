#include <iostream>
#include <vector>
#include <string>
#include <optional>

int main() {

    class SystemManager {
        public:
        struct Item {
            std::string sku;
            std::string name;
            std::string manufacturer;
            std::string part_number;
            std::string footprint;
            int min_stock_alert{0};
            Item(std::string sku,std::string name,std::string manufacturer,std::string part_number,std::string footprint,const int min_stock_alert)
            :
                sku(std::move(sku)),
                name(std::move(name)),
                manufacturer(std::move(manufacturer)),
                part_number(std::move(part_number)),
                footprint(std::move(footprint)),
                min_stock_alert(min_stock_alert)
            {}
        };

        std::vector <Item> itemsCatalogue{};

        [[nodiscard]] auto getItemsInCatalogueQuantity() const {
            return itemsCatalogue.size();
        }

        Item* getItemBySku(const std::string& sku) {
            for (auto& i : itemsCatalogue) {
                if (i.sku == sku) {
                    return &i;
                    break;
                } else {
                    continue;
                }
            }
            return nullptr;
        }

        Item* getItemByName(const std::string& name) {
            for (auto& i : itemsCatalogue) {
                if (i.name == name) {
                    return &i;
                }
            }
            return nullptr;
        }

        void addItem(std::string sku, std::string name, std::string manufacturer, std::string part_number, std::string footprint, int min_stock_alert) {
            itemsCatalogue.emplace_back(sku, name, manufacturer, part_number, footprint, min_stock_alert);
        }

    };


    class Magazine {
    private:
        std::string magazine_name;

        struct Drawer {
            unsigned long long drawer_id{0};
            int small_containers_quantity{0};
            int row{0};
            int column{0};
            struct Small_container {
                int row{0};
                int column{0};
                int item_quantity{0};
                std::string itemSku {};
                Small_container(const int row, const int column) : row(row), column(column) {}
            };
            std::vector <Small_container> small_containers{};
            Drawer(const unsigned long long drawer_id, const int row, const int column) : drawer_id(drawer_id), row(row), column(column) {}
        };

        std::vector <Drawer> drawers {};

        SystemManager MainSystemManager;

    public:
        Magazine(const std::string& magazine_name, const SystemManager& MainSystemManager) {
            this->magazine_name = magazine_name;
            this->MainSystemManager = MainSystemManager;
        }

        void addDrawer(int row, int column) {
            unsigned long long drawer_id = drawers.size() + 1;
            drawers.emplace_back(drawer_id, row, column);
        }

        void addDrawers(const int rows,const int columns) {
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < rows; j++) {
                    unsigned long long drawer_id = drawers.size() + 1;
                    drawers.emplace_back(drawer_id, j, i);
                }
            }
        }

        Drawer* getDrawerById(const unsigned long long drawer_id) {
            for (auto& i : drawers) {
                if (i.drawer_id == drawer_id) {
                    return &i;
                }
            }
            return nullptr;
        }

        std::vector <Drawer> getDrawers() {
            return drawers;
        }

        void addContainers(const int rows, const int columns, const unsigned long long drawer_id) {
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


    return 0;
}