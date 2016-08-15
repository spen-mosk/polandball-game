/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "gamewidget.h"
#include "GameObjects/Actors/Statistics/enemystatistics.h"
#include "GameObjects/Actors/enemy.h"
#include <QPainter>
#include <QTimer>
#include <stdio.h>
#include <QOpenGLWidget>
#include <vector>

//! [0]
GameWidget::GameWidget(Player * control, QWidget *parent)
    : QOpenGLWidget(parent)
{
    setFixedSize(1376, 764);
    setAutoFillBackground(false);
    player = control;
    timer = new QTimer(this);
    std::vector<GameObject*> testingitems;
    EnemyStatistics* stats = new EnemyStatistics(1, 1, 1, false, 1, NULL, 50, 40);
    Enemy * enemy = new Enemy(220, 23, stats);
    testingitems.push_back(new Platform(0,0,200,200));
    testingitems.push_back(enemy);
    testingitems.push_back(new Platform(210, -5, 100, 100));
    testingitems.push_back(new Platform(-100,100,100,105));
    //testingitems.push_back(new Platform(19,100,100,100));
    level = new Level(player,testingitems, -1);
    camera = new Camera(160, this);
    interval = 22;
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    parent->connect(parent, SIGNAL(keyPress(int)), level, SLOT(handlePress(int)));
    parent->connect(parent, SIGNAL(keyRelease(int)), level, SLOT(handleRelease(int)));
    timer->start();
}

GameWidget::~GameWidget(){
    delete player;
    delete timer;
    delete level;
    delete camera;
}

//! [0]

//! [1]
void GameWidget::animate()
{
    level->update();
    //TODO change player in this widget
    toDraw = *camera->snapshot(player, level->getObjects());
    update();
}

//! [1]

//! [2]
void GameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0, 0, 5000, 5000);
    for(int i = 0; i < toDraw.size(); i++) {
        toDraw[i]->draw(&painter);
    }
    painter.end();
}
//! [2]
