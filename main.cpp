#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>
#include <fstream>

using namespace geode::prelude;

// 1. Create a custom popup menu for your ROM Importer
class ROMImporterPopup : public Popup<> {
protected:
    bool setup() override {
        this->setTitle("ROM to GD Level Importer");

        // Create a button to trigger the import process
        auto importButton = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Select ROM"),
            this,
            menu_selector(ROMImporterPopup::onImportClicked)
        );
        importButton->setPosition({0, 0});

        this->m_buttonMenu->addChild(importButton);#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp> // Make sure this is at the very top of your file

using namespace geode::prelude;

class MyModPopup : public Popup {
public:
    bool init() {
        if (!Popup::init()) return false;

        // ... (all your other UI setup code for your mod goes here) ...

        // Paste the link code right down here at the end of the init function:
        auto linkLabel = CCLabelBMFont::create("GitHub Link", "goldFont.fnt");
        linkLabel->setScale(0.5f);

        auto linkButton = CCMenuItemSpriteExtra::create(
            linkLabel,
            this,
            [](CCObject*) {
                geode::utils::web::openLink("https://github.com/ayanmohammad2026-ui/ROMImporterMod");
            }
        );

        auto menu = CCMenu::create();
        menu->addChild(linkButton);
        menu->setPosition({m_size.width / 2, 20.f});
        this->addChild(menu);

        return true; // Keep this as the very last line of the init function
    }
};

        return true;
    }

    void onImportClicked(CCObject* sender) {
        FLAlertLayer::create("Importer", "Scanning for ROM files...", "OK")->show();
        
        // Call your file parsing and object generation function here
        this->parseAndGenerateLevel("example_path.rom");
    }

    void parseAndGenerateLevel(const std::string& filepath) {
        // Example logic: Reading binary file data using standard C++ streams
        std::ifstream file(filepath, std::ios::binary);
        if (!file.is_open()) {
            log::error("Failed to open ROM file!");
            return;
        }
    }
};
