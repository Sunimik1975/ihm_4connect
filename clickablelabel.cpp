#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent) : QLabel(parent) {}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();  // Emitimos la señal 'clicked' al detectar un clic
}
