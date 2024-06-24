#ifndef DBCPARSE_H
#define DBCPARSE_H

#include <QString>
#include <QVector>

/*
struct Signal {

    QString name;
    int startBit;
    int bitLength;
    QString endian;
    double scale;
    double offset;
    double min;
    double max;
    QString unit;
};

struct Message {
    QString name;
    int id;
    int dl;
    QVector<Signal> signalList;
};

class DBCParse {
public:
    static QVector<Message> parseDBCToMessages(const QString &filename);
};
*/


struct CANSignal {
    QString signalName;
    int startBit;
    int bitLength;
    QString endianType;
    double scaleFactor;
    double offsetValue;
    double minValue;
    double maxValue;
    QString unit;
};

struct CANMessage {
    QString messageName;
    int messageId;
    int dataLength;
    QVector<CANSignal> signalList;
};

class DBCParser {
public:
    static QVector<CANMessage> parseDBCToMessages(const QString &filePath);
};


#endif // DBCPARSE_H
