#include "Camera.h"

void Camera::SetOrthoFromFramebuffer(int fbWidth, int fbHeight) {
    //float aspect = (float)fbWidth / (float)fbHeight;
    //float worldHeight = 180.0f;
    //float worldWidth = worldHeight * aspect;

    //glm::mat4 projection = glm::ortho(
    //    -worldWidth / 2.0f, worldWidth / 2.0f,
    //    -worldHeight / 2.0f, worldHeight / 2.0f,
    //    -1.0f, 1.0f
    //);
    float scale = 100.0f;
    projection = glm::ortho(
        -fbWidth /  scale, fbWidth  / scale,
        -fbHeight / scale, fbHeight / scale,
        -1.0f, 1.0f
    );
}

const glm::mat4& Camera::GetProjection() const
{
	return projection;
}

