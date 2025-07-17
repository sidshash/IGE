#include "RightPanel.h"

void RightPanel::OnDraw() {
    if(mSelectedItem)
        mSelectedItem->DrawInspectable();


}

void RightPanel::PreWindow() {

}

void RightPanel::SetSelected(IInspectable* selectedItem) {
    mSelectedItem = selectedItem;
}