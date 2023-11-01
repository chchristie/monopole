#ifndef MONOPOLE_OUTPUT_H
#define MONOPOLE_OUTPUT_H

#include "crpropa/module/ParticleCollector.h"
#include "Monopole.h"

#include <fstream>

namespace crpropa {
/**
 * \addtogroup Output
 * @{
 */

/**
 @class MonopoleOutput
 @brief Plain text output for monopole information intended for galactic trajectories.
 */
class MonopoleOutput: public Module {
private:
	void printHeader() const;
	std::ostream *out;
	std::ofstream outfile;
	std::string filename;
	mutable size_t count;
	mutable size_t idx;
	double lengthScale;
	double energyScale;

public:
	/** Constructor
	*/
	MonopoleOutput(const std::string &filename);
	~MonopoleOutput();
	/** Set energy scale.
	 @param scale	energy scale (scale = 1 corresponds to 1 Joule)
	 */
	void setEnergyScale(double scale);
	/** Set length scale.
	 @param scale	length scale (scale = 1 corresponds to 1 meter)
	 */
	void setLengthScale(double scale);
	
	void process(Candidate *candidate) const;
	
	void close();
};
/** @}*/

} // namespace crpropa

#endif // MONOPOLE_OUTPUT_H
