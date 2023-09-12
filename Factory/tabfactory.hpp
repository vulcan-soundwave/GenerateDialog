#pragma once

#include <string>
#include <unordered_map>
#include <functional>

#include "Share/ctab.h"

class TabFactory
{
public:
    static TabFactory *getInstance() {
        return instance;
    }

    void registerTab (std::string name, std::function<CTab *()> concreteTab) {
        mapReg__.emplace(name, concreteTab);
    }

    CTab *generateInstance (std::string name) const {
        auto it = mapReg__.find(name);
        if (it != mapReg__.end()) {
            return it->second();
        }

        return nullptr;
    }

private:
    TabFactory() = default;                                 // 私有构造函数
    TabFactory(const TabFactory &) = delete;                // 删除拷贝构造函数
    TabFactory& operator=(const TabFactory &) = delete;     // 删除赋值运算符

private:
    static TabFactory *instance;

    std::unordered_map<std::string, std::function<CTab *()>> mapReg__;
};

// 初始化单例实例
inline TabFactory *TabFactory::instance = new TabFactory();
