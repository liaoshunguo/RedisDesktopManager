#ifndef HASHKEYMODEL_H
#define HASHKEYMODEL_H

#include "abstractkey.h"

class HashKeyModel : public KeyModel
{
    Q_OBJECT

public:
    HashKeyModel(QSharedPointer<RedisClient::Connection> connection, QString fullPath, int dbIndex, int ttl);

    QString getType() override;
    QStringList getColumnNames() override;
    QHash<int, QByteArray> getRoles() override;
    QString getData(int rowIndex, int dataRole) override;
    virtual void setData(int rowIndex, int dataRole, QString value) override;

    void addRow(/* ??? */) override;
    unsigned long rowsCount() override;
    void loadRows(unsigned long rowStart, unsigned long count, std::function<void()> callback) override;
    void clearRowCache() override;
    void removeRow(int) override;
    bool isRowLoaded(int) override;
    bool isMultiRow() const override;

};

#endif // HASHKEYMODEL_H