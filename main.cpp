#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class AILevelPopup : public Popup<std::string const&> {
protected:
    TextInput* m_inputField;

    bool setup(std::string const& value) override {
        this->setTitle("AI 3D Level Generator");
        
        // Create text input for pasting code
        m_inputField = TextInput::create(300.f, "Paste code or 3D structure data here...");
        m_inputField->setPosition(m_size / 2 + CCPoint{0, 20});
        m_layers->addChild(m_inputField);

        // Generate Button
        auto genButton = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Build 3D Level", "goldBtn.png", 0.8f),
            this,
            menu_selector(AILevelPopup::onGenerate3D)
        );
        
        auto menu = CCMenu::create();
        menu->addChild(genButton);
        menu->setPosition(m_size.width / 2, 45);
        m_layers->addChild(menu);

        return true;
    }

    void onGenerate3D(CCObject*) {
        std::string code = m_inputField->getString();
        
        // Simulate 3D level parsing: convert code tokens into 3D objects
        auto editorLayer = LevelEditorLayer::get();
        if (editorLayer) {
            float depthOffset = 0.f;
            for (char c : code) {
                // Example 3D translation logic: adjusting scale and Z-layer based on code input
                auto obj = editorLayer->createObject(1, {150.f + depthOffset, 150.f});
                if (obj) {
                    // Simulate 3D depth by scaling and shifting Z-order / layers
                    obj->setScale(1.0f - (depthOffset * 0.001f));
                    obj->setZOrder(static_cast<int>(depthOffset));
                }
                depthOffset += 10.f;
            }
            FLAlertLayer::create("Success", "3D Level generated successfully from code!", "OK")->show();
        }
        this->onClose(nullptr);
    }

public:
    static AILevelPopup* create() {
        auto ret = new AILevelPopup();
        if (ret && ret->initAnchored(380.f, 220.f, "GJ_square01.png")) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

class $modify(MyEditorUI, EditorUI) {
    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer)) return false;

        auto aiButtonSprite = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
        auto aiButton = CCMenuItemSpriteExtra::create(
            aiButtonSprite,
            this,
            menu_selector(MyEditorUI::onAIBtnClick)
        );

        auto menu = CCMenu::create();
        menu->addChild(aiButton);
        menu->setPosition({35, 100});
        this->addChild(menu);

        return true;
    }

    void onAIBtnClick(CCObject*) {
        AILevelPopup::create()->show();
    }
};
