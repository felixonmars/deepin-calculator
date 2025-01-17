/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     jingzhou <jingzhou@uniontech.com>
*
* Maintainer: xiajing <xiajing@uniontech.com>
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

#ifndef MEMORYITEMWIDGET_H
#define MEMORYITEMWIDGET_H

#include "../control/memorybutton.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

/**
 * @brief 内存列表Item界面
 */
class MemoryItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MemoryItemWidget(QWidget *parent = nullptr);
    ~MemoryItemWidget() override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void setTextLabel(QString s);
    QString textLabel();
    void paintEvent(QPaintEvent *e) override;
    void setLineHight(int line, int height);
    int getLine();
signals:
    void plusbtnclicked();
    void minusbtnclicked();
    void cleanbtnclicked();
    void menuclean();
    void menucopy();
    void menuplus();
    void menuminus();
public slots:
    void themetypechanged(int type);
    void isexpressionempty(bool b);
    void setNextItemHover();
    void showTextEditMenuByAltM();

public:

//    QPainter *getpainter();

private:
    MemoryButton *m_btnplus;
    MemoryButton *m_btnminus;
    MemoryButton *m_btnclean;
    QLabel *m_label;
    int m_type = 0;
    int m_themetype = 1;
    bool m_isExpressionEmpty = false;
    bool m_ispress = false;
    bool m_ishover = false;
    QFont m_font;
    int m_line = 0;
};

#endif // MEMORYITEMWIDGET_H
