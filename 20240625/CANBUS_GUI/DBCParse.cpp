#include "DBCParse.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

namespace {
QString extractToken(const QString &str, int index, const QString &delimiter) {
    return str.split(delimiter, Qt::SkipEmptyParts).value(index);
}

int extractInt(const QString &str, int index, const QString &delimiter) {
    return extractToken(str, index, delimiter).toInt();
}

double extractDouble(const QString &str, int index, const QString &delimiter) {
    return extractToken(str, index, delimiter).toDouble();
}
}

QVector<CANMessage> DBCParser::parseDBCToMessages(const QString &filePath) {
    QVector<CANMessage> messages;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open DBC file";
        return messages;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.startsWith("BO_")) {
            QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 3) {
                CANMessage message;
                message.messageId = extractInt(parts[1], 0, "");
                message.messageName = extractToken(parts[2], 0, ":");
                message.dataLength = extractInt(parts[3], 0, "");
                messages.append(message);
            }
        } else if (line.startsWith("SG_")) {
            QStringList parts = line.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 7) {
                CANSignal signal;
                signal.signalName = parts[1];
                QString bitInfo = parts[3];
                signal.startBit = extractInt(bitInfo, 0, "|");
                signal.bitLength = extractInt(bitInfo, 1, "|@");
                signal.endianType = bitInfo.contains("@1") ? "Little" : "Big";
                QString valueInfo = parts[4];
                signal.scaleFactor = extractDouble(valueInfo, 0, ",()");
                signal.offsetValue = extractDouble(valueInfo, 1, ",()");
                QString rangeInfo = parts[5];
                signal.minValue = extractDouble(rangeInfo, 0, "[|");
                signal.maxValue = extractDouble(rangeInfo, 1, "|]");
                signal.unit = parts[6].mid(1, parts[6].size() - 2);
                if (!messages.isEmpty()) {
                    messages.last().signals.append(signal);
                }
            }
        }
    }

    file.close();
    return messages;
}
