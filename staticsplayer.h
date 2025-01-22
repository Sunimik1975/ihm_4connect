#ifndef STATICSPLAYER_H
#define STATICSPLAYER_H

#include <QDialog>

namespace Ui {
class StaticsPlayer;
}

class StaticsPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit StaticsPlayer(const QString& playerName,
                           const QMap<QDate, int>& winsPerDay,
                           const QMap<QDate, int>& lossesPerDay,
                           const QMap<QDate, QSet<QString>>& opponentsPerDay,
                           const QDate& startDate,
                           const QDate& endDate,
                           QWidget* parent = nullptr);

    ~StaticsPlayer();

private:
    Ui::StaticsPlayer *ui;
};

#endif // STATICSPLAYER_H
