#include "ViewportPanel.h"
#include "../../../Application.h"

ViewportPanel::ViewportPanel() :
    IPanel("Viewport")
{
    windowHandler = Locator::GetApplication()->GetWindow();
    fbWidth = windowHandler->WIDTH;
    fbHeight = windowHandler->HEIGHT;
    Init();
    SetFlags(windowFlags);
}

void ViewportPanel::Init() {
    ResizeFramebuffer = [&](int newWidth, int newHeight) {
        if (newWidth == fbWidth && newHeight == fbHeight) return;

        fbWidth = newWidth;
        fbHeight = newHeight;

        Locator::GetCamera()->SetOrthoFromFramebuffer(fbWidth, fbHeight);


        if (depthRbo) glDeleteRenderbuffers(1, &depthRbo);
        if (colorTexture) glDeleteTextures(1, &colorTexture);
        if (fbo) glDeleteFramebuffers(1, &fbo);

        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glGenTextures(1, &colorTexture);
        glBindTexture(GL_TEXTURE_2D, colorTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, fbWidth, fbHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);

        glGenRenderbuffers(1, &depthRbo);
        glBindRenderbuffer(GL_RENDERBUFFER, depthRbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, fbWidth, fbHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthRbo);

        assert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        };
}

void ViewportPanel::OnDraw(){
    char fpsSize[50];
    std::snprintf(fpsSize, sizeof(fpsSize), "(%.1f FPS)", fps);
    ImGui::Text(fpsSize);
    ImVec2 cursor = ImGui::GetCursorScreenPos();
    ImVec2 avail = ImGui::GetContentRegionAvail();
    // Clamp to 16:9
    float aspect = 16.0f / 9.0f;
    float w = avail.x;
    float h = w / aspect;

    if (h > avail.y) {
        h = avail.y;
        w = h * aspect;
    }

    ImVec2 size = ImVec2(w, h);


    if (w > 2 && h > 2) {
        ImGui::SetCursorScreenPos(cursor); // optional—keeps image pinned
        ResizeFramebuffer((int)size.x, (int)size.y);
        ImGui::Image((void*)(intptr_t)colorTexture, size, ImVec2(0, 1), ImVec2(1, 0));
    }
}

void ViewportPanel::DrawOnFB() {
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glViewport(0, 0, fbWidth, fbHeight);
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void ViewportPanel::PreWindow() {
}