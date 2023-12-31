/**
 * @file TouchstoneFile.h
 * @brief TouchstoneFile class definition, used to read in and parse a
 * Touchstone file.
 * @author Bryce Walker
 */

#include "DataPoint.h"
#include "Options.h"
#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <list>
#include <string>

#ifndef TOUCHSTONE_FILE_H
#define TOUCHSTONE_FILE_H

/**
 * @class TouchstoneFile
 * @brief Class used to read in and parse a Touchstone File
 *
 */
class TouchstoneFile {
public:
  /**
   * @brief Build a Touchstone File and set all options to default
   */
  TouchstoneFile();  // constructor
  ~TouchstoneFile(); // TODO: Rule of 3
  TouchstoneFile(TouchstoneFile &other) = delete;
  TouchstoneFile operator=(TouchstoneFile &other) = delete;

  /**
   * @brief Build and open a Touchstone file. Set parameters based on file
   * parameters
   *
   * @param FILEPATH
   */
  TouchstoneFile(const std::string FILEPATH);

  /**
   * @brief Open a Touchstone file. Set parameters based on file parameters
   *
   * @param FILEPATH
   */
  void open(const std::string FILEPATH);

  /**
   * @brief Get max frequency
   *
   * @return Max frequency
   */
  double getMaxFreq() const;

  /**
   * @brief Get minumum frequency
   *
   * @return Min ferquency
   */
  double getMinFreq() const;

  /**
   * @brief Get max left hand side
   *
   * @return Min left hand side
   */
  double getMaxLHS() const;

  /**
   * @brief Get mnimum left hand side
   *
   * @return Min left hand side
   */
  double getMinLHS() const;

  /**
   * @brief Get max right hand side
   *
   * @return Max right hand side
   */
  double getMaxRHS() const;

  /**
   * @brief Get minimum right hand side
   *
   * @return Min right hand side
   */
  double getMinRHS() const;

  /**
   * @brief Get the total number of points in the file
   */
  unsigned long getNumPoints() const;

  /**
   * @brief Side of complementary measurements (MAG, ANGLE), (REAL, IMAGINARY),
   * etc...
   */
  enum class Side { LHS, RHS };

  /**
   * @brief Get the point at a specific index
   *
   * @param index Index of point
   * @param side Measurement side
   * @param param Number of parameter of measurement to get
   */
  sf::Vector2f at(int index, Side side, int param) const;

private:
  /**
   * @brief Set defaults based upon Touchstone File Spec
   */
  void _setDefaults();
  void _parseOptionLine(std::ifstream &file);
  void _parseDataLines(std::ifstream &file);
  FrequencyType _parseFreqT(const std::string &TOKEN);
  ParameterType _parseParamT(const std::string &TOKEN);
  ParameterFormat _parseParamFmt(const std::string &TOKEN);
  int _numPorts;
  std::list<DataPoint *> _originalData;
  FrequencyType _freqT;
  ParameterType _paramT;
  ParameterFormat _paramFmt;
  double _refRes;
  double _maxFreq;
  double _minFreq;
  double _maxLHS;
  double _minLHS;
  double _maxRHS;
  double _minRHS;
};

#endif // !TOUCHSTONE_FILE_H
