#pragma once

#include "../model/Document.h"


namespace vedt {

/**
 * @class Renderer
 * @brief Представление документа.
 */
class Renderer {
public:

    /**
     * @brief Вывод документа
     * @param document ссылка на документ.
     */
    void render(const Document& document) const;
};

}
