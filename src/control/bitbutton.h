/*
* Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     jingzhou <jingzhou@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BITBUTTON_H
#define BITBUTTON_H

#include <DPushButton>
#include <DPalette>
#include <DGuiApplicationHelper>

#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

DWIDGET_USE_NAMESPACE
DGUI_USE_NAMESPACE

/**
 * @brief 程序员模式0-1二进制按钮
 */
class BitButton : public DPushButton
{
    Q_OBJECT
public:
    explicit BitButton(QWidget *parent = nullptr);
    ~BitButton() override;

    void init();
    void animate(bool isspace = false, int msec = 100);
    void setButtonState(bool b);

public:
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;
    void paintEvent(QPaintEvent *e) override;
    void focusOutEvent(QFocusEvent *) override;
    void keyPressEvent(QKeyEvent *e) override;

signals:
    void focus(int direction); //direction 0-上　1-下　2-左　3-右
    void space();

private:
    bool m_isHover = false;
    bool m_isPress = false;
    bool m_btnState = false; //true-1, false-0
    QFont m_font;
};

#endif // BITBUTTON_H
