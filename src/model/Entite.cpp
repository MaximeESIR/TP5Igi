#include <model/Entite.h>
#include <model/Variable.h>

Entite::Entite(QString nom, QObject * pParent) : QObject(pParent)
{
	m_nom = nom;
	m_variables << new Variable("V1",this);
	m_variables << new Variable("V2",this);
	m_variables << new Variable("V3",this);
}

Entite::~Entite()
{
}

QString Entite::nom() const
{
	return m_nom;
}

QList<Variable*> Entite::variables() const
{
	return m_variables;
}
