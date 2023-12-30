#include <model/Variable.h>

#define NB_PAS 3600

Variable::Variable(QString nom, QObject * pParent) : QObject(pParent)
{
	int i;
	m_nom = nom;
	for (i=0; i<NB_PAS; ++i)
	{
		m_pasDeTemps << i;
		m_temperature << 20 + (double(i)/NB_PAS) * 20;
		m_pression << 3 + (double(i)/NB_PAS) * 10;
	}
}

Variable::~Variable()
{
}

QString Variable::nom() const
{
	return m_nom;
}

QList<double> Variable::pasDeTemps() const
{
	return m_pasDeTemps;
}

QList<double> Variable::temperature() const
{
	return m_temperature;
}

QList<double> Variable::pression() const
{
	return m_pression;
}

void Variable::setPasDeTemps(int i, double val)
{
	m_pasDeTemps[i] = val;
}

void Variable::setTemperature(int i, double val)
{
	m_temperature[i] = val;
}

void Variable::setPression(int i, double val)
{
	m_pression[i] = val;
}
