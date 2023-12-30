#ifndef CLASSE_H
#define CLASSE_H

#include <QObject>

class Entite;

class Classe : public QObject
{
	Q_OBJECT
public:
	Classe(QObject * pParent = NULL);
	virtual ~Classe();
	QList<Entite*> entites() const;
private:
	QList<Entite*> m_entites;
};

#endif