#ifndef ENTITE_H
#define ENTITE_H

#include <QMetaType>
#include <QObject>
#include <QString>

class Variable;

class Entite : public QObject
{
	Q_OBJECT
public:
	Entite(QString nom, QObject * pParent = NULL);
	virtual ~Entite();
	QString nom() const;
	QList<Variable*> variables() const;
private:
	QList<Variable*> m_variables;
	QString m_nom;
};

Q_DECLARE_METATYPE(Entite*)

#endif