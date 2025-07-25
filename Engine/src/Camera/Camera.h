#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "../Locator/Locator.h"
class Camera {
    glm::mat4 projection;
public:
    Camera() {
        Locator::SetCamera(this);
    }
    void SetOrthoFromFramebuffer(int fbWidth, int fbHeight);
    const glm::mat4& GetProjection() const;
};

