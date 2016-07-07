#pragma once
#include <QObject>
#include "hero.h"
#include "heroqueue.h"
#include "action.h"

class BattleModel : public QObject
{
Q_OBJECT
private:

signals:
    // BattleModel -> BattleGUI
    void show();  // Show GUI window
    void hide();  // Hide GUI window
    void setActiveHero(Hero*);  // Change current hero
    void setQueue(HeroQueue*);  // Change queue
    void showTargets(Action*);  // Highlight avaliable targets
    void playAction(Action*);  // Play animation/sounds, show numbers

    // BattleModel -> Game
    void finishedSignal();
    void closedSignal();

public slots:
    void selectedAction(Action*);  // After attack or skill clicked
    void selectedTarget(Hero*);  // After Hero clicked
    void closed();

public:
    BattleModel(QObject *parent = nullptr);
};