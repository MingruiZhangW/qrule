#ifndef NODEWRAPPER_H
#define NODEWRAPPER_H

#include <QList>



class NodeWrapper {
public:
    NodeWrapper(const QString value, const QString valueType, const QString nodeType,
                quint32 row, quint32 col, const QStringRef source, const QList<QStringRef> tokens):
        value(value), valueType(valueType), nodeType(nodeType), row(row), col(col),
        source(source), tokens(tokens) {}

    ~NodeWrapper();

    void addChild(NodeWrapper *node);
    const QString getValue();
    const QString getValueType();
    const QString getNodeType();
    const QStringRef getSource();
    const quint32 getRow();
    const quint32 getCol();
    const QList<NodeWrapper *>& getChildren();
    const QList<QStringRef>& getTokens();

private:
    QList<NodeWrapper *> children;
    const QList<QStringRef> tokens;
    const QString value;
    const QString valueType;
    const QString nodeType;
    const quint32 row;
    const quint32 col;
    const QStringRef source;
};

#endif // NODEWRAPPER_H