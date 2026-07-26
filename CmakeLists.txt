#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

// A simple popup menu for your mod
class ImporterPopup : public Popup<> {
protected:
    bool setup() override {
        this->setTitle("ROM Importer");

        auto label = CCLabelTTF::create("Ready to load ROM data!", "Thonburi", 18);
        label->setPosition({this->m_size.width / 2, this->m_size.height / 2});
        this->m_mainLayer->addChild(label);

        return true;
    }
};

// Hook into the Pause Menu to add a button that opens your popup
#include <Geode/modify/PauseLayer.hpp>
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        // Find the center menu and add your custom button
        if (auto menu = this->getChildByID("center-menu")) {
            auto btn = CCMenuItemSpriteExtra::create(
                ButtonSprite::create("ROM"),
                this,
                menu_selector(MyPauseLayer::onOpenImporter)
            );
            
            btn->setID("rom-button"_spr);
            menu->addChild(btn);
            menu->updateLayout();
        }
    }

    void onOpenImporter(CCObject*) {
        ImporterPopup::create()->show();
    }
};
